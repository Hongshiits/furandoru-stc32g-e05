#ifndef EEPROM_H
#define EEPROM_H

#include "pt_headfile.h"


#define  EEPROM_write_enable  EEPROM_write_enable_value //一定需要修改，不再使用GPIO作为使能方式，后续完善
#define  GO_enable			  GO_enable_value //一定需要修改，不再使用GPIO作为使能方式，后续完善

extern volatile uint8 GO_enable_value;
extern volatile uint8 EEPROM_write_enable_value;
extern uint32 GO_enable_count;

extern uint8 Direction;

extern uint8 errorspeed_pid_buff[];
extern uint8 D_Sratio_turn_buff[];
extern uint8 aim_speed_buff[];
extern uint8 round_pid_buff[];

void eeprom_init();
void force_read_eeprom();

#endif