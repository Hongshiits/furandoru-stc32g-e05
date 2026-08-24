#include "fsm_leg.h"
/*公用变量*/
int8 fsm = 1;			  // 状态机
float pid_errorspeed = 0; // 左右轮速度差
int cnt = 0;
/*丢线变量*/
uint8 lose_road_time = 0.5; // 丢线时间设置:lose_road_time*100ms

/*直线变量*/
uint8 aheadroad_L = 3; // 直道电感值							//直线目标速度
uint16 slow_time = 50; // 直道加速时间(ms)
float error = 0;

/*十字变量*/
uint8 cross_flag = 0; // cross state flag
#define CROSS_ERROR_HOLD_TICKS (8)
static uint8 cross_error_hold_count = 0;
uint8 cross_key = 0;
uint8 cross_L = 50;		 // 十字路口电感值
float cross_speed = 200; // 十字路口环岛速度
uint8 cross_key_2 = 0;
uint16 cross_2_dida = 0;
float md_turn_weight = 3.0;
float md_cross_min = 70.0;
float side_cross_min = 70.0;
float side_balance_max = 35.0;
float cross_error_scale = 0.1;

/*转角变量*/
uint8 turn_L = 12;					// 小弯电感值
uint16 right_angle_L = 50;			// 直角弯电感值
float offset_speed = 15;			// 转弯减速值
uint16 small_bends_decel_time = 0;	// 小弯减速时间
uint16 right_angle_decel_time = 50; // 直角减速时间
float bend_path_kp = 18;			// 弯道差速环KP
float bend_path_kd = 2.5;			// 弯道差速环KD

/*环岛变量*/
float Roundabout_speed = 20; // 环岛速度
uint8 Roundabout_flag = 0;	 // 环岛标志 0:无
							 // 环岛标志 1:入
							 // 环岛标志 2:出
uint8 Roundabout_LR = 0;	 // 左右环岛：1:L,2:R
uint8 Roundabout_key = 0;
float round_confirm_ticks = 8.0;
static uint8 round_right_confirm_count = 0;
static uint8 round_left_confirm_count = 0;
float round_md_min = 60.0;
float round_md_max = 135.0;
float round_side_min = 20.0;
float round_side_max = 45.0;
float round_outer_diff_min = 10.0;
float round_side_diff_min = 20.0;
float round_inner_side_max = 6.0;
float round_side_ratio_min = 0.65;
float round_error_max = 0.5;
float round_out_yaw_min = 330.0;
float round_out_side_min = 15.0;
float round_out_angle = 15.0;
float round_out_done_yaw = 360.0;

uint8 round_num_count=0;

uint32 round_encoder_accu=0;

float last_yaw=0;

/*坡道变量*/
float Ramp_speed = 19; // 坡道速度
uint8 ramp_key = 0;	   // 障碍误识别

float gyro_out = 0;
float left_motor_duty = 0;
float right_motor_duty = 0;

/*差速环动态KP，结合matlab进行观察*/
float base_kp = 50; // 动态基础KP-->用matlab绘制函数图形观察（最好还是利用中间电感值的偏差观察）
float limit = 10;
float base = 0.6;

/*计数器*/

uint16 turn_count = 0;
uint16 count_flag = 0;		 // 计数器2：状态转换
uint16 Roundabout_count = 0; // 计时器3：出入环岛
uint16 cross_count = 0;		 // 计数器4：出入十字
uint16 ramp_count = 0;		 // 计时器5：出坡判别
uint16 wuzhangai = 0;
uint16 zhizou = 0;
uint16 zhizou0 = 0;
uint16 zhiflag = 0;

uint16 Roundabout_outflag = 0;
///*避障*/
// uint16 Roadblock_forward = 0;//路障前进编码器积分
// uint8 Roadblock_flag = 1;//路障标志位
// uint16 Roadblock_jiansu_count = 0;
// uint8 Roadblock_key = 0;
/*
00.丢线
01.直线 + 小弯
02.转弯
03.十字路口
04.环岛
05.上下坡
06.障碍减速
07.路障左转
08.路障右转
09.路障直走
10.路障左转回赛道摆正
*/
uint16 speed_test = 0;

