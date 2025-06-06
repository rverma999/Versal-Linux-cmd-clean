// Copyright(C) 2020 - 2021 by Xilinx, Inc. All rights reserved.
// SPDX-License-Identifier: MIT

#include <string.h>
#include <vector>
#include <xaiengine.h>

#include <xaiefal/common/xaiefal-common.hpp>
#include <xaiefal/rsc/xaiefal-rsc-base.hpp>
#include <xaiefal/rsc/xaiefal-rscmgr.hpp>

#pragma once

namespace xaiefal {
	/**
	 * @class XAieGroupEvent
	 * @brief class for group event resource
	 */
	class XAieGroupEvent: public XAieSingleTileRsc {
	public:
		XAieGroupEvent() = delete;
		XAieGroupEvent(std::shared_ptr<XAieDevHandle> DevHd,
			XAie_LocType Loc, XAie_ModuleType Mod, XAie_Events gEvent):
			XAieSingleTileRsc(DevHd, Loc, Mod, XAIE_GROUPEVENT),
			GroupEvent(gEvent), GroupComposition(0) {
			uint32_t GroupId;

			if (getGroupId(DevHd, Mod, gEvent, GroupId) != XAIE_OK) {
				throw std::invalid_argument("Invalid group Event");
			}

			State.Initialized = 1;
			State.Configured = 1;
			preferredId = static_cast<uint32_t>(GroupEvent);
		}

		/**
		 * This function is to return group event
		 *
		 * @return Group event
		 */
		XAie_Events getEvent() const {
			return GroupEvent;
		}

