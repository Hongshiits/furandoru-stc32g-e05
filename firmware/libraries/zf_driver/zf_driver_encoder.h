/*********************************************************************************************************************
* STC32G Opensourec Library 即（STC32G 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2025 SEEKFREE 逐飞科技
*
* 本文件是STC32G144K开源库的一部分
*
* STC32G 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK FOR C251
* 适用平台          STC32G144K
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者           备注
* 2024-08-01        大W            first version
********************************************************************************************************************/

#ifndef __ZF_ENCODER_H
#define __ZF_ENCODER_H
#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"
#include "zf_driver_pwm.h"
#include "zf_driver_timer.h"

// PWM_ENCODER
// BIT[15:13]   : 0->PWMA 1->PWMB 2->PWMC 3-PWMD 4-PWME 5-PWMF 6-TIM
// BIT[12:11]  	: 0->CH1 1->CH2 2->CH3 3->CH4
// BIT[10]		: 0->P 1->N
// BIT[9:8]	    : 0->PS0 1->PS1 2->PS2 3->PS3
// BIT[7:0]		: IO_PIN

// TIM_ENCODER
// BIT[15:13]   : 0->PWMA 1->PWMB 2->PWMC 3-PWMD 4-PWME 5-PWMF 6-TIM
// BIT[12:11]  	: RESERVE
// BIT[10:8]	: 0->CH1 1->CH2 2->CH3 3->CH4
// BIT[7:0]		: IO_PIN

typedef enum    // PWM引脚枚举
{
    // PWMA、PWMB、PWMC、PWMD、PWME、PWMF是六组不同的PWM
    PWMA_ENCODER_CH1P_P10 = PWMA_CH1P_P10,
    PWMA_ENCODER_CH1P_P20 = PWMA_CH1P_P20,
    PWMA_ENCODER_CH1P_P60 = PWMA_CH1P_P60,
                            
    PWMA_ENCODER_CH2P_P54 = PWMA_CH2P_P54,
    PWMA_ENCODER_CH2P_P22 = PWMA_CH2P_P22,
    PWMA_ENCODER_CH2P_P62 = PWMA_CH2P_P62,
	                                         
    PWMB_ENCODER_CH1_P20  = PWMB_CH1_P20 ,
    PWMB_ENCODER_CH1_P17  = PWMB_CH1_P17 ,
    PWMB_ENCODER_CH1_P00  = PWMB_CH1_P00 ,
    PWMB_ENCODER_CH1_P74  = PWMB_CH1_P74 ,
                                          
    PWMB_ENCODER_CH2_P21  = PWMB_CH2_P21 ,
    PWMB_ENCODER_CH2_P54  = PWMB_CH2_P54 ,
    PWMB_ENCODER_CH2_P01  = PWMB_CH2_P01 ,
    PWMB_ENCODER_CH2_P75  = PWMB_CH2_P75 ,
                                               
    PWMC_ENCODER_CH1P_P60 = PWMC_CH1P_P60, 
    PWMC_ENCODER_CH1P_P80 = PWMC_CH1P_P80, 
    PWMC_ENCODER_CH1P_P40 = PWMC_CH1P_P40, 
    PWMC_ENCODER_CH1P_PB0 = PWMC_CH1P_PB0, 
                                                      
    PWMC_ENCODER_CH2P_P62 = PWMC_CH2P_P62, 
    PWMC_ENCODER_CH2P_P82 = PWMC_CH2P_P82, 
    PWMC_ENCODER_CH2P_P42 = PWMC_CH2P_P42, 
    PWMC_ENCODER_CH2P_PB2 = PWMC_CH2P_PB2, 
                                         
    PWMD_ENCODER_CH1_P24  = PWMD_CH1_P24 ,
    PWMD_ENCODER_CH1_P81  = PWMD_CH1_P81 ,
    PWMD_ENCODER_CH1_P50  = PWMD_CH1_P50 ,
    PWMD_ENCODER_CH1_PB4  = PWMD_CH1_PB4 ,
                                           
    PWMD_ENCODER_CH2_P25  = PWMD_CH2_P25 ,
    PWMD_ENCODER_CH2_P83  = PWMD_CH2_P83 ,
    PWMD_ENCODER_CH2_P51  = PWMD_CH2_P51 ,
    PWMD_ENCODER_CH2_PB5  = PWMD_CH2_PB5 ,
                                         
    PWME_ENCODER_CH1P_P70 = PWME_CH1P_P70, 
    PWME_ENCODER_CH1P_P90 = PWME_CH1P_P90, 
    PWME_ENCODER_CH1P_PA0 = PWME_CH1P_PA0, 
                                         
    PWME_ENCODER_CH2P_P72 = PWME_CH2P_P72, 
    PWME_ENCODER_CH2P_P92 = PWME_CH2P_P92, 
    PWME_ENCODER_CH2P_PA2 = PWME_CH2P_PA2, 
                                         
    PWMF_ENCODER_CH1_P70  = PWMF_CH1_P70 ,
    PWMF_ENCODER_CH1_PA1  = PWMF_CH1_PA1 ,
    PWMF_ENCODER_CH1_P90  = PWMF_CH1_P90 ,
                                          
    PWMF_ENCODER_CH2_P71  = PWMF_CH2_P71 ,
    PWMF_ENCODER_CH2_PA3  = PWMF_CH2_PA3 ,
    PWMF_ENCODER_CH2_P91  = PWMF_CH2_P91 ,


    TIM0_ENCODER_CH1_P34  = 6<<13|0<<8|IO_P34,
                                           
    TIM1_ENCODER_CH1_P35  = 6<<13|0<<8|IO_P35,
                                           
	TIM2_ENCODER_CH1_P12  = 6<<13|0<<8|IO_P12,
                                           
	TIM3_ENCODER_CH1_P04  = 6<<13|0<<8|IO_P04,
    // 暂不支持 TIM3_ENCODER_CH2_P00  = 6<<13|1<<8|IO_P00,
                                           
	TIM4_ENCODER_CH1_P06  = 6<<13|0<<8|IO_P06,
	// 暂不支持 TIM4_ENCODER_CH2_P02  = 6<<13|1<<8|IO_P02,
                                           
	TIM5_ENCODER_CH1_P20  = 6<<13|0<<8|IO_P20,
                                           
    TIM6_ENCODER_CH1_P22  = 6<<13|0<<8|IO_P22,
                                           
    TIM7_ENCODER_CH1_P24  = 6<<13|0<<8|IO_P24,
                                           
    TIM8_ENCODER_CH1_P26  = 6<<13|0<<8|IO_P26,
                                           
    TIM9_ENCODER_CH1_P70  = 6<<13|0<<8|IO_P70,
    // 暂不支持 TIM9_ENCODER_CH1_PB0  = 6<<13|0<<8|IO_PB0,

    TIM10_ENCODER_CH1_P60 = 6<<13|0<<8|IO_P60,
    // 暂不支持 TIM10_ENCODER_CH2_PB6 = 6<<13|1<<8|IO_PB6,
                                           
    TIM11_ENCODER_CH1_P76 = 6<<13|0<<8|IO_P76,
    // 暂不支持 TIM11_ENCODER_CH2_P14 = 6<<13|1<<8|IO_P14,
    // 暂不支持 TIM11_ENCODER_CH3_PA6 = 6<<13|2<<8|IO_PA6,
    // 暂不支持 TIM11_ENCODER_CH4_P44 = 6<<13|3<<8|IO_P44,
                                           
    TIM17_ENCODER_CH1_P80 = 6<<13|0<<8|IO_P80,
                                           
    TIM18_ENCODER_CH1_P90 = 6<<13|0<<8|IO_P90,

}encoder_channel_enum;

