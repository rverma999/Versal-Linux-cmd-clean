// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _NFE_ADF_H_
#define _NFE_ADF_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdarg.h>
#include <type_traits>
#include "types.h"
#include "adf_api_impl.h"

#ifndef __X86SIM__

#include "adf/window/types.h"
#include "adf/stream/types.h"
#endif

#define restrict

namespace adf {

#define output_port port<adf::output>
#define input_port  port<adf::input>
#define inout_port  port<adf::inout>

  /* Port related functions and classes.  */
  template <class _XILINX_ADF_TYP_T> class port {
  public:
    port () { api_impl::createPort(impl, _XILINX_ADF_TYP_T::dir); }
    port(std::shared_ptr<PortImpl> spPort) { api_impl::createPort(impl, spPort); }
    std::shared_ptr<PortImpl> impl;
  };

  /* Graph related functions and classes.  */
  class ADF_API_EXPORT graph {
  public:
      graph();
  public:
    virtual return_code init();
    virtual return_code run();
    virtual return_code run(int iterations);
    virtual return_code wait();
    virtual return_code wait(unsigned int cycle_timeout);
    virtual return_code resume();
    virtual return_code end();
    virtual return_code end(unsigned int cycle_timeout);


    virtual return_code update(input_port& rtpPort, int8 value);
    virtual return_code update(input_port& rtpPort, const int8* value, size_t size);
    virtual return_code update(input_port& rtpPort, uint8 value);
    virtual return_code update(input_port& rtpPort, const uint8* value, size_t size);

    virtual return_code update(input_port& rtpPort, int16 value);
    virtual return_code update(input_port& rtpPort, const int16* value, size_t size);
    virtual return_code update(input_port& rtpPort, uint16 value);
    virtual return_code update(input_port& rtpPort, const uint16* value, size_t size);

    virtual return_code update(input_port& rtpPort, int32 value);
    virtual return_code update(input_port& rtpPort, const int32* value, size_t size);
    virtual return_code update(input_port& rtpPort, uint32 value);
    virtual return_code update(input_port& rtpPort, const uint32* value, size_t size);

    virtual return_code update(input_port& rtpPort, int64 value);
    virtual return_code update(input_port& rtpPort, const int64* value, size_t size);
    virtual return_code update(input_port& rtpPort, uint64 value);
    virtual return_code update(input_port& rtpPort, const uint64* value, size_t size);

    virtual return_code update(input_port& rtpPort, float value);
    virtual return_code update(input_port& rtpPort, const float* value, size_t size);

    virtual return_code update(input_port& rtpPort, cint16 value);
    virtual return_code update(input_port& rtpPort, const cint16* value, size_t size);

    virtual return_code update(input_port& rtpPort, cint32 value);
    virtual return_code update(input_port& rtpPort, const cint32* value, size_t size);

    virtual return_code update(input_port& rtpPort, bfloat16 value);
    virtual return_code update(input_port& rtpPort, const bfloat16* value, size_t size);

    virtual return_code update(input_port& rtpPort, float16 value);
    virtual return_code update(input_port& rtpPort, const float16* value, size_t size);

    virtual return_code update(input_port& rtpPort, bfloat8 value);
    virtual return_code update(input_port& rtpPort, const bfloat8* value, size_t size);

    virtual return_code update(input_port& rtpPort, float8 value);
    virtual return_code update(input_port& rtpPort, const float8* value, size_t size);


    virtual return_code read(inout_port& rtpPort, int8& value);
    virtual return_code read(inout_port& rtpPort, int8* value, size_t size);
    virtual return_code read(inout_port& rtpPort, uint8& value);
    virtual return_code read(inout_port& rtpPort, uint8* value, size_t size);

    virtual return_code read(inout_port& rtpPort, int16& value);
    virtual return_code read(inout_port& rtpPort, int16* value, size_t size);
    virtual return_code read(inout_port& rtpPort, uint16& value);
    virtual return_code read(inout_port& rtpPort, uint16* value, size_t size);

    virtual return_code read(inout_port& rtpPort, int32& value);
    virtual return_code read(inout_port& rtpPort, int32* value, size_t size);
    virtual return_code read(inout_port& rtpPort, uint32& value);
    virtual return_code read(inout_port& rtpPort, uint32* value, size_t size);

    virtual return_code read(inout_port& rtpPort, int64& value);
    virtual return_code read(inout_port& rtpPort, int64* value, size_t size);
    virtual return_code read(inout_port& rtpPort, uint64& value);
    virtual return_code read(inout_port& rtpPort, uint64* value, size_t size);

    virtual return_code read(inout_port& rtpPort, float& value);
    virtual return_code read(inout_port& rtpPort, float* value, size_t size);

    virtual return_code read(inout_port& rtpPort, cint16& value);
    virtual return_code read(inout_port& rtpPort, cint16* value, size_t size);

    virtual return_code read(inout_port& rtpPort, cint32& value);
    virtual return_code read(inout_port& rtpPort, cint32* value, size_t size);

    virtual return_code read(inout_port& rtpPort, bfloat16& value);
    virtual return_code read(inout_port& rtpPort, bfloat16* value, size_t size);

