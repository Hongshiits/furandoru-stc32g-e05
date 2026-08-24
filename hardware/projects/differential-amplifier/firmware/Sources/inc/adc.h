//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: adc.h
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#ifndef __ADC_H__
#define __ADC_H__


//<<AICUBE_USER_DEFINE_BEGIN>>
// 在此添加用户宏定义  
//<<AICUBE_USER_DEFINE_END>>


#define ADC_STPCYC              1       //ADC通道选择建立时间
#define ADC_HLDCYC              3       //ADC通道选择保持时间
#define ADC_SMPCYC              31      //ADC通道采样时间


void ADC_Init(void);
uint16_t ADC_Convert(uint8_t ch);



//<<AICUBE_USER_EXTERNAL_DECLARE_BEGIN>>
// 在此添加用户外部函数和外部变量声明  
//<<AICUBE_USER_EXTERNAL_DECLARE_END>>


#endif
