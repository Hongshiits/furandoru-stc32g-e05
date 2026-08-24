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

#ifndef __ZF_DRIVER_UART_H
#define __ZF_DRIVER_UART_H


#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"
#include "zf_driver_timer.h"


#define	UART1_CLEAR_RX_FLAG (SCON  &= ~0x01)
#define	UART2_CLEAR_RX_FLAG (S2CON &= ~0x01)
#define	UART3_CLEAR_RX_FLAG (S3CON &= ~0x01)
#define	UART4_CLEAR_RX_FLAG (S4CON &= ~0x01)
#define	UART5_CLEAR_RX_FLAG (S5CON &= ~0x01)
#define	UART6_CLEAR_RX_FLAG (S6CON &= ~0x01)
#define	UART7_CLEAR_RX_FLAG (S7CON &= ~0x01)
#define	UART8_CLEAR_RX_FLAG (S8CON &= ~0x01)

#define	UART1_CLEAR_TX_FLAG (SCON  &= ~0x02)
#define	UART2_CLEAR_TX_FLAG (S2CON &= ~0x02)
#define	UART3_CLEAR_TX_FLAG (S3CON &= ~0x02)
#define	UART4_CLEAR_TX_FLAG (S4CON &= ~0x02)
#define	UART5_CLEAR_TX_FLAG (S5CON &= ~0x02)
#define	UART6_CLEAR_TX_FLAG (S6CON &= ~0x02)
#define	UART7_CLEAR_TX_FLAG (S7CON &= ~0x02)
#define	UART8_CLEAR_TX_FLAG (S8CON &= ~0x02)

#define UART1_GET_RX_FLAG   (SCON  & 0x01)
#define UART2_GET_RX_FLAG   (S2CON & 0x01)
#define UART3_GET_RX_FLAG   (S3CON & 0x01)
#define UART4_GET_RX_FLAG   (S4CON & 0x01)
#define UART5_GET_RX_FLAG   (S5CON & 0x01)
#define UART6_GET_RX_FLAG   (S6CON & 0x01)
#define UART7_GET_RX_FLAG   (S7CON & 0x01)
#define UART8_GET_RX_FLAG   (S8CON & 0x01)

#define UART1_GET_TX_FLAG   (SCON  & 0x02)
#define UART2_GET_TX_FLAG   (S2CON & 0x02)
#define UART3_GET_TX_FLAG   (S3CON & 0x02)
#define UART4_GET_TX_FLAG   (S4CON & 0x02)
#define UART5_GET_TX_FLAG   (S5CON & 0x02)
#define UART6_GET_TX_FLAG   (S6CON & 0x02)
#define UART7_GET_TX_FLAG   (S7CON & 0x02)
#define UART8_GET_TX_FLAG   (S8CON & 0x02)

//此枚举定义不允许用户修改
typedef enum //枚举串口号
{
    UART_1 = 0,         // 可使用TIM2或TIM1做比特率发生器
    UART_2,         // 可使用TIM2      做比特率发生器
    UART_3,         // 可使用TIM2或TIM3做比特率发生器
    UART_4,         // 可使用TIM2或TIM4做比特率发生器
    UART_5,         // 可使用TIM2或TIM5做比特率发生器
    UART_6,         // 可使用TIM2或TIM6做比特率发生器
    UART_7,         // 可使用TIM2或TIM7做比特率发生器
    UART_8,         // 可使用TIM2或TIM8做比特率发生器
	UART_RESERVE,	// 仅占位使用
} uart_index_enum;




