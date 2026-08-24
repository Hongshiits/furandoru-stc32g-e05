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
* 2024-xx-xx        优化           精简重复逻辑，适配SFR特性
********************************************************************************************************************/

#include "zf_common_debug.h"
#include "zf_driver_gpio.h"

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO设置推挽输出
// 参数说明     pin         引脚号选择的引脚
// 返回参数     void
// 使用示例     
//-------------------------------------------------------------------------------------------------------------------
static void gpio_set_push_pull(gpio_pin_enum pin)
{
    uint8 pin_bit = pin & 0x0F;
    uint8 port_flag = pin & 0xF0;

    // 统一高阻输入配置（PnM1置位，PnM0清零）
    switch(port_flag)
    {
        case IO_P00: P0M1 &= ~(1 << pin_bit); P0M0 |= (1 << pin_bit); break;
        case IO_P10: P1M1 &= ~(1 << pin_bit); P1M0 |= (1 << pin_bit); break;
        case IO_P20: P2M1 &= ~(1 << pin_bit); P2M0 |= (1 << pin_bit); break;
        case IO_P30: P3M1 &= ~(1 << pin_bit); P3M0 |= (1 << pin_bit); break;
        case IO_P40: P4M1 &= ~(1 << pin_bit); P4M0 |= (1 << pin_bit); break;
        case IO_P50: P5M1 &= ~(1 << pin_bit); P5M0 |= (1 << pin_bit); break;
        case IO_P60: P6M1 &= ~(1 << pin_bit); P6M0 |= (1 << pin_bit); break;
        case IO_P70: P7M1 &= ~(1 << pin_bit); P7M0 |= (1 << pin_bit); break;
        case IO_P80: P8M1 &= ~(1 << pin_bit); P8M0 |= (1 << pin_bit); break;
        case IO_P90: P9M1 &= ~(1 << pin_bit); P9M0 |= (1 << pin_bit); break;
        case IO_PA0: PAM1 &= ~(1 << pin_bit); PAM0 |= (1 << pin_bit); break;
        case IO_PB0: PBM1 &= ~(1 << pin_bit); PBM0 |= (1 << pin_bit); break;
        
        default: break; // 无效引脚
    }

}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO设置开漏
// 参数说明     pin         引脚号选择的引脚
// 返回参数     void
// 使用示例     
//-------------------------------------------------------------------------------------------------------------------
static void gpio_set_open_dtain(gpio_pin_enum pin)
{
    uint8 pin_bit = pin & 0x0F;
    uint8 port_flag = pin & 0xF0;

    // 统一高阻输入配置（PnM1置位，PnM0清零）
    switch(port_flag)
    {
        case IO_P00: P0M1 |= (1 << pin_bit); P0M0 |= (1 << pin_bit); break;
        case IO_P10: P1M1 |= (1 << pin_bit); P1M0 |= (1 << pin_bit); break;
        case IO_P20: P2M1 |= (1 << pin_bit); P2M0 |= (1 << pin_bit); break;
        case IO_P30: P3M1 |= (1 << pin_bit); P3M0 |= (1 << pin_bit); break;
        case IO_P40: P4M1 |= (1 << pin_bit); P4M0 |= (1 << pin_bit); break;
        case IO_P50: P5M1 |= (1 << pin_bit); P5M0 |= (1 << pin_bit); break;
        case IO_P60: P6M1 |= (1 << pin_bit); P6M0 |= (1 << pin_bit); break;
        case IO_P70: P7M1 |= (1 << pin_bit); P7M0 |= (1 << pin_bit); break;
        case IO_P80: P8M1 |= (1 << pin_bit); P8M0 |= (1 << pin_bit); break;
        case IO_P90: P9M1 |= (1 << pin_bit); P9M0 |= (1 << pin_bit); break;
        case IO_PA0: PAM1 |= (1 << pin_bit); PAM0 |= (1 << pin_bit); break;
        case IO_PB0: PBM1 |= (1 << pin_bit); PBM0 |= (1 << pin_bit); break;
        
        default: break; // 无效引脚
    }

}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO设置高阻输入
// 参数说明     pin         引脚号选择的引脚
// 返回参数     void
// 使用示例     
//-------------------------------------------------------------------------------------------------------------------
void gpio_set_impedance(gpio_pin_enum pin)
{
    uint8 pin_bit = pin & 0x0F;
    uint8 port_flag = pin & 0xF0;

    // 统一高阻输入配置（PnM1置位，PnM0清零）
    switch(port_flag)
    {
        case IO_P00: P0M1 |= (1 << pin_bit); P0M0 &= ~(1 << pin_bit); break;
        case IO_P10: P1M1 |= (1 << pin_bit); P1M0 &= ~(1 << pin_bit); break;
        case IO_P20: P2M1 |= (1 << pin_bit); P2M0 &= ~(1 << pin_bit); break;
        case IO_P30: P3M1 |= (1 << pin_bit); P3M0 &= ~(1 << pin_bit); break;
        case IO_P40: P4M1 |= (1 << pin_bit); P4M0 &= ~(1 << pin_bit); break;
        case IO_P50: P5M1 |= (1 << pin_bit); P5M0 &= ~(1 << pin_bit); break;
        case IO_P60: P6M1 |= (1 << pin_bit); P6M0 &= ~(1 << pin_bit); break;
        case IO_P70: P7M1 |= (1 << pin_bit); P7M0 &= ~(1 << pin_bit); break;
        case IO_P80: P8M1 |= (1 << pin_bit); P8M0 &= ~(1 << pin_bit); break;
        case IO_P90: P9M1 |= (1 << pin_bit); P9M0 &= ~(1 << pin_bit); break;
        case IO_PA0: PAM1 |= (1 << pin_bit); PAM0 &= ~(1 << pin_bit); break;
        case IO_PB0: PBM1 |= (1 << pin_bit); PBM0 &= ~(1 << pin_bit); break;
        
        default: break; // 无效引脚
    }
}