    virtual return_code read(inout_port& rtpPort, float16& value);
    virtual return_code read(inout_port& rtpPort, float16* value, size_t size);

    virtual return_code read(inout_port& rtpPort, bfloat8& value);
    virtual return_code read(inout_port& rtpPort, bfloat8* value, size_t size);

    virtual return_code read(inout_port& rtpPort, float8& value);
    virtual return_code read(inout_port& rtpPort, float8* value, size_t size);

#if __AIE_ARCH__<=20
    virtual return_code update(input_port& rtpPort, cfloat value);
    virtual return_code update(input_port& rtpPort, const cfloat* value, size_t size);

    virtual return_code read(inout_port& rtpPort, cfloat& value);
    virtual return_code read(inout_port& rtpPort, cfloat* value, size_t size);
#endif
    void as_interface();
    void as_alternative();
    void register_alternatives(std::vector<adf::graph*> alternativeGraphs);

    std::shared_ptr<GraphImpl> impl;
  };

  /* Prameter related functions and classes.  */
  class ADF_API_EXPORT parameter {
  public:
    parameter();

    template<typename _XILINX_ADF_TYP_T>
      static adf::parameter array (_XILINX_ADF_TYP_T &) {
#ifdef __ADF_FRONTEND__
      return create(api_impl::paramTypeToInfo<_XILINX_ADF_TYP_T>());
#else
      return adf::parameter();
#endif
    }

    parameter& operator=(const parameter& from);
    std::shared_ptr<ParameterImpl> impl;
    enum { winsz = sizeof(int), margin = 0, porttype = port_type::port_runtime_param }; //enum for connect<parameter>

  private:
    static adf::parameter create(api_impl::param_info paramInfo);

    friend void api_impl::RegisterKernelClass::registerParameter(api_impl::param_info paramInfo, std::string varName, std::string file, int line);
  };

  /* Kernel related functions and classes.  */
  class ADF_API_EXPORT kernel {
  public:
    kernel();
    adf::vector<adf::port<adf::input>> in;
    adf::vector<adf::port<adf::output>> out;
    adf::vector<adf::port<adf::inout>> inout;
    adf::vector<adf::parameter> param;

    template<typename _XILINX_ADF_Q, typename ..._XILINX_ADF_FArgs>
    static adf::kernel create (_XILINX_ADF_Q (f)(_XILINX_ADF_FArgs...)) {
      kernel k = create();
      api_impl::FuncArgIter<api_impl::Arity<void(_XILINX_ADF_FArgs ...)>::value, api_impl::FuncType<void(_XILINX_ADF_FArgs ...)>>::addPorts(k);
      return k;
    }

    template<typename _XILINX_ADF_C, typename... Types>
    static adf::kernel create_object(Types... values) {
        kernel k = create();
        api_impl::RegisterKernelClass::setKernelForRegistration(k, typeid(_XILINX_ADF_C).name());
        _XILINX_ADF_C::registerKernelClass();
        api_impl::RegisterKernelClass::completeRegistration();
        api_impl::setConstructorParams(k, values...);
        return k;
    }

    kernel& operator=(const kernel&);
    std::shared_ptr<KernelImpl> impl;

  private:
    static adf::kernel create();
  };

  template <int nway>
    class pktmerge {
  public:
    adf::vector<adf::port<adf::input>> in;
    adf::vector<adf::port<adf::output>> out;

    pktmerge() { api_impl::createPktMerge(impl); }

    static adf::pktmerge<nway> create() {
      adf::pktmerge<nway> x;
      api_impl::createPktMerge(x.impl, nway, x.in, x.out);
      return x;
    }

    pktmerge<nway>& operator=(const pktmerge<nway>& from) { api_impl::assignmentPktMerge(impl, in, out, from.impl, from.in, from.out); return *this; }
    std::shared_ptr<PktMergeImpl> impl;
  };

  template <int nway>
    class pktorderedmerge {
  public:
    adf::vector<adf::port<adf::input>> in;
    adf::vector<adf::port<adf::output>> out;
    pktorderedmerge() { api_impl::createPktOrderedMerge(impl); }
    static adf::pktorderedmerge<nway> create() {
      adf::pktorderedmerge<nway> x;
      api_impl::createPktOrderedMerge(x.impl, nway, x.in, x.out);
      return x;
    }

    pktorderedmerge<nway>& operator=(const pktorderedmerge<nway>& from) { api_impl::assignmentPktOrderedMerge(impl, in, out, from.impl, from.in, from.out); return *this; }
    std::shared_ptr<PktOrderedMergeImpl> impl;
  };

  template <int nway>
    class pktsplit {
  public:
    adf::vector<adf::port<adf::input>> in;
    adf::vector<adf::port<adf::output>> out;

    pktsplit() { api_impl::createPktSplit(impl); }

    static adf::pktsplit<nway> create() {
      adf::pktsplit<nway> x;
      api_impl::createPktSplit(x.impl, nway, x.in, x.out);
      return x;
    }

    pktsplit<nway>& operator=(const pktsplit<nway>& from) { api_impl::assignmentPktSplit(impl, in, out, from.impl, from.in, from.out); return *this; }
    std::shared_ptr<PktSplitImpl> impl;
  };

