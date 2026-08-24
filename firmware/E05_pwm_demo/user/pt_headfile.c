#include "pt_headfile.h"
// Variable definitions


uint8 Buzzer = 0; // 蜂鸣器控制变量

float yaw = 0;	 // 航向角
float pitch = 0; // 俯仰角

float coe_yaw = 0.002;	 // 航向角
float coe_pitch = 0.00045; // 俯仰角

float exp_acc = 0;

float PID_Steering_Kp_set = 60;
float exp_yaw_1=1;
float exp_yaw_2=1;


uint32 dead_pwm=3000;

void (*monitor_func_list[])(void)={
    null_monitor,                   //0
    adc_print_monitor,              //1
    encoder_print_monitor,          //2
    imu_print_monitor,              //3
    erroturn_monitor,               //4
    gyro_monitor,                   //5
    error_turn_monitor,             //6
    oradc_print_monitor,            //7
    imu_processed_print_monitor,    //8
    encoder_print_dyna_monitor,     //9
    oradc_erro_print_monitor,       //10
};

volatile uint8 monitor_func_index = 0; // 当前监视函数索引


pid_t* pid_list[]={
	&app_motor_left_pid,
	&app_motor_right_pid,
    &app_adc_errospeed_pid,
    &app_gyro_pid
};



// char putchar(char c)
// {
//     uart_write_byte(DEBUG_UART_INDEX, c); // 把自己实现的串口打印一字节数据的函数替换到这里
//     return c;
// }

int16 pt_atoi16(const char *str)
{
    int result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str == ' ' || *str == '\t')
        str++;

    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert digits
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return (int16)(sign * result);
}

uint8 pt_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str == ' ' || *str == '\t')
        str++;

    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert digits
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return (uint8)(sign * result);
}

float pt_atof(const char *str)
{
    float result = 0.0f;
    float fraction = 0.0f;
    int sign = 1;
    int divisor = 1;

    // Skip whitespace
    while (*str == ' ' || *str == '\t')
        str++;

    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert integer part
    while (*str >= '0' && *str <= '9') {
        result = result * 10.0f + (*str - '0');
        str++;
    }

    // Convert fractional part
    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9') {
            fraction = fraction * 10.0f + (*str - '0');
            divisor *= 10;
            str++;
        }
        result += fraction / divisor;
    }

    return sign * result;
}

int8 pt_atoi8(const char *str)
{
    int result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str == ' ' || *str == '\t')
        str++;

    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert digits
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return (int8)(sign * result);
}

void adc_print_monitor(void)
{
    uint8 i;
    for(i=0; i<ADC_CHANNEL_NUMBER; i++){
        sprintf(_pbuf, "%f", adc_data[i]); _uart_print(_pbuf);
        if(i != ADC_CHANNEL_NUMBER - 1){
            _uart_print(", ");
        }
    }
    _uart_print("\n");
}

void encoder_print_monitor(void){
    sprintf(_pbuf, "%d,%d,%f\n", count_left,count_right,aim_speed); _uart_print(_pbuf);
}
void imu_print_monitor(void){
    sprintf(_pbuf, "%d,%d,%d,%d,%d,%d,%f\n", IMU_GYRO_X, IMU_GYRO_Y, IMU_GYRO_Z, IMU_ACC_X, IMU_ACC_Y, IMU_ACC_Z,imu660ra_gyro_y_f); _uart_print(_pbuf);
}
void null_monitor(void){
    return ;
}
void erroturn_monitor(void){
    sprintf(_pbuf, "actual:%f pid:%f\n", Error_Turn, pid_errorspeed); _uart_print(_pbuf);
}
void gyro_monitor(void){
    sprintf(_pbuf, "%f,%f,%f\n", imu660ra_gyro_x_l, exp_acc,gyro_out); _uart_print(_pbuf);
}
void error_turn_monitor(void){
    sprintf(_pbuf, "%f\n", Error_Turn); _uart_print(_pbuf);
}
void oradc_print_monitor(void)
{
    uint8 i;
    for(i=0; i<ADC_CHANNEL_NUMBER; i++){
        sprintf(_pbuf, "%f", adc_ordata[i]); _uart_print(_pbuf);
        if(i != ADC_CHANNEL_NUMBER - 1){
            _uart_print(", ");
        }
    }
    _uart_print("\n");
}

void imu_processed_print_monitor(void){
    sprintf(_pbuf,"%f,%f\n",pitch,yaw);_uart_print(_pbuf);
}
void encoder_print_dyna_monitor(void){
    sprintf(_pbuf, "%d,%d,%f,%f\n", count_left,count_right,aim_speed+pid_errorspeed,aim_speed-pid_errorspeed); _uart_print(_pbuf);
}

void oradc_erro_print_monitor(void)
{
    sprintf(_pbuf, "%f,%f,%f,%f,%f,",
        ADC_DATA_LV, ADC_DATA_LH, ADC_DATA_MD, ADC_DATA_RH, ADC_DATA_RV);
    _uart_print(_pbuf);
    sprintf(_pbuf, "%f,%d,%d,%f\n", Error_Turn, fsm, Roundabout_flag, yaw);
    _uart_print(_pbuf);
}