// 设置上拉电阻
static void gpio_set_up(gpio_pin_enum pin)
{
    // P0PU 0x7efe10
    // P8PU 0x7ef9c0
    if(pin < IO_P80)
    {
        (*(unsigned char volatile far *)(0x7efe10 + ((pin >> 4) - 1))) |= (1 << (pin & 0x0F));
    }
    else
    {
        (*(unsigned char volatile far *)(0x7ef9c0 + ((pin >> 4) - 9))) |= (1 << (pin & 0x0F));
    }
}

// 设置下拉电阻
static void gpio_set_pd(gpio_pin_enum pin)
{
    // P0PD 0x7efe40
    // P8PD 0x7ef9f0
    if(pin < IO_P80)
    {
        (*(unsigned char volatile far *)(0x7efe40 + ((pin >> 4) - 1))) |= (1 << (pin & 0x0F));
    }
    else
    {
        (*(unsigned char volatile far *)(0x7ef9f0 + ((pin >> 4) - 9))) |= (1 << (pin & 0x0F));
    }
}

//  端口驱动电流控制寄存器
static void gpio_set_dr(gpio_pin_enum pin, gpio_drive_capability_enum mode)
{
    switch(mode)
    {
        case GPIO_DRIVE_ENHANCE: 
        {
            if(pin < IO_P80)
            {
                (*(unsigned char volatile far *)(0x7efe28 + ((pin >> 4) - 1))) &= ~(1 << (pin & 0x0F));
            }
            else
            {
                (*(unsigned char volatile far *)(0x7ef9d8 + ((pin >> 4) - 9))) &= ~(1 << (pin & 0x0F));
            }
            break;
        }
        
        case GPIO_DRIVE_NORMOL: 
        {
            if(pin < IO_P80)
            {
                (*(unsigned char volatile far *)(0x7efe28 + ((pin >> 4) - 1))) |= (1 << (pin & 0x0F));
            }
            else
            {
                (*(unsigned char volatile far *)(0x7ef9d8 + ((pin >> 4) - 9))) |= (1 << (pin & 0x0F));
            }
            break;
        }
        
        default:
        {
            zf_assert(0);   // 参数不匹配
            break;          // 无效引脚
        }
    }
}

