#ifndef __FSM_H
#define __FSM_H

#include "pt_headfile.h"

#define Bend_speedoffset 							0	//弯道的速度偏移量(40)


void pid_errorspeed_func(void);
void gyro_out_func(float exp_in);
void speed_pid_func(float aim_base_in,float exp_in);
void angle_turn_process(float angle_in);
void track_line_in(void);
void adcmax_calibration(void);
uint8 cross_like_detected(void);
void cross_error_hold_process(void);


void Fsm_process(void);

extern float		pid_errorspeed;
extern float		gyro_out;
extern int8 fsm;
extern uint8 huandao_in_flag;
extern uint8 cross_flag;
extern uint8 huandao_out_flag;
extern uint16 cross_count;
extern float aim_speed;
extern uint16 turn_count;
extern uint16 count_flag;
extern uint16 Roundabout_count;
extern uint8 Roundabout_flag;
extern uint8 cross_key_2;
extern uint16 cross_2_dida;


extern float md_turn_weight;
extern float md_cross_min;
extern float side_cross_min;
extern float side_balance_max;
extern float cross_error_scale;
extern float round_confirm_ticks;
extern float round_md_min;
extern float round_md_max;
extern float round_side_min;
extern float round_side_max;
extern float round_outer_diff_min;
extern float round_side_diff_min;
extern float round_inner_side_max;
extern float round_side_ratio_min;
extern float round_error_max;
extern float round_out_yaw_min;
extern float round_out_side_min;
extern float round_out_angle;
extern float round_out_done_yaw;

extern uint32 round_encoder_accu;


extern float gyro_out;
extern float left_motor_duty;
extern float right_motor_duty;
#endif
