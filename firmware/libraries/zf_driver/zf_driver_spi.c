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
#pragma warning disable = 47

#include "zf_common_debug.h"
#include "zf_common_clock.h"
#include "zf_driver_gpio.h"
#include "zf_driver_spi.h"

#pragma warning disable = 183
#pragma warning disable = 177

/*
#define SPI0_WRITE_DAT(dat) 		\
		SPSTAT = 0xc0;              \
		SPDAT = dat;				\
		while (!(SPSTAT & 0x80));

#define SPI1_WRITE_DAT(dat) 		\
		TI = 0x0;              		\
		SBUF = dat;					\
		while (!TI)

#define SPI2_WRITE_DAT(dat) 		\
		S2TI = 0x0;              	\
		S2BUF = dat;				\
		while (!S2TI)
		
#define SPI_WRITE_DAT(spi_n, dat)	\
	switch (spi_n)					\
	{                               \
		case SPI_0:                 \
			SPI0_WRITE_DAT(dat);    \
			break;                  \
		case SPI_1:                 \
			SPI1_WRITE_DAT(dat);    \
			break;                  \
		case SPI_2:                 \
			SPI2_WRITE_DAT(dat);    \
			break;                  \
		default:                    \
			zf_assert(0);           \
			break;                  \
	}

*/



const vuint32 DMA_SPIx_STA_ADDR[] = 
{
    0x7efa22,
    0x7ef812,
    0x7ef832,
};


const vuint32 DMA_SPIx_CFG_ADDR[] = 
{
    0x7efa20,
    0x7ef810,
    0x7ef830,
};

const vuint32 DMA_SPIx_AMT_ADDR[] = 
{
    0x7efa23,
    0x7ef815,
    0x7ef835,
};

const vuint32 DMA_SPIx_AMTH_ADDR[] = 
{
    0x7efa84,
    0x7ef814,
    0x7ef834,
};

const vuint32 DMA_SPIx_TXAH_ADDR[] = 
{
    0x7efa25,
    0x7ef818,
    0x7ef838,
};

const vuint32 DMA_SPIx_TXAL_ADDR[] = 
{
    0x7efa26,
    0x7ef819,
    0x7ef839,
};

const vuint32 DMA_SPIx_RXAH_ADDR[] = 
{
    0x7efa27,
    0x7ef81a,
    0x7ef83a,
};

const vuint32 DMA_SPIx_RXAL_ADDR[] = 
{
    0x7efa28,
    0x7ef81b,
    0x7ef83b,
};

const vuint32 DMA_SPIx_ITVH_ADDR[] = 
{
    0x7efa2e,
    0x7ef81e,
    0x7ef83e,
};

const vuint32 DMA_SPIx_ITVL_ADDR[] = 
{
    0x7efa2f,
    0x7ef81f,
    0x7ef83f,
};

const vuint32 DMA_SPIx_CR_ADDR[] = 
{
    0x7efa21,
    0x7ef811,
    0x7ef831,
};

const vuint32 HSSPIX_CFG_ADDR[] = 
{
    0x7efbf8,
    0x7ef809,
    0x7ef829,
};

const vuint32 HSSPIX_CFG2_ADDR[] = 
{
    0x7efbf9,
    0x7ef80a,
    0x7ef82a,
};


const vuint32 SPIX_CLKDIV_ADDR[] = 
{
    0x7efe90,
    0x7ef808,
    0x7ef828,
};

#define DMA_SPIX_STA(pin)       (*(vuint8 far *)(DMA_SPIx_STA_ADDR[pin]))
#define DMA_SPIX_CFG(pin)       (*(vuint8 far *)(DMA_SPIx_CFG_ADDR[pin]))
#define DMA_SPIX_AMT(pin)       (*(vuint8 far *)(DMA_SPIx_AMT_ADDR[pin]))
#define DMA_SPIX_AMTH(pin)      (*(vuint8 far *)(DMA_SPIx_AMTH_ADDR[pin]))    
#define DMA_SPIX_TXAH(pin)      (*(vuint8 far *)(DMA_SPIx_TXAH_ADDR[pin]))
#define DMA_SPIX_TXAL(pin)      (*(vuint8 far *)(DMA_SPIx_TXAL_ADDR[pin]))
#define DMA_SPIX_RXAH(pin)      (*(vuint8 far *)(DMA_SPIx_RXAH_ADDR[pin]))
#define DMA_SPIX_RXAL(pin)      (*(vuint8 far *)(DMA_SPIx_RXAL_ADDR[pin]))
#define DMA_SPIX_ITVH(pin)      (*(vuint8 far *)(DMA_SPIx_ITVH_ADDR[pin]))
#define DMA_SPIX_ITVL(pin)      (*(vuint8 far *)(DMA_SPIx_ITVL_ADDR[pin]))
#define DMA_SPIX_CR(pin)        (*(vuint8 far *)(DMA_SPIx_CR_ADDR[pin]))

