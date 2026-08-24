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

#include "zf_common_fifo.h"
#include "zf_common_debug.h"
#include "zf_common_clock.h"
#include "zf_common_interrupt.h"
#include "zf_common_typedef.h"

#include "zf_driver_uart.h"
#include "zf_driver_usb_cdc.h"
#include "zf_driver_delay.h"


#pragma warning disable = 183
#pragma warning disable = 177


#if DEBUG_UART_USE_INTERRUPT                                                    // 如果启用 debug uart 接收中断
    uint8                       debug_uart_buffer[DEBUG_RING_BUFFER_LEN];           // 数据存放数组
#endif

fifo_struct                 debug_uart_fifo;

static volatile uint8       zf_debug_init_flag = 1;
static volatile uint8       zf_debug_assert_enable = 1;

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     调试串口发送缓冲区
// 参数说明     *buff       读出数据存放的数组指针
// 参数说明     len         需要发送的长度
// 返回参数     uint32      剩余未发送的长度
// 使用示例
// 备注信息     本函数需要开启 DEBUG_UART_USE_INTERRUPT 宏定义才可使用
//-------------------------------------------------------------------------------------------------------------------
uint32 debug_send_buffer(const uint8 *buff, uint32 len)
{
    
#if(USER_USB_CDC)
    if(len > 0xFFFF)
	{
		usb_cdc_write_buffer(buff, 0xFFFF);
		return  len - 0xFFFF;
	}
	else
	{
		usb_cdc_write_buffer(buff, (uint16)len);
	}
    return 0;
#else
    if(len > 0xFFFF)
	{
		uart_write_buffer(DEBUG_UART_INDEX, buff, 0xFFFF);
		return  len - 0xFFFF;
	}
	else
	{
		uart_write_buffer(DEBUG_UART_INDEX, buff, (uint16)len);
	}
    
    return 0;
#endif

}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     读取 debug 环形缓冲区数据
// 参数说明     *buff       读出数据存放的数组指针
// 参数说明     len         需要读取的长度
// 返回参数     uint32      读出数据的实际长度
// 使用示例
// 备注信息     本函数需要开启 DEBUG_UART_USE_INTERRUPT 宏定义才可使用
//-------------------------------------------------------------------------------------------------------------------
uint32 debug_read_buffer (uint8 *buff, uint32 len)
{
    fifo_read_buffer(&debug_uart_fifo, buff, &len, FIFO_READ_AND_CLEAN);
    return len;
}
extern uint8 test_count ;
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     debug 串口中断处理函数 isr.c 中对应串口中断服务函数调用
// 参数说明     void
// 返回参数     void
// 使用示例     debug_interrupr_handler();
// 备注信息     本函数需要开启 DEBUG_UART_USE_INTERRUPT 宏定义才可使用
//              并且本函数默认放置在 UART1 的串口接收中断处理处
//-------------------------------------------------------------------------------------------------------------------
#if DEBUG_UART_USE_INTERRUPT                                                    // 条件编译 只有在启用串口中断才编译
    #if(USER_USB_CDC)
        void debug_interrupr_handler(uint8 *buff, uint16 len)
        {
            
            // 检测软件复位指令
            const uint8 reboot_str[8] = "@STCISP#";
            if(0 == strncmp(buff, reboot_str, 8))
            {
                EA = 0;
                CLKSEL = 0;             // 切换为默认系统时钟
                USBCON = 0;             // 清除USB设置
                USBCLK &= 0xF0;
                IRC48MCR = 0;           // 停止48M IRC时钟
                XOSCCR = 0;             // 停止外部时钟
                system_delay_ms(10);    // 等待USB总线复位
                IAP_CONTR = 0x60;       // 触发软件复位
            }
            
            if(zf_debug_init_flag)
            {
                fifo_write_buffer(&debug_uart_fifo, buff, len);               // 存入 FIFO
            }
        }
    #else
        void debug_interrupr_handler (uint8 dat)
        {
            if(zf_debug_init_flag)
            {
                uart_query_byte(DEBUG_UART_INDEX, &dat);                    // 读取串口数据
                fifo_write_buffer(&debug_uart_fifo, &dat, 1);               // 存入 FIFO
            }
        }
    #endif
