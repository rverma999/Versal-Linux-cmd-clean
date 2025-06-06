// Copyright(C) 2020 - 2021 by Xilinx, Inc. All rights reserved.
// SPDX-License-Identifier: MIT
/**
 * @param file xaiefal-rsc-base.hpp
 * Base classes for AI engine resources management
 */

#include <fstream>
#include <functional>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>
#include <xaiengine.h>
#include <xaiefal/common/xaiefal-base.hpp>
#include <xaiefal/common/xaiefal-log.hpp>

#pragma once

namespace xaiefal {
	class XAieRsc;

	/**
	 * @struct XAieUserRsc
	 * @brief Data needed to make a resource request
	 */
	struct XAieUserRsc {
		/**< Location of request */
		XAie_LocType Loc {
                        XAie_TileLoc(XAIE_LOC_ANY, XAIE_LOC_ANY)
                };
                /**< Module of request */
                XAie_ModuleType Mod {
                        static_cast<XAie_ModuleType>(XAIE_MOD_ANY)
                };
                /**< Type of request */
                XAieRscType RscType {
                        static_cast<XAieRscType>(XAIE_RSC_TYPE_ANY)
                };
                /**< Id of resource */
                uint32_t RscId {
                        static_cast<uint32_t>(XAIE_RSC_ID_ANY)
                };
        };

	/**
	 * struct XAieRscState
	 * State of each AIE resource
	 */
	struct XAieRscState {
		uint8_t Initialized: 1; /**< bit set for resource is initialized */
		uint8_t Configured: 1; /**< bit set for resource is configured */
		uint8_t Reserved: 1; /**< bit set for resource is reserved */
		uint8_t Prereserved: 1; /**< bit set for resource is prereserved
					     Prereserved resource is the resource
					     which are supposed to be allocated
					     at compilation. If user specifies
					     particular hardware resources to use
					     for this resource, this bit will be
					     set. */
		uint8_t Running: 1; /**< bit set for resource is running */
	};

	/**
	 * @class XAieRsc
	 * @brief Base AI engine resource class. It defines resource operations
	 *	  and maintains resource state machine.
	 */
	class XAieRsc {
	public:
		XAieRsc() = delete;
		XAieRsc(std::shared_ptr<XAieDevHandle> DevHd):
			State(), AieHd(DevHd) {
			if (!DevHd) {
				throw std::invalid_argument("aie rsc: empty device handle");
			}
			preferredId = XAIE_RSC_ID_ANY;
			Type = static_cast<XAieRscType>(XAIE_RSC_TYPE_ANY);
		}
		XAieRsc(std::shared_ptr<XAieDevHandle> DevHd, XAieRscType Type):
			State(), Type(Type), AieHd(DevHd) {
			if (!DevHd) {
				throw std::invalid_argument("aie rsc: empty device handle");
			}
			preferredId = XAIE_RSC_ID_ANY;
		}
		XAieRsc(XAieDev &Dev):
			State(), AieHd(Dev.getDevHandle()) {
				preferredId = XAIE_RSC_ID_ANY;
				Type = static_cast<XAieRscType>(XAIE_RSC_TYPE_ANY);
			}
		virtual ~XAieRsc() {
			if (State.Running == 1) {
				stop();
			} else if (State.Reserved == 1) {
				if (State.Prereserved == 1) {
					free();
				} else {
					release();
				}
			}
		}
		/**
		* This function sets a resource's id to a requested id value.
		* Resources that can have their id set always have XAIE_RSC_ID_ANY as
		* a default value.
		*
		* @param id requested id for resource
		* @param isStatticAllocated to indicate if the resource has been allocated at static time.
		*
		* @return XAIE_OK for success, and error code for failure.
		*/

