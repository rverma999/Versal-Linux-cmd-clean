// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _WINDOWFUNCTIONS_WINDOW_INTERNAL_H_
#define _WINDOWFUNCTIONS_WINDOW_INTERNAL_H_
#include <stdint.h>
// Included because of memcpy()
#include <string.h>

typedef int8_t window_datatype;

#if __AIE_ARCH__>=20
inline window_datatype * cyclic_add(window_datatype *ptr, int count, window_datatype *base, unsigned int size) {
    addr_t c0 = (long)ptr;
    addr_t c1 = (long)ptr;
    return add_3d_byte(ptr, count-size, (long)(base-count), c0, count+size, (long)(base-count+size), c1, count);
}
#endif // if __AIE_ARCH__>=20


#define WINDOW_DATATYPE_SIZE   (sizeof (window_datatype))
#ifdef __X86SIM__
namespace x86sim {
    class IWindowConnector;
}
#endif // ifdef __X86SIM__

#pragma pack()
struct __attribute__((__may_alias__)) window_internal
{
     unsigned int  current_bufid;
     unsigned int instanceId;
     window_datatype * restrict ptr;
     window_datatype *  restrict head;
     window_datatype  *         restrict heads[2];
     window_datatype *  restrict buffer;
     window_datatype  *         restrict  buffers[2];
     unsigned int size;
     unsigned int winsize;
   #ifdef __X86SIM__
     x86sim::IWindowConnector *conn;
   #else
     unsigned int lockids[2];
   #endif
};
#pragma pack()

static inline void window_init(window_internal *w, 
			       int const channels, 
			       window_datatype *buffer_ping,
			       unsigned int lockid_ping, 
			       window_datatype *buffer_pong, 
			       unsigned int lockid_pong, 
			       int const size, 
			       int const winsize) {
    //assert(size % 8 == 0);
    for (int i = 0; i < channels; ++i) 
    {
        w[i].buffers[0] = buffer_ping+size*i;
        w[i].heads[0] = w[i].buffers[0];
      #ifdef __X86SIM__
        w[i].conn = nullptr;
      #else
	    w[i].lockids[0] =  lockid_ping;
      #endif
        w[i].buffers[1] = 0; /* null */
        w[i].heads[1] = 0; /* null */
      #ifndef __X86SIM__
        w[i].lockids[1] = -1; /* Invalid, dummy */
      #endif

#if (__AIE_ARCH__>=20)
	if (buffer_pong != buffer_ping) {  /* there is a separate pong buffer */
	    w[i].buffers[1] = buffer_pong+size*i;
	    w[i].heads[1] = w[i].buffers[1];
        }
#ifndef __X86SIM__
	w[i].lockids[1] = lockid_pong;
#endif
#else
	if (buffer_pong != buffer_ping) {  /* there is a separate pong buffer */
	    w[i].buffers[1] = buffer_pong+size*i;
	    w[i].heads[1] = w[i].buffers[1];
#ifndef __X86SIM__
	     w[i].lockids[1] = lockid_pong;
#endif
        }
#endif
	w[i].current_bufid = 0;
        w[i].buffer = w[i].buffers[0];
        w[i].head   = w[i].heads[0];
        w[i].ptr    = w[i].head;
        w[i].size   = size;
	w[i].winsize= winsize;
    }
}

static inline void set_window_size(window_internal *w, int const size) {
  w->winsize = size;
  //printf("window@%x: size = %d, winsize = %d\n", (void*)(w->buffer), w->size, w->winsize);
}

static inline unsigned window_size(window_internal *w) {
  return w->winsize;
}

#undef CYCLIC_ADD
#ifdef __X86SIM__
inline window_datatype * x86sim_cyclic_add(window_datatype *ptr, int count, window_datatype *buf, unsigned int size) {
  int off = ptr+count-buf;
  while (off<0) off += size;
  while (off>=(int)size) off -= (int)size;
  return buf+off;
}
#define CYCLIC_ADD(PTR,OFFSET,BUF,SIZE) \
    x86sim_cyclic_add((PTR),(OFFSET),(BUF),(SIZE))
#else
#define CYCLIC_ADD(PTR,OFFSET,BUF,SIZE) \
    cyclic_add((PTR),(OFFSET),(BUF),(SIZE))
#endif // ifdef __X86SIM__

// Compiler-Inserted Window Operations

