#include "adc.h"



uint8 adc_channel_index = 0;
adc_channel_enum adc_channel_list[ADC_CHANNEL_NUMBER] =
    {
        ADC_CHANNEL1,
        ADC_CHANNEL2,
        ADC_CHANNEL3,
        ADC_CHANNEL4,
        ADC_CHANNEL5,
        ADC_CHANNEL6,
};

extern float adcmax[ADC_CHANNEL_NUMBER]={2000,2000,2000,2000,2000};

// adc_data is defined globally in isr_leg.c as float adc_data[5].
// Keep a single definition to avoid C53 redefinition conflicts.

uint16 voltage_adc = 0;
float voltage_now = 0;

float battery_voltage_data = 0;

float last_md_adc_data = 0; // 上一次的 ADC 数据

void pt_adc_init()
{
    adc_init(ADC_CHANNEL1, ADC_12BIT); // 初始化对应 ADC 通道为对应精度
    adc_init(ADC_CHANNEL2, ADC_12BIT); // 初始化对应 ADC 通道为对应精度
    adc_init(ADC_CHANNEL3, ADC_12BIT); // 初始化对应 ADC 通道为对应精度
    adc_init(ADC_CHANNEL4, ADC_12BIT); // 初始化对应 ADC 通道为对应精度
    adc_init(ADC_CHANNEL5, ADC_12BIT); // 初始化对应 ADC 通道为对应精度
    adc_init(ADC_CHANNEL6, ADC_12BIT); // 初始化对应 ADC 通道为对应精度

    // 这里你会发现输出全是 8bit 精度
    // 因为这都是同一个 ADC 模块的引脚
    // 所以会以最后一个初始化精度为准
}





//-------------------------------------------------------------------------------------------------------------------
//  @brief      以下为adc原始数据归一化函数
//  @param      void     	    
//  @return     void
//  @since      v1.0
//-------------------------------------------------------------------------------------------------------------------
float adc_normalize_value(uint16 adc_value,uint8 channel_index)
{
    float normalized;

    normalized = (float)adc_value * ADC_NORMALIZED_MAX / adcmax[channel_index];
    //return adc_limit_range(normalized, 0.0f, ADC_NORMALIZED_MAX);
    return normalized;
}

void adc_getdata(void)
{
    uint8 i;
    uint16 raw_value;
    float normalized_value;

    last_md_adc_data = adc_data[2];

    for (i = 0; i < ADC_TRACK_CHANNEL_NUMBER; i++)
    {
        raw_value = adc_convert(adc_channel_list[i]);
        adc_ordata[i] = (float)raw_value;

        normalized_value = adc_normalize_value(raw_value, i);
        //adc_data[i] = adc_low_pass_filter(i, normalized_value);
        adc_data[i]=normalized_value;
    }

    //driver_adc_loop();
}



//-------------------------------------------------------------------------------------------------------------------
// 函数简介     ADC 均值滤波转换
// 参数说明     ch              选择 ADC 通道 (详见 zf_driver_adc.h 中枚举 adc_channel_enum 定义)
// 参数说明     count           均值滤波次数
// 返回参数     uint16          转换的 ADC 值
// 使用示例     adc_mean_filter_convert(ADC0_CH00_P06_0, 5);                        // 采集5次 然后返回平均值
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
uint16 adc_mean_filter_convert_pt (adc_channel_enum adcn, uint8 count)
{
    uint8 i;
    uint32 sum;

    sum = 0;
    for(i=0; i<count; i++)
    {
        sum += adc_convert(adcn);
    }

    sum = sum/count;

    return (uint16)sum;
}



void driver_adc_loop(void)
{       
    uint16 adc_data = 0;                                                        // 定义 临时 ADC 采集数据 存储位置
      
    uint16 bat_state = 0;                                               // 定义临时电池状态
    
    adc_data = adc_mean_filter_convert_pt(ADC_VOLTAGE, 5);                             // 5次均值采样
    
    battery_voltage_data = adc_data * VOLTAGE_RECTIFY_COEFFICIENT * VOLTAGE_CONVERSION_COEFFICIENT;     // 计算实际电压  ADC数据 * 转换系数 * 矫正系数
    
//    bat_state            = battery_check(battery_voltage_data);                 // 根据电压判断当前电池状态
}

void battery_check(void)
{
    voltage_adc = adc_convert(ADC1_CH0_P10);
    voltage_now = (float)11 * 3.3 * voltage_adc / 4095;
}