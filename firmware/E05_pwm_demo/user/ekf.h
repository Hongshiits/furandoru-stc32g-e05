
#ifndef CODE_EKF_H_
#define CODE_EKF_H_

#include "pt_headfile.h"

#ifndef PI
#define PI              (3.14159265358979323846f)
#endif
#define DEG_TO_RAD      (57.295779513082320876798154814105f)
#define dt              (0.001f)
#define K               (1.0f)

typedef struct
{
        float gyro_x;
        float gyro_y;
        float gyro_z;
        float acc_x;
        float acc_y;
        float acc_z;
}imu_t;

extern int16 imu660ra_acc_x_l;
extern int16 imu660ra_acc_y_l;
extern int16 imu660ra_acc_z_l;
extern int16 imu660ra_gyro_x_l;
extern int16 imu660ra_gyro_y_l;
extern int16 imu660ra_gyro_z_l;


void imu_get_values(void);

void EKF_Init(void);
void EKF_UpData(void);


#endif /* CODE_EKF_H_ */
