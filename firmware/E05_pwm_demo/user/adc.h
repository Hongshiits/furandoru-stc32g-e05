#ifndef ADC_H
#define ADC_H

#include "pt_headfile.h"

#define ADC_CHANNEL_NUMBER (6)
#define ADC_TRACK_CHANNEL_NUMBER (5)

// #define ADC_CHANNEL1 (ADC2_CH0_P00)
// #define ADC_CHANNEL2 (ADC2_CH1_P01)
// #define ADC_CHANNEL3 (ADC2_CH2_P02)
// #define ADC_CHANNEL4 (ADC2_CH3_P03)
// #define ADC_CHANNEL5 (ADC2_CH6_P06)

// #define ADC_CHANNEL6 (ADC1_CH0_P10)

#define ADC_CHANNEL1 (ADC2_CH6_P06)
#define ADC_CHANNEL2 (ADC2_CH3_P03)
#define ADC_CHANNEL3 (ADC2_CH2_P02)
#define ADC_CHANNEL4 (ADC2_CH1_P01)
#define ADC_CHANNEL5 (ADC2_CH0_P00)

#define ADC_CHANNEL6 (ADC1_CH0_P10)


#define ADC_VOLTAGE (ADC_CHANNEL6) // 电压采集通道
// 电池电压转换系数 12位ADC采集值 直接乘以该值则可得出电池电压 
#define VOLTAGE_CONVERSION_COEFFICIENT  (0.00886446)

// 电池电压矫正系数 理论计算值与实际电池电压可能存在误差 通过该矫正系数来使计算值与实际值吻合
#define VOLTAGE_RECTIFY_COEFFICIENT     (1)

#define ADC_NORMALIZED_MAX          (100.0f)


// #define adcmax	2500			//直道上中间电感值
extern float adcmax[ADC_CHANNEL_NUMBER];

extern uint8 adc_channel_index;
extern adc_channel_enum adc_channel_list[ADC_CHANNEL_NUMBER];

// Variable declarations for battery check
extern uint16 voltage_adc;
extern float voltage_now;
extern float battery_voltage_data;

extern float last_md_adc_data; // 上一次的 ADC 数据

void pt_adc_init(void);
void battery_check(void);
void adc_getdata(void);
uint16 adc_mean_filter_convert_pt(adc_channel_enum adcn, uint8 count);
void driver_adc_loop(void);

#endif