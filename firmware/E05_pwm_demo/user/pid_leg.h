#ifndef __PID_LEG_H_
#define __PID_LEG_H_

#include "pt_headfile.h"

//#define R_DIR P60	//定义电机方向脚
//#define R_PWM P62	//定义电机PWM脚
#define Integral_Max 1500

//位置式PID结构体定义(转向环只用PD
typedef struct{
	float SetValue;					
	float ActualValue;
	float err;
	float err_last;
	uint8 temp_KP,temp_KI,temp_KD;
	float KP,KI,KD;
	int16 ControlValue;
	float integral;
}Positional_PID;


//增量式PID结构体定义(速度环用
typedef struct{
	int16 SetValue;					
	int16 ActualValue;	//编码器获取的值为整数
	int16 err;
	int16 err_last1;
	int16 err_last2;
	uint8 temp_KP,temp_KI,temp_KD;
	float KP,KI,KD;
	float IncreaseValue;//增量式允许浮点数计算
	float ControlValue; //PWM输出的占空比必须为整数
	float integral;
}Incremental_PID;



extern Positional_PID	errorspeed_pid,round_pid;
extern Incremental_PID motor_left_pid, motor_right_pid;


extern float PID_Steering_Kp;
extern float PID_Steering_Kg;
extern float PID_Gyro_Kp;
extern float PID_Gyro_Ki;
extern float PID_Gyro_Kd;
extern float PID_Current_Kp;
extern float PID_Current_Ki;
extern float PID_Current_Kd;

int16 Errorspeed_pid_calculate(void);
int16 Round_pid_calculate(void);
int16 Motor_left_pid_calculate(void);
int16 Motor_right_pid_calculate(void);

void PID_init(void);
//void PID_reinit(void);
float PID_Steering(float expect, float angle);
float PID_Gyro(float desired_gyro, float current_gyro);
float PID_Current(float desired_current, float actual_current);
float Advanced_Voltage_Feedforward(float speed_output, float supply_voltage);
#endif

