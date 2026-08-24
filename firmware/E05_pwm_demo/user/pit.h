#ifndef PIT_H
#define PIT_H
#include "pt_headfile.h"

 
#define PIT_CH                          (TIM3_PIT )                 // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用
//#define PIT_PRIORITY                    (TIM1_IRQn)               TIM1的中断优先级默认最低，不可修改，具体看手册。
#define PIT_CH2                          (TIM4_PIT )
#define PIT_CH3                          (TIM5_PIT )
#define PIT_CH4                          (TIM6_PIT )
#define PIT_CH5                          (TIM7_PIT )


void pit_handler_encoder(void);
void pit_handler_encoder_print(void);
void pit_handler_adc_print(void);
void pit_handler_imu660ra(void);
void pit_handler_imu660rb(void);


void pt_pit_init(void);

#endif