// buffer has a specific allocated amount of memory which starts at w->buffer and is of w->size in bytes

static inline void window_incr_pingpong(window_internal *w, int count) { 
  // window_incr_pingpong() is very similar to window_incr() except that it increments both heads[0] and heads[1], 
  // and is only called outside the for(...test_iteration...) loop.
  //count *= sizeof(int8_t) / sizeof(window_datatype);
  w->heads[0] = CYCLIC_ADD(w->heads[0], count, w->buffers[0], w->size);
  //if (w->is_pingpong)
  w->heads[1] = CYCLIC_ADD(w->heads[1], count, w->buffers[1], w->size);
  w->head = w->heads[0];//w->current_bufid];
}
// increments in 8-bit chunks
static inline void window_incr(window_internal * w, window_datatype *restrict ping_buffer,
                                window_datatype *restrict pong_buffer,int const index,int margin,
                                int count) {
  //Making nested scope to allow assignment to restrict pointer
  {
    window_datatype * restrict hd = (index ? pong_buffer : ping_buffer) + margin;
    hd = CYCLIC_ADD(hd, count, index ? pong_buffer : ping_buffer, w->size);
  }
}

// increments in 8-bit chunks
  static inline void window_incr(window_internal * w, int count) { 		   
    //count *= sizeof(int8_t) / sizeof(window_datatype);
    //printf("window@%x: size = %d, winsize = %d, count = %d\n", (void*)(w->buffer), w->size, w->winsize, count);
    w->head = CYCLIC_ADD(w->head, count, w->buffer, w->size);	
  }

static inline void window_bypass_copy(window_internal *win,
                                      window_internal *wout,
                                      unsigned int margin,
                                      unsigned int blocksize,
                                      unsigned int phase)
{
  int count = (margin/WINDOW_DATATYPE_SIZE);
  count *= sizeof(int8_t) / sizeof(window_datatype);
  win->head = CYCLIC_ADD(win->head, count, win->buffer, win->size);
  count = 8*(sizeof(int32_t)/WINDOW_DATATYPE_SIZE);
  count *= sizeof(int8_t) / sizeof(window_datatype);
#ifdef __X86SIM__
    static_assert(sizeof(window_datatype) == 1, "Unexpected size");
    unsigned sz = win->size;
    // h1 is destination; h2 is source
    unsigned todo = blocksize;
    while (todo > 0)
    {
        unsigned nextChunk = todo;
        if (wout->head + todo > wout->buffer + sz)
            nextChunk = wout->buffer + sz - wout->head;
        if (win->head + nextChunk > win->buffer + sz)
            nextChunk = win->buffer + sz - win->head;
        memcpy(wout->head, win->head, nextChunk);
        todo -= nextChunk;
        wout->head += nextChunk;
        if (wout->head > wout->buffer + sz)
            wout->head -= sz;
        win->head += nextChunk;
        if (win->head > win->buffer + sz)
            win->head -= sz;
    }
#else
  for (unsigned int i = 0; i < (blocksize/WINDOW_DATATYPE_SIZE)/32; ++i) {
    v8int32 tmp;
    tmp = *((v8int32  * restrict)(win->head));
    win->head = CYCLIC_ADD(win->head ,count, win->buffer, win->size);
    *((v8int32  * restrict)(wout->head)) = tmp;
    wout->head = CYCLIC_ADD(wout->head, count, wout->buffer, wout->size);
  }
#endif
  count = (-(margin/WINDOW_DATATYPE_SIZE)-(blocksize/WINDOW_DATATYPE_SIZE));
  count *= sizeof(int8_t) / sizeof(window_datatype);
  win->head = CYCLIC_ADD(win->head, count, win->buffer, win->size);
  count = -(blocksize/WINDOW_DATATYPE_SIZE);
  count *= sizeof(int8_t) / sizeof(window_datatype);
  wout->head = CYCLIC_ADD(wout->head, count, wout->buffer, wout->size);
}

