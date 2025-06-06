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
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <xaiengine.h>
#include <xaiefal/common/xaiefal-common.hpp>
#include <xaiefal/common/xaiefal-log.hpp>
#include <xaiefal/rsc/xaiefal-rsc-group.hpp>

#pragma once

namespace xaiefal {
	class XAieDevHandle;
	class XAieMod;
	class XAieTile;
	class XAieBroadcast;
	class XAieComboEvent;
	class XAieGroupEvent;
	class XAieGroupEventHandle;
	class XAieUserEvent;
	class XAiePerfCounter;
	class XAieTraceCntr;
	class XAieTraceEvent;
	class XAieActiveCycles;
	class XAieStallCycles;
	class XAieStallOccurrences;
	class XAiePCEvent;
	class XAiePCRange;
	class XAieStreamPortSelect;
	class XAieRscGroupRuntime;
	class XAieRscGroupStatic;
	class XAieRscGroupAvail;
	class XAieRscMgr;

# define XAIEDEV_DEFAULT_GROUP_STATIC "Static"
# define XAIEDEV_DEFAULT_GROUP_AVAIL "Avail"
# define XAIEDEV_DEFAULT_GROUP_GENERIC "Generic"

	/**
	 * @class XAieDevHdRscGroupWrapper
	 * @brief AI engine device handle resource group wrapper
	 */
	class XAieDevHdRscGroupWrapper {
	public:
		XAieDevHdRscGroupWrapper() {};
		XAieDevHdRscGroupWrapper(std::shared_ptr<XAieRscGroupBase> RGroup):
			RscGroup(RGroup) {}
		~XAieDevHdRscGroupWrapper() {}

		XAieRscStat getRscStat() const {
			return RscGroup->getRscStat();
		}
		XAieRscStat getRscStat(XAie_LocType Loc) const {
			return RscGroup->getRscStat(Loc);
		}
		XAieRscStat getRscStat(XAie_LocType Loc, XAieRscType RscType) const {
			return RscGroup->getRscStat(Loc, RscType);
		}
		XAieRscStat getRscStat(XAie_LocType Loc, XAie_ModuleType Mod) const {
			return RscGroup->getRscStat(Loc, Mod);
		}
		XAieRscStat getRscStat(XAie_LocType Loc, XAie_ModuleType Mod,
			XAieRscType RscType) const {
			return RscGroup->getRscStat(Loc, Mod, RscType);
		}
		XAieRscStat getRscStat(XAie_LocType Loc, XAie_ModuleType Mod,
			XAieRscType RscType, uint32_t RscId) const {
			return RscGroup->getRscStat(Loc, Mod, RscType,
					RscId);
		}
		XAieRscStat getRscStat(const std::vector<XAie_LocType> &vLocs,
			XAieRscType RscType) const {
			return RscGroup->getRscStat(vLocs, RscType);
		}
		XAieRscStat getRscStat(const std::vector<XAie_LocType> &vLocs,
			XAieRscType RscType, uint32_t RscId) const {
			return RscGroup->getRscStat(vLocs, RscType, RscId);
		}

		template<class RT>
		AieRC addRsc(std::shared_ptr<RT> Rsc) {
			return RscGroup->addRsc(Rsc);
		}
	private:
		std::shared_ptr<XAieRscGroupBase> RscGroup ; /**< Resource Group */
	};

