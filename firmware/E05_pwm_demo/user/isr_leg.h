#ifndef ISR_LEG_H
#define ISR_LEG_H

#include "pt_headfile.h"

extern float 	adc_data[5];
extern float 	adc_ordata[5];
extern float	aim_speed;
extern uint8    temp_aim_speed;
extern float  filtered_data[4];
extern float  window[25];

extern float 	adc_ecs[2];
extern float  time_dida;
extern float  time_dadi;
extern float  A_ahead;
extern float  B_ahead;
extern float  C_ahead;
extern float  Lim_ahead;
extern float  Error_ahead;
extern float  A_Turn;
extern float  B_Turn;
extern float  C_Turn;
extern float  Lim_Turn;
extern float  Error_Turn;

extern float Error_Turn_round;

extern float  A_Cross;
extern float  B_Cross;
extern float  C_Cross;
extern float  Lim_Cross;
extern float  Error_Cross;
extern float  A_Roundabout_in;
extern float  B_Roundabout_in;
extern float  C_Roundabout_in;
extern float  Lim_Roundabout_in;
extern float  Error_Roundabout_in;
extern float  A_Roundabout_out;//10
extern float  B_Roundabout_out;//5
extern float  C_Roundabout_out;//3
extern float  Lim_Roundabout_out;
extern float  Error_Roundabout_out;
extern float  Error_Cross_2;
extern uint32 count_time_w;

typedef struct{
	float A,B,C;
	uint8 temp_A,temp_B,temp_C;    //temp值为原始值的10倍
}D_Sratio;

extern D_Sratio  turn;
extern uint8 goflag;




void  clear_gryo(void);
void TM4_Isr_lega(); //原算法中断处理函数，移植
void track_line();
void sensor_capture();

#endif