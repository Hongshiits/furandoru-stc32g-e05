#ifndef IMU_H
#define IMU_H

#include "pt_headfile.h"

//#define _660RB_



extern int16  imu660ra_gyro_z_l;
extern float imu660ra_gyro_x_l;
extern float imu660ra_acc_z_l;

extern float imu660ra_gyro_y_f;

extern float 	gyroy_offset ;
extern float 	gyroz_offset ;
extern uint8 	count_gryo_offset;
extern uint8 	gyro_offset_flag ; 
extern int 		count_gryo;



void pt_660ra_init(void);
void pt_660rb_init(void);

void imu_data_get(void);

void imu_process(void);

#endif