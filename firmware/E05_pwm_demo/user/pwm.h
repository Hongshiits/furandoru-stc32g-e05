#ifndef PWM_H
#define PWM_H

#include "pt_headfile.h"

#define PWM_CHANNEL_NUMBER (3)

#define _PT_BLDC_          (0)

#define PWM_CH1 (PWMB_CH1_P74)
#define PWM_CH2 (PWMD_CH1_P24)
#define PWM_CH3 (PWMF_CH1_P70)

#define MAX_ERRORSPEED	(10)

#define MOTOR_MAX_PWM	(7000)
#define MOTOR_DEAD_PWM	(1500)

extern int16 duty;
extern uint8 pwm_channel_index;
extern pwm_channel_enum pwm_channel_list[PWM_CHANNEL_NUMBER];

extern int16 motor_left_PIDduty;
extern int16 motor_right_PIDduty;
extern int16 motor_top_PIDduty;

void pt_pwm_init(void);
int16 Errorspeed_limit(int16 errorspeed);
float Motor_duty_limit(float motor_duty);
void Motor_act(int16 leftmotor_duty, int16 rightmotor_duty);
void Motor_up_act(int16 upmotor_duty);
void pid_set(int16 leftmotor_duty, int16 rightmotor_duty);
void mot_top_on(int16 topmotduty);



#endif