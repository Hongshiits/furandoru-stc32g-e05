//
// Created by 20664 on 2025/6/28.
//

#ifndef APP_PID_H
#define APP_PID_H

#include "zf_common_headfile.h"

enum{
    LLAST    = 0,
    LAST     = 1,
    NOW     = 2,

    POSITION_PID,
    DELTA_PID,
};
typedef struct __pid_t
{
    float p;
    float i;
    float d;

    float set[3];                //目标值,包含NOW， LAST， LLAST上上次
    float get[3];                //测量值
    float err[3];                //误差


    float pout;                            //p输出
    float iout;                            //i输出
    float dout;                            //d输出

    float pos_out;                        //本次位置式输出
    float last_pos_out;                //上次输出
    float delta_u;                        //本次增量值
    float delta_out;                    //本次增量式输出 = last_delta_out + delta_u
    float last_delta_out;

      float max_err;
      float deadband;                //err < deadband return
    uint32 pid_mode;
    float MaxOutput;                //输出限幅
    float IntegralLimit;        //积分限幅

    void (*f_param_init)(struct __pid_t *pid,  //PID参数初始化
                    uint32 pid_mode,
                    uint32 maxOutput,
                    uint32 integralLimit,
                    float p,
                    float i,
                    float d);


}pid_t;
void PID_struct_init(pid_t* pid,uint32 mode,uint32 maxout,uint32 intergral_limit,float kp, float ki, float kd);
float pid_calc(pid_t* pid, float get, float set);

typedef struct Mot_pid_T{
    pid_t Pid_Loc;
    pid_t Pid_Spd;
}Mot_pid;

//****************************************
void PID_struct_init(pid_t* pid,uint32 mode,uint32 maxout,uint32 intergral_limit,float kp, float ki, float kd);
float pid_calc(pid_t* pid, float get, float set);
void Del_PID_Zero(pid_t* pid);
//****************************************



#endif //APP_PID_H