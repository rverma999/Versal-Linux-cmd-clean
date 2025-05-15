// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: simulatorInterfaces.h
// 
/// This file contains the definition of the  class.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_SIMULATOR_INTERFACES_H_
#define _SRC_X86SIM_INCLUDE_SIMULATOR_INTERFACES_H_

#include <memory>
#include <string>
#include <tuple>
#include "adf/adf_api/X86SimConfig.h"
#include "symbolVisibility.h"

namespace adf {
class io_buffer_internal;
} // namespace adf

namespace x86sim {

class Simulator;
class EventTraceFile;
class SnapshotFile;
class IKernel;
class INode;
class IConnector;
class IPlatformBuffer;
class IPlatformStreamNode;
class DFGraph;
class StreamHelperBase;
enum class PlatformStreamDataType;

// *****************************************************************************
// struct ISimulatorConfig
// 
/// This is the ISimulatorConfig class. 
// *****************************************************************************
struct X86SIM_EXPORT ISimulatorConfig {
    std::string _name;
    bool _enableProgress;
    bool _enableStopOnDeadlock;
    bool _enableEventTrace;
    bool _enableEventTracePrint;
    bool _enableSnapshots;
    bool _socketIO;
    unsigned long _simTimeout;
    unsigned long _plWaitTime;
    long _meKernelIters;
    std::string _outputDir;
    std::string _inputDir;
    std::string _optionsFile;
    std::string _pkgDir;
    bool _enableHandShakeWithExtTb;
    bool _isMultiLayerFlow;
    int _aieArch;
    unsigned long _snapshotSize;

    inline void init();
};

inline void ISimulatorConfig::init()
{
    _name = "";
    _enableProgress = true;
    _enableStopOnDeadlock = false;
    _enableEventTrace = false;
    _enableEventTracePrint = false;
    _enableSnapshots = false;
    _socketIO = false;
    _simTimeout = 0;
    _plWaitTime = 0;
    _meKernelIters = 0;
    _outputDir = "./x86simulator_output";
    _inputDir = ".";
    _optionsFile = "";
    // required for summary file generation in SW EMU flow
    _pkgDir = "";
    _enableHandShakeWithExtTb = false;
    _isMultiLayerFlow = false;
    // 10 is the macro version for AIE1 refered from BuildDevice.h
    _aieArch = 10;
    _snapshotSize = 0; 
}

// *****************************************************************************
// struct ISimulatorOptions
// 
/// This is the ISimulatorOptions class for reading simulator options
/// specified in the Work/pthread/x86sim.options file.
// *****************************************************************************
class X86SIM_EXPORT ISimulatorOptions {
  public : 
    static void processFile(ISimulatorConfig &result);
    static void read(ISimulatorConfig &result, std::istream &in);
};

// *****************************************************************************
// struct ConnectorMetaData
// 
/// This is the ConnectorMetaData struct which relates a Connector to the
/// user's graph for sake of reporting (event trace, and snapshots).
// *****************************************************************************
struct X86SIM_EXPORT ConnectorMetaData {
    IConnector  *_connector;
    std::string  _type;
    std::string  _dataType;
    std::string  _sourcePortName;
    std::string  _sinkPortName;
    std::string  _sourcePortDir;
    std::string  _sinkPortDir;
    bool _decodeSourcePortData;
    bool _decodeSinkPortData;
};



// *****************************************************************************
// struct NodeMetaData
// 
/// This is the NodeMetaData struct which relates a Node to the user's graph for
/// sake of reporting (event trace, and snapshots).
// *****************************************************************************
struct X86SIM_EXPORT NodeMetaData {
    INode      *_node;
    std::string _qualifiedName;

    struct ConnectionMetaData {
        IConnector               *_connector;
        std::vector<std::string> _ports;
    };
    std::vector<ConnectionMetaData> _connections;
};



// *****************************************************************************
// class ISimulator
// 
/// This is the ISimulator class. It is the owner of a collection of INodes and
/// IConnectors, IPlatformBuffers, and DFGraphs. Together these objects make up
/// the simulation model of 1 or more AIE graphs. 
// *****************************************************************************
class X86SIM_EXPORT ISimulator {
public:
    virtual ~ISimulator() noexcept(false) {};
    
    enum class Kind {
        kBasic,
        kSwemu,
        kXmcKernel,
        kXmcGraph
    };
    virtual Kind getKind() const = 0;

