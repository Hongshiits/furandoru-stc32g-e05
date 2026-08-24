#ifndef _HORNSHELL_H_
#define _HORNSHELL_H_

#include "zf_common_debug.h"
#include "zf_driver_uart.h"
#include "zf_common_interrupt.h"
#include "pt_headfile.h"
#include<stdio.h>

// -------------------------- 全局宏定义（适配单片机内存） --------------------------
#define MAX_SPLIT_COUNT 20    // 拆分后最大字符串数量
#define MAX_STR_LEN     64   // 单个字符串最大长度
#define HORN_EQ(a, b)   ((a) == (b))  // 字符比较宏
#define SHELL_FIFO_SIZE     256    // shell UART FIFO 缓冲区大小

// 定义业务函数的指针类型（统一接口）
typedef char* (*BusinessFunc)(char (*)[MAX_STR_LEN], int);

static char _pbuf[MAX_STR_LEN]; // UART 输出缓冲区
static char shell_rx_buf[MAX_STR_LEN]; // shell 接收缓冲区
static int shell_rx_idx; // shell 接收缓冲区索引
static uint8 shell_fifo_read_buf[SHELL_FIFO_SIZE]; // shell FIFO 读缓冲区
static uint8 shell_fifo_buffer[SHELL_FIFO_SIZE]; // shell FIFO 数据缓冲区
static fifo_struct shell_uart_fifo; // shell UART FIFO 结构体

static char horn_ok[] = "OK";
static char horn_err[] = "ERR";





// 测试用业务函数
char* test_func(char args[][MAX_STR_LEN], int args_len);
char* func_menu(char args[][MAX_STR_LEN], int args_len);
char* exit_shell(char args[][MAX_STR_LEN], int args_len);
char* mot_pwm(char args[][MAX_STR_LEN], int args_len);
char* mot_dir(char args[][MAX_STR_LEN], int args_len);
char* set_go_value(char args[][MAX_STR_LEN], int args_len);
char* write_eeprom(char args[][MAX_STR_LEN], int args_len);
char* value_list_func(char args[][MAX_STR_LEN], int args_len);
char* value_get(char args[][MAX_STR_LEN], int args_len);
char* value_set(char args[][MAX_STR_LEN], int args_len);
char* init_eeprom_func(char args[][MAX_STR_LEN], int args_len);
char* get_encoder(char args[][MAX_STR_LEN], int args_len);
char* get_adc(char args[][MAX_STR_LEN], int args_len);
char* force_read_eeprom_hs(char args[][MAX_STR_LEN], int args_len);
char* pid_set_pt(char args[][MAX_STR_LEN], int args_len);
char* pid_show_pt(char args[][MAX_STR_LEN], int args_len);
char* float_value_list_func(char args[][MAX_STR_LEN], int args_len);
char* float_value_get(char args[][MAX_STR_LEN], int args_len);
char* float_value_set(char args[][MAX_STR_LEN], int args_len);
char* int16_value_list_func(char args[][MAX_STR_LEN], int args_len);
char* int16_value_get(char args[][MAX_STR_LEN], int args_len);
char* int16_value_set(char args[][MAX_STR_LEN], int args_len);
char* enc_dir_set(char args[][MAX_STR_LEN], int args_len);
char* fsm_set(char args[][MAX_STR_LEN], int args_len);
char* fsm_show(char args[][MAX_STR_LEN], int args_len);




// 函数声明
// shell函数：执行命令字符串
// 参数：cm_shell_str - 输入的命令字符串
// 参数：out_buf - 输出缓冲区（存储函数执行结果）
// 参数：buf_len - 输出缓冲区长度
// 返回值：0=成功，1=参数错误，2=函数未找到，3=执行异常
int shell(const char* cm_shell_str, char* out_buf, int buf_len);

// 字符串拆分函数声明
int horn_split_v2(const char* cm_str, char out_str[MAX_SPLIT_COUNT][MAX_STR_LEN], int* out_count);

// 字符串trim函数声明（移除首尾空格）
void trim(char* s);

// 字符串比较函数声明
int str_compare(const char* s1, const char* s2);

// 函数查找器声明
BusinessFunc horn_finder(char func_name[][MAX_STR_LEN], int name_len);



// UART Shell 接口
void shell_uart_rx_handler(uint8 dat);
//void shell_process(void);
void shell_uart_init(void);
void _uart_print(const char* str);

#endif