//此枚举定义不允许用户修改
typedef enum //枚举串口引脚
{
    //只能使用同一行的RX和TX引脚号。不允许混用
    //例如:UART1_RX_P30,UART1_TX_P37。这样不行。
    UART1_RX_P30 = 0x0000 | IO_P30, UART1_TX_P31 = 0x0000 | IO_P31,		
    UART1_RX_P36 = 0x0100 | IO_P36, UART1_TX_P37 = 0x0100 | IO_P37,		
    UART1_RX_P16 = 0x0200 | IO_P16, UART1_TX_P17 = 0x0200 | IO_P17,
    UART1_RX_P43 = 0x0300 | IO_P43, UART1_TX_P44 = 0x0300 | IO_P44,
                                                               
    UART2_RX_P10 = 0x1000 | IO_P10, UART2_TX_P11 = 0x1000 | IO_P11,
    UART2_RX_P46 = 0x1100 | IO_P46, UART2_TX_P47 = 0x1100 | IO_P47,
    UART2_RX_P84 = 0x1200 | IO_P84, UART2_TX_P85 = 0x1200 | IO_P85,
    UART2_RX_PA0 = 0x1300 | IO_PA0, UART2_TX_PA1 = 0x1300 | IO_PA1,
    
    UART3_RX_P00 = 0x2000 | IO_P00, UART3_TX_P01 = 0x2000 | IO_P01,
    UART3_RX_P50 = 0x2100 | IO_P50, UART3_TX_P51 = 0x2100 | IO_P51,
    UART3_RX_P86 = 0x2200 | IO_P86, UART3_TX_P87 = 0x2200 | IO_P87,
    UART3_RX_PB6 = 0x2300 | IO_P50, UART3_TX_PB7 = 0x2300 | IO_PB7,
    
    UART4_RX_P02 = 0x3000 | IO_P02, UART4_TX_P03 = 0x3000 | IO_P03,
    UART4_RX_P52 = 0x3100 | IO_P52, UART4_TX_P53 = 0x3100 | IO_P53,
    UART4_RX_PA2 = 0x3200 | IO_PA2, UART4_TX_PA3 = 0x3200 | IO_PA3,
    UART4_RX_PC0 = 0x3300 | IO_P52, UART4_TX_PC1 = 0x3300 | IO_PC1,
    
    UART5_RX_P04 = 0x4000 | IO_P04, UART5_TX_P05 = 0x4000 | IO_P05,
    UART5_RX_P40 = 0x4100 | IO_P40, UART5_TX_P41 = 0x4100 | IO_P41,
    UART5_RX_P14 = 0x4200 | IO_P14, UART5_TX_P15 = 0x4200 | IO_P15,
    UART5_RX_P20 = 0x4300 | IO_P20, UART5_TX_P21 = 0x4300 | IO_P21,
    
    UART6_RX_P06 = 0x5000 | IO_P06, UART6_TX_P07 = 0x5000 | IO_P07,
    UART6_RX_P62 = 0x5100 | IO_P62, UART6_TX_P63 = 0x5100 | IO_P63,
    UART6_RX_P32 = 0x5200 | IO_P32, UART6_TX_P33 = 0x5200 | IO_P33,
    UART6_RX_P26 = 0x5300 | IO_P26, UART6_TX_P27 = 0x5300 | IO_P27,
    
    UART7_RX_P50 = 0x6000 | IO_P50, UART7_TX_P51 = 0x6000 | IO_P51,
    UART7_RX_PA4 = 0x6100 | IO_PA4, UART7_TX_PA5 = 0x6100 | IO_PA5,
    UART7_RX_P90 = 0x6200 | IO_P90, UART7_TX_P91 = 0x6200 | IO_P91,
    UART7_RX_P12 = 0x6300 | IO_P12, UART7_TX_P13 = 0x6300 | IO_P13,
    
    UART8_RX_P52 = 0x7000 | IO_P52, UART8_TX_P53 = 0x7000 | IO_P53,
    UART8_RX_PA6 = 0x7100 | IO_PA6, UART8_TX_PA7 = 0x7100 | IO_PA7,
    UART8_RX_P92 = 0x7200 | IO_P92, UART8_TX_P93 = 0x7200 | IO_P93,
    UART8_RX_P60 = 0x7300 | IO_P60, UART8_TX_P61 = 0x7300 | IO_P61,

} uart_pin_enum;



extern uart_callback_function uart_rx_handlers[UART_RESERVE];
extern uint8 xdata uart_rx_buff[UART_RESERVE][1];

void 	uart_rx_start_buff		(uart_index_enum uart_n);

void    uart_write_byte         (uart_index_enum uart_n, const uint8 dat);
void    uart_write_buffer       (uart_index_enum uart_n, const uint8 *buff, uint16 len);
void    uart_write_string       (uart_index_enum uart_n, const char *str);

uint8   uart_read_byte          (uart_index_enum uart_n);
uint8   uart_query_byte         (uart_index_enum uart_n, uint8 *dat);

//void    uart_tx_interrupt       (uart_index_enum uart_n, uint8 status); 暂不支持TX中断
void    uart_rx_interrupt       (uart_index_enum uart_n, uint8 status, uart_callback_function callback_handler);

void    uart_tim_init           (uart_index_enum uart_n, uint32 baud, uart_pin_enum tx_pin, uart_pin_enum rx_pin, timer_index_enum tim_n);
void    uart_init               (uart_index_enum uart_n, uint32 baud, uart_pin_enum tx_pin, uart_pin_enum rx_pin);

#endif