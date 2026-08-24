#include "ekf.h"



matrix_t exf_x;
matrix_t ekf_err;
EulerAngles euler_angle;
imu_t imu_data = {0, 0, 0, 0, 0, 0};
matrix_type r_yz = 0.001f;

const matrix_type q[16] = {0.005, 0, 0, 0, 0, 0.005, 0, 0, 0, 0, 0.005, 0, 0, 0, 0, 0.005};
const matrix_type r[9] = {10000, 0, 0, 0, 10000, 0, 0, 0, 10000};
const matrix_type p_init[16] = {1000000, 0, 0, 0, 0, 1000000, 0, 0, 0, 0, 1000000, 0, 0, 0, 0, 1000000};
const matrix_type ekf[4] = {1, 0, 0, 0};

static matrix_t ekf_Q;
static matrix_t ekf_R;
static matrix_t ekf_P;


void EKF_Init(void)
{
	Matrix_From_Array(&exf_x, (const matrix_type*)ekf, 4, 1);
	Matrix_From_Array(&ekf_Q, (const matrix_type*)q, 4, 4);
	Matrix_From_Array(&ekf_R, (const matrix_type*)r, 3, 3);
	Matrix_From_Array(&ekf_P, (const matrix_type*)p_init, 4, 4);
}




static void quaternion_to_euler(void)
{
    float q0, q1, q2, q3;
    q0 = (exf_x.d[MAT_IDX(0, 0)]);
    q1 = (exf_x.d[MAT_IDX(1, 0)]);
    q2 = (exf_x.d[MAT_IDX(2, 0)]);
    q3 = (exf_x.d[MAT_IDX(3, 0)]);

    //printf("%f,%f,%f,%f\n", q0, q1, q2, q3);

    euler_angle.pitch = asin(-2 * q1 * q3 + 2 * q0 * q2) * DEG_TO_RAD;                                  // pitch
    euler_angle.roll = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * DEG_TO_RAD;   // roll
    euler_angle.yaw = atan2(2 * q1 * q2 + 2 * q0 * q3, -2 * q2 * q2 - 2 * q3 * q3 + 1) * DEG_TO_RAD;    // yaw
    pitch=euler_angle.pitch;
    yaw=euler_angle.yaw;
}

// static void quaternion_to_euler(void)
// {
//     float q0, q1, q2, q3;

//     float euler[3];

//   	float sqx;
//   	float sqy;
//   	float sqz;

//     q0 = (exf_x.d[MAT_IDX(0, 0)]);
//     q1 = (exf_x.d[MAT_IDX(1, 0)]);
//     q2 = (exf_x.d[MAT_IDX(2, 0)]);
//     q3 = (exf_x.d[MAT_IDX(3, 0)]);

//     sqx = q0 * q0;
//   	sqy = q1 * q1;
//   	sqz = q2 * q2;



//   	euler[0] =  atan2(2.0f * (q1 * q3 + q0 * q2), 1.0f - 2.0f * (sqy + sqx));
//   	euler[1] = -asin(2.0f * (q0 * q3 - q1 * q2));
//   	euler[2] =  atan2(2.0f * (q0 * q1 + q2 * q3), 1.0f - 2.0f * (sqx + sqz));
    
    
    
//     pitch  = euler[1];
//     yaw    = euler[2];
// }



int16 imu660ra_acc_x_l = 0;
int16 imu660ra_acc_y_l = 0;
int16 imu660ra_acc_z_l = 0;
int16 imu660ra_gyro_x_l = 0;
int16 imu660ra_gyro_y_l = 0;
int16 imu660ra_gyro_z_l = 0;
void imu_get_values(void)
{
    imu660ra_get_gyro();
    imu660ra_get_acc();

    //一阶低通滤波，单位g/s
    imu_data.acc_x = K * imu660ra_acc_x + (1 - K) * imu660ra_acc_x_l;
    imu_data.acc_y = K * imu660ra_acc_y + (1 - K) * imu660ra_acc_y_l;
    imu_data.acc_z = K * imu660ra_acc_z + (1 - K) * imu660ra_acc_z_l;
    imu660ra_acc_x_l = imu_data.acc_x;
    imu660ra_acc_y_l = imu_data.acc_y;
    imu660ra_acc_z_l = imu_data.acc_z;

    //陀螺仪角度转弧度
    imu_data.gyro_x = imu660ra_gyro_x * PI / 180 / 16.384f;
    imu_data.gyro_y = imu660ra_gyro_y * PI / 180 / 16.384f;
    imu_data.gyro_z = imu660ra_gyro_z * PI / 180 / 16.384f;
    imu660ra_gyro_x_l = imu_data.gyro_x;
    imu660ra_gyro_y_l = imu_data.gyro_y;
    imu660ra_gyro_z_l = imu_data.gyro_z;
}