//  端口驱动电流控制寄存器
static void gpio_set_ie(gpio_pin_enum pin, gpio_port_digital_signal_input_enum mode)
{
    // 0：禁止数字信号输入。
    // 若I/O被当作比较器输入口、ADC输入口或者触摸按键输入口等模拟口时，
    // 进入主时钟停振/省电模式前，必须设置为0，否则会有额外的耗电。
    
    // 1：使能数字信号输入。若IO被当作数字口时，必须设置为1，否MCU无法读取外部端口的电平。

    switch(mode)
    {
        case GPIO_DIGITAL_IN_DISABLE: 
        {
            if(pin < IO_P80)
            {
                (*(unsigned char volatile far *)(0x7efe30 + ((pin >> 4) - 1))) &= ~(1 << (pin & 0x0F));
            }
            else
            {
                (*(unsigned char volatile far *)(0x7ef9e0 + ((pin >> 4) - 9))) &= ~(1 << (pin & 0x0F));
            }
            break;
        }
        
        case GPIO_DIGITAL_IN_ENABLE: 
        {
            if(pin < IO_P80)
            {
                (*(unsigned char volatile far *)(0x7efe30 + ((pin >> 4) - 1))) |= (1 << (pin & 0x0F));
            }
            else
            {
                (*(unsigned char volatile far *)(0x7ef9e0 + ((pin >> 4) - 9))) |= (1 << (pin & 0x0F));
            }
            break;
        }
        
        default:
        {
            zf_assert(0);   // 参数不匹配
            break;          // 无效引脚
        }
    }
}

// 内部使用，用户无需关心。
void gpio_set_level_speed(gpio_pin_enum pin, gpio_speed_enum speed)
{
    // P0SR 0x7efe20
    // P8SR 0x7ef9d0
    if(pin < IO_P00)
    {
        zf_assert(0); // 无效引脚
    }
    
    // 0:电平转换速度快，相应的上下冲会比较大
    // 1:电平转换速度慢，相应的上下冲会比较小
    if(GPIO_SPEED_FAST == speed)
    {
        if(pin < IO_P80)
        {
            (*(unsigned char volatile far *)(0x7efe20 + ((pin >> 4) - 1))) &= ~(1 << (pin & 0x0F));
        }
        else
        {
            (*(unsigned char volatile far *)(0x7ef9d0 + ((pin >> 4) - 9))) &= ~(1 << (pin & 0x0F));
        }
    }
    else
    {
        if(pin < IO_P80)
        {
            (*(unsigned char volatile far *)(0x7efe20 + ((pin >> 4) - 1))) |= (1 << (pin & 0x0F));
        }
        else
        {
            (*(unsigned char volatile far *)(0x7ef9d0 + ((pin >> 4) - 9))) |= (1 << (pin & 0x0F));
        }
    }
}



