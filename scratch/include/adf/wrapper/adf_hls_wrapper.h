// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _ADF_HLS_WRAPPER_
#define _ADF_HLS_WRAPPER_

#define X_HLS_STREAM_SIM_H //use preprocessor X_HLS_STREAM_SIM_H to skip any later #include "hls_stream.h" in HLS source files

#include "ap_axi_sdata.h" //for ap_axis(u) and ap_(u)int
#include <iostream>

namespace adf_hls_wrapper
{
    template<typename T> class base_stream
    {
    public:
        base_stream() {}
        virtual ~base_stream() {}

        virtual std::string class_name() const = 0; //pure virtual function

        virtual bool empty()
        {
            std::cerr << "hls::stream::empty is not supported in " << class_name() << " class." << std::endl;
            return true;
        }

        virtual bool full() const
        {
            std::cerr << "hls::stream::full is not supported in " << class_name() << " class." << std::endl;
            return false;
        }

        /// Blocking read
        virtual T read()
        {
            std::cerr << "hls::stream::read is not supported in " << class_name() << " class." << std::endl;
            return T();
        }

        /// Blocking write
        virtual void write(const T& tail)
        {
            std::cerr << "hls::stream::write is not supported in " << class_name() << " class." << std::endl;
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
            std::cerr << "hls::stream::read_nb is not supported in " << class_name() << " class. Program Terminated." << std::endl;
            exit( EXIT_FAILURE );
        }

        /// Nonblocking write
        virtual bool write_nb(const T& tail)
        {
            std::cerr << "hls::stream::write_nb is not supported in " << class_name() << " class. Program Terminated." << std::endl;
            exit( EXIT_FAILURE );
        }

        /// Number of available elements
        virtual size_t size()
        {
            std::cerr << "hls::stream::size is not supported in " << class_name() << " class." << std::endl;
            return 0;
        }
    };


    template<typename T> class fifo_stream : public base_stream<T>
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


    template<typename T> class input_stream : public base_stream<T>
    {
    private:
        MEStream64_get_port* instream;

    public:
        input_stream(MEStream64_get_port* get_port)
        {
            instream = get_port;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::input_stream";
        }

        T read() override
        {
            MEStreamData64 sample;
            (*instream)->get(sample);
            if (sizeof(T) <= 8)
            {
                T value;
                memcpy(&value, &sample.data[0], sizeof(T));
                return value;
            }
            else
            {
                std::cerr << class_name() << "<T> does not support sizeof(T) > 8." << std::endl;
            }
        }
    };

    template<> ap_int<8> input_stream<ap_int<8>>::read()
    {
        ap_int<32> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data = sample.data[0];
        return ap_data.range(7, 0);
    }

    template<> ap_uint<8> input_stream<ap_uint<8>>::read()
    {
        ap_uint<32> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data = sample.data[0];
        return ap_data.range(7, 0);
    }

    template<> ap_int<16> input_stream<ap_int<16>>::read()
    {
        ap_int<32> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data = sample.data[0];
        return ap_data.range(15, 0);
    }

    template<> ap_uint<16> input_stream<ap_uint<16>>::read()
    {
        ap_uint<32> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data = sample.data[0];
        return ap_data.range(15, 0);
    }

    template<> ap_int<32> input_stream<ap_int<32>>::read()
    {
        ap_int<32> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data = sample.data[0];
        return ap_data;
    }

    template<> ap_uint<32> input_stream<ap_uint<32>>::read()
    {
        ap_uint<32> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data = sample.data[0];
        return ap_data;
    }

    template<> ap_int<64> input_stream<ap_int<64>>::read()
    {
        ap_int<64> ap_data;
        MEStreamData64  sample;
        (*instream)->get(sample);
        int64 value;
        memcpy(&value, &sample.data[0], 8);
        ap_data = value;
        return ap_data;
    }

    template<> ap_uint<64> input_stream<ap_uint<64>>::read()
    {
        ap_uint<64> ap_data;
        MEStreamData64  sample;
        (*instream)->get(sample);
        uint64 value;
        memcpy(&value, &sample.data[0], 8);
        ap_data = value;
        return ap_data;
    }

    template<> ap_axis<32, 0, 0, 0> input_stream<ap_axis<32, 0, 0, 0>>::read()
    {
        ap_axis<32, 0, 0, 0> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data.data = sample.data[0];
        return ap_data;
    }

    template<> ap_axiu<32, 0, 0, 0> input_stream<ap_axiu<32, 0, 0, 0>>::read()
    {
        ap_axiu<32, 0, 0, 0> ap_data;
        MEStreamData64 sample;
        (*instream)->get(sample);
        ap_data.data = sample.data[0];
        return ap_data;
    }

