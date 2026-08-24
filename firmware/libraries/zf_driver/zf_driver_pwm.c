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
* 2025-07-16        优化           代码可读性、运算效率及健壮性优化
********************************************************************************************************************/

#include "zf_common_clock.h"
#include "zf_common_debug.h"

#include "zf_driver_pwm.h"
#include "zf_driver_gpio.h"
#include "zf_driver_uart.h"
#include "zf_driver_delay.h"

// 引脚输出选择寄存器
const vuint32 PWMX_PS_ADDR[] = 
{
    0x7efeb2,
    0x7efeb6,
    0x7ef8b2,
    0x7ef8b6,
    0x7ef6b2,
    0x7ef6b6,
};

// 输出使能寄存器
const vuint32 PWMX_ENO_ADDR[] = 
{
    0x7efeb1,
    0x7efeb5,
    0x7ef8b1,
    0x7ef8b5,
    0x7ef6b1,
    0x7ef6b5,
};

// 刹车寄存器
const vuint32 PWMX_BKR_ADDR[] = 
{
    0x7efedd,
    0x7efefd,
    0x7ef8dd,
    0x7ef8fd,
    0x7ef6dd,
    0x7ef6fd,
};

// 控制寄存器1
const vuint32 PWMX_CR1_ADDR[] = 
{
    0x7efec0,
    0x7efee0,
    0x7ef8c0,
    0x7ef8e0,
    0x7ef6c0,
    0x7ef6e0,
};

// 捕获比较模式寄存器
const vuint32 PWM_CCMR_ADDR[] = 
{
    0x7efec8, 0x7efec9, 0x7efeca, 0x7efecb, // PWMA
    0x7efee8, 0x7efee9, 0x7efeea, 0x7efeeb, // PWMB
    0x7ef8c8, 0x7ef8c9, 0x7ef8ca, 0x7ef8cb, // PWMC
    0x7ef8e8, 0x7ef8e9, 0x7ef8ea, 0x7ef8eb, // PWMD
    0x7ef6c8, 0x7ef6c9, 0x7ef6ca, 0x7ef6cb, // PWME
    0x7ef6e8, 0x7ef6e9, 0x7ef6ea, 0x7ef6eb, // PWMF
};

// 捕获比较使能寄存器
const vuint32 PWM_CCER_ADDR[] = 
{
    0x7efecc, 0x7efecd, // PWMA
    0x7efeec, 0x7efeed, // PWMB
    0x7ef8cc, 0x7ef8cd, // PWMC
    0x7ef8ec, 0x7ef8ed, // PWMD
    0x7ef6cc, 0x7ef6cd, // PWME
    0x7ef6ec, 0x7ef6ed, // PWMF
};	

// 控制寄存器,高8位地址  低8位地址 + 1即可
const vuint32 PWM_CCR_ADDR[] = 
{ 
    0x7efed5, 0x7efed7, 0x7efed9, 0x7efedb,     // PWMA
    0x7efef5, 0x7efef7, 0x7efef9, 0x7efefb,     // PWMB
    0x7ef8d5, 0x7ef8d7, 0x7ef8d9, 0x7ef8db,     // PWMC
    0x7ef8f5, 0x7ef8f7, 0x7ef8f9, 0x7ef8fb,     // PWMD 
    0x7ef6d5, 0x7ef6d7, 0x7ef6d9, 0x7ef6db,     // PWME
    0x7ef6f5, 0x7ef6f7, 0x7ef6f9, 0x7ef6fb,     // PWMF
};

// 控制寄存器,高8位地址  低8位地址 + 1即可
const vuint32 PWM_ARR_ADDR[] = 
{
    0x7efed2,   // PWMA  
    0x7efef2,   // PWMB 
    0x7ef8d2,   // PWMC 
    0x7ef8f2,   // PWMD 
    0x7ef6d2,   // PWME 
    0x7ef6f2,   // PWMF
};

// 预分频寄存器,高8位地址  低8位地址 + 1即可
const vuint32 PWM_PSCR_ADDR[] = 
{
    0x7efed0,   // PWMA 
    0x7efef0,   // PWMB 
    0x7ef8d0,   // PWMC 
    0x7ef8f0,   // PWMD 
    0x7ef6d0,   // PWME 
    0x7ef6f0,   // PWMF
};

// PWM计数器,高8位地址  低8位地址 + 1即可
const vuint32 PWMX_CNTR_ADDR[] = 
{
    0x7efece,   // PWMA 
    0x7efeee,   // PWMB 
    0x7ef8ce,   // PWMC 
    0x7ef8ee,   // PWMD 
    0x7ef6ce,   // PWME 
    0x7ef6ee,   // PWMF
};