//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO状态获取
// 参数说明     pin         选择的引脚 (可选择范围由 zf_driver_gpio.h 内gpio_pin_enum枚举值确定)
// 返回参数     uint8       0：低电平 1：高电平
// 使用示例     uint8 status = gpio_get_level(IO_P00);//获取P00引脚电平
//-------------------------------------------------------------------------------------------------------------------
uint8 gpio_get_level(gpio_pin_enum pin)
{
    uint8 pin_bit = pin & 0x0F;
    uint8 port_flag = pin & 0xF0;
    uint8 status = 0;

    // 根据端口标志读取对应Pn寄存器
    switch(port_flag)
    {
        case IO_P00: status = P0 & (1 << pin_bit); break;
        case IO_P10: status = P1 & (1 << pin_bit); break;
        case IO_P20: status = P2 & (1 << pin_bit); break;
        case IO_P30: status = P3 & (1 << pin_bit); break;
        case IO_P40: status = P4 & (1 << pin_bit); break;
        case IO_P50: status = P5 & (1 << pin_bit); break;
        case IO_P60: status = P6 & (1 << pin_bit); break;
        case IO_P70: status = P7 & (1 << pin_bit); break;
        
        case IO_P80: status = P8IN & (1 << pin_bit); break;
        case IO_P90: status = P9IN & (1 << pin_bit); break;
        case IO_PA0: status = PAIN & (1 << pin_bit); break;
        case IO_PB0: status = PBIN & (1 << pin_bit); break;

        default: break; // 无效引脚
    }
    
    return status ? 1 : 0; // 转换为0/1返回
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO输出设置
// 参数说明     pin         引脚号选择的引脚 (可选择范围由 common.h 内GPIO_PIN_enum枚举值确定)
// 参数说明     dat         引脚的电平状态，输出时有效 0：低电平 1：高电平
// 返回参数     void
// 使用示例     gpio_set_level(D0, 0);//D0输出低电平
//-------------------------------------------------------------------------------------------------------------------
void gpio_set_level(gpio_pin_enum pin, uint8 dat)
{
    uint8 pin_bit = pin & 0x0F;
    uint8 port_flag = pin & 0xF0;

    // 三元运算符精简置位/清零逻辑
    switch(port_flag)
    {
        case IO_P00: dat ? (P0 |= (1 << pin_bit)) : (P0 &= ~(1 << pin_bit)); break;
        case IO_P10: dat ? (P1 |= (1 << pin_bit)) : (P1 &= ~(1 << pin_bit)); break;
        case IO_P20: dat ? (P2 |= (1 << pin_bit)) : (P2 &= ~(1 << pin_bit)); break;
        case IO_P30: dat ? (P3 |= (1 << pin_bit)) : (P3 &= ~(1 << pin_bit)); break;
        case IO_P40: dat ? (P4 |= (1 << pin_bit)) : (P4 &= ~(1 << pin_bit)); break;
        case IO_P50: dat ? (P5 |= (1 << pin_bit)) : (P5 &= ~(1 << pin_bit)); break;
        case IO_P60: dat ? (P6 |= (1 << pin_bit)) : (P6 &= ~(1 << pin_bit)); break;
        case IO_P70: dat ? (P7 |= (1 << pin_bit)) : (P7 &= ~(1 << pin_bit)); break;
        
        case IO_P80: dat ? (P8OUT |= (1 << pin_bit)) : (P8OUT &= ~(1 << pin_bit)); break;
        case IO_P90: dat ? (P9OUT |= (1 << pin_bit)) : (P9OUT &= ~(1 << pin_bit)); break;
        case IO_PA0: dat ? (PAOUT |= (1 << pin_bit)) : (PAOUT &= ~(1 << pin_bit)); break;
        case IO_PB0: dat ? (PBOUT |= (1 << pin_bit)) : (PBOUT &= ~(1 << pin_bit)); break;
        
        default: break; // 无效引脚
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO电平翻转
// 参数说明     pin         引脚号选择的引脚
// 返回参数     void
// 使用示例     gpio_toggle_level(D0);//翻转D0电平
//-------------------------------------------------------------------------------------------------------------------
void gpio_toggle_level(gpio_pin_enum pin)
{
    // 直接调用现有函数，逻辑清晰
    gpio_set_level(pin, !gpio_get_level(pin));
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     GPIO初始化
// 参数说明     pin         选择的引脚
// 参数说明     dir         引脚的方向   输出：GPO   输入：GPI
// 参数说明     dat         引脚初始化时设置的电平状态，输出时有效
// 参数说明     mode        引脚模式（上下拉/开漏等）
// 返回参数     void
// 使用示例     gpio_init(D0, GPO, 1, GPO_PUSH_PULL);//D0初始化为输出、高电平、推挽模式
//-------------------------------------------------------------------------------------------------------------------
void gpio_init(gpio_pin_enum pin, gpio_dir_enum dir, const uint8 dat, gpio_mode_enum mode)
{
	zf_assert(dir == ((uint8)mode >> 4));

    if(dir == GPI)
	{
		if(mode == GPI_IMPEDANCE)
		{
            gpio_set_impedance(pin);
            gpio_set_ie(pin, GPIO_DIGITAL_IN_ENABLE);
		}
		else if(mode == GPI_PULL_UP)
		{
            gpio_set_impedance(pin);
			gpio_set_up(pin); 
            gpio_set_ie(pin, GPIO_DIGITAL_IN_ENABLE);
//            gpio_set_level_speed(pin, GPIO_SPEED_FAST);
		}
        else if(mode == GPI_ANALOG)
        {
            gpio_set_impedance(pin);
            gpio_set_ie(pin, GPIO_DIGITAL_IN_DISABLE);
        }
        else if(mode == GPI_PULL_DOWN)
        {
            gpio_set_impedance(pin);
            gpio_set_pd(pin);
        }
	}
	else if(dir == GPO)
	{
		if(mode == GPO_PUSH_PULL)
		{
            gpio_set_push_pull(pin);
            gpio_set_dr(pin, GPIO_DRIVE_ENHANCE);
		}
		else if(mode == GPO_OPEN_DTAIN)
		{
			gpio_set_open_dtain(pin);
		}
        gpio_set_level(pin, dat);
	}

}