#endif


//-------------------------------------------------------------------------     // printf 重定向 此部分不允许用户更改
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     printf重定向
// 参数说明     void
// 返回参数     void
//  @since      v1.0
// 备注信息              重定向printf到DEBUG串口上
//-------------------------------------------------------------------------------------------------------------------
#if(PRINTF_ENABLE)      //初始化调试串口
    //重定义printf 数字 只能输出uint16
    char putchar(char c)
    {
        #if(USER_USB_CDC)
            usb_cdc_write_byte(c);
            return c;
        #else
            uart_write_byte(DEBUG_UART_INDEX, c);//把自己实现的串口打印一字节数据的函数替换到这里
            return c;
        #endif

    }
#endif
//-------------------------------------------------------------------------     // printf 重定向 此部分不允许用户更改

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      debug 断言处理函数 此部分不允许用户更改
// 参数说明     pass        判断是否触发断言
// 参数说明     *file       文件名
// 参数说明     line        目标行数
// 返回参数     void
// 使用示例     zf_assert(0);
// 备注信息     这个函数不是直接调用的 此部分不允许用户更改
//              使用 zf_commmon_debug.h 中的 zf_assert(x) 接口
//-------------------------------------------------------------------------------------------------------------------
void debug_assert_handler (uint8 pass, char *file, int line)
{
	uint8 log_str[] = "Assert error";

	while(!pass)
	{
		// 如果代码跳转到这里停住了
		// 一般你的函数参数传递出错了
		// 或者你自己调用的 zf_assert(x) 接口处报错了

		// 如果调用了 debug_init 初始化了 log 输出
		// 就在对应串口输出去查看是哪个文件的哪一行报错

		// 如果没有初始化 debug
		// 那就看看这个 file 的字符串值和 line 的行数
		// 那代表报错的文件路径名称和对应报错行数

		// 再去调试看看是为什么参数出错


		printf("\r\n %s file %s line %d\r\n", log_str, file, line);


		system_delay_ms(500);
	}
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介      debug 串口初始化 此部分不允许用户更改
// 参数说明     void
// 返回参数     void
// 使用示例     debug_init();
// 备注信息     开源库示例默认调用 但默认禁用中断接收
//-------------------------------------------------------------------------------------------------------------------
void debug_init (void)
{
#if(USER_USB_CDC)
    usb_cdc_init();
    #if DEBUG_UART_USE_INTERRUPT                                               // 条件编译 只有在启用串口中断才编译
        fifo_init(&debug_uart_fifo, FIFO_DATA_8BIT, debug_uart_buffer, DEBUG_RING_BUFFER_LEN);
        usb_cdc_rx_interrupt(debug_interrupr_handler);
    #endif
#else
    uint8 uartx = DEBUG_UART_INDEX;
    
    uart_init(
        DEBUG_UART_INDEX,                                                       // 在 zf_common_debug.h 中查看对应值
        DEBUG_UART_BAUDRATE,                                                    // 在 zf_common_debug.h 中查看对应值
        DEBUG_UART_TX_PIN,                                                      // 在 zf_common_debug.h 中查看对应值
        DEBUG_UART_RX_PIN);                                                     // 在 zf_common_debug.h 中查看对应值
    
    #if DEBUG_UART_USE_INTERRUPT                                                // 条件编译 只有在启用串口中断才编译
        fifo_init(&debug_uart_fifo, FIFO_DATA_8BIT, debug_uart_buffer, DEBUG_RING_BUFFER_LEN);
        uart_rx_interrupt(DEBUG_UART_INDEX, 1, debug_interrupr_handler);                                     // 使能对应串口接收中断
    #endif   
#endif
}