		AieRC setPreferredId(uint32_t id, bool isStaticAllocated = false) {
			AieRC RC;

			if (State.Reserved == 1) {
				RC = XAIE_INVALID_ARGS;
			} else {
				preferredId = id;
				RC = XAIE_OK;
				if (isStaticAllocated) {
					if (id == XAIE_RSC_ID_ANY) {
						RC = XAIE_INVALID_ARGS;
						Logger::log(LogLevel::ERROR) << __func__ << " " <<
							typeid(*this).name() <<
							" If Rsc ID is any, cannot be statically allocated" << std::endl;
					} else {
						State.Prereserved = 1;
					}
				}
			}

			return RC;
		}
		/**
		 * This function returns the preferred ID
		 *
		 * @return preferred Id of resource
		 */
		uint32_t getPreferredId() {
			return preferredId;
		}

		/**
		 * This function reserves the resource.
		 * Once the resource is reserved, the underline hardware
		 * resources belong to this resource will be occupied
		 * until it is released.
		 *
		 * If no prereserved hardware resources have been specified
		 * it allocates resources from SSW AIE driver.
		 *
		 * If prereserved hardware resources have been specified, it
		 * will request to use the specified resources. If the resources
		 * are not statically allocated, SSW AIE driver will return
		 * failure.
		 *
		 * @return XAIE_OK for success, and error code for failure.
		 */
		AieRC reserve() {
			AieRC RC;

			if (State.Reserved == 1) {
				Logger::log(LogLevel::ERROR) << __func__ << " " <<
					typeid(*this).name() << " resource has been allocated." << std::endl;
				RC = XAIE_ERR;
			} else if (State.Initialized == 0) {
				Logger::log(LogLevel::ERROR) << __func__ << " " <<
					typeid(*this).name() << " resource not configured." << std::endl;
				RC = XAIE_ERR;
			} else {
				RC = _reserve();
				if (RC == XAIE_OK) {
					State.Reserved = 1;
				}
			}
			return RC;
		}
		/**
		 * This function releases the resource.
		 * Once the resource is released, the underline hardware
		 * resources belong to this resource will be released so that
		 * they can be allcated for other entity.
		 *
		 * @return XAIE_OK for success, and error code for failure.
		 */
		AieRC release() {
			AieRC RC = XAIE_OK;

			if (State.Running == 1) {
				Logger::log(LogLevel::ERROR) << __func__ << " " <<
					typeid(*this).name() << "resource is running." << std::endl;
				RC = XAIE_ERR;
			} else if (State.Reserved == 1) {
				RC = _release();
				State.Reserved = 0;
				State.Prereserved = 0;
			}
			return RC;
		}
		/**
		 * This function free the prereserved resource.
		 *
		 * Once the prereserved resource is freed, the underline
		 * hardware resources are freed to be used by other entity
		 * but these hardware resources are still prereserved. That is
		 * if some enity tries to allocate for resource, the prereserved
		 * resources will not be allocated.
		 *
		 * @return XAIE_OK for success, and error code for failure.
		 */
		AieRC free() {
			AieRC RC = XAIE_OK;

			if (State.Prereserved == 0) {
				Logger::log(LogLevel::ERROR) << __func__ << " " <<
					typeid(*this).name() << " resource is not preserved." << std::endl;
				RC = XAIE_INVALID_ARGS;
			} else {
				if (State.Running == 1) {
					Logger::log(LogLevel::ERROR) << __func__ << " " <<
						typeid(*this).name() << " resource is running." << std::endl;
					RC = XAIE_INVALID_ARGS;
				} else if (State.Reserved == 1) {
					RC = _free();
					State.Reserved = 0;
				}
			}
			return RC;
		}
		/**
		 * This function starts using the resource by configuring the
		 * hardware registers. It needs to be called after the resource
		 * is reserved.
		 *
		 * @return XAIE_OK for success, and error code for failure.
		 */
		AieRC start() {
			AieRC RC = XAIE_OK;

			if (State.Running == 1) {
				RC = XAIE_OK;
			} else if (State.Reserved == 1) {
				if (State.Configured == 1) {
					RC = _start();
					if (RC == XAIE_OK) {
						State.Running = 1;
					}
				} else {
					Logger::log(LogLevel::ERROR) << __func__ << " " <<
						typeid(*this).name() << " resource is not configured." << std::endl;
					RC = XAIE_ERR;
				}
			} else {
				Logger::log(LogLevel::ERROR) << __func__ << " " <<
					typeid(*this).name() << " resource is not allocated." << std::endl;
				RC = XAIE_ERR;
			}
			return RC;
		}
		/**
		 * This function stops using the resource by removing the config
		 * from hardware. But the resource are still occupied after this
		 * funtion.
		 *
		 * @return XAIE_OK for success, and error code for failure.
		 */
		AieRC stop() {
			AieRC RC = XAIE_OK;

			if (State.Running == 0) {
				RC = XAIE_OK;
			} else {
				RC = _stop();
				if (RC == XAIE_OK) {
					State.Running = 0;
				}
			}
			return RC;
		}
		/**
		 * This function checks if resource has been initialized.
		 *
		 * @return true if resource has been initialized, false otherwise.
		 */
		bool isInitialized() const {
			return State.Initialized;
		}
		/**
		 * This function checks if resource has been reserved.
		 *
		 * @return true if resource has been reserved, false otherwise.
		 */
		bool isReserved() const {
			return State.Reserved;
		}
		/**
		 * This function checks if resource has been configured.
		 *
		 * @return true if resource configure in software is done,
		 *	   false otherwise.
		 */
		bool isConfigured() const {
			return State.Configured;
		}
		/**
		 * This function checks if resource is in use.
		 *
		 * @return true if resource is in use, falsei otherwise.
		 */
		bool isRunning() const {
			return State.Running;
		}