		/**
		 * This function is to attach group event handle.
		 *
		 * @param Hid group event handle id
		 * @param Comp composition
		 * @return XAIE_OK for success, and error code for failure.
		 *
		 * If the group event is not reserved, this function will
		 * add the input reference to the reference list, and reserve
		 * the group event resource. If the group event has been
		 * reserved, it will only add the reference to the list if the
		 * group event enabling setting is the same as what's been
		 * reserved.
		 */
		AieRC attachHandle(const XAieGroupEventHandle *Hid, uint32_t Comp) {
			AieRC RC;

			_XAIEFAL_MUTEX_ACQUIRE(mLock);

			if (Hid == nullptr) {
				Logger::log(LogLevel::ERROR) << "Group event " << __func__ << " (" <<
					(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
					" Mod=" << Mod << ", empty handle." << std::endl;
				return XAIE_INVALID_ARGS;
			}
			if (State.Reserved == 1) {
				if (GroupComposition != Comp) {
					Logger::log(LogLevel::ERROR) << "Group event " << __func__ << " (" <<
						(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
						" Mod=" << Mod << "(" <<
						GroupEvent << ") is reserved with " <<
						GroupComposition << ", request composition is " <<
						Comp << "." << std::endl;
					RC = XAIE_INVALID_ARGS;
				} else {
					Handles.emplace(Hid, false);
					RC = XAIE_OK;
				}
			} else {
				RC = reserve();
				if (RC == XAIE_OK) {
					GroupComposition = Comp;
					Handles.emplace(Hid, false);
				}
			}

			return RC;
		}

		/**
		 * This function is to start the group event handle.
		 *
		 * @param Hid groupe event handle id
		 * @return XAIE_OK for success, and error code for failure
		 *
		 * This function will validate the reference, if it is valid,
		 * it will add it to the inuse references list, if the list
		 * was empty, it will configure the group event.
		 */
		AieRC startHandle(const XAieGroupEventHandle *Hid) {
			AieRC RC = XAIE_OK;

			auto H = Handles.find(Hid);
			if (H == Handles.end()) {
				Logger::log(LogLevel::ERROR) << "Group event " << __func__ << " (" <<
					(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
					" Mod=" << Mod <<
					" group event(" << GroupEvent <<
					"), invalid handle." << std::endl;
				RC = XAIE_INVALID_ARGS;
			} else {
				_XAIEFAL_MUTEX_ACQUIRE(mLock);

				Handles[Hid] = true;
				if (State.Running == 0) {
					RC = start();
					if (RC != XAIE_OK) {
						Handles[Hid] = false;
					}
				}
			}
			return RC;
		}

		/**
		 * This function is to stop the group event handle.
		 *
		 * @param Hid groupe event handle ID
		 * @return XAIE_OK for success, and error code for failure
		 *
		 * This function will remove the referece from the inuse
		 * references list, if the list is empty after removal, it
		 * will reset the group event configuration.
		 */
		AieRC stopHandle(const XAieGroupEventHandle *Hid) {
			AieRC RC = XAIE_OK;

			auto H = Handles.find(Hid);
			if (H == Handles.end()) {
				Logger::log(LogLevel::ERROR) << "Group event " << __func__ << " (" <<
					(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
					" Mod=" << Mod <<
					" group event(" << GroupEvent <<
					"), invalid handle." << std::endl;
				RC = XAIE_INVALID_ARGS;
			} else {
				_XAIEFAL_MUTEX_ACQUIRE(mLock);

				Handles[Hid] = false;
				// Have considered to use a StartCount to
				// count how many handles are in use.
				// However, considering every module needs
				// such variable, even for loop which is
				// less efficient then just a Starcount,
				// use for loop to save memory, as this is
				// not in performance critical path as it is
				// used for profiling and debugging.
				std::map<const XAieGroupEventHandle *, bool>::iterator it;
				for (it = Handles.begin(); it != Handles.end();
				     it++) {
					if (it->second) {
						break;
					}
				}
				if (it == Handles.end()) {
					if (State.Running == 1) {
						RC = stop();
						if (RC != XAIE_OK) {
							Handles[Hid] = true;
						}
					}
				}
			}
			return RC;
		}

		/**
		 * This function is to remove the group event handle.
		 *
		 * @param Hid groupe event handle ID
		 * @return XAIE_OK for success, and error code for failure
		 *
		 * This function will remove the referece from the
		 * references list, if the list is empty after removal, it
		 * will release the group event resource.
		 */
		AieRC removeHandle(const XAieGroupEventHandle *Hid) {
			AieRC RC = XAIE_OK;

			auto H = Handles.find(Hid);
			if (H == Handles.end()) {
				Logger::log(LogLevel::ERROR) << "Group event " << __func__ << " (" <<
					(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
					" Mod=" << Mod <<
					" group event(" << GroupEvent <<
					"), invalid handle." << std::endl;
				RC = XAIE_INVALID_ARGS;
			} else {
				_XAIEFAL_MUTEX_ACQUIRE(mLock);

				Handles.erase(Hid);
				if (State.Reserved == 1 && Handles.empty()) {
					RC = release();
				}
			}
			return RC;
		}

		uint32_t getRscIdfromEvent(XAie_Events Event) {
			uint8_t TileType;
			const XAie_EvntMod *EvntMod;

			TileType = _XAie_GetTileTypefromLoc(AieHd->dev(), Loc);

			if (Mod == XAIE_PL_MOD) {
				EvntMod = &AieHd->dev()->DevProp.DevMod[TileType].EvntMod[0U];
			} else {
				EvntMod = &AieHd->dev()->DevProp.DevMod[TileType].EvntMod[Mod];
			}

			for (uint8_t i = 0; i < EvntMod->NumGroupEvents; i++) {
				if (Event == EvntMod->Group[i].GroupEvent) {
					return EvntMod->Group[i].GroupOff;
				}
			}
			return XAIE_RSC_ID_ANY;
		}
	private:
		XAie_Events GroupEvent; /**< group event */
		uint32_t GroupComposition; /**< group event configuration */
		_XAIEFAL_MUTEX_DECLARE(mLock); /**< group config mutex lock */
		std::map<const XAieGroupEventHandle *, bool> Handles; /**< Group events handles */

	protected:
		AieRC _reserve() {
			AieRC RC;
			XAieUserRsc Rsc;

			Rsc.Loc = Loc;
			Rsc.Mod = Mod;
			Rsc.RscType = Type;
			Rsc.RscId = getRscIdfromEvent(GroupEvent);
			vRscs.push_back(Rsc);
			RC = AieHd->rscMgr()->request(*this);
			if (RC != XAIE_OK) {
				Logger::log(LogLevel::WARN) << "groupevent " << __func__ << " (" <<
					(uint32_t)Loc.Col << "," << (uint32_t)Loc.Row << ")" <<
					" Mod=" << Mod << " resource not available.\n";
				vRscs.clear();
			} else {
				reservedId = vRscs[0].RscId;
			}
			return RC;
		}
		AieRC _release() {
			AieRC RC;

			RC = AieHd->rscMgr()->free(*this);
			vRscs.clear();
			return RC;
		}
		AieRC _start() {
			uint32_t lConfig = GroupComposition;

			if (lConfig == 0) {
				lConfig = 0xFFFFFFFFU;
			}
			return XAie_EventGroupControl(dev(), Loc, Mod, GroupEvent,
					lConfig);
		}
		AieRC _stop() {
			return XAie_EventGroupReset(dev(), Loc, Mod, GroupEvent);
		}

	private:
		/**
		 * TODO: Following function will not be required.
		 * Bitmap will be moved to device driver
		 */
		/**
		 * This function returns group ID of the group event.
		 *
		 * @param DevHd AI engine device handler
		 * @param Mod module type
		 * @param Event group event
		 * @param RscId returns the group ID of the group event
		 * @return XAIE_OK for success, and error code for failure
		 */
		static AieRC getGroupId(std::shared_ptr<XAieDevHandle> DevHd,
				XAie_ModuleType Module, XAie_Events Event, uint32_t &RscId) {
			uint32_t i, *EIds;
			uint32_t EIdsTotal;
			AieRC RC;

			if (Module == XAIE_CORE_MOD) {
				EIds = DevHd->XAieGroupEventMapCore;
				EIdsTotal = sizeof(DevHd->XAieGroupEventMapCore)/
					sizeof(DevHd->XAieGroupEventMapCore[0]);
			} else if (Module == XAIE_MEM_MOD) {
				if (Event >= XAIE_EVENT_GROUP_0_MEM_TILE) {
					EIds = DevHd->XAieGroupEventMapMemTile;
					EIdsTotal = sizeof(DevHd->XAieGroupEventMapMemTile)/
						sizeof(DevHd->XAieGroupEventMapMemTile[0]);
				} else {
					EIds = DevHd->XAieGroupEventMapMem;
					EIdsTotal = sizeof(DevHd->XAieGroupEventMapMem)/
						sizeof(DevHd->XAieGroupEventMapMem[0]);
				}
			} else {
				EIds = DevHd->XAieGroupEventMapPl;
				EIdsTotal = sizeof(DevHd->XAieGroupEventMapPl)/
					sizeof(DevHd->XAieGroupEventMapPl[0]);
			}
			for (i = 0; i < EIdsTotal; i++) {
				if (Event == EIds[i]) {
					RscId = i;
					break;
				}
			}
			if (i >= EIdsTotal) {
				RC = XAIE_INVALID_ARGS;
				Logger::log(LogLevel::ERROR) << "Group event " << __func__ << " (" <<
					" Mod=" << Module << " " << Event <<
					" invalid." << std::endl;
			} else {
				RC = XAIE_OK;
			}
			return RC;
		}
	};

	/**
	 * @class XAieGroupEventHandle
	 * @brief class for group event resource reference
	 */
	class XAieGroupEventHandle: public XAieRsc {
	public:
		XAieGroupEventHandle() = delete;
		XAieGroupEventHandle(std::shared_ptr<XAieDevHandle> DevHd,
			std::shared_ptr<XAieGroupEvent> gEPtr):
			XAieRsc(DevHd), GroupEventPtr(gEPtr), GroupComposition(0) {
			State.Initialized = 1;
			State.Configured = 1;
		}

		/**
		 * This function is to set group event events enabling bits.
		 *
		 * @param Comp composition
		 *
		 * If the events bits is set, when the corresponding events
		 * are set, the group event will set.
		 */
		void setGroupEvents(uint32_t Comp) {
			GroupComposition = Comp;
		}

		/**
		 * This function is to get group event events enabling bits.
		 *
		 * @return group event events enabling bits.
		 */
		uint32_t getGroupEvents() const {
			return GroupComposition;
		}

		/**
		 * This function returns group event
		 * @return group event
		 */
		XAie_Events getEvent() const {
			return GroupEventPtr->getEvent();
		}
	protected:
		AieRC _reserve() {
			return GroupEventPtr->attachHandle(this, GroupComposition);
		}
		AieRC _release() {
			return GroupEventPtr->removeHandle(this);
		}
		AieRC _start() {
			return GroupEventPtr->startHandle(this);
		}
		AieRC _stop() {
			return GroupEventPtr->stopHandle(this);
		}
	private:
		std::shared_ptr<XAieGroupEvent> GroupEventPtr; /**< group event reference */
		uint32_t GroupComposition; /**< group event configuration */
	};
}