// 从模式控制寄存器
const vuint32 PWMX_SMCR_ADDR[] = 
{
    0x7efec2,   // PWMA 
    0x7efee2,   // PWMB 
    0x7ef8c2,   // PWMC 
    0x7ef8e2,   // PWMD 
    0x7ef6c2,   // PWME 
    0x7ef6e2,   // PWMF
};

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PWM频率和占空比设置
// 参数说明     pin           	PWM通道号及引脚
// 参数说明     freq           	PWM频率
// 参数说明     duty            PWM占空比
// 返回参数     void
// 使用示例     pwm_set_freq(PWMB_CH2_P01, 50, 1000);   //PWMB 使用引脚P01 频率50HZ 占空比为百分之 1000/PWM_DUTY_MAX*100
//                              						PWM_DUTY_MAX在zf_driver_pwm.h文件中 默认为10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_set_freq(pwm_channel_enum pin, uint32 freq, uint32 duty)
{
    uint32 match_temp = 0;
    uint32 period_temp = 0;
    uint16 freq_div = 0;
	
	// 如果是这一行报错 那你得去看看最大占空比是限定的多少 占空比写入错误
    zf_assert(PWM_DUTY_MAX >= duty);
	
    //分频计算，周期计算，占空比计算
    freq_div = (system_clock / freq) >> 16;								// 多少分频
    period_temp = system_clock / freq;
    period_temp = period_temp / (freq_div + 1) - 1;					// 周期

    if(duty != PWM_DUTY_MAX)
    {
        match_temp = period_temp * ((float)duty / PWM_DUTY_MAX);	// 占空比
    }
    else
    {
        match_temp = period_temp + 1;								// duty为100%
	}

	PWMX_PSCRH(pin) = (uint8)(freq_div >> 8);	    // 设置预分频值
	PWMX_PSCRL(pin) = (uint8)freq_div;
	
	PWMX_ARRH(pin) = (uint8)(period_temp >> 8);		// 周期值 高8位
	PWMX_ARRL(pin) = (uint8)period_temp;			// 周期值 低8位

    PWMX_CCRXH(pin) = match_temp >> 8;				// 比较值 高8位
    PWMX_CCRXL(pin) = (uint8)match_temp;			// 比较值 低8位
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PWM占空比设定
// 参数说明     pin           	PWM通道号及引脚
// 参数说明     duty            PWM占空比
// 返回参数     void
// 使用示例     pwm_set_duty(PWMB_CH2_P01, 5000);   //PWMB 使用引脚P01 占空比为百分之 5000/PWM_DUTY_MAX*100
//                              					PWM_DUTY_MAX在zf_driver_pwm.h文件中 默认为10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_set_duty(pwm_channel_enum pin, uint32 duty)
{
    uint32 match_temp;
    uint32 arr = (PWMX_ARRH(pin) << 8) | PWMX_ARRL(pin);
	
	// 如果是这一行报错 那你得去看看最大占空比是限定的多少 占空比写入错误
    zf_assert(PWM_DUTY_MAX >= duty);
	
    if(duty != PWM_DUTY_MAX)
    {
        match_temp = arr * ((float)duty / PWM_DUTY_MAX);				//占空比
    }
    else
    {
        match_temp = arr + 1;
    }

    //设置捕获值|比较值
    PWMX_CCRXH(pin) = (uint8)(match_temp >> 8);				// 比较值 高8位
    PWMX_CCRXL(pin) = (uint8)match_temp;			// 比较值 低8位
	
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PWM初始化
// 参数说明     pin				PWM通道号及引脚
// 参数说明     freq            PWM频率
// 参数说明     duty            PWM占空比
// 返回参数     void
// 使用示例     pwm_init(PWMB_CH2_P01, 50, 5000);   //初始化PWMB 使用引脚P01  输出PWM频率50HZ   占空比为百分之 5000/PWM_DUTY_MAX*100
//                              					PWM_DUTY_MAX在zf_driver_pwm.h文件中 默认为10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(pwm_channel_enum pin, uint32 freq, uint32 duty)
{

    uint16 match_temp = 0;                                              // 占空比值
    uint32 period_temp = 0;                                             // 周期值
    uint16 freq_div = 0;                                                // 分频值
    
	// 如果是这一行报错 那你得去看看最大占空比是限定的多少 占空比写入错误
    zf_assert(PWM_DUTY_MAX >= duty);
	
    gpio_init(pin  & 0xFF, GPO, 1, GPO_PUSH_PULL);						// GPIO需要设置为推挽输出

    //分频计算，周期计算，占空比计算
    freq_div = (system_clock / freq) >> 16;								// 分频值
    period_temp = system_clock / freq;
    period_temp = period_temp / (freq_div + 1) - 1;						// 周期值
	
    if(duty != PWM_DUTY_MAX)
    {		
        match_temp = period_temp * ((float)duty / PWM_DUTY_MAX);		// 占空比
    }
    else
    {
        match_temp = period_temp + 1;									// duty为100%
    }

	PWMX_PSCRH(pin) = (uint8)(freq_div >> 8);	    // 设置预分频值
	PWMX_PSCRL(pin) = (uint8)freq_div;
	
	PWMX_ARRH(pin) = (uint8)(period_temp >> 8);		// 周期值 高8位
	PWMX_ARRL(pin) = (uint8)period_temp;			// 周期值 低8位

    PWMX_CCRXH(pin) = (uint8)(match_temp >> 8);		// 比较值 高8位
    PWMX_CCRXL(pin) = (uint8)match_temp;			// 比较值 低8位

    PWMX_CCERX(pin) |= 1 << ((pin >> 11 & 0x01) * 4 + (pin >> 10 & 0x01) * 2);	// 使能N或者P通道

	PWMX_CCMRX(pin) |= 0x06 << 4;					// 设置为PWM模式1
	PWMX_CCMRX(pin) |= 1 << 3;						// 开启PWM寄存器的预装载功
    
    PWMX_ENO(pin) |= 1 << ((((pin >> 11) & 0x03) * 2) + ((pin >> 10) & 0x01));		// 使能通道
    PWMX_PS(pin)  |= ((pin >> 8) & 0x03) << (((pin >> 11) & 0x03) * 2);				// 选择引脚
    PWMX_BKR(pin) |= 0x80; 							// 主输出使能 相当于总开关
    PWMX_CR1(pin) |= 0x01;							// PWM开始计数

#if 0
    while(1)
    {
        printf("PWMX_PSCRH(pin) -> 0x%lX = 0x%X\r\n",  ((PWM_PSCR_ADDR[(pin >> 13 & 0x7)])), PWMX_PSCRH(pin));
        printf("PWMX_PSCRL(pin) -> 0x%lX = 0x%X\r\n",  (((PWM_PSCR_ADDR[(pin >> 13 & 0x7)] + 1))), PWMX_PSCRL(pin));
        printf("PWMX_ARRH(pin) -> 0x%lX = 0x%X\r\n",   (((PWM_ARR_ADDR[(pin >> 13 & 0x7)]))), PWMX_ARRH(pin));
        printf("PWMX_ARRL(pin) -> 0x%lX = 0x%X\r\n",   (((PWM_ARR_ADDR[(pin >> 13 & 0x7)] + 1))), PWMX_ARRL(pin));
        printf("PWMX_CCRXH(pin) -> 0x%lX = 0x%X\r\n",  (((PWM_CCR_ADDR[((pin >> 13 & 0x7) * 4) + (pin >> 11 & 0x3)]))), PWMX_CCRXH(pin));
        printf("PWMX_CCRXL(pin) -> 0x%lX = 0x%X\r\n",  (((PWM_CCR_ADDR[((pin >> 13 & 0x7) * 4) + (pin >> 11 & 0x3)] + 1))), PWMX_CCRXL(pin));
		
        printf("PWMX_CCERX(pin) -> 0x%lX = 0x%X\r\n",  (((PWM_CCER_ADDR[(((pin >> 13 & 0x7) * 2) + ((pin >> 11 & 0x03) >> 1))]))), PWMX_CCERX(pin));
        printf("PWMX_CCMRX(pin) -> 0x%lX = 0x%X\r\n",  (((PWM_CCMR_ADDR[((pin >> 13 & 0x7) * 4) + (pin >> 11 & 0x3)]))), PWMX_CCMRX(pin));
        printf("PWMX_ENO(pin) -> 0x%lX = 0x%X\r\n",    (((PWMX_ENO_ADDR[pin >> 13 & 0x7]))), PWMX_ENO(pin));
        printf("PWMX_PS(pin) -> 0x%lX = 0x%X\r\n",     (((PWMX_PS_ADDR[pin  >> 13 & 0x7]))), PWMX_PS(pin));
        printf("PWMX_BKR(pin) -> 0x%lX = 0x%X\r\n",    (((PWMX_BKR_ADDR[pin >> 13 & 0x7]))), PWMX_BKR(pin));
        printf("PWMX_CR1(pin) -> 0x%lX = 0x%X\r\n",    (((PWMX_CR1_ADDR[pin >> 13 & 0x7]))), PWMX_CR1(pin));
        system_delay_ms(1000);
    }
#endif
    
}
