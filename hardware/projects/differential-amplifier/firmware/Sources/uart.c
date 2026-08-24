//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: uart.c
// 文件描述: 
// 文件版本: V1.0
// 修改记录:
//   1. (2026-05-06) 创建文件
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#include "config.h"


//<<AICUBE_USER_INCLUDE_BEGIN>>
// 在此添加用户头文件包含  
//<<AICUBE_USER_INCLUDE_END>>


//<<AICUBE_USER_GLOBAL_DEFINE_BEGIN>>
// 在此添加用户全局变量定义、用户宏定义以及函数声明  
//<<AICUBE_USER_GLOBAL_DEFINE_END>>


BOOL fPrintfBusy;
BOOL fUART1ReadyRead;
uint8_t u8UART1RxCount;
uint8_t xdata pu8UART1RxBuffer[UART1_RXSIZE];
uint8_t xdata pu8UR1DMATxBuffer[UART1_DMATXSIZE]; //串口1DMA发送缓冲区数组

////////////////////////////////////////
// 串口1初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void UART1_Init(void)
{
#ifdef BAUDRATE
#undef BAUDRATE
#endif
#define BAUDRATE                (115200UL)
#define T2_RELOAD               (65536 - (SYSCLK / BAUDRATE + 2) / 4)

    UART1_SwitchP3031();                //设置串口数据端口: RxD (P3.0), TxD (P3.1)

    UART1_Timer2BRT();                  //选择定时器2作为串口1波特率发生器
    TIMER2_TimerMode();                 //设置定时器2为定时模式
    TIMER2_1TMode();                    //设置定时器2为1T模式
    TIMER2_SetPrescale(0);              //设置定时器2的8位预分频
    TIMER2_SetReload16(T2_RELOAD);      //设置定时器2的16位重载值
    TIMER2_Run();                       //定时器2开始运行

    UART1_EnableRx();                   //使能串口1接收数据
    UART1_Mode1();                      //设置串口1为模式1 (8位数据可变波特率)
    UART1_SetIntPriority(0);            //设置中断为最低优先级
    UART1_EnableInt();                  //使能串口1中断

    DMA_UART1_SetTxAmount(UART1_DMATXSIZE - 1); //设置串口DMA发送总字节数
    DMA_UART1_SetTxAddress(pu8UR1DMATxBuffer); //设置串口DMA发送缓冲区地址
    DMA_UART1_ClearTxFlag();            //清除串口发送DMA中断标志
    DMA_UART1_SetTxBusPriority(0);      //设置总线访问为最低优先级
    DMA_UART1_EnableTx();               //使能串口1DMA发送功能
//  DMA_UART1_TriggerTx();              //触发串口1DMA发送

    fPrintfBusy = 0;                    //清除发送数据忙标志
    fUART1ReadyRead = 0;                //清除接收数据完成标志
    u8UART1RxCount = 0;                 //初始化接收字节数量

    //<<AICUBE_USER_UART1_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_UART1_INITIAL_END>>
}

////////////////////////////////////////
// 重写printf字符发送重定向函数
// 入口参数: dat (printf函数待打印的字符)
// 函数返回: 需要返回入口参数的数据
////////////////////////////////////////
char putchar (char dat)                 //将串口1和printf函数绑定
{
    while (fPrintfBusy);                //等待之前的数据发送完成
    UART1_SendData(dat);                //发送当前字节
    fPrintfBusy = 1;                    //设置发送忙标志

    return dat;
}

////////////////////////////////////////
// 串口1发送数据函数
// 入口参数: dat (待发送的字节数据)
// 函数返回: 无
////////////////////////////////////////
void UART1_SendByte(uint8_t dat)
{
    putchar((char)dat);
}

////////////////////////////////////////
// 串口1发送多字节数据函数
// 入口参数: dat  (发送数据缓冲区)
//           size (数据大小)
// 函数返回: 无
////////////////////////////////////////
void UART1_SendBuffer(uint8_t *dat, uint8_t size)
{
    while (size--)                      //判断数据是否结束
        UART1_SendByte(*dat++);         //发送当前字节
}

////////////////////////////////////////
// 串口1发送字符串函数
// 入口参数: str  (字符串首地址)
// 函数返回: 无
////////////////////////////////////////
void UART1_SendString(char *str)
{
    printf(str);                        //直接使用printf函数打印字符串
}


////////////////////////////////////////
// 串口1中断服务程序
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void UART1_ISR(void) interrupt UART1_VECTOR
{
    //<<AICUBE_USER_UART1_ISR_CODE1_BEGIN>>
    // 在此添加中断函数用户代码  
    if (UART1_CheckTxFlag())            //判断串口发送中断
    {
        UART1_ClearTxFlag();            //清除串口发送中断标志

        fPrintfBusy = 0;                //清除printf发送忙标志
    }

    if (UART1_CheckRxFlag())            //判断串口接收中断
    {
        UART1_ClearRxFlag();            //清除串口接收中断标志

        pu8UART1RxBuffer[u8UART1RxCount++] = UART1_ReadData(); //保存接收的数据到接收缓冲区
        if (u8UART1RxCount >= UART1_RXSIZE)
            u8UART1RxCount = 0;         //防止数组边界溢出

        fUART1ReadyRead = 1;            //设置接收数据完成标志
    }
    //<<AICUBE_USER_UART1_ISR_CODE1_END>>
}


//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


