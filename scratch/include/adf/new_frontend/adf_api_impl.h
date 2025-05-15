// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _ADF_API_IMPL_H_
#define _ADF_API_IMPL_H_

#include <cstring>
#include <complex>
#include <vector>
#include <array>
#include <initializer_list>
#include <type_traits>
#include <memory>
#include "adf/io_buffer/io_buffer_traits.h"
#include "adf/io_buffer/io_buffer_types.h"
#include "adf_api_dynlink.h"

namespace adf
{
  
    /**************************** forward class declaration *******************************/

    class PortImpl;
    class GraphImpl;
    class KernelImpl;
    class ParameterImpl;
    class ConnectImpl;
    class ConstraintImpl;
    class LocationConstraintImpl;
    class IoAttrImpl;
    class PlatformImpl;
    class PktMergeImpl;
    class PktOrderedMergeImpl;
    class PktSplitImpl;
    class PktControlImpl;
    class MicroControllerImpl;
    class ObjectImpl;
    class BypassImpl;
    class SharedBufferImpl; //FIXME
    class ExternalBufferImpl;
    class OperatorImpl;

    class FileIO;
    class GMIO;
    class IoAttr;
    class PLIO;
    class access_pattern;
    class bypass;
    class graph;
    class input_gmio;
    class input_plio;
    class kernel;
    class output_gmio;
    class output_plio;
    class parameter;
    class pktcontrol;
    class microcontroller;
    class samples_per_iteration;
    class Operator;
    template <class _XILINX_ADF_TYP_T> class port;
    template<int> class pktmerge;
    template<int> class pktorderedmerge;
    template<int> class pktsplit;
    namespace simulation {
        template<size_t NUMI, size_t NUMO> class platform;
    }
    class shared_buffer_base
    {
      public:
        std::shared_ptr<SharedBufferImpl> impl;
    };

    class external_buffer_base
    {
      public:
        std::shared_ptr<ExternalBufferImpl> impl;
    };

    template <class _XILINX_ADF_TYP_T> class external_buffer;
    template <class _XILINX_ADF_TYP_T> class shared_buffer;
    template <typename _XILINX_ADF_TYP_T1, typename _XILINX_ADF_TYP_T2> class connect;


    namespace api_impl
    {
       /**************************** bounds checking *********************/
        ADF_API_EXPORT void checkVectorAccess(size_t pos, size_t size);

        /**************************** port *******************************/

        ADF_API_EXPORT void createPort(std::shared_ptr<PortImpl>&, adf::port_direction);
        ADF_API_EXPORT void createPort(std::shared_ptr<PortImpl>&, std::shared_ptr<PortImpl>);
        
        ADF_API_EXPORT void negate(std::shared_ptr<PortImpl>&);
        ADF_API_EXPORT void async(std::shared_ptr<PortImpl>&);
        ADF_API_EXPORT void sync(std::shared_ptr<PortImpl>&);

        /**************************** connect *******************************/

        struct ConnectTemplateParameter
        {
            adf::port_type portType;
            int windowSize;
            int margin;
        };

        template<typename _XILINX_ADF_T> ConnectTemplateParameter connectTemplateParam()
        {
            return{ (adf::port_type)_XILINX_ADF_T::porttype, _XILINX_ADF_T::winsz, _XILINX_ADF_T::margin };
        }

        ADF_API_EXPORT void connectPorts(std::shared_ptr<ConnectImpl>&, std::shared_ptr<PortImpl>&, std::shared_ptr<PortImpl>&, ConnectTemplateParameter, ConnectTemplateParameter);

        ADF_API_EXPORT void connectParameterToKernel(std::shared_ptr<ConnectImpl>&, std::shared_ptr<ParameterImpl>&, std::shared_ptr<KernelImpl>&);

        /**************************** constraint *******************************/

        ADF_API_EXPORT void createConstraintFifoDepth(std::shared_ptr<ConstraintImpl>&, std::shared_ptr<ConnectImpl>&);

        /*************************** Location constraint ***********************/

        ADF_API_EXPORT void createFIFOLocationConstraint(std::shared_ptr<LocationConstraintImpl>&, std::shared_ptr<ConnectImpl>&);
        ADF_API_EXPORT void createPLIOOrGMIOLocationConstraint(std::shared_ptr<LocationConstraintImpl>&, std::shared_ptr<IoAttrImpl>&);

        /**************************** platform *******************************/

        struct IoAttrOrFile
        {
            IoAttr* ioAttr;
            const char* ioFile;
            
            IoAttrOrFile(IoAttr* attr) : ioAttr(attr), ioFile(nullptr) {}
            IoAttrOrFile(const char* file) : ioAttr(nullptr), ioFile(file) {}
        };

        ADF_API_EXPORT void createPlatform(std::shared_ptr<PlatformImpl>& spPlatform, adf::port<adf::output>* src, int num_inputs, adf::port<adf::input>* sink, int num_outputs, std::vector<IoAttrOrFile>& ioAttrOrFiles);

        template<typename... Types> void createPlatform(std::shared_ptr<PlatformImpl>& spPlatform, adf::port<adf::output>* src, int num_inputs, adf::port<adf::input>* sink, int num_outputs, Types... ios)
        {
            std::vector<IoAttrOrFile> ioAttrOrFiles;
            getPlatformIoAttrs(ioAttrOrFiles, ios...);
            createPlatform(spPlatform, src, num_inputs, sink, num_outputs, ioAttrOrFiles);
        }

        //base function for variadic template
        void getPlatformIoAttrs(std::vector<IoAttrOrFile>& ioAttrOrFiles);
        
        //variadic template
        template<typename... Types> void getPlatformIoAttrs(std::vector<IoAttrOrFile>& ioAttrOrFiles, IoAttr* ioAttr, Types... ios)
        {
            ioAttrOrFiles.push_back(IoAttrOrFile(ioAttr));
            getPlatformIoAttrs(ioAttrOrFiles, ios...);
        }

        //variadic template
        template<typename... Types> void getPlatformIoAttrs(std::vector<IoAttrOrFile>& ioAttrOrFiles, const char* ioFile, Types... ios)
        {
            ioAttrOrFiles.push_back(IoAttrOrFile(ioFile));
            getPlatformIoAttrs(ioAttrOrFiles, ios...);
        }

        /**************************** pktmerge *******************************/

        ADF_API_EXPORT void createPktMerge(std::shared_ptr<PktMergeImpl>& spImpl);
        ADF_API_EXPORT void createPktMerge(std::shared_ptr<PktMergeImpl>& spImpl, int nway, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out);
        ADF_API_EXPORT void assignmentPktMerge(std::shared_ptr<PktMergeImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<PktMergeImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);

        /**************************** pktorderedmerge *******************************/

        ADF_API_EXPORT void createPktOrderedMerge(std::shared_ptr<PktOrderedMergeImpl>& spImpl);
        ADF_API_EXPORT void createPktOrderedMerge(std::shared_ptr<PktOrderedMergeImpl>& spImpl, int nway, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out);
        ADF_API_EXPORT void assignmentPktOrderedMerge(std::shared_ptr<PktOrderedMergeImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<PktOrderedMergeImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);

        /**************************** pktsplit *******************************/

        ADF_API_EXPORT void createPktSplit(std::shared_ptr<PktSplitImpl>& spImpl);
        ADF_API_EXPORT void createPktSplit(std::shared_ptr<PktSplitImpl>& spImpl, int nway, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out);
        ADF_API_EXPORT void assignmentPktSplit(std::shared_ptr<PktSplitImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<PktSplitImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);

        /**************************** pktcontrol *******************************/

        ADF_API_EXPORT void createPktControl(std::shared_ptr<PktControlImpl>& spImpl);
        ADF_API_EXPORT void createPktControl(std::shared_ptr<PktControlImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, bool return_packet);
        ADF_API_EXPORT void assignmentPktControl(std::shared_ptr<PktControlImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<PktControlImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);

        /**************************** microcontroller *******************************/

