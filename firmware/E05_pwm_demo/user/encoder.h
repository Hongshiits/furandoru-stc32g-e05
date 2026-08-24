#ifndef ENCODER_H
#define ENCODER_H

#include "pt_headfile.h"

#define ENCODER_DIR_1                 	(PWMA_ENCODER)              // 带方向编码器对应使用的编码器接口 
#define ENCODER_DIR_PULSE_1            	(PWMA_ENCODER_CH1P_P60)     // PULSE 对应的引脚
#define ENCODER_DIR_DIR_1              	(PWMA_ENCODER_CH2P_P62)     // DIR 对应的引脚

#define ENCODER_DIR_2                 	(PWMC_ENCODER)              // 带方向编码器对应使用的编码器接口
#define ENCODER_DIR_PULSE_2       		(PWMC_ENCODER_CH1P_P40)     // PULSE 对应的引脚
#define ENCODER_DIR_DIR_2           	(PWMC_ENCODER_CH2P_P42)     // DIR 对应的引脚



// #define ENCODER_1                 	(TIM10_ENCODER)              // 带方向编码器对应使用的编码器接口 
// #define ENCODER_PULSE_1            	(TIM10_ENCODER_CH1_P60)     // PULSE 对应的引脚
// #define ENCODER_DIR_1              	(IO_P62)     // DIR 对应的引脚

// #define ENCODER_2                 	(PWMC_ENCODER)              // 带方向编码器对应使用的编码器接口
// #define ENCODER_PULSE_2       		(PWMC_ENCODER_CH1P_P40)     // PULSE 对应的引脚
// #define ENCODER_DIR_2           	(PWMC_ENCODER_CH2P_P42)     // DIR 对应的引脚


#define	ENCODER_RIGHT       ENCODER_DIR_PULSE_1	
#define	ENCODER_LEFT	    ENCODER_DIR_PULSE_2

#define DIR_RIGHT			ENCODER_DIR_DIR_1
#define DIR_LEFT			ENCODER_DIR_DIR_2

extern int16 count_left;
extern int16 count_right;
extern float speed_left;
extern float speed_right;

extern int16 encoder_data_dir_1;
extern int16 encoder_data_dir_2;

extern int8 dl;
extern int8 dr;

void pt_encoder_init(void);
void encoder_getdata(void);

#endif

/*
	D车
	编码器齿轮数为30、外径19.2
	外齿轮的齿轮数为68
	编码器转一圈为1024个脉冲数
	外齿轮转一圈为：68/30*1024 = 2321个脉冲数
	轮胎直径为：64mm = 0.64m
	定时器1ms检测一次
	记1ms内检测到的脉冲数为：n(n0*10)
	则车轮经过的距离为：d = n*PI*0.64/23210
	则车速为：d/1ms = 640*PI*n/23210(m/s)
	2m/s:n = 23
	3m/s:n = 35
*/