	/**
	 * @class XAieDevHandle
	 * @brief AI engine low level device pointer handle.
	 */
	class XAieDevHandle: public std::enable_shared_from_this<XAieDevHandle>{
	public:
		XAieDevHandle(XAie_DevInst *DevPtr,
			bool TurnOnFinishOnDestruct = false):
			Dev(DevPtr),
			FinishOnDestruct(TurnOnFinishOnDestruct) {
			if (DevPtr == nullptr) {
				throw std::invalid_argument("AI engine device is NULL");
			}

			XAieGroupEventMapCore[0] = XAIE_EVENT_GROUP_0_CORE;
			XAieGroupEventMapCore[1] = XAIE_EVENT_GROUP_PC_EVENT_CORE;
			XAieGroupEventMapCore[2] = XAIE_EVENT_GROUP_CORE_STALL_CORE;
			XAieGroupEventMapCore[3] = XAIE_EVENT_GROUP_CORE_PROGRAM_FLOW_CORE;
			XAieGroupEventMapCore[4] = XAIE_EVENT_GROUP_ERRORS_0_CORE;
			XAieGroupEventMapCore[5] = XAIE_EVENT_GROUP_ERRORS_1_CORE;
			XAieGroupEventMapCore[6] = XAIE_EVENT_GROUP_STREAM_SWITCH_CORE;
			XAieGroupEventMapCore[7] = XAIE_EVENT_GROUP_BROADCAST_CORE;
			XAieGroupEventMapCore[8] = XAIE_EVENT_GROUP_USER_EVENT_CORE;

			XAieGroupEventMapMem[0] = XAIE_EVENT_GROUP_0_MEM;
			XAieGroupEventMapMem[1] = XAIE_EVENT_GROUP_WATCHPOINT_MEM;
			XAieGroupEventMapMem[2] = XAIE_EVENT_GROUP_DMA_ACTIVITY_MEM;
			XAieGroupEventMapMem[3] = XAIE_EVENT_GROUP_LOCK_MEM;
			XAieGroupEventMapMem[4] = XAIE_EVENT_GROUP_MEMORY_CONFLICT_MEM;
			XAieGroupEventMapMem[5] = XAIE_EVENT_GROUP_ERRORS_MEM;
			XAieGroupEventMapMem[6] = XAIE_EVENT_GROUP_BROADCAST_MEM;
			XAieGroupEventMapMem[7] = XAIE_EVENT_GROUP_USER_EVENT_MEM;

			XAieGroupEventMapPl[0] = XAIE_EVENT_GROUP_0_PL;
			XAieGroupEventMapPl[1] = XAIE_EVENT_GROUP_DMA_ACTIVITY_PL;
			XAieGroupEventMapPl[2] = XAIE_EVENT_GROUP_LOCK_PL;
			XAieGroupEventMapPl[3] = XAIE_EVENT_GROUP_ERRORS_PL;
			XAieGroupEventMapPl[4] = XAIE_EVENT_GROUP_STREAM_SWITCH_PL;
			XAieGroupEventMapPl[5] = XAIE_EVENT_GROUP_BROADCAST_A_PL;
			XAieGroupEventMapPl[6] = XAIE_EVENT_GROUP_USER_EVENT_PL;

			XAieGroupEventMapMemTile[0] = XAIE_EVENT_GROUP_0_MEM_TILE;
			XAieGroupEventMapMemTile[1] = XAIE_EVENT_GROUP_WATCHPOINT_MEM_TILE;
			XAieGroupEventMapMemTile[2] = XAIE_EVENT_GROUP_DMA_ACTIVITY_MEM_TILE;
			XAieGroupEventMapMemTile[3] = XAIE_EVENT_GROUP_LOCK_MEM_TILE;
			XAieGroupEventMapMemTile[4] = XAIE_EVENT_GROUP_STREAM_SWITCH_MEM_TILE;
			XAieGroupEventMapMemTile[5] = XAIE_EVENT_GROUP_MEMORY_CONFLICT_MEM_TILE;
			XAieGroupEventMapMemTile[6] = XAIE_EVENT_GROUP_ERRORS_MEM_TILE;
			XAieGroupEventMapMemTile[7] = XAIE_EVENT_GROUP_BROADCAST_MEM_TILE;
			XAieGroupEventMapMemTile[8] = XAIE_EVENT_GROUP_USER_EVENT_MEM_TILE;
		}
		~XAieDevHandle() {
			if (FinishOnDestruct) {
				XAie_Finish(Dev);
			}
		}
		/**
		 * This function returns AI engine device pointer.
		 *
		 * @return AI engine device instance pointer
		 */
		XAie_DevInst *dev() {
			return Dev;
		}
		/**
		 * This function returns AI engine handle shared pointer
		 *
		 * @return AI engine device shared pointer
		 */
		std::shared_ptr<XAieDevHandle> getPtr() {
			return shared_from_this();
		}
		/**
		 * This function returns AIE resource manager shared pointer
		 *
		 * @return AI engine resource manager shared pointer
		 */
		std::shared_ptr<XAieRscMgr> rscMgr() {
			return AieRscMgr;
		}