    template<> ap_axis<64, 0, 0, 0> input_stream<ap_axis<64, 0, 0, 0>>::read()
    {
        ap_axis<64, 0, 0, 0> ap_data;
        MEStreamData64  sample;
        (*instream)->get(sample);
        //one valid word
        if (sample.tlast == true && sample.tkeep == false)
        {
            ap_data.keep = 0xf;
            ap_data.last = sample.tlast;
        }
        else
        {
            ap_data.keep = 0xff;
            ap_data.last = sample.tlast;
        }
        int64 value;
        memcpy(&value, &sample.data[0], 8);
        ap_data.data = value;
        return ap_data;
    }

    template<> ap_axiu<64, 0, 0, 0> input_stream<ap_axiu<64, 0, 0, 0>>::read()
    {
        ap_axiu<64, 0, 0, 0> ap_data;
        MEStreamData64  sample;
        (*instream)->get(sample);
        //one valid word
        if (sample.tlast == true && sample.tkeep == false)
        {
            ap_data.keep = 0xf;
            ap_data.last = sample.tlast;
        }
        else
        {
            ap_data.keep = 0xff;
            ap_data.last = sample.tlast;
        }
        uint64 value;
        memcpy(&value, &sample.data[0], 8);
        ap_data.data = value;
        return ap_data;
    }

    template<> class input_stream<ap_axis<128, 0, 0, 0>> : public base_stream<ap_axis<128, 0, 0, 0>>
    {
    private:
        MEStream64_get_port* instream0;
        MEStream64_get_port* instream1;

    public:
        input_stream(MEStream64_get_port* _instream0, MEStream64_get_port* _instream1)
        {
            instream0 = _instream0;
            instream1 = _instream1;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::input_stream";
        }

        ap_axis<128, 0, 0, 0> read() override
        {
            ap_axis<128, 0, 0, 0> ap_data;
            MEStreamData64  sample0, sample1;
            (*instream0)->get(sample0);
            (*instream1)->get(sample1);
            bool tlast0 = sample0.tlast;
            bool tlast1 = sample1.tlast;
            bool tkeep0 = sample0.tkeep;
            bool tkeep1 = sample1.tkeep;
            //No of valid words in last 128-bit beat 
            //Valid TKEEP TLAST 
            //  1    2b00 2b01 
            //  2    2b01 2b01 
            //  3    2b00 2b10 
            //  4    2b10 2b10 
            //All four words are valid
            if (!tlast0 && tlast1 && !tkeep0 && tkeep1)
            {
                ap_data.keep = 0xffff;
                ap_data.last = tlast1;
            }
            //3 words are valid
            else if (!tlast0 && tlast1 && !tkeep0 && !tkeep1)
            {
                ap_data.keep = 0xfff;
                ap_data.last = tlast1;
            }
            //2 words are valid
            else if (tlast0 && !tlast1 && tkeep0 && !tkeep1)
            {
                ap_data.keep = 0xff;
                ap_data.last = tlast0;
            }
            //1 word is valid
            else if (tlast0 && !tlast1 && !tkeep0 && !tkeep1)
            {
                ap_data.keep = 0xf;
                //for 128-bit hls stream, we set just one tlast
                //but for MEStream,there are two tlast for 128-bit stream
                ap_data.last = tlast0;
            }
            else
            {
                ap_data.keep = 0xffff;
                ap_data.last = tlast0;
            }
            uint64 value0, value1;
            memcpy(&value0, &sample0.data[0], 8);
            memcpy(&value1, &sample1.data[0], 8);
            ap_data.data.range(63, 0) = value0;
            ap_data.data.range(127, 64) = value1;
            return ap_data;
        }
    };