        ADF_API_EXPORT void createMicroController(std::shared_ptr<MicroControllerImpl>& spImpl);
        ADF_API_EXPORT void createMicroController(std::shared_ptr<MicroControllerImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, int numInput, int numOutput);
        ADF_API_EXPORT void assignmentMicroController(std::shared_ptr<MicroControllerImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<MicroControllerImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);

        /**************************** shared_buffer *******************************/

        ADF_API_EXPORT void createSharedBuffer(std::shared_ptr<SharedBufferImpl>& spImpl);
        ADF_API_EXPORT void createSharedBuffer(std::shared_ptr<SharedBufferImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, element_type elemType, param_type paramType, const std::vector<uint32_t>& dimensions, size_t numInputs, size_t numOutputs);
        ADF_API_EXPORT void assignmentSharedBuffer(std::shared_ptr<SharedBufferImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<SharedBufferImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);
        
        ADF_API_EXPORT unsigned sharedBufferEnqueueTask(std::shared_ptr<SharedBufferImpl>& spImpl, std::shared_ptr<PortImpl>& pPortImpl, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count, bool enable_task_complete_token);
        ADF_API_EXPORT unsigned sharedBufferWait(std::shared_ptr<SharedBufferImpl>& spImpl, std::shared_ptr<PortImpl>& pPortImpl);


        /**************************** external_buffer *******************************/

        ADF_API_EXPORT void createExternalBuffer(std::shared_ptr<ExternalBufferImpl>& spImpl);
        ADF_API_EXPORT void createExternalBuffer(std::shared_ptr<ExternalBufferImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, element_type elemType, param_type paramType, const std::vector<uint32_t>& dimensions, size_t numInputs, size_t numOutputs);
        ADF_API_EXPORT void assignmentExternalBuffer(std::shared_ptr<ExternalBufferImpl>& spImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<ExternalBufferImpl>& spImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);
        ADF_API_EXPORT void setAddressExternalBuffer(std::shared_ptr<ExternalBufferImpl>& spImpl, const void* ptr);
        ADF_API_EXPORT return_code gm2aie_nb(std::shared_ptr<ExternalBufferImpl>& spImpl, std::shared_ptr<PortImpl>& pOutPortImpl);
        ADF_API_EXPORT return_code aie2gm_nb(std::shared_ptr<ExternalBufferImpl>& spImpl, std::shared_ptr<PortImpl>& pInPortImpl);
        ADF_API_EXPORT return_code wait(std::shared_ptr<ExternalBufferImpl>& spImpl, std::shared_ptr<PortImpl>& portImpl);
        /**************************** Operator *******************************/

        ADF_API_EXPORT void createOperator(std::string operatorName, std::shared_ptr<OperatorImpl>& impl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, size_t numInputs, size_t numOutputs);
        ADF_API_EXPORT void createOperator(std::shared_ptr<OperatorImpl>& impl);
        ADF_API_EXPORT void assignmentOperator(std::shared_ptr<OperatorImpl>& opImpl, std::vector<adf::port<adf::input>>& in, std::vector<adf::port<adf::output>>& out, const std::shared_ptr<OperatorImpl>& opImplFrom, const std::vector<adf::port<adf::input>>& inFrom, const std::vector<adf::port<adf::output>>& outFrom);
        
        /**************************** kernel port *******************************/

        struct port_info {
            adf::port_direction pd;
            adf::param_type paramType;
            adf::param_type subParamType;
            adf::port_type ptEnum;
            int arraySize;
            int apBitWidth;
            adf::locking_mode lockingMode;
            std::vector<uint32_t> dimensions;
            bool hasCyclicAddressing;
            uint32_t margin;
        };

        ADF_API_EXPORT void addPort(kernel& k, api_impl::port_info portInfo);


        template<typename _XILINX_ADF_T> struct FuncType {};
        template<typename _XILINX_ADF_T, typename ..._XILINX_ADF_Rest>
        struct FuncType<void(_XILINX_ADF_T, _XILINX_ADF_Rest...)> {
            typedef _XILINX_ADF_T firstType;
            typedef FuncType<void(_XILINX_ADF_Rest...)> restType;
        };

        template<typename _XILINX_ADF_T> struct Arity {};
        template<typename _XILINX_ADF_T, typename ..._XILINX_ADF_Rest>
        struct Arity<void(_XILINX_ADF_T, _XILINX_ADF_Rest...)> {
            enum { value = 1 + Arity<void(_XILINX_ADF_Rest...)>::value };
        };
        template <> struct Arity<void()> { enum { value = 0 }; };

        template<class...> struct Disjunction : std::false_type { };
        template<class _XILINX_ADF_B1>
            struct Disjunction<_XILINX_ADF_B1> : _XILINX_ADF_B1 { };
        template<class _XILINX_ADF_B1, class... _XILINX_ADF_BS>
        struct Disjunction<_XILINX_ADF_B1, _XILINX_ADF_BS...> 
        : std::conditional_t<bool(_XILINX_ADF_B1::value), _XILINX_ADF_B1, Disjunction<_XILINX_ADF_BS...>>  { };

        // Default templated tyPortType for frontend to report unsupported port and data types
        template <typename _XILINX_ADF_T, typename _XILINX_ADF_ENABLE_T=void> struct tyPortType
        {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_voidty; //unsupported data type
            static const adf::param_type subPtype = adf::param_type::p_voidty; //unsupported data type
            static const adf::port_type ptEnum = adf::port_type::port_blank; //unsupported port type
            static const int arraySize = 0;
            static const int apBitWidth = 0;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
        };

        //Template specialization for tyPortType should contain the following static const variables:
        //static const adf::port_direction pd      //port direction
        //static const adf::param_type paramType   //parameter type
        //static const adf::param_type subPtype    //element type for window, stream, hls::stream
        //static const adf::port_type ptEnum       //port type
        //static const int arraySize                     //array size
        //static const int apBitWidth                //arbitrary precision data type bit width, e.g., ap_int, ap_uint, ap_axis, ap_axiu


        /************ tyPortType template specialization: window ************/

#define PORT_TYPE_WINDOW(WINDOW_TYPE, DIRECTION, ELEM_TYPE)                        \
        template <> struct tyPortType<WINDOW_TYPE> {                               \
            static const adf::port_direction pd = adf::port_direction::DIRECTION;  \
            static const adf::param_type paramType = adf::param_type::p_window;    \
            static const adf::param_type subPtype = adf::param_type::ELEM_TYPE;    \
            static const adf::port_type ptEnum = adf::port_type::port_memory;      \
            static const int arraySize = 0;                                        \
            static const int apBitWidth = 0;                                       \
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto; \
            static std::vector<uint32_t> dimensions() { return {};}                \
            static const bool hasCyclicAddressing = true;                          \
            static const uint32_t margin = std::numeric_limits<uint32>::max();     \
        }
        
        PORT_TYPE_WINDOW(input_window_int8*, dir_in, p_int8);
        PORT_TYPE_WINDOW(input_window_uint8*, dir_in, p_uint8);
        PORT_TYPE_WINDOW(input_window_int16*, dir_in, p_int16);
        PORT_TYPE_WINDOW(input_window_uint16*, dir_in, p_uint16);
        PORT_TYPE_WINDOW(input_window_int32*, dir_in, p_int32);
        PORT_TYPE_WINDOW(input_window_uint32*, dir_in, p_uint32);
        PORT_TYPE_WINDOW(input_window_int64*, dir_in, p_int64);
        PORT_TYPE_WINDOW(input_window_uint64*, dir_in, p_uint64);
        PORT_TYPE_WINDOW(input_window_float*, dir_in, p_float);
        PORT_TYPE_WINDOW(input_window_cint16*, dir_in, p_cint16);
        PORT_TYPE_WINDOW(input_window_cint32*, dir_in, p_cint32);
#if __AIE_ARCH__<20
        PORT_TYPE_WINDOW(input_window_cfloat*, dir_in, p_cfloat);
#endif