		/**
		 * This function creates a resource group based on resource
		 * group name if the resource group doesn't exist.
		 */
		template<class GT>
		void createGroup(const std::string &GName) {
			_XAIEFAL_MUTEX_ACQUIRE(mLock);
			if (RscGroupsMap.find(GName) == RscGroupsMap.end()) {
				_createGroup<GT>(GName);
			}
		}

		/**
		 * This function returns resource group based on resource
		 * group name. If the resource group doesn't exist, it will
		 * create the group.
		 *
		 * @param GName resource group name
		 * @return resource group wrapper reference
		 */
		XAieDevHdRscGroupWrapper &getRscGroup(const std::string &GName) {
			_XAIEFAL_MUTEX_ACQUIRE(mLock);
			if (RscGroupsMap.find(GName) == RscGroupsMap.end()) {
				_createGroup<XAieRscGroupRuntime>(GName);
			}
			return RscGroupsMap[GName];
		}

		/**
		 * This function remove the resource group whose name is
		 * specified.
		 *
		 * @param GName resource group name
		 */
		void removeRscGroup(const std::string &GName) {
			_XAIEFAL_MUTEX_ACQUIRE(mLock);
			auto it = RscGroupsMap.find(GName);

			if (it != RscGroupsMap.end()) {
				RscGroupsMap.erase(it);
			}
		}

		/**
		 * This function will create the resource manager and attach
		 * it to the AieHandle
		 */
		void createRscMgr() {
			AieRscMgr = std::make_shared<XAieRscMgr>(this);
		}

		uint32_t XAieGroupEventMapCore[9];
		uint32_t XAieGroupEventMapMem[8];
		uint32_t XAieGroupEventMapPl[8];
		uint32_t XAieGroupEventMapMemTile[9];
	private:
		XAie_DevInst *Dev;
		bool FinishOnDestruct;
		std::shared_ptr<XAieRscMgr> AieRscMgr; /**< Resource Manager */
		std::map <std::string, XAieDevHdRscGroupWrapper> RscGroupsMap; /**< resource groups map */
		_XAIEFAL_MUTEX_DECLARE(mLock); /**< mutex lock */

	private:
		template<class GT>
		void _createGroup(const std::string &GName) {
			auto GPtr = std::make_shared<GT>(shared_from_this(),
					GName);
			RscGroupsMap[GName] = XAieDevHdRscGroupWrapper(GPtr);
			Logger::log(LogLevel::INFO) << "Resource group " <<
				GName << " is created." << std::endl;
		}
	};

	/**
	 * @class XAieDev
	 * @brief AI engine device class. It defines AI engine device
	 *	  operations.
	 */
	class XAieDev {
	public:
		XAieDev() = delete;
		XAieDev(XAie_DevInst *DevPtr,
			bool TurnOnFinishOnDestruct = false);
		~XAieDev() {}

		/**
		 * This function returns a tile object reference.
		 *
		 * @param Loc tile Location
		 * @return tile object reference
		 */
		XAieTile &tile(XAie_LocType Loc) {
			if (Loc.Col > NumCols || Loc.Row > NumRows) {
				throw std::invalid_argument("Invalid tile location");
			}
			return Tiles[Loc.Col * NumRows + Loc.Row];
		}

