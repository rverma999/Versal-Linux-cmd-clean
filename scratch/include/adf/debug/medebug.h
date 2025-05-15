// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _MEDEBUG_H
#define _MEDEBUG_H

static int debugbuffer[16];

#define FOR_WRITE 0
#define FOR_READ  1
static enum { noval, intval, lockacq, lockrel, term, lockreq, strval}  DebugType; 

#ifdef TRACE_LOCK
#define TERMINATE()  terminate(__LINE__)
void terminate(int line) 
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = term;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
  while (1); 
} 

#define ME_WRITE_HERE()  debug_write_here(__LINE__) 
void debug_write_here(int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = noval;;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
} 
#else
#define TERMINATE()  ;
#define ME_WRITE_HERE()  ;
#endif // TRACE_LOCK

#if !defined(DEBUG) || !defined(TRACE_LOCK)
#define ME_WRITE_INT(intval)  ; 
#define ME_WRITE_HEX(intval)  ; 
#define ME_WRITE_STR(p)  ;
#define ME_ASSERT(boolval, msgstr) ; 

#define ACQUIRE(x,y)  acquire(x,y)
#define RELEASE(x,y)  release(x,y)
#define ME_WRITE_LOCKACQ(lockId, value)   ;
#define ME_WRITE_LOCKREQ(lockId, value)   ;
#define ME_WRITE_LOCKREL(lockId, value)   ;

#else 
#define ME_WRITE_INT(intval)  debug_write_int(intval,__LINE__) 
#define ME_WRITE_STR(p) { const char *ptr = p; int x = (int)ptr; debug_write_str(x, __LINE__); } 
#define ME_WRITE_HEX(intval)  { int x = (int)(intval); debug_write_hex(x,__LINE__); }
#define ME_ASSERT(boolval, msgstr) { if (boolval == 0)  ME_WRITE_STR("assertion failed at"); \
    ME_WRITE_STR(msgstr); }

void debug_write_str(int p, int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = strval;
  debugbuffer[2] = p;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
}


void debug_write_int(int val, int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = intval;
  debugbuffer[2] = val;
  debugbuffer[3] = 10;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
} 


void debug_write_hex(int val, int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = intval;
  debugbuffer[2] = val;
  debugbuffer[3] = 16;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
} 


#ifndef DEBUGLOCKS
#define ACQUIRE(x,y)  acquire(x,y)
#define RELEASE(x,y)  release(x,y)
#define ME_WRITE_LOCKACQ(lockId, value)   ;
#define ME_WRITE_LOCKREQ(lockId, value)   ;
#define ME_WRITE_LOCKREL(lockId, value)   ;

#else
#define ME_WRITE_LOCKREQ(lockId, value)   debug_write_lockreq(lockId, value, __LINE__)
#define ME_WRITE_LOCKACQ(lockId, value)   debug_write_lockacq(lockId, value, __LINE__)
#define ME_WRITE_LOCKREL(lockId, value)   debug_write_lockrel(lockId, value, __LINE__)
#define ACQUIRE(x,y)  ME_WRITE_LOCKREQ(x,y); \
                      acquire(x,y) ;\
                      ME_WRITE_LOCKACQ(x,y);

#define RELEASE(x,y)  ME_WRITE_LOCKREL(x,y); \
                      release(x,y)

void debug_write_lockreq(int lockId, int reqval, int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = lockreq;
  debugbuffer[2] = lockId;
  debugbuffer[3] = reqval;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
} 

void debug_write_lockacq(int lockId, int acqval, int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = lockacq;
  debugbuffer[2] = lockId;
  debugbuffer[3] = acqval;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
} 


void debug_write_lockrel(int lockId, int relval,  int line)
{ 
  acquire(TRACE_LOCK, FOR_WRITE);
  debugbuffer[0] = line;
  debugbuffer[1] = lockrel;
  debugbuffer[2] = lockId;
  debugbuffer[3] = relval;
  debugbuffer[15] = get_me_cycles();
  release(TRACE_LOCK, FOR_READ);
} 
#endif // DEBUGLOCKS

#endif // DEBUG

#endif // _MEDEBUG_H


