/*********************************************************************************************************************
* RT1064DVL6A Opensourec Library 即（RT1064DVL6A 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是 RT1064DVL6A 开源库的一部分
*
* RT1064DVL6A 开源库 是免费软件
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
* 文件名称          zf_device_imu660rc
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          IAR 8.32.4 or MDK 5.38
* 适用平台          RT1064DVL6A
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者                备注
* 2025-12-12        SeekFree            first version
********************************************************************************************************************/
/*********************************************************************************************************************
* 接线定义：
*                   ------------------------------------
*                   模块管脚            单片机管脚
*                   // 硬件 SPI 引脚
*                   SCL/SPC           查看 zf_device_imu660rc.h 中 IMU660RC_SPC_PIN 宏定义
*                   SDA/DSI           查看 zf_device_imu660rc.h 中 IMU660RC_SDI_PIN 宏定义
*                   SA0/SDO           查看 zf_device_imu660rc.h 中 IMU660RC_SDO_PIN 宏定义
*                   CS                查看 zf_device_imu660rc.h 中 IMU660RC_CS_PIN 宏定义
*      							INT2              查看 zf_device_imu660rc.h 中 IMU660RC_INT2_PIN	宏定义
*                   VCC               3.3V电源
*                   GND               电源地
*                   其余引脚悬空
*
*                   // 软件 IIC 引脚
*                   SCL/SPC           查看 zf_device_imu660rc.h 中 IMU660RC_SCL_PIN 宏定义
*                   SDA/DSI           查看 zf_device_imu660rc.h 中 IMU660RC_SDA_PIN 宏定义
*                   VCC               3.3V电源
*                   GND               电源地
*                   其余引脚悬空
*                   ------------------------------------
********************************************************************************************************************/


#include "math.h"
#include "zf_common_debug.h"
#include "zf_driver_delay.h"
#include "zf_driver_spi.h"
#include "zf_driver_gpio.h"
#include "zf_driver_soft_iic.h"
#include "zf_device_config.h"
#include "zf_driver_uart.h"
#include "zf_driver_exti.h"
#include "zf_common_interrupt.h"
#include "zf_device_imu660rc.h"

#pragma warning disable = 183
#pragma warning disable = 177


#ifndef M_PI
#define M_PI 3.1415926f
#endif


static uint8 imu660rc_quarternion_rate;

float imu660rc_transition_factor[2];
int16 imu660rc_gyro_x = 0,  imu660rc_gyro_y = 0,    imu660rc_gyro_z = 0;    // 三轴陀螺仪数据   gyro (陀螺仪)
int16 imu660rc_acc_x  = 0,  imu660rc_acc_y  = 0,    imu660rc_acc_z  = 0;    // 三轴加速度计数据 acc  (accelerometer 加速度计)
float imu660rc_roll   = 0,  imu660rc_pitch  = 0,    imu660rc_yaw    = 0;    // 欧拉角
float imu660rc_quarternion[4];                                              // 四元数

#if (IMU660RC_USE_INTERFACE==HARDWARE_SPI) 
	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 写寄存器
	// 参数说明     reg             寄存器地址
	// 参数说明     dat            数据
	// 返回参数     void
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_write_register(uint8 reg, uint8 dat)
	{
		IMU660RC_CS(0);
		spi_write_8bit_register(IMU660RC_SPI, reg | IMU660RC_SPI_W, dat);
		IMU660RC_CS(1);
	}

	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 写数据
	// 参数说明     reg             寄存器地址
	// 参数说明     dat            数据
	// 返回参数     void
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_write_registers(uint8 reg, const uint8 *dat, uint32 len)
	{
		IMU660RC_CS(0);
		spi_write_8bit_registers(IMU660RC_SPI, reg | IMU660RC_SPI_W, dat, len);
		IMU660RC_CS(1);
	}

	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 读寄存器
	// 参数说明     reg             寄存器地址
	// 返回参数     uint8           数据
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static uint8 imu660rc_read_register(uint8 reg)
	{
        uint8 dat;
        IMU660RC_CS(0);
        dat = spi_read_8bit_register(IMU660RC_SPI, reg | IMU660RC_SPI_R);
        IMU660RC_CS(1);
        return dat;
	}

	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 读数据
	// 参数说明     reg             寄存器地址
	// 参数说明     dat            数据缓冲区
	// 参数说明     len             数据长度
	// 返回参数     void
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_read_registers(uint8 reg, uint8 *dat, uint32 len)
	{
        IMU660RC_CS(0);
        spi_read_8bit_registers(IMU660RC_SPI, reg | IMU660RC_SPI_R, dat, len);
        IMU660RC_CS(1);
	}