		/**
		 * This function returns a tile object reference.
		 *
		 * @param Col absolute column index
		 * @param Row absolute row index, 0 is shim row
		 * @return tile object reference
		 */
		XAieTile &tile(uint8_t Col, uint32_t Row) {
			return tile(XAie_TileLoc(Col, Row));
		}

		/**
		 * This function returns AI engine device pointer.
		 *
		 * @return AI engine device pointer.
		 */

		XAie_DevInst *dev() {
			return AieHandle->dev();
		}

		/**
		 * This function returns AI engine device handle
		 *
		 * @return AI engine device handle
		 */
		std::shared_ptr<XAieDevHandle> getDevHandle() {
			return AieHandle->getPtr();
		}

		/**
		 * This function returns requested resource group.
		 * If the resource group already exists, it returns it; if not,
		 * create the group.
		 *
		 * @param GName resource group name
		 * @return resource group wrapper
		 */
		XAieDevHdRscGroupWrapper &getRscGroup(const std::string &GName) {
			return AieHandle->getRscGroup(GName);
		}

		/**
		 * This function remove the resource group specified by the
		 * resource group name
		 *
		 * @param GName resource group name
		 */
		void removeRscGroup(const std::string &GName) {
			AieHandle->removeRscGroup(GName);
		}

		/**
		 * This function returns requested resource group resource statistics
		 *
		 * @param GName resource group name
		 * @return resource group resource statistics
		 */
		XAieRscStat getRscStat(const std::string &GName) {
			return AieHandle->getRscGroup(GName).getRscStat();
		}

		/**
                 * This function saves all runtime allocated resources
                 * metadata to given filename
                 *
                 * @param File filename string
                 * @return XAIE_OK for success, error code for failure
                 */
                AieRC saveAllocatedRscsToFile(const std::string &File);

                /**
                 * This loads resource metadata into the static resource
                 * bitmaps
                 *
                 * @param MetaData pointer to resource metadata
                 * @return XAIE_OK for success, error code for failure
                 */
                AieRC loadStaticRscsFromMem(const char *MetaData);

                /**
                 * This function makes a call to RscMgr Backend to reserve
                 * resources necessary for ECC
                 *
                 * @return XAIE_OK for success, error code for failure
                 */
                AieRC reserveEcc();

                /**
                 * This function makes a call to RscMgr Backend to reserve
                 * resources necessary for Error Handling
                 *
                 * @return XAIE_OK for success, error code for failure
                 */
                AieRC reserveErrorHandling();


		/**
		 * This function returns broadcast resource software object
		 * within a tile.
		 *
		 * @param vLocs vector of tile locations
		 * @param StartM starting module of the broadcast channel
		 * @param EndM Ending module of the broadcast channel
		 * @param GName resource group name
		 * @return broadcast channel software object pointer within a
		 *  tile.
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieBroadcast> broadcast(
			std::vector<XAie_LocType> &vLocs, XAie_ModuleType StartM,
			XAie_ModuleType EndM,
			XAieDevHdRscGroupWrapper &RGroup) {
			auto BC = std::make_shared<XAieBroadcast>(*this, vLocs,
					StartM, EndM);
			RGroup.addRsc(BC);
			return BC;
		}
		std::shared_ptr<XAieBroadcast> broadcast(
			std::vector<XAie_LocType> &vLocs, XAie_ModuleType StartM,
			XAie_ModuleType EndM) {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");
			return broadcast(vLocs, StartM, EndM, RGroup);
		}

		/**
		 * This function returns module type string.
		 *
		 * @param Mod module type
		 * @param MString returns module type name in string
		 * @return XAIE_OK for success, error code for failure
		 */
		AieRC modToString(XAie_ModuleType Mod, std::string &MString) {
			AieRC RC = XAIE_OK;

			if (Mod == XAIE_CORE_MOD) {
				MString = "core";
			} else if (Mod == XAIE_MEM_MOD) {
				MString = "memory";
			} else if (Mod == XAIE_PL_MOD) {
				MString = "shim";
			} else {
				RC = XAIE_INVALID_ARGS;
				Logger::log(LogLevel::ERROR) << __func__ <<
					"failed. invalid module type." <<
					std::endl;
			}
			return RC;
		}
		/**
		 * This function returns module type from module name string.
		 *
		 * @param MString module type name in string
		 * @param Mod returns module type
		 * @return XAIE_OK for success, error code for failure
		 */
		AieRC stringToMod(const std::string &MString,
			XAie_ModuleType &Mod) {
			AieRC RC = XAIE_OK;

			if (MString == "core") {
				Mod = XAIE_CORE_MOD;
			} else if (MString == "memory") {
				Mod = XAIE_MEM_MOD;
			} else if (MString == "shim") {
				Mod = XAIE_PL_MOD;
			} else {
				RC = XAIE_INVALID_ARGS;
				Logger::log(LogLevel::ERROR) << __func__ <<
				"failed. invalid module string." << std::endl;
			}
			return RC;
		}

