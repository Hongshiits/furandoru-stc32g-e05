#include "isr_leg.h"



uint8 goflag = 0;
D_Sratio turn;
uint32 count_time_w = 0;
int cnt1 = 0;
float adc_data[5] = {0};
float adc_ordata[5] = {0};
float aim_speed = 0;
uint8 temp_aim_speed = 0;
float adc_ecs[2] = {0};
float window[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float filtered_data[4] = {0, 0, 0, 0};
float time_dida = 0;
float time_dadi = 0;


float sum_adc = 0;
int flag = 0;

int D_flag = 0;
int F_flag = 0;
int K_flag = 0;
int P_flag = 0;
uint32 FA_COUNT = 0;
/*直线差比和系数*/ // 3、10、1.5
float A_ahead = 6;
float B_ahead = 6;
float C_ahead = 1.5;
float Lim_ahead = 9;
float Error_ahead = 0;

/*转弯差比和系数*/
float A_Turn = 3.5; // 6
float B_Turn = 11;
float C_Turn = 3.5; // 1.5;
float Lim_Turn = 3;
float Error_Turn = 0;

float Error_Turn_round = 0;

/*十字路口出差比和算法*/
float A_Cross = 6; // 6
float B_Cross = 0; // 1
float C_Cross = 0;
float Lim_Cross = 0;
float Error_Cross = 0;

/*圆环进环差比和算法*/
float A_Roundabout_in = 5;
float B_Roundabout_in = 15;
float C_Roundabout_in = 1.5;
float Lim_Roundabout_in = 9;
float Error_Roundabout_in = 0;

/*圆环出环差比和算法*/
float A_Roundabout_out = 15;  // 10
float B_Roundabout_out = 5;	  // 5
float C_Roundabout_out = 1.5; // 3
float Lim_Roundabout_out = 6;
float Error_Roundabout_out = 0;

/*十字内差比和算法*/
float A_Cross_2 = 5;
float B_Cross_2 = 8;
float C_Cross_2 = 1.5;
float Lim_Cross_2 = 6;
float Error_Cross_2 = 0;
void clear_gryo(void)
{
	yaw = 0;
	pitch = 0;
}


void TM4_Isr_lega()
{
	
	sensor_capture(); // 传感器数据采集和处理	

	// 04.状态机的实时状态确定


	//printf("isr leg3\n");

	if(GO_enable)
	{
		if (battery_voltage_data > 12.8)
		{
			K_flag = 1;
		}
		if ((K_flag == 1) && (F_flag == 0) && (P_flag == 0))
		{
			if (F_flag == 0)
			{
				Motor_act(4000, 4000);
				FA_COUNT++;
			}
			if (FA_COUNT >= 80)
			{
				Motor_act(0, 0);
				P_flag = 1;
			}
			if ((adc_data[1] > 50) && (adc_data[2] > 50))
			{
				// Motor_act(0, 0);
				F_flag = 1;
			}
		}
		if ((F_flag == 1) && (flag == 0))
		{
			track_line();
		}
		if (flag == 1)
		{
			Fsm_process(); // 状态机函数
		}
	}
	else
	{
		Motor_act(0, 0);
	}

	//	ccd_collect();	 //CCD采集数据
}



void track_line(){
	if (Direction == 1)
	{ // 逆时针  向右拐
		PID_Steering_Kp = 50;
		motor_left_pid.SetValue = aim_speed + PID_Steering(3, yaw);
		motor_right_pid.SetValue = aim_speed - PID_Steering(3, yaw);
		motor_left_PIDduty = Motor_left_pid_calculate();
		motor_right_PIDduty = Motor_right_pid_calculate();
		Motor_act(motor_left_PIDduty, motor_right_PIDduty);
		if ((fabs(yaw) > 2.5))
		{
			flag = 1;
		}
	}
	if (Direction == 2)
	{ // 顺时针   向左拐
		PID_Steering_Kp = 50;
		motor_left_pid.SetValue = aim_speed + PID_Steering(-3, yaw);
		motor_right_pid.SetValue = aim_speed - PID_Steering(-3, yaw);
		motor_left_PIDduty = Motor_left_pid_calculate();
		motor_right_PIDduty = Motor_right_pid_calculate();
		Motor_act(motor_left_PIDduty, motor_right_PIDduty);
		if ((fabs(yaw) > 2.5))
		{
			flag = 1;
		}
	}
}



void sensor_capture(){
	float turn_a;
	float turn_b;
	float turn_c;
	float turn_num;
	float turn_den;
		//printf("isr leg1\n");
	adc_getdata();
	encoder_getdata();
	time_dadi++;
	count_time_w++;

	
	imu_process();
	//gyro_process();
	//	cnt1++;

	//	    sum_adc = filtered_data[0] + filtered_data[1] + filtered_data[2] + filtered_data[3];
	//		/*直线差和*/
	//		Error_ahead = ( (A_ahead*(filtered_data[0]-filtered_data[3]) + B_ahead*(filtered_data[1]-filtered_data[2]))
	//		/ ((filtered_data[0]+filtered_data[3]) + C_ahead*abs(filtered_data[1]-filtered_data[2])) ) ;
	/*转弯差比和*/
	//		Error_Turn = ( (A_Turn*(filtered_data[0]-filtered_data[3]) + B_Turn*(filtered_data[1]-filtered_data[2]))
	//		/ (A_Turn*(filtered_data[0]+filtered_data[3]) + C_Turn*fabs(filtered_data[1]-filtered_data[2])) )
	//		*Lim_Turn;
	// Error_Turn = (
    // 	(
    //     	turn.A / 10 * (ADC_DATA_LV - ADC_DATA_RV) + 
    //     	turn.B / 10 * (ADC_DATA_LH - ADC_DATA_RH)
    // 	) / (
    //     	turn.A / 10 * (ADC_DATA_LV + ADC_DATA_RV) + 
    //     	turn.C / 10 * (ADC_DATA_LH + ADC_DATA_RH)+
	// 		ADC_DATA_MD
    // 	)
	// ) * Lim_Turn;
	turn_a = turn.A / 10.0;
	turn_b = turn.B / 10.0;
	turn_c = turn.C / 10.0;
	turn_num = turn_a * (ADC_DATA_LV - ADC_DATA_RV) +
		turn_b * (ADC_DATA_LH - ADC_DATA_RH);
	turn_den = turn_a * (ADC_DATA_LV + ADC_DATA_RV) +
		turn_b * (ADC_DATA_LH + ADC_DATA_RH) +
		turn_c * fabs(ADC_DATA_LH - ADC_DATA_RH) +
		md_turn_weight * ADC_DATA_MD +
		1.0;
	Error_Turn = turn_num / turn_den * Lim_Turn;

	turn_num = turn_a * (ADC_DATA_LV - ADC_DATA_RV) ;
	turn_den = turn_a * (ADC_DATA_LV + ADC_DATA_RV) +
		md_turn_weight * ADC_DATA_MD +
		1.0;

	Error_Turn_round = turn_num / turn_den * Lim_Turn;
	//	Error_Turn = ( (A_Turn*(filtered_data[0]-filtered_data[3]) + B_Turn*(filtered_data[1]-filtered_data[2]))
	//	/ (C_Turn*(filtered_data[0]+filtered_data[3]) + (filtered_data[1]+filtered_data[2])) )
	//	*Lim_Turn;
	//	/*十字路口出入差比和*/
	//	Error_Cross = ( (A_Cross*(filtered_data[0]-filtered_data[3]) + B_Cross*(filtered_data[1]-filtered_data[2]))
	//	/ (A_Cross*(filtered_data[0]+filtered_data[3]) + C_Cross*fabs(filtered_data[1]-filtered_data[2])) )
	//	*Lim_Cross;
	//		Error_Cross = (A_Cross*(filtered_data[0]-filtered_data[3])/(filtered_data[0]+filtered_data[3]));
	//		/*十字内差比和*/
	//		Error_Cross_2 = ( (A_Cross_2*(filtered_data[0]-filtered_data[3]) + B_Cross_2*(filtered_data[1]-filtered_data[2]))
	//		/ (A_Cross_2*(filtered_data[0]+filtered_data[3]) + C_Cross_2*fabs(filtered_data[1]-filtered_data[2])) )
	//		*Lim_Cross;
	//		/*环岛进环差比和*/
	//		Error_Roundabout_in = ( (A_Roundabout_in*(filtered_data[0]-filtered_data[3]) + B_Roundabout_in*(filtered_data[1]-filtered_data[2]))
	//		/ (A_Roundabout_in*(filtered_data[0]+filtered_data[3]) + C_Roundabout_in*fabs(filtered_data[1]-filtered_data[2])) )
	//		*Lim_Roundabout_in;
	//		/*环岛出环差比和*/
	//		Error_Roundabout_out = ( (A_Roundabout_out*(filtered_data[0]-filtered_data[3]) + B_Roundabout_out*(filtered_data[1]-filtered_data[2]))
	//		/ (A_Roundabout_out*(filtered_data[0]+filtered_data[3]) + C_Roundabout_out*fabs(filtered_data[1]-filtered_data[2])) )
	//		*Lim_Roundabout_out;
}