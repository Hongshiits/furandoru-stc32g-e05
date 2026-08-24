/*********************************************************************************************************************
* STC32G144K Opensourec Library 即（STC32G144K 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是STC 开源库的一部分
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

#ifndef __ZF_DRIVER_SPI_H
#define __ZF_DRIVER_SPI_H
#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"


// 该枚举体禁止用户修改
typedef enum
{
    SPI_1 = 0,
    SPI_2,
    SPI_3,

    //其中SS引脚由软件控制
} spi_index_enum;


// 该枚举体禁止用户修改
typedef enum
{
    // ---------------- SPI_1 ----------------//
    // SPI_1 只能使用同一组引脚，不允许混用引脚
    SPI1_CH1_SCLK_P15 = 0x0000 | IO_P15,
    SPI1_CH1_MOSI_P13 = 0x0000 | IO_P13,
    SPI1_CH1_MISO_P14 = 0x0000 | IO_P14,
    
    // SPI_1 只能使用同一组引脚，不允许混用引脚
    SPI1_CH2_SCLK_P25 = 0x0100 | IO_P25,
    SPI1_CH2_MOSI_P23 = 0x0100 | IO_P23,
    SPI1_CH2_MISO_P24 = 0x0100 | IO_P24,
    
    // SPI_1 只能使用同一组引脚，不允许混用引脚
    SPI1_CH3_SCLK_P43 = 0x0200 | IO_P43,
    SPI1_CH3_MOSI_P40 = 0x0200 | IO_P40,
    SPI1_CH3_MISO_P41 = 0x0200 | IO_P41,
    
    // SPI_1 只能使用同一组引脚，不允许混用引脚
    SPI1_CH4_SCLK_P32 = 0x0300 | IO_P32,
    SPI1_CH4_MOSI_P34 = 0x0300 | IO_P34,
    SPI1_CH4_MISO_P33 = 0x0300 | IO_P33,
    // ---------------- SPI_1 ----------------//
     
    // ---------------- SPI_2 ----------------//
    // SPI_2 只能使用同一组引脚，不允许混用引脚
    SPI2_CH1_SCLK_P67 = 0x1000 | IO_P67,
    SPI2_CH1_MOSI_P65 = 0x1000 | IO_P65,
    SPI2_CH1_MISO_P66 = 0x1000 | IO_P66,
    
    // SPI_2 只能使用同一组引脚，不允许混用引脚
    SPI2_CH2_SCLK_P05 = 0x1100 | IO_P05,
    SPI2_CH2_MOSI_P03 = 0x1100 | IO_P03,
    SPI2_CH2_MISO_P04 = 0x1100 | IO_P04,
    
    // SPI_2 只能使用同一组引脚，不允许混用引脚
    SPI2_CH3_SCLK_PB4 = 0x1200 | IO_PB4,
    SPI2_CH3_MOSI_PB2 = 0x1200 | IO_PB2,
    SPI2_CH3_MISO_PB3 = 0x1200 | IO_PB3,
    
    // SPI_2 只能使用同一组引脚，不允许混用引脚
    SPI2_CH4_SCLK_P83 = 0x1300 | IO_P83,
    SPI2_CH4_MOSI_P81 = 0x1300 | IO_P81,
    SPI2_CH4_MISO_P82 = 0x1300 | IO_P82,
    // ---------------- SPI_2 ----------------//
    
    // ---------------- SPI_3 ----------------//
    // SPI_3 只能使用同一组引脚，不允许混用引脚
    SPI3_CH1_SCLK_P25 = 0x2000 | IO_P25,
    SPI3_CH1_MOSI_P23 = 0x2000 | IO_P23,
    SPI3_CH1_MISO_P24 = 0x2000 | IO_P24,
    
    // SPI_3 只能使用同一组引脚，不允许混用引脚
    SPI3_CH2_SCLK_P73 = 0x2100 | IO_P73,
    SPI3_CH2_MOSI_P71 = 0x2100 | IO_P71,
    SPI3_CH2_MISO_P72 = 0x2100 | IO_P72,
    
    // SPI_3 只能使用同一组引脚，不允许混用引脚
    SPI3_CH3_SCLK_P87 = 0x2200 | IO_P87,
    SPI3_CH3_MOSI_P85 = 0x2200 | IO_P85,
    SPI3_CH3_MISO_P86 = 0x2200 | IO_P86,
    
    // SPI_3 只能使用同一组引脚，不允许混用引脚
    SPI3_CH4_SCLK_P93 = 0x2300 | IO_P93,
    SPI3_CH4_MOSI_P91 = 0x2300 | IO_P91,
    SPI3_CH4_MISO_P92 = 0x2300 | IO_P92,
    // ---------------- SPI_3 ----------------//
    
    SPI_NULL_PIN = 0xFFFF,
	SPI_MISO_NULL = 0xFFFF,
	SPI_CS_NULL = 0xFFFF,
    //其中CS引脚由软件控制
} spi_pin_enum;


//该枚举体禁止用户修改
typedef enum
{
    MASTER = 0,	 //主机
    SLAVE, //从机
} SPI_MSTR_enum;

//该枚举体禁止用户修改
typedef enum
{
    SPI_SYSclk_DIV_4 = 0,
    SPI_SYSclk_DIV_8,
    SPI_SYSclk_DIV_16,
    SPI_SYSclk_DIV_2,
} SPI_BAUD_enum;

typedef enum                                                                    // 枚举 SPI 模式 此枚举定义不允许用户修改
{
    SPI_MODE0,
    SPI_MODE1,
    SPI_MODE2,
    SPI_MODE3,
}spi_mode_enum;
//void spi_init(SPIN_enum spi_n,
//              SPI_PIN_enum sck_pin,
//              SPI_PIN_enum mosi_pin,
//              SPI_PIN_enum miso_pin,
//              uint8 mode,
//              SPI_MSTR_enum mstr,
//              SPI_BAUD_enum baud);

//void spi_change_pin(SPIN_enum spi_n,
//                    SPI_PIN_enum sck_pin,
//                    SPI_PIN_enum mosi_pin,
//                    SPI_PIN_enum miso_pin);

//void spi_change_mode(uint8 mode);

//uint8 spi_mosi(uint8 dat);

// ======================================================== SPI传输 ======================================================== //
void        spi_write_8bit                  (spi_index_enum spi_n, const uint8 dat);
void        spi_write_8bit_array            (spi_index_enum spi_n, const uint8 *dat, uint32 len);

void        spi_write_16bit                 (spi_index_enum spi_n, const uint16 dat);
void        spi_write_16bit_array           (spi_index_enum spi_n, const uint16 *dat, uint32 len);

void        spi_write_8bit_register         (spi_index_enum spi_n, const uint8 register_name, const uint8 dat);
void        spi_write_8bit_registers        (spi_index_enum spi_n, const uint8 register_name, const uint8 *dat, uint32 len);

void        spi_write_16bit_register        (spi_index_enum spi_n, const uint16 register_name, const uint16 dat);
void        spi_write_16bit_registers       (spi_index_enum spi_n, const uint16 register_name, const uint16 *dat, uint32 len);

uint8       spi_read_8bit                   (spi_index_enum spi_n);
void        spi_read_8bit_array             (spi_index_enum spi_n, uint8 *dat, uint32 len);

uint16      spi_read_16bit                  (spi_index_enum spi_n);
void        spi_read_16bit_array            (spi_index_enum spi_n, uint16 *dat, uint32 len);

uint8       spi_read_8bit_register          (spi_index_enum spi_n, const uint8 register_name);
void        spi_read_8bit_registers         (spi_index_enum spi_n, const uint8 register_name, uint8 *dat, uint32 len);

uint16      spi_read_16bit_register         (spi_index_enum spi_n, const uint16 register_name);
void        spi_read_16bit_registers        (spi_index_enum spi_n, const uint16 register_name, uint16 *dat, uint32 len);

void        spi_transfer_8bit               (spi_index_enum spi_n, const uint8 *write_buffer, uint8 *read_buffer, uint32 len);
void        spi_transfer_16bit              (spi_index_enum spi_n, const uint16 *write_buffer, uint16 *read_buffer, uint32 len);

void        spi_init                        (spi_index_enum spi_n, spi_mode_enum mode, uint32 baud, spi_pin_enum sck_pin, spi_pin_enum mosi_pin, spi_pin_enum miso_pin, gpio_pin_enum cs_pin);
// ======================================================== SPI传输 ======================================================== //

// ======================================================== SPI_DMA传输 ======================================================== //
// 注意事项：同一时刻就只允许有一个SPI DMA传输
void        spi_dma_write_8bit                  (spi_index_enum spi_n, const uint8 dat);
void        spi_dma_write_8bit_array            (spi_index_enum spi_n, const uint8 *dat, uint32 len);

void        spi_dma_write_16bit                 (spi_index_enum spi_n, const uint16 dat);
void        spi_dma_write_16bit_array           (spi_index_enum spi_n, const uint16 *dat, uint32 len);

void        spi_dma_write_8bit_register         (spi_index_enum spi_n, const uint8 register_name, const uint8 dat);
void        spi_dma_write_8bit_registers        (spi_index_enum spi_n, const uint8 register_name, const uint8 *dat, uint32 len);

void        spi_dma_write_16bit_register        (spi_index_enum spi_n, const uint16 register_name, const uint16 dat);
void        spi_dma_write_16bit_registers       (spi_index_enum spi_n, const uint16 register_name, const uint16 *dat, uint32 len);

uint8       spi_dma_read_8bit                   (spi_index_enum spi_n);
void        spi_dma_read_8bit_array             (spi_index_enum spi_n, uint8 *dat, uint32 len);

uint16      spi_dma_read_16bit                  (spi_index_enum spi_n);
void        spi_dma_read_16bit_array            (spi_index_enum spi_n, uint16 *dat, uint32 len);

uint8       spi_dma_read_8bit_register          (spi_index_enum spi_n, const uint8 register_name);
void        spi_dma_read_8bit_registers         (spi_index_enum spi_n, const uint8 register_name, uint8 *dat, uint32 len);

uint16      spi_dma_read_16bit_register         (spi_index_enum spi_n, const uint16 register_name);
void        spi_dma_read_16bit_registers        (spi_index_enum spi_n, const uint16 register_name, uint16 *dat, uint32 len);

void        spi_dma_transfer_8bit               (spi_index_enum spi_n, const uint8 *write_buffer, uint8 *read_buffer, uint32 len);
void        spi_dma_transfer_16bit              (spi_index_enum spi_n, const uint16 *write_buffer, uint16 *read_buffer, uint32 len);

void        spi_dma_init                        (spi_index_enum spi_n, spi_mode_enum mode, uint32 baud, spi_pin_enum sck_pin, spi_pin_enum mosi_pin, spi_pin_enum miso_pin, gpio_pin_enum cs_pin);
// ======================================================== SPI_DMA传输 ======================================================== //


#endif