    template<> class input_stream<ap_axiu<128, 0, 0, 0>> : public base_stream<ap_axiu<128, 0, 0, 0>>
    {
    private:
        MEStream64_get_port* instream0;
        MEStream64_get_port* instream1;

    public:
        input_stream(MEStream64_get_port* _instream0, MEStream64_get_port* _instream1)
        {
            instream0 = _instream0;
            instream1 = _instream1;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::input_stream";
        }

        ap_axiu<128, 0, 0, 0> read() override
        {
            ap_axiu<128, 0, 0, 0> ap_data;
            MEStreamData64  sample0, sample1;
            (*instream0)->get(sample0);
            (*instream1)->get(sample1);
            bool tlast0 = sample0.tlast;
            bool tlast1 = sample1.tlast;
            bool tkeep0 = sample0.tkeep;
            bool tkeep1 = sample1.tkeep;
            //No of valid words in last 128-bit beat 
            //Valid TKEEP TLAST 
            //  1    2b00 2b01 
            //  2    2b01 2b01 
            //  3    2b00 2b10 
            //  4    2b10 2b10 
            //All four words are valid
            if (!tlast0 && tlast1 && !tkeep0 && tkeep1)
            {
                ap_data.keep = 0xffff;
                ap_data.last = tlast1;
            }
            //3 words are valid
            else if (!tlast0 && tlast1 && !tkeep0 && !tkeep1)
            {
                ap_data.keep = 0xfff;
                ap_data.last = tlast1;
            }
            //2 words are valid
            else if (tlast0 && !tlast1 && tkeep0 && !tkeep1)
            {
                ap_data.keep = 0xff;
                ap_data.last = tlast0;
            }
            //1 word is valid
            else if (tlast0 && !tlast1 && !tkeep0 && !tkeep1)
            {
                ap_data.keep = 0xf;
                ap_data.last = tlast0;
            }
            else
            {
                ap_data.keep = 0xffff;
                //for 128-bit hls stream, we set just one tlast
                //but for MEStream,there are two tlast for 128-bit stream
                ap_data.last = tlast0;
            }

            uint64 value0, value1;
            memcpy(&value0, &sample0.data[0], 8);
            memcpy(&value1, &sample1.data[0], 8);
            ap_data.data.range(63, 0) = value0;
            ap_data.data.range(127, 64) = value1;
            return ap_data;
        }
    };


    template<typename T> class output_stream : public base_stream<T>
    {
    private:
        MEStream64_put_port* outstream;

    public:
        output_stream(MEStream64_put_port* put_port)
        {
            outstream = put_port;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::output_stream";
        }

        void write(const T& val) override
        {
            MEStreamData64 value;
            memcpy(&value.data[0], &val, sizeof(T));
            value.tkeep = (sizeof(T) > 4) ? true : false;
            (*outstream)->put(value);
        }
    };

