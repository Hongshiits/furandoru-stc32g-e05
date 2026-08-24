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

#ifndef __ZF_DRIVER_PWM_H
#define __ZF_DRIVER_PWM_H
#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"



// 新的16位
// BIT[15:13]   : 0->PWMA 1->PWMB 2->PWMC 3-PWMD 4-PWME 5-PWMF 6-TIM
// BIT[12:11]  	: 0->CH1 1->CH2 2->CH3 3->CH4
// BIT[10]		: 0->P 1->N
// BIT[9:8]	    : 0->PS0 1->PS1 2->PS2 3->PS3
// BIT[7:0]		: IO_PIN
	

// 旧的16位
// BIT[15] 		: 0->PWMA 1->PWMB
// BIT[14:12]  	: 0->CH1 1->CH2 2->CH3 3->CH4 4->CH5 5->CH6
// BIT[11]		: 0->P 1->N
// BIT[10:9]	: 0->PS0 1->PS1 2->PS2 3->PS3
// BIT[7:0]		: IO_PIN

typedef enum
{
    // PWMA、PWMB、PWMC、PWMD、PWME、PWMF是六组不同的PWM
    
    // 以下是PWMA通道，初始化只能有一个频率
    // 同一组PWM，同一时刻，只能有同一个PWM输出。
    // 例如:PWMA_CH1P_P10 和 PWMA_CH1N_P11不能一起输出。
	// 但是不同的通道可以同一时刻输出。
    // 例如:PWMA_CH1P_P10 和 PWMA_CH2N_P03 可以同时输出
    PWMA_CH1P_P10 = 0<<13|0<<11|0<<10|0<<8|IO_P10, PWMA_CH1N_P11 = 0<<13|0<<11|1<<10|0<<8|IO_P11,
    PWMA_CH1P_P20 = 0<<13|0<<11|0<<10|1<<8|IO_P20, PWMA_CH1N_P21 = 0<<13|0<<11|1<<10|1<<8|IO_P21,
    PWMA_CH1P_P60 = 0<<13|0<<11|0<<10|2<<8|IO_P60, PWMA_CH1N_P61 = 0<<13|0<<11|1<<10|2<<8|IO_P61,
																	                         	
    PWMA_CH2P_P54 = 0<<13|1<<11|0<<10|0<<8|IO_P54, PWMA_CH2N_P13 = 0<<13|1<<11|1<<10|0<<8|IO_P13,
    PWMA_CH2P_P22 = 0<<13|1<<11|0<<10|1<<8|IO_P22, PWMA_CH2N_P23 = 0<<13|1<<11|1<<10|1<<8|IO_P23,
    PWMA_CH2P_P62 = 0<<13|1<<11|0<<10|2<<8|IO_P62, PWMA_CH2N_P63 = 0<<13|1<<11|1<<10|2<<8|IO_P63,
																		                     	
    PWMA_CH3P_P14 = 0<<13|2<<11|0<<10|0<<8|IO_P14, PWMA_CH3N_P15 = 0<<13|2<<11|1<<10|0<<8|IO_P15,
    PWMA_CH3P_P24 = 0<<13|2<<11|0<<10|1<<8|IO_P24, PWMA_CH3N_P25 = 0<<13|2<<11|1<<10|1<<8|IO_P25,
    PWMA_CH3P_P64 = 0<<13|2<<11|0<<10|2<<8|IO_P64, PWMA_CH3N_P65 = 0<<13|2<<11|1<<10|2<<8|IO_P65,
																                             	
    PWMA_CH4P_P16 = 0<<13|3<<11|0<<10|0<<8|IO_P16, PWMA_CH4N_P17 = 0<<13|3<<11|1<<10|0<<8|IO_P17,
    PWMA_CH4P_P26 = 0<<13|3<<11|0<<10|1<<8|IO_P26, PWMA_CH4N_P27 = 0<<13|3<<11|1<<10|1<<8|IO_P27,
    PWMA_CH4P_P66 = 0<<13|3<<11|0<<10|2<<8|IO_P66, PWMA_CH4N_P67 = 0<<13|3<<11|1<<10|2<<8|IO_P67,
    PWMA_CH4P_P34 = 0<<13|3<<11|0<<10|3<<8|IO_P34, PWMA_CH4N_P33 = 0<<13|3<<11|1<<10|3<<8|IO_P33,

    // PWMA_CH5_P46 = 0<<13|4<<11|0<<10|0<<8|IO_P46,
    // PWMA_CH5_P04 = 0<<13|4<<11|0<<10|1<<8|IO_P04,
    // PWMA_CH5_P72 = 0<<13|4<<11|0<<10|2<<8|IO_P72,
    // PWMA_CH5_P13 = 0<<13|4<<11|0<<10|3<<8|IO_P13,
                                             
    // PWMA_CH6_P47 = 0<<13|5<<11|0<<10|0<<8|IO_P47,
    // PWMA_CH6_P05 = 0<<13|5<<11|0<<10|1<<8|IO_P05,
    // PWMA_CH6_P73 = 0<<13|5<<11|0<<10|2<<8|IO_P73,
    // PWMA_CH6_P15 = 0<<13|5<<11|0<<10|3<<8|IO_P15,
            
    // 以下是PWMB通道，初始化只能有一个频率
    // 同一组PWM，同一时刻，只能有同一个PWM输出。
    // 例如:PWMB_CH1_P01 和 PWMB_CH1_P21 不能同时输出
    // 但是不同的通道可以同一时刻输出。
    // 例如:PWMB_CH1_P01 和 PWMB_CH2_P13 可以同时输出
    PWMB_CH1_P20 = 1<<13|0<<11|0<<10|0<<8|IO_P20,
    PWMB_CH1_P17 = 1<<13|0<<11|0<<10|1<<8|IO_P17,
    PWMB_CH1_P00 = 1<<13|0<<11|0<<10|2<<8|IO_P00,
    PWMB_CH1_P74 = 1<<13|0<<11|0<<10|3<<8|IO_P74,
                                             
    PWMB_CH2_P21 = 1<<13|1<<11|0<<10|0<<8|IO_P21,
    PWMB_CH2_P54 = 1<<13|1<<11|0<<10|1<<8|IO_P54,
    PWMB_CH2_P01 = 1<<13|1<<11|0<<10|2<<8|IO_P01,
    PWMB_CH2_P75 = 1<<13|1<<11|0<<10|3<<8|IO_P75,
                                             
    PWMB_CH3_P22 = 1<<13|2<<11|0<<10|0<<8|IO_P22,
    PWMB_CH3_P33 = 1<<13|2<<11|0<<10|1<<8|IO_P33,
    PWMB_CH3_P02 = 1<<13|2<<11|0<<10|2<<8|IO_P02,
    PWMB_CH3_P76 = 1<<13|2<<11|0<<10|3<<8|IO_P76,
                                             
    PWMB_CH4_P23 = 1<<13|3<<11|0<<10|0<<8|IO_P23,
    PWMB_CH4_P34 = 1<<13|3<<11|0<<10|1<<8|IO_P34,
    PWMB_CH4_P03 = 1<<13|3<<11|0<<10|2<<8|IO_P03,
    PWMB_CH4_P77 = 1<<13|3<<11|0<<10|3<<8|IO_P77,
    
    // 以下是PWMC通道，初始化只能有一个频率
    // 同一组PWM，同一时刻，只能有同一个PWM输出。
    // 例如:PWMC_CH1P_P60 和 PWMC_CH1N_P81 不能同时输出
    // 但是不同的通道可以同一时刻输出。
    // 例如:PWMC_CH1P_PB0 和 PWMC_CH2P_P62 可以同时输出
    PWMC_CH1P_P60 = 2<<13|0<<11|0<<10|0<<8|IO_P60, PWMC_CH1N_P61 = 2<<13|0<<11|1<<10|0<<8|IO_P61,
    PWMC_CH1P_P80 = 2<<13|0<<11|0<<10|1<<8|IO_P80, PWMC_CH1N_P81 = 2<<13|0<<11|1<<10|1<<8|IO_P81,
    PWMC_CH1P_P40 = 2<<13|0<<11|0<<10|2<<8|IO_P40, PWMC_CH1N_P41 = 2<<13|0<<11|1<<10|2<<8|IO_P41,	
    PWMC_CH1P_PB0 = 2<<13|0<<11|0<<10|3<<8|IO_PB0, PWMC_CH1N_PB1 = 2<<13|0<<11|1<<10|3<<8|IO_PB1,
                                                                                              
    PWMC_CH2P_P62 = 2<<13|1<<11|0<<10|0<<8|IO_P62, PWMC_CH2N_P63 = 2<<13|1<<11|1<<10|0<<8|IO_P63,
    PWMC_CH2P_P82 = 2<<13|1<<11|0<<10|1<<8|IO_P82, PWMC_CH2N_P83 = 2<<13|1<<11|1<<10|1<<8|IO_P83,
    PWMC_CH2P_P42 = 2<<13|1<<11|0<<10|2<<8|IO_P42, PWMC_CH2N_P43 = 2<<13|1<<11|1<<10|2<<8|IO_P43,	
    PWMC_CH2P_PB2 = 2<<13|1<<11|0<<10|3<<8|IO_PB2, PWMC_CH2N_PB3 = 2<<13|1<<11|1<<10|3<<8|IO_PB3,
                                                                                              
    PWMC_CH3P_P64 = 2<<13|2<<11|0<<10|0<<8|IO_P64, PWMC_CH2N_P65 = 2<<13|2<<11|1<<10|0<<8|IO_P65,
    PWMC_CH3P_P84 = 2<<13|2<<11|0<<10|1<<8|IO_P84, PWMC_CH2N_P85 = 2<<13|2<<11|1<<10|1<<8|IO_P85,
    PWMC_CH3P_P44 = 2<<13|2<<11|0<<10|2<<8|IO_P44, PWMC_CH2N_P45 = 2<<13|2<<11|1<<10|2<<8|IO_P45,	
    PWMC_CH3P_PB4 = 2<<13|2<<11|0<<10|3<<8|IO_PB4, PWMC_CH2N_PB5 = 2<<13|2<<11|1<<10|3<<8|IO_PB5,
                                                                                              
    PWMC_CH4P_P66 = 2<<13|3<<11|0<<10|0<<8|IO_P66, PWMC_CH3N_P67 = 2<<13|3<<11|1<<10|0<<8|IO_P67,
    PWMC_CH4P_P86 = 2<<13|3<<11|0<<10|1<<8|IO_P86, PWMC_CH3N_P87 = 2<<13|3<<11|1<<10|1<<8|IO_P87,
    PWMC_CH4P_P46 = 2<<13|3<<11|0<<10|2<<8|IO_P46, PWMC_CH3N_P47 = 2<<13|3<<11|1<<10|2<<8|IO_P47,
    PWMC_CH4P_PB6 = 2<<13|3<<11|0<<10|3<<8|IO_PB6, PWMC_CH3N_PB7 = 2<<13|3<<11|1<<10|3<<8|IO_PB7,

    // PWMC_CH5_P11 = 2<<13|4<<11|0<<10|0<<8|IO_P11,
    // PWMC_CH5_P36 = 2<<13|4<<11|0<<10|1<<8|IO_P36,
    // PWMC_CH5_P96 = 2<<13|4<<11|0<<10|2<<8|IO_P96,
    // PWMC_CH5_P63 = 2<<13|4<<11|0<<10|3<<8|IO_P63,
                      
    // PWMC_CH6_P17 = 2<<13|5<<11|0<<10|0<<8|IO_P17,
    // PWMC_CH6_P37 = 2<<13|5<<11|0<<10|1<<8|IO_P37,
    // PWMC_CH6_P97 = 2<<13|5<<11|0<<10|2<<8|IO_P97,
    // PWMC_CH6_P65 = 2<<13|5<<11|0<<10|3<<8|IO_P65,

    // 以下是PWMD通道，初始化只能有一个频率
    // 同一组PWM，同一时刻，只能有同一个PWM输出。
    // 例如:PWMD_CH1_P24 和 PWMD_CH1_P50 不能同时输出
    // 但是不同的通道可以同一时刻输出。
    // 例如:PWMD_CH1_P24 和 PWMD_CH2_P83 可以同时输出
    PWMD_CH1_P24 = 3<<13|0<<11|0<<10|0<<8|IO_P24,
    PWMD_CH1_P81 = 3<<13|0<<11|0<<10|1<<8|IO_P81,
    PWMD_CH1_P50 = 3<<13|0<<11|0<<10|2<<8|IO_P50,
    PWMD_CH1_PB4 = 3<<13|0<<11|0<<10|3<<8|IO_PB4,
                                             
    PWMD_CH2_P25 = 3<<13|1<<11|0<<10|0<<8|IO_P25,
    PWMD_CH2_P83 = 3<<13|1<<11|0<<10|1<<8|IO_P83,
    PWMD_CH2_P51 = 3<<13|1<<11|0<<10|2<<8|IO_P51,
    PWMD_CH2_PB5 = 3<<13|1<<11|0<<10|3<<8|IO_PB5,
                                             
    PWMD_CH3_P26 = 3<<13|2<<11|0<<10|0<<8|IO_P26,
    PWMD_CH3_P85 = 3<<13|2<<11|0<<10|1<<8|IO_P85,
    PWMD_CH3_P52 = 3<<13|2<<11|0<<10|2<<8|IO_P52,
    PWMD_CH3_PB6 = 3<<13|2<<11|0<<10|3<<8|IO_PB6,
                                             
    PWMD_CH4_P27 = 3<<13|3<<11|0<<10|0<<8|IO_P27,
    PWMD_CH4_P87 = 3<<13|3<<11|0<<10|1<<8|IO_P87,
    PWMD_CH4_P53 = 3<<13|3<<11|0<<10|2<<8|IO_P53,
    PWMD_CH4_PB7 = 3<<13|3<<11|0<<10|3<<8|IO_PB7,
    
    // 以下是PWME通道，初始化只能有一个频率
    // 同一组PWM，同一时刻，只能有同一个PWM输出。
    // 例如:PWME_CH1P_P70 和 PWME_CH1N_P71 不能同时输出
    // 但是不同的通道可以同一时刻输出。
    // 例如:PWME_CH1P_P70 和 PWME_CH3P_P74 可以同时输出
    PWME_CH1P_P70 = 4<<13|0<<11|0<<10|0<<8|IO_P70, PWME_CH1N_P71 = 4<<13|0<<11|1<<10|0<<8|IO_P71,
    PWME_CH1P_P90 = 4<<13|0<<11|0<<10|1<<8|IO_P90, PWME_CH1N_P91 = 4<<13|0<<11|1<<10|1<<8|IO_P91,
    PWME_CH1P_PA0 = 4<<13|0<<11|0<<10|2<<8|IO_PA0, PWME_CH1N_PA1 = 4<<13|0<<11|1<<10|2<<8|IO_PA1,	

    PWME_CH2P_P72 = 4<<13|1<<11|0<<10|0<<8|IO_P72, PWME_CH2N_P73 = 4<<13|1<<11|1<<10|0<<8|IO_P73,
    PWME_CH2P_P92 = 4<<13|1<<11|0<<10|1<<8|IO_P92, PWME_CH2N_P93 = 4<<13|1<<11|1<<10|1<<8|IO_P93,
    PWME_CH2P_PA2 = 4<<13|1<<11|0<<10|2<<8|IO_PA2, PWME_CH2N_PA3 = 4<<13|1<<11|1<<10|2<<8|IO_PA3,	

    PWME_CH3P_P74 = 4<<13|2<<11|0<<10|0<<8|IO_P74, PWME_CH3N_P75 = 4<<13|2<<11|1<<10|0<<8|IO_P75,
    PWME_CH3P_P94 = 4<<13|2<<11|0<<10|1<<8|IO_P94, PWME_CH3N_P95 = 4<<13|2<<11|1<<10|1<<8|IO_P95,
    PWME_CH3P_PA4 = 4<<13|2<<11|0<<10|2<<8|IO_PA4, PWME_CH3N_PA5 = 4<<13|2<<11|1<<10|2<<8|IO_PA5,	

    PWME_CH4P_P76 = 4<<13|3<<11|0<<10|0<<8|IO_P76, PWME_CH4N_P77 = 4<<13|3<<11|1<<10|0<<8|IO_P77,
    PWME_CH4P_P96 = 4<<13|3<<11|0<<10|1<<8|IO_P96, PWME_CH4N_P97 = 4<<13|3<<11|1<<10|1<<8|IO_P97,
    PWME_CH4P_PA6 = 4<<13|3<<11|0<<10|2<<8|IO_PA6, PWME_CH4N_PA7 = 4<<13|3<<11|1<<10|2<<8|IO_PA7,

    // PWME_CH5_P50 = 4<<13|4<<11|0<<10|0<<8|IO_P50,
    // PWME_CH5_P43 = 4<<13|4<<11|0<<10|1<<8|IO_P43,
    // PWME_CH5_PB4 = 4<<13|4<<11|0<<10|2<<8|IO_PB4,
    // PWME_CH5_P95 = 4<<13|4<<11|0<<10|3<<8|IO_P95,

    // PWME_CH6_P51 = 4<<13|5<<11|0<<10|0<<8|IO_P51,
    // PWME_CH6_P44 = 4<<13|5<<11|0<<10|1<<8|IO_P44,
    // PWME_CH6_PB5 = 4<<13|5<<11|0<<10|2<<8|IO_PB5,
    // PWME_CH6_P97 = 4<<13|5<<11|0<<10|3<<8|IO_P97,
    
    // 以下是PWMF通道，初始化只能有一个频率
    // 同一组PWM，同一时刻，只能有同一个PWM输出。
    // 例如:PWMF_CH1_P70 和 PWMF_CH1_PA1 不能同时输出
    // 但是不同的通道可以同一时刻输出。
    // 例如:PWMF_CH1_P70 和 PWMF_CH2_P71 可以同时输出
    PWMF_CH1_P70 = 5<<13|0<<11|0<<10|0<<8|IO_P70,
    PWMF_CH1_PA1 = 5<<13|0<<11|0<<10|1<<8|IO_PA1,
    PWMF_CH1_P90 = 5<<13|0<<11|0<<10|2<<8|IO_P90,
                                                
    PWMF_CH2_P71 = 5<<13|1<<11|0<<10|0<<8|IO_P71,
    PWMF_CH2_PA3 = 5<<13|1<<11|0<<10|1<<8|IO_PA3,
    PWMF_CH2_P91 = 5<<13|1<<11|0<<10|2<<8|IO_P91,
                                                
    PWMF_CH3_P72 = 5<<13|2<<11|0<<10|0<<8|IO_P72,
    PWMF_CH3_PA5 = 5<<13|2<<11|0<<10|1<<8|IO_PA5,
    PWMF_CH3_P92 = 5<<13|2<<11|0<<10|2<<8|IO_P92,
                                                
    PWMF_CH4_P73 = 5<<13|3<<11|0<<10|0<<8|IO_P73,
    PWMF_CH4_PA7 = 5<<13|3<<11|0<<10|1<<8|IO_PA7,
    PWMF_CH4_P93 = 5<<13|3<<11|0<<10|2<<8|IO_P93,


} pwm_channel_enum;


