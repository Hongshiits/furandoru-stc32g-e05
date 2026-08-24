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
* 2025-11-20         大W            first version
********************************************************************************************************************/

#include "zf_common_typedef.h"
#include "zf_common_clock.h"
#include "zf_common_debug.h"
#include "zf_common_interrupt.h"

#include "zf_driver_delay.h"
#include "zf_driver_uart.h"

//内核频率
uint32 system_clock = 0;



void clock_init (uint32 clock)                                              // 核心时钟初始化
{
    uint8 pll_div = ((clock / 1000000UL - 78) / 3);
    interrupt_global_disable();
    EAXFR = 1;				    // 使能访问XFR
	// CKCON = 0;
    if((120*1000*1000UL) <= clock)
    {
        WTST = 4;
    }
    else if((80*1000*1000UL) <= clock)
    {
        WTST = 3;
    }
    else if((80*1000*1000UL) <= clock)
    {
        WTST = 2;
    }
    else
    {
        WTST = 4;
    }

#if(INTERNAL_CRYSTAL == USER_CRTSTAL)
    CLKDIV = 2;                 // 设置系统时钟=xxxMhz/2/2=clock，（因为CLKSEL选择时，已经将HPLL/2了）

	//以下为超过60MHz时，系统时钟使用HPLL方式提供
	VRTRIM = CHIPID22;		    // 载入27MHz频段的VRTRIM值
	IRTRIM = CHIPID12;		    // 指定当前HIRC为24MHz，此时会覆盖掉ISP设置的时钟频率
	IRCBAND &= ~0x03;			// 清空频段选择
	IRCBAND |= 0x01;			// 选择27Mhz频段
	HPLLCR &= ~0x10;    	    // 选择HPLL输入时钟源为HIRC
	HPLLPDIV = 4;				// 24MHz/4=6MHz,需要保证输入HPLL的时钟在6MHz附近
    HPLLCR |= pll_div & 0x0F;   // 设置PLL1倍频系数
	HPLLCR |= 0x80;     	    // 使能HPLL
    soft_delay(50000);
	CLKSEL &= ~0x03;			// BASE_CLK选择为HIRC，用以提供给HPLL
	CLKSEL &= ~0x0c;			// 清空主时钟源选择
	CLKSEL |= 1<<2;				// 设置主时钟源为内部 HPLL1 输出/2
   
#elif(EXTERNAL_CRYSTAL == USER_CRTSTAL)

    CLKDIV = 2;                 // 设置系统时钟=xxxMhz/2/2=clock，（因为CLKSEL选择时，已经将HPLL/2了）

    CLKSEL &= ~0x03;			//BASE_CLK选择为HIRC，用以提供给HPLL
	CLKSEL &= ~0x0c;			//清空主时钟源选择

    XOSCCR = 3<<6 | 1 << 2 | 1<<5;    // 选择外部晶振,24M晶振
    soft_delay(50000);
    while (!(XOSCCR & 1));      // 等待时钟稳定

    HPLLCR &= ~(1<<4);          // 内部基本时钟(BASECLK)
    HPLLPDIV = 4;               // 必须为6M，这里24M晶振4分频
    HPLLCR |= pll_div & 0x0F; // 设置PLL1倍频系数

//    HPLL2CR |= 6;            // 设置PLL2倍频系数
    HPLLCR |= 0<<5;            // PLL1/2提供给两组高速I2S时钟
//    HPLL2CR |= 0<<5;            // PLL1/2提供给两组高速外设时钟
    HPLLCR |= 1<<7;            // 使能HPLL

    // 先设置好时钟，最后切换外部高速晶振
    CLKSEL = 1 << 0 | 1 << 2;   // 选择外部高速晶振, 内部HPLL1输出/2

#endif


    ADCCFG = 0;
    AUXR = 0;
    SCON = 0;
    S2CON = 0;
    S3CON = 0;
    S4CON = 0;
    P_SW1 = 0;
    IE2 = 0;
    TMOD = 0;

    system_clock = clock;

#if(USER_USB_CDC)
    // 使能USB时钟，以及初始化USB相关引脚
    P3M0 &= ~0x03;
    P3M1 |= 0x03;

    IRC48MCR = 0x80;
    while (!(IRC48MCR & 0x01));
    
    // 等待48M稳定
    system_delay_ms(10);
#endif


	interrupt_global_enable();
}