  class pktcontrol {
  public:
    adf::vector<adf::port<adf::input>> in;
    adf::vector<adf::port<adf::output>> out;

    pktcontrol() { api_impl::createPktControl(impl); }

    static adf::pktcontrol create(bool return_packet = false) {
      adf::pktcontrol x;
      api_impl::createPktControl(x.impl, x.in, x.out, return_packet);
      return x;
    }

    pktcontrol& operator=(const pktcontrol& from) { api_impl::assignmentPktControl(impl, in, out, from.impl, from.in, from.out); return *this; }
    std::shared_ptr<PktControlImpl> impl;
  };

  /* Bypass related functions and classes.  */
  class ADF_API_EXPORT bypass {
  public:
    bypass();
    adf::vector<adf::port<adf::input>> in;
    adf::vector<adf::port<adf::output>> out;
    adf::vector<adf::port<adf::inout>> inout;
    adf::port<adf::input> bp;
    static adf::bypass create(adf::kernel &k);

    bypass& operator=(const bypass& from);
    std::shared_ptr<BypassImpl> impl;
  };

  template<typename _XILINX_ADF_T>
    adf::port <_XILINX_ADF_T> & negate (adf::port<_XILINX_ADF_T> &x)
  {
    api_impl::negate(x.impl);
    return x;
  }