	private:
		std::shared_ptr<XAieDevHandle> AieHandle; /**< AI engine device handle */
		uint32_t NumCols; /**< number of AI engine columns */
		uint32_t NumRows; /**< number of AI engine rows */
		std::vector<XAieTile> Tiles;
	};

	/**
	 * @class XAieMod
	 * @brief AI enigne module. It defines AI engine module operations.
	 *	  such as get resource within a module.
	 */
	class XAieMod {
	public:
		XAieMod() {};
		XAieMod(XAieDev &Dev, XAie_LocType Loc, XAie_ModuleType Mod):
			AieHandle(Dev.getDevHandle()), Loc(Loc), Mod(Mod) {
			if (_XAie_CheckModule(AieHandle->dev(), Loc, Mod) !=
				XAIE_OK) {
				throw std::invalid_argument("Invalid module and tile");
			}
			AieHandle = Dev.getDevHandle();
			TraceCntr = std::make_shared<XAieTraceCntr>(AieHandle,
					Loc, Mod);
			AieHandle->getRscGroup("Generic").addRsc(TraceCntr);
			AieHandle->getRscGroup("Avail").addRsc(TraceCntr);
		}
		~XAieMod() {}

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
		 * This function returns requested resource group resource
		 * statistics of the tile.
		 *
		 * @param GName resource group name
		 * @return resource group resource statistics
		 */
		XAieRscStat getRscStat(const std::string &GName) {
			return AieHandle->getRscGroup(GName).getRscStat(Loc, Mod);
		}