        PORT_TYPE_WINDOW(output_window_int8*, dir_out, p_int8);
        PORT_TYPE_WINDOW(output_window_uint8*, dir_out, p_uint8);
        PORT_TYPE_WINDOW(output_window_int16*, dir_out, p_int16);
        PORT_TYPE_WINDOW(output_window_uint16*, dir_out, p_uint16);
        PORT_TYPE_WINDOW(output_window_int32*, dir_out, p_int32);
        PORT_TYPE_WINDOW(output_window_uint32*, dir_out, p_uint32);
        PORT_TYPE_WINDOW(output_window_int64*, dir_out, p_int64);
        PORT_TYPE_WINDOW(output_window_uint64*, dir_out, p_uint64);
        PORT_TYPE_WINDOW(output_window_float*, dir_out, p_float);
        PORT_TYPE_WINDOW(output_window_cint16*, dir_out, p_cint16);
        PORT_TYPE_WINDOW(output_window_cint32*, dir_out, p_cint32);
#if __AIE_ARCH__<20
        PORT_TYPE_WINDOW(output_window_cfloat*, dir_out, p_cfloat);
#endif

        /************ tyPortType template specialization: adf stream ************/

#define PORT_TYPE_STREAM(STREAM_TYPE, DIRECTION, ELEM_TYPE)     \
        template <> struct tyPortType<STREAM_TYPE> {                                       \
            static const adf::port_direction pd = adf::port_direction::DIRECTION;  \
            static const adf::param_type paramType = adf::param_type::p_stream;    \
            static const adf::param_type subPtype = adf::param_type::ELEM_TYPE;    \
            static const adf::port_type ptEnum = adf::port_type::port_stream;      \
            static const int arraySize = 0;                                                  \
            static const int apBitWidth = 0;                                             \
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto; \
            static std::vector<uint32_t> dimensions() { return {};} \
            static const bool hasCyclicAddressing = false; \
            static const uint32_t margin = 0; \
        }

        PORT_TYPE_STREAM(input_stream_int8*, dir_in, p_int8);
        PORT_TYPE_STREAM(input_stream_uint8*, dir_in, p_uint8);
        PORT_TYPE_STREAM(input_stream_int16*, dir_in, p_int16);
        PORT_TYPE_STREAM(input_stream_uint16*, dir_in, p_uint16);
        PORT_TYPE_STREAM(input_stream_int32*, dir_in, p_int32);
        PORT_TYPE_STREAM(input_stream_uint32*, dir_in, p_uint32);
        PORT_TYPE_STREAM(input_stream_int64*, dir_in, p_int64);
        PORT_TYPE_STREAM(input_stream_uint64*, dir_in, p_uint64);
        PORT_TYPE_STREAM(input_stream_float*, dir_in, p_float);
        PORT_TYPE_STREAM(input_stream_cint16*, dir_in, p_cint16);
        PORT_TYPE_STREAM(input_stream_cint32*, dir_in, p_cint32);
#if __AIE_ARCH__<=20
        PORT_TYPE_STREAM(input_stream_cfloat*, dir_in, p_cfloat);
#endif
#if __AIE_ARCH__>=20
        PORT_TYPE_STREAM(input_stream_int4*, dir_in, p_int4);
        PORT_TYPE_STREAM(input_stream_uint4*, dir_in, p_uint4);
        PORT_TYPE_STREAM(input_stream_bfloat16*, dir_in, p_bfloat16);
#endif
#if __AIE_ARCH__>=22
        PORT_TYPE_STREAM(input_stream_float16*, dir_in, p_float16);
        PORT_TYPE_STREAM(input_stream_bfloat8*, dir_in, p_bfloat8);
        PORT_TYPE_STREAM(input_stream_float8*, dir_in, p_float8);
#endif
        
        PORT_TYPE_STREAM(output_stream_int8*, dir_out, p_int8);
        PORT_TYPE_STREAM(output_stream_uint8*, dir_out, p_uint8);
        PORT_TYPE_STREAM(output_stream_int16*, dir_out, p_int16);
        PORT_TYPE_STREAM(output_stream_uint16*, dir_out, p_uint16);
        PORT_TYPE_STREAM(output_stream_int32*, dir_out, p_int32);
        PORT_TYPE_STREAM(output_stream_uint32*, dir_out, p_uint32);
        PORT_TYPE_STREAM(output_stream_int64*, dir_out, p_int64);
        PORT_TYPE_STREAM(output_stream_uint64*, dir_out, p_uint64);
        PORT_TYPE_STREAM(output_stream_float*, dir_out, p_float);
        PORT_TYPE_STREAM(output_stream_cint16*, dir_out, p_cint16);
        PORT_TYPE_STREAM(output_stream_cint32*, dir_out, p_cint32);
#if __AIE_ARCH__<=20
        PORT_TYPE_STREAM(output_stream_cfloat*, dir_out, p_cfloat);
#endif
#if __AIE_ARCH__>=20
        PORT_TYPE_STREAM(output_stream_int4*, dir_out, p_int4);
        PORT_TYPE_STREAM(output_stream_uint4*, dir_out, p_uint4);
        PORT_TYPE_STREAM(output_stream_bfloat16*, dir_out, p_bfloat16);
#endif
#if __AIE_ARCH__>=22
        PORT_TYPE_STREAM(output_stream_float16*, dir_out, p_float16);
        PORT_TYPE_STREAM(output_stream_bfloat8*, dir_out, p_bfloat8);
        PORT_TYPE_STREAM(output_stream_float8*, dir_out, p_float8);
#endif

        /************ tyPortType template specialization: cascade stream ************/

