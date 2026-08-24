//
// Created by 20664 on 2025/6/28.
//

#include "pid.h"


/*
********************************************************************************
*  函数名--abs_limit
*  作用----限幅执行
*  参数----float *a, float ABS_MAX
*  返回----/
********************************************************************************
*/

static void abs_limit(float *a, float ABS_MAX)
{
    if(*a > ABS_MAX)
        *a = ABS_MAX;
    if(*a < -ABS_MAX)
        *a = -ABS_MAX;
}

static float abs_float(float value)
{
    return (value >= 0) ? value : -value;
}
/*
********************************************************************************
*  函数名--pid_param_init
*  作用----pid初始化??嵌入结构体
*  参数----pid mode maxout intergral_limit kp ki kd
*  返回----/
********************************************************************************
*/
static void pid_param_init(pid_t *pid, uint32 mode,uint32 maxout,uint32 intergral_limit,float kp, float ki, float kd)
{

    pid->IntegralLimit = intergral_limit;
    pid->MaxOutput = maxout;
    pid->pid_mode = mode;

    pid->p = kp;
    pid->i = ki;
    pid->d = kd;

}
/*
********************************************************************************
*  函数名--pid_calc
*  作用----pid运算
*  参数----pid get：实际 set：目标
*  返回----运算结果
********************************************************************************
*/
void Del_PID_Zero(pid_t* pid)
{
    pid->err[0]=0;
    pid->err[1]=0;
    pid->err[2]=0;
    pid->get[0]=0;
    pid->get[1]=0;
    pid->get[2]=0;
    pid->set[0]=0;
    pid->set[1]=0;
    pid->set[2]=0;
    pid->pout=0;
    pid->iout=0;
    pid->dout=0;
    pid->delta_u=0;
    pid->last_delta_out=0;
    pid->delta_out=0;
}
float pid_calc(pid_t* pid, float get, float set)
{
    pid->get[NOW] = get;
    pid->set[NOW] = set;
    pid->err[NOW] = set - get;    //set - measure
    if (pid->max_err != 0 && abs_float(pid->err[NOW]) >  pid->max_err  )
        return 0;
    if (pid->deadband != 0 && abs_float(pid->err[NOW]) < pid->deadband)
        return 0;

    if(pid->pid_mode == POSITION_PID) //位置式p
    {
        pid->pout = pid->p * pid->err[NOW];
        pid->iout += pid->i * pid->err[NOW];
        pid->dout = pid->d * (pid->err[NOW] - pid->err[LAST] );
        abs_limit(&(pid->iout), pid->IntegralLimit);
        pid->pos_out = pid->pout + pid->iout + pid->dout;
        abs_limit(&(pid->pos_out), pid->MaxOutput);
        pid->last_pos_out = pid->pos_out;    //update last time
    }
    else if(pid->pid_mode == DELTA_PID)//增量式P
    {
        pid->pout = pid->p * (pid->err[NOW] - pid->err[LAST]);
        pid->iout = pid->i * pid->err[NOW];
        pid->dout = pid->d * (pid->err[NOW] - 2*pid->err[LAST] + pid->err[LLAST]);

        abs_limit(&(pid->iout), pid->IntegralLimit);
        pid->delta_u = pid->pout + pid->iout + pid->dout;
        pid->delta_out = pid->last_delta_out + pid->delta_u;
        abs_limit(&(pid->delta_out), pid->MaxOutput);
        pid->last_delta_out = pid->delta_out;    //update last time
    }

    pid->err[LLAST] = pid->err[LAST];
    pid->err[LAST] = pid->err[NOW];
    pid->get[LLAST] = pid->get[LAST];
    pid->get[LAST] = pid->get[NOW];
    pid->set[LLAST] = pid->set[LAST];
    pid->set[LAST] = pid->set[NOW];
    return pid->pid_mode==POSITION_PID ? pid->pos_out : pid->delta_out;

}
/*
********************************************************************************
*  函数名--PID_struct_init
*  作用----初始化pid
*  参数----pid mode maxout intergral_limit kp ki kd
*  返回----/
********************************************************************************
*/
void PID_struct_init(pid_t* pid,uint32 mode,uint32 maxout,uint32 intergral_limit,float kp, float ki, float kd)
{
    //直接把初始化函数嵌入结构体，更方便
    pid->f_param_init = pid_param_init;
    pid_param_init(pid, mode, maxout, intergral_limit, kp, ki, kd);

}