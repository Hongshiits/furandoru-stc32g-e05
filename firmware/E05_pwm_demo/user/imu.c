#include "imu.h"



float gyroy_offset = 0;
float gyroz_offset = 0;
uint8 count_gryo_offset = 0;
uint8 gyro_offset_flag = 0;
int count_gryo = 0;



void pt_660ra_init()
{
    while (1)
    {
        if (imu660ra_init())
            printf("\r\nIMU660RA init error."); // IMU660RA 初始化失败
        else
        {
            printf("\r\nIMU660RA init success."); // IMU660RA 初始化成功
            break;
        }
    }
}

void pt_660rb_init()
{
    while (1)
    {
        if (imu660rb_init())
            printf("\r\nIMU660RB init error."); // IMU660RB 初始化失败
        else
        {
            printf("\r\nIMU660RB init success."); // IMU660RB 初始化成功
            break;
        }
    }
}

float filter = 0;
int16  imu660ra_gyro_z_l = 0;
float imu660ra_gyro_x_l = 0;
float imu660ra_acc_z_l = 0;
static float imu660ra_acc_x_l = 0;

float imu660ra_gyro_y_f = 0;

/* IMU_GYRO_Y滑动窗口滤波 */
#define IMU_GYRO_Y_WIN_SIZE 10
static float imu_gyro_y_win[IMU_GYRO_Y_WIN_SIZE] = {0};
static uint8 imu_gyro_y_win_idx = 0;
static uint8 imu_gyro_y_win_cnt = 0;
static float imu_gyro_y_win_sum = 0;

static float imu_gyro_y_sliding_filter(float input)
{
	imu_gyro_y_win_sum -= imu_gyro_y_win[imu_gyro_y_win_idx];
	imu_gyro_y_win[imu_gyro_y_win_idx] = input;
	imu_gyro_y_win_sum += input;

	imu_gyro_y_win_idx++;
	if (imu_gyro_y_win_idx >= IMU_GYRO_Y_WIN_SIZE)
	{
		imu_gyro_y_win_idx = 0;
	}

	if (imu_gyro_y_win_cnt < IMU_GYRO_Y_WIN_SIZE)
	{
		imu_gyro_y_win_cnt++;
	}

	return imu_gyro_y_win_sum / imu_gyro_y_win_cnt;
}


/* 一阶互补滤波 */
#define COMPLEMENTARY_ALPHA  (0.98f)
#define COMPLEMENTARY_DT     (0.002f)
#define COMPLEMENTARY_RAD_TO_DEG  (57.29578f)

static void get_pitch_complementary(float ax, float az, float gyro_y)
{
	float pitch_acc;

	pitch_acc = atan2(ax, az) * COMPLEMENTARY_RAD_TO_DEG;
	pitch += COMPLEMENTARY_ALPHA * (pitch + gyro_y * COMPLEMENTARY_DT)
	      + (1.0f - COMPLEMENTARY_ALPHA) * pitch_acc;
}





void imu_data_get(void)
{

#ifdef _660RB_
	imu660rb_get_gyro();
	imu660rb_get_acc();
#else
	imu660ra_get_gyro();
	imu660ra_get_acc();
#endif

	imu660ra_gyro_x_l = IMU_GYRO_X - 1;
	if(imu660ra_gyro_x_l <= 5 && imu660ra_gyro_x_l >= -5)
	{
		imu660ra_gyro_x_l = 0;
	}
//	imu660ra_gyro_z_l = imu660ra_gyro_transition(imu660ra_gyro_z);
//	limitt(&imu660ra_gyro_x);
//	limitt(&imu660ra_gyro_y);
//	limitt(&imu660ra_gyro_z);
#ifdef _660RB_
    imu660ra_gyro_x_l = imu660rb_gyro_transition(imu660ra_gyro_x_l);
	imu660ra_gyro_y_f = imu660rb_gyro_transition(IMU_GYRO_Y);
	imu660ra_acc_x_l = imu660rb_acc_transition (IMU_ACC_X);
	imu660ra_acc_z_l = imu660rb_acc_transition (IMU_ACC_Z);
#else
    imu660ra_gyro_x_l = imu660ra_gyro_transition(imu660ra_gyro_x_l);
	imu660ra_gyro_y_f = imu660ra_gyro_transition(IMU_GYRO_Y);
	imu660ra_acc_x_l = imu660ra_acc_transition (IMU_ACC_X);
	imu660ra_acc_z_l = imu660ra_acc_transition (IMU_ACC_Z);
#endif

	imu660ra_gyro_y_f = imu_gyro_y_sliding_filter(imu660ra_gyro_y_f);

}


void imu_process(){
		//---陀螺仪及零漂处理Begin-----------------------------------------------------------------------------------------------------------------
	if (count_gryo < 200)
	{
		count_gryo++;
	}
	else
	{
		gyro_offset_flag = 1;
		gyroy_offset = 0.0625;
		gyroz_offset = -0.1678;
	}


	//printf("isr leg2\n");
	imu_data_get();
	if (count_gryo_offset < 150 && gyro_offset_flag == 0)
	{
		// gyroy_offset += imu660ra_gyro_y;
		// gyroz_offset += imu660ra_gyro_x;
		gyroy_offset += IMU_GYRO_Y;
		gyroz_offset += IMU_GYRO_X;
		count_gryo_offset++;
	}
	else if (gyro_offset_flag == 0)
	{
		gyroy_offset = gyroy_offset / count_gryo_offset;
		gyroz_offset = gyroz_offset / count_gryo_offset;
		if (gyroy_offset < 0.002 || gyroz_offset < 0.02) // 一定要计算出合理的零漂，否则不准
		{
			count_gryo_offset = 0;
			gyroy_offset = 0;
			gyroz_offset = 0;
		}
		else
			gyro_offset_flag = 1;

		count_gryo_offset = 0;
	}
	else if (gyro_offset_flag == 1)
	{
		#ifdef _660RB_
		get_pitch_complementary(imu660ra_acc_x_l, imu660ra_acc_z_l, imu660ra_gyro_y_f - imu660rb_gyro_transition(gyroy_offset));
		yaw += (imu660rb_gyro_transition(IMU_GYRO_X) - imu660rb_gyro_transition(gyroz_offset)) * coe_yaw;
		#else
		//get_pitch_complementary(imu660ra_acc_x_l, imu660ra_acc_z_l, imu660ra_gyro_y_f - imu660ra_gyro_transition(gyroy_offset));
		pitch += imu660ra_gyro_y_f;
		yaw += (imu660ra_gyro_transition(IMU_GYRO_X) - imu660ra_gyro_transition(gyroz_offset)) * coe_yaw;
		#endif
		
	}
	//---陀螺仪及零漂处理End-----------------------------------------------------------------------------------------------------


	

}