// 引脚输出选择寄存器
extern const vuint32 PWMX_PS_ADDR[];
// 输出使能寄存器
extern const vuint32 PWMX_ENO_ADDR[];
// 刹车寄存器
extern const vuint32 PWMX_BKR_ADDR[];
// 控制寄存器1
extern const vuint32 PWMX_CR1_ADDR[];
// 捕获比较模式寄存器
extern const vuint32 PWM_CCMR_ADDR[];
// 捕获比较使能寄存器
extern const vuint32 PWM_CCER_ADDR[];	
// 控制寄存器,高8位地址  低8位地址 + 1即可
extern const vuint32 PWM_CCR_ADDR[];
// 控制寄存器,高8位地址  低8位地址 + 1即可
extern const vuint32 PWM_ARR_ADDR[];
// 预分频寄存器,高8位地址  低8位地址 + 1即可
extern const vuint32 PWM_PSCR_ADDR[];
// PWM计数器,高8位地址  低8位地址 + 1即可
extern const vuint32 PWMX_CNTR_ADDR[];
// 从模式控制寄存器
extern const vuint32 PWMX_SMCR_ADDR[];


#define PWMX_PSCRH(pin)		(*(vuint8 far *)(PWM_PSCR_ADDR[(pin >> 13 & 0x7)]))
#define PWMX_PSCRL(pin)		(*(vuint8 far *)(PWM_PSCR_ADDR[(pin >> 13 & 0x7)] + 1))

