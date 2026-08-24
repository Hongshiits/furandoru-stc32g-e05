#include "encoder.h"


int16 count_left = 0;
int16 count_right = 0;
float speed_left = 0;
float speed_right = 0;

int16 encoder_data_dir_1 = 0;
int16 encoder_data_dir_2 = 0;

int8 dl=-1;
int8 dr=-1;

void pt_encoder_init()
{
    encoder_dir_init(ENCODER_DIR_1, ENCODER_DIR_PULSE_1, ENCODER_DIR_DIR_1);   	// 初始化编码器模块与引脚 带方向增量编码器模式
    encoder_dir_init(ENCODER_DIR_2, ENCODER_DIR_PULSE_2, ENCODER_DIR_DIR_2);    // 初始化编码器模块与引脚 带方向增量编码器模式
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为编码器获取数据及清除函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
void encoder_getdata(void)
{
    encoder_data_dir_1 = encoder_get_count(ENCODER_DIR_1);    
    encoder_data_dir_2 = encoder_get_count(ENCODER_DIR_2);              

	count_left = encoder_data_dir_2 * dl;
	count_right = -encoder_data_dir_1 * dr;

//	speed_left = 640*PI*count_left/23210/5;
//	speed_right = 640*PI*count_right/23210/5;
    encoder_clear_count(ENCODER_DIR_1);
    encoder_clear_count(ENCODER_DIR_2);
}