    virtual void addGraphConfig(adf::X86SimGraphConfig const &) = 0;
    virtual void addGMIOConfig(adf::X86SimGMIOConfig const &) = 0;
    virtual void addPLIOConfig(adf::X86SimPLIOConfig const &) = 0;
    virtual void addRTPConfig(adf::X86SimRTPConfig const &) = 0;
    virtual void addSharedBufferConfig(adf::X86SimSharedBufferConfig const &) = 0;
    virtual void addExternalBufferPortConfig(
                     adf::X86SimExternalBufferPortConfig const &) = 0;
    virtual DFGraph *getGraph(std::string const &graphName) const = 0;

    // For sake of EventTrace and Snapshot
    virtual void addConnectorMetaData(ConnectorMetaData const &) = 0;
    virtual void addNodeMetaData(NodeMetaData const &) = 0;
    
    virtual void start() = 0;
    
    using AdfApiConfig =
        std::tuple<adf::X86SimGraphConfig const* , size_t,
                   adf::X86SimRTPConfig const* , size_t,
                   adf::X86SimGMIOConfig const*, size_t,
                   adf::X86SimPLIOConfig const*, size_t,
                   adf::X86SimSharedBufferConfig const*, size_t,
                   adf::X86SimExternalBufferPortConfig const*, size_t>;

    // This function returns the full configuration for use with
    // adf::ConfigManager::initialize()
    virtual AdfApiConfig getConfig() const = 0;

    static void initiateTermination();
};



// *****************************************************************************
// class IBasicSimulator
// 
/// This is the IBasicSimulator class. It is the derivative of ISimulator
/// for sake of Work/pthread/sim.out, which is the use case where the simulator
/// is driven through the adf API of the user's adf::graph.
// *****************************************************************************
class X86SIM_EXPORT IBasicSimulator: public virtual ISimulator {
public:
    virtual ~IBasicSimulator() noexcept(false) {};
    virtual ISimulator::Kind getKind() const override
        {
            return ISimulator::Kind::kBasic;
        }

};



// *****************************************************************************
// class ISwemuSimulator
// 
/// This is the ISwemuSimulator class. It is the derivative of ISimulator
/// for sake the software emulation flow. In this case, the simulator is driven
/// via the APIs x86simSwemuIfc.h and via hls::streams connected to the 
/// simulator.
// *****************************************************************************
class X86SIM_EXPORT ISwemuSimulator: public virtual ISimulator {
public:
    typedef std::unique_ptr<StreamHelperBase> (*StreamHelperMakeFunc)
                                        (PlatformStreamDataType type,
                            int dataWidth, int user, int id, int dest);
    virtual ~ISwemuSimulator() noexcept(false) {};
    virtual ISimulator::Kind getKind() const override
        {
            return ISimulator::Kind::kSwemu;
        }