void lose_line_cond(void)
{
	/*丢线判定*/
	if ((ADC_DATA_LV < aheadroad_L) && (ADC_DATA_LH < aheadroad_L) &&
		(ADC_DATA_RV < aheadroad_L) && (ADC_DATA_RH < aheadroad_L))
	{
		fsm=0;
	}
}

void corner_cond()
{
	/*直角判定(50)*/
	if (fabs(Error_Turn) > 4.000 && (time_dadi > 0))
	{
		//				Buzzer = ON;
		//				clear_gryo();
		fsm = 2;
		turn_count = 0;
		return;
	}
}

void corner_process()
{
	//*依靠PID差速打角度转弯

	//-----------------------------------转向环----------------------------------------------------------------------
	//				errorspeed_pid.KP = 74;
	//				errorspeed_pid.KD = 80;

	//------------------------角速度参数----------------------------------------------------------------------------
	// PID_Gyro_Kp = 0.25;
	// PID_Gyro_Ki = 0;
	// PID_Gyro_Kd = 0.1;
	//----------------------------------------调好勿动-----------------------------------------------------------

	// errorspeed_pid.ActualValue = Error_Turn;
	// pid_errorspeed = Errorspeed_pid_calculate();
	// gyro_out = PID_Gyro(pid_errorspeed, imu660ra_gyro_x_l);
	// //}
	// // if(){//直角
	// // }
	// // if(){//钝角
	// // }
	// motor_left_pid.SetValue = aim_speed - gyro_out;
	// motor_right_pid.SetValue = aim_speed + gyro_out;
	// motor_left_PIDduty = Motor_left_pid_calculate();
	// motor_right_PIDduty = Motor_right_pid_calculate();
	// Motor_act(motor_left_PIDduty, motor_right_PIDduty);

	pid_errorspeed = pid_calc(&app_adc_errospeed_pid, Error_Turn, 0); // ADC误差速度PID计算
	// gyro_out = pid_calc(&app_gyro_pid, imu660ra_gyro_x_l, 0);
	gyro_out = pid_calc(&app_gyro_pid, imu660ra_gyro_x_l, pid_errorspeed); // 角速度PID计算
	motor_left_PIDduty = -pid_calc(&app_motor_left_pid, count_left, aim_speed - gyro_out);
	motor_right_PIDduty = pid_calc(&app_motor_right_pid, count_right, aim_speed + gyro_out);
	Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出

}

uint8 cross_like_detected(void)
{
	return ((ADC_DATA_MD > md_cross_min) &&
			((ADC_DATA_LH + ADC_DATA_RH) > side_cross_min) &&
			(fabs(ADC_DATA_LH - ADC_DATA_RH) < side_balance_max));
}

void cross_error_hold_process(void)
{
	if (cross_like_detected())
	{
		cross_error_hold_count = CROSS_ERROR_HOLD_TICKS;
		cross_flag = 1;
		Buzzer = ON;
	}

	if (cross_error_hold_count > 0)
	{
		Error_Turn *= cross_error_scale;
		cross_error_hold_count--;
		if (cross_error_hold_count == 0)
		{
			cross_flag = 0;
			Buzzer = OFF;
		}
	}
}

void cross_cond(void)
{
	cross_error_hold_process();
}

void cross_process(void)
{
	cross_error_hold_process();
	track_line_in();
	if (cross_flag == 0)
	{
		fsm = 1;
	}
}

// void round_cond()
// {
// 	float round_side_sum;
// 	float round_outer_diff;
// 	float round_side_diff;
// 	float round_side_ratio;
// 	uint8 round_like;

// 	if (Roundabout_outflag == 1)
// 	{
// 		Roundabout_count++;
// 	}
// 	if (Roundabout_count >= 20)
// 	{
// 		Roundabout_outflag = 0;
// 		Roundabout_count = 0;
// 		round_right_confirm_count = 0;
// 		round_left_confirm_count = 0;
// 	}

// 	if (cross_flag != 0)
// 	{
// 		round_right_confirm_count = 0;
// 		round_left_confirm_count = 0;
// 		return;
// 	}

