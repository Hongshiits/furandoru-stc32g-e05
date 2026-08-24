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


#ifndef __ZF_DRIVER_EXTI_H
#define __ZF_DRIVER_EXTI_H

#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"


//此枚举定义不允许用户修改
typedef enum
{
	INT0_P32 = 0x0100 | IO_P32,	    // 支持边沿，下降沿中断
	INT1_P33 = 0x0200 | IO_P33,		// 支持边沿，下降沿中断
	INT2_P36 = 0x0300 | IO_P36,		// 支持下降沿中断		
 	INT3_P37 = 0x0400 | IO_P37,		// 支持下降沿中断
	INT4_P30 = 0x0500 | IO_P30,		// 支持下降沿中断
}INTN_enum;

#define INT0_CLEAR_FLAG (TCON &= (~(0x01 << 1)))		// 外部中断 0 中断请求标志。中断服务程序中，硬件自动清零。
#define INT1_CLEAR_FLAG (TCON &= (~(0x01 << 3)))		// 外部中断 1 中断请求标志。中断服务程序中，硬件自动清零。
                                                           
#define INT2_CLEAR_FLAG (AUXINTIF &= (~(0x10 << 0)))	// 外部中断 2 中断请求标志。中断服务程序中，硬件自动清零。
#define INT3_CLEAR_FLAG (AUXINTIF &= (~(0x10 << 1)))	// 外部中断 3 中断请求标志。中断服务程序中，硬件自动清零。
#define INT4_CLEAR_FLAG (AUXINTIF &= (~(0x10 << 2)))	// 外部中断 4 中断请求标志。中断服务程序中，硬件自动清零。


typedef enum    	
{
	BOTH,			//边沿
	FALLING_EDGE,	//下降沿
//	RISING_EDGE,	//不支持上升沿

}INT_MODE_enum;


extern callback_function int_irq_handlers[5];

void exit_init(INTN_enum int_n,INT_MODE_enum mode);


#endif