#include "pit.h"



void pit_handler_encoder_print()
{
    printf("encoder: %d,%d\n", encoder_data_dir_1, encoder_data_dir_2);
}

void pit_handler_adc_print()
{
    for (adc_channel_index = 0; adc_channel_index < ADC_CHANNEL_NUMBER; adc_channel_index++)
    {
        printf("%d", adc_convert(adc_channel_list[adc_channel_index]));
        // sprintf(_pbuf, "func %d: %d\n", adc_channel_index, adc_convert(adc_channel_list[adc_channel_index]));
        //_uart_print(_pbuf);
        if (adc_channel_index < ADC_CHANNEL_NUMBER - 1)
        {
            // printf(",");
            _uart_print(",");
        }
    }
    // printf("\n");
    _uart_print("\n");
}

void pit_handler_imu660ra()
{
    imu660ra_get_acc();  // 获取 IMU660RA 的加速度测量数值
    imu660ra_get_gyro(); // 获取 IMU660RA 的角速度测量数值

    // printf("\r\nIMU660RA acc data: x=%5d, y=%5d, z=%5d\r\n", imu660ra_acc_x, imu660ra_acc_y, imu660ra_acc_z);
    // printf("\r\nIMU660RA gyro data:  x=%5d, y=%5d, z=%5d\r\n", imu660ra_gyro_x, imu660ra_gyro_y, imu660ra_gyro_z);
    system_delay_ms(1);
    printf("%d,%d,%d,%d,%d,%d\n", imu660ra_acc_x, imu660ra_acc_y, imu660ra_acc_z, imu660ra_gyro_x, imu660ra_gyro_y, imu660ra_gyro_z);
}

float pt_acc_x, pt_acc_y, pt_acc_z, pt_gyro_x, pt_gyro_y, pt_gyro_z;

void pit_handler_imu660rb()
{
    imu660rb_get_acc();  // 获取 IMU660RB 的加速度测量数值
    imu660rb_get_gyro(); // 获取 IMU660RB 的角速度测量数值

    // printf("\r\nIMU660RB acc data: x=%5d, y=%5d, z=%5d\r\n", imu660rb_acc_x, imu660rb_acc_y, imu660rb_acc_z);
    // printf("\r\nIMU660RB gyro data:  x=%5d, y=%5d, z=%5d\r\n", imu660rb_gyro_x, imu660rb_gyro_y, imu660rb_gyro_z);
    system_delay_ms(1);

    printf("%d,%d,%d,%d,%d,%d\n", imu660rb_acc_x, imu660rb_acc_y, imu660rb_acc_z, imu660rb_gyro_x, imu660rb_gyro_y, imu660rb_gyro_z);

    /*pt_acc_x = imu660rb_acc_transition(imu660rb_acc_x);
    pt_acc_y = imu660rb_acc_transition(imu660rb_acc_y);
    pt_acc_z = imu660rb_acc_transition(imu660rb_acc_z);
    pt_gyro_x = imu660rb_gyro_transition(imu660rb_gyro_x);
    pt_gyro_y = imu660rb_gyro_transition(imu660rb_gyro_y);
    pt_gyro_z = imu660rb_gyro_transition(imu660rb_gyro_z);

    printf("%f,%f,%f,", pt_acc_x, pt_acc_y, pt_acc_z);
    printf("%f,%f,%f\n", pt_gyro_x, pt_gyro_y, pt_gyro_z);*/
}

void pit_handler_main()
{
    uint8 ii_in_inner_o;
    // Fsm_process();
    

    gpio_set_level(IO_P52, 0);

    // system_delay_ms(10);
    // Motor_act(motor_left_PIDduty, motor_right_PIDduty);

    // 此处编写需要循环执行的代码
    // pit_handler_hornshell();

    // pit_handler_fsm(); // 调用 FSM 处理函数 会根据状态调用对应的处理函数
    // TM4_Isr_lega(); // 调用 TM4 中断处理函数 处理定时器中断等
    sensor_capture();

    //adc_getdata();

    // track_line();
    // Fsm_process(); // 状态机函数

    // pit_handler_encoder(); // 调用编码器处理函数
    // pit_handler_adc_print(); // 调用 ADC 处理函数

    //encoder_getdata();
    // if (GO_enable)
    // {
    //     Fsm_process();
    //     Motor_up_act(6500);
    // }
    // else{
    //     Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
    //     Motor_up_act(motor_top_PIDduty);
    //     if(!gpio_get_level(IO_P32)){
    //         //interrupt_global_disable();
    //         GO_enable_count=1;
    //         //mot_top_on(800);
        
    //         //interrupt_global_enable();
    //     }else if(GO_enable_count>0){

    //         if(GO_enable_count>2040){
    //             GO_enable_count=0;
    //             GO_enable=1;
    //         }else if(GO_enable_count>40){
    //             Motor_up_act(6500);
    //         }else if(GO_enable_count>20){
    //             Motor_up_act(2000);
    //         }else if(GO_enable_count>0){
    //             Motor_up_act(800);
    //         }

    //         GO_enable_count++;
    //         //printf("%d \n",GO_enable_count);

    //     }
    // }

    if (GO_enable)
    {
        Fsm_process();
    }
    else{
        Motor_act(motor_left_PIDduty, motor_right_PIDduty); // 调用电机控制函数 根据 PID 计算结果控制电机输出
        Motor_up_act(motor_top_PIDduty);
        if(!gpio_get_level(IO_P32)){
            interrupt_global_disable();
            GO_enable=1;
            //mot_top_on(800);
            Motor_up_act(800);
            system_delay_ms(1000);

            //mot_top_on(2000);
            Motor_up_act(6500);

            
            for(ii_in_inner_o=0;ii_in_inner_o<15;ii_in_inner_o++)
            system_delay_ms(1000);

            interrupt_global_enable();
        }
    }


    // TM4_Isr_lega(); // 调用 TM4 中断处理函数 处理定时器中断等

    gpio_set_level(IO_P52, 1);
}

void pt_pit_init()
{
    // 设置100ms的周期定时器
    // pit_ms_init(PIT_CH, 1, pit_handler_encoder); // 初始化 PIT 为周期中断 1ms 周期
    // pit_ms_init(PIT_CH2, 50, pit_handler_encoder_print);
    // pit_us_init(PIT_CH3, 5, pit_handler_adc_print);
    // pit_ms_init(PIT_CH4, 5, pit_handler4rb);
    // pit_ms_init(PIT_CH5, 1500, pit_handler_hornshell);

    // pit_ms_init(PIT_CH, 1, pit_handler_fsm); // 初始化 PIT 为周期中断 1ms 周期
    
    //逐飞库环境下us定时器存在问题会干扰编码器计数，使用ms定时器替代us定时器
    pit_ms_init(PIT_CH, 2, pit_handler_main); // 初始化 PIT 为周期中断 1ms 周期
    //pit_us_init(PIT_CH,500,pit_handler_main);
}