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

#ifndef __COMMON_H_
#define __COMMON_H_
#include "stc32g144k246.h"
#include <string.h>
#include <stdio.h>
#include "intrins.h"


#ifndef ENABLE
#define ENABLE 1
#endif

#ifndef DISABLE
#define DISABLE 0
#endif

//typedef bit                     BOOL;
//typedef unsigned char           BYTE;
//typedef unsigned int            WORD;
//typedef unsigned long           DWORD;

//数据类型声明
typedef unsigned char   uint8  ;	//  8 bits
typedef unsigned int  	uint16 ;	// 16 bits
typedef unsigned long  	uint32 ;	// 32 bits


typedef signed char     int8   ;	//  8 bits
typedef signed int      int16  ;	// 16 bits
typedef signed long     int32  ;	// 32 bits


typedef int8   volatile vint8  ;	//  8 bits
typedef int16  volatile vint16 ;	// 16 bits
typedef int32  volatile vint32 ;	// 32 bits


typedef uint8  volatile vuint8 ;	//  8 bits
typedef uint16 volatile vuint16;	// 16 bits
typedef uint32 volatile vuint32;	// 32 bits



typedef enum //无线模块
{
    NO_WIRELESS_MODE = 0,   // 没有无线模块
    WIRELESS_SI24R1 = 1,    // 无线转串口
    WIRELESS_CH9141 = 2,    // 蓝牙转串口
    WIRELESS_CH573 = 3,     // CH573模块
    WIRELESS_BLE6A20 = 4,   // BLE6A20蓝牙模块
    
} WIRELESS_TYPE_enum;


typedef void (*uart_callback_function)(uint8 dat);
typedef void (*callback_function)(void);

extern uint32 system_clock;


#define ZF_ENABLE           (1)
#define ZF_DISABLE          (0)

#define ZF_TRUE             (1)
#define ZF_FALSE            (0)

#endif
