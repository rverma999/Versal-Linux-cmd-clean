// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_X86SIM_HLS_STREAM_H_
#define _SRC_X86SIM_INCLUDE_X86SIM_HLS_STREAM_H_

// use preprocessor X_HLS_STREAM_SIM_H to skip any later #include "hls_stream.h"
// in HLS source files
#define X_HLS_STREAM_SIM_H 
#include <systemc.h>
#include <stdint.h>
//for ap_axis(u) and ap_(u)int
#include "ap_int.h"
#include "ap_axi_sdata.h" 
#include <iostream>
#include <queue>
#include <complex>
#include "symbolVisibility.h"

// Fwd declarations
namespace x86sim {
    struct stream_internal;
}
extern int read32bits(x86sim::stream_internal* strm);
extern void  write32bits(x86sim::stream_internal* strm, int, bool /* tlast */);

namespace adf_hls_wrapper
{
    template<typename T> class X86SIM_EXPORT base_stream
    {
    public:
        base_stream() {}
        virtual ~base_stream() {}

        virtual std::string class_name() const = 0; //pure virtual function

        virtual bool empty()
        {
            std::cerr << "hls::stream::empty is not supported in "
		      << class_name() << " class." << std::endl;
            return true;
        }

        virtual bool full() const
        {
            std::cerr << "hls::stream::full is not supported in "
		      << class_name() << " class." << std::endl;
            return false;
        }

        /// Blocking read
        virtual T read()
        {
            std::cerr << "hls::stream::read is not supported in "
		      << class_name() << " class." << std::endl;
            return T();
        }

        /// Blocking write
        virtual void write(const T& tail)
        {
            std::cerr << "hls::stream::write is not supported in "
		      << class_name() << " class." << std::endl;
        }

        /// Blocking read
        virtual void read(T& head)
        {
            head = read();
        }

        virtual void operator >> (T& rdata)
        {
            read(rdata);
        }

        virtual void operator << (const T& wdata)
        {
            write(wdata);
        }
        
        /// Nonblocking read
        virtual bool read_nb(T& head)
        {
            std::cerr << "hls::stream::read_nb is not supported in "
		      << class_name() << " class." << std::endl;
            return false;
        }

        /// Nonblocking write
        virtual bool write_nb(const T& tail)
        {
            std::cerr << "hls::stream::write_nb is not supported in "
		      << class_name() << " class." << std::endl;
            return false;
        }

        /// Number of available elements
        virtual size_t size()
        {
            std::cerr << "hls::stream::size is not supported in "
		      << class_name() << " class." << std::endl;
            return 0;
        }
    };


    template<typename T> class X86SIM_EXPORT fifo_stream : public base_stream<T>
    {
    private:
        std::queue<T> _fifo;

    public:
        fifo_stream() {}

        std::string class_name() const override
        {
            return "adf_hls_wrapper::fifo_stream";
        }

        inline bool empty() override
        {
            return _fifo.empty();
        }

        inline bool full() const override
        {
            return false;
        }

        inline T read() override
        {
            T val = _fifo.front();
            _fifo.pop();
            return val;
        }

        inline void write(const T& tail) override
        {
            _fifo.push(tail);
        }

        inline bool read_nb(T& head) override
        {
            if (_fifo.empty())
                return false;
            else
            {
                head = read();
                return true;
            }
        }

        inline bool write_nb(const T& tail) override
        {
            _fifo.push(tail);
            return true;
        }

        inline size_t size() override
        {
            return _fifo.size();
        }
    };


    template<typename T> class X86SIM_EXPORT port_stream : public base_stream<T>
    {
    private:
        ::x86sim::stream_internal* m_stream;

    public:
        port_stream(::x86sim::stream_internal *port)
        {
            m_stream = port;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::port_stream";
        }

        T read() override;
        void write(T const&) override;
    };

