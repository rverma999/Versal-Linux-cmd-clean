// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _MESYNC_H
#define _MESYNC_H


/******************************************************************************
   
  --> sync_buffer[0] is used to store termination word
  --> sync_buffer[1] is used to store (static or dynamic) test_iterations value
    
*******************************************************************************/

static inline void set_termination_word() {
  sync_buffer[0] = 0xdeadbeef;
}

static inline void clear_termination_word() {
  sync_buffer[0] = 0;
}

#endif // _MEDEBUG_H