typedef enum
{
    PWMA_ENCODER = 0x0000 , 			// 支持正交编码器和带方向编码器
    PWMB_ENCODER = 0x0001 , 			// 支持正交编码器和带方向编码器
    PWMC_ENCODER = 0x0002 , 			// 支持正交编码器和带方向编码器
    PWMD_ENCODER = 0x0003 , 			// 支持正交编码器和带方向编码器
    PWME_ENCODER = 0x0004 , 			// 支持正交编码器和带方向编码器
    PWMF_ENCODER = 0x0005 , 			// 支持正交编码器和带方向编码器
				
    TIM0_ENCODER  = 0x1000 | TIM_0,    	// 仅支持带方向编码器
    TIM1_ENCODER  = 0x1000 | TIM_1,    	// 仅支持带方向编码器
    TIM2_ENCODER  = 0x1000 | TIM_2,    	// 仅支持带方向编码器
    TIM3_ENCODER  = 0x1000 | TIM_3,    	// 仅支持带方向编码器
    TIM4_ENCODER  = 0x1000 | TIM_4,    	// 仅支持带方向编码器
    TIM5_ENCODER  = 0x1000 | TIM_5,    	// 仅支持带方向编码器
    TIM6_ENCODER  = 0x1000 | TIM_6,    	// 仅支持带方向编码器
    TIM7_ENCODER  = 0x1000 | TIM_7,    	// 仅支持带方向编码器
    TIM8_ENCODER  = 0x1000 | TIM_8,    	// 仅支持带方向编码器
    TIM9_ENCODER  = 0x1000 | TIM_9,    	// 仅支持带方向编码器
    TIM10_ENCODER = 0x1000 | TIM_10,   	// 仅支持带方向编码器
    TIM11_ENCODER = 0x1000 | TIM_11,   	// 仅支持带方向编码器
    TIM17_ENCODER = 0x1000 | TIM_17,   	// 仅支持带方向编码器
    TIM18_ENCODER = 0x1000 | TIM_18,   	// 仅支持带方向编码器
}encoder_index_enum;

int16   encoder_get_count   (encoder_index_enum encoder_n);
void    encoder_clear_count (encoder_index_enum encoder_n);
void    encoder_quad_init   (encoder_index_enum encoder_n, encoder_channel_enum ch1_pin, encoder_channel_enum ch2_pin);
void    encoder_dir_init    (uint16 encoder_n, uint16 lsb_pin, uint16 dir_pin);
#endif