static inline void window_margin_copy(window_internal *w,
                                      unsigned  int margin)
{
  //Making nested scope to allow assignment to restrict pointer
  {
    unsigned  int id = w->current_bufid;
    window_datatype *restrict h1 = w->heads[1-id];
    window_datatype *restrict h2 = w->heads[id];
    window_datatype *restrict buf1 = w->buffers[1-id];
    window_datatype *restrict buf2  = w->buffers[id];
    h2 = CYCLIC_ADD(h2, w->winsize, buf2, w->size);
#ifdef __X86SIM__
    static_assert(sizeof(window_datatype) == 1, "Unexpected size");
    unsigned sz = w->size;
    // h1 is destination; h2 is source
    unsigned todo = (margin >> 5) << 5;
    while (todo > 0)
    {
        unsigned nextChunk = todo;
        if (h1 + todo > buf1 + sz)
            nextChunk = buf1 + sz - h1;
        if (h2 + nextChunk > buf2 + sz)
            nextChunk = buf2 + sz - h2;
        memcpy(h1, h2, nextChunk);
        todo -= nextChunk;
        h1 += nextChunk;
        if (h1 > buf1 + sz)
            h1 -= sz;
        h2 += nextChunk;
        if (h2 > buf2 + sz)
            h2 -= sz;
    }
#else
    for (unsigned int k = 0; k < margin/32; ++k)
        chess_flatten_loop
    {
      v8int32 tmp;
      tmp = *((v8int32  * restrict)(h2));
      h2 = CYCLIC_ADD(h2, 8*(sizeof(int32)), buf2, w->size);
      *((v8int32  * restrict)(h1)) = tmp;
      h1 = CYCLIC_ADD(h1, 8*(sizeof(int32)), buf1, w->size);
    }
#endif
    int msize = -(margin);
    h2 = CYCLIC_ADD(h2, msize-w->winsize,buf2, w->size);
    h1 = CYCLIC_ADD(h1, msize,buf1, w->size);
    w->heads[1-id] = h1;
    w->heads[id] = h2;
    w->buffers[1-id] = buf1;
    w->buffers[id] = buf2;
  }
}

static inline void window_margin_copy(window_internal *w, 
                                      unsigned const int margin, 
                                      window_datatype * restrict ping_buffer,
                                      window_datatype * restrict pong_buffer, 
                                      const int index)
{
  //Making nested scope to allow assignment to restrict pointer
  {
    window_datatype *restrict h1 = index ? ping_buffer : pong_buffer;//w->heads[1-index];
    window_datatype *restrict h2 = index ? pong_buffer : ping_buffer;//index ? w->heads[1] : w->heads[0];
    window_datatype *restrict buf1 = index ? ping_buffer : pong_buffer; //w->buffers[1-index];
    window_datatype *restrict buf2  = index ? pong_buffer : ping_buffer;//index ? w->buffers[1] : w->buffers[0];

#ifdef __X86SIM__
    static_assert(sizeof(window_datatype) == 1, "Unexpected size");
    unsigned sz = w->size;
    // h1 is destination; h2 is source
    h2 = CYCLIC_ADD(h2, w->winsize, buf2, w->size);
    unsigned todo = (margin >> 5) << 5;
    while (todo > 0)
    {
        unsigned nextChunk = todo;
        if (h1 + todo > buf1 + sz)
            nextChunk = buf1 + sz - h1;
        if (h2 + nextChunk > buf2 + sz)
            nextChunk = buf2 + sz - h2;
        memcpy(h1, h2, nextChunk);
        todo -= nextChunk;
        h1 += nextChunk;
        if (h1 > buf1 + sz)
            h1 -= sz;
        h2 += nextChunk;
        if (h2 > buf2 + sz)
            h2 -= sz;
    }
#else
    h2 = CYCLIC_ADD(h2, w->winsize, buf2, w->size);
    for (unsigned int k = 0; k < margin/32; ++k)
    //chess_unroll_loop(*)
    {
         v8int32 tmp;
         tmp = *((v8int32  * restrict)(h2));
         h2 = CYCLIC_ADD(h2, 8*(sizeof(int32)), buf2, chess_copy(w->size));
         *((v8int32  * restrict)(h1)) = tmp;
         h1 = CYCLIC_ADD(h1, 8*(sizeof(int32)), buf1, chess_copy(w->size));
    }
    h2 = CYCLIC_ADD(h2, -(margin)-w->winsize,buf2, w->size); 
    h1 = CYCLIC_ADD(h1, -(margin),buf1, w->size);
    (index ? ping_buffer : pong_buffer ) = buf1; 
    (index ?  pong_buffer : ping_buffer ) = buf2;
#endif
  }
}

#endif // ifndef _WINDOWFUNCTIONS_WINDOW_INTERNAL_H_