		/**
		 * This function returns resources reserved.
		 *
		 * @param vOutRscs vector to store the reserved resources
		 */
		void getReservedRscs(std::vector<XAieUserRsc> &vOutRscs) const {
			if (State.Reserved != 0) {
				_getReservedRscs(vOutRscs);
			}
		}
		/**
		 * This function returns resources to be reserved.
		 *
		 * @param vOutRscs vector to store the resources
		 * @return XAIE_OK for success, error code for failure
		 */
		AieRC getRscs(std::vector<XAieUserRsc> &vOutRscs) {
			_getRscs(vOutRscs);
			return XAIE_OK;
		}
		/**
		 * This function sets the resources
		 *
		 * @param vInRscs vector to set resources from
		 * @return XAIE_OK for success, error code for failure
		 */
		AieRC setRscs(std::vector<XAieUserRsc> &vInRscs) {
			_setRscs(vInRscs);
			return XAIE_OK;
		}
		/**
		 * This function returns resources type.
		 *
		 * @return resource type
		 */
		virtual XAieRscType getRscType() const {
			return Type;
		}
		/**
		 * This function returns resources static for a specific
		 * group of this type of resource.
		 *
		 * @param GName resource group name
		 * @return resource group resource statistics of this type of
		 *	resource of specific tiles/module
		 */
		virtual XAieRscStat getRscStat(const std::string &GName) const {
			XAieRscStat RscStat(GName);
			std::string rName(typeid(*this).name());
			(void) GName;

			throw std::invalid_argument("get rsc stat not supported of rsc" +
					rName);
		}
		/**
		 * This funtion returns AI engine device
		 */
		XAie_DevInst *dev() {
			return AieHd->dev();
		}

		/**
		 * This function returns number of available child resources
		 * which is managed by this resource in AIEFAL
		 */
		virtual uint32_t getAvailManagedRscs() {
			std::string rName(typeid(*this).name());
			throw std::invalid_argument("get max rsc num not supported of rsc " +
					rName);
		}

		/**
		 * This function returns the type of child resources
		 * which is managed by this resource in AIEFAL
		 */
		virtual XAieRscType getManagedRscsType() {
			std::string rName(typeid(*this).name());
			throw std::invalid_argument("get managed rsc type not supported of rsc " +
					rName);
		}