// 	round_side_sum = ADC_DATA_LH + ADC_DATA_RH;
// 	round_outer_diff = ADC_DATA_LV - ADC_DATA_RV;
// 	round_side_diff = ADC_DATA_RH - ADC_DATA_LH;
// 	round_side_ratio = fabs(round_side_diff) / (round_side_sum + 1.0);
// 	round_like = ((ADC_DATA_MD > round_md_min) &&
// 		(ADC_DATA_MD < round_md_max) &&
// 		(round_side_sum > round_side_min) &&
// 		(round_side_sum < round_side_max) &&
// 		(fabs(round_side_diff) > round_side_diff_min) &&
// 		(round_side_ratio > round_side_ratio_min) &&
// 		(fabs(Error_Turn) < round_error_max) &&
// 		(fabs(imu660ra_gyro_y_f) < 300) &&
// 		(Roundabout_count == 0));

// 	if (round_like && (round_outer_diff > round_outer_diff_min) &&
// 		(round_side_diff > round_side_diff_min) &&
// 		(ADC_DATA_LH < round_inner_side_max))
// 	{
// 		round_right_confirm_count++;
// 	}
// 	else
// 	{
// 		round_right_confirm_count = 0;
// 	}

// 	if (round_like && (round_outer_diff < -round_outer_diff_min) &&
// 		(round_side_diff < -round_side_diff_min) &&
// 		(ADC_DATA_RH < round_inner_side_max))
// 	{
// 		round_left_confirm_count++;
// 	}
// 	else
// 	{
// 		round_left_confirm_count = 0;
// 	}

// 	if (round_right_confirm_count >= round_confirm_ticks)
// 	{
// 		round_right_confirm_count = 0;
// 		round_left_confirm_count = 0;
// 		Roundabout_flag = 1;
// 		Roundabout_LR = 2;
// 		fsm = 6;
// 		clear_gryo();
// 		return;
// 	}

// 	if (round_left_confirm_count >= round_confirm_ticks)
// 	{
// 		round_right_confirm_count = 0;
// 		round_left_confirm_count = 0;
// 		Roundabout_flag = 1;
// 		Roundabout_LR = 1;
// 		fsm = 7;
// 		clear_gryo();
// 		return;
// 	}
// }

void round_cond()
{
	/*右环岛判定¨*/
	if((fsm==1)&&((Roundabout_outflag!=0)||(Roundabout_outflag!=1))){
		Roundabout_outflag = 0;
		Roundabout_count = 0;
	}
	if (Roundabout_outflag != 0)
	{
		Roundabout_count++;
	}
	if (Roundabout_count >= 20)
	{
		Roundabout_outflag = 0;
		Roundabout_count = 0;
	}
	if (((last_md_adc_data-ADC_DATA_MD) < 0) && (ADC_DATA_MD < 210) && (ADC_DATA_MD > 120) && 
	(ADC_DATA_LH + ADC_DATA_RH < 110) && (ADC_DATA_LV > ADC_DATA_RV) 
	&& (fabs(Error_Turn) < 1.0) 
	&& (fabs(imu660ra_gyro_y_f)<150) 
	&& (Roundabout_count == 0)) // 120 100 90
	//if ((ADC_DATA_MD > 145) && (ADC_DATA_LH + ADC_DATA_RH < 135) && (ADC_DATA_LV > ADC_DATA_RV) && (fabs(Error_Turn) < 8)) // 120 100 90
	{
		Roundabout_flag = 1;
		fsm = 1;
		clear_gryo();
		last_yaw=0;
		//printf("round 6 detected\n");
		// printf("%f,%f,%f,%f\n",(last_md_adc_data-ADC_DATA_MD),ADC_DATA_MD,(ADC_DATA_LH + ADC_DATA_RH),(ADC_DATA_LV - ADC_DATA_RV));
		// printf(",%f,%f,%d\n",fabs(Error_Turn),fabs(imu660ra_gyro_y_f),Roundabout_count);
		return;
	}
	/*left环岛判断¨*/
	if (((last_md_adc_data-ADC_DATA_MD) < 0) && (ADC_DATA_MD < 210) && (ADC_DATA_MD > 120) && 
	(ADC_DATA_LH + ADC_DATA_RH < 75) && (ADC_DATA_LV < ADC_DATA_RV) 
	&& (fabs(Error_Turn) < 0.5) 
	&& (fabs(imu660ra_gyro_y_f)<150) 
	&& (Roundabout_count == 0)) // 120 100 90
	//if ((ADC_DATA_MD > 145) && (ADC_DATA_LH + ADC_DATA_RH < 135) && (ADC_DATA_LV < ADC_DATA_RV) && (fabs(Error_Turn) < 8)) // 120 100 90
	{
		Roundabout_flag = 1;
		fsm = 1;
		clear_gryo();
		last_yaw=0;
		printf("round 7 detected\n");
		
		interrupt_global_disable();

		system_delay_ms(200);

		interrupt_global_enable();

		// printf("%f,%f,%f,%f\n",(last_md_adc_data-ADC_DATA_MD),ADC_DATA_MD,(ADC_DATA_LH + ADC_DATA_RH),(ADC_DATA_LV - ADC_DATA_RV));
		// printf(",%f,%f,%d\n",fabs(Error_Turn),fabs(imu660ra_gyro_y_f),Roundabout_count);
		return;
	}
}