        template <typename _XILINX_ADF_T> struct tyPortType <input_cascade<_XILINX_ADF_T> *>
        {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_voidty; 
            static const adf::param_type subPtype = adf::param_type::p_voidty; 
            static const adf::port_type ptEnum = adf::port_type::port_cascade;
            static const int arraySize = 0;
            static const int apBitWidth = 0;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _XILINX_ADF_T> struct tyPortType <output_cascade<_XILINX_ADF_T> *>
        {
            static const adf::port_direction pd = adf::port_direction::dir_out;
            static const adf::param_type paramType = adf::param_type::p_voidty; 
            static const adf::param_type subPtype = adf::param_type::p_voidty; 
            static const adf::port_type ptEnum = adf::port_type::port_cascade;
            static const int arraySize = 0;
            static const int apBitWidth = 0;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //FIXME paramType should be p_cascade and subPtype should be acc48 or cacc48
#define PORT_TYPE_CASCADE(CASCADE_TYPE, DIRECTION, PARAM_TYPE)     \
        template <> struct tyPortType<CASCADE_TYPE> {                                      \
            static const adf::port_direction pd = adf::port_direction::DIRECTION;  \
            static const adf::param_type paramType = adf::param_type::PARAM_TYPE;  \
            static const adf::param_type subPtype = adf::param_type::p_int32;      \
            static const adf::port_type ptEnum = adf::port_type::port_cascade;     \
            static const int arraySize = 0;                                                  \
            static const int apBitWidth = 0;                                             \
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto; \
            static std::vector<uint32_t> dimensions() { return {};} \
            static const bool hasCyclicAddressing = false; \
            static const uint32_t margin = 0; \
        }
        PORT_TYPE_CASCADE(input_stream_accfloat*, dir_in, p_accfloat);
        PORT_TYPE_CASCADE(output_stream_accfloat*, dir_out, p_accfloat);
#if __AIE_ARCH__<20
        PORT_TYPE_CASCADE(input_stream_cacc48*, dir_in, p_cacc48);
        PORT_TYPE_CASCADE(output_stream_cacc48*, dir_out, p_cacc48);
        PORT_TYPE_CASCADE(input_stream_cacc80*, dir_in, p_cacc80);
        PORT_TYPE_CASCADE(output_stream_cacc80*, dir_out, p_cacc80);
        PORT_TYPE_CASCADE(input_stream_acc48*, dir_in, p_acc48);
        PORT_TYPE_CASCADE(output_stream_acc48*, dir_out, p_acc48);
        PORT_TYPE_CASCADE(input_stream_acc80*, dir_in, p_acc80);
        PORT_TYPE_CASCADE(output_stream_acc80*, dir_out, p_acc80);
        PORT_TYPE_CASCADE(input_stream_caccfloat*, dir_in, p_caccfloat);
        PORT_TYPE_CASCADE(output_stream_caccfloat*, dir_out, p_caccfloat);
#else
        PORT_TYPE_CASCADE(input_stream_acc32*, dir_in, p_acc32);
        PORT_TYPE_CASCADE(input_stream_acc64*, dir_in, p_acc64);
        PORT_TYPE_CASCADE(input_stream_cacc64*, dir_in, p_cacc64);
        PORT_TYPE_CASCADE(output_stream_acc32*, dir_out, p_acc32);
        PORT_TYPE_CASCADE(output_stream_acc64*, dir_out, p_acc64);
        PORT_TYPE_CASCADE(output_stream_cacc64*, dir_out, p_cacc64);
#endif
 
        PORT_TYPE_CASCADE(input_cascade<acc48>*, dir_in, p_acc48);
        PORT_TYPE_CASCADE(input_cascade<cacc48>*, dir_in, p_cacc48);
        PORT_TYPE_CASCADE(input_cascade<acc32>*, dir_in, p_acc32);
        PORT_TYPE_CASCADE(input_cascade<cacc32>*, dir_in, p_cacc32);
        PORT_TYPE_CASCADE(input_cascade<acc64>*, dir_in, p_acc64);
        PORT_TYPE_CASCADE(input_cascade<cacc64>*, dir_in, p_cacc64);
        PORT_TYPE_CASCADE(input_cascade<accfloat>*, dir_in, p_accfloat);
#if __AIE_ARCH__<20 
        PORT_TYPE_CASCADE(input_cascade<acc80>*, dir_in, p_acc80);
        PORT_TYPE_CASCADE(input_cascade<cacc80>*, dir_in, p_cacc80);
#else
        PORT_TYPE_CASCADE(input_cascade<int4>*, dir_in, p_int4);
        PORT_TYPE_CASCADE(input_cascade<uint4>*, dir_in, p_uint4);
        PORT_TYPE_CASCADE(input_cascade<bfloat16>*, dir_in, p_bfloat16);
#endif
#if __AIE_ARCH__>=22
        PORT_TYPE_CASCADE(input_cascade<float16>*, dir_in, p_float16);
        PORT_TYPE_CASCADE(input_cascade<bfloat8>*, dir_in, p_bfloat8);
        PORT_TYPE_CASCADE(input_cascade<float8>*, dir_in, p_float8);
#endif
        PORT_TYPE_CASCADE(input_cascade<int8>*, dir_in, p_int8);
        PORT_TYPE_CASCADE(input_cascade<int16>*, dir_in, p_int16);
        PORT_TYPE_CASCADE(input_cascade<int32>*, dir_in, p_int32);
        PORT_TYPE_CASCADE(input_cascade<int64>*, dir_in, p_int64);
        PORT_TYPE_CASCADE(input_cascade<uint8>*, dir_in, p_uint8);
        PORT_TYPE_CASCADE(input_cascade<uint16>*, dir_in, p_uint16);
        PORT_TYPE_CASCADE(input_cascade<cint16>*, dir_in, p_cint16);
        PORT_TYPE_CASCADE(input_cascade<cint32>*, dir_in, p_cint32);
        PORT_TYPE_CASCADE(input_cascade<float>*, dir_in, p_float);
        PORT_TYPE_CASCADE(input_cascade<cfloat>*, dir_in, p_cfloat);
        
        PORT_TYPE_CASCADE(output_cascade<acc48>*, dir_out, p_acc48);
        PORT_TYPE_CASCADE(output_cascade<cacc48>*, dir_out, p_cacc48);
        PORT_TYPE_CASCADE(output_cascade<acc32>*, dir_out, p_acc32);
        PORT_TYPE_CASCADE(output_cascade<cacc32>*, dir_out, p_cacc32);
        PORT_TYPE_CASCADE(output_cascade<acc64>*, dir_out, p_acc64);
        PORT_TYPE_CASCADE(output_cascade<cacc64>*, dir_out, p_cacc64);
        PORT_TYPE_CASCADE(output_cascade<accfloat>*, dir_out, p_accfloat);

#if __AIE_ARCH__<20 
        PORT_TYPE_CASCADE(output_cascade<acc80>*, dir_out, p_acc80);
        PORT_TYPE_CASCADE(output_cascade<cacc80>*, dir_out, p_cacc80);
#else
        PORT_TYPE_CASCADE(output_cascade<int4>*, dir_out, p_int4);
        PORT_TYPE_CASCADE(output_cascade<uint4>*, dir_out, p_uint4);
        PORT_TYPE_CASCADE(output_cascade<bfloat16>*, dir_out, p_bfloat16);
#endif
#if __AIE_ARCH__>=22
        PORT_TYPE_CASCADE(output_cascade<float16>*, dir_out, p_float16);
        PORT_TYPE_CASCADE(output_cascade<bfloat8>*, dir_out, p_bfloat8);
        PORT_TYPE_CASCADE(output_cascade<float8>*, dir_out, p_float8);
#endif
        PORT_TYPE_CASCADE(output_cascade<int8>*, dir_out, p_int8);
        PORT_TYPE_CASCADE(output_cascade<int16>*, dir_out, p_int16);
        PORT_TYPE_CASCADE(output_cascade<int32>*, dir_out, p_int32);
        PORT_TYPE_CASCADE(output_cascade<int64>*, dir_out, p_int64);
        PORT_TYPE_CASCADE(output_cascade<uint8>*, dir_out, p_uint8);
        PORT_TYPE_CASCADE(output_cascade<uint16>*, dir_out, p_uint16);
        PORT_TYPE_CASCADE(output_cascade<cint16>*, dir_out, p_cint16);
        PORT_TYPE_CASCADE(output_cascade<cint32>*, dir_out, p_cint32);
        PORT_TYPE_CASCADE(output_cascade<float>*, dir_out, p_float);
        PORT_TYPE_CASCADE(output_cascade<cfloat>*, dir_out, p_cfloat);
#if __AIE_ARCH__<=20
        PORT_TYPE_CASCADE(input_cascade<caccfloat>*, dir_in, p_caccfloat);
        PORT_TYPE_CASCADE(output_cascade<caccfloat>*, dir_out, p_caccfloat);
#endif

        
        /************ tyPortType template specialization: pktstream ************/

#define PORT_TYPE_PKTSTREAM(PKTSTREAM_TYPE, DIRECTION)     \
        template <> struct tyPortType<PKTSTREAM_TYPE> {                                     \
            static const adf::port_direction pd = adf::port_direction::DIRECTION;   \
            static const adf::param_type paramType = adf::param_type::p_pktstream;  \
            static const adf::param_type subPtype = adf::param_type::p_pktstream;   \
            static const adf::port_type ptEnum = adf::port_type::port_pktstream;    \
            static const int arraySize = 0;                                                   \
            static const int apBitWidth = 0;                                              \
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto; \
            static std::vector<uint32_t> dimensions() { return {};} \
            static const bool hasCyclicAddressing = false; \
            static const uint32_t margin = 0; \
        }

        PORT_TYPE_PKTSTREAM(input_pktstream*, dir_in);
        PORT_TYPE_PKTSTREAM(output_pktstream*, dir_out);

        /************ tyPortType template specialization: scalar ************/

#define PORT_TYPE_SCALAR(DATA_TYPE, PARAM_TYPE)     \
        template <> struct tyPortType<DATA_TYPE> {                                            \
            static const adf::port_direction pd = adf::port_direction::dir_in;        \
            static const adf::param_type paramType = adf::param_type::PARAM_TYPE;     \
            static const adf::param_type subPtype = adf::param_type::p_voidty;        \
            static const adf::port_type ptEnum = adf::port_type::port_runtime_param;  \
            static const int arraySize = 0;                                                     \
            static const int apBitWidth = 0;                                                \
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto; \
            static std::vector<uint32_t> dimensions() { return {};} \
            static const bool hasCyclicAddressing = false; \
            static const uint32_t margin = 0; \
        }

        PORT_TYPE_SCALAR(int8, p_int8);
        PORT_TYPE_SCALAR(uint8, p_uint8);
        PORT_TYPE_SCALAR(short, p_int16);
        PORT_TYPE_SCALAR(unsigned short, p_uint16);
        PORT_TYPE_SCALAR(int, p_int32);
        PORT_TYPE_SCALAR(unsigned int, p_uint32);
        PORT_TYPE_SCALAR(int64, p_int64);
        PORT_TYPE_SCALAR(uint64, p_uint64);
        PORT_TYPE_SCALAR(float, p_float);
        PORT_TYPE_SCALAR(cint16, p_cint16);
        PORT_TYPE_SCALAR(std::complex<short>, p_cint16);
        PORT_TYPE_SCALAR(cint32, p_cint32);
        PORT_TYPE_SCALAR(std::complex<int>, p_cint32);
#if __AIE_ARCH__<=20
        PORT_TYPE_SCALAR(cfloat, p_cfloat);
        PORT_TYPE_SCALAR(std::complex<float>, p_cfloat);
#endif
#if __AIE_ARCH__>=20
        PORT_TYPE_SCALAR(int4, p_int4);
        PORT_TYPE_SCALAR(uint4, p_uint4);
        PORT_TYPE_SCALAR(bfloat16, p_bfloat16);
#endif
#if __AIE_ARCH__>=22
        PORT_TYPE_SCALAR(float16, p_float16);
        PORT_TYPE_SCALAR(bfloat8, p_bfloat8);
        PORT_TYPE_SCALAR(float8, p_float8);
#endif


        /************ tyPortType template specialization: hls scalar ************/

        //ap_int
        template <int _AP_W> struct tyPortType<ap_int<_AP_W>> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_ap_int;
            static const adf::param_type subPtype = adf::param_type::p_voidty;
            static const adf::port_type ptEnum = adf::port_type::port_runtime_param;
            static const int arraySize = 0;
            static const int apBitWidth = _AP_W;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //ap_uint
        template <int _AP_W> struct tyPortType<ap_uint<_AP_W>> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_ap_uint;
            static const adf::param_type subPtype = adf::param_type::p_voidty;
            static const adf::port_type ptEnum = adf::port_type::port_runtime_param;
            static const int arraySize = 0;
            static const int apBitWidth = _AP_W;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //ap_axis
        template <int D> struct tyPortType<ap_axis<D, 0, 0, 0>> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_ap_axis;
            static const adf::param_type subPtype = adf::param_type::p_voidty;
            static const adf::port_type ptEnum = adf::port_type::port_blank; //do not support ap_axis as RTP
            static const int arraySize = 0;
            static const int apBitWidth = D;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //ap_axiu
        template <int D> struct tyPortType<ap_axiu<D, 0, 0, 0>> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_ap_axiu;
            static const adf::param_type subPtype = adf::param_type::p_voidty;
            static const adf::port_type ptEnum = adf::port_type::port_blank; //do not support ap_axis as RTP
            static const int arraySize = 0;
            static const int apBitWidth = D;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        /************ tyPortType template specialization: RTP ************/

        //input scalar RTP
        template <typename _XILINX_ADF_T> struct tyPortType <const _XILINX_ADF_T> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::subPtype;
            static const adf::port_type ptEnum = tyPortType<_XILINX_ADF_T>::ptEnum;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //input scalar RTP
        template <typename _XILINX_ADF_T> struct tyPortType
            <_XILINX_ADF_T const &,
             std::enable_if_t<!Disjunction<std::is_array<_XILINX_ADF_T>,
                                           MapBufferPort<_XILINX_ADF_T>>::value>> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::subPtype;
            static const adf::port_type ptEnum = tyPortType<_XILINX_ADF_T>::ptEnum;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //output scalar RTP
        template <typename _XILINX_ADF_T> struct tyPortType
            <_XILINX_ADF_T &,
             std::enable_if_t<!Disjunction<std::is_const<_XILINX_ADF_T>,
                                           std::is_array<_XILINX_ADF_T>,
                                           MapBufferPort<_XILINX_ADF_T>>::value>> {
            static const adf::port_direction pd = adf::port_direction::dir_inout;
            static const adf::param_type paramType = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::subPtype;
            static const adf::port_type ptEnum = tyPortType<_XILINX_ADF_T>::ptEnum;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //input array RTP: const T(&)[N]
        template <typename _XILINX_ADF_T, std::size_t _XILINX_ADF_Q>
            struct tyPortType
            <_XILINX_ADF_T const (&)[_XILINX_ADF_Q] > {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_array;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = tyPortType<_XILINX_ADF_T>::ptEnum;
            static const int arraySize = _XILINX_ADF_Q;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //output array RTP: T(&)[N]
        template <typename _XILINX_ADF_T, std::size_t _XILINX_ADF_Q>
            struct tyPortType
            <_XILINX_ADF_T(&)[_XILINX_ADF_Q],
             std::enable_if_t<!Disjunction<std::is_const<_XILINX_ADF_T>,
                                           MapBufferPort<_XILINX_ADF_T>>::value>> {
            static const adf::port_direction pd = adf::port_direction::dir_inout;
            static const adf::param_type paramType = adf::param_type::p_array;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = tyPortType<_XILINX_ADF_T>::ptEnum;
            static const int arraySize = _XILINX_ADF_Q;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        /************ tyPortType template specialization: hls stream ************/

        //adf::in<hls::stream<T, D>&>
        template <typename _XILINX_ADF_T, int DEPTH> struct tyPortType<adf::dir::in<hls::stream<_XILINX_ADF_T, DEPTH>&>> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_hls_stream;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = adf::port_type::port_stream;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //adf::out<hls::stream<T, D>&>
        template <typename _XILINX_ADF_T, int DEPTH> struct tyPortType<adf::dir::out<hls::stream<_XILINX_ADF_T, DEPTH>&>> {
            static const adf::port_direction pd = adf::port_direction::dir_out;
            static const adf::param_type paramType = adf::param_type::p_hls_stream;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = adf::port_type::port_stream;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        /************ tyPortType template specialization: PL/HLS kernel global memory access ************/

        //input const pointer for read-only GM access
        template <typename _XILINX_ADF_T> struct tyPortType <const _XILINX_ADF_T *,
                    typename std::enable_if<!MapBufferPort<_XILINX_ADF_T>::value>::type> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_pointer;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = adf::port_type::port_global_memory;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //input const array for read-only GM access (C++ canonical data type is still pointer)
        template <typename _XILINX_ADF_T, std::size_t _XILINX_ADF_Q> struct tyPortType <const _XILINX_ADF_T[_XILINX_ADF_Q]> {
            static const adf::port_direction pd = adf::port_direction::dir_in;
            static const adf::param_type paramType = adf::param_type::p_pointer;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = adf::port_type::port_global_memory;
            static const int arraySize = _XILINX_ADF_Q;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //inout pointer for read-write GM access
        template<typename tpPortTy> struct CascadePort: std::false_type {};
        template<typename Ty> struct CascadePort<input_cascade<Ty>>: std::true_type{};
        template<typename Ty> struct CascadePort<output_cascade<Ty>>: std::true_type{};

        template <typename _XILINX_ADF_T> struct tyPortType <_XILINX_ADF_T *,
                typename std::enable_if<!MapBufferPort<_XILINX_ADF_T>::value  && 
                                        !CascadePort<_XILINX_ADF_T>::value &&
                                        !std::is_const<_XILINX_ADF_T>::value>::type> {
            static const adf::port_direction pd = adf::port_direction::dir_inout;
            static const adf::param_type paramType = adf::param_type::p_pointer;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = adf::port_type::port_global_memory;
            static const int arraySize = 0;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        //inout pointer for read-write GM access (C++ canonical data type is still pointer)
        template <typename _XILINX_ADF_T, std::size_t _XILINX_ADF_Q> struct tyPortType <_XILINX_ADF_T[_XILINX_ADF_Q]> {
            static const adf::port_direction pd = adf::port_direction::dir_inout;
            static const adf::param_type paramType = adf::param_type::p_pointer;
            static const adf::param_type subPtype = tyPortType<_XILINX_ADF_T>::paramType;
            static const adf::port_type ptEnum = adf::port_type::port_global_memory;
            static const int arraySize = _XILINX_ADF_Q;
            static const int apBitWidth = tyPortType<_XILINX_ADF_T>::apBitWidth;
            static const adf::locking_mode lockingMode = adf::locking_mode::lm_auto;
            static std::vector<uint32_t> dimensions() { return {};}
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        /************ tyPortType template specialization: buffer ports ************/
        template <typename _XILINX_ADF_T>
            struct tyPortType<_XILINX_ADF_T &,
                              typename std::enable_if<MapBufferPort<_XILINX_ADF_T>::value>::type>
        {
            static const adf::port_direction pd
                = MapBufferPort<_XILINX_ADF_T>::direction();
            static const adf::param_type paramType = adf::param_type::p_buffer;
            static const adf::param_type subPtype 
                = MapBufferPort<_XILINX_ADF_T>::subPtype();
            static const adf::port_type ptEnum = adf::port_type::port_buffer;
            static const int arraySize = 0;
            static const int apBitWidth = 0;
            static const adf::locking_mode lockingMode
                = MapBufferPort<_XILINX_ADF_T>::lockingMode();
            static std::vector<uint32_t> dimensions() {
                return MapBufferPort<_XILINX_ADF_T>::dimensions();
            };
            static const bool hasCyclicAddressing
            = MapBufferPort<_XILINX_ADF_T>::hasCyclicAddressing();
            static const uint32_t margin = MapBufferPort<_XILINX_ADF_T>::margin();
        };

        template <typename _XILINX_ADF_T>
        struct tyPortType<_XILINX_ADF_T *,
            typename std::enable_if<MapBufferPort<_XILINX_ADF_T>::value>::type>
        {
            static_assert(MapBufferPort<_XILINX_ADF_T *>::value, "Buffer ports must be passed by reference.");
        };

        /**************************** kernel port *******************************/

        template<typename _XILINX_ADF_T> port_info portTypeToInfo()
        {
            return {
                tyPortType<_XILINX_ADF_T>::pd,
                tyPortType<_XILINX_ADF_T>::paramType,
                tyPortType<_XILINX_ADF_T>::subPtype,
                tyPortType<_XILINX_ADF_T>::ptEnum,
                tyPortType<_XILINX_ADF_T>::arraySize,
                tyPortType<_XILINX_ADF_T>::apBitWidth,
                tyPortType<_XILINX_ADF_T>::lockingMode,
                tyPortType<_XILINX_ADF_T>::dimensions(),
                tyPortType<_XILINX_ADF_T>::hasCyclicAddressing,
                tyPortType<_XILINX_ADF_T>::margin
            };
        }

        template<int _XILINX_ADF_N, typename _XILINX_ADF_R> struct FuncArgIter {
            typedef typename _XILINX_ADF_R::firstType _XILINX_ADF_R0;
            typedef typename _XILINX_ADF_R::restType rest;
            static void addPorts(kernel& k) {
                addPort(k, portTypeToInfo<_XILINX_ADF_R0>());
                FuncArgIter<_XILINX_ADF_N - 1, rest>::addPorts(k);
            }
        };

        template<typename _XILINX_ADF_R> struct FuncArgIter<0, _XILINX_ADF_R> {
            static void addPorts(kernel& k) {}
        };


        /**************************** kernel parameter *******************************/

        struct param_info
        {
            element_type elemType;
            bool isPointer;
            bool isArray;
            int arraySize;
        };

        class RegisterKernelClass
        {
        public:
            static void setKernelForRegistration(kernel& k, std::string className);
            static kernel* getKernelForRegistration();
            static void registerParameter(param_info paramInfo, std::string varName, std::string file = std::string(), int line = -1);
            static void completeRegistration();

            template<typename _XILINX_ADF_C, typename _XILINX_ADF_Q, typename ..._XILINX_ADF_FArgs>
            static void registerFunction(_XILINX_ADF_Q(_XILINX_ADF_C::*)(_XILINX_ADF_FArgs...), std::string funcName, std::string file = std::string(), int line = -1)
            {
                api_impl::FuncArgIter<api_impl::Arity<void(_XILINX_ADF_FArgs ...)>::value, api_impl::FuncType<void(_XILINX_ADF_FArgs ...)>>::addPorts(*s_pKernel);
                registerFunction(funcName, file, line);
            }

        private:
            static void registerFunction(std::string funcName, std::string file, int line);
            static kernel* s_pKernel;
        };

        template <typename _TYPE> struct paramType
        {
            static const element_type elemType = element_type::et_voidty;
            static const bool isArray = false;
            static const bool isConst = false;
            static const bool isPointer = false;
            static const bool isReference = false;
            static const int arraySize = 0;
        };

#define SCALAR_PARAM_TYPE(state, elemtype)                                \
        template <> struct paramType<state>                               \
        {                                                                 \
            static const element_type elemType = element_type::elemtype;  \
            static const bool isArray = false;                            \
            static const bool isConst = false;                            \
            static const bool isPointer = false;                          \
            static const bool isReference = false;                        \
            static const int arraySize = 0;                               \
        }

        SCALAR_PARAM_TYPE(int8, et_int8);
        SCALAR_PARAM_TYPE(int16, et_int16);
        SCALAR_PARAM_TYPE(int32, et_int32);
        SCALAR_PARAM_TYPE(int64, et_int64);
        SCALAR_PARAM_TYPE(uint8, et_uint8);
        SCALAR_PARAM_TYPE(uint16, et_uint16);
        SCALAR_PARAM_TYPE(uint32, et_uint32);
        SCALAR_PARAM_TYPE(uint64, et_uint64);
        SCALAR_PARAM_TYPE(float, et_float);
        SCALAR_PARAM_TYPE(double, et_double);
        SCALAR_PARAM_TYPE(bool, et_bool);
        SCALAR_PARAM_TYPE(cint16, et_cint16);
        SCALAR_PARAM_TYPE(cint32, et_cint32);
#if __AIE_ARCH__<=20
        SCALAR_PARAM_TYPE(cfloat, et_cfloat);
#endif
#if __AIE_ARCH__>=20
        SCALAR_PARAM_TYPE(int4, et_int4);
        SCALAR_PARAM_TYPE(uint4, et_uint4);
        SCALAR_PARAM_TYPE(bfloat16, et_bfloat16);
#endif
#if __AIE_ARCH__>=22
        SCALAR_PARAM_TYPE(float16, et_float16);
        SCALAR_PARAM_TYPE(bfloat8, et_bfloat8);
        SCALAR_PARAM_TYPE(float8, et_float8);
#endif

        template <typename _TYPE, size_t _SIZE> struct paramType<_TYPE[_SIZE]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = false;
            static const bool isPointer = false;
            static const bool isReference = false;
            static const int arraySize = _SIZE;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _TYPE, size_t _SIZE> struct paramType<const _TYPE[_SIZE]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = true;
            static const bool isPointer = false;
            static const bool isReference = false;
            static const int arraySize = _SIZE;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _TYPE, size_t _SIZE> struct paramType<_TYPE(&)[_SIZE]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = false;
            static const bool isPointer = false;
            static const bool isReference = true;
            static const int arraySize = _SIZE;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _TYPE, size_t _SIZE> struct paramType<const _TYPE(&)[_SIZE]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = true;
            static const bool isPointer = false;
            static const bool isReference = true;
            static const int arraySize = _SIZE;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        /*template <typename _TYPE, size_t _SIZE> struct paramType<_TYPE(*)[_SIZE]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isPointer = true;
            static const bool isArray = true;
            static const int arraySize = _SIZE;
        };

        template <typename _TYPE, size_t _SIZE> struct paramType<const _TYPE(*)[_SIZE]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isPointer = true;
            static const bool isArray = true;
            static const int arraySize = _SIZE;
        };*/

        template <typename _TYPE, size_t _SIZE1, size_t _SIZE2> struct paramType<_TYPE[_SIZE1][_SIZE2]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = false;
            static const bool isPointer = false;
            static const bool isReference = false;
            static const int arraySize = _SIZE1*_SIZE2;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _TYPE,size_t _SIZE1, size_t _SIZE2> struct paramType<const _TYPE[_SIZE1][_SIZE2]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = true;
            static const bool isPointer = false;
            static const bool isReference = false;
            static const int arraySize = _SIZE1*_SIZE2;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _TYPE,size_t _SIZE1, size_t _SIZE2> struct paramType<_TYPE(&)[_SIZE1][_SIZE2]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = false;
            static const bool isPointer = false;
            static const bool isReference = true;
            static const int arraySize = _SIZE1*_SIZE2;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template <typename _TYPE,size_t _SIZE1, size_t _SIZE2> struct paramType<const _TYPE(&)[_SIZE1][_SIZE2]>
        {
            static const element_type elemType = paramType<_TYPE>::elemType;
            static const bool isArray = true;
            static const bool isConst = true;
            static const bool isPointer = false;
            static const bool isReference = true;
            static const int arraySize = _SIZE1*_SIZE2;
            static const bool hasCyclicAddressing = false;
            static const uint32_t margin = 0;
        };

        template<typename _TYPE> param_info paramTypeToInfo()
        {
            return{ paramType<_TYPE>::elemType, paramType<_TYPE>::isPointer, paramType<_TYPE>::isArray, paramType<_TYPE>::arraySize };
        }

#ifdef __AIENGINE__
#define REGISTER_PARAMETER(var) {}
#else
#define REGISTER_PARAMETER(var) \
        adf::api_impl::RegisterKernelClass::registerParameter(adf::api_impl::paramTypeToInfo<decltype(var)>(), #var, __FILE__, __LINE__)
#endif

#ifdef __AIENGINE__
#define REGISTER_FUNCTION(func) {}
#else
#define REGISTER_FUNCTION(func) \
        adf::api_impl::RegisterKernelClass::registerFunction(&func, #func, __FILE__, __LINE__)
#endif

        class ADF_API_EXPORT variant
        {
        public:
            template<typename _TYPE> variant(_TYPE val)
                : elemType(element_type::et_voidty), isArray(false)
            {
                if (paramType<_TYPE>::elemType != element_type::et_voidty && !paramType<_TYPE>::isPointer && !paramType<_TYPE>::isArray)
                {
                    elemType = paramType<_TYPE>::elemType;
                    isArray = false;
                    value.resize(sizeof(_TYPE));
                    *(_TYPE*)value.data() = val;
                }
                //else //invalid by default
            }

            template<typename _TYPE> variant(const std::initializer_list<_TYPE>& val)
                : elemType(element_type::et_voidty), isArray(false)
            {
                if (paramType<_TYPE>::elemType != element_type::et_voidty && !paramType<_TYPE>::isPointer && !paramType<_TYPE>::isArray)
                {
                    elemType = paramType<_TYPE>::elemType;
                    isArray = true;
                    value.resize(sizeof(_TYPE) * val.size());
                    std::memcpy(value.data(), val.begin(), value.size());
                }
                //else //invalid by default
            }

            template<typename _TYPE> variant(const std::vector<_TYPE>& val)
                : elemType(element_type::et_voidty), isArray(false)
            {
                if (paramType<_TYPE>::elemType != element_type::et_voidty && !paramType<_TYPE>::isPointer && !paramType<_TYPE>::isArray)
                {
                    elemType = paramType<_TYPE>::elemType;
                    isArray = true;
                    value.resize(sizeof(_TYPE) * val.size());
                    std::memcpy(value.data(), val.data(), value.size());
                }
                //else //invalid by default
            }

            template<typename _TYPE, size_t _SIZE> variant(const std::array<_TYPE, _SIZE>& val)
                : elemType(element_type::et_voidty), isArray(false)
            {
                if (paramType<_TYPE>::elemType != element_type::et_voidty && !paramType<_TYPE>::isPointer && !paramType<_TYPE>::isArray)
                {
                    elemType = paramType<_TYPE>::elemType;
                    isArray = true;
                    value.resize(sizeof(_TYPE) * val.size());
                    std::memcpy(value.data(), val.data(), value.size());
                }
                //else //invalid by default
            }

            variant() : elemType(element_type::et_voidty), isArray(false) {}

            std::string toStr() const;
            size_t numElements() const;

            int64_t getInt(unsigned idx = 0) const;
            double getFloat(unsigned idx = 0) const;
            const std::vector<uint8_t>& getValueInBytes();
            
            element_type elemType;
            bool isArray;
            
        private:
            std::vector<uint8_t> value;
        };

        void setConstructorParameters(kernel& k, const std::vector<variant>& params);

        //base function for variadic template reduction
        void collectParams(std::vector<variant>& params);

        template<typename _TYPE, typename... _TYPES> void collectParams(std::vector<variant>& params, _TYPE value, _TYPES... values)
        {
            params.push_back(variant(value));
            collectParams(params, values...);
        }

        template<typename... Types> void setConstructorParams(kernel& k, Types... values)
        {
            std::vector<api_impl::variant> params;
            api_impl::collectParams(params, values...);
            api_impl::setConstructorParameters(k, params);
        }
    }

    template<class T> class vector: public std::vector<T> {
    public:
         vector() : std::vector<T>() {}

         typename std::vector<T>::const_reference operator[](typename std::vector<T>::size_type _Pos) const {
             api_impl::checkVectorAccess(_Pos, this->size());
             return std::vector<T>::operator[](_Pos);
         }

         typename std::vector<T>::reference operator[](typename std::vector<T>::size_type _Pos) {
             api_impl::checkVectorAccess(_Pos, this->size());
             return std::vector<T>::operator[](_Pos);
         }
    };

/**************************** frontend *******************************/

    namespace frontend
    {
        class ADF_API_EXPORT DeclConnect
        {
        public:
            DeclConnect(const char* loc, const char* varName);
        };

        class ADF_API_EXPORT CallExprKernelCreate
        {
        public:
            CallExprKernelCreate(const char* funcName, bool isInline, const char* loc, const std::vector<std::string>& argTypes, const std::vector<std::string>& argNames, const char* returnType, const char* templateDeclaration, const char* headerPath);
        };

        class ADF_API_EXPORT CallExprKernelObjectCreate
        {
        public:
            CallExprKernelObjectCreate(const char* loc, const std::vector<std::string>& constructorParamArgTypes, const std::vector<std::string>& constructorParamArgNames, const char* headerLoc);
        };

        class ADF_API_EXPORT CallExprRegisterFunction
        {
        public:
            CallExprRegisterFunction(KernelImpl* pKernel, bool isInline, const std::vector<std::string>& argTypes, const std::vector<std::string>& argNames);
        };

        struct KernelClassTemplateInstantiation
        {
            std::string kernelClassType;
            bool isInline;
			bool isExplicitClassSpecialization;
            std::vector<std::string> argTypes;
            std::vector<std::string> argNames;
        };

        class ADF_API_EXPORT CallExprRegisterFunctionTemplateKernelClass
        {
        public:
            CallExprRegisterFunctionTemplateKernelClass(KernelImpl* pKernel, const std::vector<KernelClassTemplateInstantiation>& instantiations);
        };

        class ADF_API_EXPORT CallExprParameterArray
        {
        public:
            CallExprParameterArray(const char* arrayName, const char* loc);
        };

        class ADF_API_EXPORT CallExprConstraintFunction
        {
        public:
            CallExprConstraintFunction(const char* funcName, const char* loc);
        };

        class ADF_API_EXPORT CallExprLocationConstraint
        {
        public:
            CallExprLocationConstraint(const char* funcName, const char* loc);
        };

        struct KernelTemplateInstantiation
        {
            std::string graphType;
            std::string funcName;
            bool isInline;
            std::vector<std::string> argTypes;
            std::vector<std::string> argNames;
            std::string returnType;
        };

        class CallExprKernelCreateTemplatedGraphAndKernel
        {
        public:
            CallExprKernelCreateTemplatedGraphAndKernel(const char* loc, const char* templateDeclaration, const std::vector<KernelTemplateInstantiation>& instantiations);
        };

        class ADF_API_EXPORT DeclGraph
        {
        public:
            DeclGraph(GraphImpl* pGraph, GraphImpl* pParent, const char* varName, const char* graphType, const char* loc, const char* typeLoc);
        };

        class ADF_API_EXPORT DeclObject
        {
        public:
            DeclObject(ObjectImpl* pObj, const char* varName, const char* loc);
        };

        class ADF_API_EXPORT UnsupportedDeclObject
        {
        public:
            UnsupportedDeclObject(const char* varName, const char* varType, const char* loc);
        };

        class ADF_API_EXPORT DeclObjectArray
        {
        public:
            DeclObjectArray(std::vector<ObjectImpl*> objectImpls, std::vector<size_t> dimensions, const char* varName, const char* loc);
        };

        class ADF_API_EXPORT DeclGraphArray
        {
        public:
            DeclGraphArray(std::vector<GraphImpl*> graphImpls, std::vector<size_t> dimensions, GraphImpl* pParent, const char* varName, const char* graphType, const char* loc, const char *typeLoc);
        };
    
        class ADF_API_EXPORT SignalHandler
        {
        public:
            SignalHandler();
        private:
            static void handle_sigsegv(int);
        };

        XV_MEIR_EXPORT int writeMeIr(std::string filename, int argc, char** argv);

//XXX Needed because adf_api_xrt on aarch does not compile with --std=c++17
#ifdef __ADF_FRONTEND__
        template<typename T>
        GraphImpl *
        getParentGraphImpl(T &obj)
        {
            if constexpr (std::is_base_of_v< graph, T >)
            {
                return obj.impl.get();
            } 
            else
            {
                return nullptr;
            } 
        }

        template<typename T>
        struct IsNonGraphObj: std::false_type {};
        template<> struct IsNonGraphObj<::adf::bypass>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::input_gmio>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::input_plio>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::kernel>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::output_gmio>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::output_plio>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::parameter>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::pktcontrol>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::microcontroller>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::port<adf::input>>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::port<adf::output>>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::port<adf::inout>>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::samples_per_iteration>: std::true_type {};
        template<> struct IsNonGraphObj<::adf::Operator>: std::true_type {};
        template<int nway> struct IsNonGraphObj<::adf::pktmerge<nway>>: std::true_type {};
        template<int nway> struct IsNonGraphObj<::adf::pktorderedmerge<nway>>: std::true_type {};
        template<int nway> struct IsNonGraphObj<::adf::pktsplit<nway>>: std::true_type {};
        template<typename T> struct IsNonGraphObj<::adf::external_buffer<T>>: std::true_type {};
        template<typename T> struct IsNonGraphObj<::adf::shared_buffer<T>>: std::true_type {};

        template<typename T>
        struct IsConnect: std::false_type {};
        template<typename T1, typename T2> struct IsConnect<::adf::connect<T1,T2>>: std::true_type {};

        template<typename T>
        struct IsSimulationPlatform: std::false_type {};
        template<size_t numI, size_t numO> struct IsSimulationPlatform<::adf::simulation::platform<numI,numO>>: std::true_type {};

        ADF_API_EXPORT std::string getDemangledTypeName(const std::type_info  &ti);

        template<typename T, size_t ... DIMS>
        auto instrumentArray(T *obj, const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            constexpr size_t num = (... * DIMS);
            if constexpr (std::is_base_of_v< graph, T >)
            {
                std::vector<size_t> dims = { DIMS... };
                
                std::vector<GraphImpl*> impls;
                for (size_t k0 = 0; k0 < num; ++k0)
                    impls.push_back(reinterpret_cast<GraphImpl*>(obj[k0].impl.get()));

                std::string dName = num > 0 ? getDemangledTypeName(typeid(obj[0])) : "";
                return DeclGraphArray { impls, dims, par, varName, dName.c_str(), loc, typeLoc };
            } 
            else if constexpr (IsNonGraphObj<T>::value)
            {
                std::vector<size_t> dims = { DIMS... };
                std::vector<ObjectImpl*> impls;
                for (size_t k0 = 0; k0 < num; ++k0)
                    impls.push_back(reinterpret_cast<ObjectImpl*>(obj[k0].impl.get()));
                return DeclObjectArray { impls, dims, varName, loc };
            } 
            else if constexpr (std::is_same_v<T,::adf::PLIO> || std::is_same_v<T,adf::GMIO> || std::is_same_v<T,::adf::FileIO>)
            {
                std::vector<size_t> dims = { DIMS... };
                std::vector<ObjectImpl*> impls;
                for (size_t k0 = 0; k0 < num; ++k0)
                    impls.push_back(reinterpret_cast<ObjectImpl*>(obj[k0].impl.get()));
                return DeclObjectArray { impls, dims, varName, loc };
            } 
            else
            {
                return int { 0 };
            } 
        }

        template<typename T>
        auto instrumentAux(T &obj, const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            return int { 0 };
        }
    
        template<typename T, size_t dim0>
        auto instrumentAux(std::array<T,dim0> &obj, const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            return instrumentArray<T, dim0>(obj.data(), varName, loc, par, typeLoc);
        }

        template<typename T, size_t dim0>
        auto instrumentAux(T (&obj)[dim0], const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            return instrumentArray<T, dim0>(&obj[0], varName, loc, par, typeLoc);
        }

        template<typename T, size_t dim0, size_t dim1>
        auto instrumentAux(T (&obj)[dim0][dim1], const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            return instrumentArray<T, dim0, dim1>(&obj[0][0], varName, loc, par, typeLoc);
        }

        template<typename T, size_t dim0, size_t dim1, size_t dim2>
        auto instrumentAux(T (&obj)[dim0][dim1][dim2], const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            return instrumentArray<T, dim0, dim1, dim2>(&obj[0][0][0], varName, loc, par, typeLoc);
        }

        template<typename T>
        auto instrumentAux(std::vector<T> &obj, const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            using TT = std::remove_pointer_t< T >;
            if constexpr (std::is_base_of_v< graph, TT >)
            {
                std::string dName = getDemangledTypeName(typeid(obj));
                return UnsupportedDeclObject(varName, dName.c_str(), loc);
            } 
            else if constexpr (IsNonGraphObj< TT >::value)
            {
                std::string dName = getDemangledTypeName(typeid(obj));
                return UnsupportedDeclObject(varName, dName.c_str(), loc);
            } 
            else
            {
                return int { 0 };
            } 
        }

        template<typename T>
        auto instrument(T &obj, const char* varName = "", const char* loc = "", GraphImpl *par = nullptr, const char *typeLoc = "")
        {
            if constexpr (std::is_base_of_v< graph, T >)
            {
                std::string dName = getDemangledTypeName(typeid(obj));
                return DeclGraph { reinterpret_cast<GraphImpl*>(obj.impl.get()), par, varName, dName.c_str(), loc, typeLoc };
            } 
            else if constexpr (IsNonGraphObj<T>::value)
            {
                return DeclObject { reinterpret_cast<ObjectImpl*>(obj.impl.get()), varName, loc };
            } 
            else if constexpr (IsConnect<T>::value)
            {
                return DeclConnect { loc, varName };
            } 
            else if constexpr (IsSimulationPlatform<T>::value)
            {
                return DeclObject { reinterpret_cast<ObjectImpl*>(obj.impl.get()), varName, loc };
            } 
            else if constexpr (std::is_same_v<T,::adf::PLIO> || std::is_same_v<T,adf::GMIO> || std::is_same_v<T,::adf::FileIO>)
            {
                return DeclObject { reinterpret_cast<ObjectImpl*>(obj.impl.get()), varName, loc };
            } 
            else if constexpr (std::is_pointer_v<T> && std::is_base_of_v< graph, std::remove_pointer_t<T> >)
            {
                std::string dName = getDemangledTypeName(typeid(obj));
                return UnsupportedDeclObject(varName, dName.c_str(), loc);
            } 
            else if constexpr (std::is_pointer_v<T> && IsNonGraphObj< std::remove_pointer_t<T> >::value)
            {
                std::string dName = getDemangledTypeName(typeid(obj));
                return UnsupportedDeclObject(varName, dName.c_str(), loc);
            } 
            else if constexpr (std::is_reference_v<T>)
            {
                return int { 0 };
            } 
            else
            {
                return instrumentAux(obj, varName, loc, par, typeLoc);
            } 
        }
#endif  // #ifdef __ADF_FRONTEND__
    } // namespace frontend
} // namespace aff

#endif
