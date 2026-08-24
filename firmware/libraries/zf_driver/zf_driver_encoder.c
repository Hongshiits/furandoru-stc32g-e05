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

#include "zf_driver_encoder.h"
#include "zf_common_debug.h"

static volatile uint8 encoder_dir_pin[20] = 
{ 
    // 0-5  为 PWM 接口，一共6个
    // 6-19 为 TIM 接口，一共14个
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     定时器编码器解码取值
// 参数说明     timer_ch      定时器枚举体
// 返回参数     void
// 备注信息
// 使用示例    encoder_get_count(TIM2_ENCODER)  // 获取定时器2的采集到的编码器数据
//-------------------------------------------------------------------------------------------------------------------
int16 encoder_get_count(encoder_index_enum encoder_n)
{
    int16 ret = 0;
    if(encoder_n >= TIM0_ENCODER)
    {
        switch(encoder_n)
        {
            case TIM0_ENCODER: ret = (uint16)TH0 << 8; ret |= TL0; break;
            case TIM1_ENCODER: ret = (uint16)TH1 << 8; ret |= TL1; break;
            case TIM2_ENCODER: ret = (uint16)T2H << 8; ret |= T2L; break;
            case TIM3_ENCODER: ret = (uint16)T3H << 8; ret |= T3L; break;
            case TIM4_ENCODER: ret = (uint16)T4H << 8; ret |= T4L; break;
            case TIM5_ENCODER: ret = (uint16)T5H << 8; ret |= T5L; break;
            case TIM6_ENCODER: ret = (uint16)T6H << 8; ret |= T6L; break;
            case TIM7_ENCODER: ret = (uint16)T7H << 8; ret |= T7L; break;
            case TIM8_ENCODER: ret = (uint16)T8H << 8; ret |= T8L; break;
            case TIM9_ENCODER: ret = (uint16)T9H << 8; ret |= T9L; break;
            case TIM10_ENCODER: ret = (uint16)T10H << 8; ret |= T10L; break;
            case TIM11_ENCODER: ret = (uint16)T11H << 8; ret |= T11L; break;
            case TIM17_ENCODER: ret = (uint16)T17H << 8; ret |= T17L; break;
            case TIM18_ENCODER: ret = (uint16)T18H << 8; ret |= T18L; break;
            default: zf_assert(0); break;            
        }
        if(gpio_get_level(encoder_dir_pin[encoder_n & 0x0F + PWMF_ENCODER + 1]) == 0)
        {
            ret = -ret;
        }
    }
    else
    {
        ret  = ((*(vuint8 far *)(PWMX_CNTR_ADDR[encoder_n])) << 8);
        ret |= ((*(vuint8 far *)(PWMX_CNTR_ADDR[encoder_n] + 1)));
        if(encoder_dir_pin[encoder_n & 0x0F] != 0xFF)
        {
            // 方向编码器
            if(gpio_get_level(encoder_dir_pin[encoder_n & 0x0F]) == 0)
            {
                ret = -ret;
            }
        }
        else
        {
            // 正交编码器，四倍频模式
            ret = ret >> 2;
        }
    }

    return  ret;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     定时器的计数器清空
// 参数说明     timer_ch      定时器枚举体
// 返回参数     void
// 备注信息
// 使用示例    encoder_clear_count(TIM1_ENCODER)  //清除定时器1采集到的编码器数据
//-------------------------------------------------------------------------------------------------------------------
void encoder_clear_count(encoder_index_enum encoder_n)
{
    if(encoder_n >= TIM0_ENCODER)
    {
        switch(encoder_n)
        {
            case TIM0_ENCODER:  TR0 = 0; TH0 = 0; TL0 = 0; TR0 = 1; break;
            case TIM1_ENCODER:  TR1 = 0; TH1 = 0; TL1 = 0; TR1 = 1; break;
            case TIM2_ENCODER:  AUXR    &= ~(1 << 4); T2H = 0;  T2L = 0;  AUXR    |= (1 << 4); break;
            case TIM3_ENCODER:  T4T3M   &= ~(1 << 3); T3H = 0;  T3L = 0;  T4T3M   |= (1 << 3); break;
            case TIM4_ENCODER:  T4T3M   &= ~(1 << 7); T4H = 0;  T4L = 0;  T4T3M   |= (1 << 7); break;
            case TIM5_ENCODER:  T6T5M   &= ~(1 << 3); T5H = 0;  T5L = 0;  T6T5M   |= (1 << 3); break;
            case TIM6_ENCODER:  T6T5M   &= ~(1 << 7); T6H = 0;  T6L = 0;  T6T5M   |= (1 << 3); break;
            case TIM7_ENCODER:  T8T7M   &= ~(1 << 3); T7H = 0;  T7L = 0;  T8T7M   |= (1 << 3); break;
            case TIM8_ENCODER:  T8T7M   &= ~(1 << 7); T8H = 0;  T8L = 0;  T8T7M   |= (1 << 3); break;
            case TIM9_ENCODER:  T10T9M  &= ~(1 << 3); T9H = 0;  T9L = 0;  T10T9M  |= (1 << 3); break;
            case TIM10_ENCODER: T10T9M  &= ~(1 << 7); T10H = 0; T10L = 0; T10T9M  |= (1 << 3); break;
            case TIM11_ENCODER: T11CR   &= ~(1 << 7); T11H = 0; T11L = 0; T11CR   |= (1 << 7); break;
            case TIM17_ENCODER: T18T17M &= ~(1 << 3); T17H = 0; T17L = 0; T18T17M |= (1 << 3); break;
            case TIM18_ENCODER: T18T17M &= ~(1 << 7); T18H = 0; T18L = 0; T18T17M |= (1 << 7); break;
            default: zf_assert(0); break;            
        }                          
    }
    else
    {
        // (*(vuint8 far *)(PWMX_CR1_ADDR[encoder_n]))     &= 0xFE;
        (*(vuint8 far *)(PWMX_CNTR_ADDR[encoder_n]))     = 0;
        (*(vuint8 far *)(PWMX_CNTR_ADDR[encoder_n] + 1)) = 0;
        // (*(vuint8 far *)(PWMX_CR1_ADDR[encoder_n]))     |= 0x01;
    }
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     定时器编码器解码初始化
// 参数说明     encoder_n        PWM通道
// 参数说明     ch1_pin          通道A以及引脚
// 参数说明     ch2_pin          通道B以及引脚
// 返回参数     void
// 备注信息     
// 使用示例     内部使用，用户无需关心
// 备注信息     仅支持正交编码器
//-------------------------------------------------------------------------------------------------------------------
static void tim_encoder_dir_init(encoder_index_enum encoder_n, encoder_channel_enum lsb_pin, gpio_pin_enum dir_pin)
{
    // 如果程序在输出了断言信息 并且提示出错位置在这里
    // 就去查看你在什么地方调用这个函数 检查你的传入参数
    // 这里是检查是否有重复使用定时器
	// TIM2已经给串口用作波特率发生器了。不能再初始化为其他的。
	zf_assert(timer_funciton_check(encoder_n & 0xFF, TIMER_FUNCTION_ENCODER));

    // 传入的引脚错误
    zf_assert(((uint16)lsb_pin >> 13) == 6);
    gpio_init(dir_pin & 0xFF, GPI, 0, GPI_PULL_UP);
    gpio_init(lsb_pin & 0xFF, GPI, 0, GPI_PULL_UP);
    encoder_dir_pin[encoder_n & 0x0F + PWMF_ENCODER + 1] = (uint8)(dir_pin & 0xFF);
    switch(encoder_n)
    {
        case TIM0_ENCODER:  TL0=0;  TH0=0;  TMOD|=0x04; TR0=1; break;
        case TIM1_ENCODER:  TL1=0;  TH1=0;  TMOD|=0x40; TR1=1; break;
        case TIM2_ENCODER:  T2L=0;  T2H=0;  AUXR|=0x18; break;
        case TIM3_ENCODER:  T3L=0;  T3H=0;  T4T3M|=0x0c; break;
        case TIM4_ENCODER:  T4L=0;  T4H=0;  T4T3M|=0xc0; break;
        case TIM5_ENCODER:  T5L=0;  T5H=0;  T6T5M|=0x0c; break;
        case TIM6_ENCODER:  T6L=0;  T6H=0;  T6T5M|=0xc0; break;
        case TIM7_ENCODER:  T7L=0;  T7H=0;  T8T7M|=0x0c; break;
        case TIM8_ENCODER:  T8L=0;  T8H=0;  T8T7M|=0xc0; break;
        case TIM9_ENCODER:  T9L=0;  T9H=0;  T10T9M|=0x0c; break;
        case TIM10_ENCODER: T10L=0; T10H=0; T10T9M|=0xc0; break;
        case TIM11_ENCODER: T11L=0; T11H=0; T11CR|=0xc0; break;
        case TIM17_ENCODER: T17L=0; T17H=0; T18T17M|=0x0c; break;
        case TIM18_ENCODER: T18L=0; T18H=0; T18T17M|=0xc0; break;
        default: zf_assert(0); break;            
    
    }
}
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PWM编码器解码初始化
// 参数说明     encoder_n        PWM通道
// 参数说明     ch1_pin          通道A以及引脚
// 参数说明     ch2_pin          通道B以及引脚
// 返回参数     void
// 使用示例     内部使用，用户无需关心
// 备注信息     支持带方向编码器和正交编码器              
//-------------------------------------------------------------------------------------------------------------------
static void pwm_encoder_dir_init(encoder_index_enum encoder_n, encoder_channel_enum ch1_pin, encoder_channel_enum ch2_pin)
{
//    encoder_quad_init(encoder_n, ch1_pin, ch2_pin);
    gpio_init(ch1_pin & 0xFF, GPI, 0, GPI_PULL_UP);
    gpio_init(ch2_pin & 0xFF, GPI, 0, GPI_PULL_UP);
    encoder_dir_pin[encoder_n & 0x0F] = (uint8)(ch2_pin & 0xFF);
    
    
    PWMX_CR1(ch1_pin) &= 0xFE;
    PWMX_PS(ch1_pin)  |= ((ch1_pin >> 8) & 0x03) << (((ch1_pin >> 11) & 0x03) * 2);				// 选择引脚

    PWMX_ARRH(ch1_pin) = 0xFF;              // 周期寄存器
    PWMX_ARRL(ch1_pin) = 0xFF;              // 周期寄存器
        
    PWMX_PSCRH(ch1_pin) = 0;                // 分频寄存器
    PWMX_PSCRL(ch1_pin) = 0;                // 分频寄存器

    PWMX_SMCR(ch1_pin)  = 0x07 | 5 << 4;    // 外部计数模式 , 滤波后的CH1输入

    PWMX_CCERX(ch1_pin) = 0x00;             // 关闭所有输出
    PWMX_CCERX(ch2_pin) = 0x00;             // 关闭所有输出
    PWMX_CCMRX(ch1_pin) |= 0x01;	        // 01:CC1 通道被配置为输入，IC1 映射在TI1 上
    PWMX_CR1(ch1_pin)   |= 0x01; 	        // 开启定时器，向上计数
    
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     正交编码器解码初始化
// 参数说明     timer_ch      定时器枚举体
// 参数说明     phaseA      通道A以及引脚
// 参数说明     phaseB      通道B以及引脚
// 返回参数     void
// 使用示例             encoder_quad_init(PWMA_ENCODER, PWMA_ENCODER_CH1P_P60, PWMA_ENCODER_CH2P_P62)
//                      // 使用PWMA 做正交解码使用， 通道1脉冲信号引脚P60，通道2脉冲信号引脚P62
// 备注信息                                
//-------------------------------------------------------------------------------------------------------------------
void encoder_quad_init(encoder_index_enum encoder_n, encoder_channel_enum ch1_pin, encoder_channel_enum ch2_pin)
{
    // 如果程序在输出了断言信息 并且提示出错位置在这里
    // 就去查看你在什么地方调用这个函数 检查你的传入参数
    zf_assert(((uint16)ch1_pin >> 13) == ((uint8)encoder_n));              // ch1_pin 与 ch2_pin 必须与 encoder_n 匹配
    zf_assert(((uint16)ch2_pin >> 13) == ((uint8)encoder_n));              // ch1_pin 与 ch2_pin 必须与 encoder_n 匹配


    gpio_init(ch1_pin  & 0xFF, GPI, 1, GPI_IMPEDANCE);		    // 初始化引脚
    gpio_init(ch2_pin  & 0xFF, GPI, 1, GPI_IMPEDANCE);		    // 初始化引脚

    PWMX_CR1(ch1_pin) &= 0xFE;
    PWMX_PS(ch1_pin)  |= ((ch1_pin >> 8) & 0x03) << (((ch1_pin >> 11) & 0x03) * 2);				// 选择引脚
    PWMX_PS(ch2_pin)  |= ((ch2_pin >> 8) & 0x03) << (((ch2_pin >> 11) & 0x03) * 2);				// 选择引脚

    PWMX_ARRH(ch1_pin) = 0xFF;      // 周期寄存器
    PWMX_ARRL(ch1_pin) = 0xFF;      // 周期寄存器

    PWMX_PSCRH(ch1_pin) = 0;        // 分频寄存器
    PWMX_PSCRL(ch1_pin) = 0;        // 分频寄存器

    PWMX_SMCR(ch1_pin)  = 0x03; 	// 边沿计数

    PWMX_CCERX(ch1_pin) = 0x00;     // 关闭所有输出
    PWMX_CCERX(ch2_pin) = 0x00;     // 关闭所有输出
    PWMX_CCMRX(ch1_pin) |= 0x01;	// 01:CC1 通道被配置为输入，IC1 映射在TI1 上
    PWMX_CCMRX(ch2_pin) |= 0x01;    // 01:CC2 通道被配置为输入，IC2 映射在TI2 上
    PWMX_CR1(ch1_pin)   |= 0x01; 	// 开启定时器，向上计数



    // PWMA_PS |= 0x02;		// 选择引脚
    // PWMA_PS |= 0x02 << 2;	// 选择引脚
    // PWMA_PSCRH = 0;         // 分频寄存器
    // PWMA_PSCRL = 1;         // 分频寄存器
    // PWMA_CR1 = 0;           // 控制寄存器
    // PWMA_CR2 = 0;	        // 控制寄存器
    // PWMA_SR1 = 0;           // 状态寄存器
    // PWMA_SR2 = 0;	        // 状态寄存器
    // PWMA_ARRH = 0xFF;	    // 设置自动重装载值
    // PWMA_ARRL = 0xFF;	    // 设置自动重装载值
    // PWMA_SMCR = 0x02; 		// 010:编码器模式2-根据TI2 的电平，计数器在TI1 的边沿向上/向下计数
    // PWMA_CCER1 = 0x00;      // 关闭所有输出
    // PWMA_CCER2 = 0x00;      // 关闭所有输出
    // PWMA_CCMR1 = 0x01;	    // 01:CC2 通道被配置为输入，IC2 映射在TI2 上
    // PWMA_CCMR2 = 0x01;      // 01:CC1 通道被配置为输入，IC1 映射在TI1 上
    // PWMA_CR1 |= 0x01; 		// 开启定时器，向上计数
      
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     带方向编码器初始化
// 参数说明     timer_ch        定时器枚举体
// 参数说明     phaseA          通道A以及引脚
// 参数说明     phaseB          通道B以及引脚
// 返回参数     void
// 备注信息   
// 使用示例     encoder_init_dir(PWMA_ENCODER, PWMA_ENCODER_CH1P_P60, PWMA_ENCODER_CH2P_P62)
//             // 使用PWMA 做正交解码使用， 通道1方向信号引脚P60，通道2脉冲信号引脚P62
//             encoder_init_dir(TIM17_ENCODER, TIM17_ENCODER_CH1_P80, IO_P45)
//             // 使用TIM17_ENCODER 读取编码器读取 ，脉冲信号引脚P80 ，方向信号引脚P45
//-------------------------------------------------------------------------------------------------------------------
void encoder_dir_init(uint16 encoder_n, uint16 lsb_pin, uint16 dir_pin)
{
    if(encoder_n >= TIM0_ENCODER)
    {
        // 传入的引脚错误
        zf_assert(!((uint16)dir_pin & 0xFF00));
        tim_encoder_dir_init((encoder_index_enum)encoder_n, (encoder_channel_enum)lsb_pin, (gpio_pin_enum)dir_pin);
    }
    else
    {
        pwm_encoder_dir_init((encoder_index_enum)encoder_n, (encoder_channel_enum)lsb_pin, (encoder_channel_enum)dir_pin);
    }
}
