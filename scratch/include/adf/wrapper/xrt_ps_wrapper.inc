/*
 * Copyright 2022 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dlfcn.h>
#include <atomic>
#include <thread>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstdio>
#include <cinttypes>
#include <iostream>

static std::atomic<bool> xrt_pending_req  (false);
static std::atomic<bool> xrt_ps_main_started (false);
const uint64_t MEMSIZE = 0x0000000400000000;

typedef void*(create_xcl_client_graph_t)();      
typedef void (destroy_xcl_client_graph_t)(void*);
typedef void (*xrt_graph_callback_t)(int api, char*, void** argv);

void* xcl_client_graph;
destroy_xcl_client_graph_t* xcl_graph_destroy;

void register_graph_cb(xrt_graph_callback_t func);
xsc::xsc_async_event xrt_graph_event;

//! This enum must be kept in sync with xcl_aiesim_graph_api.cxx
//! .../src/products/sdx/ocl/src/emulation/cpu_em/xcl_aiesim_graph_api/src/xcl_aiesim_graph_api.cxx
enum class AIESIM_GRAPH_API {
  GRAPH_INIT = 0,
  GRAPH_RUN  = 1,
  GRAPH_WAIT = 2,
  GRAPH_END  = 3,
  GRAPH_UPDATE_RTP   = 4,
  GRAPH_READ_RTP     = 5,
  GRAPH_SYNCBO_AIENB = 6,
  GRAPH_GMIO_WAIT    = 7,
  GRAPH_TIMED_WAIT   = 8,
  GRAPH_TIMED_END    = 9,
  GRAPH_RESUME       = 10
};

struct xcl_graph_args_t {
  AIESIM_GRAPH_API graph_api;
  char* graphName;
  void** argv;
} xcl_graph_args;

static bool is_hybrid_emu()
{
  static auto hemu = std::getenv("XILINX_VITIS_EMU_HYBRID"); 
  if (hemu)   {
      return true;
  }
  return false;
} 

static void xrt_graph_callback(int graph_api, char* graphName, void** argv)
{
  using namespace std::literals::chrono_literals;

  while(!xrt_ps_main_started) {
    std::this_thread::sleep_for(10ms);
  }

  //! Save xcl graph call args...
  xcl_graph_args.graph_api = static_cast<AIESIM_GRAPH_API>(graph_api);
  xcl_graph_args.graphName = graphName;
  xcl_graph_args.argv = argv;

  xrt_pending_req = true;
  xrt_graph_event.notify();

  while(xrt_pending_req) {
    std::this_thread::sleep_for(1ms);
  }
}

static void load_xcl_client_graph()
{
  if(!is_hybrid_emu()) return;

  std::string lib_path = std::string(getenv("XILINX_VITIS")) +
  "/lib/lnx64.o/libxv_emu_xcl_aiesim_graph_api.so";

  void* handle = dlopen(lib_path.c_str(), RTLD_LAZY | RTLD_GLOBAL);

  create_xcl_client_graph_t* xcl_graph = (create_xcl_client_graph_t*) dlsym(handle, "create_aiesim_graph_xcl_client");
  xcl_graph_destroy = (destroy_xcl_client_graph_t*) dlsym(handle, "destroy_aiesim_graph_xcl_client");

  const char* dlsym_error = dlerror();
  if (dlsym_error) {
    std::cout<< "dlsym error: " << dlsym_error<<std::endl;
  }

  register_graph_cb(xrt_graph_callback);

  std::cout << "Creating XCL AIESIM Graph Client..." << std::endl;
  xcl_client_graph = xcl_graph();
}

static std::pair<int, char*> get_ddr_mem_ptr()
{
  std::string shared_mem_file = std::string(std::getenv("VITIS_SW_EMU_SHARED_MEM_FILE"));
  int fd = open(shared_mem_file.c_str(), (O_CREAT | O_RDWR), 0666);
  if (fd == -1) {
    printf("Error opening exported BO file.\n");
    return std::make_pair(-1, nullptr);
  };

  char* data = (char*) mmap(0, MEMSIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, fd, 0);
  return std::make_pair(fd, data);
}

struct xrt_gmio
{
  xrt_gmio(std::map<std::string, adf::GMIO*>& gmioMap) {
    for(auto& gmio : gmioMap) {
      m_gmio_buf[gmio.first] = std::make_tuple(adf::GMIO::malloc(BUFF_SIZE), nullptr, 0);
    }
  }

  void* get_host_ptr(const std::string& gmio_name) {
    return std::get<0>(m_gmio_buf.at(gmio_name));
  }

  char* get_ddr_ptr(const std::string& gmio_name) {
    return std::get<1>(m_gmio_buf.at(gmio_name));
  }

  uint64_t get_buf_length(const std::string& gmio_name) {
    return std::get<2>(m_gmio_buf.at(gmio_name));
  }

  void set_ddr_ptr(const std::string& gmio_name, char* ddr_ptr) {
    std::get<1>(m_gmio_buf.at(gmio_name)) = ddr_ptr;
  }

  void add_buf_length(const std::string& gmio_name, uint64_t len) {
    std::get<2>(m_gmio_buf.at(gmio_name)) += len;
  }

  ~xrt_gmio() {
    for(auto& buf_ptr : m_gmio_buf) {
      adf::GMIO::free(std::get<0>(buf_ptr.second));
    }
  }

  private:
    std::map<std::string, std::tuple<void*, char*, uint64_t>> m_gmio_buf;
    uint32_t BUFF_SIZE {1024}; 
};

static int xrt_ps_main()
{
  if(!is_hybrid_emu()) return 0;
  xrt_ps_main_started = true;

  xrt_gmio gmio_buf(gmioMap);
  
  while(true) 
  {
    wait(xrt_graph_event);

    switch(xcl_graph_args.graph_api)
    {
      case AIESIM_GRAPH_API::GRAPH_INIT:
      {
        std::cout << "xrt main: graph.init()" <<std::endl;
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        std::cout << "xrt main: graph.init(graph_name = " << graph_name << ")" <<std::endl;
        _gr_inst[graph_name]->init();
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_RUN:
      {
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        uint32_t num_iterations = *(static_cast<uint32_t*>(xcl_graph_args.argv[1]));
        std::cout << "xrt main: graph.run(graph_name = " << graph_name << ")" <<std::endl;
        std::cout << "xrt main: graph.run(num_iterations = "<<num_iterations<<")" <<std::endl;
        _gr_inst[graph_name]->run(num_iterations);
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_WAIT:
      {
        std::cout << "xrt main: graph.wait() started." << std::endl;
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        std::cout << "xrt main: graph.wait(graph_name = " << graph_name << ")" <<std::endl;
        _gr_inst[graph_name]->wait();
        std::cout << "xrt main: graph.wait() completed." << std::endl;
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_END:
      {
        using namespace std::literals::chrono_literals;
        std::cout << "xrt main: graph.end() started" <<std::endl;
        char* graph_name = xcl_graph_args.graphName;
        std::cout << "xrt main: graph.end(graph_name = " << graph_name << ")" <<std::endl;
        std::this_thread::sleep_for(10ms);
        //char* graph_name_argv = static_cast<char*>(xcl_graph_args.argv[0]);
        //std::cout << "xrt main: graph.end(graph_name_argv = " << graph_name_argv << ")" <<std::endl;
        _gr_inst[graph_name]->end();
        std::cout << "xrt main: graph.end() completed." <<std::endl;
        static int count = _gr_inst.size();
        if (--count <= 0) {   // If all graphs end then exit myself by going to XRT_MAIN_END
	        goto XRT_MAIN_END;  //! Break out of while loop to end the graph execution
        }
        else                  // A couple more graph's present, let's clean them as well.
          break;
      }
      
      case AIESIM_GRAPH_API::GRAPH_UPDATE_RTP:
      {
        char *graph_name = static_cast<char *>(xcl_graph_args.argv[0]);
        char *port_name = static_cast<char *>(xcl_graph_args.argv[1]);
        void *buff = xcl_graph_args.argv[2];
        size_t size = (*static_cast<size_t *>(xcl_graph_args.argv[3]));
        std::cout << "graph_name: " << graph_name << " port_name: " << port_name << " size: " << size << std::endl;

        if (inputPortMap.size())
        {
          std::string dataType = inputPortMap[port_name].second;
          if (dataType == "int8")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (int8 *)buff, size / 4);
          else if (dataType == "int16")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (int16 *)buff, size / 4);
          else if (dataType == "int32")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (int32 *)buff, size / 4);
          else if (dataType == "int64")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (int64 *)buff, size / 4);
          else if (dataType == "uint8")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (uint8 *)buff, size / 4);
          else if (dataType == "uint16")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (uint16 *)buff, size / 4);
          else if (dataType == "uint32")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (uint32 *)buff, size / 4);
          else if (dataType == "uint64")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (uint64 *)buff, size / 4);
          else if (dataType == "cint16")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (cint16 *)buff, size / 4);
          else if (dataType == "cint32")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (cint32 *)buff, size / 4);
          else if (dataType == "float")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (float *)buff, size / 4);
          else if (dataType == "cfloat")
            _gr_inst[graph_name]->update(*inputPortMap[port_name].first, (cfloat *)buff, size / 4);
        }
        std::cout << "xrt main: GRAPH_UPDATE_RTP Supported" << std::endl;
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_READ_RTP:
      {
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        char* port_name = static_cast<char*>(xcl_graph_args.argv[1]);
        char* buff = static_cast<char*>(xcl_graph_args.argv[2]);
        size_t size =  (*static_cast<size_t*>(xcl_graph_args.argv[3]));
        std::cout << "graph_name: " << graph_name << " port_name: " << port_name << " size: " << size << std::endl;

        if (inoutPortMap.size()) 
        {
          std::string dataType = inoutPortMap[port_name].second;
          if (dataType == "int8")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (int8 *)buff, size / 4);
          else if (dataType == "int16")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (int16 *)buff, size / 4);
          else if (dataType == "int32")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (int32 *)buff, size / 4);
          else if (dataType == "int64")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (int64 *)buff, size / 4);
          else if (dataType == "uint8")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (uint8 *)buff, size / 4);
          else if (dataType == "uint16")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (uint16 *)buff, size / 4);
          else if (dataType == "uint32")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (uint32 *)buff, size / 4);
          else if (dataType == "uint64")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (uint64 *)buff, size / 4);
          else if (dataType == "cint16")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (cint16 *)buff, size / 4);
          else if (dataType == "cint32")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (cint32 *)buff, size / 4);
          else if (dataType == "float")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (float *)buff, size / 4);
          else if (dataType == "cfloat")
            _gr_inst[graph_name]->read(*inoutPortMap[port_name].first, (cfloat *)buff, size / 4);
        }
        std::cout << "xrt main: GRAPH_READ_RTP Supported" << std::endl;        
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_SYNCBO_AIENB:
      {
        char* gmioname = static_cast<char*>(xcl_graph_args.argv[0]);
        uint64_t buff_handle =  (*static_cast<uint64_t*>(xcl_graph_args.argv[1]));
        uint32_t direction =  (*static_cast<uint32_t*>(xcl_graph_args.argv[2]));
        uint64_t size =  (*static_cast<uint64_t*>(xcl_graph_args.argv[3]));
        uint64_t offset =  (*static_cast<uint64_t*>(xcl_graph_args.argv[4]));

        std::cout << "syncbo_aienb gmioname: " << gmioname << " buff_handle: " << buff_handle << " direction: " << direction << " size: " << std::hex << size << " offset: " << offset << std::endl;

        //! get the device ddr mem start ptr and fd
        auto [fd, ddr_start_ptr] = get_ddr_mem_ptr();
        char* data = ddr_start_ptr + buff_handle;

        if (direction == 2) {
          std::cout << "xrt main: " << gmioname << "->gm2aie_nb(" << std::hex << gmio_buf.get_host_ptr(gmioname) <<", 0x"<<size<<") ..."<< std::endl;
          memcpy((char*)gmio_buf.get_host_ptr(gmioname) + offset, data + offset, size);
          gmioMap[gmioname]->gm2aie_nb((char*)gmio_buf.get_host_ptr(gmioname) + offset, size);
        } else if (direction == 3) {
          std::cout << "xrt main: " << gmioname << "->aie2gm_nb(" << std::hex << gmio_buf.get_host_ptr(gmioname) <<", 0x"<<size<<") ..."<< std::endl;

          gmio_buf.set_ddr_ptr(gmioname, data);
          gmio_buf.add_buf_length(gmioname, size);

          gmioMap[gmioname]->aie2gm_nb((char*)gmio_buf.get_host_ptr(gmioname) + offset, size);
        } else {
          std::cout << "xrt main: GRAPH_SYNCBO_AIENB INVALID DIRECTION" << std::endl;
        }
        close(fd);
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_GMIO_WAIT:
      {
        //! Get the gmio pointer using "gmioname" and call gmio_ptr->wait()
        char* gmioname = static_cast<char*>(xcl_graph_args.argv[0]); 
        std::cout << "xrt main: " << gmioname <<"->wait() ..." << std::endl;

        gmioMap[gmioname]->wait();
        memcpy(gmio_buf.get_ddr_ptr(gmioname), (char*)gmio_buf.get_host_ptr(gmioname), gmio_buf.get_buf_length(gmioname));

        std::cout << "xrt main: " << gmioname <<"->wait() Completed..." << std::endl;
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_TIMED_WAIT:
      {
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        uint64_t cycle_timeout = *(static_cast<uint64_t*>(xcl_graph_args.argv[1]));
        std::cout << "xrt main: graph.wait(cycle_timeout = "<<cycle_timeout<<")" <<std::endl;
        _gr_inst[graph_name]->wait(cycle_timeout);
      }
      break;

      case AIESIM_GRAPH_API::GRAPH_TIMED_END:
      {
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        uint64_t cycle_timeout = *(static_cast<uint64_t*>(xcl_graph_args.argv[1]));
        std::cout << "xrt main: graph.end(cycle_timeout = "<<cycle_timeout<<")" <<std::endl;
        _gr_inst[graph_name]->end(cycle_timeout);
      }
      goto XRT_MAIN_END; //! Break out of while loop to end the graph execution

      case AIESIM_GRAPH_API::GRAPH_RESUME:
      {
        char* graph_name = static_cast<char*>(xcl_graph_args.argv[0]);
        std::cout << "xrt main: graph.resume()" <<std::endl;
        _gr_inst[graph_name]->resume();
      }
      break;

      default: 
      std::cout << "xrt main: Unknown AIESIM_GRAPH_API " <<std::endl;
      break;
    }
    xrt_pending_req = false;
  }

  XRT_MAIN_END:
  xrt_pending_req = false;
  std::cout << "xrt main: graph completed" <<std::endl;
  return 0;
  //xcl_graph_destroy(xcl_client_graph);
}
