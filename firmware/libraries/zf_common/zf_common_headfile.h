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

#ifndef __HEADFILE_H_
#define __HEADFILE_H_


#pragma warning disable = 115
#pragma warning disable = 188

#include <string.h>
#include <stdio.h>
#include <math.h>
#include "intrins.h"
#include "isr.h"

//------STC32G144K SDK等
#include "stc32g144k246.h"
#include "zf_common_typedef.h"
#include "zf_common_clock.h"
#include "zf_common_fifo.h"
#include "zf_common_debug.h"
#include "zf_common_interrupt.h"
#include "zf_common_font.h"
#include "zf_common_function.h"

////------逐飞科技单片机外设驱动头文件
#include "zf_driver_uart.h"
#include "zf_driver_gpio.h"
#include "zf_driver_adc.h"
#include "zf_driver_spi.h"
#include "zf_driver_spi.h"
#include "zf_driver_timer.h"
#include "zf_driver_pwm.h"
//#include "zf_driver_flash.h"
#include "zf_driver_exti.h"
#include "zf_driver_delay.h"
#include "zf_driver_eeprom.h"
#include "zf_driver_pit.h"
#include "zf_driver_encoder.h"
#include "zf_driver_usb_cdc.h"


////------逐飞科技产品驱动头文件

#include "zf_device_mt9v03x.h"

#include "zf_device_config.h"
#include "zf_device_type.h"

//#include "zf_device_icm20602.h"
#include "zf_device_imu660ra.h"
#include "zf_device_imu660rb.h"
#include "zf_device_imu963ra.h"
#include "zf_device_imu660rc.h"

////#include "zf_device_oled.h"
#include "zf_device_tft180.h"
#include "zf_device_ips114.h"
#include "zf_device_ips200.h"
#include "zf_device_ips200pro.h"

#include "zf_device_dl1a.h"
#include "zf_device_dl1b.h"

#include "zf_device_ble6a20.h"
//#include "zf_device_tsl1401.h"
#include "zf_device_wireless_uart.h"
////#include "zf_device_gnss.h"
//#include "zf_device_gps_tau1201.h"
#include "zf_device_wifi_spi.h"
#include "zf_device_mt9v03x_dma.h"

////------逐飞科技产品组件层文件
#include "seekfree_assistant.h"

#include "seekfree_assistant_interface.h"


#endif