  /* adf::connect class and function prototypes.  */
  template <typename _XILINX_ADF_L = adf::blank, typename _XILINX_ADF_R = adf::blank> class connect {
  public:
    connect (adf::port<adf::output>& portL,
             adf::port<adf::input>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::input>& portL,
             adf::port<adf::input>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::output>& portL,
             adf::port<adf::output>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::inout>& portL,
             adf::port<adf::input>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::inout>& portL,
             adf::port<adf::output>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::input>& portL,
             adf::port<adf::inout>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::output>& portL,
             adf::port<adf::inout>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect (adf::port<adf::inout>& portL,
             adf::port<adf::inout>& portR) { api_impl::connectPorts(impl, portL.impl, portR.impl, api_impl::connectTemplateParam<_XILINX_ADF_L>(), api_impl::connectTemplateParam<_XILINX_ADF_R>()); }
    connect(adf::parameter& param, adf::kernel& k) { api_impl::connectParameterToKernel(impl, param.impl, k.impl); }

    std::shared_ptr<ConnectImpl> impl;
  };

  /// Shared buffer. AIE-ML only.
  template<typename _XILINX_ADF_T> class shared_buffer : public shared_buffer_base
  {
  public:
      adf::vector<adf::port<adf::input>> in;
      adf::vector<adf::port<adf::output>> out;

      shared_buffer() { api_impl::createSharedBuffer(impl); }

      /// @param dimensions Shared buffer dimensions in terms of template data type. dimension[0] is the fast-moving dimension and is contiguous in memory.
      /// @param numInputs Number of input ports for write access.
      /// @param numOutputs Number of output ports for read access.
      static adf::shared_buffer<_XILINX_ADF_T> create(const std::vector<uint32_t>& dimension, size_t numInputs, size_t numOutputs) {
          adf::shared_buffer<_XILINX_ADF_T> x;
          api_impl::createSharedBuffer(x.impl, x.in, x.out, api_impl::paramType<_XILINX_ADF_T>::elemType, api_impl::tyPortType<_XILINX_ADF_T>::paramType, dimension, numInputs, numOutputs);
          return x;
      }

      adf::shared_buffer<_XILINX_ADF_T>& operator=(const adf::shared_buffer<_XILINX_ADF_T>& from) { api_impl::assignmentSharedBuffer(impl, in, out, from.impl, from.in, from.out); return *this; }

      /// Low level API to enqueue task in AIE-ML MEM tile DMA task queue.
      /// Management of buffer descriptor resources, lock resources, etc. belong to caller.
      /// @param buffer_descriptors Buffer descriptors for a task.
      /// @param bd_ids Buffer descriptor IDs. bd_ids[0] is used as the start BD to enqueue the task.
      /// @param repeat_count Repeat count of a task.
      /// @param enable_task_complete_token Whether to issue task complete token.
      template<class _XILINX_ADF_Q, typename = std::enable_if_t<std::is_same<_XILINX_ADF_Q, input>::value || std::is_same<_XILINX_ADF_Q, output>::value>>
      return_code enqueue_task(port<_XILINX_ADF_Q>& port, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count = 1, bool enable_task_complete_token = false) { return (return_code)api_impl::sharedBufferEnqueueTask(impl, port.impl, buffer_descriptors, bd_ids, repeat_count, enable_task_complete_token); }

      /// Wait for all the enqueued tasks to finish.
      template<class _XILINX_ADF_Q, typename = std::enable_if_t<std::is_same<_XILINX_ADF_Q, input>::value || std::is_same<_XILINX_ADF_Q, output>::value>>
      return_code wait(port<_XILINX_ADF_Q>& port) { return (return_code) api_impl::sharedBufferWait(impl, port.impl); }
  };

  template<typename _XILINX_ADF_T> class external_buffer : public external_buffer_base
  {
  public:
      adf::vector<adf::port<adf::input>> in;
      adf::vector<adf::port<adf::output>> out;

      external_buffer() { api_impl::createExternalBuffer(impl); }

      /// @param dimensions External buffer dimensions in terms of template data type. dimension[0] is the fast-moving dimension and is contiguous in memory.
      /// @param numInputs Number of input ports for write access.
      /// @param numOutputs Number of output ports for read access.
      static adf::external_buffer<_XILINX_ADF_T> create(const std::vector<uint32_t>& dimension, size_t numInputs, size_t numOutputs) {
          adf::external_buffer<_XILINX_ADF_T> x;
          api_impl::createExternalBuffer(x.impl, x.in, x.out, api_impl::paramType<_XILINX_ADF_T>::elemType, api_impl::tyPortType<_XILINX_ADF_T>::paramType, dimension, numInputs, numOutputs);
          return x;
      }

      adf::external_buffer<_XILINX_ADF_T>& operator=(const adf::external_buffer<_XILINX_ADF_T>& from) { api_impl::assignmentExternalBuffer(impl, in, out, from.impl, from.in, from.out); return *this; }

      void setAddress(const void* ptr) { api_impl::setAddressExternalBuffer(impl, ptr); }

      return_code gm2aie_nb(adf::port<adf::output>& out) { return api_impl::gm2aie_nb(impl, out.impl); }

      return_code aie2gm_nb(adf::port<adf::input>& in) { return api_impl::aie2gm_nb(impl, in.impl); }

      return_code wait(adf::port<adf::input>& in) { return api_impl::wait(impl, in.impl); }

      return_code wait(adf::port<adf::output>& out) { return api_impl::wait(impl, out.impl); }
  };

  /// @param length Transaction length in 32bit word
  /// @param offset Address offset with respect to shared_buffer base address, in 32bit word
  /// @param stepsize Multi-dimensional DMA step sizes, in 32bit word
  /// @param wrap Multi-dimensional DMA wraps
  access_pattern buffer_descriptor(uint32_t length, uint32_t offset, const std::vector<uint32_t>& stepsize, const std::vector<uint32_t>& wrap);

  inline access_pattern tiling(const tiling_parameters& tilingParams) { return access_pattern(tilingParams); }

  /* Constraint related functions, classes and prototypes.  */
  template <typename _XILINX_ADF_T> struct ADF_API_EXPORT constraint {
      void operator=(const constraint&) = delete;
    constraint<_XILINX_ADF_T> & operator=(_XILINX_ADF_T t);
    std::shared_ptr<ConstraintImpl> impl;
  };

  /* For constraint objects accepting _XILINX_ADF_T and std::vector<_XILINX_ADF_T> assignments. */
  template <typename _XILINX_ADF_T> struct ADF_API_EXPORT constraints {
      void operator=(const constraints&) = delete;
      constraints<_XILINX_ADF_T> & operator=(_XILINX_ADF_T t);
      constraints<_XILINX_ADF_T> & operator=(std::vector<_XILINX_ADF_T> t);
      std::shared_ptr<ConstraintImpl> impl;
  };

  template <typename _XILINX_ADF_T, typename _XILINX_ADF_P, typename _XILINX_ADF_Q=int>
    constraint<_XILINX_ADF_Q> fifo_depth (connect<_XILINX_ADF_T, _XILINX_ADF_P> &c)
    { constraint<_XILINX_ADF_Q> constr; api_impl::createConstraintFifoDepth(constr.impl, c.impl); return constr; }

  template <typename _XILINX_ADF_T=adf::ratio, typename _XILINX_ADF_Q=float>
  ADF_API_EXPORT constraint<_XILINX_ADF_Q> runtime(adf::kernel& k);

  template <typename _XILINX_ADF_T=std::string>
  ADF_API_EXPORT constraint<_XILINX_ADF_T> source(adf::kernel& k);

  template <typename _XILINX_ADF_T=std::string>
  ADF_API_EXPORT constraint<_XILINX_ADF_T> shared_lib(adf::kernel& k);

  template <typename _XILINX_ADF_T=std::string>
  ADF_API_EXPORT constraint<_XILINX_ADF_T> systemc_lib(adf::kernel& k);

  template <typename _XILINX_ADF_T=std::vector<std::string>>
  ADF_API_EXPORT constraint<_XILINX_ADF_T> headers(adf::kernel& k);

  ADF_API_EXPORT constraint<double> pl_frequency(adf::kernel& k);

  template <typename _XILINX_ADF_T=std::string>
  ADF_API_EXPORT constraint<_XILINX_ADF_T> initialization_function(adf::kernel &k);

  template <class _XILINX_ADF_T,typename _XILINX_ADF_Q=float>
  ADF_API_EXPORT constraint<_XILINX_ADF_Q> utilization(adf::port<_XILINX_ADF_T>& p);

  /* DMA mode constraints */
  template <class _XILINX_ADF_T>
  ADF_API_EXPORT constraint<DMA_MODE> dma_mode(adf::port<_XILINX_ADF_T>& p);

  template <class _XILINX_ADF_T>
  ADF_API_EXPORT void single_buffer(adf::port<_XILINX_ADF_T>& p);

  template <typename _XILINX_ADF_T=api_impl::variant>
  ADF_API_EXPORT constraint<_XILINX_ADF_T> initial_value(adf::port<adf::input>& p);

  ADF_API_EXPORT constraint<int> stack_size(adf::kernel& k);

  ADF_API_EXPORT constraint<int> heap_size(adf::kernel& k);

  ADF_API_EXPORT constraints<access_pattern> write_access(adf::port<adf::input>& p);
  ADF_API_EXPORT constraints<access_pattern> read_access(adf::port<adf::output>& p);

  /// Set task complete token controller ID (if needed) in DMA channel
  ADF_API_EXPORT void enable_task_complete_token(adf::port<adf::input>& p);
  ADF_API_EXPORT void enable_task_complete_token(adf::port<adf::output>& p);

  ADF_API_EXPORT constraint<uint64_t> repetition_count(adf::kernel& k);
  ADF_API_EXPORT constraint<uint64_t> repetition_count(adf::shared_buffer_base& sb);

  ADF_API_EXPORT void enable_compression(adf::port<adf::input>& p);
  ADF_API_EXPORT void enable_compression(adf::port<adf::output>& p);

  ADF_API_EXPORT constraint<int> num_buffers(adf::shared_buffer_base& sb);

  ADF_API_EXPORT void disable_dma_autostart(adf::port<adf::input>& p);
  ADF_API_EXPORT void disable_dma_autostart(adf::port<adf::output>& p);

  ADF_API_EXPORT constraint<uint32_t> async_repetition(adf::port<adf::input>& p);
  ADF_API_EXPORT constraint<uint32_t> async_repetition(adf::port<adf::output>& p);

  ADF_API_EXPORT constraint<uint32_t> storage_size(adf::port<adf::input>& p);
  ADF_API_EXPORT constraint<uint32_t> storage_size(adf::port<adf::output>& p);

  // constraint to specify samples per iteration for stream/pktstream ports to support multirate connections
  ADF_API_EXPORT constraint<uint32_t> samples_per_iteration(adf::port<adf::input>& p);
  ADF_API_EXPORT constraint<uint32_t> samples_per_iteration(adf::port<adf::output>& p);

  ADF_API_EXPORT constraint<std::vector<uint32_t>> dimensions(adf::port<adf::input>& p);
  ADF_API_EXPORT constraint<std::vector<uint32_t>> dimensions(adf::port<adf::output>& p);

  /* Location related constraints, functions, classes and prototypes */
  struct ADF_API_EXPORT location_constraint
  {
    location_constraint &operator=(location_constraint t); // absolute and relative locations
    location_constraint &operator=(std::vector<location_constraint> t); // for buffer ping and pong locations or bounding boxes
    location_constraint &operator=(std::vector<std::vector<location_constraint>> t); // for fragmented buffer ping and pong locations
    location_constraint operator+(const location_constraint& t); // for relative node location constraints
    std::shared_ptr<LocationConstraintImpl> impl;
  };

  /* kernel absolute location constraint */
  template<typename _XILINX_ADF_T>
   ADF_API_EXPORT location_constraint location (adf::kernel &k);

  /* pktcontrol node location constraint */
  template<typename _XILINX_ADF_T=adf::interconnect>
   ADF_API_EXPORT location_constraint location (adf::pktcontrol &k);

  /* _XILINX_ADF_M=adf::buffer : buffer absolute and relative location constraint */
  /* _XILINX_ADF_M=adf::dma : dma relative location constraint */
  template <typename _XILINX_ADF_M=adf::buffer>
   ADF_API_EXPORT location_constraint location (input_port &p);

  template <typename _XILINX_ADF_M=adf::buffer>
   ADF_API_EXPORT location_constraint location (output_port &p);

  template <typename _XILINX_ADF_M = adf::buffer>
   ADF_API_EXPORT location_constraint location(inout_port &p);

  /// Absolute and relative location constraint for adf::parameter
  template<typename _XILINX_ADF_T>
   ADF_API_EXPORT location_constraint location (adf::parameter &p);

  /// graph location constraint
  template<typename _XILINX_ADF_T=adf::graph>
   ADF_API_EXPORT location_constraint location(adf::graph &g);

  /// FIFO location constraint
  template<typename _XILINX_ADF_T, typename _XILINX_ADF_L, typename _XILINX_ADF_R>
    location_constraint location(connect<_XILINX_ADF_L, _XILINX_ADF_R> &c)
  {
    location_constraint constraint;
    api_impl::createFIFOLocationConstraint(constraint.impl, c.impl);
    return constraint;
  }

  /// tile function to specify tile location for kernel with column and row
  ADF_API_EXPORT location_constraint tile (int column, int row);

  /// tile function to specify tile location with column and row relative to tile type
  ADF_API_EXPORT location_constraint tile(tile_type tType, int column, int row);

  /// address function to specify absolute buffer location address with column, row, and offset
  ADF_API_EXPORT location_constraint address (int column, int row, int offset);

  /// bank function to specify partial buffer location with column, row, and bank (no offset)
  location_constraint bank (int column, int row, int bankid);

  /// channel function to specify absolute stream switch channel constraint using column, row, stream switch channel number, and stream switch channel direction
  location_constraint channel(int column, int row, int channel_number, ss_channel_dir direction);

  /// channel function to specify relative stream switch channel constraint using tile offset respect to the bounding box edge, stream switch channel number, and stream switch channel direction
  location_constraint channel(int tile_offset, int channel_number, ss_channel_dir direction);

  /// region function to specify bounding box
  location_constraint bounding_box(int column_min, int row_min, int column_max, int row_max);

  /// offset function to specify buffer location offset with respect to a tile
  location_constraint offset(int offset_value);

  /// Kernel Function Address Location in Program Memory
  location_constraint program_memory(std::vector<std::string> constr_value);

  /// not_equal function to specify the two location_constraint objects should not be collocated
  void not_equal(location_constraint lhs, location_constraint rhs);

  /// mark location<graph> constraint a reference for stamp and repeat
  location_constraint stamp(location_constraint graph_location);

  /// function to specify DMA FIFO location, column and row coordinates are relative to the tile type
  location_constraint dma_fifo(tile_type tType, int column, int row, int address, int size);

  /// function to specify SS FIFO location, column and row coordinates are relative to the tile type
  location_constraint ss_fifo(tile_type tType, int column, int row, int fifo_id);

  /// function to select FIFO placement resource type as DMA FIFO without completely specifying location
  location_constraint dma_fifo();

  /// function to select FIFO placement resource type as Stream Switch FIFO without completely specifying location
  location_constraint ss_fifo();

  /// function to specify area group constraint
  /// @param groups: Specify the collection of group. Each group can be specified using:
  /// - tile-type: Specify the tile-type for the group. Supported tile-types are aie_tile, shim_tile or memory_tile.
  /// - column_min: Column index for lower left corner.
  /// - row_min: Row index for lower left corner.
  /// - column_max: Column index for upper right corner.
  /// - row_max: Row index for upper right corner.
  /// @param contain_routing: Routing between the nodes inside the area group constraint needs to be within the area
  /// @param exclusive_routing: Routing for nodes outside the area group constraint cannot be routed into the area
  /// @param exclusive_placement: Nodes outside the area group constraint cannot be placed into the area
  location_constraint area_group(std::vector<group> groups, bool contain_routing = false, bool exclusive_routing = false, bool exclusive_placement = false);

  /// function to specify SHIM column location
  location_constraint shim(int column);

  /// function to specify SHIM column and channel location
  location_constraint shim(int column, int channel);

  /// shared buffer location constraint. AIE-ML only.
  template<typename _XILINX_ADF_T = adf::buffer>
    location_constraint location(adf::shared_buffer_base& sb);

  /// function to specify DMA channel location
  ADF_API_EXPORT location_constraint dma_channel(tile_type tType, int column, int row, int channel);

  /// function to specify column and row offset for relative location constraints
  location_constraint relative_offset(const relative_coordinate& offset);

  /* IoAttributes.  */
  class ADF_API_EXPORT IoAttr {
  public:
    virtual io_attr_type type() = 0;

    std::shared_ptr<IoAttrImpl> impl;
  };

  class ADF_API_EXPORT FileIO: public IoAttr {
  public:
    FileIO(std::string data_file);
    FileIO(std::string logical_name, std::string data_file);
    io_attr_type type() override { return io_attr_fileio; }
  };

  class ADF_API_EXPORT PLIO: public IoAttr {
  public:
    PLIO (std::string logical_name, enum plio_type plio_width);
    PLIO (std::string logical_name, enum plio_type plio_width, std::string data_file);
    PLIO (std::string logical_name);
    PLIO (std::string logical_name, std::string data_file);

    // This constructor is experimental and subject to change
    PLIO(std::string logical_name, enum plio_type plio_width, std::string data_file, double frequency, bool binary = false, bool hex = false);

    io_attr_type type() override { return io_attr_plio; }

  protected:
    PLIO () { };

  };

  class ADF_API_EXPORT GMIO: public IoAttr {
  public:
    /// GMIO constructor.
    /// @param name Unique GMIO data name.
    /// @param burst_length Burst length in 64, 128, or 256 bytes.
    /// @param bandwidth Expected throughput in MB/s.
    GMIO (const std::string& logical_name, size_t burst_length, size_t bandwidth);
    //virtual ~GMIO();

    io_attr_type type() override { return io_attr_gmio; }

    /// Initiate GM to AIE transfer starting from virtual memory address with transaction_size (in bytes).
    /// Non-blocking. Can only be invoked for platform source GMIO or input_gmio.
    /// The transaction memory space needs to be within the total memory space allocated by GMIO::malloc.
    /// @param address Pointer to the start address of the virtual memory space for the transaction.
    /// @param transaction_size Transaction size in bytes.
    return_code gm2aie_nb(const void* address, size_t transaction_size);

    /// Initiate AIE to GM transfer starting from virtual memory address with transaction_size (in bytes).
    /// Non-blocking. Can only be invoked for platform sink GMIO or output_gmio.
    /// The transaction memory space needs to be within the total memory space allocated by GMIO::malloc.
    /// @param address Pointer to the start address of the virtual memory space for the transaction.
    /// @param transaction_size Transaction size in bytes.
    return_code aie2gm_nb(void* address, size_t transaction_size);

    /// Initiate GM to AIE transfer starting from virtual memory address with transaction_size (in bytes).
    /// Blocking until the transaction is completed. Can only be invoked for platform source GMIO or input_gmio.
    /// The transaction memory space needs to be within the total memory space allocated by GMIO::malloc.
    /// @param address Pointer to the start address of the virtual memory space for the transaction.
    /// @param transaction_size Transaction size in bytes.
    return_code gm2aie(const void* address, size_t transaction_size);

    /// Initiate AIE to GM transfer starting from virtual memory address with transaction_size (in bytes).
    /// Blocking until the transaction is completed. Can only be invoked for platform sink GMIO or output_gmio.
    /// The transaction memory space needs to be within the total memory space allocated by GMIO::malloc.
    /// @param address Pointer to the start address of the virtual memory space for the transaction.
    /// @param transaction_size Transaction size in bytes.
    return_code aie2gm(void* address, size_t transaction_size);

    /// Initiate GM to AIE transfer starting from virtual memory address with low level dma_buffer_descriptor.
    /// Non-blocking.
    /// The transaction memory space needs to be within the total memory space allocated by GMIO::malloc.
    /// Only applicable to AIE-ML. Can only be invoked from input_gmio.
    /// Management of buffer descriptor resources, lock resources, etc. belong to caller.
    /// @param address Pointer to the start address of the virtual memory space for the transaction.
    /// @param buffer_descriptors Buffer descriptors for a task. buffer_descriptors.address represents 32-bit word offset to address
    /// @param bd_ids Buffer descriptor IDs. bd_ids[0] is used as the start BD to enqueue the task.
    /// @param repeat_count Repeat count of a task.
    /// @param enable_task_complete_token Whether to issue task complete token.
    return_code gm2aie_nb(const void* address, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count = 1, bool enable_task_complete_token = false);

    /// Initiate AIE to GM transfer starting from virtual memory address with low level dma_buffer_descriptor.
    /// Non-blocking.
    /// The transaction memory space needs to be within the total memory space allocated by GMIO::malloc.
    /// Only applicable to AIE-ML. Can only be invoked from output_gmio.
    /// Management of buffer descriptor resources, lock resources, etc. belong to caller.
    /// @param address Pointer to the start address of the virtual memory space for the transaction.
    /// @param buffer_descriptors Buffer descriptors for a task. buffer_descriptors.address represents 32-bit word offset to address
    /// @param bd_ids Buffer descriptor IDs. bd_ids[0] is used as the start BD to enqueue the task.
    /// @param repeat_count Repeat count of a task.
    /// @param enable_task_complete_token Whether to issue task complete token.
    return_code aie2gm_nb(void* address, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count = 1, bool enable_task_complete_token = false);

    /// Wait for all the previously initiated GMIO transactions to complete.
    return_code wait();

    /// Allocate contiguous physical memory space and return the corresponding virtual address.
    /// @param size Memory size in bytes to be allocated.
    /// @return Virtual memory pointer to the allocated memory space. nullptr if failed.
    static void* malloc(size_t size);

    /// Free memory space allocated by GMIO::malloc.
    /// @param address Virtual memory pointer to the memory space allocated by GMIO::malloc.
    static void free(void* address);

  protected:
    GMIO () { };

  };

  class ADF_API_EXPORT input_plio : public PLIO {
    public:
      input_plio();
      adf::vector<adf::port<adf::output>> out;
      static adf::input_plio create(std::string logical_name, plio_type plio_width = adf::plio_32_bits, std::string data_file = std::string(), double frequency = 0.0, bool hex = false);
      static adf::input_plio create(plio_type plio_width = adf::plio_32_bits, std::string data_file = std::string(), double frequency = 0.0, bool hex = false);
      input_plio& operator=(const input_plio& from);
  };

  class ADF_API_EXPORT output_plio : public PLIO {
    public:
      output_plio();
      adf::vector<adf::port<adf::input>> in;
      static adf::output_plio create(std::string logical_name, plio_type plio_width = adf::plio_32_bits, std::string data_file = std::string(), double frequency = 0.0, bool hex = false);
      static adf::output_plio create(plio_type plio_width = adf::plio_32_bits, std::string data_file = std::string(), double frequency = 0.0, bool hex = false);
      output_plio& operator=(const output_plio& from);
  };

  class ADF_API_EXPORT input_gmio : public GMIO {
    public:
      input_gmio();
      adf::vector<adf::port<adf::output>> out;
      static adf::input_gmio create(std::string logical_name, size_t burst_length, size_t bandwidth);
      static adf::input_gmio create(size_t burst_length, size_t bandwidth);
      input_gmio& operator=(const input_gmio& from);

    private:
      using GMIO::aie2gm_nb;
      using GMIO::aie2gm;
  };

  class ADF_API_EXPORT output_gmio : public GMIO {
    public:
      output_gmio();
      adf::vector<adf::port<adf::input>> in;
      static adf::output_gmio create(std::string logical_name, size_t burst_length, size_t bandwidth);
      static adf::output_gmio create(size_t burst_length, size_t bandwidth);
      output_gmio& operator=(const output_gmio& from);

    private:
      using GMIO::gm2aie_nb;
      using GMIO::gm2aie;
  };

  /// SHIM location constraints for input_plio/output_plio and input_gmio/output_gmio
  template<typename _XILINX_ADF_T1, typename _XILINX_ADF_T2,
  typename = std::enable_if_t<(
      ((std::is_same<_XILINX_ADF_T1, adf::PLIO>::value) && ((std::is_same<_XILINX_ADF_T2, adf::input_plio>::value) || (std::is_same<_XILINX_ADF_T2, adf::output_plio>::value))) ||
      ((std::is_same<_XILINX_ADF_T1, adf::GMIO>::value) && ((std::is_same<_XILINX_ADF_T2, adf::input_gmio>::value) || (std::is_same<_XILINX_ADF_T2, adf::output_gmio>::value)))), _XILINX_ADF_T2>>
  location_constraint location(_XILINX_ADF_T2 &io)
  {
      location_constraint constraint;
      api_impl::createPLIOOrGMIOLocationConstraint(constraint.impl, io.impl);
      return constraint;
  }

  template<typename _XILINX_ADF_T>
    adf::port<_XILINX_ADF_T>
    &async(adf::port<_XILINX_ADF_T>  &prt) { api_impl::async(prt.impl); return prt; }

  template<typename _XILINX_ADF_T>
    adf::port<_XILINX_ADF_T>
    &sync(adf::port<_XILINX_ADF_T>  &prt) { api_impl::sync(prt.impl); return prt; }

  /* Platform related functions, classes and prototypes. */
  namespace simulation {
    template <size_t num_inputs, size_t num_outputs> class platform {
    public:
      adf::port<direction::out> src[num_inputs];
      adf::port<direction::in> sink[num_outputs];

      template<typename... Types> platform(IoAttr* io, Types... ios)
      {
          api_impl::createPlatform(impl, src, num_inputs, sink, num_outputs, io, ios...);
      }

      template<typename... Types> platform(const char* file, Types... files)
      {
          api_impl::createPlatform(impl, src, num_inputs, sink, num_outputs, file, files...);
      }

      std::shared_ptr<PlatformImpl> impl;
    };
  }

  class event
  {
  private:
    enum options_enum_init
    {
      io_profiling_option_enum_init = 0x20,
      graph_tracing_option_enum_init = 0x40,
      graph_tracing_MemTile_option_enum_init = 0x70
    };

  public:
    /// Event handle
    typedef int handle;
    /// Invalid event handle for checking validity of the return handle from start_profiling
    static const handle invalid_handle = -1;

    /// Enumeration for profiling options available for platform IO objects
    enum io_profiling_option
    {
      io_total_stream_running_to_idle_cycles = io_profiling_option_enum_init, /// Total accumulated cycles in between stream running to stream idle events
      io_stream_start_to_bytes_transferred_cycles,                            /// Cycles in between the first event of stream running to the event that the specified number of bytes are transferred (assuming the stream stops right after the specified number of bytes are transferred)
      io_stream_start_difference_cycles,                                      /// Cycles elapsed between the first stream running events of the two platform IO objects
      io_stream_running_event_count                                           /// Number of stream running events
    };

    enum graph_tracing_option
    {
      function_view = graph_tracing_option_enum_init, /// function view
      function_view_wo_stall,                         /// function view without stall
      function_view_group_stall,                      /// function view with group stall
      function_view_group_stall_wo_mem_stall,         /// function view with group stall but without memory stall
      unified_view                                    /// unified (function/system/data) view
    };

    enum graph_tracing_MemTile_option
    {
#ifdef ENABLE_MEMTILE_L1_L2
      L1 = graph_tracing_MemTile_option_enum_init,    /// L1 view
      L2 ,                                             /// L2 view
      input_channels,
      output_channels
#else
      input_channels = graph_tracing_MemTile_option_enum_init,
      output_channels
#endif
    };

  public:
    /// Start profiling and acquire resources needed for profiling. Should be called after graph::init.
    /// @param io Plarform PLIO or GMIO object
    /// @param option io_profiling_option enum
    /// @param value Optional value for the specified option
    /// @return Return event::handle to be used by read_profiling and stop_profiling. Return event::invalid_handle for error conditions or unsupported use cases.
    static handle start_profiling(IoAttr& io, io_profiling_option option, uint32 value = 0);

    /// Start profiling. Should be called after graph::init.
    /// @param io1 Plarform PLIO or GMIO object
    /// @param io2 Plarform PLIO or GMIO object
    /// @param option io_profiling_option enum. Currently supports only io_stream_start_difference_cycles.
    /// @param value Optional value for the specified option
    /// @return Return event::handle to be used by read_profiling and stop_profiling. Return event::invalid_handle for error conditions or unsupported use cases.
    static handle start_profiling(IoAttr& io1, IoAttr& io2, io_profiling_option option, uint32 value = 0);

    /// Read profiling.
    /// @param h event::handle returned from start_profiling
    /// @return Profiling value
    static long long read_profiling(handle h);

    /// Stop profiling and release resources needed for profiling.
    /// @param h event::handle returned from start_profiling
    static void stop_profiling(handle h);
  };

}

#include "adf_internal.h"

#endif