#define HSSPIX_CFG(pin)         (*(vuint8 far *)(HSSPIX_CFG_ADDR[pin]))
#define HSSPIX_CFG2(pin)        (*(vuint8 far *)(HSSPIX_CFG2_ADDR[pin]))
#define SPIX_CLKDIV(pin)        (*(vuint8 far *)(SPIX_CLKDIV_ADDR[pin]))

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI传输接口
// 返回参数     void
// 使用示例     内部使用，用户无需关心
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_transfer(spi_index_enum spi_n, uint8 *write_buffer, uint8 *read_buffer, uint32 len)
{
	#define BUFF_LEN 64
	
	// 因DMA只能操作xdata区域的数据，所以，这里新建一个数组，搬移。
	uint8 xdata tmp_buff[BUFF_LEN] = {0};
    uint16 tmp_len = 0;
    uint16 read_idx = 0;
    // 指针地址大于0x800000的时候，为FLASH地址
    // FLASH地址，不支持DMA搬移。
	if((uint32)write_buffer >= 0x800000)
    {
        while(len)
        {
            tmp_len = (len > BUFF_LEN) ? BUFF_LEN : len;                    		// 计算长度
            memcpy(tmp_buff, write_buffer, tmp_len);                        		// 拷贝
            len -= tmp_len;                                                 		// 去掉已经发送的长度
            write_buffer += tmp_len;                                        		// 指针指向后面
					
            DMA_SPIX_AMT(spi_n)  = (uint8)((tmp_len - 1) & 0xFF);	        		// 设置传输总字节数(低8位)：n+1
            DMA_SPIX_AMTH(spi_n) = (uint8)(((tmp_len - 1) & 0xFF00) >> 8);			// 设置传输总字节数(高8位)：n+1
		
            DMA_SPIX_TXAH(spi_n) = (uint8)((uint16)&tmp_buff[0] >> 8);	    		// SPI发送数据存储地址
            DMA_SPIX_TXAL(spi_n) = (uint8)((uint16)&tmp_buff[0]);
			
			DMA_SPIX_TXAH(spi_n) = (uint8)((uint16)&read_buffer[read_idx] >> 8);	// SPI接收数据存储地址
            DMA_SPIX_TXAL(spi_n) = (uint8)((uint16)&read_buffer[read_idx]);
			
            DMA_SPIX_CFG(spi_n)  = 1 << 6;                                  		// 发送数据
            DMA_SPIX_CR(spi_n)   = 0xC1;                                    		// 使能SPI_DMA 设置为主机模式 清空FIFO
            while(!(DMA_SPIX_STA(spi_n) & 0x01));		
            DMA_SPIX_STA(spi_n)  = 0;                                       		// 清空标志位
					
			read_idx += tmp_len;
        }
    }
	else
	{
		DMA_SPIX_AMT(spi_n)  = (uint8)((len - 1) & 0xFF);	            // 设置传输总字节数(低8位)：n+1
		DMA_SPIX_AMTH(spi_n) = (uint8)(((len - 1) & 0xFF00) >> 8);		// 设置传输总字节数(高8位)：n+1
		DMA_SPIX_TXAH(spi_n) = (uint8)((uint16)&write_buffer[0] >> 8);  // SPI发送数据存储地址
		DMA_SPIX_TXAL(spi_n) = (uint8)((uint16)&write_buffer[0]);
		DMA_SPIX_RXAH(spi_n) = (uint8)((uint16)&read_buffer[0] >> 8);	// SPI接收数据存储地址
		DMA_SPIX_RXAL(spi_n) = (uint8)((uint16)&read_buffer[0]);
		
		DMA_SPIX_CFG(spi_n)  = 1 << 6 | 1 <<5;                          // 发送数据，读取数据
		DMA_SPIX_CR(spi_n)   = 0xC1;                                    // 使能SPI_DMA 设置为主机模式 清空FIFO
		while(!(DMA_SPIX_STA(spi_n) & 0x01));
		DMA_SPIX_STA(spi_n)  = 0;                                       // 清空标志位
	}
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI写接口
// 返回参数     void
// 使用示例     内部使用，用户无需关心
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write(spi_index_enum spi_n, const uint8 *write_buffer, uint32 len)
{
    #define BUFF_LEN 64
	
	// 因DMA只能操作xdata区域的数据，所以，这里新建一个数组，搬移。
	uint8 xdata tmp_buff[BUFF_LEN] = {0};
    uint16 tmp_len = 0;

    // 指针地址大于0x800000的时候，为FLASH地址
    // FLASH地址，不支持DMA搬移。
    if((uint32)write_buffer >= 0x800000)
    {
        while(len)
        {
            tmp_len = (len > BUFF_LEN) ? BUFF_LEN : len;                    // 计算长度
            memcpy(tmp_buff, write_buffer, tmp_len);                               // 拷贝
            len -= tmp_len;                                                 // 去掉已经发送的长度
            write_buffer += tmp_len;                                               // 指针指向后面
            
            DMA_SPIX_AMT(spi_n)  = (uint8)((tmp_len - 1) & 0xFF);	        //设置传输总字节数(低8位)：n+1
            DMA_SPIX_AMTH(spi_n) = (uint8)(((tmp_len - 1) & 0xFF00) >> 8);	//设置传输总字节数(高8位)：n+1

            DMA_SPIX_TXAH(spi_n) = (uint8)((uint16)&tmp_buff[0] >> 8);	    // SPI发送数据存储地址
            DMA_SPIX_TXAL(spi_n) = (uint8)((uint16)&tmp_buff[0]);

            DMA_SPIX_CFG(spi_n)  = 1 << 6;                                  // 发送数据
            DMA_SPIX_CR(spi_n)   = 0xC1;                                    // 使能SPI_DMA 设置为主机模式 清空FIFO
            while(!(DMA_SPIX_STA(spi_n) & 0x01));
            DMA_SPIX_STA(spi_n)  = 0;                                       // 清空标志位
        }
    }
    else
    {
        DMA_SPIX_AMT(spi_n)  = (uint8)((len - 1) & 0xFF);	        	//设置传输总字节数(低8位)：n+1
        DMA_SPIX_AMTH(spi_n) = (uint8)(((len - 1) & 0xFF00) >> 8);		//设置传输总字节数(高8位)：n+1
	
        DMA_SPIX_TXAH(spi_n) = (uint8)((uint16)&write_buffer[0] >> 8);	    	// SPI发送数据存储地址
        DMA_SPIX_TXAL(spi_n) = (uint8)((uint16)&write_buffer[0]);

        DMA_SPIX_CFG(spi_n)  = 1 << 6;                                  // 发送数据
        DMA_SPIX_CR(spi_n)   = 0xC1;                                    // 使能SPI_DMA 设置为主机模式 清空FIFO
        while(!(DMA_SPIX_STA(spi_n) & 0x01));
        DMA_SPIX_STA(spi_n)  = 0;                                       // 清空标志位
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI读接口
// 返回参数     void
// 使用示例     内部使用，用户无需关心
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_read(spi_index_enum spi_n, const uint8 *read_buffer, uint32 len)
{
    DMA_SPIX_AMT(spi_n)  = (uint8)((len - 1) & 0xFF);	            //设置传输总字节数(低8位)：n+1
    DMA_SPIX_AMTH(spi_n) = (uint8)(((len - 1) & 0xFF00) >> 8);		//设置传输总字节数(高8位)：n+1
    DMA_SPIX_RXAH(spi_n) = (uint8)((uint16)&read_buffer[0] >> 8);	        // SPI接收数据存储地址
    DMA_SPIX_RXAL(spi_n) = (uint8)((uint16)&read_buffer[0]);

    DMA_SPIX_CFG(spi_n)  = 1 << 5;                                  // 读取数据
    DMA_SPIX_CR(spi_n)   = 0xC1;                                    // 使能SPI_DMA 设置为主机模式 清空FIFO
    while(!(DMA_SPIX_STA(spi_n) & 0x01));
    DMA_SPIX_STA(spi_n)  = 0;                                       // 清空标志位
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口写 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_8bit(SPI_1,0x11);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_8bit (spi_index_enum spi_n, const uint8 dat)
{
    spi_dma_write(spi_n, &dat, 1);	
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口写 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_8bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_8bit_array (spi_index_enum spi_n, const uint8 *dat, uint32 len)
{
    spi_dma_write(spi_n, dat, len);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口写 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_16bit(SPI_1,0x1101);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_16bit (spi_index_enum spi_n, const uint16 dat)
{
    spi_dma_write(spi_n, (uint8 *)&dat, 2);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口写 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_16bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_16bit_array (spi_index_enum spi_n, const uint16 *dat, uint32 len)
{
    spi_dma_write(spi_n, (uint8 *)&dat[0], len * 2);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI_DMA 接口向传感器的寄存器写 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_8bit_register(SPI_1,0x11,0x01);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_8bit_register (spi_index_enum spi_n, const uint8 register_name, const uint8 dat)
{
    spi_dma_write(spi_n, &register_name, 1);
    spi_dma_write(spi_n, &dat, 1);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口向传感器的寄存器写 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_8bit_registers(SPI_1,0x11,data,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_8bit_registers (spi_index_enum spi_n, const uint8 register_name, const uint8 *dat, uint32 len)
{
    spi_dma_write(spi_n, &register_name, 1);
    spi_dma_write(spi_n, dat, len);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口向传感器的寄存器写 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_16bit_register(SPI_1,0x1011,0x0101);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_16bit_register (spi_index_enum spi_n, const uint16 register_name, const uint16 dat)
{
    spi_dma_write(spi_n, (uint8 *)&register_name, 2);
    spi_dma_write(spi_n, (uint8 *)&dat, 2);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口向传感器的寄存器写 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_16bit_registers(SPI_1,0x1011,data,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_write_16bit_registers (spi_index_enum spi_n, const uint16 register_name, const uint16 *dat, uint32 len)
{
    spi_dma_write(spi_n, (uint8 *)&register_name, 2);
    spi_dma_write(spi_n, (uint8 *)&dat[0], len*2);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口读 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint8         数据
// 使用示例     spi_read_8bit(SPI_1);
//-------------------------------------------------------------------------------------------------------------------
uint8 spi_dma_read_8bit (spi_index_enum spi_n)
{
    uint8 value = 0;
    spi_dma_read(spi_n, &value, 1);
    return value;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口读 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_8bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_read_8bit_array (spi_index_enum spi_n, uint8 *dat, uint32 len)
{
    spi_dma_read(spi_n, dat, len);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口读 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint16        数据
// 使用示例     spi_read_16bit(SPI_1);
//-------------------------------------------------------------------------------------------------------------------
uint16 spi_dma_read_16bit (spi_index_enum spi_n)
{
    uint16 dat;
    spi_dma_read(spi_n, (uint8 *)&dat, 2);
    return dat;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口读 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_16bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_read_16bit_array (spi_index_enum spi_n, uint16 *dat, uint32 len)
{
    spi_dma_read(spi_n, (uint8 * )&dat[0], len*2);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口从传感器的寄存器读 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint8         数据
// 使用示例     spi_read_8bit_register(SPI_1,0x11);
//-------------------------------------------------------------------------------------------------------------------
uint8 spi_dma_read_8bit_register (spi_index_enum spi_n, const uint8 register_name)
{
    uint8 reg = 0;
    spi_dma_write(spi_n, &register_name, 1);
    spi_dma_read(spi_n, &reg, 1);
    return reg;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口从传感器的寄存器读 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_8bit_registers(SPI_1,0x11,data,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_read_8bit_registers (spi_index_enum spi_n, const uint8 register_name, uint8 *dat, uint32 len)
{
    spi_dma_write(spi_n, &register_name, 1);
    spi_dma_read(spi_n, dat, len);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口从传感器的寄存器读 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint16        数据
// 使用示例     spi_read_16bit_register(SPI_1,0x1011);
//-------------------------------------------------------------------------------------------------------------------
uint16 spi_dma_read_16bit_register (spi_index_enum spi_n, const uint16 register_name)
{
    uint16 dat;
    spi_dma_write(spi_n, (uint8 *)&register_name, 2);
    spi_dma_read(spi_n, (uint8 *)&dat, 2);
    return dat;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口从传感器的寄存器读 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *dat           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_16bit_registers(SPI_1,0x1101,dat,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_read_16bit_registers (spi_index_enum spi_n, const uint16 register_name, uint16 *dat, uint32 len)
{
    spi_dma_write(spi_n, (uint8 *)&register_name, 2);
    spi_dma_read(spi_n, (uint8 *)&dat[0], len);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 8bit 数据传输 发送与接收数据是同时进行的
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     write_buffer    发送的数据缓冲区地址
// 参数说明     read_buffer     发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_transfer_8bit(SPI_1,buf,buf,1);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_transfer_8bit (spi_index_enum spi_n, const uint8 *write_buffer, uint8 *read_buffer, uint32 len)
{
    spi_dma_transfer(spi_n, write_buffer, read_buffer, len);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 16bit 数据传输 发送与接收数据是同时进行的
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     write_buffer    发送的数据缓冲区地址
// 参数说明     read_buffer     发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_transfer_16bit(SPI_1,buf,buf,1);
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_transfer_16bit (spi_index_enum spi_n, const uint16 *write_buffer, uint16 *read_buffer, uint32 len)
{
    spi_dma_transfer(spi_n, (uint8 *)&write_buffer[0], (uint8 *)&read_buffer[0], len * 2);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI_DMA 接口初始化
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     mode            SPI_DMA 模式 参照 zf_driver_spi.h 内 spi_mode_enum 枚举体定义
// 参数说明     baud            设置 SPI_DMA 的波特率 不超过系统时钟的一半 部分速率会被适配成相近的速率
// 参数说明     sck_pin         选择 SCK 引脚 参照 zf_driver_spi.h 内 spi_pin_enum 枚举体定义
// 参数说明     mosi_pin        选择 MOSI 引脚 参照 zf_driver_spi.h 内 spi_pin_enum 枚举体定义
// 参数说明     miso_pin        选择 MISO 引脚 参照 zf_driver_spi.h 内 spi_pin_enum 枚举体定义
// 参数说明     cs_pin          选择 CS 引脚 参照 zf_driver_gpio.h 内 gpio_pin_enum 枚举体定义
// 返回参数     void
// 使用示例     spi_init(SPI_1, 0, 1*1000*1000, SPI1_SCK_A5, SPI1_MOSI_A7, SPI1_MISO_A6, A4);  //硬件SPI初始化  模式0 波特率为1Mhz
//-------------------------------------------------------------------------------------------------------------------
void spi_dma_init(spi_index_enum spi_n, spi_mode_enum mode, uint32 baud, spi_pin_enum sck_pin, spi_pin_enum mosi_pin, spi_pin_enum miso_pin, gpio_pin_enum cs_pin)
{
    // 使用SPI_DMA CLK频率就必须要两分频，所以这里填写时钟
    uint32 spi_psc = 0;
    
    if((sck_pin & 0xFF00) != (mosi_pin & 0xFF00))
    {
        zf_assert(0);
        // SPI只能使用同一组引脚，不允许混用引脚
    }
    
    gpio_init(sck_pin  & 0xFF, GPO, 1, GPO_PUSH_PULL);
    gpio_init(mosi_pin & 0xFF, GPO, 1, GPO_PUSH_PULL);
    
    if(miso_pin != SPI_NULL_PIN)
    {
        gpio_init(miso_pin & 0xFF, GPI, 1, GPI_PULL_UP);
    }
    
    if(cs_pin != SPI_NULL_PIN)
    {
        gpio_init(cs_pin & 0xFF, GPO, 0, GPO_PUSH_PULL);
    }

	// 波特率大于等于10M就需要设置GPIO电平转换速度
	if(baud >= (10*1000*1000U))
	{
		gpio_set_level_speed(sck_pin  & 0xFF, GPIO_SPEED_FAST);
		gpio_set_level_speed(mosi_pin  & 0xFF, GPIO_SPEED_FAST);
		if(miso_pin != SPI_NULL_PIN)
		{
			gpio_set_level_speed(miso_pin & 0xFF, GPIO_SPEED_FAST);
		}
		if(cs_pin != SPI_NULL_PIN)
		{
			gpio_set_level_speed(cs_pin & 0xFF, GPIO_SPEED_FAST);
		}
	}
    
    switch(spi_n)
    {
        case SPI_1:
        {
            P_SW1 &= ~(0x03 << 2); // 清除SPI_1引脚选择位
            switch((sck_pin >> 8) & 0x03) 
            {
                case 0: P_SW1 |= 0x00 << 2; break;
                case 1: P_SW1 |= 0x01 << 2; break;
                case 2: P_SW1 |= 0x02 << 2; break;
                case 3: P_SW1 |= 0x03 << 2; break;
            }

            SPCTL = 0; // 初始化SPI_1控制寄存器
            SPCTL |= (1 << 7) | (1 << 4); // 忽略SS引脚 + 主机模式
            
            SPCTL |= 0x03; // 时钟/2

            // 配置SPI_1极性相位
            switch(mode) 
            {
                case SPI_MODE1: SPCTL |= 0x01 << 2; break;
                case SPI_MODE2: SPCTL |= 0x02 << 2; break;
                case SPI_MODE3: SPCTL |= 0x03 << 2; break;
                default: break; // MODE0默认
            }
            SPCTL |= 1 << 6; // 使能SPI_1
            break;
        }
        
        case SPI_2:
        {
            P_SWX4 &= ~(0x03 << 0); // 清除SPI_2引脚选择位
            switch((sck_pin >> 8) & 0x03) 
            {
                case 0: P_SWX4 |= 0x00 << 0; break;
                case 1: P_SWX4 |= 0x01 << 0; break;
                case 2: P_SWX4 |= 0x02 << 0; break;
                case 3: P_SWX4 |= 0x03 << 0; break;
            }

            SPI2CTL = 0; // 初始化SPI_2控制寄存器
            SPI2CTL |= (1 << 7) | (1 << 4); // 忽略SS引脚 + 主机模式
            
            spi_psc = system_clock / baud;
            SPI2CTL |= 0x03; // 时钟/2

            // 配置SPI_2极性相位
            switch(mode) 
            {
                case SPI_MODE1: SPI2CTL |= 0x01 << 2; break;
                case SPI_MODE2: SPI2CTL |= 0x02 << 2; break;
                case SPI_MODE3: SPI2CTL |= 0x03 << 2; break;
                default: break; // MODE0默认
            }
            SPI2CTL |= 1 << 6; // 使能SPI_2
            break;
        }

        case SPI_3:
        {
            P_SWX4 &= ~(0x03 << 2); // 清除SPI_3引脚选择位
            switch((sck_pin >> 8) & 0x03) 
            {
                case 0: P_SWX4 |= 0x00 << 2; break;
                case 1: P_SWX4 |= 0x01 << 2; break;
                case 2: P_SWX4 |= 0x02 << 2; break;
                case 3: P_SWX4 |= 0x03 << 2; break;
            }

            SPI3CTL = 0; // 初始化SPI_3控制寄存器
            SPI3CTL |= (1 << 7) | (1 << 4); // 忽略SS引脚 + 主机模式
            
            
            SPI3CTL |= 0x03; // 时钟/2

            // 配置SPI_3极性相位
            switch(mode) 
            {
                case SPI_MODE1: SPI3CTL |= 0x01 << 2; break;
                case SPI_MODE2: SPI3CTL |= 0x02 << 2; break;
                case SPI_MODE3: SPI3CTL |= 0x03 << 2; break;
                default: break; // MODE0默认
            }
            SPI3CTL |= 1 << 6; // 使能SPI_3
            break;
        }

        default:
            // 无效SPI编号（可选：zf_assert(0);）
            break;
    }

    HSSPIX_CFG(spi_n) = 0;
    // HSSPI2_CFG2 = 1<<5 | 1<<4 | 1<< 7; // 使能SPI高速模式， 使能FIFO

    HSSPIX_CFG2(spi_n) = 0x10; // 使能SPI高速模式， 使能FIFO

    spi_psc = system_clock / baud + ((system_clock % baud) == 0? 0:1);
    if(spi_psc > 255) spi_psc = 255;
    SPIX_CLKDIV(spi_n) = spi_psc;
    
    DMA_SPIX_STA(spi_n)  = 0x00;
	DMA_SPIX_CFG(spi_n)  = 0x00;		// bit7->SPI_DMA中断 bit6->发送数据控制位 bit5->接受数据控制位 
                                        // bit[3:2] 中断优先级
                                        // bit[1:0] DMA总线优先级

    DMA_SPIX_ITVH(spi_n) = 0;
    DMA_SPIX_ITVL(spi_n) = 0;

	DMA_SPIX_CR(spi_n)   = 0xc1;		//bit7 1:使能 SPI_DMA, bit6 1:开始 SPI_DMA 主机模式,  bit5 1:开始 SPI_DMA 从机模式, bit0 1:清除 SPI_DMA FIFO
}

#define SPI_WRITE_DAT(spi_n, dat) spi_write_dat(spi_n, dat)
void spi_write_dat(spi_index_enum spi_n, const uint8 dat)
{
	switch (spi_n)					
	{                               
		case SPI_1:                 
            SPSTAT = 0xc0;              
			SPDAT = dat;				
			while (!(SPSTAT & 0x80));  
			break;                  
		case SPI_2:
            SPI2STAT = 0xc0;              
			SPI2DAT = dat;				
			while (!(SPI2STAT & 0x80));
			break;     
        case SPI_3:
            SPI3STAT = 0xc0;              
			SPI3DAT = dat;				
			while (!(SPI3STAT & 0x80));  
			break;           
		default:                    
			zf_assert(0);           
			break;                  
	}
}
	
#define SPI_READ_DAT(spi_n, dat) spi_read_dat(spi_n, dat)
uint8 spi_read_dat(spi_index_enum spi_n, const uint8 dat)
{
	uint8 ret = 0xFF;
	switch (spi_n)					
	{                               
		case SPI_1:                 
			SPSTAT = 0xc0;              
			SPDAT = dat;				
			while (!(SPSTAT & 0x80));  
			ret = SPDAT;
			break;             
		case SPI_2:
			SPI2STAT = 0xc0;              
			SPI2DAT = dat;				
			while (!(SPI2STAT & 0x80));  
			ret = SPI2DAT;
			break;   
        case SPI_3:
			SPI3STAT = 0xc0;              
			SPI3DAT = dat;				
			while (!(SPI3STAT & 0x80));  
			ret = SPI3DAT;
			break;         
		default:                    
			zf_assert(0);           
			break;                  
	}
	
	return ret;
}



//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口写 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_8bit(SPI_1,0x11);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_8bit (spi_index_enum spi_n, const uint8 dat)
{
	SPI_WRITE_DAT(spi_n, dat);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口写 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_8bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_8bit_array (spi_index_enum spi_n, const uint8 *dat, uint32 len)
{
	while(len--)
	{
		SPI_WRITE_DAT(spi_n, *dat++);
	}
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口写 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_16bit(SPI_1,0x1101);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_16bit (spi_index_enum spi_n, const uint16 dat)
{
	SPI_WRITE_DAT(spi_n, (uint8)((dat & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(dat & 0x00FF));
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口写 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_16bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_16bit_array (spi_index_enum spi_n, const uint16 *dat, uint32 len)
{
    while(len--)
    {
		SPI_WRITE_DAT(spi_n, (uint8)((*dat & 0xFF00) >> 8));
		SPI_WRITE_DAT(spi_n, (uint8)(*dat++ & 0x00FF));
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口向传感器的寄存器写 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_8bit_register(SPI_1,0x11,0x01);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_8bit_register (spi_index_enum spi_n, const uint8 register_name, const uint8 dat)
{
	SPI_WRITE_DAT(spi_n, register_name);
	SPI_WRITE_DAT(spi_n, dat);
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口向传感器的寄存器写 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_8bit_registers(SPI_1,0x11,data,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_8bit_registers (spi_index_enum spi_n, const uint8 register_name, const uint8 *dat, uint32 len)
{
	SPI_WRITE_DAT(spi_n, register_name);
    while(len--)
    {
		SPI_WRITE_DAT(spi_n, *dat++);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI 接口向传感器的寄存器写 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     data            数据
// 返回参数     void
// 使用示例     spi_write_16bit_register(SPI_1,0x1011,0x0101);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_16bit_register (spi_index_enum spi_n, const uint16 register_name, const uint16 dat)
{
	SPI_WRITE_DAT(spi_n, (uint8)((register_name & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(register_name & 0x00FF));
	SPI_WRITE_DAT(spi_n, (uint8)((dat & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(dat & 0x00FF));
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口向传感器的寄存器写 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_write_16bit_registers(SPI_1,0x1011,data,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_write_16bit_registers (spi_index_enum spi_n, const uint16 register_name, const uint16 *dat, uint32 len)
{
	SPI_WRITE_DAT(spi_n, (uint8)((register_name & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(register_name & 0x00FF));
	SPI_WRITE_DAT(spi_n, (uint8)((*dat & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(*dat++ & 0x00FF));
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口读 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint8         数据
// 使用示例     spi_read_8bit(SPI_1);
//-------------------------------------------------------------------------------------------------------------------
uint8 spi_read_8bit (spi_index_enum spi_n)
{
    return SPI_READ_DAT(spi_n, 0);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口读 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_8bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_read_8bit_array (spi_index_enum spi_n, uint8 *dat, uint32 len)
{
    while(len--)
    {
        *dat++ = SPI_READ_DAT(spi_n, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口读 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint16        数据
// 使用示例     spi_read_16bit(SPI_1);
//-------------------------------------------------------------------------------------------------------------------
uint16 spi_read_16bit (spi_index_enum spi_n)
{
    uint16 dat = 0;

    dat = SPI_READ_DAT(spi_n, 0);

    dat = ((dat << 8) | SPI_READ_DAT(spi_n, 0));
    
    return dat;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口读 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_16bit_array(SPI_1,data,64);
//-------------------------------------------------------------------------------------------------------------------
void spi_read_16bit_array (spi_index_enum spi_n, uint16 *dat, uint32 len)
{
    while(len--)
    {
        *dat = SPI_READ_DAT(spi_n, 0);
        *dat = ((*dat << 8) | SPI_READ_DAT(spi_n, 0));
        dat++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口从传感器的寄存器读 8bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint8         数据
// 使用示例     spi_read_8bit_register(SPI_1,0x11);
//-------------------------------------------------------------------------------------------------------------------
uint8 spi_read_8bit_register (spi_index_enum spi_n, const uint8 register_name)
{
	SPI_WRITE_DAT(spi_n, register_name);
    return SPI_READ_DAT(spi_n, 0);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口从传感器的寄存器读 8bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *data           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_8bit_registers(SPI_1,0x11,data,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_read_8bit_registers (spi_index_enum spi_n, const uint8 register_name, uint8 *dat, uint32 len)
{
	SPI_WRITE_DAT(spi_n, register_name);
    while(len--)
    {
        *dat++ = SPI_READ_DAT(spi_n, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口从传感器的寄存器读 16bit 数据
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 返回参数     uint16        数据
// 使用示例     spi_read_16bit_register(SPI_1,0x1011);
//-------------------------------------------------------------------------------------------------------------------
uint16 spi_read_16bit_register (spi_index_enum spi_n, const uint16 register_name)
{
    uint16 dat = 0;
    
	SPI_WRITE_DAT(spi_n, (uint8)((register_name & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(register_name & 0x00FF));
	
	dat = SPI_READ_DAT(spi_n, 0);
	dat = ((dat << 8) |  SPI_READ_DAT(spi_n, 0));

    return dat;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 接口从传感器的寄存器读 16bit 数组
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     register_name   寄存器地址
// 参数说明     *dat           数据存放缓冲区
// 参数说明     len             发送缓冲区长度
// 返回参数     void
// 使用示例     spi_read_16bit_registers(SPI_1,0x1101,dat,32);
//-------------------------------------------------------------------------------------------------------------------
void spi_read_16bit_registers (spi_index_enum spi_n, const uint16 register_name, uint16 *dat, uint32 len)
{
	SPI_WRITE_DAT(spi_n, (uint8)((register_name & 0xFF00) >> 8));
	SPI_WRITE_DAT(spi_n, (uint8)(register_name & 0x00FF));
    
    while(len--)
    {
		*dat = SPI_READ_DAT(spi_n, 0);
		*dat = ((*dat << 8) |  SPI_READ_DAT(spi_n, 0));
        dat++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 8bit 数据传输 发送与接收数据是同时进行的
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     write_buffer    发送的数据缓冲区地址
// 参数说明     read_buffer     发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_transfer_8bit(SPI_1,buf,buf,1);
//-------------------------------------------------------------------------------------------------------------------
void spi_transfer_8bit (spi_index_enum spi_n, const uint8 *write_buffer, uint8 *read_buffer, uint32 len)
{
    while(len--)
    {
        if(read_buffer != NULL)
        {
            *read_buffer++ = SPI_READ_DAT(spi_n, *(write_buffer++));
        }
		else
		{
			SPI_WRITE_DAT(spi_n, *(write_buffer++));
		}
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介      SPI 16bit 数据传输 发送与接收数据是同时进行的
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     write_buffer    发送的数据缓冲区地址
// 参数说明     read_buffer     发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
// 参数说明     len             缓冲区长度
// 返回参数     void
// 使用示例     spi_transfer_16bit(SPI_1,buf,buf,1);
//-------------------------------------------------------------------------------------------------------------------
void spi_transfer_16bit (spi_index_enum spi_n, const uint16 *write_buffer, uint16 *read_buffer, uint32 len)
{
    while(len--)
    {
		if(read_buffer != NULL)
        {
            *read_buffer = SPI_READ_DAT(spi_n, (uint8)((*write_buffer & 0xFF00) >> 8));
			*read_buffer = *read_buffer << 8 | (uint8)(SPI_READ_DAT(spi_n, (*write_buffer & 0x00FF)));
			read_buffer++;
        }
		else
		{
			SPI_WRITE_DAT(spi_n, (uint8)((*write_buffer & 0xFF00) >> 8));
			SPI_WRITE_DAT(spi_n, (uint8)(*write_buffer & 0x00FF));
		}
        write_buffer++;
    }
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     SPI 接口初始化
// 参数说明     spi_n           SPI 模块号 参照 zf_driver_spi.h 内 spi_index_enum 枚举体定义
// 参数说明     mode            SPI 模式 参照 zf_driver_spi.h 内 spi_mode_enum 枚举体定义
// 参数说明     baud            设置 SPI 的波特率 不超过系统时钟的一半 部分速率会被适配成相近的速率
// 参数说明     sck_pin         选择 SCK 引脚 参照 zf_driver_spi.h 内 spi_pin_enum 枚举体定义
// 参数说明     mosi_pin        选择 MOSI 引脚 参照 zf_driver_spi.h 内 spi_pin_enum 枚举体定义
// 参数说明     miso_pin        选择 MISO 引脚 参照 zf_driver_spi.h 内 spi_pin_enum 枚举体定义
// 参数说明     cs_pin          选择 CS 引脚 参照 zf_driver_gpio.h 内 gpio_pin_enum 枚举体定义
// 返回参数     void
// 使用示例     spi_init(SPI_1, 0, 1*1000*1000, SPI1_SCK_A5, SPI1_MOSI_A7, SPI1_MISO_A6, A4);  //硬件SPI初始化  模式0 波特率为1Mhz
//-------------------------------------------------------------------------------------------------------------------
void spi_init(spi_index_enum spi_n, spi_mode_enum mode, uint32 baud, spi_pin_enum sck_pin, spi_pin_enum mosi_pin, spi_pin_enum miso_pin, gpio_pin_enum cs_pin)
{
    uint32 spi_psc = 0;
    
    if((sck_pin & 0xFF00) != (mosi_pin & 0xFF00))
    {
        zf_assert(0);
        // SPI只能使用同一组引脚，不允许混用引脚
    }
    
    gpio_init(sck_pin  & 0xFF, GPO, 1, GPO_PUSH_PULL);
    gpio_init(mosi_pin & 0xFF, GPO, 1, GPO_PUSH_PULL);
    
    if(miso_pin != SPI_NULL_PIN)
    {
        gpio_init(miso_pin & 0xFF, GPI, 1, GPI_IMPEDANCE);
    }
    
    if(cs_pin != SPI_NULL_PIN)
    {
        gpio_init(cs_pin & 0xFF, GPO, 0, GPO_PUSH_PULL);
    }

	// 波特率大于等于10M就需要设置GPIO电平转换速度
	if(baud >= (10*1000*1000U))
	{
		gpio_set_level_speed(sck_pin  & 0xFF, GPIO_SPEED_FAST);
		gpio_set_level_speed(mosi_pin  & 0xFF, GPIO_SPEED_FAST);
		if(miso_pin != SPI_NULL_PIN)
		{
			gpio_set_level_speed(miso_pin & 0xFF, GPIO_SPEED_FAST);
		}
		if(cs_pin != SPI_NULL_PIN)
		{
			gpio_set_level_speed(cs_pin & 0xFF, GPIO_SPEED_FAST);
		}
	}
    
    switch(spi_n)
    {
        case SPI_1:
        {
            P_SW1 &= ~(0x03 << 2); // 清除SPI_1引脚选择位
            switch((sck_pin >> 8) & 0x03) 
            {
                case 0: P_SW1 |= 0x00 << 2; break;
                case 1: P_SW1 |= 0x01 << 2; break;
                case 2: P_SW1 |= 0x02 << 2; break;
                case 3: P_SW1 |= 0x03 << 2; break;
            }

            SPCTL = 0; // 初始化SPI_1控制寄存器
            SPCTL |= (1 << 7) | (1 << 4); // 忽略SS引脚 + 主机模式
            
            spi_psc = system_clock / baud;
//            if(spi_psc > 8) SPCTL |= 0x02;  // 时钟/16
//            else if(spi_psc > 4) SPCTL |= 0x01; // 时钟/8
//            else if(spi_psc > 2) SPCTL |= 0x00; // 时钟/4
//            else SPCTL |= 0x03; // 时钟/2
            

            SPI_CLKDIV = spi_psc / 2 + 1;
            // 配置SPI_1极性相位
            switch(mode) 
            {
                case SPI_MODE1: SPCTL |= 0x01 << 2; break;
                case SPI_MODE2: SPCTL |= 0x02 << 2; break;
                case SPI_MODE3: SPCTL |= 0x03 << 2; break;
                default: break; // MODE0默认
            }
            SPCTL |= 1 << 6; // 使能SPI_1
            break;
        }
        
        case SPI_2:
        {
            P_SWX4 &= ~(0x03 << 0); // 清除SPI_2引脚选择位
            switch((sck_pin >> 8) & 0x03) 
            {
                case 0: P_SWX4 |= 0x00 << 0; break;
                case 1: P_SWX4 |= 0x01 << 0; break;
                case 2: P_SWX4 |= 0x02 << 0; break;
                case 3: P_SWX4 |= 0x03 << 0; break;
            }

            SPI2CTL = 0; // 初始化SPI_2控制寄存器
            SPI2CTL |= (1 << 7) | (1 << 4); // 忽略SS引脚 + 主机模式
            
            spi_psc = system_clock / baud;
//            if(spi_psc > 8) SPI2CTL |= 0x02;  // 时钟/16
//            else if(spi_psc > 4) SPI2CTL |= 0x01; // 时钟/8
//            else if(spi_psc > 2) SPI2CTL |= 0x00; // 时钟/4
//            else SPI2CTL |= 0x03; // 时钟/2

            SPI2_CLKDIV = spi_psc / 2 + 1;
            // 配置SPI_2极性相位
            switch(mode) 
            {
                case SPI_MODE1: SPI2CTL |= 0x01 << 2; break;
                case SPI_MODE2: SPI2CTL |= 0x02 << 2; break;
                case SPI_MODE3: SPI2CTL |= 0x03 << 2; break;
                default: break; // MODE0默认
            }
            SPI2CTL |= 1 << 6; // 使能SPI_2
            break;
        }

        case SPI_3:
        {
            P_SWX4 &= ~(0x03 << 2); // 清除SPI_3引脚选择位
            switch((sck_pin >> 8) & 0x03) 
            {
                case 0: P_SWX4 |= 0x00 << 2; break;
                case 1: P_SWX4 |= 0x01 << 2; break;
                case 2: P_SWX4 |= 0x02 << 2; break;
                case 3: P_SWX4 |= 0x03 << 2; break;
            }

            SPI3CTL = 0; // 初始化SPI_3控制寄存器
            SPI3CTL |= (1 << 7) | (1 << 4); // 忽略SS引脚 + 主机模式
            
            spi_psc = system_clock / baud;
//            if(spi_psc > 8) SPI3CTL |= 0x02;  // 时钟/16
//            else if(spi_psc > 4) SPI3CTL |= 0x01; // 时钟/8
//            else if(spi_psc > 2) SPI3CTL |= 0x00; // 时钟/4
//            else SPI3CTL |= 0x03; // 时钟/2

            SPI3_CLKDIV = spi_psc / 2 + 1;
            
            // 配置SPI_3极性相位
            switch(mode) 
            {
                case SPI_MODE1: SPI3CTL |= 0x01 << 2; break;
                case SPI_MODE2: SPI3CTL |= 0x02 << 2; break;
                case SPI_MODE3: SPI3CTL |= 0x03 << 2; break;
                default: break; // MODE0默认
            }
            SPI3CTL |= 1 << 6; // 使能SPI_3
            break;
        }

        default:
            // 无效SPI编号（可选：zf_assert(0);）
            break;
    }   
}



