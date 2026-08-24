#ifndef _zf_device_mt9v03x_dma_h
#define _zf_device_mt9v03x_dma_h


#include "zf_common_debug.h"
#include "zf_common_clock.h"

// FIFO引脚禁止修改,除此之外摄像头的DMA还占用了P45 P36这两个引脚
// FIFO引脚禁止修改,除此之外摄像头的DMA还占用了P45 P36这两个引脚
// FIFO引脚禁止修改,除此之外摄像头的DMA还占用了P45 P36这两个引脚
#define         FIFO_VSY_PIN                    ( IO_P33 )
#define         FIFO_RCK_PIN                    ( IO_P37 )
#define         FIFO_WE_PIN                     ( IO_P41 )
#define         FIFO_WRST_PIN                   ( IO_P73 )
#define         FIFO_OE_PIN                     ( IO_P72 )
#define         FIFO_RRST_PIN                   ( IO_P43 )


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     总钻风内部接口
// 返回参数     void
// 使用示例     内部使用，用户无需关心
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
unsigned char   mt9v03x_sccb_check_id           (void *soft_iic_obj);
unsigned char   mt9v03x_sccb_set_config         (const short int buff[10][2]);
unsigned char   mt9v03x_sccb_set_exposure_time  (unsigned short int light);
unsigned char   mt9v03x_sccb_set_reg            (unsigned char addr, unsigned short int dat);


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     总钻风场中断回调函数
// 返回参数     void
// 使用示例     
// 备注信息     内部使用，用户无需关心
//-------------------------------------------------------------------------------------------------------------------
void mt9v03x_vsync_handler(void);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     总钻风DMA完成中断回调函数
// 返回参数     void
// 使用示例     
// 备注信息     内部使用，用户无需关心
//-------------------------------------------------------------------------------------------------------------------
void mt9v03x_dma_handler(void);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     总钻风DMA初始化
// 参数说明     image_addr            寄存器地址
// 参数说明     image_size            数据
// 参数说明     value                 内部参数，用户无需关心
// 参数说明     isr_priority          中断优先级，抢占式，0-3,3为最高
// 参数说明     dma_priority          DMA优先级，0-3,3为最高
// 返回参数     void
// 使用示例     mt9v03x_dma_init((uint8 *)&mt9v03x_image[0][0], MT9V03X_IMAGE_SIZE, 4, 3, 3);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
void mt9v03x_dma_init(unsigned char  *image_addr, uint32 image_size,unsigned char value, unsigned char isr_priority, unsigned char  dma_priority);

#endif
