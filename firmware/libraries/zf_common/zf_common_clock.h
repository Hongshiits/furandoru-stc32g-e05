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

#ifndef __zf_common_clock_h__
#define __zf_common_clock_h__

#include "zf_common_typedef.h"


#define EXTERNAL_CRYSTAL 0
#define INTERNAL_CRYSTAL 1


#define USER_CRTSTAL INTERNAL_CRYSTAL


#define SYSTEM_CLOCK_124M   (124000000)
#define SYSTEM_CLOCK_120M   (120000000)
#define SYSTEM_CLOCK_114M   (114000000)
#define SYSTEM_CLOCK_111M   (111000000)
#define SYSTEM_CLOCK_108M   (108000000)
#define SYSTEM_CLOCK_105M   (105000000)
#define SYSTEM_CLOCK_102M   (102000000)
#define SYSTEM_CLOCK_99M    (99000000)
#define SYSTEM_CLOCK_96M    (96000000)
#define SYSTEM_CLOCK_93M    (93000000)
#define SYSTEM_CLOCK_90M    (90000000)
#define SYSTEM_CLOCK_87M    (87000000)
#define SYSTEM_CLOCK_84M    (84000000)
#define SYSTEM_CLOCK_81M    (81000000)
#define SYSTEM_CLOCK_78M    (78000000)



extern uint32 system_clock;

void clock_init(uint32 clock);                                               // 核心时钟初始化


#endif

