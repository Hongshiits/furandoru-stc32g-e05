#include "pid_leg.h"
/*
	差速PID针对的对象：电感差
	目标值：电感差为0
	反馈值：实际的电感差
	偏差值：（0-）实际的电感值
	情况：当电感差为0时，PID输出的控制量为0，此时小车应位于中线位置，因此此时的占空比应为中线占空比
				即：最终实际的控制量应为PID的输出量+基础目标速度
*/

Positional_PID	errorspeed_pid,compensated_pid,round_pid;
Incremental_PID motor_left_pid,motor_right_pid;

float PID_Steering_Kp = 0;
float PID_Steering_Kg = 0;
float PID_Gyro_Kp = 0;
float PID_Gyro_Ki = 0;
float PID_Gyro_Kd = 0;
float PID_Current_Kp = 0;
float PID_Current_Ki = 0;
float PID_Current_Kd = 0;
//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为差速PID结构体初始化函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
void Errorspeed_pid_init(void)
{
	errorspeed_pid.SetValue = 0.0;			//差速PID的SetValue恒为0
	errorspeed_pid.ActualValue = 0.0;		//实际的电感差
	errorspeed_pid.err = 0.0;
	errorspeed_pid.err_last = 0.0;
	errorspeed_pid.ControlValue = 0;
	errorspeed_pid.integral = 0.0;
	errorspeed_pid.KP = (float)errorspeed_pid.temp_KP;
	errorspeed_pid.KD = (float)2 * errorspeed_pid.temp_KD;
	errorspeed_pid.KI = (float)errorspeed_pid.temp_KI;
	round_pid.KP = (float)round_pid.temp_KP;
	round_pid.KD = (float)round_pid.temp_KD;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为差速PID计算实现函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
int16 Errorspeed_pid_calculate(void)
{
	errorspeed_pid.err = errorspeed_pid.SetValue - errorspeed_pid.ActualValue;  
	errorspeed_pid.ControlValue = (int16)(errorspeed_pid.KP* errorspeed_pid.err\
																+ errorspeed_pid.KD  * (errorspeed_pid.err - errorspeed_pid.err_last)\
																+ errorspeed_pid.KI * errorspeed_pid.integral);
	errorspeed_pid.err_last = errorspeed_pid.err;
	//errorspeed_pid.integral += errorspeed_pid.err;
	return (errorspeed_pid.ControlValue);	// 限幅差速的范围
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为round差速PID计算实现函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
int16 Round_pid_calculate(void)
{
	round_pid.err = round_pid.SetValue - round_pid.ActualValue;  
	round_pid.ControlValue = (int16)(round_pid.KP * round_pid.err\
																+ round_pid.KD  * (round_pid.err - round_pid.err_last)\
																+ round_pid.KI * round_pid.integral);
	round_pid.err_last = round_pid.err;
	//errorspeed_pid.integral += errorspeed_pid.err;
	return (round_pid.ControlValue);	// 限幅差速的范围
}

float Integral_limit(float integral)
{
	if(integral > Integral_Max)									return Integral_Max;
	else if(integral < -Integral_Max)						return (-1)*Integral_Max;
	else	return integral;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为左轮电机PID结构体初始化函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
void Motor_left_pid_init(void)
{
	motor_left_pid.SetValue = aim_speed;	//电机的目标速度
	motor_left_pid.ActualValue = 0.0;			  //编码器获取的值
	motor_left_pid.err = 0;
	motor_left_pid.err_last1 = 0;
	motor_left_pid.err_last2 = 0;
	motor_left_pid.IncreaseValue = 0.0;
	motor_left_pid.ControlValue = 0;
	motor_left_pid.integral = 0.0;
//	motor_left_pid.KP = (float)motor_left_pid.temp_KP;
//	motor_left_pid.KD = (float)motor_left_pid.temp_KD;
//	motor_left_pid.KI = (float)motor_left_pid.temp_KI;
	motor_left_pid.KP=16;
	motor_left_pid.KD=0;
	motor_left_pid.KI=1.95;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为左轮电机PID计算实现函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
int16 Motor_left_pid_calculate(void)
{
	motor_left_pid.ActualValue = count_left;
  motor_left_pid.err = motor_left_pid.SetValue  - motor_left_pid.ActualValue;		
	motor_left_pid.IncreaseValue = motor_left_pid.KP*(motor_left_pid.err-motor_left_pid.err_last1)+ motor_left_pid.KI*motor_left_pid.err\
																 + motor_left_pid.KD*(motor_left_pid.err-2*motor_left_pid.err_last1+motor_left_pid.err_last2);
	motor_left_pid.ControlValue +=  motor_left_pid.IncreaseValue;
	motor_left_pid.err_last2 = motor_left_pid.err_last1;
	motor_left_pid.err_last1 = motor_left_pid.err;
	return (int16)Motor_duty_limit(motor_left_pid.ControlValue );	// 限幅 输出值应为整数
}




//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为右轮电机PID结构体初始化函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
void Motor_right_pid_init(void)
{
	motor_right_pid.SetValue = aim_speed;	//电机的目标速度
	motor_right_pid.ActualValue = 0;			//编码器获取的值
	motor_right_pid.err = 0;
	motor_right_pid.err_last1 = 0;
	motor_right_pid.err_last2 = 0;
	motor_right_pid.IncreaseValue = 0.0;
	motor_right_pid.ControlValue = 0;
	motor_right_pid.integral = 0.0;
//	motor_left_pid.KP = (float)motor_left_pid.temp_KP;
//	motor_left_pid.KD = (float)motor_left_pid.temp_KD;
//	motor_left_pid.KI = (float)motor_left_pid.temp_KI;
	motor_right_pid.KP=16;
	motor_right_pid.KD=0;
	motor_right_pid.KI=1.95;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为右轮电机PID计算实现函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
int16 Motor_right_pid_calculate(void)
{
	motor_right_pid.ActualValue = count_right;	
	motor_right_pid.err = motor_right_pid.SetValue  - motor_right_pid.ActualValue;
	motor_right_pid.IncreaseValue = motor_right_pid.KP*(motor_right_pid.err-motor_right_pid.err_last1)+ motor_right_pid.KI*motor_right_pid.err\
																	+ motor_right_pid.KD*(motor_right_pid.err-2*motor_right_pid.err_last1+motor_right_pid.err_last2);
	motor_right_pid.ControlValue +=  motor_right_pid.IncreaseValue;
	motor_right_pid.err_last2 = motor_right_pid.err_last1;
	motor_right_pid.err_last1 = motor_right_pid.err;
	return (int16)Motor_duty_limit(motor_right_pid.ControlValue);	// 限幅 输出值应为整数
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为所有PID初始化函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
void PID_init(void)
{
	Motor_left_pid_init();		//左电机PID初始化
	Motor_right_pid_init(); 	//右电机PID初始化
//	errorspeed_pid.temp_KP = 74;
//	errorspeed_pid.temp_KD = 80;
	Errorspeed_pid_init();
}



/**
 * @brief 转向环(位置式PD)
 * @param expect:期望转向的角度
 * @param angle:真实的角度(一般是yaw)
 * @param gyro:真实角加速度(一般是gyro_z)
 * @return PWM
 */
float PID_Steering(float expect, float angle)
{
    float PWM_out;
    float a = 0.7;

    PWM_out = PID_Steering_Kp * (expect - angle); 
    return PWM_out;
}



/**
 * @brief 角速度环(位置式PD)
 * @param expect:期望角度
 * @param angle:真实角度
 * @param gyro:真实角速度
 * @return PWM
 */

float gyro_error_last = 0;
float gyro_integral = 0.0f;
// 角速度环PID控制函数
float PID_Gyro(float desired_gyro, float current_gyro) {
	float gyro_error,gyro_error_diff,gyro_p_term,gyro_i_term,gyro_d_term,gyro_output;
		
    // 计算角速度误差
    gyro_error = current_gyro - desired_gyro;

    // 计算误差的变化率（微分项所需）
    gyro_error_diff = gyro_error - gyro_error_last;

    // 积分项计算
    gyro_integral += gyro_error;
    // 积分限幅
    if (gyro_integral > 1000)
        gyro_integral = 1000;
    if (gyro_integral < -1000)
        gyro_integral = -1000;

    // 计算比例项
    gyro_p_term = PID_Gyro_Kp * gyro_error;
    // 计算积分项
    gyro_i_term = PID_Gyro_Ki * gyro_integral;
    // 计算微分项
    gyro_d_term = PID_Gyro_Kd * gyro_error_diff;

    // 计算总输出
    gyro_output = gyro_p_term + gyro_i_term + gyro_d_term;

    // 输出限幅
    if (gyro_output > 8000) gyro_output = 8000;
    if (gyro_output < -8000) gyro_output = -8000;

    // 更新上一次的误差
    gyro_error_last = gyro_error;

    return gyro_output;
}

// 电流环全局变量
float current_error_last = 0;
float current_integral = 0.0f;

/**
 * @brief 电流环PID控制函数
 * @param desired_current: 期望电流值（来自速度环）
 * @param actual_current: 实际测量电流值
 * @return PWM占空比值（-7000~7000）
 */
float PID_Current(float desired_current, float actual_current) {
    float current_error, current_error_diff;
    float current_p_term, current_i_term, current_d_term;
    float current_output;
    
    // 计算电流误差
    current_error = desired_current - actual_current;
    
    // 计算误差的变化率（微分项所需）
    current_error_diff = current_error - current_error_last;
    
    // 积分项计算与限幅
    current_integral += current_error;
    if (current_integral > 1000) current_integral = 1000;
    if (current_integral < -1000) current_integral = -1000;
    
    // 计算比例项
    current_p_term = PID_Current_Kp * current_error;
    // 计算积分项
    current_i_term = PID_Current_Ki * current_integral;
    // 计算微分项
    current_d_term = PID_Current_Kd * current_error_diff;
    
    // 计算总输出
    current_output = current_p_term + current_i_term + current_d_term;
    
    // 输出限幅（假设PWM为8位，范围-7000~7000）
    if (current_output > 7000) current_output = 7000;
    if (current_output < -7000) current_output = -7000;
    
    // 更新上一次的误差
    current_error_last = current_error;
    
    return current_output;
}


// 电压前馈控制
float Advanced_Voltage_Feedforward(float speed_output, float supply_voltage) {
    
    float base_pwm, compensation , final_pwm;
	 // 基本PWM占空比
    base_pwm = speed_output;
    // 电压前馈补偿（非线性模型）
    if (supply_voltage > 10.0f) {
        // 高电压区域，轻微补偿
        compensation = 0.8f + 0.2f * (12.6f / supply_voltage);
    } else {
        // 低电压区域，更强补偿
        compensation = 1.0f + 0.5f * (12.6f / supply_voltage - 1.0f);
    }
    
    // 计算最终PWM
		final_pwm = base_pwm * compensation;
    
    // 限幅
    if (final_pwm > 7000) final_pwm = 7000;
    if (final_pwm < -7000) final_pwm = -7000;
    
    return final_pwm;
}
