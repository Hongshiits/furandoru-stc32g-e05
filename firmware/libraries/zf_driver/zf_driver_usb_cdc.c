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

#include "stdlib.h"
#include "zf_common_clock.h"
#include "zf_common_debug.h"

#include "zf_driver_usb_cdc.h"
#include "zf_driver_gpio.h"
#include "stc.h"
#include "usb.h"

void usb_cdc_init()
{
    usb_init();
}


// 返回剩余字节数
uint16 usb_cdc_write_buffer(const uint8 *buff, uint16 len)
{
    int32 timeout = USB_TIME_OUT_COUNT;
    vuint8 tmp_len = 0;
    vuint8 idx = 0;
    
    // 设备没有加载成功，直接返回
    if (DeviceState != DEVSTATE_CONFIGURED)
        return len;
    
    while(len > 0)
    {
        timeout = USB_TIME_OUT_COUNT;
        tmp_len = (len >= 64) ? 64 : len;
        
        UsbInBusy = 1;
        // 关闭USB中断
        EUSB = 0;
        // 设置端点索引
        usb_write_reg(INDEX, 1);
        // 将数据写入FIFO
        
        for(idx=0; idx < tmp_len; idx ++)
        {
            usb_write_reg(FIFO1, *buff++);
        }
//        usb_write_fifo(FIFO1, buff, tmp_len);
        // IN数据包准备完成
        usb_write_reg(INCSR1, INIPRDY);
        // 开启USB中断
        EUSB = 1;
        
        // 等待发送完成，或者超时
        while(UsbInBusy && timeout--);
        
        // 超时则发送失败，直接返回剩余字节数
        if(timeout <= 0)
        {
            return len;
        }
        else
        {
            len = len - tmp_len;
        }
    }

    return 0;
}
    
void usb_cdc_write_byte(const uint8 dat)
{
    usb_cdc_write_buffer(&dat, 1);
}

uint16 usb_cdc_write_string(const char *str)
{
    uint16 len = strlen(str);
    return usb_cdc_write_buffer(str, len);
}

void (*usb_cdc_read_buffer_handler)(uint8 *buff, uint16 len) = NULL;


void usb_cdc_rx_interrupt(void (*handler)(uint8 *buff, uint16 len))
{
    // 设置中断回调函数
    usb_cdc_read_buffer_handler = handler;
}
//            if(UsbInBusy == 0)
//            {
//                UsbInBusy = 1;
//                
//                // 关闭USB中断
//                EUSB = 0;
//                // 设置端点索引
//                usb_write_reg(INDEX, 1);
//                // 将数据写入FIFO
//                usb_write_fifo(FIFO1, str, 10);
//                // IN数据包准备完成
//                usb_write_reg(INCSR1, INIPRDY);
//                // 开启USB中断
//                EUSB = 1;
//            }