void EKF_UpData(void)
{
    float gx, gy, gz;
    float q0, q1, q2, q3;
    matrix_t Z, F, FT, H, HT, PK_, DK, invDK, EK, EKT, Kk, temp, eye;
    matrix_type f[16];
    matrix_type h[12];

    imu_get_values();
    gx = imu_data.gyro_x;
    gy = imu_data.gyro_y;
    gz = imu_data.gyro_z;

    Matrix_Init(&Z, 3, 1);

    Z.d[MAT_IDX(0, 0)] = (matrix_type)imu_data.acc_x;
    Z.d[MAT_IDX(1, 0)] = (matrix_type)imu_data.acc_y;
    Z.d[MAT_IDX(2, 0)] = (matrix_type)imu_data.acc_z;

    normalize_vector(&Z);

    f[0]  = 1;              f[1]  = -0.5f * gx * dt; f[2]  = -0.5f * gy * dt; f[3]  = -0.5f * gz * dt;
    f[4]  = 0.5f * gx * dt; f[5]  = 1;               f[6]  = 0.5f * gz * dt;  f[7]  = -0.5f * gy * dt;
    f[8]  = 0.5f * gy * dt; f[9]  = -0.5f * gz * dt; f[10] = 1;               f[11] = 0.5f * gx * dt;
    f[12] = 0.5f * gz * dt; f[13] = 0.5f * gy * dt;  f[14] = -0.5f * gx * dt; f[15] = 1;

    Matrix_From_Array(&F, (const matrix_type*)f, 4, 4);
    FT = Matrix_Transpose(&F);

    exf_x = multiply_matrices(&F, &exf_x);  //X = F * X;
    normalize_vector(&exf_x);

    q0 = (exf_x.d[MAT_IDX(0, 0)]);
    q1 = (exf_x.d[MAT_IDX(1, 0)]);
    q2 = (exf_x.d[MAT_IDX(2, 0)]);
    q3 = (exf_x.d[MAT_IDX(3, 0)]);

    h[0]  = -2 * q2; h[1]  = 2 * q3;  h[2]  = -2 * q0; h[3]  = 2 * q1;
    h[4]  = 2 * q1;  h[5]  = 2 * q0;  h[6]  = 2 * q3;  h[7]  = 2 * q2;
    h[8]  = 2 * q0;  h[9]  = -2 * q1; h[10] = -2 * q2; h[11] = 2 * q3;

    Matrix_From_Array(&H, (const matrix_type*)h, 3, 4);
    HT = Matrix_Transpose(&H);

    //PK_ = F * P(K - 1) * FT + Q;
    PK_ = multiply_matrices(&F, &ekf_P);       //F * P;
    PK_ = multiply_matrices(&PK_, &FT);    //F * P * FT;
    ekf_P = add_matrices(&PK_, &ekf_Q);            //F * P * FT + Q;


    //DK_ = H * PK_ * HT + R;
    DK = multiply_matrices(&H, &ekf_P);
    DK = multiply_matrices(&DK, &HT);
    DK = add_matrices(&DK, &ekf_R);

    if(inverse_matrix(&DK, &invDK))
    {
    	quaternion_to_euler();
    	return;
    }

    //ek = Z - h(q);  (nonlinear observation, NOT H*X)
    Matrix_Init(&EK, 3, 1);
    EK.d[MAT_IDX(0, 0)] = 2.0f * (q1*q3 - q0*q2);
    EK.d[MAT_IDX(1, 0)] = 2.0f * (q2*q3 + q0*q1);
    EK.d[MAT_IDX(2, 0)] = q0*q0 - q1*q1 - q2*q2 + q3*q3;
    EK = subtract_matrices(&Z, &EK);        //Z - h(q)
    EKT = Matrix_Transpose(&EK);

    //r = EKT * invDK * EK;
    ekf_err = multiply_matrices(&EKT, &invDK);
    ekf_err = multiply_matrices(&ekf_err, &EK);

    if(ekf_err.d[MAT_IDX(0, 0)] > r_yz)
    {
    	quaternion_to_euler();
    	return;
    }

    //Kk = M * P * HT * invDK;
    Kk = multiply_matrices(&ekf_P, &HT);
    Kk = multiply_matrices(&Kk, &invDK);

    //X = X_ + Kk * Ek;
    temp = multiply_matrices(&Kk, &EK);
    exf_x = add_matrices(&exf_x, &temp);
    normalize_vector(&exf_x);

    //P = (I - Kk * H) * PK_;
    Matrix_Identity(&eye, 4);
    temp = multiply_matrices(&Kk, &H);
    temp = subtract_matrices(&eye, &temp);
    ekf_P = multiply_matrices(&temp, &ekf_P);
	quaternion_to_euler();


}