void angle_turn_process(float angle_in){
				/*打角*/
			{
				// motor_left_PIDduty = -pid_calc(&app_motor_left_pid, count_left, aim_speed + PID_Steering(angle_in, yaw));
				// motor_right_PIDduty = pid_calc(&app_motor_right_pid, count_right, aim_speed - PID_Steering(angle_in, yaw));
				speed_pid_func(aim_speed, -PID_Steering(angle_in, yaw));
				Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
			}
}

char* set_go_value_in(){
    uint8 value;

    motor_left_PIDduty = 0;
    motor_right_PIDduty = 0;

    value = 0;
    GO_enable=value;

    if(!GO_enable){
        motor_top_PIDduty=0;
    }

    return horn_ok;
}


void round_process_left(void)
{ // direct_in:1L,-1R
	/*Roundabout_flag
	 *	1:打角进圆环
	 *	2:环内
	 *	3:出环打角
	 *	4:出环
	 */
	{

		Buzzer = ON;
		if(fabs(imu660ra_gyro_y_f)>700){
				fsm=1;
				Roundabout_flag = 1;
				Roundabout_count = 0;
		}
		if (Roundabout_flag == 1)//打角进环岛
		{
			
			// PID_Steering_Kp = PID_Steering_Kp_set;
			// angle_turn_process(60);
		}
		if ((fabs(yaw) > 40) && (Roundabout_flag == 1))
		{
			Roundabout_flag = 2;
			Roundabout_count = 0;
			last_yaw=yaw;
		}

		if (Roundabout_flag == 2)//圆环内循迹
		{
			/*圆环内循迹*/
			//-----------------------------------转向环----------------------------------------------------------------------
			//					errorspeed_pid.KP = 76;
			//					errorspeed_pid.KD = 80;

			//------------------------角速度参数----------------------------------------------------------------------------

			//----------------------------------------调好勿动-----------------------------------------------------------
			track_line_in();
			if(((fabs(yaw)-fabs(last_yaw))<=-10)||(fabs(yaw)>360)||(fabs(imu660ra_gyro_y_f)>700)){
				fsm=1;
				Roundabout_flag = 1;
				Roundabout_count = 0;
			}
			last_yaw=yaw;

			
		}

		// if(
		// 	(fabs(yaw) > (round_out_yaw_min/2)) &&
		// 	round_num_count>2
		// ){
		// 	set_go_value_in();
		// }

		if ((fabs(yaw) > round_out_yaw_min) &&
			((ADC_DATA_LH + ADC_DATA_RH) > round_out_side_min) &&
			(Roundabout_flag == 2))
		{
			//printf("round out:%f,%f\n",fabs(yaw),(ADC_DATA_LH + ADC_DATA_RH));

			// app_adc_errospeed_pid.p=app_adc_errospeed_pid.p/16;
			// app_adc_errospeed_pid.d=app_adc_errospeed_pid.d*4;
			//printf("round out pid:%f,%f\n",app_adc_errospeed_pid.p,app_adc_errospeed_pid.d);
			Roundabout_flag = 3;
			Roundabout_count = 0;
			clear_gryo();
		}
		if (Roundabout_flag == 3)//出环打角
		{
			// PID_Steering_Kp = PID_Steering_Kp_set;
			// angle_turn_process(-round_out_angle);

			//round_encoder_accu+=count_left+count_right;
			// Error_Turn=0.01;
			// track_line_in();
			speed_pid_func(0, -100);
		}
		if (
			(fabs(yaw) > round_out_done_yaw) && 
			(Roundabout_flag == 3)
			//&&(round_encoder_accu>1000)
		)
		{
			//printf("round out done\n");
			// app_adc_errospeed_pid.p=app_adc_errospeed_pid.p*16;
			// app_adc_errospeed_pid.d=app_adc_errospeed_pid.d/4;
			Roundabout_flag = 4;
			Roundabout_count = 0;
			clear_gryo();
			round_encoder_accu=0;
		}
		if (((Roundabout_flag == 4)))//出环
		{
			// aim_speed = 50;
			fsm = 1;
			Roundabout_flag = 0;
			Roundabout_count = 0;
			Buzzer = OFF;
			Roundabout_LR = 0;
			Roundabout_outflag = 1;
			// offset_speed = 4;//6

			round_num_count++;

			return;
		}
	}
}