	protected:
		XAieRscState State; /**< resource state */
		XAieRscType Type; /**< resource type */
		std::shared_ptr<XAieDevHandle> AieHd; /**< AI engine device instance */
		uint32_t preferredId; /**< preferred resource Id */
		uint32_t reservedId; /**< reserved resource Id */
		std::vector<XAieUserRsc> vRscs; /**< resources data*/
	private:
		/**
		 * This function will be called by reserve(). It allows child
		 * class to implement its own resource reservation.
		 *
		 * @return XAIE_OK for success, error code for failure.
		 */
		virtual AieRC _reserve() {return XAIE_OK;}
		/**
		 * This function will be called by release(). It allows child
		 * class to implement its own resource release.
		 *
		 * @return XAIE_OK for success, error code for failure.
		 */
		virtual AieRC _release() {return XAIE_OK;}
		/**
		 * This function will be called by free(). It allows child
		 * class to implement its own prereserved resource free.
		 *
		 * @return XAIE_OK for success, error code for failure.
		 */
		virtual AieRC _free() {return XAIE_OK;}
		/**
		 * This function will be called by start(). It allows child
		 * class to implement its own resource start.
		 *
		 * @return XAIE_OK for success, error code for failure.
		 */
		virtual AieRC _start() {return XAIE_OK;}
		/**
		 * This function will be called by stop(). It allows child
		 * class to implement its own resource stop.
		 *
		 * @return XAIE_OK for success, error code for failure.
		 */
		virtual AieRC _stop() {return XAIE_OK;}

		/**
		 * This function returns resources reserved.
		 *
		 * @param vOutRscs vector to store the reserved resources
		 */
		virtual void _getReservedRscs(std::vector<XAieUserRsc> &vOutRscs) const {
			std::string rName(typeid(*this).name());

			(void)vOutRscs;
			throw std::invalid_argument("get resource not supported of rsc" +
					rName);
		}
		/**
		 * This function returns resources to be reserved
		 *
		 * @param vOutRscs vector to store the reserved resources
		 */
		virtual void _getRscs(std::vector<XAieUserRsc> &vOutRscs) {
			vOutRscs.insert(vOutRscs.end(), vRscs.begin(), vRscs.end());
		}
		/**
		 * This function sets the resources to be reserved
		 *
		 * @param vInRscs vector to set the resources to
		 */
		virtual void _setRscs(std::vector<XAieUserRsc> &vInRscs) {
			vRscs = vInRscs;
		}
	};