    // Connects the PLIO port with specified name to specified hls::stream<T>.
    // The T is encoded using arguments 3-7:
    // streamType in {"KAXIS", "KAXIU"}
    // datawidth in {32,64,128}
    // user, id, dest should all be 0
    //
    // Valid Ts are:
    // hls::axis<ap_int<W>,0,0,0>     if streamType="KAXIS"
    // hls::axis<ap_uint<W>,0,0,0>    if streamType="KAXIU"
    // where W=dataWidth and W in {32,64,128}
    virtual bool connectHlsStream(std::string const &portName,
                                  void *hlsStream,              
                                  int dataWidth,
                                  int user,
                                  int id,
                                  int dest,
                                  std::string const &streamType) = 0;
    virtual void registerHlsStreamNode(IPlatformStreamNode *node,
                                       std::string const   &id) = 0;
    virtual void registerStreamHelperMakeFunc(StreamHelperMakeFunc func) = 0;
    virtual bool updateRtp(std::string const &graphName,
                           std::string const &portName,
                           void const *data,
                           size_t numBytes) = 0;
    virtual bool readRtp(std::string const &graphName,
                         std::string const &portName,
                         void *data,
                         size_t numBytes) = 0;
    // Calls gmio Api gm2aie_nb or aie2gm_nb on the IGMIO node pointer.
    // if type = gm2aie, call gm2aie_nb
    // if type = aie2gm, call aie2gm_nb
    virtual bool gmioApi(std::string const &gmioName,
                         adf::X86SimGMIOConfig::GMIOType type,
                         void* addr,
                         size_t sz) = 0;    
    virtual bool wait(std::string const &gmioName) = 0;
    virtual long getIter() = 0;
    virtual void generateSummaryFile(bool initSummary, 
                            unsigned long long startTime,
                            int pid, 
                            unsigned long long finishTime, 
                            bool runStatus) = 0;
    virtual bool setAddress(std::string const &bufferName,
                            void* buffAddr) = 0;
};

// *****************************************************************************
// class IXmcSimulatorTypes
// 
/// This is the SimulatorTypes class. It encapsulates the types used for
/// constructing a KernelSimulator.
// *****************************************************************************
class X86SIM_EXPORT IXmcSimulatorTypes {
public:
   enum class ConnectorType {
      kStream,
      kWindow,
      kParameter,
      kNumValues
   };
   enum class ElementDataType {
      kFloat,
      kDouble,
      kInt8,
      kInt16,
      kInt32,
      kInt64,
      kUint8,
      kUint16,
      kUint32,
      kUint64,
      kAcc48,
      kAcc80,
      kAccFloat,
      kNumValues,
      kBfloat16,
      kFloat16,
      kBfloat8,
      kFloat8
   };
   enum class Complexity {
      kReal,
      kComplex,
      kNumValues
   };
   enum class Synchronicity {
      kAsync,
      kSync,
      kNumValues
   };
   // For window connector specs all fields are used.
   // The following parameters can be set via configWindow:
   //  m_size, m_windowMargin, and m_synchronicity.
   //
   // For stream connector specs, m_size, m_windowMargin, and m_synchronicity
   // are not used and there is no further configuration.
   //
   // For RTP connector specs m_dataType, m_complexity, and m_windowMargin
   // are not used. Synchronicity can be set via configRtp(). The total size
   // of the RTP must be specified via m_size and cannot be configured later.
   struct ConnectorSpec {
      ConnectorType          _connectorType;
      ElementDataType        _dataType;
      Complexity             _complexity;      
      int                    _size;
      int                    _windowMargin;
      Synchronicity          _synchronicity;
      adf::io_buffer_internal *_wPort;
      adf::io_buffer_internal *_rPort;
   };

   static size_t getSize(ElementDataType type);
};

// *****************************************************************************
// class IXmcSimulator
// 
/// This is the IXmcSimulator class. It is the derivative of ISimulator
/// for sake model composer  this case, the simulator is driven
/// via the APIs x86simXmcIfc.h and via IPlatformBuffers.
// *****************************************************************************
class X86SIM_EXPORT IXmcSimulator: public virtual ISimulator {
public:
    virtual ~IXmcSimulator() noexcept(false) {};

   virtual INode *getNode(int ind) = 0;
   
   virtual void configWindow(int dir,
			     int index,
			     int size,
			     int margin,
			     bool sync) = 0;
   virtual void configRtp(int dir,
			  int index,
			  bool sync) = 0;
   virtual void configEnd() = 0;

   virtual void end() = 0;
   
   virtual void writeInputsBegin() = 0;
   virtual void writeInputsEnd() = 0;
   virtual void readOutputsBegin() = 0;
   virtual void readOutputsEnd() = 0;
   virtual size_t writeInput(int index,
			     size_t size,
			     void const *data) = 0;
   virtual size_t readOutput(int index,
			     size_t size,
			     void *data) = 0;
};

class X86SIM_EXPORT SimulatorFactory {
public:
    static ISimulator      *simulator(ISimulatorConfig const &config,
                                      ISimulator::Kind);
    static IBasicSimulator *basicSimulator(ISimulatorConfig const &config);
    static ISwemuSimulator *swemuSimulator(ISimulatorConfig const &config);
    static IXmcSimulator   *xmcKernelSimulator
        (ISimulatorConfig const &config,
         std::vector<IXmcSimulatorTypes::ConnectorSpec> const &iConnSpecs,
         std::vector<IXmcSimulatorTypes::ConnectorSpec> const &oConnSpecs);
    static IXmcSimulator   *xmcGraphSimulator(ISimulatorConfig const &config);
};


} // namespace x86sim


#endif // ifndef _SRC_X86SIM_INCLUDE_SIMULATOR_INTERFACES_H_
