//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: main.c
// 文件描述: 
// 文件版本: V1.0
// 修改记录:
//   1. (2026-05-06) 创建文件
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#include "config.h"                     //默认已包含stdio.h、intrins.h等头文件


//<<AICUBE_USER_INCLUDE_BEGIN>>
// 在此添加用户头文件包含  
//<<AICUBE_USER_INCLUDE_END>>


//<<AICUBE_USER_GLOBAL_DEFINE_BEGIN>>
// 在此添加用户全局变量定义、用户宏定义以及函数声明  
#define OE1 P33 //使能1，2通道
#define MUX1 P32//切换1，2通道

#define OE2 P36//使能3，4通道
#define MUX2 P34//切换3，4通道

#define ROE P10 //电阻档位使能
#define RMUX P37 //电阻档位选择

#define ADC_RST P17 //采样保持电容清空

void R_GAIN(unsigned char gain);//档位切换，0对应5x，1对应20x，2对应50x
void MUX_CH(unsigned char ch);//选择通道，0~3对应外部的in0~in3

unsigned int ch_val[4] = {0};//用于存储四个通道的数据
//<<AICUBE_USER_GLOBAL_DEFINE_END>>



////////////////////////////////////////
// 项目主函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void main(void)
{
    //<<AICUBE_USER_MAIN_INITIAL_BEGIN>>
    // 在此添加用户主函数初始化代码  
    //<<AICUBE_USER_MAIN_INITIAL_END>>

    SYS_Init();

    //<<AICUBE_USER_MAIN_CODE_BEGIN>>
    // 在此添加主函数中运行一次的用户代码  
		R_GAIN(1);//这里可以调节放大倍率
		MUX_CH(0);
    //<<AICUBE_USER_MAIN_CODE_END>>

    while (1)
    {
        //<<AICUBE_USER_MAIN_LOOP_BEGIN>>
        // 在此添加主函数中用户主循环代码
				MUX_CH(0);
				ADC_RST = 0;
				delay_us(10);//清空电荷
				ADC_RST = 1;//恢复高阻状态
				delay_us(75);//等待1.5个周期，峰值保持电路充电
				ch_val[0] = ADC_Convert(3);
			
				
				MUX_CH(1);
				ADC_RST = 0;
				delay_us(10);//清空电荷
				ADC_RST = 1;//恢复高阻状态
				delay_us(75);//等待1.5个周期，峰值保持电路充电
				ch_val[1] = ADC_Convert(3);
			
				
				MUX_CH(2);
				ADC_RST = 0;
				delay_us(10);//清空电荷
				ADC_RST = 1;//恢复高阻状态
				delay_us(75);//等待1.5个周期，峰值保持电路充电
				ch_val[2] = ADC_Convert(3);
			
				
				MUX_CH(3);
				ADC_RST = 0;
				delay_us(10);//清空电荷
				ADC_RST = 1;//恢复高阻状态
				delay_us(75);//等待1.5个周期，峰值保持电路充电
				ch_val[3] = ADC_Convert(3);
				
				
				printf("%u,%u\r\n",ch_val[0],ch_val[1]);//输出
				//delay_ms(1);
        //<<AICUBE_USER_MAIN_LOOP_END>>
    }
}

////////////////////////////////////////
// 系统初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void SYS_Init(void)
{
    EnableAccessXFR();                  //使能访问扩展XFR
    IAP_SetTimeBase();                  //设置IAP等待参数,产生1us时基

    //<<AICUBE_USER_PREINITIAL_CODE_BEGIN>>
    // 在此添加用户预初始化代码  
    //<<AICUBE_USER_PREINITIAL_CODE_END>>

    P0M0 = 0x00; P0M1 = 0x00;           //初始化P0口为准双向口模式
    P1M0 = 0x00; P1M1 = 0x00;           //初始化P1口为准双向口模式
    P2M0 = 0x00; P2M1 = 0x00;           //初始化P2口为准双向口模式
    P3M0 = 0x00; P3M1 = 0x00;           //初始化P3口为准双向口模式
    P4M0 = 0x00; P4M1 = 0x00;           //初始化P4口为准双向口模式
    P5M0 = 0x00; P5M1 = 0x00;           //初始化P5口为准双向口模式
    P6M0 = 0x00; P6M1 = 0x00;           //初始化P6口为准双向口模式
    P7M0 = 0x00; P7M1 = 0x00;           //初始化P7口为准双向口模式

    PORT1_Init();                       //P1口初始化
    PORT3_Init();                       //P3口初始化
    CLK_Init();                         //时钟模块初始化
    UART1_Init();                       //串口1初始化
    ADC_Init();                         //ADC初始化

    //<<AICUBE_USER_INITIAL_CODE_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_INITIAL_CODE_END>>

    EnableGlobalInt();                  //使能全局中断
}

////////////////////////////////////////
// 微秒延时函数
// 入口参数: us (设置延时的微秒值)
// 函数返回: 无
////////////////////////////////////////
void delay_us(uint16_t us)
{
    do
    {
        NOP(30);                        //(MAIN_Fosc + 500000) / 1000000 - 10
    } while (--us);
}


////////////////////////////////////////
// 毫秒延时函数
// 入口参数: ms (设置延时的毫秒值)
// 函数返回: 无
////////////////////////////////////////
void delay_ms(uint16_t ms)
{
    uint16_t i;

    do
    {
        i = MAIN_Fosc / 10000;
        while (--i);
    } while (--ms);
}


//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
void R_GAIN(unsigned char gain)//档位切换，0对应5x，1对应20x，2对应50x
{
	if(gain==0){ROE = 1;}
	if(gain==1){ROE = 0;RMUX = 0;}
	if(gain==2){ROE = 0;RMUX = 1;}
}

void MUX_CH(unsigned char ch)//选择通道，0~3对应外部的in0~in3
{
	OE1 = 1; OE2 = 1;
	if(ch == 0){OE1 = 0;OE2 = 1;MUX1 = 0;}
	if(ch == 1){OE1 = 0;OE2 = 1;MUX1 = 1;}
	if(ch == 2){OE1 = 1;OE2 = 0;MUX2 = 0;}
	if(ch == 3){OE1 = 1;OE2 = 0;MUX2 = 1;}
	delay_us(50);//切换通道前等待一个周期，方便信号跟随，否则第一个周期的波形比较烂
}
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