void round_process_left_re(void){
	if(fabs(imu660ra_gyro_y_f)>400){
				fsm=1;
				printf("gyro to fsm 1\n");
				Roundabout_flag = 0;
				Roundabout_count = 0;
		}

	if ((fabs(yaw) > 40) && (Roundabout_flag == 1))
	{
		Roundabout_flag = 2;
		Roundabout_count = 0;
		last_yaw=yaw;
		printf("out1 to fsm 2\n");
	}


	if (Roundabout_flag == 2)//圆环内循迹
	{
		track_line_in();

		if(((fabs(yaw)-fabs(last_yaw))<=-10)||(fabs(yaw)>360)||(fabs(imu660ra_gyro_y_f)>700)){
			fsm=1;
			printf("out2 to fsm 1\n");
			Roundabout_flag = 1;
			Roundabout_count = 0;
		}
		last_yaw=yaw;

	}

	if ((fabs(yaw) > round_out_yaw_min) &&
			((ADC_DATA_LH + ADC_DATA_RH) > round_out_side_min) &&
			(Roundabout_flag == 2))
		{

			Roundabout_flag = 3;
			printf("round out 2 to 3\n");
			Roundabout_count = 0;
			clear_gryo();
		}


	if (Roundabout_flag == 3)//出环打角
	{

		//speed_pid_func(aim_speed, 20);

		interrupt_global_disable();

		system_delay_ms(100);

		interrupt_global_enable();

		// Error_Turn=Error_Turn_round;
		// track_line_in();

	}
	if (
		(fabs(yaw) > round_out_done_yaw) && 
		(Roundabout_flag == 3)
	)
	{
		Roundabout_flag = 4;
		Roundabout_count = 0;
		clear_gryo();
		printf("round out 3 to 4\n");

	}

	if (((Roundabout_flag == 4)))//出环
	{

		fsm = 1;
		printf("round out 4 to fsm 1\n");

		Roundabout_flag = 0;

		Roundabout_count = 0;

		Roundabout_outflag = 1;

		round_num_count++;

		return;
	}


}


