/*********************************************************************************************************************
* STC32G144K Opensourec Library 即（STC32G144K 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2025 SEEKFREE 逐飞科技
*
* 本文件是STC32G144K开源库的一部分
*
* STC32G144K 开源库 是免费软件
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
* 2025-11-20        大W            first version
********************************************************************************************************************/

#ifndef __ZF_DRIVER_PIT_H
#define __ZF_DRIVER_PIT_H
#include "zf_common_typedef.h"
#include "zf_driver_timer.h"


typedef enum                                                                    // 枚举 TIM通道
{
	TIM0_PIT  = TIM_0,
    TIM1_PIT  = TIM_1,
    TIM2_PIT  = TIM_2,
    TIM3_PIT  = TIM_3,
    TIM4_PIT  = TIM_4,
    TIM5_PIT  = TIM_5,
    TIM6_PIT  = TIM_6,
    TIM7_PIT  = TIM_7,
    TIM8_PIT  = TIM_8,
    TIM9_PIT  = TIM_9,
    TIM10_PIT = TIM_10,
    TIM11_PIT = TIM_11,
    TIM17_PIT = TIM_17,
    TIM18_PIT = TIM_18,
}pit_index_enum;


#define TIM0_CLEAR_FLAG 	TCON      &= ~(1<<5)    // 定时器0溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM1_CLEAR_FLAG 	TCON      &= ~(1<<7)    // 定时器1溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM2_CLEAR_FLAG		AUXINTIF  &= ~(1<<0) 	// 定时器2溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM3_CLEAR_FLAG		AUXINTIF  &= ~(1<<1) 	// 定时器3溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM4_CLEAR_FLAG		AUXINTIF  &= ~(1<<2)	// 定时器4溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM5_CLEAR_FLAG		T6T5CFG   &= ~(1<<3)	// 定时器5溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM6_CLEAR_FLAG		T6T5CFG   &= ~(1<<7)	// 定时器6溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM7_CLEAR_FLAG		T8T7CFG   &= ~(1<<3)	// 定时器7溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM8_CLEAR_FLAG		T8T7CFG   &= ~(1<<7)	// 定时器8溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM9_CLEAR_FLAG		T10T9CFG  &= ~(1<<3)	// 定时器9溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM10_CLEAR_FLAG	T10T9CFG  &= ~(1<<7)	// 定时器10溢出中断标志位。 中断服务程序中，硬件自动清零。
#define TIM11_CLEAR_FLAG	T11CR     &= ~(1<<0)	// 定时器11溢出中断标志位。 中断服务程序中，硬件自动清零。
#define TIM17_CLEAR_FLAG	T18T17CFG &= ~(1<<3)	// 定时器17溢出中断标志位。 中断服务程序中，硬件自动清零。
#define TIM18_CLEAR_FLAG	T18T17CFG &= ~(1<<7)	// 定时器18溢出中断标志位。 中断服务程序中，硬件自动清零。


#define TIM0_GET_FLAG 	(TCON      & (1<<5))	    // 定时器0溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM1_GET_FLAG 	(TCON      & (1<<7))	    // 定时器1溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM2_GET_FLAG	(AUXINTIF  & (1<<0))	    // 定时器2溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM3_GET_FLAG	(AUXINTIF  & (1<<1))	    // 定时器3溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM4_GET_FLAG	(AUXINTIF  & (1<<2))	    // 定时器4溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM5_GET_FLAG	(T6T5CFG   & (1<<3))	    // 定时器5溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM6_GET_FLAG	(T6T5CFG   & (1<<7))	    // 定时器6溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM7_GET_FLAG	(T8T7CFG   & (1<<3))	    // 定时器7溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM8_GET_FLAG	(T8T7CFG   & (1<<7))	    // 定时器8溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM9_GET_FLAG	(T10T9CFG  & (1<<3))	    // 定时器9溢出中断标志位。  中断服务程序中，硬件自动清零。
#define TIM10_GET_FLAG	(T10T9CFG  & (1<<7))	    // 定时器10溢出中断标志位。 中断服务程序中，硬件自动清零。
#define TIM11_GET_FLAG	(T11CR     & (1<<0))        // 定时器11溢出中断标志位。 中断服务程序中，硬件自动清零。
#define TIM17_GET_FLAG	(T18T17CFG & (1<<3))	    // 定时器17溢出中断标志位。 中断服务程序中，硬件自动清零。
#define TIM18_GET_FLAG	(T18T17CFG & (1<<7))	    // 定时器18溢出中断标志位。 中断服务程序中，硬件自动清零。

//====================================================宏定义函数区====================================================
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     TIM PIT 中断初始化 ms 周期
// 参数说明     pit_n           使用的 PIT 编号
// 参数说明     ms              PIT 周期 ms 级别
// 返回参数     void
// 使用示例     pit_ms_init(TIM0_PIT, 1, pit_handler);
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
#define pit_ms_init(pit_n, ms, pit_handler)  (pit_init((pit_n), (ms) * (system_clock / 1000), (pit_handler)))

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     TIM PIT 中断初始化 us 周期
// 参数说明     pit_n           使用的 PIT 编号
// 参数说明     us              PIT 周期 us 级别
// 返回参数     void
// 使用示例     pit_us_init(TIM0_PIT, 100, pit_handler);
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
#define pit_us_init(pit_n, us, pit_handler)  (pit_init((pit_n), (us) * (system_clock / 1000000), (pit_handler)))

//====================================================宏定义函数区====================================================

extern callback_function tim_irq_handlers[TIM_RESERVE];

// void pit_enable  (pit_index_enum pit_n);
// void pit_disable (pit_index_enum pit_n);

void pit_init (pit_index_enum pit_n, uint32 period, callback_function pit_handler);

#endif