#elif (IMU660RC_USE_INTERFACE==SOFT_SPI)

	#define IMU660RC_SCK(x)				IMU660RC_SPC_PIN  = x
	#define IMU660RC_MOSI(x) 			IMU660RC_SDI_PIN = x
	#define IMU660RC_MISO    			IMU660RC_SDO_PIN
	#define IMU660RC_CS(x)  			IMU660RC_CS_PIN  = x

	//-------------------------------------------------------------------------------------------------------------------
	//  @brief      通过SPI写一个byte,同时读取一个byte
	//  @param      byte        发送的数据
	//  @return     uint8 edata       return 返回status状态
	//  @since      v1.0
	//  Sample usage:
	//-------------------------------------------------------------------------------------------------------------------
	static uint8 imu660rc_simspi_wr_byte(uint8 byte)
	{
		uint8 i;
		for(i=0; i<8; i++)
		{
			IMU660RC_SCK (0);
			IMU660RC_MOSI(byte&0x80);
			byte <<= 1;
			IMU660RC_SCK (1);
			byte |= IMU660RC_MISO;
		}
		IMU660RC_SCK (0);
		return(byte);
	}
	
	//-------------------------------------------------------------------------------------------------------------------
	//  @brief      将val写入cmd对应的寄存器地址,同时返回status字节
	//  @param      cmd         命令字
	//  @param      val         待写入寄存器的数值
	//  @since      v1.0
	//  Sample usage:
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_simspi_w_reg_byte(uint8 cmd, uint8 val)
	{
		cmd |= IMU660RC_SPI_W;
		imu660rc_simspi_wr_byte(cmd);
		imu660rc_simspi_wr_byte(val);
	}


	//-------------------------------------------------------------------------------------------------------------------
	//  @brief      将val写入cmd对应的寄存器地址
	//  @param      cmd         命令字
	//  @param      val         待写入寄存器的数值
	//  @since      v1.0
	//  Sample usage:
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_simspi_w_reg_bytes(uint8 cmd, uint8 *dat_addr, uint32 len)
	{
		cmd |= IMU660RC_SPI_W;
		imu660rc_simspi_wr_byte(cmd);
		while(len--)
		{
			imu660rc_simspi_wr_byte(*dat_addr++);
		}
	}

	//-------------------------------------------------------------------------------------------------------------------
	//  @brief      读取cmd所对应的寄存器地址
	//  @param      cmd         命令字
	//  @param      *val        存储读取的数据地址
	//  @param      num         读取的数量
	//  @since      v1.0
	//  Sample usage:
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_simspi_r_reg_bytes(uint8 cmd, uint8 *val, uint32 num)
	{
		cmd |= IMU660RC_SPI_R;
		imu660rc_simspi_wr_byte(cmd);
		while(num--)
		{
			*val++ = imu660rc_simspi_wr_byte(0);
		}
	}


	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 写寄存器
	// 参数说明     reg             寄存器地址
	// 参数说明     dat            数据
	// 返回参数     void
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_write_register(uint8 reg, uint8 dat)
	{
		IMU660RC_CS(0);
		imu660rc_simspi_w_reg_byte(reg | IMU660RC_SPI_W, dat);
		IMU660RC_CS(1);
	}

	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 写数据
	// 参数说明     reg             寄存器地址
	// 参数说明     dat            数据
	// 返回参数     void
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_write_registers(uint8 reg, const uint8 *dat, uint32 len)
	{
		IMU660RC_CS(0);
		imu660rc_simspi_w_reg_bytes(reg | IMU660RC_SPI_W, dat, len);
		IMU660RC_CS(1);
	}

	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 读寄存器
	// 参数说明     reg             寄存器地址
	// 返回参数     uint8 edata           数据
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static uint8 imu660rc_read_register(uint8 reg)
	{
        uint8 dat;
		IMU660RC_CS(0);
		imu660rc_simspi_r_reg_bytes(reg | IMU660RC_SPI_R, &dat, 1);
		IMU660RC_CS(1);
		return dat;
	}

	//-------------------------------------------------------------------------------------------------------------------
	// 函数简介     IMU660RC 读数据
	// 参数说明     reg             寄存器地址
	// 参数说明     dat            数据缓冲区
	// 参数说明     len             数据长度
	// 返回参数     void
	// 使用示例     
	// 备注信息     内部调用
	//-------------------------------------------------------------------------------------------------------------------
	static void imu660rc_read_registers(uint8 reg, uint8 *dat, uint32 len)
	{
		IMU660RC_CS(0);
		imu660rc_simspi_r_reg_bytes(reg | IMU660RC_SPI_R, dat, len);
		IMU660RC_CS(1);
	}
	