    template<> inline int port_stream<int>::read()
    {
       return ::read32bits(m_stream);
    }
    template<> inline unsigned port_stream<unsigned>::read()
    {
       return ::read32bits(m_stream);
    }
    template<> inline ap_int<32> port_stream<ap_int<32>>::read()
    {
       return ::read32bits(m_stream);
    }
    template<> inline long long port_stream<long long>::read()
    {
       long long result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline unsigned long long port_stream<unsigned long long>::read()
    {
       unsigned long long result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline ap_int<64> port_stream<ap_int<64>>::read()
    {
       ap_int<64> result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline ap_axis<32, 0, 0, 0>
    port_stream<ap_axis<32, 0, 0, 0>>::read()
    {
       int value = ::read32bits(m_stream);
       ap_axis<32, 0, 0, 0> result;
       *((int*)&result.data) = value;
       return result;
    }
    template<> inline ap_axis<64, 0, 0, 0>
    port_stream<ap_axis<64, 0, 0, 0>>::read()
    {
       ap_axis<64, 0, 0, 0> result;
       int *words = (int*) &result.data;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline ap_axis<128, 0, 0, 0>
    port_stream<ap_axis<128, 0, 0, 0>>::read()
    {
       ap_axis<128, 0, 0, 0> result;
       int *words = (int*) &result.data;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       words[2] = ::read32bits(m_stream);
       words[3] = ::read32bits(m_stream);
       return result;
    }

    template<> inline ap_uint<32> port_stream<ap_uint<32>>::read()
    {
       return ::read32bits(m_stream);
    }
    template<> inline ap_uint<64> port_stream<ap_uint<64>>::read()
    {
       ap_uint<64> result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline ap_axiu<32, 0, 0, 0>
    port_stream<ap_axiu<32, 0, 0, 0>>::read()
    {
       int value = ::read32bits(m_stream);
       ap_axiu<32, 0, 0, 0> result;
       *((int*)&result.data) = value;
       return result;
    }
    template<> inline ap_axiu<64, 0, 0, 0>
    port_stream<ap_axiu<64, 0, 0, 0>>::read()
    {
       ap_axiu<64, 0, 0, 0> result;
       int *words = (int*) &result.data;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline ap_axiu<128, 0, 0, 0>
    port_stream<ap_axiu<128, 0, 0, 0>>::read()
    {
       ap_axiu<128, 0, 0, 0> result;
       int *words = (int*) &result.data;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       words[2] = ::read32bits(m_stream);
       words[3] = ::read32bits(m_stream);
       return result;
    }
    template<> inline float port_stream<float>::read()
    {
       float result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       return result;
    }
    template<> inline std::complex<short> port_stream<std::complex<short>>::read()
    {
       std::complex<short> result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       return result;
    }
    template<> inline std::complex<int> port_stream<std::complex<int>>::read()
    {
       std::complex<int> result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }
    template<> inline std::complex<float> port_stream<std::complex<float>>::read()
    {
       std::complex<float> result;
       int *words = (int*) &result;
       words[0] = ::read32bits(m_stream);
       words[1] = ::read32bits(m_stream);
       return result;
    }

    template<> inline void port_stream<int>::write(int const &value)
    {
       return ::write32bits(m_stream, value, false);
    }
    template<> inline void port_stream<unsigned>::write(unsigned const &value)
    {
       return ::write32bits(m_stream, value, false);
    }
    template<> inline void
    port_stream<ap_int<32>>::write(const ap_int<32>& val)
    {
       return ::write32bits(m_stream,
			  *((int*) &val), false);
    }
    template<> inline void
    port_stream<long long>::write(long long const & val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<unsigned long long>::write(unsigned long long const & val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<ap_int<64>>::write(const ap_int<64>& val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<ap_axis<32, 0, 0, 0>>::write(const ap_axis<32, 0, 0, 0>& val)
    {
       return ::write32bits(m_stream,
			  *((int*) &val.data), false);
    }
    template<> inline void
    port_stream<ap_axis<64, 0, 0, 0>>::write(const ap_axis<64, 0, 0, 0>& val)
    {
       int *words = (int*) &val.data;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<ap_axis<128, 0, 0, 0>>::write(const ap_axis<128, 0, 0, 0>& val)
    {
       int *words = (int*) &val.data;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
       ::write32bits(m_stream, words[2], false);
       ::write32bits(m_stream, words[3], false);
    }

    template<> inline void
    port_stream<ap_uint<32>>::write(const ap_uint<32>& val)
    {
       return ::write32bits(m_stream,
			  *((int*) &val), false);
    }
    template<> inline void
    port_stream<ap_uint<64>>::write(const ap_uint<64>& val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<ap_axiu<32, 0, 0, 0>>::write(const ap_axiu<32, 0, 0, 0>& val)
    {
       return ::write32bits(m_stream,
			  *((int*) &val.data), false);
    }
    template<> inline void
    port_stream<ap_axiu<64, 0, 0, 0>>::write(const ap_axiu<64, 0, 0, 0>& val)
    {
       int *words = (int*) &val.data;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<ap_axiu<128, 0, 0, 0>>::write(const ap_axiu<128, 0, 0, 0>& val)
    {
       int *words = (int*) &val.data;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
       ::write32bits(m_stream, words[2], false);
       ::write32bits(m_stream, words[3], false);
    }
    template<> inline void port_stream<float>::write(float const &val)
    {
       int *words = (int*) &val;
       return ::write32bits(m_stream, words[0], false);
    }
    template<> inline void
    port_stream<std::complex<short>>::write(const std::complex<short>& val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
    }
    template<> inline void
    port_stream<std::complex<int>>::write(const std::complex<int>& val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
    template<> inline void
    port_stream<std::complex<float>>::write(const std::complex<float>& val)
    {
       int *words = (int*) &val;
       ::write32bits(m_stream, words[0], false);
       ::write32bits(m_stream, words[1], false);
    }
}


namespace hls
{
    template<typename __STREAM_T__, int DEPTH=0> class X86SIM_EXPORT stream
    {
    private:
        adf_hls_wrapper::base_stream<__STREAM_T__>* _stream;

    public:
        stream()
        {
            _stream = new adf_hls_wrapper::fifo_stream<__STREAM_T__>();
        }

        stream(::x86sim::stream_internal* port)
        {
            _stream = new adf_hls_wrapper::port_stream<__STREAM_T__>(port);
        }

        stream(::x86sim::stream_internal* port0,
	       ::x86sim::stream_internal* port1)
        {
            _stream = new adf_hls_wrapper::port_stream<__STREAM_T__>
	       (port0, port1);
        }

        virtual ~stream()
        {
            delete _stream;
        }

        inline bool empty()
        {
            return _stream->empty();
        }

        inline bool full() const
        {
            return _stream->full();
        }

        inline __STREAM_T__ read()
        {
            return _stream->read();
        }

        inline void write(const __STREAM_T__& tail)
        {
            return _stream->write(tail);
        }

        inline void read(__STREAM_T__& head)
        {
            head = read();
        }

        inline void operator >> (__STREAM_T__& rdata)
        {
            read(rdata);
        }

        inline void operator << (const __STREAM_T__& wdata)
        {
            write(wdata);
        }

        inline bool read_nb(__STREAM_T__& head)
        {
            return _stream->read_nb(head);
        }

        inline bool write_nb(const __STREAM_T__& tail)
        {
            return _stream->write_nb(tail);
        }

        inline size_t size()
        {
            return _stream->size();
        }
    };
}

#endif //ifndef _SRC_X86SIM_INCLUDE_X86SIM_HLS_STREAM_H_