		/**
		 * This function returns perfcounter resource software object
		 * of the module.
		 *
		 * @param RGroup resource group
		 * @return perfconter software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAiePerfCounter> perfCounter(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto Rsc = std::make_shared<XAiePerfCounter>(AieHandle,
					Loc, Mod);

			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAiePerfCounter> perfCounter() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return perfCounter(RGroup);
		}

		/**
		 * This function returns trace control resource software object
		 * of the module.
		 *
		 * @return trace control software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieTraceCntr> traceControl() {
			return TraceCntr;
		}

		/**
		 * This function returns trace event resource software object
		 * of the module.
		 *
		 * @param RGroup resource group
		 * @return trace event software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieTraceEvent> traceEvent(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto Rsc = std::make_shared<XAieTraceEvent>(AieHandle,
				Loc, Mod, TraceCntr);

			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAieTraceEvent> traceEvent() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return traceEvent(RGroup);
		}


		/**
		 * This function returns perfcounter resource software object
		 * for active cycles.
		 *
		 * @param RGroup resource group
		 * @return perfconter software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieActiveCycles> activeCycles(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto Rsc = std::make_shared<XAieActiveCycles>(AieHandle,
					Loc);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAieActiveCycles> activeCycles() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return activeCycles(RGroup);
		}

		/**
		 * This function returns perfcounter resource software object
		 * for stall cycles.
		 *
		 * @param RGroup resource group
		 * @return perfconter software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieStallCycles> stallCycles(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto StallG = groupEvent(XAIE_EVENT_GROUP_CORE_STALL_CORE);
			auto FlowG = groupEvent(XAIE_EVENT_GROUP_CORE_PROGRAM_FLOW_CORE);
			auto Rsc = std::make_shared<XAieStallCycles>(AieHandle,
					Loc, StallG, FlowG);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAieStallCycles> stallCycles() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return stallCycles(RGroup);
		}

		/**
		 * This function returns perfcounter resource software object
		 * for stall occurences.
		 *
		 * @param RGroup resource group
		 * @return perfconter software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieStallOccurrences> stallOccurrences(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto StallG = groupEvent(XAIE_EVENT_GROUP_CORE_STALL_CORE);
			auto Rsc = std::make_shared<XAieStallOccurrences>(AieHandle,
					Loc, StallG);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAieStallOccurrences> stallOccurrences() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return stallOccurrences(RGroup);
		}

		/**
		 * This function returns PC event resource software object.
		 *
		 * @param RGroup resource group
		 * @return PC event software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAiePCEvent> pcEvent(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto Rsc = std::make_shared<XAiePCEvent>(AieHandle, Loc);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAiePCEvent> pcEvent() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return pcEvent(RGroup);
		}

		/**
		 * This function returns PC range resource software object.
		 *
		 * @param RGroup resource group
		 * @return PC range software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAiePCRange> pcRange(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto Rsc = std::make_shared<XAiePCRange>(AieHandle, Loc);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAiePCRange> pcRange() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return pcRange(RGroup);
		}

		/**
		 * This function returns combo event resource software object.
		 *
		 * @param RGroup resource group
		 * @ENum number of input events
		 * @return combo event software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieComboEvent> comboEvent(
				XAieDevHdRscGroupWrapper &RGroup,
				uint32_t ENum = 2) {
			auto Rsc = std::make_shared<XAieComboEvent>(AieHandle,
								Loc, Mod,
								ENum);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAieComboEvent> comboEvent(uint32_t ENum = 2) {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return comboEvent(RGroup, ENum);
		}

		/**
		 * This function returns group event handle object shared pointer
		 *
		 * @param RGroup resource group
		 * @Event group event
		 * @return group event handle software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieGroupEventHandle> groupEvent(
				XAieDevHdRscGroupWrapper &RGroup,
				XAie_Events Event) {
			auto gEvent = GroupEvents.find(Event);
			if (gEvent != GroupEvents.end()) {
				return std::make_shared<XAieGroupEventHandle>(
						AieHandle, GroupEvents[Event]);
			}
			auto gEPtr = std::make_shared<XAieGroupEvent>(AieHandle,
								      Loc, Mod, Event);
			RGroup.addRsc(gEPtr);
			GroupEvents.emplace(Event, gEPtr);
			return std::make_shared<XAieGroupEventHandle>(AieHandle,
					gEPtr);
		}
		std::shared_ptr<XAieGroupEventHandle> groupEvent(
				XAie_Events Event) {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return groupEvent(RGroup, Event);
		}

		/**
		 * This function returns user event handle object shared pointer
		 *
		 * @param RGroup resource group
		 * @return user event handle software object pointer
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieUserEvent> userEvent(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto Rsc = std::make_shared<XAieUserEvent>(AieHandle,
								Loc, Mod);
			RGroup.addRsc(Rsc);
			return Rsc;
		}
		std::shared_ptr<XAieUserEvent> userEvent() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return userEvent(RGroup);
		}
	private:
		std::shared_ptr<XAieDevHandle> AieHandle; /**< AI engine device
							    handle */
		XAie_LocType Loc; /**< Tile location */
		XAie_ModuleType Mod; /**< Module type */
		std::shared_ptr<XAieTraceCntr> TraceCntr; /**< trace control pointer */
		std::map<XAie_Events, std::shared_ptr<XAieGroupEvent>> GroupEvents; /**< Group Events */
	};
	/**
	 * @class XAieTile
	 * @brief AI enigne tile. It defines AI engine tile operations.
	 *	  such as get resource within a tile, or get a module.
	 */
	class XAieTile {
	public:
		XAieTile() {}
		XAieTile(XAieDev &Dev, XAie_LocType Loc):
			AieHandle(Dev.getDevHandle()), Loc(Loc) {
			uint32_t TType;

			TType = _XAie_GetTileTypefromLoc(Dev.dev(), Loc);

			if (TType == XAIEGBL_TILE_TYPE_MAX) {
				throw std::invalid_argument("Invalid tile");
			}
			if (TType == XAIEGBL_TILE_TYPE_AIETILE) {
				Mods.push_back(XAieMod(Dev, Loc, XAIE_MEM_MOD));
				Mods.push_back(XAieMod(Dev, Loc, XAIE_CORE_MOD));
			} else {
				if (TType == XAIEGBL_TILE_TYPE_SHIMPL ||
					TType == XAIEGBL_TILE_TYPE_SHIMNOC) {
					Mods.push_back(XAieMod(Dev, Loc, XAIE_PL_MOD));
				} else {
					Mods.push_back(XAieMod(Dev, Loc, XAIE_MEM_MOD));
				}
			}
			AieHandle = Dev.getDevHandle();
		}
		~XAieTile() {}