#elif (IMU660RC_USE_INTERFACE==SOFT_IIC)

	static soft_iic_info_struct imu660rc_iic_struct;
	#define imu660rc_write_register(reg, dat)        (soft_iic_write_8bit_register(&imu660rc_iic_struct, (reg), (dat)))
	#define imu660rc_write_registers(reg, dat, len)  (soft_iic_write_8bit_registers(&imu660rc_iic_struct, (reg), (dat), (len)))
	#define imu660rc_read_register(reg)              (soft_iic_read_8bit_register(&imu660rc_iic_struct, (reg)))
	#define imu660rc_read_registers(reg, dat, len)   (soft_iic_read_8bit_registers(&imu660rc_iic_struct, (reg), (dat), (len)))

#endif

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RC fp16转浮点数
// 参数说明     void
// 返回参数     uint8           
// 使用示例     
// 备注信息     内部调用
//-------------------------------------------------------------------------------------------------------------------
static uint32 fp16_to_float(uint16 h)
{
    uint32 f_sgn;
    uint16 h_exp;
    uint32 f_exp;
    uint32 f_sig;
    
    h_exp = (h & 0x7c00u);
    f_sgn = ((uint32)h & 0x8000u) << 16;
    switch (h_exp)
    {
        case 0x0000u:   // 0 or subnormal
        {
            uint16 h_sig = (h & 0x03ffu);
            // Signed zero
            if (h_sig == 0)
            {
                return f_sgn;
            }
            // Subnormal
            h_sig <<= 1;
            while ((h_sig & 0x0400u) == 0)
            {
                h_sig <<= 1;
                h_exp++;
            }
            f_exp = ((uint32)(127 - 15 - h_exp)) << 23;
            f_sig = ((uint32)(h_sig & 0x03ffu)) << 13;
            return f_sgn + f_exp + f_sig;
        }
        case 0x7c00u: // inf or NaN
        {
            // All-ones exponent and a copy of the significand
            return f_sgn + 0x7f800000u + (((uint32)(h & 0x03ffu)) << 13);
        }
        default: // normalized
        {
            // Just need to adjust the exponent and shift
            return f_sgn + (((uint32)(h & 0x7fffu) + 0x1c000u) << 13);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RC 四元数归一化
// 参数说明     void
// 返回参数     uint8           
// 使用示例     
// 备注信息     内部调用
//-------------------------------------------------------------------------------------------------------------------
static void quarternion_normalize(float quat[4], uint16 *fp16)
{
    float n = 0;
    float temp[4];
    
    *(uint32 *)(&temp[0]) = fp16_to_float(fp16[0]);
    *(uint32 *)(&temp[1]) = fp16_to_float(fp16[1]);
    *(uint32 *)(&temp[2]) = fp16_to_float(fp16[2]);
    *(uint32 *)(&temp[3]) = fp16_to_float(fp16[3]);
    
    n = temp[0] * temp[0] + temp[1] * temp[1] + temp[2] * temp[2] + temp[3] * temp[3];
    n = sqrt(n);
    
    if(n > 0.001f)  // 避免除以接近0的值
    {
        n = temp[3] < 0.0f ? -n : n;
        
        quat[0] = temp[1] / n;
        quat[1] = temp[2] / n;
        quat[2] = temp[0] / n;
        quat[3] = temp[3] / n;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RC 四元数转欧拉角
// 参数说明     void
// 返回参数     uint8           
// 使用示例     
// 备注信息     内部调用
//-------------------------------------------------------------------------------------------------------------------
static void quarternion_to_euler(float quat[4], float *roll, float *pitch, float *yaw)
{
    float euler[3];

  	float sqx = quat[0] * quat[0];
  	float sqy = quat[1] * quat[1];
  	float sqz = quat[2] * quat[2];

  	euler[0] =  atan2(2.0f * (quat[1] * quat[3] + quat[0] * quat[2]), 1.0f - 2.0f * (sqy + sqx));
  	euler[1] = -asin(2.0f * (quat[0] * quat[3] - quat[1] * quat[2]));
  	euler[2] =  atan2(2.0f * (quat[0] * quat[1] + quat[2] * quat[3]), 1.0f - 2.0f * (sqx + sqz));
    
    // 弧度转角度
    euler[0] = 180 * (euler[0]) / M_PI;
    euler[1] = 180 * (euler[1]) / M_PI;
    euler[2] = 180 * (euler[2]) / M_PI;
    
    // 角度调整
    euler[2] = 0 > euler[2] ? euler[2] + 360 : euler[2];
    
    *roll   = euler[0];
    *pitch  = euler[1];
    *yaw    = euler[2];
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RC 设置访问区域
// 参数说明     void
// 返回参数     uint8           
// 使用示例     
// 备注信息     内部调用
//-------------------------------------------------------------------------------------------------------------------
static void imu660rc_set_mem_bank (imu660rc_mem_bank_enum bank)
{
    imu660rc_write_register(IMU660RC_FUNC_CFG_ACCESS, (uint8)bank);
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RC 自检
// 参数说明     void
// 返回参数     uint8           1-自检失败 0-自检成功
// 使用示例     imu660rc_self_check();
// 备注信息     内部调用
//-------------------------------------------------------------------------------------------------------------------
static uint8 imu660rc_self_check (void)
{
    uint8 dat, return_state = 0;
    uint16 timeout_count = 0;
    do
    {
        if(IMU660RC_TIMEOUT_COUNT < timeout_count ++)
        {
            return_state =  1;
            break;
        }
        dat = imu660rc_read_register(IMU660RC_CHIP_ID);
        system_delay_ms(1);
    }while(0x70 != dat);                                                        // 读取设备ID是否等于0x70，如果不是0x70则认为没检测到设备
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RC 加速度计数据
// 参数说明     void
// 返回参数     void
// 使用示例     imu660rc_get_acc();                                             // 执行该函数后，直接查看对应的变量即可
// 备注信息     使用 SPI 的采集时间为10us
//-------------------------------------------------------------------------------------------------------------------
void imu660rc_get_acc (void)
{
    uint8 dat[6];
    if(IMU660RC_QUARTERNION_DISABLE == imu660rc_quarternion_rate)
    {   // 仅在四元数关闭状态下支持调用此函数， 四元数开启时如果需要读取加速度信息则IMU660RC_QUARTERNION_GET_ACC设置为1
        imu660rc_read_registers(IMU660RC_OUTX_L_A, dat, 6);
        imu660rc_acc_x =((uint16)dat[1] << 8) | dat[0];
        imu660rc_acc_y =((uint16)dat[3] << 8) | dat[2];
        imu660rc_acc_z =((uint16)dat[5] << 8) | dat[4];
    }
}
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RC 陀螺仪数据
// 参数说明     void
// 返回参数     void
// 使用示例     imu660rc_get_gyro();                                            // 执行该函数后，直接查看对应的变量即可
// 备注信息     使用 SPI 的采集时间为10us
//-------------------------------------------------------------------------------------------------------------------
void imu660rc_get_gyro (void)
{
    uint8 dat[6];
    if(IMU660RC_QUARTERNION_DISABLE == imu660rc_quarternion_rate)
    {   // 仅在四元数关闭状态下支持调用此函数， 四元数开启时如果需要读取加速度信息则IMU660RC_QUARTERNION_GET_GYRO设置为1
        imu660rc_read_registers(IMU660RC_OUTX_L_G, dat, 6);
        imu660rc_gyro_x = ((uint16)dat[1] << 8) | dat[0];
        imu660rc_gyro_y = ((uint16)dat[3] << 8) | dat[2];
        imu660rc_gyro_z = ((uint16)dat[5] << 8) | dat[4];
    }
}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RC 四元数数据并转换为欧拉角
// 参数说明     void
// 返回参数     void
// 使用示例     imu660rc_get_quarternion();                                     // 执行该函数后，直接查看对应的变量即可
// 备注信息     需要在INT2引脚触发的上升沿中断调用此函数
//             
//-------------------------------------------------------------------------------------------------------------------
void imu660rc_get_quarternion(void)
{
    uint8   i;
    uint16  buff[4];
    uint8   dat[6];
    uint8   *buff_ptr;

    if(IMU660RC_QUARTERNION_DISABLE != imu660rc_quarternion_rate)
    {
        buff_ptr = (uint8 *)buff;
        
        imu660rc_set_mem_bank(IMU660RC_EMBED_MEM_BANK);
        imu660rc_write_register(IMU660RC_PAGE_RW, 0x20);
        imu660rc_write_register(IMU660RC_PAGE_SEL, 0x31);

        for(i = 0; 4 > i; i++) 
        {
            imu660rc_write_register(0x08, (uint8)(0x4C + i * 2 + 0));
            buff_ptr[i * 2 + 1] = imu660rc_read_register(0x09);
            imu660rc_write_register(0x08, (uint8)(0x4C + i * 2 + 1));
            buff_ptr[i * 2 + 0] = imu660rc_read_register(0x09);
        }
        
        imu660rc_write_register(IMU660RC_PAGE_RW, 0x0);
        imu660rc_set_mem_bank(IMU660RC_MAIN_MEM_BANK);
        
        // 四元数归一化
        quarternion_normalize(imu660rc_quarternion, buff);
        // 四元数转欧拉角
        quarternion_to_euler(imu660rc_quarternion, &imu660rc_roll, &imu660rc_pitch, &imu660rc_yaw);
        
        // 读取加速度与角速度信息
        #if(1 == IMU660RC_QUARTERNION_GET_ACC)
        {
            imu660rc_read_registers(IMU660RC_OUTX_L_A, dat, 6);
            imu660rc_acc_x =((uint16)dat[1] << 8) | dat[0];
            imu660rc_acc_y =((uint16)dat[3] << 8) | dat[2];
            imu660rc_acc_z =((uint16)dat[5] << 8) | dat[4];
        }
        #endif
        #if(1 == IMU660RC_QUARTERNION_GET_GYRO)
        {
            imu660rc_read_registers(IMU660RC_OUTX_L_G, dat, 6);
            imu660rc_gyro_x = ((uint16)dat[1] << 8) | dat[0];
            imu660rc_gyro_y = ((uint16)dat[3] << 8) | dat[2];
            imu660rc_gyro_z = ((uint16)dat[5] << 8) | dat[4];
        }
        #endif
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RC中断回调函数，主要在中断内读取四元数
// 参数说明     void
// 返回参数     void
// 使用示例     
// 备注信息     此函数默认在INT2(P32)中断服务函数调用
//             
//-------------------------------------------------------------------------------------------------------------------
void imu660rc_callback(void)
{
    if(gpio_get_level(IMU660RC_INT2_PIN & 0xff))
    {
        imu660rc_get_quarternion();
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     初始化 IMU660RC
// 参数说明     void
// 返回参数     uint8           1-初始化失败 0-初始化成功
// 使用示例     imu660rc_init(IMU660RC_QUARTERNION_120HZ);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
uint8 imu660rc_init(imu660rc_quarternion_rate_config quarternion_rate)
{
    uint8 return_state = 0;

    imu660rc_quarternion_rate = quarternion_rate;
	
#if (IMU660RC_USE_INTERFACE==HARDWARE_SPI)   
    spi_init(IMU660RC_SPI, SPI_MODE0, IMU660RC_SPI_SPEED, IMU660RC_SPC_PIN, IMU660RC_SDI_PIN, IMU660RC_SDO_PIN, SPI_CS_NULL);   // 配置 IMU660RC 的 SPI 端口
    gpio_init(IMU660RC_CS_PIN, GPO, GPIO_HIGH, GPO_PUSH_PULL);                  // 配置 IMU660RC 的CS端口
#elif (IMU660RC_USE_INTERFACE==SOFT_SPI)
    // 默认使用双向IO，不需要初始化。
    // soft_spi_init (IMU660RC_SPI, SPI_MODE0, 0, IMU660RC_SPC_PIN, IMU660RC_SDI_PIN, IMU660RC_SDO_PIN, IMU660RC_CS_PIN);
#elif (IMU660RC_USE_INTERFACE==SOFT_IIC)
    soft_iic_init(&imu660rc_iic_struct, IMU660RC_DEV_ADDR, IMU660RC_SOFT_IIC_DELAY, IMU660RC_SCL_PIN, IMU660RC_SDA_PIN);        // 配置 IMU660RC 的 IIC 端口
#endif

    system_delay_ms(10);

    do
    {
        if(imu660rc_self_check())                                               // IMU660RC 自检
        {
            // 如果程序在输出了断言信息 并且提示出错位置在这里
            // 那么就是 IMU660RC 自检出错并超时退出了
            // 检查一下接线有没有问题 如果没问题可能就是坏了
            printf("imu660rc self check error.");
            return_state = 1;
            break;
        }
                
        // 复位传感器
        imu660rc_write_register(IMU660RC_FUNC_CFG_ACCESS, 0x04);
        system_delay_ms(30);

        // 启用块更新功能与地址递增
        imu660rc_write_register(IMU660RC_CTRL3, 0x44);
        
        switch(IMU660RC_ACC_SAMPLE_DEFAULT)
        {
            default:
            {
                printf("IMU660RC_ACC_SAMPLE_DEFAULT set error.");
                return_state = 1;
            }break;
            case IMU660RC_ACC_SAMPLE_SGN_2G:
            {
                imu660rc_write_register(IMU660RC_CTRL8, 0x00);
                imu660rc_transition_factor[0] = 16393.44;
            }break;
            case IMU660RC_ACC_SAMPLE_SGN_4G:
            {
                imu660rc_write_register(IMU660RC_CTRL8, 0x01);
                imu660rc_transition_factor[0] = 8196.72;
            }break;
            case IMU660RC_ACC_SAMPLE_SGN_8G:
            {
                imu660rc_write_register(IMU660RC_CTRL8, 0x02);
                imu660rc_transition_factor[0] = 4098.36;
            }break;
            case IMU660RC_ACC_SAMPLE_SGN_16G:
            {
                imu660rc_write_register(IMU660RC_CTRL8, 0x03);
                imu660rc_transition_factor[0] = 2049.18;
            }break;
        }
        if(1 == return_state)
        {
            break;
        }
        
        switch(IMU660RC_GYRO_SAMPLE_DEFAULT)
        {
            default:
            {
                printf("IMU660RC_GYRO_SAMPLE_DEFAULT set error.");
                return_state = 1;
            }break;
            case IMU660RC_GYRO_SAMPLE_SGN_125DPS:
            {
                imu660rc_write_register(IMU660RC_CTRL6, 0x00);
                imu660rc_transition_factor[1] = 228.5714;
            }break;
            case IMU660RC_GYRO_SAMPLE_SGN_250DPS:
            {
                imu660rc_write_register(IMU660RC_CTRL6, 0x01);
                imu660rc_transition_factor[1] = 114.2857;
            }break;
            case IMU660RC_GYRO_SAMPLE_SGN_500DPS:
            {
                imu660rc_write_register(IMU660RC_CTRL6, 0x02);
                imu660rc_transition_factor[1] = 57.1428;
            }break;
            case IMU660RC_GYRO_SAMPLE_SGN_1000DPS:
            {
                imu660rc_write_register(IMU660RC_CTRL6, 0x03);
                imu660rc_transition_factor[1] = 28.5714;
            }break;
            case IMU660RC_GYRO_SAMPLE_SGN_2000DPS:
            {
                imu660rc_write_register(IMU660RC_CTRL6, 0x04);
                imu660rc_transition_factor[1] = 14.2857;
            }break;
            case IMU660RC_GYRO_SAMPLE_SGN_4000DPS:
            {
                imu660rc_write_register(IMU660RC_CTRL6, 0x0C);
                imu660rc_transition_factor[1] = 7.14285;
            }break;
        }
        if(1 == return_state)
        {
            break;
        }
        
        // 设置传感器模式，设置为高精度模式以及输出速率
        imu660rc_write_register(IMU660RC_CTRL1, 0x15);
        imu660rc_write_register(IMU660RC_CTRL2, 0x18);
        
        // 开启LPF1滤波器
        imu660rc_write_register(IMU660RC_CTRL7, 0x01);
        
        // 开启LPF2滤波器
        imu660rc_write_register(IMU660RC_CTRL9, 0x08);
        

        
        // 如果启用四元数输出，则配置相应数据
        if(IMU660RC_QUARTERNION_DISABLE != quarternion_rate)
        {
            // 设置中断触发信号
            imu660rc_write_register(IMU660RC_INT2_CTRL, 0x80);
            imu660rc_write_register(IMU660RC_CTRL4, 0x08);
            imu660rc_write_register(IMU660RC_EMB_FUNC_CFG, 0x30);
            
            // 重新配置加速度、角速度输出速率
            imu660rc_write_register(IMU660RC_CTRL1, 0x10 | (quarternion_rate + 3));
            imu660rc_write_register(IMU660RC_CTRL2, 0x10 | (quarternion_rate + 3));
            
            // 设置四元数输出速率并开启
            imu660rc_set_mem_bank(IMU660RC_EMBED_MEM_BANK);
            imu660rc_write_register(IMU660RC_SFLP_ODR, 0x43 | (quarternion_rate << 3));
            imu660rc_write_register(IMU660RC_EMB_FUNC_EN_A, 0x02);
            imu660rc_write_register(IMU660RC_PAGE_RW, 0x00);
            imu660rc_set_mem_bank(IMU660RC_MAIN_MEM_BANK);
            
            // 开启中断检测引脚
            int_irq_handlers[0] = imu660rc_callback;
            exit_init(IMU660RC_INT2_PIN,BOTH);
			
			switch(IMU660RC_INT2_PIN)
			{
				case INT0_P32: interrupt_set_priority(INT0_IRQn, 2); break;
				case INT1_P33: interrupt_set_priority(INT1_IRQn, 2); break;
				default: break;
			}
        }
        
    }while(0);
    
    return return_state;
}
