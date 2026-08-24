#include "algorithm.h"



pid_t app_motor_left_pid={0};
pid_t app_motor_right_pid={0};

pid_t app_adc_errospeed_pid={0};
pid_t app_gyro_pid={0};



void init_algorithm()
{
	//1ms pit 2 0.5 0 pid
	// PID_struct_init(&app_motor_left_pid, DELTA_PID, APP_MOTOR_MAX_PWM, 100000, 20, 1.8, 0.0); //增量式PID	
	// PID_struct_init(&app_motor_right_pid, DELTA_PID, APP_MOTOR_MAX_PWM, 100000, 20, 1.8, 0.0); //增量式PID
	PID_struct_init(&app_motor_left_pid, DELTA_PID, APP_MOTOR_MAX_PWM, 100000, 22.0, 0.74, 0.0); //增量式PID	
	PID_struct_init(&app_motor_right_pid, DELTA_PID, APP_MOTOR_MAX_PWM, 100000, 22.0, 0.74, 0.0); //增量式PID

	PID_struct_init(&app_adc_errospeed_pid, POSITION_PID, 100000, 100000, 3200.0, 0.0, 1000.0);
	//PID_struct_init(&app_adc_errospeed_pid, POSITION_PID, 100000, 100000, 600.0, 0.0, 10.0); 
	//PID_struct_init(&app_adc_errospeed_pid, POSITION_PID, 100000, 100000, 185.0, 0.0, 115.0);  //380
	//PID_struct_init(&app_adc_errospeed_pid, POSITION_PID, 100000, 100000, 260.0, 0.0, 200.0);  //560
	PID_struct_init(&app_gyro_pid, POSITION_PID, 8000, 1000, 0.4, 0.0, 0.025); 


}