		/**
		 * This function returns tile location
		 *
		 * @return tile location
		 */
		XAie_LocType loc() const {
			return Loc;
		}

		/**
		 * This function returns module reference.
		 *
		 * @param Mod module type
		 * @return module reference
		 */
		XAieMod &module (XAie_ModuleType Mod) {
			if (_XAie_CheckModule(AieHandle->dev(), Loc, Mod) !=
				XAIE_OK) {
				std::string str = "module " +
					std::to_string(Mod) + " not in tile.";

				throw std::invalid_argument(str);
			}
			if (Mod == XAIE_CORE_MOD) {
				return Mods[1];
			} else {
				return Mods[0];
			}
		}

		/**
		 * This function returns core module reference.
		 *
		 * @return core module reference
		 */
		XAieMod &core() {
			return module(XAIE_CORE_MOD);
		}

		/**
		 * This function returns memory module reference.
		 *
		 * @return memory module reference
		 */
		XAieMod &mem() {
			return module(XAIE_MEM_MOD);
		}

		/**
		 * This function returns pl module reference.
		 *
		 * @return pl module reference
		 */
		XAieMod &pl() {
			return module(XAIE_PL_MOD);
		}

		/**
		 * This function returns requested resource group resource
		 * statistics of the tile.
		 *
		 * @param GName resource group name
		 * @return resource group resource statistics
		 */
		XAieRscStat getRscStat(const std::string &GName) {
			return AieHandle->getRscGroup(GName).getRscStat(Loc);
		}

