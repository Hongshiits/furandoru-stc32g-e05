#include "eeprom.h"


volatile uint8 GO_enable_value=0;
volatile uint8 EEPROM_write_enable_value=0;
uint32 GO_enable_count=0;


//30速度pid参数		20  0 	160
								//24	0		35
// 80 0 80 入环
//uint8 errorspeed_pid_buff[] 	= {76,0,80};//原本，速度大了后得细条，加数量级
uint8 errorspeed_pid_buff[] = {128,0,115};//240    
// 142,225,260  147,236,270  152,245,280
uint8 round_pid_buff[]          = {0,200};
//30速度pid参7
//uint8 motor_left_pid_buff[] 	= {62,50,0};			  //P   I   D			P缩小10倍，I缩小10倍,D缩小10倍
//uint8 motor_right_pid_buff[] 	= {60,36,0};				//P   I   D  I和D缩小10倍
//uint8 motor_left_pid_buff[] 	= {62,50,0};			  //P   I   D			P缩小10倍，I缩小10倍,D缩小10倍
//uint8 motor_right_pid_buff[] 	= {60,36,0};				//P   I   D  I和D缩小10倍
//uint8 D_Sratio_turn_buff[] 	= {35,110,35};			  //P   I   D  I和D缩小10倍
uint8 D_Sratio_turn_buff[] 	= {29,128,37};
//uint8 motor_right_pid_buff[] 	= {132,108,0};				//P   I   D  I和D缩小10倍
uint8 aim_speed_buff[] = {20};   //为目标速度的0.5倍  原120
uint8 gogogogo_buf[] = {0};
uint8 Direction  = 0;
void eeprom_init()
{
	iap_init();			//初始化EEPROM
//----
	//由于EEPROM掉电不失真，因此写数据只需写一次即可
	if(EEPROM_write_enable)
	{
		printf("EEPROM write enable, writing data...\n");
		iap_erase_page(0);
		extern_iap_write_buff(0x00,errorspeed_pid_buff,3);
		extern_iap_write_buff(0x05,D_Sratio_turn_buff,3);
		extern_iap_write_buff(0x08,aim_speed_buff,1);
		extern_iap_write_buff(0x09,round_pid_buff,2);

	}
//----
	iap_read_buff(0x00,&errorspeed_pid.temp_KP,1);
	iap_read_buff(0x01,&errorspeed_pid.temp_KI,1);
	iap_read_buff(0x02,&errorspeed_pid.temp_KD,1);
	iap_read_buff(0x05,&turn.temp_A,1);
	iap_read_buff(0x06,&turn.temp_B,1);
	iap_read_buff(0x07,&turn.temp_C,1);
	iap_read_buff(0x08,&temp_aim_speed,1);
	iap_read_buff(0x09,&round_pid.temp_KP,1);
	iap_read_buff(0x0A,&round_pid.temp_KD,1);

//	iap_read_bytes(0x0C,&motor_right_pid.temp_KD,1);
	

}

void force_read_eeprom(){
	errorspeed_pid.temp_KP=errorspeed_pid_buff[0];
	errorspeed_pid.temp_KI=errorspeed_pid_buff[1];
	errorspeed_pid.temp_KD=errorspeed_pid_buff[2];
	turn.temp_A=D_Sratio_turn_buff[0];
	turn.temp_B=D_Sratio_turn_buff[1];
	turn.temp_C=D_Sratio_turn_buff[2];
	temp_aim_speed=aim_speed_buff[0];
	round_pid.temp_KP=round_pid_buff[0];
	round_pid.temp_KD=round_pid_buff[1];

}