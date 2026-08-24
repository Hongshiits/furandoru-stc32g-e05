#ifndef _PT_HEADFILE_H_
#define _PT_HEADFILE_H_

#include "zf_common_headfile.h"
#include "hornshell.h"

#include "adc.h"
#include "encoder.h"
#include "imu.h"
#include "pwm.h"
#include "pit.h"
#include "gpio.h"
#include "fsm.h"
#include "pid_leg.h"
#include "isr_leg.h"
#include "eeprom.h"
#include "fsm_leg.h"
#include "pid.h"
#include "algorithm.h"
//#include "matrix.h"
//#include "ekf.h"


#define ON (1)
#define OFF (0)

#define ADC_DATA_LV adc_data[4]
#define ADC_DATA_LH adc_data[3]
#define ADC_DATA_MD adc_data[2]
#define ADC_DATA_RH adc_data[1]
#define ADC_DATA_RV adc_data[0]


#ifdef _660RB_
#define IMU_GYRO_X imu660rb_gyro_x
#define IMU_GYRO_Y imu660rb_gyro_y
#define IMU_GYRO_Z imu660rb_gyro_z
#define IMU_ACC_X imu660rb_acc_x
#define IMU_ACC_Y imu660rb_acc_y
#define IMU_ACC_Z imu660rb_acc_z
#else
#define IMU_GYRO_X imu660ra_gyro_x
#define IMU_GYRO_Y imu660ra_gyro_y
#define IMU_GYRO_Z imu660ra_gyro_z
#define IMU_ACC_X imu660ra_acc_x
#define IMU_ACC_Y imu660ra_acc_y
#define IMU_ACC_Z imu660ra_acc_z
#endif

extern float	yaw ;    //航向角
extern float 	pitch ; 

extern float	coe_yaw ;	 // 航向角
extern float	coe_pitch; // 俯仰角

extern float exp_acc;
extern float PID_Steering_Kp_set;
extern float exp_yaw_1;
extern float exp_yaw_2;

extern uint32 dead_pwm;

extern uint8 Buzzer; // 蜂鸣器控制变量

extern void(*monitor_func_list[])(void);
extern volatile uint8 monitor_func_index;

extern pid_t* pid_list[];

uint8 pt_atoi(const char *str);
int16 pt_atoi16(const char *str);
float pt_atof(const char *str);
int8 pt_atoi8(const char *str);

void adc_print_monitor(void);
void encoder_print_monitor(void);
void null_monitor(void);
void imu_print_monitor(void);
void erroturn_monitor(void);
void gyro_monitor(void);
void error_turn_monitor(void);
void oradc_print_monitor(void);
void imu_processed_print_monitor(void);
void encoder_print_dyna_monitor(void);
void oradc_erro_print_monitor(void);

#endif



