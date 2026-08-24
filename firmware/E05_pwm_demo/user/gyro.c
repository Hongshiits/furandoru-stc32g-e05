/*
 * gyro.c
 *
 *  Created on: 2024年1月25日
 *      Author: A
 */

# include "gyro.h"

int16 gyro1;
int16 gyro2;
int16 gyro3;

int16 acc1;
int16 acc2;
int16 acc3;

// 陀螺仪初始化
void gyro_init(void)
{
//    imu660ra_init();  // IMU初始化
    while(1)
    {
       if(imu660ra_init())
           printf("\r\n IMU660RA init error.");                                 // IMU660RA 初始化失败
       else
           break;
    }

    EKF_Init();       // EKF初始化
    //pit_ms_init(CCU60_CH0, 1);
}

// 陀螺仪获取角速度、加速度
void gyro_getangv(void)
{
    imu660ra_get_gyro();   // 获取 ICM20602 陀螺仪的数据
    imu660ra_get_acc();    // 获取 ICM20602 加速度计的数据

//    // 记录 ICM20602 陀螺仪 的各个数据
//    gyro1 = imu660ra_gyro_x;
//    gyro2 = imu660ra_gyro_y;
//    gyro3 = imu660ra_gyro_z;
//
//    // 记录 ICM20602 加速度计 的各个数据
//
//    acc1 = imu660ra_acc_x;
//    acc2 = imu660ra_acc_y;
//    acc3 = imu660ra_acc_z;
}

void gyro_process(void){
    //imu_get_values();  // 获取陀螺仪数据并进行滤波处理
    EKF_UpData();      // 更新EKF状态
}



