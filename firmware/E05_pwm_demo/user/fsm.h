#ifndef FSM_H
#define FSM_H

#include "pt_headfile.h"

// FSM state and handlers
extern uint8 fsm_state;
extern void(*pit_handler_fsm_ptr_map[])(void);
extern void(*pit_handler_fsm_cond_map[])(uint8*);
extern void(*pit_handler_fsm_ptr)(void);

void pit_handler_fsm(void);
void pit_handler_hornshell(void);
void pit_handler_cond_common(uint8 *stat_fsm);
void pit_handler_cond_dec_one(uint8 *stat_fsm);
void pit_handler_cond_hornshell(uint8 *stat_fsm);

#endif