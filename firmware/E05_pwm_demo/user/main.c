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

#include "pt_headfile.h"
#include "hornshell.h"
// *************************** 例程测试说明 ***************************
// 1.核心板烧录完成本例程，完成上电
//
// 2.使用万用表检测 PWM_CHx 对应的通道，会看到电压变化
//
// 2.使用示波器检测 PWM_CHx 对应的通道，会看到脉宽变化
//
// 如果发现现象与说明严重不符 请参照本文件最下方 例程常见问题说明 进行排查

// **************************** 代码区域 ****************************
#define UART_INDEX (DEBUG_UART_INDEX)   // 默认 UART_5
#define UART_BAUDRATE (115200)          // 默认 115200
#define UART_TX_PIN (DEBUG_UART_TX_PIN) // 默认 UART5_TX_P05
#define UART_RX_PIN (DEBUG_UART_RX_PIN) // 默认 UART5_RX_P04

uint8 uart_get_data[64] = {0}; // 串口接收数据缓冲区
uint8 fifo_get_data[64] = {0}; // fifo 输出读出缓冲区

uint32 fifo_data_count = 0; // fifo 数据个数

fifo_struct uart_data_fifo = {0};

void uart_rx_interrupt_handler(uint8 dat)
{
    //    get_data = uart_read_byte(UART_INDEX);                                      // 接收数据 while 等待式 不建议在中断使用
    uart_query_byte(UART_INDEX, &dat);           // 接收数据 查询式 有数据会返回 TRUE 没有数据会返回 FALSE
    fifo_write_buffer(&uart_data_fifo, &dat, 1); // 将数据写入 fifo 中
    if (dat == '\n')
    {
        pit_handler_hornshell(); // 直接在中断中调用 shell 处理函数 也可以在主循环中调用
    }
}
void shell_process_re(void)
{

    // gpio_set_level(IO_P52, 0);

    char result_buf[MAX_STR_LEN];
    uint32 fifo_data_count;
    uint32 k;
    int ret;
    int i;

    interrupt_global_disable();

    fifo_data_count = fifo_used(&uart_data_fifo);
    if (fifo_data_count == 0)
    {
        _uart_print("shell_process: no data in fifo\n");
        return;
    }
    _uart_print("shell_process: data in fifo, processing...\n");

    fifo_read_buffer(&uart_data_fifo, fifo_get_data, &fifo_data_count, FIFO_READ_AND_CLEAN);

    /* 逐字节组装命令行 */
    for (k = 0; k < fifo_data_count; k++)
    {
        if (fifo_get_data[k] == '\n' || fifo_get_data[k] == '\r')
        {
            if (shell_rx_idx > 0)
            {
                shell_rx_buf[shell_rx_idx] = '\0';

                /* 执行命令 */
                for (i = 0; i < MAX_STR_LEN; i++)
                    result_buf[i] = 0;
                sprintf(_pbuf, "shell> %s\n", shell_rx_buf);
                _uart_print(_pbuf);
                ret = shell(shell_rx_buf, result_buf, MAX_STR_LEN);
                if (ret == 0)
                {
                    sprintf(_pbuf, "OK: %s\n", result_buf);
                    _uart_print(_pbuf);
                }
                else
                {
                    sprintf(_pbuf, "ERR: ret=%d\n", ret);
                    _uart_print(_pbuf);
                }

                /* 复位命令缓冲区 */
                shell_rx_idx = 0;
                for (i = 0; i < MAX_STR_LEN; i++)
                    shell_rx_buf[i] = 0;
            }
        }
        else
        {
            if (shell_rx_idx < MAX_STR_LEN - 1)
            {
                shell_rx_buf[shell_rx_idx++] = (char)fifo_get_data[k];
            }
        }
    }

    // gpio_set_level(IO_P52, 1);
    interrupt_global_enable();
}