void round_process_right(void)
{ // direct_in:1L,-1R
	/*Roundabout_flag
	 *	1:打角进圆环
	 *	2:环内
	 *	3:出环打角
	 *	4:出环
	 */
	{

		Buzzer = ON;
		if(fabs(imu660ra_gyro_y_f)>700){
				fsm=1;
				Roundabout_flag = 1;
				Roundabout_count = 0;
		}
		if (Roundabout_flag == 1)//打角进环岛
		{
			// PID_Steering_Kp = PID_Steering_Kp_set;
			// angle_turn_process(-60);
		}
		if ((fabs(yaw) > 40) && (Roundabout_flag == 1))
		{
			Roundabout_flag = 2;
			Roundabout_count = 0;

			last_yaw=yaw;
		}

		if (Roundabout_flag == 2)//圆环内循迹
		{
			/*圆环内循迹*/
			//-----------------------------------转向环----------------------------------------------------------------------
			//					errorspeed_pid.KP = 76;
			//					errorspeed_pid.KD = 80;

			//------------------------角速度参数----------------------------------------------------------------------------

			//----------------------------------------调好勿动-----------------------------------------------------------
			track_line_in();

			if(((fabs(yaw)-fabs(last_yaw))<=-10)||(fabs(yaw)>360)||(fabs(imu660ra_gyro_y_f)>700)){
				fsm=1;
				Roundabout_flag = 1;
				Roundabout_count = 0;
			}

			last_yaw=yaw;

		}
		if ((fabs(yaw) > round_out_yaw_min) &&
			((ADC_DATA_LH + ADC_DATA_RH) > round_out_side_min) &&
			(Roundabout_flag == 2))
		{
			//printf("round out:%f,%f\n",fabs(yaw),(ADC_DATA_LH + ADC_DATA_RH));

			app_adc_errospeed_pid.p=app_adc_errospeed_pid.p/16;
			app_adc_errospeed_pid.d=app_adc_errospeed_pid.d*4;
			//printf("round out pid:%f,%f\n",app_adc_errospeed_pid.p,app_adc_errospeed_pid.d);
			Roundabout_flag = 3;
			Roundabout_count = 0;
			clear_gryo();
		}
		if (Roundabout_flag == 3)//出环打角
		{
			// PID_Steering_Kp = PID_Steering_Kp_set;
			// angle_turn_process(round_out_angle);
			round_encoder_accu+=count_left+count_right;
			Error_Turn=-0.01;
			track_line_in();
		}
		if (
			(fabs(yaw) > round_out_done_yaw) && 
			(Roundabout_flag == 3)
			//&&(round_encoder_accu>1000)
			)
		{
			//printf("round out done\n");
			app_adc_errospeed_pid.p=app_adc_errospeed_pid.p*16;
			app_adc_errospeed_pid.d=app_adc_errospeed_pid.d/4;
			Roundabout_flag = 4;
			Roundabout_count = 0;
			clear_gryo();
			round_encoder_accu=0;
		}
		if (((Roundabout_flag == 4)))//出环
		{
			// aim_speed = 50;
			fsm = 1;
			Roundabout_flag = 0;
			Roundabout_count = 0;
			Buzzer = OFF;
			Roundabout_LR = 0;
			Roundabout_outflag = 1;
			// offset_speed = 4;//6
			return;
		}
	}
}



void pid_errorspeed_func(void){
	#if (ENABLE_DIV_PIT)
	if(pit_count!=0) return; // PID分频，降低计算频率，减轻CPU负担
	#endif
	pid_errorspeed = pid_calc(&app_adc_errospeed_pid, Error_Turn, 0); // ADC误差速度PID计算

}


void gyro_out_func(float exp_in){
	#if (ENABLE_DIV_PIT)
	if(pit_count!=1) return; // PID分频，降低计算频率，减轻CPU负担
	#endif
	gyro_out = pid_calc(&app_gyro_pid, -imu660ra_gyro_x_l, exp_in); // 角速度PID计算
}

void speed_pid_func(float aim_base_in,float exp_in){

	#if (ENABLE_DIV_PIT)
	if(pit_count!=2) return; // PID分频，降低计算频率，减轻CPU负担
	#endif
	motor_left_PIDduty = pid_calc(&app_motor_left_pid, count_left, aim_base_in + exp_in);
	motor_right_PIDduty = -pid_calc(&app_motor_right_pid, count_right, aim_base_in - exp_in);
}

// void aim_speed_pid_func(float aim_base_in){

// 	#if (ENABLE_DIV_PIT)
// 	if(pit_count!=3) return; // PID分频，降低计算频率，减轻CPU负担
// 	#endif
// 	aim_speed = aim_base_in-pid_calc(&app_aim_speed_pid, abs(Error_Turn), 0);
// }

