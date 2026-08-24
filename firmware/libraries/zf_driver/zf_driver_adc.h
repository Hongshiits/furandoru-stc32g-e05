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

#ifndef __ZF_DRIVER_ADC_H
#define __ZF_DRIVER_ADC_H

#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"

//此枚举定义不允许用户修改
typedef enum
{
    ADC1_CH0_P10  = 0x0000 | IO_P10,
    ADC1_CH1_P11  = 0x0100 | IO_P11,
    ADC1_CH2_P12  = 0x0200 | IO_P12,
    ADC1_CH3_P13  = 0x0300 | IO_P13,
    ADC1_CH4_P14  = 0x0400 | IO_P14,
    ADC1_CH5_P15  = 0x0500 | IO_P15,
    ADC1_CH6_P16  = 0x0600 | IO_P16,
    ADC1_CH7_P17  = 0x0700 | IO_P17,
    ADC1_CH8_P00  = 0x0800 | IO_P00,
    ADC1_CH9_P01  = 0x0900 | IO_P01,
    ADC1_CH10_P02 = 0x0A00 | IO_P02,
                                                                                
    ADC2_CH0_P00  = 0x1000 | IO_P00,
    ADC2_CH1_P01  = 0x1100 | IO_P01,
    ADC2_CH2_P02  = 0x1200 | IO_P02,
    ADC2_CH3_P03  = 0x1300 | IO_P03,
    ADC2_CH4_P04  = 0x1400 | IO_P04,
    ADC2_CH5_P05  = 0x1500 | IO_P05,
    ADC2_CH6_P06  = 0x1600 | IO_P06,
    ADC2_CH7_P07  = 0x1700 | IO_P07,
    ADC2_CH8_P60  = 0x1800 | IO_P60,
    ADC2_CH9_P61  = 0x1900 | IO_P61,
    ADC2_CH10_P62 = 0x1A00 | IO_P62,
} adc_channel_enum;

//此枚举定义不允许用户修改
typedef enum
{
    ADC_SYSclk_DIV_2 = 0,
    ADC_SYSclk_DIV_4,
    ADC_SYSclk_DIV_6,
    ADC_SYSclk_DIV_8,
    ADC_SYSclk_DIV_10,
    ADC_SYSclk_DIV_12,
    ADC_SYSclk_DIV_14,
    ADC_SYSclk_DIV_16,
    ADC_SYSclk_DIV_18,
    ADC_SYSclk_DIV_20,
    ADC_SYSclk_DIV_22,
    ADC_SYSclk_DIV_24,
    ADC_SYSclk_DIV_26,
    ADC_SYSclk_DIV_28,
    ADC_SYSclk_DIV_30,
    ADC_SYSclk_DIV_32,
} adc_speed_enum;


//此枚举定义不允许用户修改
typedef enum    
{

    ADC_12BIT = 0,  //12位分辨率
    ADC_11BIT,		//11位分辨率
    ADC_10BIT,		//10位分辨率
    ADC_9BIT,    	//9位分辨率
    ADC_8BIT,     	//8位分辨率
} adc_resolution_enum;


uint16  adc_convert             (adc_channel_enum ch);
uint16  adc_mean_filter_convert (adc_channel_enum ch, const uint8 count);
void    adc_init                (adc_channel_enum ch, adc_resolution_enum resolution);



#endif