void pit_handler_hornshell()
{
    fifo_data_count = fifo_used(&uart_data_fifo); // 查看 fifo 是否有数据
    if (fifo_data_count != 0)                     // 读取到数据了
    {
        shell_process_re(); // 调用shell处理函数
    }

    system_delay_ms(10);
}

void main(void)
{
    clock_init(SYSTEM_CLOCK_96M); // 时钟配置及系统初始化<务必保留>
    //clock_init(SYSTEM_CLOCK_124M);
    // debug_init();                       		// 调试串口信息初始化

    // 此处编写用户代码 例如外设初始化代码等

    fifo_init(&uart_data_fifo, FIFO_DATA_8BIT, uart_get_data, 64); // 初始化 fifo 挂载缓冲区

    uart_init(UART_INDEX, UART_BAUDRATE, UART_TX_PIN, UART_RX_PIN); // 初始化串口
    memset(_pbuf, 0, sizeof(_pbuf)); // 清空打印缓冲区

    // UART1的中断优先级不能设置，为最低优先级值0
    // UART1的中断优先级不能设置，为最低优先级值0
    // UART1的中断优先级不能设置，为最低优先级值0
    uart_rx_interrupt(UART_INDEX, ZF_ENABLE, uart_rx_interrupt_handler); // 开启 UART_INDEX 的接收中断

    #ifdef _660RB_
	pt_660rb_init();
    #else
	pt_660ra_init();
    #endif
    //gyro_init();

    // 取消注释此处需要同时修改fsm.c中的pit_handler_fsm_ptr_map和pit_handler_fsm_cond_map 将 hornshell 处理函数注册到 FSM 中
    // pit_handler_fsm_ptr_map[2] = pit_handler_hornshell; // 将 hornshell 处理函数注册到 FSM 中
    pt_encoder_init();


    pt_gpio_init();
    // 提前初始化gpio避免电机输出异常
    gpio_set_level(IO_P35, 0); // MOT1 left 输出高电平
    gpio_set_level(IO_P36, 0); // MOT2 right 输出低电平
    gpio_set_level(IO_P37, 0); // MOT3 top 输出高电平

    // 提前初始化pwm避免电机开机爆转
    pt_pwm_init();

    pwm_set_duty(PWM_CH1, 00);  // 设置 PWM_CH1 占空比为 50% (占空比范围 0-10000)
    pwm_set_duty(PWM_CH2, 0);  // 设置 PWM_CH2 占空比为 30% (占空比范围 0-10000)
    pwm_set_duty(PWM_CH3, 00); // 设置 PWM_CH3 占空比为 70% (占空比范围 0-10000)

    pt_adc_init();
    

    
    eeprom_init();
    PID_init();

    force_read_eeprom(); // 强制读取默认 EEPROM 数据到对应变量中,eeprom存在问题无法使用

    turn.A = A_Turn;
    turn.B = B_Turn;
    turn.C = C_Turn;
    aim_speed = 300;
    Direction = round_pid.temp_KP;

    motor_left_PIDduty = 0;
    motor_right_PIDduty = 0;

    fsm=0;

    init_algorithm();

    pt_pit_init(); // 初始化 PIT 定时器

    // pit_ms_init(PIT_CH, 500, pit_handler_hornshell);

    // 此处编写用户代码 例如外设初始化代码等

    while (1)
    {
        monitor_func_list[monitor_func_index](); // 调用当前监视函数 监视函数通过 monitor_func_index 进行切换
        system_delay_ms(10);
        
        // 此处编写需要循环执行的代码
    }
}
// **************************** 代码区域 ****************************

// *************************** 例程常见问题说明 ***************************
// 遇到问题时请按照以下问题检查列表检查
//
// 问题1：PWM_CHx 对应的通道长时间无信号、电压变化
//      查看程序是否正常烧录，是否下载报错，确认正常按下复位按键
//      四个通道同一时间只有一个通道输出，换个通道看看
