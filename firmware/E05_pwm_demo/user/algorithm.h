#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "pid.h"

#define APP_MOTOR_MAX_PWM (5500)


extern pid_t app_motor_left_pid;
extern pid_t app_motor_right_pid;
extern pid_t app_adc_errospeed_pid;
extern pid_t app_gyro_pid;



void init_algorithm(void);

#endif // _ALGORITHM_H_