		/**
		 * This function returns broadcast resource software object
		 * within a tile.
		 *
		 * @param RGroup resource group
		 * @return broadcast channel software object pointer within a
		 *  tile.
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieBroadcast> broadcast(
				XAieDevHdRscGroupWrapper &RGroup) {
			std::vector<XAie_LocType> vL;
			XAie_ModuleType StartM, EndM;

			vL.push_back(Loc);
			if (_XAie_CheckModule(AieHandle->dev(), Loc, XAIE_CORE_MOD)
				== XAIE_OK) {
				StartM = XAIE_CORE_MOD;
				EndM = XAIE_MEM_MOD;
			} else if (_XAie_CheckModule(AieHandle->dev(), Loc,
				XAIE_PL_MOD) == XAIE_OK) {
				StartM = XAIE_PL_MOD;
				EndM = XAIE_PL_MOD;
			} else {
				StartM = XAIE_MEM_MOD;
				EndM = XAIE_MEM_MOD;
			}
			auto BC = std::make_shared<XAieBroadcast>(AieHandle,
				vL, StartM, EndM);
			RGroup.addRsc(BC);

			return BC;
		}
		std::shared_ptr<XAieBroadcast> broadcast() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return broadcast(RGroup);
		}

		/**
		 * This function returns perfcounter software object
		 * within a tile.
		 *
		 * @param RGroup resource group
		 * @return perfcounter software object pointer within a tile.
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAiePerfCounter> perfCounter(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto C = std::make_shared<XAiePerfCounter>(AieHandle,
					Loc, Mods[0].mod(), true);
			RGroup.addRsc(C);
			return C;
		}
		std::shared_ptr<XAiePerfCounter> perfCounter() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return perfCounter(RGroup);
		}

		/**
		 * This function returns stream switch port select software
		 * object within a tile.
		 *
		 * @param RGroup resource group
		 * @return stream switch port select software object pointer
		 *	   within a tile.
		 *
		 * Please note that this function will not request hardware
		 * resource. After this function is called, in order to reserve
		 * the hardware resource, it will need to call reserve()
		 * function of the resource class.
		 */
		std::shared_ptr<XAieStreamPortSelect> sswitchPort(
				XAieDevHdRscGroupWrapper &RGroup) {
			auto SS = std::make_shared<XAieStreamPortSelect>(
					AieHandle, Loc);
			RGroup.addRsc(SS);
			return SS;
		}
		std::shared_ptr<XAieStreamPortSelect> sswitchPort() {
			XAieDevHdRscGroupWrapper RGroup =
				AieHandle->getRscGroup("Generic");

			return sswitchPort(RGroup);
		}

	private:
		std::shared_ptr<XAieDevHandle> AieHandle; /**< AI engine device
							    handle */
		XAie_LocType Loc;
		std::vector<XAieMod> Mods;
	};

	inline XAieDev::XAieDev(XAie_DevInst *DevPtr,
		bool TurnOnFinishOnDestruct) {

		AieHandle = std::make_shared<XAieDevHandle>(DevPtr,
			TurnOnFinishOnDestruct);

		AieHandle->createGroup<XAieRscGroupAvail>("Avail");
		AieHandle->createGroup<XAieRscGroupStatic>("Static");
		AieHandle->createGroup<XAieRscGroupRuntime>("Generic");

		NumCols = DevPtr->NumCols;
		NumRows = DevPtr->NumRows;
		for (uint32_t c = 0; c < NumCols; c++) {
			for (uint32_t r = 0; r < NumRows; r++) {
				Tiles.push_back(XAieTile(*this,
					XAie_TileLoc(c, r)));
			}
		}
		AieHandle->createRscMgr();
	}

	/**
	 * This function returns the estimated module type of an AI enigne
	 * event enum value.
	 *
	 * @param Event input event enum
	 * @return estimated module type
	 *
	 * Please note that this funciton will not check if the input event
	 * is valid or not, it will returns the estimated module type of the
	 * event.
	 */
	static inline XAie_ModuleType XAieEstimateModFromEvent(XAie_Events Event)
	{
		XAie_ModuleType Module;

		if (Event < XAIE_EVENT_NONE_MEM) {
			Module = XAIE_CORE_MOD;
		} else if (Event < XAIE_EVENT_NONE_PL ||
				(Event >= XAIE_EVENT_NONE_MEM_TILE &&
				 Event <= XAIE_EVENT_USER_EVENT_1_MEM_TILE)) {
			Module = XAIE_MEM_MOD;
		} else {
			Module = XAIE_PL_MOD;
		}
		return Module;
	}
}
