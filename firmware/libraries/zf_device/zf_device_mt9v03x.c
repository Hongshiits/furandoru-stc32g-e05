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
* 2025-11-12        大W            first version
********************************************************************************************************************/


#include "zf_common_fifo.h"
#include "zf_common_interrupt.h"

#include "zf_driver_gpio.h"
#include "zf_driver_soft_iic.h"
#include "zf_driver_uart.h"
#include "zf_driver_delay.h"
#include "zf_driver_exti.h"

#include "zf_device_type.h"
#include "zf_device_config.h"
#include "zf_device_mt9v03x.h"
#include "zf_device_mt9v03x_dma.h"






// 需要配置到摄像头的数据 不允许在这修改参数
const int16 mt9v03x_set_confing_buffer[MT9V03X_CONFIG_FINISH][2]=
{
    {MT9V03X_INIT,              0},                                     // 摄像头开始初始化

    {MT9V03X_AUTO_EXP,          MT9V03X_AUTO_EXP_DEF},                  // 自动曝光设置
    {MT9V03X_EXP_TIME,          MT9V03X_EXP_TIME_DEF},                  // 曝光时间
    {MT9V03X_FPS,               MT9V03X_FPS_DEF},                       // 图像帧率
    {MT9V03X_SET_COL,           MT9V03X_W},                             // 图像列数量
    {MT9V03X_SET_ROW,           MT9V03X_H},                             // 图像行数量
    {MT9V03X_LR_OFFSET,         MT9V03X_LR_OFFSET_DEF},                 // 图像左右偏移量
    {MT9V03X_UD_OFFSET,         MT9V03X_UD_OFFSET_DEF},                 // 图像上下偏移量
    {MT9V03X_GAIN,              MT9V03X_GAIN_DEF},                      // 图像增益
};

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     单独设置摄像头曝光时间
// 参数说明     light           设定曝光时间
// 返回参数     uint8           1-失败 0-成功
// 使用示例     mt9v03x_set_exposure_time(100);                 // 调用该函数前请先初始化串口
// 备注信息     设置曝光时间越大图像越亮
//              摄像头收到后会根据分辨率及FPS计算最大曝光时间如果设置的数据过大
//              那么摄像头将会设置这个最大值
//-------------------------------------------------------------------------------------------------------------------
uint8 mt9v03x_set_exposure_time (uint16 light)
{
    uint8 return_state = mt9v03x_sccb_set_exposure_time(light);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     对摄像头内部寄存器进行写操作
// 参数说明     addr            摄像头内部寄存器地址
// 参数说明     dat            需要写入的数据
// 返回参数     uint8           1-失败 0-成功
// 使用示例     mt9v03x_set_reg(addr, dat);                    // 调用该函数前请先初始化串口
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
uint8 mt9v03x_set_reg (uint8 addr, uint16 dat)
{
    uint8 return_state = mt9v03x_sccb_set_reg(addr, dat);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     MT9V03X SCCB 初始化
// 参数说明     void
// 返回参数     uint8           0-成功 x-失败
// 使用示例     mt9v03x_sccb_init();
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
uint8 mt9v03x_sccb_init (void)
{
    uint8 return_state  = 1;
    soft_iic_info_struct mt9v03x_iic_struct;


    soft_iic_init(
        &mt9v03x_iic_struct, 0,
        MT9V03X_COF_IIC_DELAY,
        MT9V03X_COF_IIC_SCL,
        MT9V03X_COF_IIC_SDA);
    
    if(!mt9v03x_sccb_check_id(&mt9v03x_iic_struct))
    {

        return_state = mt9v03x_sccb_set_config(&mt9v03x_set_confing_buffer[0][0]);
    }

    return return_state;
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     MT9V03X 摄像头初始化
// 参数说明     void
// 返回参数     uint8           0-成功 x-失败
// 使用示例     mt9v03x_init();
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
uint8 mt9v03x_init (void)
{
    uint8 loop_count    = 0;
    uint8 return_state  = 0;
    
    do
    { 
        return_state = mt9v03x_sccb_init();

        if(!return_state)
        {
            gpio_init(MT9V03X_D0_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D1_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D2_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D3_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D4_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D5_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D6_PIN, GPI, GPIO_LOW, GPI_PULL_UP);
            gpio_init(MT9V03X_D7_PIN, GPI, GPIO_LOW, GPI_PULL_UP);

            gpio_init(FIFO_WE_PIN,   GPO, 0, GPO_PUSH_PULL);
            gpio_init(FIFO_WRST_PIN, GPO, 1, GPO_PUSH_PULL);
            gpio_init(FIFO_RCK_PIN,  GPO, 1, GPO_PUSH_PULL);
            gpio_init(FIFO_OE_PIN,   GPO, 0, GPO_PUSH_PULL);
            gpio_init(FIFO_RRST_PIN, GPO, 1, GPO_PUSH_PULL);
            gpio_init(FIFO_VSY_PIN,  GPI, 1, GPI_PULL_UP);

            // 默认中断优先级最高，DMA优先级最高
            mt9v03x_dma_init((uint8 *)&mt9v03x_image[0][0], MT9V03X_IMAGE_SIZE, 0, 3, 3);   
            
            exit_init(INT1_P33, BOTH);
            // 默认中断优先级最高
            interrupt_set_priority(INT1_IRQn, 3);                               
            
            break;
        }
    }while(0);
    
    return return_state;
}