void track_line_in(void){

	/*差速环控制+速度环控制*/
	{

		//aim_speed_pid_func(aim_base);
		pid_errorspeed_func(); // ADC误差速度PID计算
		//gyro_out = pid_calc(&app_gyro_pid, imu660ra_gyro_x_l, 0);
		gyro_out_func(pid_errorspeed);
		speed_pid_func(aim_speed, gyro_out);
		//speed_pid_func(aim_speed, pid_errorspeed);

		//motor_left_PIDduty = -pid_calc(&app_motor_left_pid, count_left, aim_speed + pid_errorspeed);
		//motor_right_PIDduty = pid_calc(&app_motor_right_pid, count_right, aim_speed - pid_errorspeed);

		Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
	}
}

void adcmax_calibration(){
	uint8 i;
	monitor_func_index=0;
	for (i = 0; i < ADC_TRACK_CHANNEL_NUMBER; i++)
    {
        adcmax[i]=(adc_ordata[i]>adcmax[i])?adc_ordata[i]:adcmax[i];
		printf("%f",adcmax[i]);
		if(i!=ADC_TRACK_CHANNEL_NUMBER-1)printf(",");
    }
	printf("\n");
}


void Fsm_process(void)
{

	switch (fsm)
	{
		/*------------------------------------------------------------丢线-------------------------------------------------------------------*/
	case 0:
	{
		/*直线判定*/
		if ((ADC_DATA_LV > aheadroad_L) || (ADC_DATA_RV > aheadroad_L))
		{
			fsm = 1;
			break;
		}
		/*进入丢线*/
		{
			speed_pid_func(0,0);
			Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
			Buzzer = 0;
		}
	}
	break;

		/*------------------------------------------------------------直线-------------------------------------------------------------------*/
	case 1://直线
	{
		lose_line_cond();
		if (fsm != 1)
		{
			break;
		}
		//cross_cond();
		if (fsm != 1)
		{
			break;
		}
		//round_cond();
		//round_cond_test();
		if (fsm != 1)
		{
			break;
		}
		//-----------------------------------转向环----------------------------------------------------------------------
		//				errorspeed_pid.KP = 74;//75
		//				errorspeed_pid.KD = 80;
		//------------------------角速度参数----------------------------------------------------------------------------

		//----------------------------------------调好勿动-----------------------------------------------------------
		track_line_in();
	}
	break;

	case 2://直角
		lose_line_cond();
		round_cond();
		corner_process();
		break;

	case 3://十字
		lose_line_cond();
		cross_process();
		break;

	case 6://右环岛
		/*丢线判定*/
		lose_line_cond();
		round_process_right(); // 1右环岛
		break;

	case 7://左环岛
		/*丢线判定*/
		lose_line_cond();
		round_process_left_re(); // 1左环岛
		break;

	case 8://测试用循迹
		// lose_line_cond();
		// if (fsm != 8)
		// {
		// 	break;
		// }
		// cross_cond();

		pid_errorspeed_func(); // ADC误差速度PID计算
		speed_pid_func(aim_speed, pid_errorspeed);

		Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
		break;
	case 9://测试用直行
		speed_pid_func(aim_speed, 5);
		Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
		break;
	case 10://测试用角度环直线行驶

		gyro_out_func(exp_acc); // 角速度PID计算
		speed_pid_func(aim_speed, gyro_out);
		Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
		break;
	case 11://测试用角度环循迹行驶

		// lose_line_cond();
		// if (fsm != 11)
		// {
		// 	break;
		// }
		// cross_cond();
		// if (fsm != 11)
		// {
		// 	break;
		// }

		pid_errorspeed_func(); // ADC误差速度PID计算
		gyro_out_func(pid_errorspeed);
		speed_pid_func(aim_speed, gyro_out);
		Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
		break;

	case 12:
		PID_Steering_Kp = PID_Steering_Kp_set;

		//speed_pid_func(aim_speed, PID_Steering(exp_yaw_1, yaw));

		angle_turn_process(exp_yaw_1);
		//motor_left_PIDduty = -pid_calc(&app_motor_left_pid, count_left, aim_speed + PID_Steering(exp_yaw_1, yaw));
		//motor_right_PIDduty = pid_calc(&app_motor_right_pid, count_right, aim_speed - PID_Steering(exp_yaw_1, yaw));
		Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出

	case 13:
		adcmax_calibration();
		break;
	default:
		break;
	}
}