#define PWMX_CCRXH(pin)		(*(vuint8 far *)(PWM_CCR_ADDR[((pin >> 13 & 0x7) * 4) + (pin >> 11 & 0x3)]))
#define PWMX_CCRXL(pin)		(*(vuint8 far *)(PWM_CCR_ADDR[((pin >> 13 & 0x7) * 4) + (pin >> 11 & 0x3)] + 1))

#define PWMX_ARRH(pin)		(*(vuint8 far *)(PWM_ARR_ADDR[(pin >> 13 & 0x7)]))
#define PWMX_ARRL(pin)		(*(vuint8 far *)(PWM_ARR_ADDR[(pin >> 13 & 0x7)] + 1))

#define PWMX_CNTRH(pin)     (*(vuint8 far *)(PWMX_SMCR_ADDR[(pin >> 13 & 0x7)]))
#define PWMX_CNTRL(pin)     (*(vuint8 far *)(PWMX_SMCR_ADDR[(pin >> 13 & 0x7)]))

#define PWMX_CCMRX(pin)		(*(vuint8 far *)(PWM_CCMR_ADDR[((pin >> 13 & 0x7) * 4) + (pin >> 11 & 0x3)]))
#define PWMX_CCERX(pin)		(*(vuint8 far *)(PWM_CCER_ADDR[(((pin >> 13 & 0x7) * 2) + ((pin >> 11 & 0x03) >> 1))]))

#define PWMX_SMCR(pin)		(*(vuint8 far *)(PWMX_SMCR_ADDR[pin >> 13 & 0x7]))

#define PWMX_ENO(pin)		(*(vuint8 far *)(PWMX_ENO_ADDR[pin >> 13 & 0x7]))
#define PWMX_PS(pin)		(*(vuint8 far *)(PWMX_PS_ADDR[pin  >> 13 & 0x7]))
#define PWMX_BKR(pin)		(*(vuint8 far *)(PWMX_BKR_ADDR[pin >> 13 & 0x7]))
#define PWMX_CR1(pin)		(*(vuint8 far *)(PWMX_CR1_ADDR[pin >> 13 & 0x7]))


#define PWM_DUTY_MAX        10000

void    pwm_set_duty    (pwm_channel_enum pin, uint32 duty);
void    pwm_set_freq    (pwm_channel_enum pin, uint32 freq, uint32 duty);
void    pwm_init        (pwm_channel_enum pin, uint32 freq, uint32 duty);

#endif
