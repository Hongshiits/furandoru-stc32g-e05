#include "pwm.h"

int16 motor_left_PIDduty = 0;
int16 motor_right_PIDduty = 0;
int16 motor_top_PIDduty = 0;

int16 duty = 0;
uint8 pwm_channel_index = 0;
pwm_channel_enum pwm_channel_list[PWM_CHANNEL_NUMBER] = {PWM_CH1, PWM_CH2, PWM_CH3};





void pt_pwm_init()
{
    pwm_init(PWM_CH1, 170000, 0); // MOT1 left
    pwm_init(PWM_CH2, 170000, 0); // MOT2 right

#if (_PT_BLDC_==1)
    pwm_init(PWM_CH3, 200, 0); 
#else
    pwm_init(PWM_CH3, 170000, 0); // MOT3 top
#endif

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      电机驱动速度误差限幅函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
int16 Errorspeed_limit(int16 errorspeed)
{
	if(errorspeed > MAX_ERRORSPEED)									return MAX_ERRORSPEED;
	else if(errorspeed < -MAX_ERRORSPEED)						return (-1)*MAX_ERRORSPEED;
	else	return errorspeed;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      电机驱动占空比限幅函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
float Motor_duty_limit(float motor_duty)
{
	if(motor_duty >= MOTOR_MAX_PWM)									return MOTOR_MAX_PWM;
	else if(motor_duty <= -MOTOR_MAX_PWM)						return (-1)*MOTOR_MAX_PWM;
	else	return motor_duty;
}
void pid_set(int16 leftmotor_duty, int16 rightmotor_duty)
{
	motor_left_pid.SetValue = leftmotor_duty;
	motor_right_pid.SetValue = rightmotor_duty;
	motor_left_PIDduty = Motor_left_pid_calculate();		
	motor_right_PIDduty = Motor_right_pid_calculate();		
	Motor_act(motor_left_PIDduty, motor_right_PIDduty);	
}


void Motor_act(int16 leftmotor_duty, int16 rightmotor_duty)
{
	leftmotor_duty = Motor_duty_limit(leftmotor_duty);
	rightmotor_duty = Motor_duty_limit(rightmotor_duty);
	
	if(leftmotor_duty >= 0)           // 左电机正转
    {    
        gpio_set_level(MOTOR_LEFT_DIR_PIN, 1);
        //pwm_set_freq(PWM_CH1, 170000, leftmotor_duty);  
        pwm_set_duty(PWM_CH1, leftmotor_duty);
    }    
    else                               // 左电机反转  
    {    
        gpio_set_level(MOTOR_LEFT_DIR_PIN, 0);
        pwm_set_duty(PWM_CH1, -leftmotor_duty);    
    } 
    
    if(rightmotor_duty >= 0)          // 右电机正转  
    {    
        gpio_set_level(MOTOR_RIGHT_DIR_PIN, 0);
        pwm_set_duty(PWM_CH2, rightmotor_duty);    
    }    
    else                               // 右电机反转   
    {    
        gpio_set_level(MOTOR_RIGHT_DIR_PIN, 1);
        pwm_set_duty(PWM_CH2, -rightmotor_duty);
    }
}

// void Motor_act(int16 leftmotor_duty, int16 rightmotor_duty)
// {
// 	leftmotor_duty = Motor_duty_limit(leftmotor_duty);
// 	rightmotor_duty = Motor_duty_limit(rightmotor_duty);
	
// 	if(leftmotor_duty > 0)           // 左电机正转
//     {    
//         gpio_set_level(MOTOR_LEFT_DIR_PIN, 1);
//         //pwm_set_freq(PWM_CH1, 170000, leftmotor_duty);  
//         pwm_set_duty(PWM_CH1, leftmotor_duty>dead_pwm?leftmotor_duty:dead_pwm);
//     }    
//     else if(leftmotor_duty < 0)                              // 左电机反转  
//     {    
//         gpio_set_level(MOTOR_LEFT_DIR_PIN, 0);
//         pwm_set_duty(PWM_CH1, leftmotor_duty<-dead_pwm?-leftmotor_duty:dead_pwm);    
//     } else{
//         pwm_set_duty(PWM_CH1, 0);    
//     }
    
//     if(rightmotor_duty > 0)          // 右电机正转  
//     {    
//         gpio_set_level(MOTOR_RIGHT_DIR_PIN, 0);
//         pwm_set_duty(PWM_CH2, rightmotor_duty>dead_pwm?rightmotor_duty:dead_pwm);    
//     }    
//     else if(rightmotor_duty < 0)                              // 右电机反转   
//     {    
//         gpio_set_level(MOTOR_RIGHT_DIR_PIN, 1);
//         pwm_set_duty(PWM_CH2, rightmotor_duty<-dead_pwm?-rightmotor_duty:dead_pwm);
//     }else{
//         pwm_set_duty(PWM_CH2, 0);    
//     }
// }

void Motor_up_act(int16 upmotor_duty)
{
	upmotor_duty = Motor_duty_limit(upmotor_duty);
	
	if(upmotor_duty >= 0)           // 负压电机正转
    {    
        gpio_set_level(MOTOR_UP_DIR_PIN, 1);
        pwm_set_duty(PWM_CH3, upmotor_duty);
    }    
    else                               // 负压电机反转  
    {    
        gpio_set_level(MOTOR_UP_DIR_PIN, 0);
        pwm_set_duty(PWM_CH3, -upmotor_duty);    
    }
}


#if (_PT_BLDC_==1)
void mot_top_on(int16 topmotduty){
    pwm_set_duty(PWM_CH3, topmotduty);
    motor_top_PIDduty=topmotduty;
    
}
#else
void mot_top_on(int16 topmotduty){
    int16 i;
    pwm_set_duty(PWM_CH3, 3000);
    system_delay_ms(500);
    for(i = 3000; i <= topmotduty; i += 1){
        pwm_set_duty(PWM_CH3, i);
        system_delay_ms(1);
    }
    motor_top_PIDduty=topmotduty;
    
}
#endif