	/**
	 * @class XAieSingleTileRsc
	 * @brief class of resource of a single tile
	 */
	class XAieSingleTileRsc: public XAieRsc {
	public:
		XAieSingleTileRsc() = delete;
		XAieSingleTileRsc(std::shared_ptr<XAieDevHandle> DevHd,
			XAie_LocType Loc, XAie_ModuleType Mod):
			XAieRsc(DevHd), Loc(Loc), Mod(Mod) {
			if (_XAie_CheckModule(AieHd->dev(), Loc, Mod) !=
				XAIE_OK) {
				throw std::invalid_argument("invalid module tile");
			}
		}
		XAieSingleTileRsc(std::shared_ptr<XAieDevHandle> DevHd,
			XAie_LocType Loc, XAie_ModuleType Mod, XAieRscType Type):
			XAieRsc(DevHd, Type), Loc(Loc), Mod(Mod) {
			if (_XAie_CheckModule(AieHd->dev(), Loc, Mod) !=
				XAIE_OK) {
				throw std::invalid_argument("invalid module tile");
			}
		}
		XAieSingleTileRsc(XAieDev &Dev,
			XAie_LocType Loc, XAie_ModuleType Mod):
			XAieSingleTileRsc(Dev.getDevHandle(), Loc, Mod) {}
		XAieSingleTileRsc(XAieDev &Dev,
			XAie_LocType Loc, XAie_ModuleType Mod, XAieRscType Type):
			XAieSingleTileRsc(Dev.getDevHandle(), Loc, Mod, Type) {}
		XAieSingleTileRsc(std::shared_ptr<XAieDevHandle> DevHd,
			XAie_LocType Loc):
			XAieRsc(DevHd), Loc(Loc) {
			uint8_t TType = _XAie_GetTileTypefromLoc(
					AieHd->dev(), Loc);
			if (TType == XAIEGBL_TILE_TYPE_MAX) {
				throw std::invalid_argument("Invalid tile");
			}
			if (TType == XAIEGBL_TILE_TYPE_AIETILE) {
				Mod = XAIE_CORE_MOD;
			} else if (TType == XAIEGBL_TILE_TYPE_SHIMPL ||
					TType == XAIEGBL_TILE_TYPE_SHIMNOC) {
				Mod = XAIE_PL_MOD;
			} else {
				Mod = XAIE_MEM_MOD;
			}
		}
		XAieSingleTileRsc(std::shared_ptr<XAieDevHandle> DevHd,
			XAie_LocType Loc, XAieRscType Type):
			XAieRsc(DevHd, Type), Loc(Loc){
			uint8_t TType = _XAie_GetTileTypefromLoc(
					AieHd->dev(), Loc);
			if (TType == XAIEGBL_TILE_TYPE_MAX) {
				throw std::invalid_argument("Invalid tile");
			}
			if (TType == XAIEGBL_TILE_TYPE_AIETILE) {
				Mod = XAIE_CORE_MOD;
			} else if (TType == XAIEGBL_TILE_TYPE_SHIMPL ||
					TType == XAIEGBL_TILE_TYPE_SHIMNOC) {
				Mod = XAIE_PL_MOD;
			} else {
				Mod = XAIE_MEM_MOD;
			}
		}
		XAieSingleTileRsc(XAieDev &Dev, XAie_LocType Loc, XAieRscType Type):
			XAieSingleTileRsc(Dev.getDevHandle(), Loc, Type) {}
		virtual ~XAieSingleTileRsc() {}
		/**
		 * This function returns tile location
		 *
		 * @return tile location
		 */
		XAie_LocType loc() const {
			return Loc;
		}
		/**
		 * This function returns module type
		 *
		 * @return module type
		 */
		XAie_ModuleType mod() const {
			return Mod;
		}
		/**
		 * This function returns resource id
		 *
		 * @param OutLoc returns tile location
		 * @param OutMod returns module type
		 * @param OutRscId returns resource ID
		 * @return XAIE_OK for success, error code for failure
		 */
		AieRC getRscId(XAie_LocType &OutLoc, XAie_ModuleType &OutMod,
				uint32_t &OutRscId) {
			AieRC RC = XAIE_ERR;

			if (State.Reserved == 0) {
				Logger::log(LogLevel::ERROR) << typeid(*this).name() << " " <<
					__func__ << "(" <<
					(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
					" Expect Mod= " << Mod <<
					" resource not reserved." << std::endl;
			} else {
				if (vRscs.size() > 0) {
					OutMod = vRscs[0].Mod;
					OutRscId = reservedId;
				}
				OutLoc = Loc;
				RC = XAIE_OK;
			}
			return RC;
		}
		virtual XAieRscStat getRscStat(const std::string &GName) const {
			XAieRscStat RscStat(GName);
			(void) GName;

			if (preferredId == XAIE_RSC_ID_ANY) {
				return AieHd->getRscGroup(GName).getRscStat(Loc,
						Mod, getRscType());
			} else {
				return AieHd->getRscGroup(GName).getRscStat(Loc,
						Mod, getRscType(), preferredId);
			}
		}
	protected:
		XAie_LocType Loc; /**< tile location */
		XAie_ModuleType Mod; /**< expected resource module */
	private:
		/**
		 * This function returns resources reserved.
		 *
		 * @param vOutRscs vector to store the reserved resources
		 */
		virtual void _getReservedRscs(std::vector<XAieUserRsc> &vOutRscs) const {
			if (vRscs.size() > 0) {
				vOutRscs.push_back(vRscs[0]);
			}
		}
	};

	struct XAieRscGetRscsWrapper {
		XAieRscGetRscsWrapper() = delete;
		XAieRscGetRscsWrapper(std::shared_ptr<XAieRsc> &Rsc,
				std::vector<XAieUserRsc> &Rscs) {
			Rsc->getReservedRscs(Rscs);
		}
		~XAieRscGetRscsWrapper() {};
	};
}