    //TODO needs discussion on 8 and 16-bit write, currently this is 
    //signed or zero extended to 32-bit
    template<> void output_stream<ap_int<8>>::write(const ap_int<8>& val)
    {
        MEStreamData64 value((int32)val, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_uint<8>>::write(const ap_uint<8>& val)
    {
        MEStreamData64 value((uint32)val, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_int<16>>::write(const ap_int<16>& val)
    { 
        MEStreamData64 value((int32)val, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_uint<16>>::write(const ap_uint<16>& val)
    {
        MEStreamData64 value((uint32)val, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_int<32>>::write(const ap_int<32>& val)
    {
        MEStreamData64 value(val, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_uint<32>>::write(const ap_uint<32>& val)
    {
        MEStreamData64 value(val, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_int<64>>::write(const ap_int<64>& val)
    {
        uint32 data[2];
        memcpy(data, &val, 8);
        MEStreamData64 value(data[0], data[1], false, true);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_uint<64>>::write(const ap_uint<64>& val)
    {
        uint32 data[2];
        memcpy(data, &val, 8);
        MEStreamData64 value(data[0], data[1], false, true);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_axis<32, 0, 0, 0>>::write(const ap_axis<32, 0, 0, 0>& val)
    {
        MEStreamData64 value(val.data, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_axiu<32, 0, 0, 0>>::write(const ap_axiu<32, 0, 0, 0>& val)
    {
        MEStreamData64 value(val.data, 0, false, false);
        (*outstream)->put(value);
    }

    template<> void output_stream<ap_axis<64, 0, 0, 0>>::write(const ap_axis<64, 0, 0, 0>& val)
    {
        uint32 data[2];
        memcpy(data, &val.data, 8);
        if (0xf == val.keep && val.last == true)
        {
            MEStreamData64 value(data[0], data[1], true, false);
            (*outstream)->put(value);
        }
        else
        {
            //TODO check if val.last is always flase?
            MEStreamData64 value(data[0], data[1], val.last, true);
            (*outstream)->put(value);
        }
    }

    template<> void output_stream<ap_axiu<64, 0, 0, 0>>::write(const ap_axiu<64, 0, 0, 0>& val)
    {
        uint32 data[2];
        memcpy(data, &val.data, 8);
        if (0xf == val.keep && val.last == true)
        {
            MEStreamData64 value(data[0], data[1], true, false);
            (*outstream)->put(value);
        }
        else
        {
            //TODO check if val.last is always flase?
            MEStreamData64 value(data[0], data[1], val.last, true);
            (*outstream)->put(value);
        }
    }

    template <> class output_stream<ap_axis<128, 0, 0, 0>> : public base_stream<ap_axis<128, 0, 0, 0>>
    {
    private:
        MEStream64_put_port* outstream0;
        MEStream64_put_port* outstream1;

    public:
        output_stream(MEStream64_put_port* _outstream0, MEStream64_put_port* _outstream1)
        {
            outstream0 = _outstream0;
            outstream1 = _outstream1;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::output_stream";
        }

        void write(const ap_axis<128, 0, 0, 0>& val) override
        {
            int32 data[4];
            data[0] = val.data.range(31, 0);
            data[1] = val.data.range(63, 32);
            data[2] = val.data.range(95, 64);
            data[3] = val.data.range(127, 96);
            //No of valid words in last 128-bit beat 
            //Valid TKEEP TLAST 
            //  1    2b00 2b01 
            //  2    2b01 2b01 
            //  3    2b00 2b10 
            //  4    2b10 2b10 
            //  1 valid word
            if (0xf == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], true, false);
                MEStreamData64 scalar1(data[2], data[3], false, false);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            else if (0xff == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], true, true);
                MEStreamData64 scalar1(data[2], data[3], false, false);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            else if (0xff == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], false, false);
                MEStreamData64 scalar1(data[2], data[3], true, false);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            //4 valid words
            else if (0xffff == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], false, false);
                MEStreamData64 scalar1(data[2], data[3], true, true);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            else
            {
                //TODO check in this case if -->val.last == false, val.keep == true? always
                MEStreamData64 scalar0(data[0], data[1], val.last, val.keep);
                MEStreamData64 scalar1(data[2], data[3], val.last, val.keep);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
        }
    };

    template<> class output_stream<ap_axiu<128, 0, 0, 0>> : public base_stream<ap_axiu<128, 0, 0, 0>>
    {
    private:
        MEStream64_put_port* outstream0;
        MEStream64_put_port* outstream1;

    public:
        output_stream(MEStream64_put_port* _outstream0, MEStream64_put_port* _outstream1)
        {
            outstream0 = _outstream0;
            outstream1 = _outstream1;
        }

        std::string class_name() const override
        {
            return "adf_hls_wrapper::output_stream";
        }

        void write(const ap_axiu<128, 0, 0, 0>& val)
        {
            int32 data[4];
            data[0] = val.data.range(31, 0);
            data[1] = val.data.range(63, 32);
            data[2] = val.data.range(95, 64);
            data[3] = val.data.range(127, 96);
            //No of valid words in last 128-bit beat 
            //Valid TKEEP TLAST 
            //  1    2b00 2b01 
            //  2    2b01 2b01 
            //  3    2b00 2b10 
            //  4    2b10 2b10 
            //  1 valid word
            if (0xf == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], true, false);
                MEStreamData64 scalar1(data[2], data[3], false, false);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            else if (0xff == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], true, true);
                MEStreamData64 scalar1(data[2], data[3], false, false);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            else if (0xfff == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], false, false);
                MEStreamData64 scalar1(data[2], data[3], true, false);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            //4 valid words
            else if (0xffff == val.keep && val.last == true)
            {
                MEStreamData64 scalar0(data[0], data[1], false, false);
                MEStreamData64 scalar1(data[2], data[3], true, true);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
            else
            {
                //TODO check in this case if -->val.last == false, val.keep == true? always
                MEStreamData64 scalar0(data[0], data[1], val.last, val.keep);
                MEStreamData64 scalar1(data[2], data[3], val.last, val.keep);
                (*outstream0)->put(scalar0);
                (*outstream1)->put(scalar1);
            }
        }
    };
}


namespace hls
{
    template<typename __STREAM_T__, int DEPTH=0> class stream
    {
    private:
        adf_hls_wrapper::base_stream<__STREAM_T__>* _stream;

    public:
        stream()
        {
            _stream = new adf_hls_wrapper::fifo_stream<__STREAM_T__>();
        }

        stream(MEStream64_get_port* in)
        {
            _stream = new adf_hls_wrapper::input_stream<__STREAM_T__>(in);
        }

        stream(MEStream64_put_port* out)
        {
            _stream = new adf_hls_wrapper::output_stream<__STREAM_T__>(out);
        }

        stream(MEStream64_get_port* in0, MEStream64_get_port* in1)
        {
            _stream = new adf_hls_wrapper::input_stream<__STREAM_T__>(in0, in1);
        }

        stream(MEStream64_put_port* out0, MEStream64_put_port* out1)
        {
            _stream = new adf_hls_wrapper::output_stream<__STREAM_T__>(out0, out1);
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

#endif //_ADF_HLS_WRAPPER_
