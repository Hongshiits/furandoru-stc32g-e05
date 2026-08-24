#ifndef __STC8H_DEF_H__
#define __STC8H_DEF_H__

/////////////////////////////////////////////////

#include "stc8h.h"
#include "def.h"

/////////////////////////////////////////////////

#define PORT_SetInitLevelLow(p, b)      CLR_REG_BIT(P##p, (b))
#define PORT_SetInitLevelHigh(p, b)     SET_REG_BIT(P##p, (b))

#define PORT_SetQuasiMode(p, b)         CLR_REG_BIT(P##p##M0, (b)); \
                                        CLR_REG_BIT(P##p##M1, (b))

#define PORT_SetPushPullMode(p, b)      SET_REG_BIT(P##p##M0, (b)); \
                                        CLR_REG_BIT(P##p##M1, (b))

#define PORT_SetHighZInputMode(p, b)    CLR_REG_BIT(P##p##M0, (b)); \
                                        SET_REG_BIT(P##p##M1, (b))

#define PORT_SetOpenDrainMode(p, b)     SET_REG_BIT(P##p##M0, (b)); \
                                        SET_REG_BIT(P##p##M1, (b))

#define PORT_EnablePullUp(p, b)         SET_REG_BIT(P##p##PU, (b))
#define PORT_DisablePullUp(p, b)        CLR_REG_BIT(P##p##PU, (b))

#define PORT_EnablePullDown(p, b)       SET_REG_BIT(P##p##PD, (b))
#define PORT_DisablePullDown(p, b)      CLR_REG_BIT(P##p##PD, (b))

#define PORT_EnableSchmitt(p, b)        CLR_REG_BIT(P##p##NCS, (b))
#define PORT_DisableSchmitt(p, b)       SET_REG_BIT(P##p##NCS, (b))

#define PORT_SetSlewRateFast(p, b)      CLR_REG_BIT(P##p##SR, (b))
#define PORT_SetSlewRateNormal(p, b)    SET_REG_BIT(P##p##SR, (b))

#define PORT_SetDrivingStrong(p, b)     CLR_REG_BIT(P##p##DR, (b))
#define PORT_SetDrivingNormal(p, b)     SET_REG_BIT(P##p##DR, (b))

#define PORT_SetAnalogInput(p, b)       CLR_REG_BIT(P##p##IE, (b))
#define PORT_SetDigitalInput(p, b)      SET_REG_BIT(P##p##IE, (b))

#define SetP0nInitLevelLow(b)           PORT_SetInitLevelLow(0, (b))
#define SetP1nInitLevelLow(b)           PORT_SetInitLevelLow(1, (b))
#define SetP2nInitLevelLow(b)           PORT_SetInitLevelLow(2, (b))
#define SetP3nInitLevelLow(b)           PORT_SetInitLevelLow(3, (b))
#define SetP4nInitLevelLow(b)           PORT_SetInitLevelLow(4, (b))
#define SetP5nInitLevelLow(b)           PORT_SetInitLevelLow(5, (b))
#define SetP6nInitLevelLow(b)           PORT_SetInitLevelLow(6, (b))
#define SetP7nInitLevelLow(b)           PORT_SetInitLevelLow(7, (b))

#define SetP0nInitLevelHigh(b)          PORT_SetInitLevelHigh(0, (b))
#define SetP1nInitLevelHigh(b)          PORT_SetInitLevelHigh(1, (b))
#define SetP2nInitLevelHigh(b)          PORT_SetInitLevelHigh(2, (b))
#define SetP3nInitLevelHigh(b)          PORT_SetInitLevelHigh(3, (b))
#define SetP4nInitLevelHigh(b)          PORT_SetInitLevelHigh(4, (b))
#define SetP5nInitLevelHigh(b)          PORT_SetInitLevelHigh(5, (b))
#define SetP6nInitLevelHigh(b)          PORT_SetInitLevelHigh(6, (b))
#define SetP7nInitLevelHigh(b)          PORT_SetInitLevelHigh(7, (b))

#define SetP0nQuasiMode(b)              PORT_SetQuasiMode(0, (b))
#define SetP1nQuasiMode(b)              PORT_SetQuasiMode(1, (b))
#define SetP2nQuasiMode(b)              PORT_SetQuasiMode(2, (b))
#define SetP3nQuasiMode(b)              PORT_SetQuasiMode(3, (b))
#define SetP4nQuasiMode(b)              PORT_SetQuasiMode(4, (b))
#define SetP5nQuasiMode(b)              PORT_SetQuasiMode(5, (b))
#define SetP6nQuasiMode(b)              PORT_SetQuasiMode(6, (b))
#define SetP7nQuasiMode(b)              PORT_SetQuasiMode(7, (b))

#define SetP0nPushPullMode(b)           PORT_SetPushPullMode(0, (b))
#define SetP1nPushPullMode(b)           PORT_SetPushPullMode(1, (b))
#define SetP2nPushPullMode(b)           PORT_SetPushPullMode(2, (b))
#define SetP3nPushPullMode(b)           PORT_SetPushPullMode(3, (b))
#define SetP4nPushPullMode(b)           PORT_SetPushPullMode(4, (b))
#define SetP5nPushPullMode(b)           PORT_SetPushPullMode(5, (b))
#define SetP6nPushPullMode(b)           PORT_SetPushPullMode(6, (b))
#define SetP7nPushPullMode(b)           PORT_SetPushPullMode(7, (b))

#define SetP0nHighZInputMode(b)         PORT_SetHighZInputMode(0, (b))
#define SetP1nHighZInputMode(b)         PORT_SetHighZInputMode(1, (b))
#define SetP2nHighZInputMode(b)         PORT_SetHighZInputMode(2, (b))
#define SetP3nHighZInputMode(b)         PORT_SetHighZInputMode(3, (b))
#define SetP4nHighZInputMode(b)         PORT_SetHighZInputMode(4, (b))
#define SetP5nHighZInputMode(b)         PORT_SetHighZInputMode(5, (b))
#define SetP6nHighZInputMode(b)         PORT_SetHighZInputMode(6, (b))
#define SetP7nHighZInputMode(b)         PORT_SetHighZInputMode(7, (b))

#define SetP0nOpenDrainMode(b)          PORT_SetOpenDrainMode(0, (b))
#define SetP1nOpenDrainMode(b)          PORT_SetOpenDrainMode(1, (b))
#define SetP2nOpenDrainMode(b)          PORT_SetOpenDrainMode(2, (b))
#define SetP3nOpenDrainMode(b)          PORT_SetOpenDrainMode(3, (b))
#define SetP4nOpenDrainMode(b)          PORT_SetOpenDrainMode(4, (b))
#define SetP5nOpenDrainMode(b)          PORT_SetOpenDrainMode(5, (b))
#define SetP6nOpenDrainMode(b)          PORT_SetOpenDrainMode(6, (b))
#define SetP7nOpenDrainMode(b)          PORT_SetOpenDrainMode(7, (b))

#define EnableP0nPullUp(b)              PORT_EnablePullUp(0, (b))
#define EnableP1nPullUp(b)              PORT_EnablePullUp(1, (b))
#define EnableP2nPullUp(b)              PORT_EnablePullUp(2, (b))
#define EnableP3nPullUp(b)              PORT_EnablePullUp(3, (b))
#define EnableP4nPullUp(b)              PORT_EnablePullUp(4, (b))
#define EnableP5nPullUp(b)              PORT_EnablePullUp(5, (b))
#define EnableP6nPullUp(b)              PORT_EnablePullUp(6, (b))
#define EnableP7nPullUp(b)              PORT_EnablePullUp(7, (b))

#define DisableP0nPullUp(b)             PORT_DisablePullUp(0, (b))
#define DisableP1nPullUp(b)             PORT_DisablePullUp(1, (b))
#define DisableP2nPullUp(b)             PORT_DisablePullUp(2, (b))
#define DisableP3nPullUp(b)             PORT_DisablePullUp(3, (b))
#define DisableP4nPullUp(b)             PORT_DisablePullUp(4, (b))
#define DisableP5nPullUp(b)             PORT_DisablePullUp(5, (b))
#define DisableP6nPullUp(b)             PORT_DisablePullUp(6, (b))
#define DisableP7nPullUp(b)             PORT_DisablePullUp(7, (b))

#define EnableP0nPullDown(b)            PORT_EnablePullDown(0, (b))
#define EnableP1nPullDown(b)            PORT_EnablePullDown(1, (b))
#define EnableP2nPullDown(b)            PORT_EnablePullDown(2, (b))
#define EnableP3nPullDown(b)            PORT_EnablePullDown(3, (b))
#define EnableP4nPullDown(b)            PORT_EnablePullDown(4, (b))
#define EnableP5nPullDown(b)            PORT_EnablePullDown(5, (b))
#define EnableP6nPullDown(b)            PORT_EnablePullDown(6, (b))
#define EnableP7nPullDown(b)            PORT_EnablePullDown(7, (b))

#define DisableP0nPullDown(b)           PORT_DisablePullDown(0, (b))
#define DisableP1nPullDown(b)           PORT_DisablePullDown(1, (b))
#define DisableP2nPullDown(b)           PORT_DisablePullDown(2, (b))
#define DisableP3nPullDown(b)           PORT_DisablePullDown(3, (b))
#define DisableP4nPullDown(b)           PORT_DisablePullDown(4, (b))
#define DisableP5nPullDown(b)           PORT_DisablePullDown(5, (b))
#define DisableP6nPullDown(b)           PORT_DisablePullDown(6, (b))
#define DisableP7nPullDown(b)           PORT_DisablePullDown(7, (b))

#define EnableP0nSchmitt(b)             PORT_EnableSchmitt(0, (b))
#define EnableP1nSchmitt(b)             PORT_EnableSchmitt(1, (b))
#define EnableP2nSchmitt(b)             PORT_EnableSchmitt(2, (b))
#define EnableP3nSchmitt(b)             PORT_EnableSchmitt(3, (b))
#define EnableP4nSchmitt(b)             PORT_EnableSchmitt(4, (b))
#define EnableP5nSchmitt(b)             PORT_EnableSchmitt(5, (b))
#define EnableP6nSchmitt(b)             PORT_EnableSchmitt(6, (b))
#define EnableP7nSchmitt(b)             PORT_EnableSchmitt(7, (b))

#define DisableP0nSchmitt(b)            PORT_DisableSchmitt(0, (b))
#define DisableP1nSchmitt(b)            PORT_DisableSchmitt(1, (b))
#define DisableP2nSchmitt(b)            PORT_DisableSchmitt(2, (b))
#define DisableP3nSchmitt(b)            PORT_DisableSchmitt(3, (b))
#define DisableP4nSchmitt(b)            PORT_DisableSchmitt(4, (b))
#define DisableP5nSchmitt(b)            PORT_DisableSchmitt(5, (b))
#define DisableP6nSchmitt(b)            PORT_DisableSchmitt(6, (b))
#define DisableP7nSchmitt(b)            PORT_DisableSchmitt(7, (b))

#define SetP0nSlewRateFast(b)           PORT_SetSlewRateFast(0, (b))
#define SetP1nSlewRateFast(b)           PORT_SetSlewRateFast(1, (b))
#define SetP2nSlewRateFast(b)           PORT_SetSlewRateFast(2, (b))
#define SetP3nSlewRateFast(b)           PORT_SetSlewRateFast(3, (b))
#define SetP4nSlewRateFast(b)           PORT_SetSlewRateFast(4, (b))
#define SetP5nSlewRateFast(b)           PORT_SetSlewRateFast(5, (b))
#define SetP6nSlewRateFast(b)           PORT_SetSlewRateFast(6, (b))
#define SetP7nSlewRateFast(b)           PORT_SetSlewRateFast(7, (b))

#define SetP0nSlewRateNormal(b)         PORT_SetSlewRateNormal(0, (b))
#define SetP1nSlewRateNormal(b)         PORT_SetSlewRateNormal(1, (b))
#define SetP2nSlewRateNormal(b)         PORT_SetSlewRateNormal(2, (b))
#define SetP3nSlewRateNormal(b)         PORT_SetSlewRateNormal(3, (b))
#define SetP4nSlewRateNormal(b)         PORT_SetSlewRateNormal(4, (b))
#define SetP5nSlewRateNormal(b)         PORT_SetSlewRateNormal(5, (b))
#define SetP6nSlewRateNormal(b)         PORT_SetSlewRateNormal(6, (b))
#define SetP7nSlewRateNormal(b)         PORT_SetSlewRateNormal(7, (b))

#define SetP0nDrivingStrong(b)          PORT_SetDrivingStrong(0, (b))
#define SetP1nDrivingStrong(b)          PORT_SetDrivingStrong(1, (b))
#define SetP2nDrivingStrong(b)          PORT_SetDrivingStrong(2, (b))
#define SetP3nDrivingStrong(b)          PORT_SetDrivingStrong(3, (b))
#define SetP4nDrivingStrong(b)          PORT_SetDrivingStrong(4, (b))
#define SetP5nDrivingStrong(b)          PORT_SetDrivingStrong(5, (b))
#define SetP6nDrivingStrong(b)          PORT_SetDrivingStrong(6, (b))
#define SetP7nDrivingStrong(b)          PORT_SetDrivingStrong(7, (b))

#define SetP0nDrivingNormal(b)          PORT_SetDrivingNormal(0, (b))
#define SetP1nDrivingNormal(b)          PORT_SetDrivingNormal(1, (b))
#define SetP2nDrivingNormal(b)          PORT_SetDrivingNormal(2, (b))
#define SetP3nDrivingNormal(b)          PORT_SetDrivingNormal(3, (b))
#define SetP4nDrivingNormal(b)          PORT_SetDrivingNormal(4, (b))
#define SetP5nDrivingNormal(b)          PORT_SetDrivingNormal(5, (b))
#define SetP6nDrivingNormal(b)          PORT_SetDrivingNormal(6, (b))
#define SetP7nDrivingNormal(b)          PORT_SetDrivingNormal(7, (b))

#define SetP0nAnalogInput(b)            PORT_SetAnalogInput(0, (b))
#define SetP1nAnalogInput(b)            PORT_SetAnalogInput(1, (b))
#define SetP2nAnalogInput(b)            PORT_SetAnalogInput(2, (b))
#define SetP3nAnalogInput(b)            PORT_SetAnalogInput(3, (b))
#define SetP4nAnalogInput(b)            PORT_SetAnalogInput(4, (b))
#define SetP5nAnalogInput(b)            PORT_SetAnalogInput(5, (b))
#define SetP6nAnalogInput(b)            PORT_SetAnalogInput(6, (b))
#define SetP7nAnalogInput(b)            PORT_SetAnalogInput(7, (b))

#define SetP0nDigitalInput(b)           PORT_SetDigitalInput(0, (b))
#define SetP1nDigitalInput(b)           PORT_SetDigitalInput(1, (b))
#define SetP2nDigitalInput(b)           PORT_SetDigitalInput(2, (b))
#define SetP3nDigitalInput(b)           PORT_SetDigitalInput(3, (b))
#define SetP4nDigitalInput(b)           PORT_SetDigitalInput(4, (b))
#define SetP5nDigitalInput(b)           PORT_SetDigitalInput(5, (b))
#define SetP6nDigitalInput(b)           PORT_SetDigitalInput(6, (b))
#define SetP7nDigitalInput(b)           PORT_SetDigitalInput(7, (b))

/////////////////////////////////////////////////

#define EnableGlobalInt()               (EA = 1)
#define DisableGlobalInt()              (EA = 0)

#define INT0_EnableInt()                (EX0 = 1)
#define INT0_DisableInt()               (EX0 = 0)

#define INT1_EnableInt()                (EX1 = 1)
#define INT1_DisableInt()               (EX1 = 0)

#define INTCLKO_EX2_MSK                 BIT4
#define INT2_EnableInt()                SET_REG_BIT(INTCLKO, INTCLKO_EX2_MSK)
#define INT2_DisableInt()               CLR_REG_BIT(INTCLKO, INTCLKO_EX2_MSK)

#define INTCLKO_EX3_MSK                 BIT5
#define INT3_EnableInt()                SET_REG_BIT(INTCLKO, INTCLKO_EX3_MSK)
#define INT3_DisableInt()               CLR_REG_BIT(INTCLKO, INTCLKO_EX3_MSK)

#define INTCLKO_EX4_MSK                 BIT6
#define INT4_EnableInt()                SET_REG_BIT(INTCLKO, INTCLKO_EX4_MSK)
#define INT4_DisableInt()               CLR_REG_BIT(INTCLKO, INTCLKO_EX4_MSK)

#define TIMER0_EnableInt()              (ET0 = 1)
#define TIMER0_DisableInt()             (ET0 = 0)

#define TIMER1_EnableInt()              (ET1 = 1)
#define TIMER1_DisableInt()             (ET1 = 0)

#define IE2_ET2_MSK                     BIT2
#define TIMER2_EnableInt()              SET_REG_BIT(IE2, IE2_ET2_MSK)
#define TIMER2_DisableInt()             CLR_REG_BIT(IE2, IE2_ET2_MSK)

#define IE2_ET3_MSK                     BIT5
#define TIMER3_EnableInt()              SET_REG_BIT(IE2, IE2_ET3_MSK)
#define TIMER3_DisableInt()             CLR_REG_BIT(IE2, IE2_ET3_MSK)

#define IE2_ET4_MSK                     BIT6
#define TIMER4_EnableInt()              SET_REG_BIT(IE2, IE2_ET4_MSK)
#define TIMER4_DisableInt()             CLR_REG_BIT(IE2, IE2_ET4_MSK)

#define T11CR_ET11I_MSK                 BIT1
#define TIMER11_EnableInt()             SET_REG_BIT(T11CR, T11CR_ET11I_MSK)
#define TIMER11_DisableInt()            CLR_REG_BIT(T11CR, T11CR_ET11I_MSK)

#define UART1_EnableInt()               (ES = 1)
#define UART1_DisableInt()              (ES = 0)

#define IE2_ES2_MSK                     BIT0
#define UART2_EnableInt()               SET_REG_BIT(IE2, IE2_ES2_MSK)
#define UART2_DisableInt()              CLR_REG_BIT(IE2, IE2_ES2_MSK)

#define IE2_ES3_MSK                     BIT3
#define UART3_EnableInt()               SET_REG_BIT(IE2, IE2_ES3_MSK)
#define UART3_DisableInt()              CLR_REG_BIT(IE2, IE2_ES3_MSK)

#define IE2_ES4_MSK                     BIT4
#define UART4_EnableInt()               SET_REG_BIT(IE2, IE2_ES4_MSK)
#define UART4_DisableInt()              CLR_REG_BIT(IE2, IE2_ES4_MSK)

#define LVD_EnableInt()                 (ELVD = 1)
#define LVD_DisableInt()                (ELVD = 0)

#define ADC_EnableInt()                 (EADC = 1)
#define ADC_DisableInt()                (EADC = 0)

#define IE2_ESPI_MSK                    BIT1
#define SPI_EnableInt()                 SET_REG_BIT(IE2, IE2_ESPI_MSK)
#define SPI_DisableInt()                CLR_REG_BIT(IE2, IE2_ESPI_MSK)

#define IE2_EUSB_MSK                    BIT7
#define USB_EnableInt()                 SET_REG_BIT(IE2, IE2_EUSB_MSK)
#define USB_DisableInt()                CLR_REG_BIT(IE2, IE2_EUSB_MSK)

#define CMPCR1_PIE_MSK                  BIT5
#define CMPCR1_NIE_MSK                  BIT4
#define CMP_EnablePosedgeInt()          SET_REG_BIT(CMPCR1, CMPCR1_PIE_MSK)
#define CMP_EnableNegedgeInt()          SET_REG_BIT(CMPCR1, CMPCR1_NIE_MSK)
#define CMP_EnableEdgeInt()             SET_REG_BIT(CMPCR1, (CMPCR1_PIE_MSK | CMPCR1_NIE_MSK))
#define CMP_DisableInt()                CLR_REG_BIT(CMPCR1, (CMPCR1_PIE_MSK | CMPCR1_NIE_MSK))

#define RTCIEN_ALARM_MSK                BIT7
#define RTCIEN_DAY_MSK                  BIT6
#define RTCIEN_HOUR_MSK                 BIT5
#define RTCIEN_MIN_MSK                  BIT4
#define RTCIEN_SEC_MSK                  BIT3
#define RTCIEN_SEC2_MSK                 BIT2
#define RTCIEN_SEC8_MSK                 BIT1
#define RTCIEN_SEC32_MSK                BIT0
#define RTC_EnableAlarmInt()            SET_REG_BIT(RTCIEN, RTCIEN_ALARM_MSK)
#define RTC_EnableDayInt()              SET_REG_BIT(RTCIEN, RTCIEN_DAY_MSK)
#define RTC_EnableHourInt()             SET_REG_BIT(RTCIEN, RTCIEN_HOUR_MSK)
#define RTC_EnableMinuteInt()           SET_REG_BIT(RTCIEN, RTCIEN_MIN_MSK)
#define RTC_EnableSecondInt()           SET_REG_BIT(RTCIEN, RTCIEN_SEC_MSK)
#define RTC_EnableSecondD2Int()         SET_REG_BIT(RTCIEN, RTCIEN_SEC2_MSK)
#define RTC_EnableSecondD8Int()         SET_REG_BIT(RTCIEN, RTCIEN_SEC8_MSK)
#define RTC_EnableSecondD32Int()        SET_REG_BIT(RTCIEN, RTCIEN_SEC32_MSK)
#define RTC_DisableAlarmInt()           CLR_REG_BIT(RTCIEN, RTCIEN_ALARM_MSK)
#define RTC_DisableDayInt()             CLR_REG_BIT(RTCIEN, RTCIEN_DAY_MSK)
#define RTC_DisableHourInt()            CLR_REG_BIT(RTCIEN, RTCIEN_HOUR_MSK)
#define RTC_DisableMinuteInt()          CLR_REG_BIT(RTCIEN, RTCIEN_MIN_MSK)
#define RTC_DisableSecondInt()          CLR_REG_BIT(RTCIEN, RTCIEN_SEC_MSK)
#define RTC_DisableSecondD2Int()        CLR_REG_BIT(RTCIEN, RTCIEN_SEC2_MSK)
#define RTC_DisableSecondD8Int()        CLR_REG_BIT(RTCIEN, RTCIEN_SEC8_MSK)
#define RTC_DisableSecondD32Int()       CLR_REG_BIT(RTCIEN, RTCIEN_SEC32_MSK)

#define LCMIFIE_MSK                     BIT7
#define LCM_EnableInt()                 SET_REG_BIT(LCMIFCFG, LCMIFIE_MSK)
#define LCM_DisableInt()                CLR_REG_BIT(LCMIFCFG, LCMIFIE_MSK)

#define I2CMSCR_EMSI_MSK                BIT7
#define I2C_EnableMasterInt()           SET_REG_BIT(I2CMSCR, I2CMSCR_EMSI_MSK)
#define I2C_DisableMasterInt()          CLR_REG_BIT(I2CMSCR, I2CMSCR_EMSI_MSK)

#define I2CSLCR_ESTAI_MSK               BIT6
#define I2CSLCR_ERXI_MSK                BIT5
#define I2CSLCR_ETXI_MSK                BIT4
#define I2CSLCR_ESTOI_MSK               BIT3
#define I2C_EnableSlaveSTAInt()         SET_REG_BIT(I2CSLCR, I2CSLCR_ESTAI_MSK)
#define I2C_EnableSlaveSTOInt()         SET_REG_BIT(I2CSLCR, I2CSLCR_ESTOI_MSK)
#define I2C_EnableSlaveRXInt()          SET_REG_BIT(I2CSLCR, I2CSLCR_ERXI_MSK)
#define I2C_EnableSlaveTXInt()          SET_REG_BIT(I2CSLCR, I2CSLCR_ETXI_MSK)
#define I2C_EnableSlaveAllInt()         SET_REG_BIT(I2CSLCR, I2CSLCR_ESTAI_MSK | I2CSLCR_ESTOI_MSK | I2CSLCR_ERXI_MSK | I2CSLCR_ETXI_MSK)
#define I2C_DisableSlaveSTAInt()        CLR_REG_BIT(I2CSLCR, I2CSLCR_ESTAI_MSK)
#define I2C_DisableSlaveSTOInt()        CLR_REG_BIT(I2CSLCR, I2CSLCR_ESTOI_MSK)
#define I2C_DisableSlaveRXInt()         CLR_REG_BIT(I2CSLCR, I2CSLCR_ERXI_MSK)
#define I2C_DisableSlaveTXInt()         CLR_REG_BIT(I2CSLCR, I2CSLCR_ETXI_MSK)
#define I2C_DisableSlaveAllInt()        CLR_REG_BIT(I2CSLCR, I2CSLCR_ESTAI_MSK | I2CSLCR_ESTOI_MSK | I2CSLCR_ERXI_MSK | I2CSLCR_ETXI_MSK)

#define PWMAIER_BIE_MSK                 BIT7
#define PWMAIER_TIE_MSK                 BIT6
#define PWMAIER_COMIE_MSK               BIT5
#define PWMAIER_CC4IE_MSK               BIT4
#define PWMAIER_CC3IE_MSK               BIT3
#define PWMAIER_CC2IE_MSK               BIT2
#define PWMAIER_CC1IE_MSK               BIT1
#define PWMAIER_UIE_MSK                 BIT0
#define PWMA_EnableBreakInt()           SET_REG_BIT(PWMA_IER, PWMAIER_BIE_MSK)
#define PWMA_EnableTriggerInt()         SET_REG_BIT(PWMA_IER, PWMAIER_TIE_MSK)
#define PWMA_EnableCOMInt()             SET_REG_BIT(PWMA_IER, PWMAIER_COMIE_MSK)
#define PWMA_EnableCC4Int()             SET_REG_BIT(PWMA_IER, PWMAIER_CC4IE_MSK)
#define PWMA_EnableCC3Int()             SET_REG_BIT(PWMA_IER, PWMAIER_CC3IE_MSK)
#define PWMA_EnableCC2Int()             SET_REG_BIT(PWMA_IER, PWMAIER_CC2IE_MSK)
#define PWMA_EnableCC1Int()             SET_REG_BIT(PWMA_IER, PWMAIER_CC1IE_MSK)
#define PWMA_EnableUpdateInt()          SET_REG_BIT(PWMA_IER, PWMAIER_UIE_MSK)
#define PWMA_DisableBreakInt()          CLR_REG_BIT(PWMA_IER, PWMAIER_BIE_MSK)
#define PWMA_DisableTriggerInt()        CLR_REG_BIT(PWMA_IER, PWMAIER_TIE_MSK)
#define PWMA_DisableCOMInt()            CLR_REG_BIT(PWMA_IER, PWMAIER_COMIE_MSK)
#define PWMA_DisableCC4Int()            CLR_REG_BIT(PWMA_IER, PWMAIER_CC4IE_MSK)
#define PWMA_DisableCC3Int()            CLR_REG_BIT(PWMA_IER, PWMAIER_CC3IE_MSK)
#define PWMA_DisableCC2Int()            CLR_REG_BIT(PWMA_IER, PWMAIER_CC2IE_MSK)
#define PWMA_DisableCC1Int()            CLR_REG_BIT(PWMA_IER, PWMAIER_CC1IE_MSK)
#define PWMA_DisableUpdateInt()         CLR_REG_BIT(PWMA_IER, PWMAIER_UIE_MSK)

#define PWMBIER_BIE_MSK                 BIT7
#define PWMBIER_TIE_MSK                 BIT6
#define PWMBIER_COMIE_MSK               BIT5
#define PWMBIER_CC8IE_MSK               BIT4
#define PWMBIER_CC7IE_MSK               BIT3
#define PWMBIER_CC6IE_MSK               BIT2
#define PWMBIER_CC5IE_MSK               BIT1
#define PWMBIER_UIE_MSK                 BIT0
#define PWMB_EnableBreakInt()           SET_REG_BIT(PWMB_IER, PWMBIER_BIE_MSK)
#define PWMB_EnableTriggerInt()         SET_REG_BIT(PWMB_IER, PWMBIER_TIE_MSK)
#define PWMB_EnableCOMInt()             SET_REG_BIT(PWMB_IER, PWMBIER_COMIE_MSK)
#define PWMB_EnableCC8Int()             SET_REG_BIT(PWMB_IER, PWMBIER_CC8IE_MSK)
#define PWMB_EnableCC7Int()             SET_REG_BIT(PWMB_IER, PWMBIER_CC7IE_MSK)
#define PWMB_EnableCC6Int()             SET_REG_BIT(PWMB_IER, PWMBIER_CC6IE_MSK)
#define PWMB_EnableCC5Int()             SET_REG_BIT(PWMB_IER, PWMBIER_CC5IE_MSK)
#define PWMB_EnableUpdateInt()          SET_REG_BIT(PWMB_IER, PWMBIER_UIE_MSK)
#define PWMB_DisableBreakInt()          CLR_REG_BIT(PWMB_IER, PWMBIER_BIE_MSK)
#define PWMB_DisableTriggerInt()        CLR_REG_BIT(PWMB_IER, PWMBIER_TIE_MSK)
#define PWMB_DisableCOMInt()            CLR_REG_BIT(PWMB_IER, PWMBIER_COMIE_MSK)
#define PWMB_DisableCC8Int()            CLR_REG_BIT(PWMB_IER, PWMBIER_CC8IE_MSK)
#define PWMB_DisableCC7Int()            CLR_REG_BIT(PWMB_IER, PWMBIER_CC7IE_MSK)
#define PWMB_DisableCC6Int()            CLR_REG_BIT(PWMB_IER, PWMBIER_CC6IE_MSK)
#define PWMB_DisableCC5Int()            CLR_REG_BIT(PWMB_IER, PWMBIER_CC5IE_MSK)
#define PWMB_DisableUpdateInt()         CLR_REG_BIT(PWMB_IER, PWMBIER_UIE_MSK)

#define PORT_EnableInt(p, b)            SET_REG_BIT(P##p##INTE, (b))
#define PORT_DisableInt(p, b)           CLR_REG_BIT(P##p##INTE, (b))

#define EnableP0nInt(b)                 PORT_EnableInt(0, (b))
#define EnableP1nInt(b)                 PORT_EnableInt(1, (b))
#define EnableP2nInt(b)                 PORT_EnableInt(2, (b))
#define EnableP3nInt(b)                 PORT_EnableInt(3, (b))
#define EnableP4nInt(b)                 PORT_EnableInt(4, (b))
#define EnableP5nInt(b)                 PORT_EnableInt(5, (b))
#define EnableP6nInt(b)                 PORT_EnableInt(6, (b))
#define EnableP7nInt(b)                 PORT_EnableInt(7, (b))

#define DisableP0nInt(b)                PORT_DisableInt(0, (b))
#define DisableP1nInt(b)                PORT_DisableInt(1, (b))
#define DisableP2nInt(b)                PORT_DisableInt(2, (b))
#define DisableP3nInt(b)                PORT_DisableInt(3, (b))
#define DisableP4nInt(b)                PORT_DisableInt(4, (b))
#define DisableP5nInt(b)                PORT_DisableInt(5, (b))
#define DisableP6nInt(b)                PORT_DisableInt(6, (b))
#define DisableP7nInt(b)                PORT_DisableInt(7, (b))

#define UR1TOCR_ENTOI_MSK               BIT6
#define UART1_EnableTimeoutInt()        SET_REG_BIT(UR1TOCR, UR1TOCR_ENTOI_MSK)
#define UART1_DisableTimeoutInt()       CLR_REG_BIT(UR1TOCR, UR1TOCR_ENTOI_MSK)

#define UR2TOCR_ENTOI_MSK               BIT6
#define UART2_EnableTimeoutInt()        SET_REG_BIT(UR2TOCR, UR2TOCR_ENTOI_MSK)
#define UART2_DisableTimeoutInt()       CLR_REG_BIT(UR2TOCR, UR2TOCR_ENTOI_MSK)

#define UR3TOCR_ENTOI_MSK               BIT6
#define UART3_EnableTimeoutInt()        SET_REG_BIT(UR3TOCR, UR3TOCR_ENTOI_MSK)
#define UART3_DisableTimeoutInt()       CLR_REG_BIT(UR3TOCR, UR3TOCR_ENTOI_MSK)

#define UR4TOCR_ENTOI_MSK               BIT6
#define UART4_EnableTimeoutInt()        SET_REG_BIT(UR4TOCR, UR4TOCR_ENTOI_MSK)
#define UART4_DisableTimeoutInt()       CLR_REG_BIT(UR4TOCR, UR4TOCR_ENTOI_MSK)

#define SPITOCR_ENTOI_MSK               BIT6
#define SPI_EnableTimeoutInt()          SET_REG_BIT(SPITOCR, SPITOCR_ENTOI_MSK)
#define SPI_DisableTimeoutInt()         CLR_REG_BIT(SPITOCR, SPITOCR_ENTOI_MSK)

#define I2CTOCR_ENTOI_MSK               BIT6
#define I2C_EnableTimeoutInt()          SET_REG_BIT(I2CTOCR, I2CTOCR_ENTOI_MSK)
#define I2C_DisableTimeoutInt()         CLR_REG_BIT(I2CTOCR, I2CTOCR_ENTOI_MSK)

#define DMAM2MCFG_M2MIE_MSK             BIT7
#define DMAADCCFG_ADCIE_MSK             BIT7
#define DMASPICFG_SPIIE_MSK             BIT7
#define DMALCMCFG_LCMIE_MSK             BIT7
#define DMAUR1TCFG_UR1TIE_MSK           BIT7
#define DMAUR1RCFG_UR1RIE_MSK           BIT7
#define DMAUR2TCFG_UR2TIE_MSK           BIT7
#define DMAUR2RCFG_UR2RIE_MSK           BIT7
#define DMAUR3TCFG_UR3TIE_MSK           BIT7
#define DMAUR3RCFG_UR3RIE_MSK           BIT7
#define DMAUR4TCFG_UR4TIE_MSK           BIT7
#define DMAUR4RCFG_UR4RIE_MSK           BIT7
#define DMA_M2M_EnableInt()             SET_REG_BIT(DMA_M2M_CFG,   DMAM2MCFG_M2MIE_MSK)
#define DMA_ADC_EnableInt()             SET_REG_BIT(DMA_ADC_CFG,   DMAADCCFG_ADCIE_MSK)
#define DMA_SPI_EnableInt()             SET_REG_BIT(DMA_SPI_CFG,   DMASPICFG_SPIIE_MSK)
#define DMA_LCM_EnableInt()             SET_REG_BIT(DMA_LCM_CFG,   DMALCMCFG_LCMIE_MSK)
#define DMA_UART1_EnableTxInt()         SET_REG_BIT(DMA_UR1T_CFG,  DMAUR1TCFG_UR1TIE_MSK)
#define DMA_UART1_EnableRxInt()         SET_REG_BIT(DMA_UR1R_CFG,  DMAUR1RCFG_UR1RIE_MSK)
#define DMA_UART2_EnableTxInt()         SET_REG_BIT(DMA_UR2T_CFG,  DMAUR2TCFG_UR2TIE_MSK)
#define DMA_UART2_EnableRxInt()         SET_REG_BIT(DMA_UR2R_CFG,  DMAUR2RCFG_UR2RIE_MSK)
#define DMA_UART3_EnableTxInt()         SET_REG_BIT(DMA_UR3T_CFG,  DMAUR3TCFG_UR3TIE_MSK)
#define DMA_UART3_EnableRxInt()         SET_REG_BIT(DMA_UR3R_CFG,  DMAUR3RCFG_UR3RIE_MSK)
#define DMA_UART4_EnableTxInt()         SET_REG_BIT(DMA_UR4T_CFG,  DMAUR4TCFG_UR4TIE_MSK)
#define DMA_UART4_EnableRxInt()         SET_REG_BIT(DMA_UR4R_CFG,  DMAUR4RCFG_UR4RIE_MSK)
#define DMA_M2M_DisableInt()            CLR_REG_BIT(DMA_M2M_CFG,   DMAM2MCFG_M2MIE_MSK)
#define DMA_ADC_DisableInt()            CLR_REG_BIT(DMA_ADC_CFG,   DMAADCCFG_ADCIE_MSK)
#define DMA_SPI_DisableInt()            CLR_REG_BIT(DMA_SPI_CFG,   DMASPICFG_SPIIE_MSK)
#define DMA_LCM_DisableInt()            CLR_REG_BIT(DMA_LCM_CFG,   DMALCMCFG_LCMIE_MSK)
#define DMA_UART1_DisableTxInt()        CLR_REG_BIT(DMA_UR1T_CFG,  DMAUR1TCFG_UR1TIE_MSK)
#define DMA_UART1_DisableRxInt()        CLR_REG_BIT(DMA_UR1R_CFG,  DMAUR1RCFG_UR1RIE_MSK)
#define DMA_UART2_DisableTxInt()        CLR_REG_BIT(DMA_UR2T_CFG,  DMAUR2TCFG_UR2TIE_MSK)
#define DMA_UART2_DisableRxInt()        CLR_REG_BIT(DMA_UR2R_CFG,  DMAUR2RCFG_UR2RIE_MSK)
#define DMA_UART3_DisableTxInt()        CLR_REG_BIT(DMA_UR3T_CFG,  DMAUR3TCFG_UR3TIE_MSK)
#define DMA_UART3_DisableRxInt()        CLR_REG_BIT(DMA_UR3R_CFG,  DMAUR3RCFG_UR3RIE_MSK)
#define DMA_UART4_DisableTxInt()        CLR_REG_BIT(DMA_UR4T_CFG,  DMAUR4TCFG_UR4TIE_MSK)
#define DMA_UART4_DisableRxInt()        CLR_REG_BIT(DMA_UR4R_CFG,  DMAUR4RCFG_UR4RIE_MSK)

#define INT0_FallingRisingInt()         (IT0 = 0)
#define INT0_FallingInt()               (IT0 = 1)

#define INT0_CheckFlag()                (IE0)
#define INT0_ClearFlag()                (IE0 = 0)

#define INT1_FallingRisingInt()         (IT1 = 0)
#define INT1_FallingInt()               (IT1 = 1)

#define INT1_CheckFlag()                (IE1)
#define INT1_ClearFlag()                (IE1 = 0)

#define AUXINTIF_INT2IF_MSK             BIT4
#define INT2_CheckFlag()                READ_REG_BIT(AUXINTIF, AUXINTIF_INT2IF_MSK)
#define INT2_ClearFlag()                CLR_REG_BIT(AUXINTIF, AUXINTIF_INT2IF_MSK)

#define AUXINTIF_INT3IF_MSK             BIT5
#define INT3_CheckFlag()                READ_REG_BIT(AUXINTIF, AUXINTIF_INT3IF_MSK)
#define INT3_ClearFlag()                CLR_REG_BIT(AUXINTIF, AUXINTIF_INT3IF_MSK)

#define AUXINTIF_INT4IF_MSK             BIT6
#define INT4_CheckFlag()                READ_REG_BIT(AUXINTIF, AUXINTIF_INT4IF_MSK)
#define INT4_ClearFlag()                CLR_REG_BIT(AUXINTIF, AUXINTIF_INT4IF_MSK)

#define TIMER0_CheckFlag()              (TF0)
#define TIMER0_ClearFlag()              (TF0 = 0)

#define TIMER1_CheckFlag()              (TF1)
#define TIMER1_ClearFlag()              (TF1 = 0)

#define AUXINTIF_T2IF_MSK               BIT0
#define TIMER2_CheckFlag()              READ_REG_BIT(AUXINTIF, AUXINTIF_T2IF_MSK)
#define TIMER2_ClearFlag()              CLR_REG_BIT(AUXINTIF, AUXINTIF_T2IF_MSK)

#define AUXINTIF_T3IF_MSK               BIT1
#define TIMER3_CheckFlag()              READ_REG_BIT(AUXINTIF, AUXINTIF_T3IF_MSK)
#define TIMER3_ClearFlag()              CLR_REG_BIT(AUXINTIF, AUXINTIF_T3IF_MSK)

#define AUXINTIF_T4IF_MSK               BIT2
#define TIMER4_CheckFlag()              READ_REG_BIT(AUXINTIF, AUXINTIF_T4IF_MSK)
#define TIMER4_ClearFlag()              CLR_REG_BIT(AUXINTIF, AUXINTIF_T4IF_MSK)

#define T11CR_T11IF_MSK                 BIT0
#define TIMER11_CheckFlag()             READ_REG_BIT(T11CR, T11CR_T11IF_MSK)
#define TIMER11_ClearFlag()             CLR_REG_BIT(T11CR, T11CR_T11IF_MSK)

#define UART1_CheckRxFlag()             (RI)
#define UART1_CheckTxFlag()             (TI)
#define UART1_ClearRxFlag()             (RI = 0)
#define UART1_ClearTxFlag()             (TI = 0)
#define UART1_SetRxFlag()               (RI = 1)
#define UART1_SetTxFlag()               (TI = 1)

#define S2CON_S2TI_MSK                  BIT1
#define S2CON_S2RI_MSK                  BIT0
#define UART2_CheckRxFlag()             READ_REG_BIT(S2CON, S2CON_S2RI_MSK)
#define UART2_CheckTxFlag()             READ_REG_BIT(S2CON, S2CON_S2TI_MSK)
#define UART2_ClearRxFlag()             CLR_REG_BIT(S2CON, S2CON_S2RI_MSK)
#define UART2_ClearTxFlag()             CLR_REG_BIT(S2CON, S2CON_S2TI_MSK)
#define UART2_SetRxFlag()               SET_REG_BIT(S2CON, S2CON_S2RI_MSK)
#define UART2_SetTxFlag()               SET_REG_BIT(S2CON, S2CON_S2TI_MSK)

#define S3CON_S3TI_MSK                  BIT1
#define S3CON_S3RI_MSK                  BIT0
#define UART3_CheckRxFlag()             READ_REG_BIT(S3CON, S3CON_S3RI_MSK)
#define UART3_CheckTxFlag()             READ_REG_BIT(S3CON, S3CON_S3TI_MSK)
#define UART3_ClearRxFlag()             CLR_REG_BIT(S3CON, S3CON_S3RI_MSK)
#define UART3_ClearTxFlag()             CLR_REG_BIT(S3CON, S3CON_S3TI_MSK)
#define UART3_SetRxFlag()               SET_REG_BIT(S3CON, S3CON_S3RI_MSK)
#define UART3_SetTxFlag()               SET_REG_BIT(S3CON, S3CON_S3TI_MSK)

#define S4CON_S4TI_MSK                  BIT1
#define S4CON_S4RI_MSK                  BIT0
#define UART4_CheckRxFlag()             READ_REG_BIT(S4CON, S4CON_S4RI_MSK)
#define UART4_CheckTxFlag()             READ_REG_BIT(S4CON, S4CON_S4TI_MSK)
#define UART4_ClearRxFlag()             CLR_REG_BIT(S4CON, S4CON_S4RI_MSK)
#define UART4_ClearTxFlag()             CLR_REG_BIT(S4CON, S4CON_S4TI_MSK)
#define UART4_SetRxFlag()               SET_REG_BIT(S4CON, S4CON_S4RI_MSK)
#define UART4_SetTxFlag()               SET_REG_BIT(S4CON, S4CON_S4TI_MSK)

#define PCON_LVDF_MSK                   BIT5
#define LVD_CheckFlag()                 READ_REG_BIT(PCON, PCON_LVDF_MSK)
#define LVD_ClearFlag()                 CLR_REG_BIT(PCON, PCON_LVDF_MSK)

#define ADCCONTR_ADCFLAG_MSK            BIT5
#define ADC_CheckFlag()                 READ_REG_BIT(ADC_CONTR, ADCCONTR_ADCFLAG_MSK)
#define ADC_ClearFlag()                 CLR_REG_BIT(ADC_CONTR, ADCCONTR_ADCFLAG_MSK)

#define SPSTAT_SPIF_MSK                 BIT7
#define SPSTAT_WCOL_MSK                 BIT6
#define SPI_CheckFlag()                 READ_REG_BIT(SPSTAT, SPSTAT_SPIF_MSK)
#define SPI_ClearFlag()                 SET_REG_BIT(SPSTAT, SPSTAT_SPIF_MSK | SPSTAT_WCOL_MSK)

#define CMPCR1_CMPIF_MSK                BIT6
#define CMP_CheckFlag()                 READ_REG_BIT(CMPCR1, CMPCR1_CMPIF_MSK)
#define CMP_ClearFlag()                 CLR_REG_BIT(CMPCR1, CMPCR1_CMPIF_MSK)

#define RTCIF_ALARM_MSK                 BIT7
#define RTCIF_DAY_MSK                   BIT6
#define RTCIF_HOUR_MSK                  BIT5
#define RTCIF_MIN_MSK                   BIT4
#define RTCIF_SEC_MSK                   BIT3
#define RTCIF_SEC2_MSK                  BIT2
#define RTCIF_SEC8_MSK                  BIT1
#define RTCIF_SEC32_MSK                 BIT0
#define RTC_CheckAlarmFlag()            READ_REG_BIT(RTCIF, RTCIF_ALARM_MSK)
#define RTC_CheckDayFlag()              READ_REG_BIT(RTCIF, RTCIF_DAY_MSK)
#define RTC_CheckHourFlag()             READ_REG_BIT(RTCIF, RTCIF_HOUR_MSK)
#define RTC_CheckMinuteFlag()           READ_REG_BIT(RTCIF, RTCIF_MIN_MSK)
#define RTC_CheckSecondFlag()           READ_REG_BIT(RTCIF, RTCIF_SEC_MSK)
#define RTC_CheckSecondD2Flag()         READ_REG_BIT(RTCIF, RTCIF_SEC2_MSK)
#define RTC_CheckSecondD8Flag()         READ_REG_BIT(RTCIF, RTCIF_SEC8_MSK)
#define RTC_CheckSecondD32Flag()        READ_REG_BIT(RTCIF, RTCIF_SEC32_MSK)
#define RTC_ClearAlarmFlag()            CLR_REG_BIT(RTCIF, RTCIF_ALARM_MSK)
#define RTC_ClearDayFlag()              CLR_REG_BIT(RTCIF, RTCIF_DAY_MSK)
#define RTC_ClearHourFlag()             CLR_REG_BIT(RTCIF, RTCIF_HOUR_MSK)
#define RTC_ClearMinuteFlag()           CLR_REG_BIT(RTCIF, RTCIF_MIN_MSK)
#define RTC_ClearSecondFlag()           CLR_REG_BIT(RTCIF, RTCIF_SEC_MSK)
#define RTC_ClearSecondD2Flag()         CLR_REG_BIT(RTCIF, RTCIF_SEC2_MSK)
#define RTC_ClearSecondD8Flag()         CLR_REG_BIT(RTCIF, RTCIF_SEC8_MSK)
#define RTC_ClearSecondD32Flag()        CLR_REG_BIT(RTCIF, RTCIF_SEC32_MSK)

#define LCMIFIF_MSK                     BIT0
#define LCM_CheckFlag()                 READ_REG_BIT(LCMIFSTA, LCMIFIF_MSK)
#define LCM_ClearFlag()                 CLR_REG_BIT(LCMIFSTA, LCMIFIF_MSK)

#define I2CMSST_MSIF_MSK                BIT6
#define I2C_CheckMasterFlag()           READ_REG_BIT(I2CMSST, I2CMSST_MSIF_MSK)
#define I2C_ClearMasterFlag()           CLR_REG_BIT(I2CMSST, I2CMSST_MSIF_MSK)

#define I2CSLST_STAIF_MSK               BIT6
#define I2CSLST_RXIF_MSK                BIT5
#define I2CSLST_TXIF_MSK                BIT4
#define I2CSLST_STOIF_MSK               BIT3
#define I2C_CheckSlaveSTAFlag()         READ_REG_BIT(I2CSLST, I2CSLST_STAIF_MSK)
#define I2C_CheckSlaveSTOFlag()         READ_REG_BIT(I2CSLST, I2CSLST_STOIF_MSK)
#define I2C_CheckSlaveRXFlag()          READ_REG_BIT(I2CSLST, I2CSLST_RXIF_MSK)
#define I2C_CheckSlaveTXFlag()          READ_REG_BIT(I2CSLST, I2CSLST_TXIF_MSK)
#define I2C_CheckSlaveAllFlag()         READ_REG_BIT(I2CSLST, I2CSLST_STAIF_MSK | I2CSLST_STOIF_MSK | I2CSLST_RXIF_MSK | I2CSLST_TXIF_MSK)
#define I2C_ClearSlaveSTAFlag()         CLR_REG_BIT(I2CSLST, I2CSLST_STAIF_MSK)
#define I2C_ClearSlaveSTOFlag()         CLR_REG_BIT(I2CSLST, I2CSLST_STOIF_MSK)
#define I2C_ClearSlaveRXFlag()          CLR_REG_BIT(I2CSLST, I2CSLST_RXIF_MSK)
#define I2C_ClearSlaveTXFlag()          CLR_REG_BIT(I2CSLST, I2CSLST_TXIF_MSK)
#define I2C_ClearSlaveAllFlag()         CLR_REG_BIT(I2CSLST, I2CSLST_STAIF_MSK | I2CSLST_STOIF_MSK | I2CSLST_RXIF_MSK | I2CSLST_TXIF_MSK)

#define PWMASR1_BIF_MSK                 BIT7
#define PWMASR1_TIF_MSK                 BIT6
#define PWMASR1_COMIF_MSK               BIT5
#define PWMASR1_CC4IF_MSK               BIT4
#define PWMASR1_CC3IF_MSK               BIT3
#define PWMASR1_CC2IF_MSK               BIT2
#define PWMASR1_CC1IF_MSK               BIT1
#define PWMASR1_UIF_MSK                 BIT0
#define PWMA_CheckBreakFlag()           READ_REG_BIT(PWMA_SR1, PWMASR1_BIF_MSK)
#define PWMA_CheckTriggerFlag()         READ_REG_BIT(PWMA_SR1, PWMASR1_TIF_MSK)
#define PWMA_CheckCOMFlag()             READ_REG_BIT(PWMA_SR1, PWMASR1_COMIF_MSK)
#define PWMA_CheckCC4Flag()             READ_REG_BIT(PWMA_SR1, PWMASR1_CC4IF_MSK)
#define PWMA_CheckCC3Flag()             READ_REG_BIT(PWMA_SR1, PWMASR1_CC3IF_MSK)
#define PWMA_CheckCC2Flag()             READ_REG_BIT(PWMA_SR1, PWMASR1_CC2IF_MSK)
#define PWMA_CheckCC1Flag()             READ_REG_BIT(PWMA_SR1, PWMASR1_CC1IF_MSK)
#define PWMA_CheckUpdateFlag()          READ_REG_BIT(PWMA_SR1, PWMASR1_UIF_MSK)
#define PWMA_ClearBreakFlag()           CLR_REG_BIT(PWMA_SR1, PWMASR1_BIF_MSK)
#define PWMA_ClearTriggerFlag()         CLR_REG_BIT(PWMA_SR1, PWMASR1_TIF_MSK)
#define PWMA_ClearCOMFlag()             CLR_REG_BIT(PWMA_SR1, PWMASR1_COMIF_MSK)
#define PWMA_ClearCC4Flag()             CLR_REG_BIT(PWMA_SR1, PWMASR1_CC4IF_MSK)
#define PWMA_ClearCC3Flag()             CLR_REG_BIT(PWMA_SR1, PWMASR1_CC3IF_MSK)
#define PWMA_ClearCC2Flag()             CLR_REG_BIT(PWMA_SR1, PWMASR1_CC2IF_MSK)
#define PWMA_ClearCC1Flag()             CLR_REG_BIT(PWMA_SR1, PWMASR1_CC1IF_MSK)
#define PWMA_ClearUpdateFlag()          CLR_REG_BIT(PWMA_SR1, PWMASR1_UIF_MSK)

#define PWMBSR1_BIF_MSK                 BIT7
#define PWMBSR1_TIF_MSK                 BIT6
#define PWMBSR1_COMIF_MSK               BIT5
#define PWMBSR1_CC8IF_MSK               BIT4
#define PWMBSR1_CC7IF_MSK               BIT3
#define PWMBSR1_CC6IF_MSK               BIT2
#define PWMBSR1_CC5IF_MSK               BIT1
#define PWMBSR1_UIF_MSK                 BIT0
#define PWMB_CheckBreakFlag()           READ_REG_BIT(PWMB_SR1, PWMBSR1_BIF_MSK)
#define PWMB_CheckTriggerFlag()         READ_REG_BIT(PWMB_SR1, PWMBSR1_TIF_MSK)
#define PWMB_CheckCOMFlag()             READ_REG_BIT(PWMB_SR1, PWMBSR1_COMIF_MSK)
#define PWMB_CheckCC8Flag()             READ_REG_BIT(PWMB_SR1, PWMBSR1_CC8IF_MSK)
#define PWMB_CheckCC7Flag()             READ_REG_BIT(PWMB_SR1, PWMBSR1_CC7IF_MSK)
#define PWMB_CheckCC6Flag()             READ_REG_BIT(PWMB_SR1, PWMBSR1_CC6IF_MSK)
#define PWMB_CheckCC5Flag()             READ_REG_BIT(PWMB_SR1, PWMBSR1_CC5IF_MSK)
#define PWMB_CheckUpdateFlag()          READ_REG_BIT(PWMB_SR1, PWMBSR1_UIF_MSK)
#define PWMB_ClearBreakFlag()           CLR_REG_BIT(PWMB_SR1, PWMBSR1_BIF_MSK)
#define PWMB_ClearTriggerFlag()         CLR_REG_BIT(PWMB_SR1, PWMBSR1_TIF_MSK)
#define PWMB_ClearCOMFlag()             CLR_REG_BIT(PWMB_SR1, PWMBSR1_COMIF_MSK)
#define PWMB_ClearCC8Flag()             CLR_REG_BIT(PWMB_SR1, PWMBSR1_CC8IF_MSK)
#define PWMB_ClearCC7Flag()             CLR_REG_BIT(PWMB_SR1, PWMBSR1_CC7IF_MSK)
#define PWMB_ClearCC6Flag()             CLR_REG_BIT(PWMB_SR1, PWMBSR1_CC6IF_MSK)
#define PWMB_ClearCC5Flag()             CLR_REG_BIT(PWMB_SR1, PWMBSR1_CC5IF_MSK)
#define PWMB_ClearUpdateFlag()          CLR_REG_BIT(PWMB_SR1, PWMBSR1_UIF_MSK)

#define PWMASR2_CC4OF_MSK               BIT4
#define PWMASR2_CC3OF_MSK               BIT3
#define PWMASR2_CC2OF_MSK               BIT2
#define PWMASR2_CC1OF_MSK               BIT1
#define PWMA_CheckCC4OverFlag()         READ_REG_BIT(PWMA_SR2, PWMASR2_CC4OF_MSK)
#define PWMA_CheckCC3OverFlag()         READ_REG_BIT(PWMA_SR2, PWMASR2_CC3OF_MSK)
#define PWMA_CheckCC2OverFlag()         READ_REG_BIT(PWMA_SR2, PWMASR2_CC2OF_MSK)
#define PWMA_CheckCC1OverFlag()         READ_REG_BIT(PWMA_SR2, PWMASR2_CC1OF_MSK)
#define PWMA_ClearCC4OverFlag()         CLR_REG_BIT(PWMA_SR2, PWMASR2_CC4OF_MSK)
#define PWMA_ClearCC3OverFlag()         CLR_REG_BIT(PWMA_SR2, PWMASR2_CC3OF_MSK)
#define PWMA_ClearCC2OverFlag()         CLR_REG_BIT(PWMA_SR2, PWMASR2_CC2OF_MSK)
#define PWMA_ClearCC1OverFlag()         CLR_REG_BIT(PWMA_SR2, PWMASR2_CC1OF_MSK)

#define PWMBSR2_CC8OF_MSK               BIT4
#define PWMBSR2_CC7OF_MSK               BIT3
#define PWMBSR2_CC6OF_MSK               BIT2
#define PWMBSR2_CC5OF_MSK               BIT1
#define PWMB_CheckCC8OverFlag()         READ_REG_BIT(PWMB_SR2, PWMASR2_CC8OF_MSK)
#define PWMB_CheckCC7OverFlag()         READ_REG_BIT(PWMB_SR2, PWMASR2_CC7OF_MSK)
#define PWMB_CheckCC6OverFlag()         READ_REG_BIT(PWMB_SR2, PWMASR2_CC6OF_MSK)
#define PWMB_CheckCC5OverFlag()         READ_REG_BIT(PWMB_SR2, PWMASR2_CC5OF_MSK)
#define PWMB_ClearCC8OverFlag()         CLR_REG_BIT(PWMB_SR2, PWMASR2_CC8OF_MSK)
#define PWMB_ClearCC7OverFlag()         CLR_REG_BIT(PWMB_SR2, PWMASR2_CC7OF_MSK)
#define PWMB_ClearCC6OverFlag()         CLR_REG_BIT(PWMB_SR2, PWMASR2_CC6OF_MSK)
#define PWMB_ClearCC5OverFlag()         CLR_REG_BIT(PWMB_SR2, PWMASR2_CC5OF_MSK)

#define PORT_CheckFlag(p, b)            READ_REG_BIT(P##p##INTF, (b))
#define PORT_ClearFlag(p, b)            CLR_REG_BIT(P##p##INTF, (b))

#define CheckP0nFlag(b)                 PORT_CheckFlag(0, (b))
#define CheckP1nFlag(b)                 PORT_CheckFlag(1, (b))
#define CheckP2nFlag(b)                 PORT_CheckFlag(2, (b))
#define CheckP3nFlag(b)                 PORT_CheckFlag(3, (b))
#define CheckP4nFlag(b)                 PORT_CheckFlag(4, (b))
#define CheckP5nFlag(b)                 PORT_CheckFlag(5, (b))
#define CheckP6nFlag(b)                 PORT_CheckFlag(6, (b))
#define CheckP7nFlag(b)                 PORT_CheckFlag(7, (b))
#define ClearP0nFlag(b)                 PORT_ClearFlag(0, (b))
#define ClearP1nFlag(b)                 PORT_ClearFlag(1, (b))
#define ClearP2nFlag(b)                 PORT_ClearFlag(2, (b))
#define ClearP3nFlag(b)                 PORT_ClearFlag(3, (b))
#define ClearP4nFlag(b)                 PORT_ClearFlag(4, (b))
#define ClearP5nFlag(b)                 PORT_ClearFlag(5, (b))
#define ClearP6nFlag(b)                 PORT_ClearFlag(6, (b))
#define ClearP7nFlag(b)                 PORT_ClearFlag(7, (b))

#define UR1TOSR_TOIF_MSK                BIT0
#define UR2TOSR_TOIF_MSK                BIT0
#define UR3TOSR_TOIF_MSK                BIT0
#define UR4TOSR_TOIF_MSK                BIT0
#define SPITOSR_TOIF_MSK                BIT0
#define I2CTOSR_TOIF_MSK                BIT0
#define UART1_CheckTimeoutFlag()        READ_REG_BIT(UR1TOSR, UR1TOSR_TOIF_MSK)
#define UART2_CheckTimeoutFlag()        READ_REG_BIT(UR2TOSR, UR2TOSR_TOIF_MSK)
#define UART3_CheckTimeoutFlag()        READ_REG_BIT(UR3TOSR, UR3TOSR_TOIF_MSK)
#define UART4_CheckTimeoutFlag()        READ_REG_BIT(UR4TOSR, UR4TOSR_TOIF_MSK)
#define SPI_CheckTimeoutFlag()          READ_REG_BIT(SPITOSR, SPITOSR_TOIF_MSK)
#define I2C_CheckTimeoutFlag()          READ_REG_BIT(I2CTOSR, I2CTOSR_TOIF_MSK)

#define UR1TOSR_CTOIF_MSK               BIT7
#define UR2TOSR_CTOIF_MSK               BIT7
#define UR3TOSR_CTOIF_MSK               BIT7
#define UR4TOSR_CTOIF_MSK               BIT7
#define SPITOSR_CTOIF_MSK               BIT7
#define I2CTOSR_CTOIF_MSK               BIT7
#define UART1_ClearTimeoutFlag()        SET_REG_BIT(UR1TOSR, UR1TOSR_CTOIF_MSK)
#define UART2_ClearTimeoutFlag()        SET_REG_BIT(UR2TOSR, UR2TOSR_CTOIF_MSK)
#define UART3_ClearTimeoutFlag()        SET_REG_BIT(UR3TOSR, UR3TOSR_CTOIF_MSK)
#define UART4_ClearTimeoutFlag()        SET_REG_BIT(UR4TOSR, UR4TOSR_CTOIF_MSK)
#define SPI_ClearTimeoutFlag()          SET_REG_BIT(SPITOSR, SPITOSR_CTOIF_MSK)
#define I2C_ClearTimeoutFlag()          SET_REG_BIT(I2CTOSR, I2CTOSR_CTOIF_MSK)

#define DMAM2MSTA_M2MIF_MSK             BIT0
#define DMAADCSTA_ADCIF_MSK             BIT0
#define DMASPISTA_SPIIF_MSK             BIT0
#define DMALCMSTA_LCMIF_MSK             BIT0
#define DMAUR1TSTA_UR1TIF_MSK           BIT0
#define DMAUR1RSTA_UR1RIF_MSK           BIT0
#define DMAUR2TSTA_UR2TIF_MSK           BIT0
#define DMAUR2RSTA_UR2RIF_MSK           BIT0
#define DMAUR3TSTA_UR3TIF_MSK           BIT0
#define DMAUR3RSTA_UR3RIF_MSK           BIT0
#define DMAUR4TSTA_UR4TIF_MSK           BIT0
#define DMAUR4RSTA_UR4RIF_MSK           BIT0
#define DMA_M2M_CheckFlag()             READ_REG_BIT(DMA_M2M_STA,   DMAM2MSTA_M2MIF_MSK)
#define DMA_ADC_CheckFlag()             READ_REG_BIT(DMA_ADC_STA,   DMAADCSTA_ADCIF_MSK)
#define DMA_SPI_CheckFlag()             READ_REG_BIT(DMA_SPI_STA,   DMASPISTA_SPIIF_MSK)
#define DMA_LCM_CheckFlag()             READ_REG_BIT(DMA_LCM_STA,   DMALCMSTA_LCMIF_MSK)
#define DMA_UART1_CheckTxFlag()         READ_REG_BIT(DMA_UR1T_STA,  DMAUR1TSTA_UR1TIF_MSK)
#define DMA_UART1_CheckRxFlag()         READ_REG_BIT(DMA_UR1R_STA,  DMAUR1RSTA_UR1RIF_MSK)
#define DMA_UART2_CheckTxFlag()         READ_REG_BIT(DMA_UR2T_STA,  DMAUR2TSTA_UR2TIF_MSK)
#define DMA_UART2_CheckRxFlag()         READ_REG_BIT(DMA_UR2R_STA,  DMAUR2RSTA_UR2RIF_MSK)
#define DMA_UART3_CheckTxFlag()         READ_REG_BIT(DMA_UR3T_STA,  DMAUR3TSTA_UR3TIF_MSK)
#define DMA_UART3_CheckRxFlag()         READ_REG_BIT(DMA_UR3R_STA,  DMAUR3RSTA_UR3RIF_MSK)
#define DMA_UART4_CheckTxFlag()         READ_REG_BIT(DMA_UR4T_STA,  DMAUR4TSTA_UR4TIF_MSK)
#define DMA_UART4_CheckRxFlag()         READ_REG_BIT(DMA_UR4R_STA,  DMAUR4RSTA_UR4RIF_MSK)
#define DMA_M2M_ClearFlag()             CLR_REG_BIT(DMA_M2M_STA,    DMAM2MSTA_M2MIF_MSK)
#define DMA_ADC_ClearFlag()             CLR_REG_BIT(DMA_ADC_STA,    DMAADCSTA_ADCIF_MSK)
#define DMA_SPI_ClearFlag()             CLR_REG_BIT(DMA_SPI_STA,    DMASPISTA_SPIIF_MSK)
#define DMA_LCM_ClearFlag()             CLR_REG_BIT(DMA_LCM_STA,    DMALCMSTA_LCMIF_MSK)
#define DMA_UART1_ClearTxFlag()         CLR_REG_BIT(DMA_UR1T_STA,   DMAUR1TSTA_UR1TIF_MSK)
#define DMA_UART1_ClearRxFlag()         CLR_REG_BIT(DMA_UR1R_STA,   DMAUR1RSTA_UR1RIF_MSK)
#define DMA_UART2_ClearTxFlag()         CLR_REG_BIT(DMA_UR2T_STA,   DMAUR2TSTA_UR2TIF_MSK)
#define DMA_UART2_ClearRxFlag()         CLR_REG_BIT(DMA_UR2R_STA,   DMAUR2RSTA_UR2RIF_MSK)
#define DMA_UART3_ClearTxFlag()         CLR_REG_BIT(DMA_UR3T_STA,   DMAUR3TSTA_UR3TIF_MSK)
#define DMA_UART3_ClearRxFlag()         CLR_REG_BIT(DMA_UR3R_STA,   DMAUR3RSTA_UR3RIF_MSK)
#define DMA_UART4_ClearTxFlag()         CLR_REG_BIT(DMA_UR4T_STA,   DMAUR4TSTA_UR4TIF_MSK)
#define DMA_UART4_ClearRxFlag()         CLR_REG_BIT(DMA_UR4R_STA,   DMAUR4RSTA_UR4RIF_MSK)

#define IPH_PX0H_MSK                    BIT0
#define INT0_SetIntPriority(n)          PX0 = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PX0H_MSK, ((((n) >> 1) & 1) << 0))

#define IPH_PX1H_MSK                    BIT2
#define INT1_SetIntPriority(n)          PX1 = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PX1H_MSK, ((((n) >> 1) & 1) << 2))

#define IP2_PX4_MSK                     BIT4
#define IP2H_PX4H_MSK                   BIT4
#define INT4_SetIntPriority(n)          MODIFY_REG(IP2, IP2_PX4_MSK, (((n) & 1) << 4)); \
                                        MODIFY_REG(IP2H, IP2H_PX4H_MSK, ((((n) >> 1) & 1) << 4))

#define IPH_PT0H_MSK                    BIT1
#define TIMER0_SetIntPriority(n)        PT0 = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PT0H_MSK, ((((n) >> 1) & 1) << 1))

#define IPH_PT1H_MSK                    BIT3
#define TIMER1_SetIntPriority(n)        PT1 = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PT1H_MSK, ((((n) >> 1) & 1) << 3))

#define IPH_PSH_MSK                     BIT4
#define UART1_SetIntPriority(n)         PS = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PSH_MSK, ((((n) >> 1) & 1) << 4))

#define IP2_PS2_MSK                     BIT0
#define IP2H_PS2H_MSK                   BIT0
#define UART2_SetIntPriority(n)         MODIFY_REG(IP2, IP2_PS2_MSK, (((n) & 1) << 0)); \
                                        MODIFY_REG(IP2H, IP2H_PS2H_MSK, ((((n) >> 1) & 1) << 0))

#define IP3_PS3_MSK                     BIT0
#define IP3H_PS3H_MSK                   BIT0
#define UART3_SetIntPriority(n)         MODIFY_REG(IP3, IP3_PS3_MSK, (((n) & 1) << 0)); \
                                        MODIFY_REG(IP3H, IP3H_PS3H_MSK, ((((n) >> 1) & 1) << 0))

#define IP3_PS4_MSK                     BIT1
#define IP3H_PS4H_MSK                   BIT1
#define UART4_SetIntPriority(n)         MODIFY_REG(IP3, IP3_PS4_MSK, (((n) & 1) << 1)); \
                                        MODIFY_REG(IP3H, IP3H_PS4H_MSK, ((((n) >> 1) & 1) << 1))

#define IPH_PLVDH_MSK                   BIT6
#define LVD_SetIntPriority(n)           PLVD = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PLVDH_MSK, ((((n) >> 1) & 1) << 6))

#define IPH_PADCH_MSK                   BIT5
#define ADC_SetIntPriority(n)           PADC = ((n) & 1); \
                                        MODIFY_REG(IPH, IPH_PADCH_MSK, ((((n) >> 1) & 1) << 5))

#define IP2_PSPI_MSK                    BIT1
#define IP2H_PSPIH_MSK                  BIT1
#define SPI_SetIntPriority(n)           MODIFY_REG(IP2, IP2_PSPI_MSK, (((n) & 1) << 1)); \
                                        MODIFY_REG(IP2H, IP2H_PSPIH_MSK, ((((n) >> 1) & 1) << 1))

#define IP2_PCMP_MSK                    BIT5
#define IP2H_PCMPH_MSK                  BIT5
#define CMP_SetIntPriority(n)           MODIFY_REG(IP2, IP2_PCMP_MSK, (((n) & 1) << 5)); \
                                        MODIFY_REG(IP2H, IP2H_PCMPH_MSK, ((((n) >> 1) & 1) << 5))

#define IP3_PRTC_MSK                    BIT2
#define IP3H_PRTCH_MSK                  BIT2
#define RTC_SetIntPriority(n)           MODIFY_REG(IP3, IP3_PRTC_MSK, (((n) & 1) << 2)); \
                                        MODIFY_REG(IP3H, IP3H_PRTCH_MSK, ((((n) >> 1) & 1) << 2))

#define IP2_PI2C_MSK                    BIT6
#define IP2H_PI2CH_MSK                  BIT6
#define I2C_SetIntPriority(n)           MODIFY_REG(IP2, IP2_PI2C_MSK, (((n) & 1) << 6)); \
                                        MODIFY_REG(IP2H, IP2H_PI2CH_MSK, ((((n) >> 1) & 1) << 6))

#define IP2_PUSB_MSK                    BIT7
#define IP2H_PUSBH_MSK                  BIT7
#define USB_SetIntPriority(n)           MODIFY_REG(IP2, IP2_PUSB_MSK, (((n) & 1) << 7)); \
                                        MODIFY_REG(IP2H, IP2H_PUSBH_MSK, ((((n) >> 1) & 1) << 7))

#define IP2_PPWMA_MSK                   BIT2
#define IP2H_PPWMAH_MSK                 BIT2
#define PWMA_SetIntPriority(n)          MODIFY_REG(IP2, IP2_PPWMA_MSK, (((n) & 1) << 2)); \
                                        MODIFY_REG(IP2H, IP2H_PPWMAH_MSK, ((((n) >> 1) & 1) << 2))

#define IP2_PPWMB_MSK                   BIT3
#define IP2H_PPWMBH_MSK                 BIT3
#define PWMB_SetIntPriority(n)          MODIFY_REG(IP2, IP2_PPWMB_MSK, (((n) & 1) << 3)); \
                                        MODIFY_REG(IP2H, IP2H_PPWMBH_MSK, ((((n) >> 1) & 1) << 3))

#define LCMIFIP_MSK                     (BIT5 | BIT4)
#define LCM_SetIntPriority(n)           MODIFY_REG(LCMIFCFG, LCMIFIP_MSK, ((n) << 4))

#define PORT_SetIntPriority(p, n)       MODIFY_REG(PINIPL, BIT(p), (((n) & 0x01) << (p))); \
                                        MODIFY_REG(PINIPH, BIT(p), ((((n) >> 1) & 0x01) << (p)))

#define SetP0IntPriority(n)             PORT_SetIntPriority(0, (n))
#define SetP1IntPriority(n)             PORT_SetIntPriority(1, (n))
#define SetP2IntPriority(n)             PORT_SetIntPriority(2, (n))
#define SetP3IntPriority(n)             PORT_SetIntPriority(3, (n))
#define SetP4IntPriority(n)             PORT_SetIntPriority(4, (n))
#define SetP5IntPriority(n)             PORT_SetIntPriority(5, (n))
#define SetP6IntPriority(n)             PORT_SetIntPriority(6, (n))
#define SetP7IntPriority(n)             PORT_SetIntPriority(7, (n))

#define DMAM2MCFG_M2MIP_MSK             (BIT3 | BIT2)
#define DMAADCCFG_ADCIP_MSK             (BIT3 | BIT2)
#define DMASPICFG_SPIIP_MSK             (BIT3 | BIT2)
#define DMALCMCFG_LCMIP_MSK             (BIT3 | BIT2)
#define DMAUR1TCFG_UR1TIP_MSK           (BIT3 | BIT2)
#define DMAUR1RCFG_UR1RIP_MSK           (BIT3 | BIT2)
#define DMAUR2TCFG_UR2TIP_MSK           (BIT3 | BIT2)
#define DMAUR2RCFG_UR2RIP_MSK           (BIT3 | BIT2)
#define DMAUR3TCFG_UR3TIP_MSK           (BIT3 | BIT2)
#define DMAUR3RCFG_UR3RIP_MSK           (BIT3 | BIT2)
#define DMAUR4TCFG_UR4TIP_MSK           (BIT3 | BIT2)
#define DMAUR4RCFG_UR4RIP_MSK           (BIT3 | BIT2)
#define DMA_M2M_SetIntPriority(n)       MODIFY_REG(DMA_M2M_CFG,   DMAM2MCFG_M2MIP_MSK, ((n) << 2))
#define DMA_ADC_SetIntPriority(n)       MODIFY_REG(DMA_ADC_CFG,   DMAADCCFG_ADCIP_MSK, ((n) << 2))
#define DMA_SPI_SetIntPriority(n)       MODIFY_REG(DMA_SPI_CFG,   DMASPICFG_SPIIP_MSK, ((n) << 2))
#define DMA_LCM_SetIntPriority(n)       MODIFY_REG(DMA_LCM_CFG,   DMALCMCFG_LCMIP_MSK, ((n) << 2))
#define DMA_UART1_SetTxIntPriority(n)   MODIFY_REG(DMA_UR1T_CFG,  DMAUR1TCFG_UR1TIP_MSK, ((n) << 2))
#define DMA_UART1_SetRxIntPriority(n)   MODIFY_REG(DMA_UR1R_CFG,  DMAUR1RCFG_UR1RIP_MSK, ((n) << 2))
#define DMA_UART2_SetTxIntPriority(n)   MODIFY_REG(DMA_UR2T_CFG,  DMAUR2TCFG_UR2TIP_MSK, ((n) << 2))
#define DMA_UART2_SetRxIntPriority(n)   MODIFY_REG(DMA_UR2R_CFG,  DMAUR2RCFG_UR2RIP_MSK, ((n) << 2))
#define DMA_UART3_SetTxIntPriority(n)   MODIFY_REG(DMA_UR3T_CFG,  DMAUR3TCFG_UR3TIP_MSK, ((n) << 2))
#define DMA_UART3_SetRxIntPriority(n)   MODIFY_REG(DMA_UR3R_CFG,  DMAUR3RCFG_UR3RIP_MSK, ((n) << 2))
#define DMA_UART4_SetTxIntPriority(n)   MODIFY_REG(DMA_UR4T_CFG,  DMAUR4TCFG_UR4TIP_MSK, ((n) << 2))
#define DMA_UART4_SetRxIntPriority(n)   MODIFY_REG(DMA_UR4R_CFG,  DMAUR4RCFG_UR4RIP_MSK, ((n) << 2))

/////////////////////////////////////////////////

#define EAXFR_MSK                       BIT7
#define EnableAccessXFR()               SET_REG_BIT(P_SW2, EAXFR_MSK)

#define ACCEXRAM_MSK                    (BIT2 | BIT1 | BIT0)
#define AccessEXramSpeed(n)             MODIFY_REG(BUS_SPEED, ACCEXRAM_MSK, ((n) << 0))
#define AccessEXramFastest()            AccessEXramSpeed(0)

#define UART1_PS_MSK                    (BIT7 | BIT6)
#define UART1_SwitchP3031()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((0) << 6))
#define UART1_SwitchP3637()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((1) << 6))
#define UART1_SwitchP1617()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((2) << 6))
#define UART1_SwitchP4344()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((3) << 6))

#define UART2_PS_MSK                    (BIT0)
#define UART2_SwitchP1011()             CLR_REG_BIT(P_SW2, UART2_PS_MSK)
#define UART2_SwitchP4647()             SET_REG_BIT(P_SW2, UART2_PS_MSK)

#define UART3_PS_MSK                    (BIT1)
#define UART3_SwitchP0001()             CLR_REG_BIT(P_SW2, UART3_PS_MSK)
#define UART3_SwitchP5051()             SET_REG_BIT(P_SW2, UART3_PS_MSK)

#define UART4_PS_MSK                    (BIT2)
#define UART4_SwitchP0203()             CLR_REG_BIT(P_SW2, UART4_PS_MSK)
#define UART4_SwitchP5253()             SET_REG_BIT(P_SW2, UART4_PS_MSK)

#define I2C_PS_MSK                      (BIT5 | BIT4)
#define I2C_SwitchP1415()               MODIFY_REG(P_SW2, I2C_PS_MSK, ((0) << 4))
#define I2C_SwitchP2425()               MODIFY_REG(P_SW2, I2C_PS_MSK, ((1) << 4))
#define I2C_SwitchP7677()               MODIFY_REG(P_SW2, I2C_PS_MSK, ((2) << 4))
#define I2C_SwitchP3332()               MODIFY_REG(P_SW2, I2C_PS_MSK, ((3) << 4))

#define SPI_PS_MSK                      (BIT3 | BIT2)
#define SPI_SwitchP1n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((0) << 2))
#define SPI_SwitchP2n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((1) << 2))
#define SPI_SwitchP4n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((2) << 2))
#define SPI_SwitchP3n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((3) << 2))

#define USART1_PS_MSK                   (BIT3 | BIT2)
#define USART1_SwitchP1n()              MODIFY_REG(P_SW3, USART1_PS_MSK, ((0) << 2))
#define USART1_SwitchP2n()              MODIFY_REG(P_SW3, USART1_PS_MSK, ((1) << 2))
#define USART1_SwitchP4n()              MODIFY_REG(P_SW3, USART1_PS_MSK, ((2) << 2))
#define USART1_SwitchP3n()              MODIFY_REG(P_SW3, USART1_PS_MSK, ((3) << 2))

#define USART2_PS_MSK                   (BIT5 | BIT4)
#define USART2_SwitchP1n()              MODIFY_REG(P_SW3, USART2_PS_MSK, ((0) << 4))
#define USART2_SwitchP2n()              MODIFY_REG(P_SW3, USART2_PS_MSK, ((1) << 4))
#define USART2_SwitchP4n()              MODIFY_REG(P_SW3, USART2_PS_MSK, ((2) << 4))
#define USART2_SwitchP3n()              MODIFY_REG(P_SW3, USART2_PS_MSK, ((3) << 4))

#define CMPO_PS_MSK                     (BIT3)
#define CMPO_SwitchP34()                CLR_REG_BIT(P_SW2, CMPO_PS_MSK)
#define CMPO_SwitchP41()                SET_REG_BIT(P_SW2, CMPO_PS_MSK)

#define CMPNS_MSK                       BIT2
#define CMPN_SwitchP36()                CLR_REG_BIT(CMPEXCFG, CMPNS_MSK)
#define CMPN_SwitchREFV()               SET_REG_BIT(CMPEXCFG, CMPNS_MSK)

#define CMPPS_MSK                       (BIT1 | BIT0)
#define CMPP_SwitchP37()                 MODIFY_REG(CMPEXCFG, CMPPS_MSK, ((0) << 0))
#define CMPP_SwitchP50()                 MODIFY_REG(CMPEXCFG, CMPPS_MSK, ((1) << 0))
#define CMPP_SwitchP51()                 MODIFY_REG(CMPEXCFG, CMPPS_MSK, ((2) << 0))
#define CMPP_SwitchADCIN()               MODIFY_REG(CMPEXCFG, CMPPS_MSK, ((3) << 0))

#define MCLKO_PS_MSK                    (BIT7)
#define CLK_SYSCLKO_SwitchP54()         CLR_REG_BIT(MCLKOCR, MCLKO_PS_MSK)
#define CLK_SYSCLKO_SwitchP16()         SET_REG_BIT(MCLKOCR, MCLKO_PS_MSK)

#define PWMA_C1PS_MSK                   (BIT1 | BIT0)
#define PWMA_C1SwitchP1011()            MODIFY_REG(PWMA_PS, PWMA_C1PS_MSK, ((0) << 0))
#define PWMA_C1SwitchP2021()            MODIFY_REG(PWMA_PS, PWMA_C1PS_MSK, ((1) << 0))
#define PWMA_C1SwitchP6061()            MODIFY_REG(PWMA_PS, PWMA_C1PS_MSK, ((2) << 0))

#define PWMA_C2PS_MSK                   (BIT3 | BIT2)
#define PWMA_C2SwitchP5413()            MODIFY_REG(PWMA_PS, PWMA_C2PS_MSK, ((0) << 2))
#define PWMA_C2SwitchP2223()            MODIFY_REG(PWMA_PS, PWMA_C2PS_MSK, ((1) << 2))
#define PWMA_C2SwitchP6263()            MODIFY_REG(PWMA_PS, PWMA_C2PS_MSK, ((2) << 2))

#define PWMA_C3PS_MSK                   (BIT5 | BIT4)
#define PWMA_C3SwitchP1415()            MODIFY_REG(PWMA_PS, PWMA_C3PS_MSK, ((0) << 4))
#define PWMA_C3SwitchP2425()            MODIFY_REG(PWMA_PS, PWMA_C3PS_MSK, ((1) << 4))
#define PWMA_C3SwitchP6465()            MODIFY_REG(PWMA_PS, PWMA_C3PS_MSK, ((2) << 4))

#define PWMA_C4PS_MSK                   (BIT7 | BIT6)
#define PWMA_C4SwitchP1617()            MODIFY_REG(PWMA_PS, PWMA_C4PS_MSK, ((0) << 6))
#define PWMA_C4SwitchP2627()            MODIFY_REG(PWMA_PS, PWMA_C4PS_MSK, ((1) << 6))
#define PWMA_C4SwitchP6667()            MODIFY_REG(PWMA_PS, PWMA_C4PS_MSK, ((2) << 6))

#define PWMB_C5PS_MSK                   (BIT1 | BIT0)
#define PWMB_C5SwitchP20()              MODIFY_REG(PWMB_PS, PWMB_C5PS_MSK, ((0) << 0))
#define PWMB_C5SwitchP17()              MODIFY_REG(PWMB_PS, PWMB_C5PS_MSK, ((1) << 0))
#define PWMB_C5SwitchP00()              MODIFY_REG(PWMB_PS, PWMB_C5PS_MSK, ((2) << 0))
#define PWMB_C5SwitchP74()              MODIFY_REG(PWMB_PS, PWMB_C5PS_MSK, ((3) << 0))

#define PWMB_C6PS_MSK                   (BIT3 | BIT2)
#define PWMB_C6SwitchP21()              MODIFY_REG(PWMB_PS, PWMB_C6PS_MSK, ((0) << 2))
#define PWMB_C6SwitchP54()              MODIFY_REG(PWMB_PS, PWMB_C6PS_MSK, ((1) << 2))
#define PWMB_C6SwitchP01()              MODIFY_REG(PWMB_PS, PWMB_C6PS_MSK, ((2) << 2))
#define PWMB_C6SwitchP75()              MODIFY_REG(PWMB_PS, PWMB_C6PS_MSK, ((3) << 2))

#define PWMB_C7PS_MSK                   (BIT5 | BIT4)
#define PWMB_C7SwitchP22()              MODIFY_REG(PWMB_PS, PWMB_C7PS_MSK, ((0) << 4))
#define PWMB_C7SwitchP33()              MODIFY_REG(PWMB_PS, PWMB_C7PS_MSK, ((1) << 4))
#define PWMB_C7SwitchP02()              MODIFY_REG(PWMB_PS, PWMB_C7PS_MSK, ((2) << 4))
#define PWMB_C7SwitchP76()              MODIFY_REG(PWMB_PS, PWMB_C7PS_MSK, ((3) << 4))

#define PWMB_C8PS_MSK                   (BIT7 | BIT6)
#define PWMB_C8SwitchP23()              MODIFY_REG(PWMB_PS, PWMB_C8PS_MSK, ((0) << 6))
#define PWMB_C8SwitchP34()              MODIFY_REG(PWMB_PS, PWMB_C8PS_MSK, ((1) << 6))
#define PWMB_C8SwitchP03()              MODIFY_REG(PWMB_PS, PWMB_C8PS_MSK, ((2) << 6))
#define PWMB_C8SwitchP77()              MODIFY_REG(PWMB_PS, PWMB_C8PS_MSK, ((3) << 6))

#define PWMA_ETRPS_MSK                  (BIT1 | BIT0)
#define PWMA_ETRSwitchP32()             MODIFY_REG(PWMA_ETRPS, PWMA_ETRPS_MSK, ((0) << 0))
#define PWMA_ETRSwitchP41()             MODIFY_REG(PWMA_ETRPS, PWMA_ETRPS_MSK, ((1) << 0))
#define PWMA_ETRSwitchP73()             MODIFY_REG(PWMA_ETRPS, PWMA_ETRPS_MSK, ((2) << 0))

#define PWMB_ETRPS_MSK                  (BIT1 | BIT0)
#define PWMB_ETRSwitchP32()             MODIFY_REG(PWMB_ETRPS, PWMB_ETRPS_MSK, ((0) << 0))
#define PWMB_ETRSwitchP06()             MODIFY_REG(PWMB_ETRPS, PWMB_ETRPS_MSK, ((1) << 0))

#define PWMA_BRKPS_MSK                  (BIT3 | BIT2)
#define PWMA_BRKSwitchP35()             MODIFY_REG(PWMA_ETRPS, PWMA_BRKPS_MSK, ((0) << 2))
#define PWMA_BRKSwitchCMPO()            MODIFY_REG(PWMA_ETRPS, PWMA_BRKPS_MSK, ((1) << 2))

#define PWMB_BRKPS_MSK                  (BIT3 | BIT2)
#define PWMB_BRKSwitchP35()             MODIFY_REG(PWMB_ETRPS, PWMB_BRKPS_MSK, ((0) << 2))
#define PWMB_BRKSwitchCMPO()            MODIFY_REG(PWMB_ETRPS, PWMB_BRKPS_MSK, ((1) << 2))

#define LCM_DPS_MSK                     (BIT3 | BIT2)
#define LCM_DATA8BSwitchP2()            MODIFY_REG(LCMIFCFG, LCM_DPS_MSK, ((0) << 2))
#define LCM_DATA8BSwitchP6()            MODIFY_REG(LCMIFCFG, LCM_DPS_MSK, ((1) << 2))
#define LCM_DATA16BSwitchP2P0()         MODIFY_REG(LCMIFCFG, LCM_DPS_MSK, ((0) << 2))
#define LCM_DATA16BSwitchP6P2()         MODIFY_REG(LCMIFCFG, LCM_DPS_MSK, ((1) << 2))
#define LCM_DATA16BSwitchP2P4()         MODIFY_REG(LCMIFCFG, LCM_DPS_MSK, ((2) << 2))
#define LCM_DATA16BSwitchP6P7()         MODIFY_REG(LCMIFCFG, LCM_DPS_MSK, ((3) << 2))

#define LCM_RSPS_MSK                    (BIT6)
#define LCM_RSSwitchP45()               CLR_REG_BIT(LCMIFCFG2, LCM_RSPS_MSK)
#define LCM_RSSwitchP40()               SET_REG_BIT(LCMIFCFG2, LCM_RSPS_MSK)

#define LCM_RWPS_MSK                    (BIT5)
#define LCM_CTRLSwitchP4442()           CLR_REG_BIT(LCMIFCFG2, LCM_RWPS_MSK)
#define LCM_CTRLSwitchP3736()           SET_REG_BIT(LCMIFCFG2, LCM_RWPS_MSK)

/////////////////////////////////////////////////

#define CLKSEL_MCKSEL_MSK               (BIT1 | BIT0)
#define CLK_MCLK_HIRC()                 MODIFY_REG(CLKSEL, CLKSEL_MCKSEL_MSK, ((0x00) << 0))
#define CLK_MCLK_XTAL()                 MODIFY_REG(CLKSEL, CLKSEL_MCKSEL_MSK, ((0x01) << 0))
#define CLK_MCLK_X32K()                 MODIFY_REG(CLKSEL, CLKSEL_MCKSEL_MSK, ((0x02) << 0))
#define CLK_MCLK_LIRC()                 MODIFY_REG(CLKSEL, CLKSEL_MCKSEL_MSK, ((0x03) << 0))

#define CLKSEL_MCK2SEL_MSK              (BIT3 | BIT2)
#define CLK_MCLK2_BYPASS()              MODIFY_REG(CLKSEL, CLKSEL_MCK2SEL_MSK, ((0x00) << 2))
#define CLK_MCLK2_PLLD2()               MODIFY_REG(CLKSEL, CLKSEL_MCK2SEL_MSK, ((0x01) << 2))
#define CLK_MCLK2_PLLD4()               MODIFY_REG(CLKSEL, CLKSEL_MCK2SEL_MSK, ((0x02) << 2))
#define CLK_MCLK2_IRC48M()              MODIFY_REG(CLKSEL, CLKSEL_MCK2SEL_MSK, ((0x03) << 2))

#define USBCLK_ENCKM_MSK                (BIT7)
#define CLK_PLL_Enable()                SET_REG_BIT(USBCLK, USBCLK_ENCKM_MSK)
#define CLK_PLL_Disable()               CLR_REG_BIT(USBCLK, USBCLK_ENCKM_MSK)

#define USBCLK_PCKI_MSK                 (BIT6 | BIT5)
#define CLK_PLL_PreDivider1()           MODIFY_REG(USBCLK, USBCLK_PCKI_MSK, ((0) << 5))
#define CLK_PLL_PreDivider2()           MODIFY_REG(USBCLK, USBCLK_PCKI_MSK, ((1) << 5))
#define CLK_PLL_PreDivider3()           MODIFY_REG(USBCLK, USBCLK_PCKI_MSK, ((2) << 5))
#define CLK_PLL_PreDivider4()           MODIFY_REG(USBCLK, USBCLK_PCKI_MSK, ((3) << 5))

#define CKSEL_CKMS_MSK                  (BIT7)
#define CLK_PLL_Output96MHz()           CLR_REG_BIT(CLKSEL, CKSEL_CKMS_MSK)
#define CLK_PLL_Output144MHz()          SET_REG_BIT(CLKSEL, CKSEL_CKMS_MSK)

#define CKSEL_HSIOCK_MSK                (BIT6)
#define CLK_HSIOCK_MCLK()               CLR_REG_BIT(CLKSEL, CKSEL_HSIOCK_MSK)
#define CLK_HSIOCK_PLL()                SET_REG_BIT(CLKSEL, CKSEL_HSIOCK_MSK)

#define CLK_HSIOCK_Divider(n)           WRITE_REG(HSCLKDIV, (n))

#define CLK_SYSCLK_Divider(n)           WRITE_REG(CLKDIV, (n))

#define MCLKODIV_MSK                    (~(BIT7))
#define CLK_SYSCLKO_Divider(n)          MODIFY_REG(MCLKOCR, MCLKODIV_MSK, (n))

#define HIRCCR_EN_MSK                   (BIT7)
#define HIRCCR_ST_MSK                   (BIT0)
#define CLK_HIRC_Enable()               SET_REG_BIT(HIRCCR, HIRCCR_EN_MSK)
#define CLK_HIRC_WaitStable()           while (READ_REG_BIT(HIRCCR, HIRCCR_ST_MSK) == 0)

#define IRCBAND_SEL_MSK                 (BIT1 | BIT0)
#define CLK_HIRC_6MHzBand()             MODIFY_REG(IRCBAND, IRCBAND_SEL_MSK, ((0) << 0))
#define CLK_HIRC_10MHzBand()            MODIFY_REG(IRCBAND, IRCBAND_SEL_MSK, ((1) << 0))
#define CLK_HIRC_27MHzBand()            MODIFY_REG(IRCBAND, IRCBAND_SEL_MSK, ((2) << 0))
#define CLK_HIRC_44MHzBand()            MODIFY_REG(IRCBAND, IRCBAND_SEL_MSK, ((3) << 0))

#define IRC48MCR_EN_MSK                 (BIT7)
#define IRC48MCR_ST_MSK                 (BIT0)
#define CLK_IRC48M_Enable()             SET_REG_BIT(IRC48MCR, IRC48MCR_EN_MSK)
#define CLK_IRC48M_WaitStable()         while (READ_REG_BIT(IRC48MCR, IRC48MCR_ST_MSK) == 0)

#define LIRCCR_EN_MSK                   (BIT7)
#define LIRCCR_ST_MSK                   (BIT0)
#define CLK_LIRC_Enable()               SET_REG_BIT(IRC32KCR, LIRCCR_EN_MSK)
#define CLK_LIRC_WaitStable()           while (READ_REG_BIT(IRC32KCR, LIRCCR_ST_MSK) == 0)

#define XOSCCR_EN_MSK                   (BIT7)
#define XOSCCR_XITYPE_MSK               (BIT6)
#define XOSCCR_GAIN_MSK                 (BIT5)
#define XOSCCR_FILTER_MSK               (BIT3 | BIT2)
#define XOSCCR_ST_MSK                   (BIT0)

#define CLK_XTAL_Enable()               SET_REG_BIT(XOSCCR, XOSCCR_EN_MSK | XOSCCR_XITYPE_MSK)
#define CLK_XOSC_Enable()               SET_REG_BIT(XOSCCR, XOSCCR_EN_MSK)
#define CLK_XOSC_WaitStable()           while (READ_REG_BIT(XOSCCR, XOSCCR_ST_MSK) == 0)

#define CLK_XOSC_LowGain()              CLR_REG_BIT(XOSCCR, XOSCCR_GAIN_MSK)
#define CLK_XOSC_FullGain()             SET_REG_BIT(XOSCCR, XOSCCR_GAIN_MSK)

#define CLK_XOSC_HighFilter()           MODIFY_REG(CLKSEL, XOSCCR_FILTER_MSK, ((0) << 2))
#define CLK_XOSC_MiddleFilter()         MODIFY_REG(CLKSEL, XOSCCR_FILTER_MSK, ((1) << 2))
#define CLK_XOSC_LowFilter()            MODIFY_REG(CLKSEL, XOSCCR_FILTER_MSK, ((2) << 2))

#define X32KCR_EN_MSK                   (BIT7)
#define X32KCR_GAIN_MSK                 (BIT6)
#define X32KCR_ST_MSK                   (BIT0)

#define CLK_X32K_Enable()               SET_REG_BIT(X32KCR, X32KCR_EN_MSK)
#define CLK_X32K_WaitStable()           while (READ_REG_BIT(X32KCR, X32KCR_ST_MSK) == 0)

#define CLK_X32K_LowGain()              CLR_REG_BIT(X32KCR, X32KCR_GAIN_MSK)
#define CLK_X32K_FullGain()             SET_REG_BIT(X32KCR, X32KCR_GAIN_MSK)

#define IRCBAND_USBCKS_MSK              (BIT7 | BIT6)
#define USB_CLK_PLLD2()                 MODIFY_REG(IRCBAND, IRCBAND_USBCKS_MSK, ((0) << 6))
#define USB_CLK_IRC48M()                MODIFY_REG(IRCBAND, IRCBAND_USBCKS_MSK, ((2) << 6))
#define USB_CLK_SYSCLK()                MODIFY_REG(IRCBAND, IRCBAND_USBCKS_MSK, ((1) << 6))

/////////////////////////////////////////////////

#define CRECR_ENCRE_MSK                 (BIT7)
#define CRECR_MONO_MSK                  (BIT6)
#define CRECR_UPT_MSK                   (BIT5 | BIT4)
#define CRECR_CREHF_MSK                 (BIT3)
#define CRECR_CREINC_MSK                (BIT2)
#define CRECR_CREDEC_MSK                (BIT1)
#define CRECR_CRERDY_MSK                (BIT0)

#define CRE_Enable()                    SET_REG_BIT(CRECR, CRECR_ENCRE_MSK)
#define CRE_Disable()                   CLR_REG_BIT(CRECR, CRECR_ENCRE_MSK)

#define CRE_OneStepMode()               CLR_REG_BIT(CRECR, CRECR_MONO_MSK)
#define CRE_TwoStepsMode()              SET_REG_BIT(CRECR, CRECR_MONO_MSK)

#define CRE_CalibCycle_1ms()            MODIFY_REG(CRECR, CRECR_UPT_MSK, ((0) << 4))
#define CRE_CalibCycle_4ms()            MODIFY_REG(CRECR, CRECR_UPT_MSK, ((1) << 4))
#define CRE_CalibCycle_32ms()           MODIFY_REG(CRECR, CRECR_UPT_MSK, ((2) << 4))
#define CRE_CalibCycle_64ms()           MODIFY_REG(CRECR, CRECR_UPT_MSK, ((3) << 4))

#define CRE_LowFrequency()              CLR_REG_BIT(CRECR, CRECR_CREHF_MSK)
#define CRE_HighFrequency()             SET_REG_BIT(CRECR, CRECR_CREHF_MSK)

#define CRE_CalibReady()                READ_REG_BIT(CRECR, CRECR_CRERDY_MSK)

#define CRE_LFCNT(freq)                 ((16UL * (freq)) / 32768)
#define CRE_HFCNT(freq)                 ((8UL * (freq)) / 32768)

#define CRE_SetCalibCounter(n)          WRITE_REG(CRECNTH, HIBYTE(n)); \
                                        WRITE_REG(CRECNTL, LOBYTE(n))

#define CRE_LFERROR(freq, err)          ((BYTE)(CRE_LFCNT(freq) * (err) / 1000))
#define CRE_HFERROR(freq, err)          ((BYTE)(CRE_HFCNT(freq) * (err) / 1000))

#define CRE_SetCalibError(n)            WRITE_REG(CRERES, (n))

/////////////////////////////////////////////////

#define WDTCONTR_FLAG_MSK               BIT7
#define WDTCONTR_EN_MSK                 BIT5
#define WDTCONTR_CLR_MSK                BIT4
#define WDTCONTR_IDL_MSK                BIT3
#define WDTCONTR_PS_MSK                 (BIT2 | BIT1 | BIT0)

#define WDT_Enable()                    SET_REG_BIT(WDT_CONTR, WDTCONTR_EN_MSK)
#define WDT_Clear()                     SET_REG_BIT(WDT_CONTR, WDTCONTR_CLR_MSK)
#define WDT_CheckWDTReset()             READ_REG_BIT(WDT_CONTR, WDTCONTR_FLAG_MSK)
#define WDT_IdlePause()                 CLR_REG_BIT(WDT_CONTR, WDTCONTR_IDL_MSK)
#define WDT_IdleContinue()              SET_REG_BIT(WDT_CONTR, WDTCONTR_IDL_MSK)

#define WDT_SetPrescale(n)              MODIFY_REG(WDT_CONTR, WDTCONTR_PS_MSK, ((n) << 0))
#define WDT_SetPrescale2()              WDT_SetPrescale(0)
#define WDT_SetPrescale4()              WDT_SetPrescale(1)
#define WDT_SetPrescale8()              WDT_SetPrescale(2)
#define WDT_SetPrescale16()             WDT_SetPrescale(3)
#define WDT_SetPrescale32()             WDT_SetPrescale(4)
#define WDT_SetPrescale64()             WDT_SetPrescale(5)
#define WDT_SetPrescale128()            WDT_SetPrescale(6)
#define WDT_SetPrescale256()            WDT_SetPrescale(7)

/////////////////////////////////////////////////

#define CHIPID_ReadID0()                CHIPID0
#define CHIPID_ReadID1()                CHIPID1
#define CHIPID_ReadID2()                CHIPID2
#define CHIPID_ReadID3()                CHIPID3
#define CHIPID_ReadID4()                CHIPID4
#define CHIPID_ReadID5()                CHIPID5
#define CHIPID_ReadID6()                CHIPID6
#define CHIPID_ReadREFVoltage()         MAKEWORD(CHIPID8, CHIPID7)
#define CHIPID_ReadLIRCFrequency()      MAKEWORD(CHIPID10, CHIPID9)
#define CHIPID_Read22MIRCTrim()         CHIPID11
#define CHIPID_Read24MIRCTrim()         CHIPID12
#define CHIPID_Read27MIRCTrim()         CHIPID13
#define CHIPID_Read30MIRCTrim()         CHIPID14
#define CHIPID_Read33MIRCTrim()         CHIPID15
#define CHIPID_Read35MIRCTrim()         CHIPID16
#define CHIPID_Read36MIRCTrim()         CHIPID17
#define CHIPID_Read40MIRCTrim()         CHIPID18
#define CHIPID_Read44MIRCTrim()         CHIPID19
#define CHIPID_Read45MIRCTrim()         CHIPID20
#define CHIPID_Read6MVRTrim()           CHIPID21
#define CHIPID_Read10MVRTrim()          CHIPID22
#define CHIPID_Read27MVRTrim()          CHIPID23
#define CHIPID_Read44MVRTrim()          CHIPID24
#define CHIPID_ReadTag()                CHIPID31

#define HIRC_22M1184()                          \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read22MIRCTrim();           \
    VRTRIM = CHIPID_Read27MVRTrim();            \
    CLK_HIRC_27MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_24M()                              \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read24MIRCTrim();           \
    VRTRIM = CHIPID_Read27MVRTrim();            \
    CLK_HIRC_27MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_27M()                              \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read27MIRCTrim();           \
    VRTRIM = CHIPID_Read27MVRTrim();            \
    CLK_HIRC_27MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_30M()                              \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read30MIRCTrim();           \
    VRTRIM = CHIPID_Read27MVRTrim();            \
    CLK_HIRC_27MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_33M1776()                          \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read33MIRCTrim();           \
    VRTRIM = CHIPID_Read27MVRTrim();            \
    CLK_HIRC_27MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_35M()                              \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read35MIRCTrim();           \
    VRTRIM = CHIPID_Read44MVRTrim();            \
    CLK_HIRC_44MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_36M864()                           \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read36MIRCTrim();           \
    VRTRIM = CHIPID_Read44MVRTrim();            \
    CLK_HIRC_44MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_40M()                              \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read40MIRCTrim();           \
    VRTRIM = CHIPID_Read44MVRTrim();            \
    CLK_HIRC_44MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_44M2368()                          \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read44MIRCTrim();           \
    VRTRIM = CHIPID_Read44MVRTrim();            \
    CLK_HIRC_44MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

#define HIRC_45M1584()                          \
{                                               \
    /* CLKDIV = 0x04; */                        \
    IRTRIM = CHIPID_Read45MIRCTrim();           \
    VRTRIM = CHIPID_Read44MVRTrim();            \
    CLK_HIRC_44MHzBand();                       \
    /* CLKDIV = 0x00; */                        \
}

/////////////////////////////////////////////////

#define PORT_SetFallingInt(p, b)        CLR_REG_BIT(P##p##IM0, (b)); \
                                        CLR_REG_BIT(P##p##IM1, (b))

#define PORT_SetRisingInt(p, b)         SET_REG_BIT(P##p##IM0, (b)); \
                                        CLR_REG_BIT(P##p##IM1, (b))

#define PORT_SetLowLevelInt(p, b)       CLR_REG_BIT(P##p##IM0, (b)); \
                                        SET_REG_BIT(P##p##IM1, (b))

#define PORT_SetHighLevelInt(p, b)      SET_REG_BIT(P##p##IM0, (b)); \
                                        SET_REG_BIT(P##p##IM1, (b))

#define SetP0nFallingInt(b)             PORT_SetFallingInt(0, (b))
#define SetP1nFallingInt(b)             PORT_SetFallingInt(1, (b))
#define SetP2nFallingInt(b)             PORT_SetFallingInt(2, (b))
#define SetP3nFallingInt(b)             PORT_SetFallingInt(3, (b))
#define SetP4nFallingInt(b)             PORT_SetFallingInt(4, (b))
#define SetP5nFallingInt(b)             PORT_SetFallingInt(5, (b))
#define SetP6nFallingInt(b)             PORT_SetFallingInt(6, (b))
#define SetP7nFallingInt(b)             PORT_SetFallingInt(7, (b))

#define SetP0nRisingInt(b)              PORT_SetRisingInt(0, (b))
#define SetP1nRisingInt(b)              PORT_SetRisingInt(1, (b))
#define SetP2nRisingInt(b)              PORT_SetRisingInt(2, (b))
#define SetP3nRisingInt(b)              PORT_SetRisingInt(3, (b))
#define SetP4nRisingInt(b)              PORT_SetRisingInt(4, (b))
#define SetP5nRisingInt(b)              PORT_SetRisingInt(5, (b))
#define SetP6nRisingInt(b)              PORT_SetRisingInt(6, (b))
#define SetP7nRisingInt(b)              PORT_SetRisingInt(7, (b))

#define SetP0nLowLevelInt(b)            PORT_SetLowLevelInt(0, (b))
#define SetP1nLowLevelInt(b)            PORT_SetLowLevelInt(1, (b))
#define SetP2nLowLevelInt(b)            PORT_SetLowLevelInt(2, (b))
#define SetP3nLowLevelInt(b)            PORT_SetLowLevelInt(3, (b))
#define SetP4nLowLevelInt(b)            PORT_SetLowLevelInt(4, (b))
#define SetP5nLowLevelInt(b)            PORT_SetLowLevelInt(5, (b))
#define SetP6nLowLevelInt(b)            PORT_SetLowLevelInt(6, (b))
#define SetP7nLowLevelInt(b)            PORT_SetLowLevelInt(7, (b))

#define SetP0nHighLevelInt(b)           PORT_SetHighLevelInt(0, (b))
#define SetP1nHighLevelInt(b)           PORT_SetHighLevelInt(1, (b))
#define SetP2nHighLevelInt(b)           PORT_SetHighLevelInt(2, (b))
#define SetP3nHighLevelInt(b)           PORT_SetHighLevelInt(3, (b))
#define SetP4nHighLevelInt(b)           PORT_SetHighLevelInt(4, (b))
#define SetP5nHighLevelInt(b)           PORT_SetHighLevelInt(5, (b))
#define SetP6nHighLevelInt(b)           PORT_SetHighLevelInt(6, (b))
#define SetP7nHighLevelInt(b)           PORT_SetHighLevelInt(7, (b))

#define PORT_EnableIntWaieup(p, b)      SET_REG_BIT(P##p##WKUE, (b))

#define SetP0nIntWaieup(b)              PORT_EnableIntWaieup(0, (b))
#define SetP1nIntWaieup(b)              PORT_EnableIntWaieup(1, (b))
#define SetP2nIntWaieup(b)              PORT_EnableIntWaieup(2, (b))
#define SetP3nIntWaieup(b)              PORT_EnableIntWaieup(3, (b))
#define SetP4nIntWaieup(b)              PORT_EnableIntWaieup(4, (b))
#define SetP5nIntWaieup(b)              PORT_EnableIntWaieup(5, (b))
#define SetP6nIntWaieup(b)              PORT_EnableIntWaieup(6, (b))
#define SetP7nIntWaieup(b)              PORT_EnableIntWaieup(7, (b))

/////////////////////////////////////////////////

#define TIMER0_Run()                    (TR0 = 1)
#define TIMER0_Stop()                   (TR0 = 0)

#define TIMER0_SetReload8(n)            (TH0 = LOBYTE(n), TL0 = LOBYTE(n))
#define TIMER0_SetReload16(n)           (TH0 = HIBYTE(n), TL0 = LOBYTE(n))
#define TIMER0_SetPrescale(n)           (TM0PS = (n))

#define TMOD_T0M_MSK                    (BIT1 | BIT0)
#define TIMER0_Mode0()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((0) << 0))
#define TIMER0_Mode1()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((1) << 0))
#define TIMER0_Mode2()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((2) << 0))
#define TIMER0_Mode3()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((3) << 0))

#define AUXR_T0X12_MSK                  BIT7
#define TIMER0_1TMode()                 SET_REG_BIT(AUXR, AUXR_T0X12_MSK)
#define TIMER0_12TMode()                CLR_REG_BIT(AUXR, AUXR_T0X12_MSK)

#define TMOD_T0CT_MSK                   BIT2
#define TIMER0_TimerMode()              CLR_REG_BIT(TMOD, TMOD_T0CT_MSK)
#define TIMER0_CounterMode()            SET_REG_BIT(TMOD, TMOD_T0CT_MSK)

#define TMOD_T0GATE_MSK                 BIT3
#define TIMER0_EnableGateINT0()         SET_REG_BIT(TMOD, TMOD_T0GATE_MSK)
#define TIMER0_DisableGateINT0()        CLR_REG_BIT(TMOD, TMOD_T0GATE_MSK)

#define INTCLKO_T0CLKO_MSK              BIT0
#define TIMER0_EnableCLKO()             SET_REG_BIT(INTCLKO, INTCLKO_T0CLKO_MSK)
#define TIMER0_DisableCLKO()            CLR_REG_BIT(INTCLKO, INTCLKO_T0CLKO_MSK)

////////////////////////

#define TIMER1_Run()                    (TR1 = 1)
#define TIMER1_Stop()                   (TR1 = 0)

#define TIMER1_SetReload8(n)            (TH1 = LOBYTE(n), TL1 = LOBYTE(n))
#define TIMER1_SetReload16(n)           (TH1 = HIBYTE(n), TL1 = LOBYTE(n))
#define TIMER1_SetPrescale(n)           (TM1PS = (n))

#define TMOD_T1M_MSK                    (BIT5 | BIT4)
#define TIMER1_Mode0()                  MODIFY_REG(TMOD, TMOD_T1M_MSK, ((0) << 4))
#define TIMER1_Mode1()                  MODIFY_REG(TMOD, TMOD_T1M_MSK, ((1) << 4))
#define TIMER1_Mode2()                  MODIFY_REG(TMOD, TMOD_T1M_MSK, ((2) << 4))

#define AUXR_T1X12_MSK                  BIT6
#define TIMER1_1TMode()                 SET_REG_BIT(AUXR, AUXR_T1X12_MSK)
#define TIMER1_12TMode()                CLR_REG_BIT(AUXR, AUXR_T1X12_MSK)

#define TMOD_T1CT_MSK                   BIT6
#define TIMER1_TimerMode()              CLR_REG_BIT(TMOD, TMOD_T1CT_MSK)
#define TIMER1_CounterMode()            SET_REG_BIT(TMOD, TMOD_T1CT_MSK)

#define TMOD_T1GATE_MSK                 BIT7
#define TIMER1_EnableGateINT1()         SET_REG_BIT(TMOD, TMOD_T1GATE_MSK)
#define TIMER1_DisableGateINT1()        CLR_REG_BIT(TMOD, TMOD_T1GATE_MSK)

#define INTCLKO_T1CLKO_MSK              BIT1
#define TIMER1_EnableCLKO()             SET_REG_BIT(INTCLKO, INTCLKO_T1CLKO_MSK)
#define TIMER1_DisableCLKO()            CLR_REG_BIT(INTCLKO, INTCLKO_T1CLKO_MSK)

////////////////////////

#define AUXR_T2R_MSK                    BIT4
#define TIMER2_Run()                    SET_REG_BIT(AUXR, AUXR_T2R_MSK)
#define TIMER2_Stop()                   CLR_REG_BIT(AUXR, AUXR_T2R_MSK)

#define TIMER2_SetReload16(n)           (T2H = HIBYTE(n), T2L = LOBYTE(n))
#define TIMER2_SetPrescale(n)           (TM2PS = (n))

#define AUXR_T2X12_MSK                  BIT2
#define TIMER2_1TMode()                 SET_REG_BIT(AUXR, AUXR_T2X12_MSK)
#define TIMER2_12TMode()                CLR_REG_BIT(AUXR, AUXR_T2X12_MSK)

#define AUXR_T2CT_MSK                   BIT3
#define TIMER2_TimerMode()              CLR_REG_BIT(AUXR, AUXR_T2CT_MSK)
#define TIMER2_CounterMode()            SET_REG_BIT(AUXR, AUXR_T2CT_MSK)

#define INTCLKO_T2CLKO_MSK              BIT2
#define TIMER2_EnableCLKO()             SET_REG_BIT(INTCLKO, INTCLKO_T2CLKO_MSK)
#define TIMER2_DisableCLKO()            CLR_REG_BIT(INTCLKO, INTCLKO_T2CLKO_MSK)

////////////////////////

#define T4T3M_T3R_MSK                   BIT3
#define TIMER3_Run()                    SET_REG_BIT(T4T3M, T4T3M_T3R_MSK)
#define TIMER3_Stop()                   CLR_REG_BIT(T4T3M, T4T3M_T3R_MSK)

#define TIMER3_SetReload16(n)           (T3H = HIBYTE(n), T3L = LOBYTE(n))
#define TIMER3_SetPrescale(n)           (TM3PS = (n))

#define T4T3M_T3X12_MSK                 BIT1
#define TIMER3_1TMode()                 SET_REG_BIT(T4T3M, T4T3M_T3X12_MSK)
#define TIMER3_12TMode()                CLR_REG_BIT(T4T3M, T4T3M_T3X12_MSK)

#define T4T3M_T3CT_MSK                  BIT2
#define TIMER3_TimerMode()              CLR_REG_BIT(T4T3M, T4T3M_T3CT_MSK)
#define TIMER3_CounterMode()            SET_REG_BIT(T4T3M, T4T3M_T3CT_MSK)

#define T4T3M_T3CLKO_MSK                BIT0
#define TIMER3_EnableCLKO()             SET_REG_BIT(T4T3M, T4T3M_T3CLKO_MSK)
#define TIMER3_DisableCLKO()            CLR_REG_BIT(T4T3M, T4T3M_T3CLKO_MSK)

#define T3T4PIN_T3T4SEL_MSK             BIT0
#define T3T4_CLKO_SwitchP0507()         CLR_REG_BIT(T3T4PIN, T3T4PIN_T3T4SEL_MSK)
#define T3T4_CLKO_SwitchP0103()         SET_REG_BIT(T3T4PIN, T3T4PIN_T3T4SEL_MSK)

////////////////////////

#define T4T3M_T4R_MSK                   BIT7
#define TIMER4_Run()                    SET_REG_BIT(T4T3M, T4T3M_T4R_MSK)
#define TIMER4_Stop()                   CLR_REG_BIT(T4T3M, T4T3M_T4R_MSK)

#define TIMER4_SetReload16(n)           (T4H = HIBYTE(n), T4L = LOBYTE(n))
#define TIMER4_SetPrescale(n)           (TM4PS = (n))

#define T4T3M_T4X12_MSK                 BIT5
#define TIMER4_1TMode()                 SET_REG_BIT(T4T3M, T4T3M_T4X12_MSK)
#define TIMER4_12TMode()                CLR_REG_BIT(T4T3M, T4T3M_T4X12_MSK)

#define T4T3M_T4CT_MSK                  BIT6
#define TIMER4_TimerMode()              CLR_REG_BIT(T4T3M, T4T3M_T4CT_MSK)
#define TIMER4_CounterMode()            SET_REG_BIT(T4T3M, T4T3M_T4CT_MSK)

#define T4T3M_T4CLKO_MSK                BIT4
#define TIMER4_EnableCLKO()             SET_REG_BIT(T4T3M, T4T3M_T4CLKO_MSK)
#define TIMER4_DisableCLKO()            CLR_REG_BIT(T4T3M, T4T3M_T4CLKO_MSK)

////////////////////////

#define T11CR_T11R_MSK                  BIT7
#define TIMER11_Run()                   SET_REG_BIT(T11CR, T11CR_T11R_MSK)
#define TIMER11_Stop()                  CLR_REG_BIT(T11CR, T11CR_T11R_MSK)

#define TIMER11_CheckFlag()             READ_REG_BIT(T11CR, T11CR_T11IF_MSK)
#define TIMER11_ClearFlag()             CLR_REG_BIT(T11CR, T11CR_T11IF_MSK)

#define TIMER11_SetReload16(n)          (T11H = HIBYTE(n), T11L = LOBYTE(n))
#define TIMER11_SetPrescale(n)          (T11PS = (n))

#define T11CR_T11X12_MSK                BIT4
#define TIMER11_1TMode()                SET_REG_BIT(T11CR, T11CR_T11X12_MSK)
#define TIMER11_12TMode()               CLR_REG_BIT(T11CR, T11CR_T11X12_MSK)

#define T11CR_T11CT_MSK                 BIT6
#define TIMER11_TimerMode()             CLR_REG_BIT(T11CR, T11CR_T11CT_MSK)
#define TIMER11_CounterMode()           SET_REG_BIT(T11CR, T11CR_T11CT_MSK)

#define T11CR_T11CLKO_MSK               BIT5
#define TIMER11_EnableCLKO()            SET_REG_BIT(T11CR, T11CR_T11CLKO_MSK)
#define TIMER11_DisableCLKO()           CLR_REG_BIT(T11CR, T11CR_T11CLKO_MSK)

#define T11CR_T11CS_MSK                 (BIT3 | BIT2)
#define TIMER11_ClockSource(n)          MODIFY_REG(T11CR, T11CR_T11CS_MSK, ((n) << 2))
#define TIMER11_CLK_SYSCLK()            TIMER11_ClockSource(0)
#define TIMER11_CLK_HIRC()              TIMER11_ClockSource(1)
#define TIMER11_CLK_X32K()              TIMER11_ClockSource(2)
#define TIMER11_CLK_LIRC()              TIMER11_ClockSource(3)

/////////////////////////////////////////////////

#define SCON_SM_MSK                     (BIT7 | BIT6)
#define UART1_SetMode(n)                MODIFY_REG(SCON, SCON_SM_MSK, ((n) << 6))
#define UART1_Mode0()                   UART1_SetMode(0)
#define UART1_Mode1()                   UART1_SetMode(1)
#define UART1_Mode2()                   UART1_SetMode(2)
#define UART1_Mode3()                   UART1_SetMode(3)

#define UART1_EnableRx()                (REN = 1)
#define UART1_DisableRx()               (REN = 0)
#define UART1_SetTB8(b)                 (TB8 = (b))
#define UART1_ReadRB8()                 (RB8)

#define UART1_SendData(d)               (SBUF = (d))
#define UART1_ReadData()                (SBUF)

#define PCON_SMOD_MSK                   BIT7
#define UART1_BaudrateX2()              SET_REG_BIT(PCON, PCON_SMOD_MSK)

#define AUXR_M0X6_MSK                   BIT5
#define UART1_Mode0BaudrateX6()         SET_REG_BIT(AUXR, AUXR_M0X6_MSK)

#define USARTCR2_PCEN_MSK               BIT2
#define USARTCR2_PS_MSK                 BIT1
#define UART1_NoneParity()              CLR_REG_BIT(USARTCR2, USARTCR2_PCEN_MSK)
#define UART1_OddParity()               SET_REG_BIT(USARTCR2, USARTCR2_PCEN_MSK); \
                                        SET_REG_BIT(USARTCR2, USARTCR2_PS_MSK)
#define UART1_EvenParity()              SET_REG_BIT(USARTCR2, USARTCR2_PCEN_MSK); \
                                        CLR_REG_BIT(USARTCR2, USARTCR2_PS_MSK)
#define UART1_MarkParity()              CLR_REG_BIT(USARTCR2, USARTCR2_PCEN_MSK); \
                                        UART1_SetTB8(1)
#define UART1_SpaceParity()             CLR_REG_BIT(USARTCR2, USARTCR2_PCEN_MSK); \
                                        UART1_SetTB8(0)

#define UR1TOCR_ENTO_MSK                BIT7
#define UART1_EnableTimeout()           SET_REG_BIT(UR1TOCR, UR1TOCR_ENTO_MSK)
#define UART1_DisableTimeout()          CLR_REG_BIT(UR1TOCR, UR1TOCR_ENTO_MSK)

#define UR1TOCR_SCALE_MSK               BIT5
#define UART1_TimeoutScale_SYSCLK()     SET_REG_BIT(UR1TOCR, UR1TOCR_SCALE_MSK)
#define UART1_TimeoutScale_BRT()        CLR_REG_BIT(UR1TOCR, UR1TOCR_SCALE_MSK)

#define UART1_SetTimeoutInterval(n)     UR1TOTL = BYTE0(n); \
                                        UR1TOTH = BYTE1(n); \
                                        UR1TOTE = BYTE2(n)

#define AUXR_S1BRT_MSK                  BIT0
#define UART1_Timer1BRT()               CLR_REG_BIT(AUXR, AUXR_S1BRT_MSK)
#define UART1_Timer2BRT()               SET_REG_BIT(AUXR, AUXR_S1BRT_MSK)

////////////////////////

#define S2CON_S2SM_MSK                  BIT7
#define UART2_SetMode(n)                MODIFY_REG(S2CON, S2CON_S2SM_MSK, ((n) << 7))
#define UART2_Mode0()                   CLR_REG_BIT(S2CON, S2CON_S2SM_MSK)
#define UART2_Mode1()                   SET_REG_BIT(S2CON, S2CON_S2SM_MSK)

#define S2CON_S2REN_MSK                 BIT4
#define UART2_EnableRx()                SET_REG_BIT(S2CON, S2CON_S2REN_MSK)
#define UART2_DisableRx()               CLR_REG_BIT(S2CON, S2CON_S2REN_MSK)

#define S2CON_S2TB8_MSK                 BIT3
#define UART2_SetTB8(b)                 MODIFY_REG(S2CON, S2CON_S2TB8_MSK, ((b) << 3))

#define S2CON_S2RB8_MSK                 BIT2
#define UART2_ReadRB8()                 READ_REG_BIT(S2CON, S2CON_S2RB8_MSK)

#define UART2_SendData(d)               (S2BUF = (d))
#define UART2_ReadData()                (S2BUF)

#define UR2TOCR_ENTO_MSK                BIT7
#define UART2_EnableTimeout()           SET_REG_BIT(UR2TOCR, UR2TOCR_ENTO_MSK)
#define UART2_DisableTimeout()          CLR_REG_BIT(UR2TOCR, UR2TOCR_ENTO_MSK)

#define UR2TOCR_SCALE_MSK               BIT5
#define UART2_TimeoutScale_SYSCLK()     SET_REG_BIT(UR2TOCR, UR2TOCR_SCALE_MSK)
#define UART2_TimeoutScale_BRT()        CLR_REG_BIT(UR2TOCR, UR2TOCR_SCALE_MSK)

#define UART2_SetTimeoutInterval(n)     UR2TOTL = BYTE0(n); \
                                        UR2TOTH = BYTE1(n); \
                                        UR2TOTE = BYTE2(n)

////////////////////////

#define S3CON_S3SM_MSK                  BIT7
#define UART3_SetMode(n)                MODIFY_REG(S3CON, S3CON_S3SM_MSK, ((n) << 7))
#define UART3_Mode0()                   CLR_REG_BIT(S3CON, S3CON_S3SM_MSK)
#define UART3_Mode1()                   SET_REG_BIT(S3CON, S3CON_S3SM_MSK)

#define S3CON_S3REN_MSK                 BIT4
#define UART3_EnableRx()                SET_REG_BIT(S3CON, S3CON_S3REN_MSK)
#define UART3_DisableRx()               CLR_REG_BIT(S3CON, S3CON_S3REN_MSK)

#define S3CON_S3TB8_MSK                 BIT3
#define UART3_SetTB8(b)                 MODIFY_REG(S3CON, S3CON_S3TB8_MSK, ((b) << 3))

#define S3CON_S3RB8_MSK                 BIT2
#define UART3_ReadRB8()                 READ_REG_BIT(S3CON, S3CON_S3RB8_MSK)

#define UART3_SendData(d)               (S3BUF = (d))
#define UART3_ReadData()                (S3BUF)

#define UR3TOCR_ENTO_MSK                BIT7
#define UART3_EnableTimeout()           SET_REG_BIT(UR3TOCR, UR3TOCR_ENTO_MSK)
#define UART3_DisableTimeout()          CLR_REG_BIT(UR3TOCR, UR3TOCR_ENTO_MSK)

#define UR3TOCR_SCALE_MSK               BIT5
#define UART3_TimeoutScale_SYSCLK()     SET_REG_BIT(UR3TOCR, UR3TOCR_SCALE_MSK)
#define UART3_TimeoutScale_BRT()        CLR_REG_BIT(UR3TOCR, UR3TOCR_SCALE_MSK)

#define UART3_SetTimeoutInterval(n)     UR3TOTL = BYTE0(n); \
                                        UR3TOTH = BYTE1(n); \
                                        UR3TOTE = BYTE2(n)

#define S3CON_S3BRT_MSK                 BIT6
#define UART3_Timer2BRT()               CLR_REG_BIT(S3CON, S3CON_S3BRT_MSK)
#define UART3_Timer3BRT()               SET_REG_BIT(S3CON, S3CON_S3BRT_MSK)

////////////////////////

#define S4CON_S4SM_MSK                  BIT7
#define UART4_SetMode(n)                MODIFY_REG(S4CON, S4CON_S4SM_MSK, ((n) << 7))
#define UART4_Mode0()                   CLR_REG_BIT(S4CON, S4CON_S4SM_MSK)
#define UART4_Mode1()                   SET_REG_BIT(S4CON, S4CON_S4SM_MSK)

#define S4CON_S4REN_MSK                 BIT4
#define UART4_EnableRx()                SET_REG_BIT(S4CON, S4CON_S4REN_MSK)
#define UART4_DisableRx()               CLR_REG_BIT(S4CON, S4CON_S4REN_MSK)

#define S4CON_S4TB8_MSK                 BIT3
#define UART4_SetTB8(b)                 MODIFY_REG(S4CON, S4CON_S4TB8_MSK, ((b) << 3))

#define S4CON_S4RB8_MSK                 BIT2
#define UART4_ReadRB8()                 READ_REG_BIT(S4CON, S4CON_S4RB8_MSK)

#define UART4_SendData(d)               (S4BUF = (d))
#define UART4_ReadData()                (S4BUF)

#define UR4TOCR_ENTO_MSK                BIT7
#define UART4_EnableTimeout()           SET_REG_BIT(UR4TOCR, UR4TOCR_ENTO_MSK)
#define UART4_DisableTimeout()          CLR_REG_BIT(UR4TOCR, UR4TOCR_ENTO_MSK)

#define UR4TOCR_SCALE_MSK               BIT5
#define UART4_TimeoutScale_SYSCLK()     SET_REG_BIT(UR4TOCR, UR4TOCR_SCALE_MSK)
#define UART4_TimeoutScale_BRT()        CLR_REG_BIT(UR4TOCR, UR4TOCR_SCALE_MSK)

#define UART4_SetTimeoutInterval(n)     UR4TOTL = BYTE0(n); \
                                        UR4TOTH = BYTE1(n); \
                                        UR4TOTE = BYTE2(n)

#define S4CON_S4BRT_MSK                 BIT6
#define UART4_Timer2BRT()               CLR_REG_BIT(S4CON, S4CON_S4BRT_MSK)
#define UART4_Timer4BRT()               SET_REG_BIT(S4CON, S4CON_S4BRT_MSK)

/////////////////////////////////////////////////

#define CMPCR1_CMPEN_MSK                BIT7
#define CMP_Enable()                    SET_REG_BIT(CMPCR1, CMPCR1_CMPEN_MSK)
#define CMP_Disable()                   CLR_REG_BIT(CMPCR1, CMPCR1_CMPEN_MSK)

#define CMPCR1_CMPOE_MSK                BIT1
#define CMP_EnableOutput()              SET_REG_BIT(CMPCR1, CMPCR1_CMPOE_MSK)
#define CMP_DisableOutput()             CLR_REG_BIT(CMPCR1, CMPCR1_CMPOE_MSK)

#define CMPCR1_CMPRES_MSK               BIT0
#define CMP_ReadResult()                READ_REG_BIT(CMPCR1, CMPCR1_CMPRES_MSK)

#define CMPCR2_INVO_MSK                 BIT7
#define CMP_OutputInvert()              SET_REG_BIT(CMPCR2, CMPCR2_INVO_MSK)

#define CMPCR2_DISFLT_MSK               BIT6
#define CMP_EnableAnalogFilter()        CLR_REG_BIT(CMPCR2, CMPCR2_DISFLT_MSK)
#define CMP_DisableAnalogFilter()       SET_REG_BIT(CMPCR2, CMPCR2_DISFLT_MSK)

#define CMPCR2_LCDTY_MSK                (BIT5 | BIT4 | BIT_LN)
#define CMP_SetDigitalFilter(n)         MODIFY_REG(CMPCR2, CMPCR2_LCDTY_MSK, ((n) << 0))

#define CMPEXCFG_CHYS_MSK               (BIT7 | BIT6)
#define CMP_SetHysteresis(n)            MODIFY_REG(CMPEXCFG, CMPEXCFG_CHYS_MSK, ((n) << 6))
#define CMP_DisableHysteresis()         CMP_SetHysteresis(0)
#define CMP_SetHysteresis_10mV()        CMP_SetHysteresis(1)
#define CMP_SetHysteresis_20mV()        CMP_SetHysteresis(2)
#define CMP_SetHysteresis_30mV()        CMP_SetHysteresis(3)

/////////////////////////////////////////////////

#define IAPCON_IAPEN_MSK                BIT7
#define IAP_Enable()                    SET_REG_BIT(IAP_CONTR, IAPCON_IAPEN_MSK)
#define IAP_Disable()                   CLR_REG_BIT(IAP_CONTR, IAPCON_IAPEN_MSK)

#define IAP_SetData(d)                  (IAP_DATA = (d))
#define IAP_ReadData()                  (IAP_DATA)

#define IAP_SetAddress(n)               IAP_ADDRL = BYTE0(n); \
                                        IAP_ADDRH = BYTE1(n)

#define IAP_Trigger()                   IAP_TRIG = 0x5a; \
                                        IAP_TRIG = 0xa5; \
                                        _nop_();         \
                                        _nop_();         \
                                        _nop_();         \
                                        _nop_()

#define IAP_Idle()                      IAP_CMD = 0
#define IAP_TriggerRead()               IAP_CMD = 1; IAP_Trigger()
#define IAP_TriggerProgram()            IAP_CMD = 2; IAP_Trigger()
#define IAP_TriggerErase()              IAP_CMD = 3; IAP_Trigger()

#define IAP_SetTimeBase()               IAP_TPS = ((SYSCLK) / 1000000UL)

#define IAPCON_FAIL_MSK                 BIT4
#define IAP_CheckErrorFlag()            READ_REG_BIT(IAP_CONTR, IAPCON_FAIL_MSK)
#define IAP_ClearErrorFlag()            CLR_REG_BIT(IAP_CONTR, IAPCON_FAIL_MSK)

/////////////////////////////////////////////////

#define ADCCONTR_ADCPOWER_MSK           BIT7
#define ADC_Enable()                    SET_REG_BIT(ADC_CONTR, ADCCONTR_ADCPOWER_MSK)
#define ADC_Disable()                   CLR_REG_BIT(ADC_CONTR, ADCCONTR_ADCPOWER_MSK)

#define ADC_ReadResult()                MAKEWORD(ADC_RESL, ADC_RES)

#define ADCCONTR_ADCSTART_MSK           BIT6
#define ADC_Start()                     SET_REG_BIT(ADC_CONTR, ADCCONTR_ADCSTART_MSK)

#define ADCCONTR_ADCCHS_MSK             (BIT_LN)
#define ADC_ActiveChannel(n)            MODIFY_REG(ADC_CONTR, ADCCONTR_ADCCHS_MSK, ((n) << 0))

#define ADCCONTR_ADCEPWMT_MSK           BIT4
#define ADC_EnablePWMTrig()             SET_REG_BIT(ADC_CONTR, ADCCONTR_ADCEPWMT_MSK)

#define ADCCFG_RESFMT_MSK               BIT5
#define ADC_ResultLeftAlign()           CLR_REG_BIT(ADCCFG, ADCCFG_RESFMT_MSK)
#define ADC_ResultRightAlign()          SET_REG_BIT(ADCCFG, ADCCFG_RESFMT_MSK)

#define ADCCFG_SPEED_MSK                (BIT_LN)
#define ADC_SetClockDivider(n)          MODIFY_REG(ADCCFG, ADCCFG_SPEED_MSK, ((n) << 0))

#define ADCEXCFG_ETRE_MSK               BIT5
#define ADC_EnableETR()                 SET_REG_BIT(ADCEXCFG, ADCEXCFG_ETRE_MSK)
#define ADC_DisableETR()                CLR_REG_BIT(ADCEXCFG, ADCEXCFG_ETRE_MSK)

#define ADCEXCFG_ETRP_MSK               BIT4
#define ADC_ETRRising()                 CLR_REG_BIT(ADCEXCFG, ADCEXCFG_ETRP_MSK)
#define ADC_ETRFalling()                SET_REG_BIT(ADCEXCFG, ADCEXCFG_ETRP_MSK)

#define ADCEXCFG_CVT_MSK                (BIT2 | BIT1 | BIT0)
#define ADC_SetRepeatTimes(n)           MODIFY_REG(ADCEXCFG, ADCEXCFG_CVT_MSK, ((n) << 0))

#define ADC_DisableRepeatConv()         ADC_SetRepeatTimes(0)
#define ADC_SetRepeat2Times()           ADC_SetRepeatTimes(4)
#define ADC_SetRepeat4Times()           ADC_SetRepeatTimes(5)
#define ADC_SetRepeat8Times()           ADC_SetRepeatTimes(6)
#define ADC_SetRepeat16Times()          ADC_SetRepeatTimes(7)

#define ADCTIM_CSSETUP_MSK              BIT7
#define ADCTIM_CSHOLD_MSK               (BIT6 | BIT5)
#define ADCTIM_SMPDUTY_MSK              (BIT4 | BIT_LN)
#define ADC_SetCSSetupCycles(n)         MODIFY_REG(ADCTIM, ADCTIM_CSSETUP_MSK, (((n) - 1) << 7))
#define ADC_SetCSHoldCycles(n)          MODIFY_REG(ADCTIM, ADCTIM_CSHOLD_MSK, (((n) - 1) << 5))
#define ADC_SetSampleDutyCycles(n)      MODIFY_REG(ADCTIM, ADCTIM_SMPDUTY_MSK, (((n) - 1) << 0))

/////////////////////////////////////////////////

#define SPCTL_SPEN_MSK                  BIT6
#define SPI_Enable()                    SET_REG_BIT(SPCTL, SPCTL_SPEN_MSK)
#define SPI_Disable()                   CLR_REG_BIT(SPCTL, SPCTL_SPEN_MSK)

#define SPCTL_DORD_MSK                  BIT5
#define SPI_DataLSB()                   SET_REG_BIT(SPCTL, SPCTL_DORD_MSK)
#define SPI_DataMSB()                   CLR_REG_BIT(SPCTL, SPCTL_DORD_MSK)

#define SPCTL_MSTR_MSK                  BIT4
#define SPI_MasterMode()                SET_REG_BIT(SPCTL, SPCTL_MSTR_MSK)
#define SPI_SlaveMode()                 CLR_REG_BIT(SPCTL, SPCTL_MSTR_MSK)

#define SPCTL_SSIG_MSK                  BIT7
#define SPI_IgnoreSS()                  SET_REG_BIT(SPCTL, SPCTL_SSIG_MSK)
#define SPI_UnignoreSS()                CLR_REG_BIT(SPCTL, SPCTL_SSIG_MSK)

#define SPCTL_CPOL_MSK                  BIT3
#define SPCTL_CPHA_MSK                  BIT2
#define SPIMODE                         (SPCTL_CPOL_MSK | SPCTL_CPHA_MSK)
#define SPI_SetMode0()                  MODIFY_REG(SPCTL, SPIMODE, ((0) << 2))
#define SPI_SetMode1()                  MODIFY_REG(SPCTL, SPIMODE, ((1) << 2))
#define SPI_SetMode2()                  MODIFY_REG(SPCTL, SPIMODE, ((2) << 2))
#define SPI_SetMode3()                  MODIFY_REG(SPCTL, SPIMODE, ((3) << 2))

#define SPCTL_SPR_MSK                   (BIT1 | BIT0)
#define SPI_SetClockDivider(n)          MODIFY_REG(SPCTL, SPCTL_SPR_MSK, ((n) << 0))
#define SPI_SetClockDivider2()          SPI_SetClockDivider(3)
#define SPI_SetClockDivider4()          SPI_SetClockDivider(0)
#define SPI_SetClockDivider8()          SPI_SetClockDivider(1)
#define SPI_SetClockDivider16()         SPI_SetClockDivider(2)

#define SPI_SendData(d)                 (SPDAT = (d))
#define SPI_ReadData()                  (SPDAT)

#define HSSPICFG2_IOSW_MSK              BIT6
#define SPI_SwapMosiMiso()              SET_REG_BIT(HSSPI_CFG2, HSSPICFG2_IOSW_MSK)

#define HSSPICFG2_HSSPIEN_MSK           BIT5
#define HSSPI_Enable()                  SET_REG_BIT(HSSPI_CFG2, HSSPICFG2_HSSPIEN_MSK)
#define HSSPI_Disable()                 CLR_REG_BIT(HSSPI_CFG2, HSSPICFG2_HSSPIEN_MSK)

#define HSSPICFG_SSHLD_MSK              BIT_HN
#define HSSPI_SetSSHoldTime(n)          MODIFY_REG(HSSPI_CFG, HSSPICFG_SSHLD_MSK, ((n) << 4))

#define HSSPICFG_SSSETUP_MSK            BIT_LN
#define HSSPI_SetSSSetupTime(n)         MODIFY_REG(HSSPI_CFG, HSSPICFG_SSSETUP_MSK, ((n) << 0))

#define HSSPICFG2_SSDACT_MSK            BIT_LN
#define HSSPI_SetSSDeactTime(n)         MODIFY_REG(HSSPI_CFG2, HSSPICFG2_SSDACT_MSK, ((n) << 0))

#define HSSPICFG2_FIFOEN_MSK            BIT4
#define HSSPI_EnableFIFO()              SET_REG_BIT(HSSPI_CFG2, HSSPICFG2_FIFOEN_MSK)
#define HSSPI_DisableFIFO()             CLR_REG_BIT(HSSPI_CFG2, HSSPICFG2_FIFOEN_MSK)

#define SPITOCR_ENTO_MSK                BIT7
#define SPI_EnableTimeout()             SET_REG_BIT(SPITOCR, SPITOCR_ENTO_MSK)
#define SPI_DisableTimeout()            CLR_REG_BIT(SPITOCR, SPITOCR_ENTO_MSK)

#define SPITOCR_SCALE_MSK               BIT5
#define SPI_TimeoutScale_SYSCLK()       SET_REG_BIT(SPITOCR, SPITOCR_SCALE_MSK)
#define SPI_TimeoutScale_1us()          CLR_REG_BIT(SPITOCR, SPITOCR_SCALE_MSK)

#define SPI_SetTimeoutInterval(n)       SPITOTL = BYTE0(n); \
                                        SPITOTH = BYTE1(n); \
                                        SPITOTE = BYTE2(n)

/////////////////////////////////////////////////

#define I2CCFG_ENI2C_MSK                BIT7
#define I2C_Enable()                    SET_REG_BIT(I2CCFG, I2CCFG_ENI2C_MSK)
#define I2C_Disable()                   CLR_REG_BIT(I2CCFG, I2CCFG_ENI2C_MSK)

#define I2CCFG_MSSL_MSK                 BIT6
#define I2C_MasterMode()                SET_REG_BIT(I2CCFG, I2CCFG_MSSL_MSK)
#define I2C_SlaveMode()                 CLR_REG_BIT(I2CCFG, I2CCFG_MSSL_MSK)

#define I2CCFG_SPEED_MSK                (BIT5 | BIT4 |BIT_LN)
#define I2C_SetClockDivider(n)          MODIFY_REG(I2CCFG, I2CCFG_SPEED_MSK, ((n) << 0))

#define I2CMSCR_MSCMD_MSK               (BIT_LN)
#define I2C_SetMasterCommand(n)         MODIFY_REG(I2CMSCR, I2CMSCR_MSCMD_MSK, ((n) << 0))

#define I2CCMD_IDLE                     0
#define I2CCMD_START                    1
#define I2CCMD_SENDDATA                 2
#define I2CCMD_RECVACK                  3
#define I2CCMD_RECVDATA                 4
#define I2CCMD_SENDACK                  5
#define I2CCMD_STOP                     6
#define I2CCMD_START_SENDDATA_RECVACK   9
#define I2CCMD_SENDDATA_RECVACK         10
#define I2CCMD_RECVDATA_SENDACK         11
#define I2CCMD_RECVDATA_SENDNAK         12
#define I2C_Idle()                      I2C_SetMasterCommand(I2CCMD_IDLE)
#define I2C_Start()                     I2C_SetMasterCommand(I2CCMD_START)
#define I2C_SendData()                  I2C_SetMasterCommand(I2CCMD_SENDDATA)
#define I2C_RecvACK()                   I2C_SetMasterCommand(I2CCMD_RECVACK)
#define I2C_RecvData()                  I2C_SetMasterCommand(I2CCMD_RECVDATA)
#define I2C_SendACK()                   I2C_SetMasterCommand(I2CCMD_SENDACK)
#define I2C_Stop()                      I2C_SetMasterCommand(I2CCMD_STOP)
#define I2C_StartSendDataRecvACK()      I2C_SetMasterCommand(I2CCMD_START_SENDDATA_RECVACK)
#define I2C_SendDataRecvACK()           I2C_SetMasterCommand(I2CCMD_SENDDATA_RECVACK)
#define I2C_RecvDataSendACK()           I2C_SetMasterCommand(I2CCMD_RECVDATA_SENDACK)
#define I2C_RecvDataSendNAK()           I2C_SetMasterCommand(I2CCMD_RECVDATA_SENDNAK)

#define I2CMSST_BUSY_MSK                BIT7
#define I2C_CheckMasterBusy()           READ_REG_BIT(I2CMSST, I2CMSST_BUSY_MSK)

#define I2CMSST_MSIF_MSK                BIT6
#define I2C_CheckMasterFlag()           READ_REG_BIT(I2CMSST, I2CMSST_MSIF_MSK)
#define I2C_ClearMasterFlag()           CLR_REG_BIT(I2CMSST, I2CMSST_MSIF_MSK)

#define I2C_WriteData(d)                (I2CTXD = (d))
#define I2C_ReadData()                  (I2CRXD)

#define I2CMSST_ACKI_MSK                BIT1
#define I2CMSST_ACKO_MSK                BIT0
#define I2C_MasterSetACK()              CLR_REG_BIT(I2CMSST, I2CMSST_ACKO_MSK)
#define I2C_MasterSetNAK()              SET_REG_BIT(I2CMSST, I2CMSST_ACKO_MSK)
#define I2C_MasterReadACK()             READ_REG_BIT(I2CMSST, I2CMSST_ACKI_MSK)

#define I2CSLCR_SLRST_MSK               BIT0
#define I2C_SlaveReset()                SET_REG_BIT(I2CSLCR, I2CSLCR_SLRST_MSK)

#define I2CSLST_BUSY_MSK                BIT7
#define I2C_CheckSlaveBusy()            READ_REG_BIT(I2CSLST, I2CSLST_BUSY_MSK)

#define I2CSLST_ACKI_MSK                BIT1
#define I2CSLST_ACKO_MSK                BIT0
#define I2C_SlaveSetACK()               CLR_REG_BIT(I2CSLST, I2CSLST_ACKO_MSK)
#define I2C_SlaveSetNAK()               SET_REG_BIT(I2CSLST, I2CSLST_ACKO_MSK)
#define I2C_SlaveReadACK()              READ_REG_BIT(I2CSLST, I2CSLST_ACKI_MSK)

#define I2CSLADR_SLADR_MSK              (BIT_HN | BIT3 | BIT2 | BIT1)
#define I2C_SetSlaveAddress(n)          I2CSLADR = ((n) << 1)

#define I2CSLADR_MA_MSK                 (BIT0)
#define I2C_SetSlaveBroadcast()         SET_REG_BIT(I2CSLADR, I2CSLADR_MA_MSK)

#define I2CTOCR_ENTO_MSK                BIT7
#define I2C_EnableTimeout()             SET_REG_BIT(I2CTOCR, I2CTOCR_ENTO_MSK)
#define I2C_DisableTimeout()            CLR_REG_BIT(I2CTOCR, I2CTOCR_ENTO_MSK)

#define I2CTOCR_SCALE_MSK               BIT5
#define I2C_TimeoutScale_SYSCLK()       SET_REG_BIT(I2CTOCR, I2CTOCR_SCALE_MSK)
#define I2C_TimeoutScale_1us()          CLR_REG_BIT(I2CTOCR, I2CTOCR_SCALE_MSK)

#define I2C_SetTimeoutInterval(n)       I2CTOTL = BYTE0(n); \
                                        I2CTOTH = BYTE1(n); \
                                        I2CTOTE = BYTE2(n)

/////////////////////////////////////////////////

#define RTCCR_RUNRTC_MSK                BIT0
#define RTC_Run()                       SET_REG_BIT(RTCCR, RTCCR_RUNRTC_MSK)
#define RTC_Stop()                      CLR_REG_BIT(RTCCR, RTCCR_RUNRTC_MSK)

#define RTCCFG_RTCCKS_MSK               BIT1
#define RTC_CLK_X32K()                  CLR_REG_BIT(RTCCFG, RTCCFG_RTCCKS_MSK)
#define RTC_CLK_LIRC()                  SET_REG_BIT(RTCCFG, RTCCFG_RTCCKS_MSK)

#define RTCCFG_SETRTC_MSK               BIT0
#define RTC_SyncInitial()               SET_REG_BIT(RTCCFG, RTCCFG_SETRTC_MSK)
#define RTC_IsSyncing()                 READ_REG_BIT(RTCCFG, RTCCFG_SETRTC_MSK)

#define RTC_SetAlarmHour(n)             (ALAHOUR = (n))
#define RTC_SetAlarmMinute(n)           (ALAMIN = (n))
#define RTC_SetAlarmSecond(n)           (ALASEC = (n))
#define RTC_SetAlarmSSecond(n)          (ALASSEC = (n))

#define RTC_SetYear(n)                  (INIYEAR = (n))
#define RTC_SetMonth(n)                 (INIMONTH = (n))
#define RTC_SetDay(n)                   (INIDAY = (n))
#define RTC_SetHour(n)                  (INIHOUR = (n))
#define RTC_SetMinute(n)                (INIMIN = (n))
#define RTC_SetSecond(n)                (INISEC = (n))
#define RTC_SetSSecond(n)               (INISSEC = (n))

#define RTC_ReadYear()                  (RTCYEAR)
#define RTC_ReadMonth()                 (RTCMONTH)
#define RTC_ReadDay()                   (RTCDAY)
#define RTC_ReadHour()                  (RTCHOUR)
#define RTC_ReadMinute()                (RTCMIN)
#define RTC_ReadSecond()                (RTCSEC)
#define RTC_ReadSSecond()               (RTCSSEC)

/////////////////////////////////////////////////

#define LCMIFCR_EN_MSK                  BIT7
#define LCM_Enable()                    SET_REG_BIT(LCMIFCR, LCMIFCR_EN_MSK)
#define LCM_Disable()                   CLR_REG_BIT(LCMIFCR, LCMIFCR_EN_MSK)

#define LCMIFCFG_BW_MSK                 BIT1
#define LCM_SetBitWidth_8B()            CLR_REG_BIT(LCMIFCFG, LCMIFCFG_BW_MSK)
#define LCM_SetBitWidth_16B()           SET_REG_BIT(LCMIFCFG, LCMIFCFG_BW_MSK)

#define LCMIFCFG_MODE_MSK               BIT0
#define LCM_SetMode_i8080()             CLR_REG_BIT(LCMIFCFG, LCMIFCFG_MODE_MSK)
#define LCM_SetMode_M6800()             SET_REG_BIT(LCMIFCFG, LCMIFCFG_MODE_MSK)

#define LCMIFCFG2_SETUPT_MSK            (BIT4 | BIT3 | BIT2)
#define LCMIFCFG2_HOLDT_MSK             (BIT1 | BIT0)
#define LCM_SetSetupTime(n)             MODIFY_REG(LCMIFCFG2, LCMIFCFG2_SETUPT_MSK, ((n) << 2))
#define LCM_SetHoldTime(n)              MODIFY_REG(LCMIFCFG2, LCMIFCFG2_HOLDT_MSK, ((n) << 0))

#define LCMIFCR_ENDIAN_MSK              BIT4
#define LCM_SetDataBigEndian()          CLR_REG_BIT(LCMIFCR, LCMIFCR_ENDIAN_MSK)
#define LCM_SetDataLittleEndian()       SET_REG_BIT(LCMIFCR, LCMIFCR_ENDIAN_MSK)

#define LCMIFCR_CMD_MSK                 (BIT2 | BIT1 | BIT0)
#define LCM_SetCommand(n)               MODIFY_REG(LCMIFCR, LCMIFCR_CMD_MSK, ((n) << 0))

#define LCMCMD_IDLE                     0
#define LCMCMD_SENDCMD                  4
#define LCMCMD_SENDDATA                 5
#define LCMCMD_READSTAT                 6
#define LCMCMD_READDATA                 7
#define LCM_Idle()                      LCM_SetCommand(LCMCMD_IDLE)
#define LCM_TrigSendCommand()           LCM_SetCommand(LCMCMD_SENDCMD)
#define LCM_TrigSendData()              LCM_SetCommand(LCMCMD_SENDDATA)
#define LCM_TrigReadStatus()            LCM_SetCommand(LCMCMD_READSTAT)
#define LCM_TrigReadData()              LCM_SetCommand(LCMCMD_READDATA)

#define LCM_WriteData_8B(d)             WRITE_REG(LCMIFDATL, (d))
#define LCM_ReadData_8B()               (LCMIFDATL)

#define LCM_WriteData_16B(d)            (LCMIFDATH = HIBYTE(d), LCMIFDATL = LOBYTE(d))
#define LCM_ReadData_16B()              MAKEWORD(LCMIFDATL, LCMIFDATH)

#define LCM_SetClockDivider(n)          WRITE_REG(LCMIFPSCR, (n))

/////////////////////////////////////////////////

#define TFPU_CLK_SYSCLK()               WRITE_REG(DMAIR, (0x3e))
#define TFPU_CLK_HSIOCK()               WRITE_REG(DMAIR, (0x3f))

/////////////////////////////////////////////////

#define DMAUR1TCFG_UR1TPTY_MSK          (BIT1 | BIT0)
#define DMAUR2TCFG_UR2TPTY_MSK          (BIT1 | BIT0)
#define DMAUR3TCFG_UR3TPTY_MSK          (BIT1 | BIT0)
#define DMAUR4TCFG_UR4TPTY_MSK          (BIT1 | BIT0)
#define DMA_UART1_SetTxBusPriority(n)   MODIFY_REG(DMA_UR1T_CFG,  DMAUR1TCFG_UR1TPTY_MSK, ((n) << 0))
#define DMA_UART2_SetTxBusPriority(n)   MODIFY_REG(DMA_UR2T_CFG,  DMAUR2TCFG_UR2TPTY_MSK, ((n) << 0))
#define DMA_UART3_SetTxBusPriority(n)   MODIFY_REG(DMA_UR3T_CFG,  DMAUR3TCFG_UR3TPTY_MSK, ((n) << 0))
#define DMA_UART4_SetTxBusPriority(n)   MODIFY_REG(DMA_UR4T_CFG,  DMAUR4TCFG_UR4TPTY_MSK, ((n) << 0))

#define DMAUR1RCFG_UR1RPTY_MSK          (BIT1 | BIT0)
#define DMAUR2RCFG_UR2RPTY_MSK          (BIT1 | BIT0)
#define DMAUR3RCFG_UR3RPTY_MSK          (BIT1 | BIT0)
#define DMAUR4RCFG_UR4RPTY_MSK          (BIT1 | BIT0)
#define DMA_UART1_SetRxBusPriority(n)   MODIFY_REG(DMA_UR1R_CFG,  DMAUR1RCFG_UR1RPTY_MSK, ((n) << 0))
#define DMA_UART2_SetRxBusPriority(n)   MODIFY_REG(DMA_UR2R_CFG,  DMAUR2RCFG_UR2RPTY_MSK, ((n) << 0))
#define DMA_UART3_SetRxBusPriority(n)   MODIFY_REG(DMA_UR3R_CFG,  DMAUR3RCFG_UR3RPTY_MSK, ((n) << 0))
#define DMA_UART4_SetRxBusPriority(n)   MODIFY_REG(DMA_UR4R_CFG,  DMAUR4RCFG_UR4RPTY_MSK, ((n) << 0))

#define DMAUR1TCR_ENUR1T_MSK            BIT7
#define DMAUR2TCR_ENUR2T_MSK            BIT7
#define DMAUR3TCR_ENUR3T_MSK            BIT7
#define DMAUR4TCR_ENUR4T_MSK            BIT7
#define DMA_UART1_EnableTx()            SET_REG_BIT(DMA_UR1T_CR, DMAUR1TCR_ENUR1T_MSK)
#define DMA_UART2_EnableTx()            SET_REG_BIT(DMA_UR2T_CR, DMAUR2TCR_ENUR2T_MSK)
#define DMA_UART3_EnableTx()            SET_REG_BIT(DMA_UR3T_CR, DMAUR3TCR_ENUR3T_MSK)
#define DMA_UART4_EnableTx()            SET_REG_BIT(DMA_UR4T_CR, DMAUR4TCR_ENUR4T_MSK)
#define DMA_UART1_DisableTx()           CLR_REG_BIT(DMA_UR1T_CR, DMAUR1TCR_ENUR1T_MSK)
#define DMA_UART2_DisableTx()           CLR_REG_BIT(DMA_UR2T_CR, DMAUR2TCR_ENUR2T_MSK)
#define DMA_UART3_DisableTx()           CLR_REG_BIT(DMA_UR3T_CR, DMAUR3TCR_ENUR3T_MSK)
#define DMA_UART4_DisableTx()           CLR_REG_BIT(DMA_UR4T_CR, DMAUR4TCR_ENUR4T_MSK)

#define DMAUR1RCR_ENUR1R_MSK            BIT7
#define DMAUR2RCR_ENUR2R_MSK            BIT7
#define DMAUR3RCR_ENUR3R_MSK            BIT7
#define DMAUR4RCR_ENUR4R_MSK            BIT7
#define DMA_UART1_EnableRx()            SET_REG_BIT(DMA_UR1R_CR, DMAUR1RCR_ENUR1R_MSK)
#define DMA_UART2_EnableRx()            SET_REG_BIT(DMA_UR2R_CR, DMAUR2RCR_ENUR2R_MSK)
#define DMA_UART3_EnableRx()            SET_REG_BIT(DMA_UR3R_CR, DMAUR3RCR_ENUR3R_MSK)
#define DMA_UART4_EnableRx()            SET_REG_BIT(DMA_UR4R_CR, DMAUR4RCR_ENUR4R_MSK)
#define DMA_UART1_DisableRx()           CLR_REG_BIT(DMA_UR1R_CR, DMAUR1RCR_ENUR1R_MSK)
#define DMA_UART2_DisableRx()           CLR_REG_BIT(DMA_UR2R_CR, DMAUR2RCR_ENUR2R_MSK)
#define DMA_UART3_DisableRx()           CLR_REG_BIT(DMA_UR3R_CR, DMAUR3RCR_ENUR3R_MSK)
#define DMA_UART4_DisableRx()           CLR_REG_BIT(DMA_UR4R_CR, DMAUR4RCR_ENUR4R_MSK)

#define DMAUR1TCR_TRIG_MSK              BIT6
#define DMAUR2TCR_TRIG_MSK              BIT6
#define DMAUR3TCR_TRIG_MSK              BIT6
#define DMAUR4TCR_TRIG_MSK              BIT6
#define DMA_UART1_TriggerTx()           SET_REG_BIT(DMA_UR1T_CR, DMAUR1TCR_TRIG_MSK)
#define DMA_UART2_TriggerTx()           SET_REG_BIT(DMA_UR2T_CR, DMAUR2TCR_TRIG_MSK)
#define DMA_UART3_TriggerTx()           SET_REG_BIT(DMA_UR3T_CR, DMAUR3TCR_TRIG_MSK)
#define DMA_UART4_TriggerTx()           SET_REG_BIT(DMA_UR4T_CR, DMAUR4TCR_TRIG_MSK)

#define DMAUR1RCR_TRIG_MSK              BIT5
#define DMAUR2RCR_TRIG_MSK              BIT5
#define DMAUR3RCR_TRIG_MSK              BIT5
#define DMAUR4RCR_TRIG_MSK              BIT5
#define DMA_UART1_TriggerRx()           SET_REG_BIT(DMA_UR1R_CR, DMAUR1RCR_TRIG_MSK)
#define DMA_UART2_TriggerRx()           SET_REG_BIT(DMA_UR2R_CR, DMAUR2RCR_TRIG_MSK)
#define DMA_UART3_TriggerRx()           SET_REG_BIT(DMA_UR3R_CR, DMAUR3RCR_TRIG_MSK)
#define DMA_UART4_TriggerRx()           SET_REG_BIT(DMA_UR4R_CR, DMAUR4RCR_TRIG_MSK)

#define DMAUR1RCR_CLRFIFO_MSK           BIT0
#define DMAUR2RCR_CLRFIFO_MSK           BIT0
#define DMAUR3RCR_CLRFIFO_MSK           BIT0
#define DMAUR4RCR_CLRFIFO_MSK           BIT0
#define DMA_UART1_ClearFIFO()           SET_REG_BIT(DMA_UR1R_CR, DMAUR1RCR_CLRFIFO_MSK)
#define DMA_UART2_ClearFIFO()           SET_REG_BIT(DMA_UR2R_CR, DMAUR2RCR_CLRFIFO_MSK)
#define DMA_UART3_ClearFIFO()           SET_REG_BIT(DMA_UR3R_CR, DMAUR3RCR_CLRFIFO_MSK)
#define DMA_UART4_ClearFIFO()           SET_REG_BIT(DMA_UR4R_CR, DMAUR4RCR_CLRFIFO_MSK)

#define DMAUR1TSTA_TXOVW_MSK            BIT2
#define DMAUR2TSTA_TXOVW_MSK            BIT2
#define DMAUR3TSTA_TXOVW_MSK            BIT2
#define DMAUR4TSTA_TXOVW_MSK            BIT2
#define DMA_UART1_CheckOverWriteFlag()  READ_REG_BIT(DMA_UR1T_STA,  DMAUR1TSTA_TXOVW_MSK)
#define DMA_UART2_CheckOverWriteFlag()  READ_REG_BIT(DMA_UR2T_STA,  DMAUR2TSTA_TXOVW_MSK)
#define DMA_UART3_CheckOverWriteFlag()  READ_REG_BIT(DMA_UR3T_STA,  DMAUR3TSTA_TXOVW_MSK)
#define DMA_UART4_CheckOverWriteFlag()  READ_REG_BIT(DMA_UR4T_STA,  DMAUR4TSTA_TXOVW_MSK)
#define DMA_UART1_ClearOverWriteFlag()  CLR_REG_BIT(DMA_UR1T_STA,   DMAUR1TSTA_TXOVW_MSK)
#define DMA_UART2_ClearOverWriteFlag()  CLR_REG_BIT(DMA_UR2T_STA,   DMAUR2TSTA_TXOVW_MSK)
#define DMA_UART3_ClearOverWriteFlag()  CLR_REG_BIT(DMA_UR3T_STA,   DMAUR3TSTA_TXOVW_MSK)
#define DMA_UART4_ClearOverWriteFlag()  CLR_REG_BIT(DMA_UR4T_STA,   DMAUR4TSTA_TXOVW_MSK)

#define DMAUR1RSTA_RXLOSS_MSK           BIT1
#define DMAUR2RSTA_RXLOSS_MSK           BIT1
#define DMAUR3RSTA_RXLOSS_MSK           BIT1
#define DMAUR4RSTA_RXLOSS_MSK           BIT1
#define DMA_UART1_CheckRxLossFlag()     READ_REG_BIT(DMA_UR1R_STA,  DMAUR1RSTA_RXLOSS_MSK)
#define DMA_UART2_CheckRxLossFlag()     READ_REG_BIT(DMA_UR2R_STA,  DMAUR2RSTA_RXLOSS_MSK)
#define DMA_UART3_CheckRxLossFlag()     READ_REG_BIT(DMA_UR3R_STA,  DMAUR3RSTA_RXLOSS_MSK)
#define DMA_UART4_CheckRxLossFlag()     READ_REG_BIT(DMA_UR4R_STA,  DMAUR4RSTA_RXLOSS_MSK)
#define DMA_UART1_ClearRxLossFlag()     CLR_REG_BIT(DMA_UR1R_STA,   DMAUR1RSTA_RXLOSS_MSK)
#define DMA_UART2_ClearRxLossFlag()     CLR_REG_BIT(DMA_UR2R_STA,   DMAUR2RSTA_RXLOSS_MSK)
#define DMA_UART3_ClearRxLossFlag()     CLR_REG_BIT(DMA_UR3R_STA,   DMAUR3RSTA_RXLOSS_MSK)
#define DMA_UART4_ClearRxLossFlag()     CLR_REG_BIT(DMA_UR4R_STA,   DMAUR4RSTA_RXLOSS_MSK)

#define DMA_UART1_SetTxAmount(d)        (DMA_UR1T_AMT = LOBYTE(d))
#define DMA_UART2_SetTxAmount(d)        (DMA_UR2T_AMT = LOBYTE(d))
#define DMA_UART3_SetTxAmount(d)        (DMA_UR3T_AMT = LOBYTE(d))
#define DMA_UART4_SetTxAmount(d)        (DMA_UR4T_AMT = LOBYTE(d))

#define DMA_UART1_SetRxAmount(d)        (DMA_UR1R_AMT = LOBYTE(d))
#define DMA_UART2_SetRxAmount(d)        (DMA_UR2R_AMT = LOBYTE(d))
#define DMA_UART3_SetRxAmount(d)        (DMA_UR3R_AMT = LOBYTE(d))
#define DMA_UART4_SetRxAmount(d)        (DMA_UR4R_AMT = LOBYTE(d))

#define DMA_UART1_ReadTxDone()          MAKEWORD(DMA_UR1T_DONE, 0)
#define DMA_UART2_ReadTxDone()          MAKEWORD(DMA_UR2T_DONE, 0)
#define DMA_UART3_ReadTxDone()          MAKEWORD(DMA_UR3T_DONE, 0)
#define DMA_UART4_ReadTxDone()          MAKEWORD(DMA_UR4T_DONE, 0)

#define DMA_UART1_ReadRxDone()          MAKEWORD(DMA_UR1R_DONE, 0)
#define DMA_UART2_ReadRxDone()          MAKEWORD(DMA_UR2R_DONE, 0)
#define DMA_UART3_ReadRxDone()          MAKEWORD(DMA_UR3R_DONE, 0)
#define DMA_UART4_ReadRxDone()          MAKEWORD(DMA_UR4R_DONE, 0)

#define DMA_UART1_SetTxAddress(d)       (DMA_UR1T_TXAH = HIBYTE(d), DMA_UR1T_TXAL = LOBYTE(d))
#define DMA_UART2_SetTxAddress(d)       (DMA_UR2T_TXAH = HIBYTE(d), DMA_UR2T_TXAL = LOBYTE(d))
#define DMA_UART3_SetTxAddress(d)       (DMA_UR3T_TXAH = HIBYTE(d), DMA_UR3T_TXAL = LOBYTE(d))
#define DMA_UART4_SetTxAddress(d)       (DMA_UR4T_TXAH = HIBYTE(d), DMA_UR4T_TXAL = LOBYTE(d))

#define DMA_UART1_SetRxAddress(d)       (DMA_UR1R_RXAH = HIBYTE(d), DMA_UR1R_RXAL = LOBYTE(d))
#define DMA_UART2_SetRxAddress(d)       (DMA_UR2R_RXAH = HIBYTE(d), DMA_UR2R_RXAL = LOBYTE(d))
#define DMA_UART3_SetRxAddress(d)       (DMA_UR3R_RXAH = HIBYTE(d), DMA_UR3R_RXAL = LOBYTE(d))
#define DMA_UART4_SetRxAddress(d)       (DMA_UR4R_RXAH = HIBYTE(d), DMA_UR4R_RXAL = LOBYTE(d))

/////////////////////////////////////////////////

#define DMAADCCFG_ADCPTY_MSK            (BIT1 | BIT0)
#define DMA_ADC_SetBusPriority(n)       MODIFY_REG(DMA_ADC_CFG,  DMAADCCFG_ADCPTY_MSK, ((n) << 0))

#define DMAADCCR_ENADC_MSK              BIT7
#define DMA_ADC_Enable()                SET_REG_BIT(DMA_ADC_CR, DMAADCCR_ENADC_MSK)
#define DMA_ADC_Disable()               CLR_REG_BIT(DMA_ADC_CR, DMAADCCR_ENADC_MSK)

#define DMAADCCR_TRIG_MSK               BIT6
#define DMA_ADC_Trigger()               SET_REG_BIT(DMA_ADC_CR, DMAADCCR_TRIG_MSK)

#define DMA_ADC_SetAmount(d)            (DMA_ADC_AMT = LOBYTE(d))
#define DMA_ADC_ReadDone()              MAKEWORD(DMA_ADC_DONE, 0)
#define DMA_ADC_SetAddress(d)           (DMA_ADC_RXAH = HIBYTE(d), DMA_ADC_RXAL = LOBYTE(d))
#define DMA_ADC_SetChannels(d)          (DMA_ADC_CHSW1 = HIBYTE(d), DMA_ADC_CHSW0 = LOBYTE(d))

#define DMAADCCFG2_CVTIMES_MSK          (BIT_LN)
#define DAM_ADC_SetRepeatTimes(n)       MODIFY_REG(DMA_ADC_CFG2,  DMAADCCFG2_CVTIMES_MSK, ((n) << 0))
#define DMA_ADC_DisableRepeatConv()     DAM_ADC_SetRepeatTimes(0)
#define DMA_ADC_SetRepeat2Times()       DAM_ADC_SetRepeatTimes(8)
#define DMA_ADC_SetRepeat4Times()       DAM_ADC_SetRepeatTimes(9)
#define DMA_ADC_SetRepeat8Times()       DAM_ADC_SetRepeatTimes(10)
#define DMA_ADC_SetRepeat16Times()      DAM_ADC_SetRepeatTimes(11)
#define DMA_ADC_SetRepeat32Times()      DAM_ADC_SetRepeatTimes(12)
#define DMA_ADC_SetRepeat64Times()      DAM_ADC_SetRepeatTimes(13)
#define DMA_ADC_SetRepeat128Times()     DAM_ADC_SetRepeatTimes(14)
#define DMA_ADC_SetRepeat256Times()     DAM_ADC_SetRepeatTimes(15)

/////////////////////////////////////////////////

#define DMASPICFG_ACTTX_MSK             BIT6
#define DMASPICFG_ACTRX_MSK             BIT5
#define DMA_SPI_EnableTx()              SET_REG_BIT(DMA_SPI_CFG, DMASPICFG_ACTTX_MSK)
#define DMA_SPI_DisableTx()             CLR_REG_BIT(DMA_SPI_CFG, DMASPICFG_ACTTX_MSK)
#define DMA_SPI_EnableRx()              SET_REG_BIT(DMA_SPI_CFG, DMASPICFG_ACTRX_MSK)
#define DMA_SPI_DisableRx()             CLR_REG_BIT(DMA_SPI_CFG, DMASPICFG_ACTRX_MSK)

#define DMASPICFG_SPIPTY_MSK            (BIT1 | BIT0)
#define DMA_SPI_SetBusPriority(n)       MODIFY_REG(DMA_SPI_CFG,  DMASPICFG_SPIPTY_MSK, ((n) << 0))

#define DMASPICFG2_WRPSS_MSK            BIT2
#define DMA_SPI_AutoSS()                SET_REG_BIT(DMA_SPI_CFG2, DMASPICFG2_WRPSS_MSK)
#define DMA_SPI_ManualSS()              CLR_REG_BIT(DMA_SPI_CFG2, DMASPICFG2_WRPSS_MSK)

#define DMASPICFG2_SSS_MSK              (BIT1 | BIT0)
#define DMA_SPI_SetAutoSSPort(n)        MODIFY_REG(DMA_SPI_CFG2,  DMASPICFG2_SSS_MSK, ((n) << 0))
#define DMA_SPI_SetAutoSSP54()          DMA_SPI_SetAutoSSPort(0)
#define DMA_SPI_SetAutoSSP22()          DMA_SPI_SetAutoSSPort(1)
#define DMA_SPI_SetAutoSSP54_2()        DMA_SPI_SetAutoSSPort(2)
#define DMA_SPI_SetAutoSSP35()          DMA_SPI_SetAutoSSPort(3)

#define DMASPICR_ENSPI_MSK              BIT7
#define DMA_SPI_Enable()                SET_REG_BIT(DMA_SPI_CR, DMASPICR_ENSPI_MSK)
#define DMA_SPI_Disable()               CLR_REG_BIT(DMA_SPI_CR, DMASPICR_ENSPI_MSK)

#define DMASPICR_TRIGM_MSK              BIT6
#define DMASPICR_TRIGS_MSK              BIT5
#define DMA_SPI_MasterTrigger()         SET_REG_BIT(DMA_SPI_CR, DMASPICR_TRIGM_MSK)
#define DMA_SPI_SlaveTrigger()          SET_REG_BIT(DMA_SPI_CR, DMASPICR_TRIGS_MSK)

#define DMASPICR_CLRFIFO_MSK            BIT0
#define DMA_SPI_ClearFIFO()             SET_REG_BIT(DMA_SPI_CR, DMASPICR_CLRFIFO_MSK)

#define DMASPISTA_TXOVW_MSK             BIT2
#define DMASPISTA_RXLOSS_MSK            BIT1
#define DMA_SPI_CheckOverWriteFlag()    READ_REG_BIT(DMA_SPI_STA,  DMASPISTA_TXOVW_MSK)
#define DMA_SPI_ClearOverWriteFlag()    CLR_REG_BIT(DMA_SPI_STA,   DMASPISTA_TXOVW_MSK)
#define DMA_SPI_CheckRxLossFlag()       READ_REG_BIT(DMA_SPI_STA,  DMASPISTA_RXLOSS_MSK)
#define DMA_SPI_ClearRxLossFlag()       CLR_REG_BIT(DMA_SPI_STA,   DMASPISTA_RXLOSS_MSK)

#define DMA_SPI_SetAmount(d)            (DMA_SPI_AMT = LOBYTE(d))
#define DMA_SPI_ReadDone()              MAKEWORD(DMA_SPI_DONE, 0)
#define DMA_SPI_SetTxAddress(d)         (DMA_SPI_TXAH = HIBYTE(d), DMA_SPI_TXAL = LOBYTE(d))
#define DMA_SPI_SetRxAddress(d)         (DMA_SPI_RXAH = HIBYTE(d), DMA_SPI_RXAL = LOBYTE(d))

/////////////////////////////////////////////////

#define DMALCMCFG_LCMPTY_MSK            (BIT1 | BIT0)
#define DMA_LCM_SetBusPriority(n)       MODIFY_REG(DMA_LCM_CFG,  DMALCMCFG_LCMPTY_MSK, ((n) << 0))

#define DMALCMCR_ENLCM_MSK              BIT7
#define DMA_LCM_Enable()                SET_REG_BIT(DMA_LCM_CR, DMALCMCR_ENLCM_MSK)
#define DMA_LCM_Disable()               CLR_REG_BIT(DMA_LCM_CR, DMALCMCR_ENLCM_MSK)

#define DMALCMCR_TRIGWC_MSK             BIT6
#define DMALCMCR_TRIGWD_MSK             BIT5
#define DMALCMCR_TRIGRC_MSK             BIT4
#define DMALCMCR_TRIGRD_MSK             BIT3
#define DMA_LCM_TriggerWriteCommand()   SET_REG_BIT(DMA_LCM_CR, DMALCMCR_TRIGWC_MSK)
#define DMA_LCM_TriggerWriteData()      SET_REG_BIT(DMA_LCM_CR, DMALCMCR_TRIGWD_MSK)
#define DMA_LCM_TriggerReadStatus()     SET_REG_BIT(DMA_LCM_CR, DMALCMCR_TRIGRC_MSK)
#define DMA_LCM_TriggerReadData()       SET_REG_BIT(DMA_LCM_CR, DMALCMCR_TRIGRD_MSK)

#define DMALCMSTA_TXOVW_MSK             BIT1
#define DMA_LCM_CheckOverWriteFlag()    READ_REG_BIT(DMA_LCM_STA,  DMALCMSTA_TXOVW_MSK)
#define DMA_LCM_ClearOverWriteFlag()    CLR_REG_BIT(DMA_LCM_STA,   DMALCMSTA_TXOVW_MSK)

#define DMA_LCM_SetAmount(d)            (DMA_LCM_AMT = LOBYTE(d))
#define DMA_LCM_ReadDone()              MAKEWORD(DMA_LCM_DONE, 0)
#define DMA_LCM_SetTxAddress(d)         (DMA_LCM_TXAH = HIBYTE(d), DMA_LCM_TXAL = LOBYTE(d))
#define DMA_LCM_SetRxAddress(d)         (DMA_LCM_RXAH = HIBYTE(d), DMA_LCM_RXAL = LOBYTE(d))

/////////////////////////////////////////////////

#define RSTCFG_P47RST_MSK               BIT4
#define RST_EnableResetPin()            SET_REG_BIT(RSTCFG, RSTCFG_P47RST_MSK)
#define RST_ResetPinAsGPIO()            CLR_REG_BIT(RSTCFG, RSTCFG_P47RST_MSK)

#define RSTCFG_ENLVR_MSK                BIT6
#define LVR_EnableLVR()                 SET_REG_BIT(RSTCFG, RSTCFG_ENLVR_MSK)
#define LVR_DisableLVR()                CLR_REG_BIT(RSTCFG, RSTCFG_ENLVR_MSK)

#define RSTCFG_LVDS_MSK                 (BIT1 | BIT0)
#define LVR_SetLVDS(n)                  MODIFY_REG(RSTCFG,  RSTCFG_LVDS_MSK, ((n) << 0))
#define LVR_SetLVDLevelV2p0()           LVR_SetLVDS(0)
#define LVR_SetLVDLevelV2p4()           LVR_SetLVDS(1)
#define LVR_SetLVDLevelV2p7()           LVR_SetLVDS(2)
#define LVR_SetLVDLevelV3p0()           LVR_SetLVDS(3)

/////////////////////////////////////////////////

#define PWMAENO_ENO1P_MSK               BIT0
#define PWMAENO_ENO1N_MSK               BIT1
#define PWMAENO_ENO2P_MSK               BIT2
#define PWMAENO_ENO2N_MSK               BIT3
#define PWMAENO_ENO3P_MSK               BIT4
#define PWMAENO_ENO3N_MSK               BIT5
#define PWMAENO_ENO4P_MSK               BIT6
#define PWMAENO_ENO4N_MSK               BIT7
#define PWMA_EnablePWM1POutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO1P_MSK)
#define PWMA_DisablePWM1POutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO1P_MSK)
#define PWMA_EnablePWM1NOutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO1N_MSK)
#define PWMA_DisablePWM1NOutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO1N_MSK)
#define PWMA_EnablePWM2POutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO2P_MSK)
#define PWMA_DisablePWM2POutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO2P_MSK)
#define PWMA_EnablePWM2NOutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO2N_MSK)
#define PWMA_DisablePWM2NOutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO2N_MSK)
#define PWMA_EnablePWM3POutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO3P_MSK)
#define PWMA_DisablePWM3POutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO3P_MSK)
#define PWMA_EnablePWM3NOutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO3N_MSK)
#define PWMA_DisablePWM3NOutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO3N_MSK)
#define PWMA_EnablePWM4POutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO4P_MSK)
#define PWMA_DisablePWM4POutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO4P_MSK)
#define PWMA_EnablePWM4NOutput()        SET_REG_BIT(PWMA_ENO, PWMAENO_ENO4N_MSK)
#define PWMA_DisablePWM4NOutput()       CLR_REG_BIT(PWMA_ENO, PWMAENO_ENO4N_MSK)

#define PWMAIOAUX_AUX1P_MSK             BIT0
#define PWMAIOAUX_AUX1N_MSK             BIT1
#define PWMAIOAUX_AUX2P_MSK             BIT2
#define PWMAIOAUX_AUX2N_MSK             BIT3
#define PWMAIOAUX_AUX3P_MSK             BIT4
#define PWMAIOAUX_AUX3N_MSK             BIT5
#define PWMAIOAUX_AUX4P_MSK             BIT6
#define PWMAIOAUX_AUX4N_MSK             BIT7
#define PWMA_EnoCtrlPWM1P()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX1P_MSK)
#define PWMA_EnoBrkCtrlPWM1P()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX1P_MSK)
#define PWMA_EnoCtrlPWM1N()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX1N_MSK)
#define PWMA_EnoBrkCtrlPWM1N()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX1N_MSK)
#define PWMA_EnoCtrlPWM2P()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX2P_MSK)
#define PWMA_EnoBrkCtrlPWM2P()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX2P_MSK)
#define PWMA_EnoCtrlPWM2N()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX2N_MSK)
#define PWMA_EnoBrkCtrlPWM2N()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX2N_MSK)
#define PWMA_EnoCtrlPWM3P()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX3P_MSK)
#define PWMA_EnoBrkCtrlPWM3P()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX3P_MSK)
#define PWMA_EnoCtrlPWM3N()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX3N_MSK)
#define PWMA_EnoBrkCtrlPWM3N()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX3N_MSK)
#define PWMA_EnoCtrlPWM4P()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX4P_MSK)
#define PWMA_EnoBrkCtrlPWM4P()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX4P_MSK)
#define PWMA_EnoCtrlPWM4N()             CLR_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX4N_MSK)
#define PWMA_EnoBrkCtrlPWM4N()          SET_REG_BIT(PWMA_IOAUX, PWMAIOAUX_AUX4N_MSK)

#define PWMACR1_ARPE_MSK                BIT7
#define PWMA_UnbufferARR()              CLR_REG_BIT(PWMA_CR1, PWMACR1_ARPE_MSK)
#define PWMA_BufferARR()                SET_REG_BIT(PWMA_CR1, PWMACR1_ARPE_MSK)

#define PWMACR1_CMS_MSK                 (BIT6 | BIT5)
#define PWMA_SetAlignMode(n)            MODIFY_REG(PWMA_CR1,  PWMACR1_CMS_MSK, ((n) << 5))
#define PWMA_EdgeAlignMode()            PWMA_SetAlignMode(0)
#define PWMA_CenterAlignMode1()         PWMA_SetAlignMode(1)
#define PWMA_CenterAlignMode2()         PWMA_SetAlignMode(2)
#define PWMA_CenterAlignMode3()         PWMA_SetAlignMode(3)

#define PWMACR1_DIR_MSK                 BIT4
#define PWMA_UpCounter()                CLR_REG_BIT(PWMA_CR1, PWMACR1_DIR_MSK)
#define PWMA_DownCounter()              SET_REG_BIT(PWMA_CR1, PWMACR1_DIR_MSK)

#define PWMACR1_OPM_MSK                 BIT3
#define PWMA_ContinueMode()             CLR_REG_BIT(PWMA_CR1, PWMACR1_OPM_MSK)
#define PWMA_OnePulseMode()             SET_REG_BIT(PWMA_CR1, PWMACR1_OPM_MSK)

#define PWMACR1_URS_MSK                 BIT2
#define PWMA_UpdateRequestMode1()       SET_REG_BIT(PWMA_CR1, PWMACR1_URS_MSK)
#define PWMA_UpdateRequestMode2()       CLR_REG_BIT(PWMA_CR1, PWMACR1_URS_MSK)

#define PWMACR1_UDIS_MSK                BIT1
#define PWMA_EnableUpdate()             CLR_REG_BIT(PWMA_CR1, PWMACR1_UDIS_MSK)
#define PWMA_DisableUpdate()            SET_REG_BIT(PWMA_CR1, PWMACR1_UDIS_MSK)

#define PWMACR1_CEN_MSK                 BIT0
#define PWMA_Run()                      SET_REG_BIT(PWMA_CR1, PWMACR1_CEN_MSK)
#define PWMA_Stop()                     CLR_REG_BIT(PWMA_CR1, PWMACR1_CEN_MSK)

#define PWMACR2_TIS_MSK                 BIT7
#define PWMA_PWM1PToTI()                CLR_REG_BIT(PWMA_CR2, PWMACR2_TIS_MSK)
#define PWMA_Xor1P2P3PToTI()            SET_REG_BIT(PWMA_CR2, PWMACR2_TIS_MSK)

#define PWMACR2_MMS_MSK                 (BIT6 | BIT5 | BIT4)
#define PWMA_SelectTRGO(n)              MODIFY_REG(PWMA_CR2,  PWMACR2_MMS_MSK, ((n) << 4))
#define PWMA_ResetAsTRGO()              PWMA_SelectTRGO(0)
#define PWMA_EnableAsTRGO()             PWMA_SelectTRGO(1)
#define PWMA_UpdateAsTRGO()             PWMA_SelectTRGO(2)
#define PWMA_MatchAsTRGO()              PWMA_SelectTRGO(3)
#define PWMA_OC1REFAsTRGO()             PWMA_SelectTRGO(4)
#define PWMA_OC2REFAsTRGO()             PWMA_SelectTRGO(5)
#define PWMA_OC3REFAsTRGO()             PWMA_SelectTRGO(6)
#define PWMA_OC4REFAsTRGO()             PWMA_SelectTRGO(7)

#define PWMACR2_COMS_MSK                BIT2
#define PWMA_CCOCUpdateMode0()          CLR_REG_BIT(PWMA_CR2, PWMACR2_COMS_MSK)
#define PWMA_CCOCUpdateMode1()          SET_REG_BIT(PWMA_CR2, PWMACR2_COMS_MSK)

#define PWMACR2_CCPC_MSK                BIT0
#define PWMA_UnbufferCCOC()             CLR_REG_BIT(PWMA_CR2, PWMACR2_CCPC_MSK)
#define PWMA_BufferCCOC()               SET_REG_BIT(PWMA_CR2, PWMACR2_CCPC_MSK)

#define PWMASMCR_MSM_MSK                BIT7
#define PWMA_StandaloneMode()           CLR_REG_BIT(PWMA_SMCR, PWMASMCR_MSM_MSK)
#define PWMA_MasterSlaveMode()          SET_REG_BIT(PWMA_SMCR, PWMASMCR_MSM_MSK)

#define PWMASMCR_TS_MSK                 (BIT6 | BIT5 | BIT4)
#define PWMA_SelectTRGI(n)              MODIFY_REG(PWMA_SMCR,  PWMASMCR_TS_MSK, ((n) << 4))
#define PWMA_DisableTRGI()              PWMA_SelectTRGI(0)
#define PWMA_ITR2AsTRGI()               PWMA_SelectTRGI(2)
#define PWMA_TI1FEDAsTRGI()             PWMA_SelectTRGI(4)
#define PWMA_TI1FP1AsTRGI()             PWMA_SelectTRGI(5)
#define PWMA_TI2FP2AsTRGI()             PWMA_SelectTRGI(6)
#define PWMA_ETRFAsTRGI()               PWMA_SelectTRGI(7)

#define PWMASMCR_SMS_MSK                (BIT2 | BIT1 | BIT0)
#define PWMA_SetClockMode(n)            MODIFY_REG(PWMA_SMCR,  PWMASMCR_SMS_MSK, ((n) << 0))
#define PWMA_InternalClockMode()        PWMA_SetClockMode(0)
#define PWMA_EncoderMode1()             PWMA_SetClockMode(1)
#define PWMA_EncoderMode2()             PWMA_SetClockMode(2)
#define PWMA_EncoderMode3()             PWMA_SetClockMode(3)
#define PWMA_TriggerResetMode()        	PWMA_SetClockMode(4)
#define PWMA_TriggerGateMode()          PWMA_SetClockMode(5)
#define PWMA_TriggerStartMode()      	PWMA_SetClockMode(6)
#define PWMA_ExternalClockMode()        PWMA_SetClockMode(7)

#define PWMAETR_ETP_MSK                 BIT7
#define PWMA_ETRNonInverted()           CLR_REG_BIT(PWMA_ETR, PWMAETR_ETP_MSK)
#define PWMA_ETRInverted()              SET_REG_BIT(PWMA_ETR, PWMAETR_ETP_MSK)

#define PWMAETR_ECE_MSK                 BIT6
#define PWMA_DisableExternalClock2()    CLR_REG_BIT(PWMA_ETR, PWMAETR_ECE_MSK)
#define PWMA_EnableExternalClock2()     SET_REG_BIT(PWMA_ETR, PWMAETR_ECE_MSK)

#define PWMAETR_ETPS_MSK                (BIT5 | BIT4)
#define PWMA_SetETRDivider(n)           MODIFY_REG(PWMA_ETR,  PWMAETR_ETPS_MSK, ((n) << 4))
#define PWMA_ETRDivider1()              PWMA_SetETRDivider(0)
#define PWMA_ETRDivider2()              PWMA_SetETRDivider(1)
#define PWMA_ETRDivider4()              PWMA_SetETRDivider(2)
#define PWMA_ETRDivider8()              PWMA_SetETRDivider(3)

#define PWMAETR_ETF_MSK                 (BIT_LN)
#define PWMA_SetETRFilter(n)            MODIFY_REG(PWMA_ETR,  PWMAETR_ETF_MSK, ((n) << 0))
#define PWMA_ETRFilter1()               PWMA_SetETRFilter(0)
#define PWMA_ETRFilter2()               PWMA_SetETRFilter(1)
#define PWMA_ETRFilter4()               PWMA_SetETRFilter(2)
#define PWMA_ETRFilter8()               PWMA_SetETRFilter(3)
#define PWMA_ETRFilter12()              PWMA_SetETRFilter(4)
#define PWMA_ETRFilter16()              PWMA_SetETRFilter(5)
#define PWMA_ETRFilter24()              PWMA_SetETRFilter(6)
#define PWMA_ETRFilter32()              PWMA_SetETRFilter(7)
#define PWMA_ETRFilter48()              PWMA_SetETRFilter(8)
#define PWMA_ETRFilter64()              PWMA_SetETRFilter(9)
#define PWMA_ETRFilter80()              PWMA_SetETRFilter(10)
#define PWMA_ETRFilter96()              PWMA_SetETRFilter(11)
#define PWMA_ETRFilter128()             PWMA_SetETRFilter(12)
#define PWMA_ETRFilter160()             PWMA_SetETRFilter(13)
#define PWMA_ETRFilter192()             PWMA_SetETRFilter(14)
#define PWMA_ETRFilter256()             PWMA_SetETRFilter(15)

#define PWMAEGR_BG_MSK                  BIT7
#define PWMAEGR_TG_MSK                  BIT6
#define PWMAEGR_COMG_MSK                BIT5
#define PWMAEGR_CC4G_MSK                BIT4
#define PWMAEGR_CC3G_MSK                BIT3
#define PWMAEGR_CC2G_MSK                BIT2
#define PWMAEGR_CC1G_MSK                BIT1
#define PWMAEGR_UG_MSK                  BIT0
#define PWMA_GenerateBreakEvent()       SET_REG_BIT(PWMA_EGR, PWMAEGR_BG_MSK)
#define PWMA_GenerateTriggerEvent()     SET_REG_BIT(PWMA_EGR, PWMAEGR_TG_MSK)
#define PWMA_GenerateCOMEvent()         SET_REG_BIT(PWMA_EGR, PWMAEGR_COMG_MSK)
#define PWMA_GenerateCC4Event()         SET_REG_BIT(PWMA_EGR, PWMAEGR_CC4G_MSK)
#define PWMA_GenerateCC3Event()         SET_REG_BIT(PWMA_EGR, PWMAEGR_CC3G_MSK)
#define PWMA_GenerateCC2Event()         SET_REG_BIT(PWMA_EGR, PWMAEGR_CC2G_MSK)
#define PWMA_GenerateCC1Event()         SET_REG_BIT(PWMA_EGR, PWMAEGR_CC1G_MSK)
#define PWMA_GenerateUpdateEvent()      SET_REG_BIT(PWMA_EGR, PWMAEGR_UG_MSK)

#define PWMACCMR1_OC1CE_MSK             BIT7
#define PWMA_EnableETRFClearOC1REF()    SET_REG_BIT(PWMA_CCMR1, PWMACCMR1_OC1CE_MSK)
#define PWMA_DisableETRFClearOC1REF()   CLR_REG_BIT(PWMA_CCMR1, PWMACCMR1_OC1CE_MSK)

#define PWMACCMR1_OC1M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMA_SetOC1OutputMode(n)        MODIFY_REG(PWMA_CCMR1,  PWMACCMR1_OC1M_MSK, ((n) << 4))
#define PWMA_OC1REFFrozen()             PWMA_SetOC1OutputMode(0)
#define PWMA_OC1REFHighIfMatch()        PWMA_SetOC1OutputMode(1)
#define PWMA_OC1REFLowIfMatch()         PWMA_SetOC1OutputMode(2)
#define PWMA_OC1REFToggleIfMatch()      PWMA_SetOC1OutputMode(3)
#define PWMA_OC1REFForceLow()           PWMA_SetOC1OutputMode(4)
#define PWMA_OC1REFForceHigh()          PWMA_SetOC1OutputMode(5)
#define PWMA_OC1REFPWMMode1()           PWMA_SetOC1OutputMode(6)
#define PWMA_OC1REFPWMMode2()           PWMA_SetOC1OutputMode(7)

#define PWMACCMR1_OC1PE_MSK             BIT3
#define PWMA_UnbufferCCR1()             CLR_REG_BIT(PWMA_CCMR1, PWMACCMR1_OC1PE_MSK)
#define PWMA_BufferCCR1()               SET_REG_BIT(PWMA_CCMR1, PWMACCMR1_OC1PE_MSK)

#define PWMACCMR1_OC1FE_MSK             BIT2
#define PWMA_DisableOC1FastMode()       CLR_REG_BIT(PWMA_CCMR1, PWMACCMR1_OC1FE_MSK)
#define PWMA_EnableOC1FastMode()        SET_REG_BIT(PWMA_CCMR1, PWMACCMR1_OC1FE_MSK)

#define PWMACCMR1_CC1S_MSK              (BIT1 | BIT0)
#define PWMA_SetCC1Mode(n)              MODIFY_REG(PWMA_CCMR1,  PWMACCMR1_CC1S_MSK, ((n) << 0))
#define PWMA_CC1Output()                PWMA_SetCC1Mode(0)
#define PWMA_CC1CaptureTI1FP1()         PWMA_SetCC1Mode(1)
#define PWMA_CC1CaptureTI2FP1()         PWMA_SetCC1Mode(2)
#define PWMA_CC1CaptureTRC()            PWMA_SetCC1Mode(3)

#define PWMACCMR1_IC1F_MSK              (BIT_HN)
#define PWMA_SetIC1Filter(n)            MODIFY_REG(PWMA_CCMR1,  PWMACCMR1_IC1F_MSK, ((n) << 4))
#define PWMA_IC1Filter1()               PWMA_SetIC1Filter(0)
#define PWMA_IC1Filter2()               PWMA_SetIC1Filter(1)
#define PWMA_IC1Filter4()               PWMA_SetIC1Filter(2)
#define PWMA_IC1Filter8()               PWMA_SetIC1Filter(3)
#define PWMA_IC1Filter12()              PWMA_SetIC1Filter(4)
#define PWMA_IC1Filter16()              PWMA_SetIC1Filter(5)
#define PWMA_IC1Filter24()              PWMA_SetIC1Filter(6)
#define PWMA_IC1Filter32()              PWMA_SetIC1Filter(7)
#define PWMA_IC1Filter48()              PWMA_SetIC1Filter(8)
#define PWMA_IC1Filter64()              PWMA_SetIC1Filter(9)
#define PWMA_IC1Filter80()              PWMA_SetIC1Filter(10)
#define PWMA_IC1Filter96()              PWMA_SetIC1Filter(11)
#define PWMA_IC1Filter128()             PWMA_SetIC1Filter(12)
#define PWMA_IC1Filter160()             PWMA_SetIC1Filter(13)
#define PWMA_IC1Filter192()             PWMA_SetIC1Filter(14)
#define PWMA_IC1Filter256()             PWMA_SetIC1Filter(15)

#define PWMACCMR1_IC1PS_MSK             (BIT3 | BIT2)
#define PWMA_SetIC1Divider(n)           MODIFY_REG(PWMA_CCMR1,  PWMACCMR1_IC1PS_MSK, ((n) << 2))
#define PWMA_IC1Divider1()              PWMA_SetIC1Divider(0)
#define PWMA_IC1Divider2()              PWMA_SetIC1Divider(1)
#define PWMA_IC1Divider4()              PWMA_SetIC1Divider(2)
#define PWMA_IC1Divider8()              PWMA_SetIC1Divider(3)

#define PWMACCMR2_OC2CE_MSK             BIT7
#define PWMA_EnableETRFClearOC2REF()    SET_REG_BIT(PWMA_CCMR2, PWMACCMR2_OC2CE_MSK)
#define PWMA_DisableETRFClearOC2REF()   CLR_REG_BIT(PWMA_CCMR2, PWMACCMR2_OC2CE_MSK)

#define PWMACCMR2_OC2M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMA_SetOC2OutputMode(n)        MODIFY_REG(PWMA_CCMR2,  PWMACCMR2_OC2M_MSK, ((n) << 4))
#define PWMA_OC2REFFrozen()             PWMA_SetOC2OutputMode(0)
#define PWMA_OC2REFHighIfMatch()        PWMA_SetOC2OutputMode(1)
#define PWMA_OC2REFLowIfMatch()         PWMA_SetOC2OutputMode(2)
#define PWMA_OC2REFToggleIfMatch()      PWMA_SetOC2OutputMode(3)
#define PWMA_OC2REFForceLow()           PWMA_SetOC2OutputMode(4)
#define PWMA_OC2REFForceHigh()          PWMA_SetOC2OutputMode(5)
#define PWMA_OC2REFPWMMode1()           PWMA_SetOC2OutputMode(6)
#define PWMA_OC2REFPWMMode2()           PWMA_SetOC2OutputMode(7)

#define PWMACCMR2_OC2PE_MSK             BIT3
#define PWMA_UnbufferCCR2()             CLR_REG_BIT(PWMA_CCMR2, PWMACCMR2_OC2PE_MSK)
#define PWMA_BufferCCR2()               SET_REG_BIT(PWMA_CCMR2, PWMACCMR2_OC2PE_MSK)

#define PWMACCMR2_OC2FE_MSK             BIT2
#define PWMA_DisableOC2FastMode()       CLR_REG_BIT(PWMA_CCMR2, PWMACCMR2_OC2FE_MSK)
#define PWMA_EnableOC2FastMode()        SET_REG_BIT(PWMA_CCMR2, PWMACCMR2_OC2FE_MSK)

#define PWMACCMR2_CC2S_MSK              (BIT1 | BIT0)
#define PWMA_SetCC2Mode(n)              MODIFY_REG(PWMA_CCMR2,  PWMACCMR2_CC2S_MSK, ((n) << 0))
#define PWMA_CC2Output()                PWMA_SetCC2Mode(0)
#define PWMA_CC2CaptureTI2FP2()         PWMA_SetCC2Mode(1)
#define PWMA_CC2CaptureTI1FP2()         PWMA_SetCC2Mode(2)
#define PWMA_CC2CaptureTRC()            PWMA_SetCC2Mode(3)

#define PWMACCMR2_IC2F_MSK              (BIT_HN)
#define PWMA_SetIC2Filter(n)            MODIFY_REG(PWMA_CCMR2,  PWMACCMR2_IC2F_MSK, ((n) << 4))
#define PWMA_IC2Filter1()               PWMA_SetIC2Filter(0)
#define PWMA_IC2Filter2()               PWMA_SetIC2Filter(1)
#define PWMA_IC2Filter4()               PWMA_SetIC2Filter(2)
#define PWMA_IC2Filter8()               PWMA_SetIC2Filter(3)
#define PWMA_IC2Filter12()              PWMA_SetIC2Filter(4)
#define PWMA_IC2Filter16()              PWMA_SetIC2Filter(5)
#define PWMA_IC2Filter24()              PWMA_SetIC2Filter(6)
#define PWMA_IC2Filter32()              PWMA_SetIC2Filter(7)
#define PWMA_IC2Filter48()              PWMA_SetIC2Filter(8)
#define PWMA_IC2Filter64()              PWMA_SetIC2Filter(9)
#define PWMA_IC2Filter80()              PWMA_SetIC2Filter(10)
#define PWMA_IC2Filter96()              PWMA_SetIC2Filter(11)
#define PWMA_IC2Filter128()             PWMA_SetIC2Filter(12)
#define PWMA_IC2Filter160()             PWMA_SetIC2Filter(13)
#define PWMA_IC2Filter192()             PWMA_SetIC2Filter(14)
#define PWMA_IC2Filter256()             PWMA_SetIC2Filter(15)

#define PWMACCMR2_IC2PS_MSK             (BIT3 | BIT2)
#define PWMA_SetIC2Divider(n)           MODIFY_REG(PWMA_CCMR2,  PWMACCMR2_IC2PS_MSK, ((n) << 2))
#define PWMA_IC2Divider1()              PWMA_SetIC2Divider(0)
#define PWMA_IC2Divider2()              PWMA_SetIC2Divider(1)
#define PWMA_IC2Divider4()              PWMA_SetIC2Divider(2)
#define PWMA_IC2Divider8()              PWMA_SetIC2Divider(3)

#define PWMACCMR3_OC3CE_MSK             BIT7
#define PWMA_EnableETRFClearOC3REF()    SET_REG_BIT(PWMA_CCMR3, PWMACCMR3_OC3CE_MSK)
#define PWMA_DisableETRFClearOC3REF()   CLR_REG_BIT(PWMA_CCMR3, PWMACCMR3_OC3CE_MSK)

#define PWMACCMR3_OC3M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMA_SetOC3OutputMode(n)        MODIFY_REG(PWMA_CCMR3,  PWMACCMR3_OC3M_MSK, ((n) << 4))
#define PWMA_OC3REFFrozen()             PWMA_SetOC3OutputMode(0)
#define PWMA_OC3REFHighIfMatch()        PWMA_SetOC3OutputMode(1)
#define PWMA_OC3REFLowIfMatch()         PWMA_SetOC3OutputMode(2)
#define PWMA_OC3REFToggleIfMatch()      PWMA_SetOC3OutputMode(3)
#define PWMA_OC3REFForceLow()           PWMA_SetOC3OutputMode(4)
#define PWMA_OC3REFForceHigh()          PWMA_SetOC3OutputMode(5)
#define PWMA_OC3REFPWMMode1()           PWMA_SetOC3OutputMode(6)
#define PWMA_OC3REFPWMMode2()           PWMA_SetOC3OutputMode(7)

#define PWMACCMR3_OC3PE_MSK             BIT3
#define PWMA_UnbufferCCR3()             CLR_REG_BIT(PWMA_CCMR3, PWMACCMR3_OC3PE_MSK)
#define PWMA_BufferCCR3()               SET_REG_BIT(PWMA_CCMR3, PWMACCMR3_OC3PE_MSK)

#define PWMACCMR3_OC3FE_MSK             BIT2
#define PWMA_DisableOC3FastMode()       CLR_REG_BIT(PWMA_CCMR3, PWMACCMR3_OC3FE_MSK)
#define PWMA_EnableOC3FastMode()        SET_REG_BIT(PWMA_CCMR3, PWMACCMR3_OC3FE_MSK)

#define PWMACCMR3_CC3S_MSK              (BIT1 | BIT0)
#define PWMA_SetCC3Mode(n)              MODIFY_REG(PWMA_CCMR3,  PWMACCMR3_CC3S_MSK, ((n) << 0))
#define PWMA_CC3Output()                PWMA_SetCC3Mode(0)
#define PWMA_CC3CaptureTI3FP3()         PWMA_SetCC3Mode(1)
#define PWMA_CC3CaptureTI4FP3()         PWMA_SetCC3Mode(2)
#define PWMA_CC3CaptureTRC()            PWMA_SetCC3Mode(3)

#define PWMACCMR3_IC3F_MSK              (BIT_HN)
#define PWMA_SetIC3Filter(n)            MODIFY_REG(PWMA_CCMR3,  PWMACCMR3_IC3F_MSK, ((n) << 4))
#define PWMA_IC3Filter1()               PWMA_SetIC3Filter(0)
#define PWMA_IC3Filter2()               PWMA_SetIC3Filter(1)
#define PWMA_IC3Filter4()               PWMA_SetIC3Filter(2)
#define PWMA_IC3Filter8()               PWMA_SetIC3Filter(3)
#define PWMA_IC3Filter12()              PWMA_SetIC3Filter(4)
#define PWMA_IC3Filter16()              PWMA_SetIC3Filter(5)
#define PWMA_IC3Filter24()              PWMA_SetIC3Filter(6)
#define PWMA_IC3Filter32()              PWMA_SetIC3Filter(7)
#define PWMA_IC3Filter48()              PWMA_SetIC3Filter(8)
#define PWMA_IC3Filter64()              PWMA_SetIC3Filter(9)
#define PWMA_IC3Filter80()              PWMA_SetIC3Filter(10)
#define PWMA_IC3Filter96()              PWMA_SetIC3Filter(11)
#define PWMA_IC3Filter128()             PWMA_SetIC3Filter(12)
#define PWMA_IC3Filter160()             PWMA_SetIC3Filter(13)
#define PWMA_IC3Filter192()             PWMA_SetIC3Filter(14)
#define PWMA_IC3Filter256()             PWMA_SetIC3Filter(15)

#define PWMACCMR3_IC3PS_MSK             (BIT3 | BIT2)
#define PWMA_SetIC3Divider(n)           MODIFY_REG(PWMA_CCMR3,  PWMACCMR3_IC3PS_MSK, ((n) << 2))
#define PWMA_IC3Divider1()              PWMA_SetIC3Divider(0)
#define PWMA_IC3Divider2()              PWMA_SetIC3Divider(1)
#define PWMA_IC3Divider4()              PWMA_SetIC3Divider(2)
#define PWMA_IC3Divider8()              PWMA_SetIC3Divider(3)

#define PWMACCMR4_OC4CE_MSK             BIT7
#define PWMA_EnableETRFClearOC4REF()    SET_REG_BIT(PWMA_CCMR4, PWMACCMR4_OC4CE_MSK)
#define PWMA_DisableETRFClearOC4REF()   CLR_REG_BIT(PWMA_CCMR4, PWMACCMR4_OC4CE_MSK)

#define PWMACCMR4_OC4M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMA_SetOC4OutputMode(n)        MODIFY_REG(PWMA_CCMR4,  PWMACCMR4_OC4M_MSK, ((n) << 4))
#define PWMA_OC4REFFrozen()             PWMA_SetOC4OutputMode(0)
#define PWMA_OC4REFHighIfMatch()        PWMA_SetOC4OutputMode(1)
#define PWMA_OC4REFLowIfMatch()         PWMA_SetOC4OutputMode(2)
#define PWMA_OC4REFToggleIfMatch()      PWMA_SetOC4OutputMode(3)
#define PWMA_OC4REFForceLow()           PWMA_SetOC4OutputMode(4)
#define PWMA_OC4REFForceHigh()          PWMA_SetOC4OutputMode(5)
#define PWMA_OC4REFPWMMode1()           PWMA_SetOC4OutputMode(6)
#define PWMA_OC4REFPWMMode2()           PWMA_SetOC4OutputMode(7)

#define PWMACCMR4_OC4PE_MSK             BIT3
#define PWMA_UnbufferCCR4()             CLR_REG_BIT(PWMA_CCMR4, PWMACCMR4_OC4PE_MSK)
#define PWMA_BufferCCR4()               SET_REG_BIT(PWMA_CCMR4, PWMACCMR4_OC4PE_MSK)

#define PWMACCMR4_OC4FE_MSK             BIT2
#define PWMA_DisableOC4FastMode()       CLR_REG_BIT(PWMA_CCMR4, PWMACCMR4_OC4FE_MSK)
#define PWMA_EnableOC4FastMode()        SET_REG_BIT(PWMA_CCMR4, PWMACCMR4_OC4FE_MSK)

#define PWMACCMR4_CC4S_MSK              (BIT1 | BIT0)
#define PWMA_SetCC4Mode(n)              MODIFY_REG(PWMA_CCMR4,  PWMACCMR4_CC4S_MSK, ((n) << 0))
#define PWMA_CC4Output()                PWMA_SetCC4Mode(0)
#define PWMA_CC4CaptureTI4FP4()         PWMA_SetCC4Mode(1)
#define PWMA_CC4CaptureTI3FP4()         PWMA_SetCC4Mode(2)
#define PWMA_CC4CaptureTRC()            PWMA_SetCC4Mode(3)

#define PWMACCMR4_IC4F_MSK              (BIT_HN)
#define PWMA_SetIC4Filter(n)            MODIFY_REG(PWMA_CCMR4,  PWMACCMR4_IC4F_MSK, ((n) << 4))
#define PWMA_IC4Filter1()               PWMA_SetIC4Filter(0)
#define PWMA_IC4Filter2()               PWMA_SetIC4Filter(1)
#define PWMA_IC4Filter4()               PWMA_SetIC4Filter(2)
#define PWMA_IC4Filter8()               PWMA_SetIC4Filter(3)
#define PWMA_IC4Filter12()              PWMA_SetIC4Filter(4)
#define PWMA_IC4Filter16()              PWMA_SetIC4Filter(5)
#define PWMA_IC4Filter24()              PWMA_SetIC4Filter(6)
#define PWMA_IC4Filter32()              PWMA_SetIC4Filter(7)
#define PWMA_IC4Filter48()              PWMA_SetIC4Filter(8)
#define PWMA_IC4Filter64()              PWMA_SetIC4Filter(9)
#define PWMA_IC4Filter80()              PWMA_SetIC4Filter(10)
#define PWMA_IC4Filter96()              PWMA_SetIC4Filter(11)
#define PWMA_IC4Filter128()             PWMA_SetIC4Filter(12)
#define PWMA_IC4Filter160()             PWMA_SetIC4Filter(13)
#define PWMA_IC4Filter192()             PWMA_SetIC4Filter(14)
#define PWMA_IC4Filter256()             PWMA_SetIC4Filter(15)

#define PWMACCMR4_IC4PS_MSK             (BIT3 | BIT2)
#define PWMA_SetIC4Divider(n)           MODIFY_REG(PWMA_CCMR4,  PWMACCMR4_IC4PS_MSK, ((n) << 2))
#define PWMA_IC4Divider1()              PWMA_SetIC4Divider(0)
#define PWMA_IC4Divider2()              PWMA_SetIC4Divider(1)
#define PWMA_IC4Divider4()              PWMA_SetIC4Divider(2)
#define PWMA_IC4Divider8()              PWMA_SetIC4Divider(3)

#define PWMACCER1_CC1E_MSK              BIT0
#define PWMA_CC1PEnable()               SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC1E_MSK)
#define PWMA_CC1PDisable()              CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC1E_MSK)

#define PWMACCER1_CC1P_MSK              BIT1
#define PWMA_CC1PNonInverted()          CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC1P_MSK)
#define PWMA_CC1PInverted()             SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC1P_MSK)

#define PWMACCER1_CC1NE_MSK             BIT2
#define PWMA_CC1NEnable()               SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC1NE_MSK)
#define PWMA_CC1NDisable()              CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC1NE_MSK)

#define PWMACCER1_CC1NP_MSK             BIT3
#define PWMA_CC1NNonInverted()          CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC1NP_MSK)
#define PWMA_CC1NInverted()             SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC1NP_MSK)

#define PWMACCER1_CC2E_MSK              BIT4
#define PWMA_CC2PEnable()               SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC2E_MSK)
#define PWMA_CC2PDisable()              CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC2E_MSK)

#define PWMACCER1_CC2P_MSK              BIT5
#define PWMA_CC2PNonInverted()          CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC2P_MSK)
#define PWMA_CC2PInverted()             SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC2P_MSK)

#define PWMACCER1_CC2NE_MSK             BIT6
#define PWMA_CC2NEnable()               SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC2NE_MSK)
#define PWMA_CC2NDisable()              CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC2NE_MSK)

#define PWMACCER1_CC2NP_MSK             BIT7
#define PWMA_CC2NNonInverted()          CLR_REG_BIT(PWMA_CCER1, PWMACCER1_CC2NP_MSK)
#define PWMA_CC2NInverted()             SET_REG_BIT(PWMA_CCER1, PWMACCER1_CC2NP_MSK)

#define PWMACCER2_CC3E_MSK              BIT0
#define PWMA_CC3PEnable()               SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC3E_MSK)
#define PWMA_CC3PDisable()              CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC3E_MSK)

#define PWMACCER2_CC3P_MSK              BIT1
#define PWMA_CC3PNonInverted()          CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC3P_MSK)
#define PWMA_CC3PInverted()             SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC3P_MSK)

#define PWMACCER2_CC3NE_MSK             BIT2
#define PWMA_CC3NEnable()               SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC3NE_MSK)
#define PWMA_CC3NDisable()              CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC3NE_MSK)

#define PWMACCER2_CC3NP_MSK             BIT3
#define PWMA_CC3NNonInverted()          CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC3NP_MSK)
#define PWMA_CC3NInverted()             SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC3NP_MSK)

#define PWMACCER2_CC4E_MSK              BIT4
#define PWMA_CC4PEnable()               SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC4E_MSK)
#define PWMA_CC4PDisable()              CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC4E_MSK)

#define PWMACCER2_CC4P_MSK              BIT5
#define PWMA_CC4PNonInverted()          CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC4P_MSK)
#define PWMA_CC4PInverted()             SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC4P_MSK)

#define PWMACCER2_CC4NE_MSK             BIT6
#define PWMA_CC4NEnable()               SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC4NE_MSK)
#define PWMA_CC4NDisable()              CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC4NE_MSK)

#define PWMACCER2_CC4NP_MSK             BIT7
#define PWMA_CC4NNonInverted()          CLR_REG_BIT(PWMA_CCER2, PWMACCER2_CC4NP_MSK)
#define PWMA_CC4NInverted()             SET_REG_BIT(PWMA_CCER2, PWMACCER2_CC4NP_MSK)

#define PWMABRK_MOE_MSK                 BIT7
#define PWMA_EnableMainOutput()         SET_REG_BIT(PWMA_BKR, PWMABRK_MOE_MSK)
#define PWMA_DisableMainOutput()        CLR_REG_BIT(PWMA_BKR, PWMABRK_MOE_MSK)

#define PWMABRK_AOE_MSK                 BIT6
#define PWMA_EnableAutoOutput()         SET_REG_BIT(PWMA_BKR, PWMABRK_AOE_MSK)
#define PWMA_DisableAutoOutput()        CLR_REG_BIT(PWMA_BKR, PWMABRK_AOE_MSK)

#define PWMABRK_BKP_MSK                 BIT5
#define PWMA_BRKNonInverted()           SET_REG_BIT(PWMA_BKR, PWMABRK_BKP_MSK)
#define PWMA_BRKInverted()              CLR_REG_BIT(PWMA_BKR, PWMABRK_BKP_MSK)

#define PWMABRK_BKE_MSK                 BIT4
#define PWMA_BRKEnable()                SET_REG_BIT(PWMA_BKR, PWMABRK_BKE_MSK)
#define PWMA_BRKDisable()               CLR_REG_BIT(PWMA_BKR, PWMABRK_BKE_MSK)

#define PWMABRK_OSSR_MSK                BIT3
#define PWMABRK_OSSI_MSK                BIT2
#define PWMA_RunInactiveNoOutput()      CLR_REG_BIT(PWMA_BKR, PWMABRK_OSSR_MSK)
#define PWMA_RunInactiveOutput()        SET_REG_BIT(PWMA_BKR, PWMABRK_OSSR_MSK)
#define PWMA_IdleInactiveNoOutput()     CLR_REG_BIT(PWMA_BKR, PWMABRK_OSSI_MSK)
#define PWMA_IdleInactiveOutput()       SET_REG_BIT(PWMA_BKR, PWMABRK_OSSI_MSK)

#define PWMABRK_LOCK_MSK                (BIT1 | BIT0)
#define PWMA_SetLockLevel(n)            MODIFY_REG(PWMA_BKR,  PWMABRK_LOCK_MSK, ((n) << 0))
#define PWMA_SetUnLock()                PWMA_SetLockLevel(0)

#define PWMAOISR_OIS1_MSK               BIT0
#define PWMAOISR_OIS1N_MSK              BIT1
#define PWMAOISR_OIS2_MSK               BIT2
#define PWMAOISR_OIS2N_MSK              BIT3
#define PWMAOISR_OIS3_MSK               BIT4
#define PWMAOISR_OIS3N_MSK              BIT5
#define PWMAOISR_OIS4_MSK               BIT6
#define PWMAOISR_OIS4N_MSK              BIT7
#define PWMA_OC1PIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS1_MSK)
#define PWMA_OC1PIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS1_MSK)
#define PWMA_OC1NIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS1N_MSK)
#define PWMA_OC1NIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS1N_MSK)
#define PWMA_OC2PIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS2_MSK)
#define PWMA_OC2PIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS2_MSK)
#define PWMA_OC2NIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS2N_MSK)
#define PWMA_OC2NIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS2N_MSK)
#define PWMA_OC3PIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS3_MSK)
#define PWMA_OC3PIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS3_MSK)
#define PWMA_OC3NIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS3N_MSK)
#define PWMA_OC3NIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS3N_MSK)
#define PWMA_OC4PIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS4_MSK)
#define PWMA_OC4PIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS4_MSK)
#define PWMA_OC4NIdleLevelLow()         CLR_REG_BIT(PWMA_OISR, PWMAOISR_OIS4N_MSK)
#define PWMA_OC4NIdleLevelHigh()        SET_REG_BIT(PWMA_OISR, PWMAOISR_OIS4N_MSK)

#define PWMA_SetCounter(n)              (PWMA_CNTRH = HIBYTE(n), PWMA_CNTRL = LOBYTE(n))
#define PWMA_SetClockDivider(n)         (PWMA_PSCRH = HIBYTE(n), PWMA_PSCRL = LOBYTE(n))
#define PWMA_SetReload16(n)             (PWMA_ARRH = HIBYTE(n), PWMA_ARRL = LOBYTE(n))
//#define PWMA_SetRepeatCounter(n)      (PWMA_RCRH = HIBYTE(n), PWMA_RCR = LOBYTE(n))
#define PWMA_SetRepeatCounter(n)        (PWMA_RCR = LOBYTE(n))

#define PWMA_SetCCR1Value(n)            (PWMA_CCR1H = HIBYTE(n), PWMA_CCR1L = LOBYTE(n))
#define PWMA_SetCCR2Value(n)            (PWMA_CCR2H = HIBYTE(n), PWMA_CCR2L = LOBYTE(n))
#define PWMA_SetCCR3Value(n)            (PWMA_CCR3H = HIBYTE(n), PWMA_CCR3L = LOBYTE(n))
#define PWMA_SetCCR4Value(n)            (PWMA_CCR4H = HIBYTE(n), PWMA_CCR4L = LOBYTE(n))

#define PWMA_ReadReload16()            	MAKEWORD(PWMA_ARRL, PWMA_ARRH)

#define PWMA_ReadCCR1Value()            MAKEWORD(PWMA_CCR1L, PWMA_CCR1H)
#define PWMA_ReadCCR2Value()            MAKEWORD(PWMA_CCR2L, PWMA_CCR2H)
#define PWMA_ReadCCR3Value()            MAKEWORD(PWMA_CCR3L, PWMA_CCR3H)
#define PWMA_ReadCCR4Value()            MAKEWORD(PWMA_CCR4L, PWMA_CCR4H)

#define PWMA_SetDeadTime(n)             PWMA_DTR = LOBYTE(n)

////////////////////////

#define PWMBENO_ENO5P_MSK               BIT0
#define PWMBENO_ENO6P_MSK               BIT2
#define PWMBENO_ENO7P_MSK               BIT4
#define PWMBENO_ENO8P_MSK               BIT6
#define PWMB_EnablePWM5POutput()        SET_REG_BIT(PWMB_ENO, PWMBENO_ENO5P_MSK)
#define PWMB_DisablePWM5POutput()       CLR_REG_BIT(PWMB_ENO, PWMBENO_ENO5P_MSK)
#define PWMB_EnablePWM6POutput()        SET_REG_BIT(PWMB_ENO, PWMBENO_ENO6P_MSK)
#define PWMB_DisablePWM6POutput()       CLR_REG_BIT(PWMB_ENO, PWMBENO_ENO6P_MSK)
#define PWMB_EnablePWM7POutput()        SET_REG_BIT(PWMB_ENO, PWMBENO_ENO7P_MSK)
#define PWMB_DisablePWM7POutput()       CLR_REG_BIT(PWMB_ENO, PWMBENO_ENO7P_MSK)
#define PWMB_EnablePWM8POutput()        SET_REG_BIT(PWMB_ENO, PWMBENO_ENO8P_MSK)
#define PWMB_DisablePWM8POutput()       CLR_REG_BIT(PWMB_ENO, PWMBENO_ENO8P_MSK)

#define PWMBIOAUX_AUX5P_MSK             BIT0
#define PWMBIOAUX_AUX6P_MSK             BIT2
#define PWMBIOAUX_AUX7P_MSK             BIT4
#define PWMBIOAUX_AUX8P_MSK             BIT6
#define PWMB_EnoCtrlPWM5P()             CLR_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX5P_MSK)
#define PWMB_EnoBrkCtrlPWM5P()          SET_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX5P_MSK)
#define PWMB_EnoCtrlPWM6P()             CLR_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX6P_MSK)
#define PWMB_EnoBrkCtrlPWM6P()          SET_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX6P_MSK)
#define PWMB_EnoCtrlPWM7P()             CLR_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX7P_MSK)
#define PWMB_EnoBrkCtrlPWM7P()          SET_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX7P_MSK)
#define PWMB_EnoCtrlPWM8P()             CLR_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX8P_MSK)
#define PWMB_EnoBrkCtrlPWM8P()          SET_REG_BIT(PWMB_IOAUX, PWMBIOAUX_AUX8P_MSK)

#define PWMBCR1_ARPE_MSK                BIT7
#define PWMB_UnbufferARR()              CLR_REG_BIT(PWMB_CR1, PWMBCR1_ARPE_MSK)
#define PWMB_BufferARR()                SET_REG_BIT(PWMB_CR1, PWMBCR1_ARPE_MSK)

#define PWMBCR1_CMS_MSK                 (BIT6 | BIT5)
#define PWMB_SetAlignMode(n)            MODIFY_REG(PWMB_CR1,  PWMBCR1_CMS_MSK, ((n) << 5))
#define PWMB_EdgeAlignMode()            PWMB_SetAlignMode(0)
#define PWMB_CenterAlignMode1()         PWMB_SetAlignMode(1)
#define PWMB_CenterAlignMode2()         PWMB_SetAlignMode(2)
#define PWMB_CenterAlignMode3()         PWMB_SetAlignMode(3)

#define PWMBCR1_DIR_MSK                 BIT4
#define PWMB_UpCounter()                CLR_REG_BIT(PWMB_CR1, PWMBCR1_DIR_MSK)
#define PWMB_DownCounter()              SET_REG_BIT(PWMB_CR1, PWMBCR1_DIR_MSK)

#define PWMBCR1_OPM_MSK                 BIT3
#define PWMB_ContinueMode()             CLR_REG_BIT(PWMB_CR1, PWMBCR1_OPM_MSK)
#define PWMB_OnePulseMode()             SET_REG_BIT(PWMB_CR1, PWMBCR1_OPM_MSK)

#define PWMBCR1_URS_MSK                 BIT2
#define PWMB_UpdateRequestMode1()       SET_REG_BIT(PWMB_CR1, PWMBCR1_URS_MSK)
#define PWMB_UpdateRequestMode2()       CLR_REG_BIT(PWMB_CR1, PWMBCR1_URS_MSK)

#define PWMBCR1_UDIS_MSK                BIT1
#define PWMB_EnableUpdate()             CLR_REG_BIT(PWMB_CR1, PWMBCR1_UDIS_MSK)
#define PWMB_DisableUpdate()            SET_REG_BIT(PWMB_CR1, PWMBCR1_UDIS_MSK)

#define PWMBCR1_CEN_MSK                 BIT0
#define PWMB_Run()                      SET_REG_BIT(PWMB_CR1, PWMBCR1_CEN_MSK)
#define PWMB_Stop()                     CLR_REG_BIT(PWMB_CR1, PWMBCR1_CEN_MSK)

#define PWMBCR2_TIS_MSK                 BIT7
#define PWMB_PWM5PToTI()                CLR_REG_BIT(PWMB_CR2, PWMBCR2_TIS_MSK)
#define PWMB_Xor5P6P7PToTI()            SET_REG_BIT(PWMB_CR2, PWMBCR2_TIS_MSK)

#define PWMBCR2_MMS_MSK                 (BIT6 | BIT5 | BIT4)
#define PWMB_SelectTRGO(n)              MODIFY_REG(PWMB_CR2,  PWMBCR2_MMS_MSK, ((n) << 4))
#define PWMB_ResetAsTRGO()              PWMB_SelectTRGO(0)
#define PWMB_EnableAsTRGO()             PWMB_SelectTRGO(1)
#define PWMB_UpdateAsTRGO()             PWMB_SelectTRGO(2)
#define PWMB_MatchAsTRGO()              PWMB_SelectTRGO(3)
#define PWMB_OC5REFAsTRGO()             PWMB_SelectTRGO(4)
#define PWMB_OC6REFAsTRGO()             PWMB_SelectTRGO(5)
#define PWMB_OC7REFAsTRGO()             PWMB_SelectTRGO(6)
#define PWMB_OC8REFAsTRGO()             PWMB_SelectTRGO(7)

#define PWMBCR2_COMS_MSK                BIT2
#define PWMB_CCOCUpdateMode0()          CLR_REG_BIT(PWMB_CR2, PWMBCR2_COMS_MSK)
#define PWMB_CCOCUpdateMode1()          SET_REG_BIT(PWMB_CR2, PWMBCR2_COMS_MSK)

#define PWMBCR2_CCPC_MSK                BIT0
#define PWMB_UnbufferCCOC()             CLR_REG_BIT(PWMB_CR2, PWMBCR2_CCPC_MSK)
#define PWMB_BufferCCOC()               SET_REG_BIT(PWMB_CR2, PWMBCR2_CCPC_MSK)

#define PWMBSMCR_TS_MSK                 (BIT6 | BIT5 | BIT4)
#define PWMB_SelectTRGI(n)              MODIFY_REG(PWMB_SMCR,  PWMBSMCR_TS_MSK, ((n) << 4))
#define PWMB_DisableTRGI()              PWMB_SelectTRGI(0)
#define PWMB_TI5FEDAsTRGI()             PWMB_SelectTRGI(4)
#define PWMB_TI5FP5AsTRGI()             PWMB_SelectTRGI(5)
#define PWMB_TI6FP6AsTRGI()             PWMB_SelectTRGI(6)
#define PWMB_ETRFAsTRGI()               PWMB_SelectTRGI(7)

#define PWMBSMCR_SMS_MSK                (BIT2 | BIT1 | BIT0)
#define PWMB_SetClockMode(n)            MODIFY_REG(PWMB_SMCR,  PWMBSMCR_SMS_MSK, ((n) << 0))
#define PWMB_InternalClockMode()        PWMB_SetClockMode(0)
#define PWMB_EncoderMode1()             PWMB_SetClockMode(1)
#define PWMB_EncoderMode2()             PWMB_SetClockMode(2)
#define PWMB_EncoderMode3()             PWMB_SetClockMode(3)
#define PWMB_TriggerResetMode()        	PWMB_SetClockMode(4)
#define PWMB_TriggerGateMode()          PWMB_SetClockMode(5)
#define PWMB_TriggerStartMode()      	PWMB_SetClockMode(6)
#define PWMB_ExternalClockMode()        PWMB_SetClockMode(7)

#define PWMBETR_ETP_MSK                 BIT7
#define PWMB_ETRNonInverted()           CLR_REG_BIT(PWMB_ETR, PWMBETR_ETP_MSK)
#define PWMB_ETRInverted()              SET_REG_BIT(PWMB_ETR, PWMBETR_ETP_MSK)

#define PWMBETR_ECE_MSK                 BIT6
#define PWMB_DisableExternalClock2()    CLR_REG_BIT(PWMB_ETR, PWMBETR_ECE_MSK)
#define PWMB_EnableExternalClock2()     SET_REG_BIT(PWMB_ETR, PWMBETR_ECE_MSK)

#define PWMBETR_ETPS_MSK                (BIT5 | BIT4)
#define PWMB_SetETRDivider(n)           MODIFY_REG(PWMB_ETR,  PWMBETR_ETPS_MSK, ((n) << 4))
#define PWMB_ETRDivider1()              PWMB_SetETRDivider(0)
#define PWMB_ETRDivider2()              PWMB_SetETRDivider(1)
#define PWMB_ETRDivider4()              PWMB_SetETRDivider(2)
#define PWMB_ETRDivider8()              PWMB_SetETRDivider(3)

#define PWMBETR_ETF_MSK                 (BIT_LN)
#define PWMB_SetETRFilter(n)            MODIFY_REG(PWMB_ETR,  PWMBETR_ETF_MSK, ((n) << 0))
#define PWMB_ETRFilter1()               PWMB_SetETRFilter(0)
#define PWMB_ETRFilter2()               PWMB_SetETRFilter(1)
#define PWMB_ETRFilter4()               PWMB_SetETRFilter(2)
#define PWMB_ETRFilter8()               PWMB_SetETRFilter(3)
#define PWMB_ETRFilter12()              PWMB_SetETRFilter(4)
#define PWMB_ETRFilter16()              PWMB_SetETRFilter(5)
#define PWMB_ETRFilter24()              PWMB_SetETRFilter(6)
#define PWMB_ETRFilter32()              PWMB_SetETRFilter(7)
#define PWMB_ETRFilter48()              PWMB_SetETRFilter(8)
#define PWMB_ETRFilter64()              PWMB_SetETRFilter(9)
#define PWMB_ETRFilter80()              PWMB_SetETRFilter(10)
#define PWMB_ETRFilter96()              PWMB_SetETRFilter(11)
#define PWMB_ETRFilter128()             PWMB_SetETRFilter(12)
#define PWMB_ETRFilter160()             PWMB_SetETRFilter(13)
#define PWMB_ETRFilter192()             PWMB_SetETRFilter(14)
#define PWMB_ETRFilter256()             PWMB_SetETRFilter(15)

#define PWMBEGR_BG_MSK                  BIT7
#define PWMBEGR_TG_MSK                  BIT6
#define PWMBEGR_COMG_MSK                BIT5
#define PWMBEGR_CC8G_MSK                BIT4
#define PWMBEGR_CC7G_MSK                BIT3
#define PWMBEGR_CC6G_MSK                BIT2
#define PWMBEGR_CC5G_MSK                BIT1
#define PWMBEGR_UG_MSK                  BIT0
#define PWMB_GenerateBreakEvent()       SET_REG_BIT(PWMB_EGR, PWMBEGR_BG_MSK)
#define PWMB_GenerateTriggerEvent()     SET_REG_BIT(PWMB_EGR, PWMBEGR_TG_MSK)
#define PWMB_GenerateCOMEvent()         SET_REG_BIT(PWMB_EGR, PWMBEGR_COMG_MSK)
#define PWMB_GenerateCC8Event()         SET_REG_BIT(PWMB_EGR, PWMBEGR_CC8G_MSK)
#define PWMB_GenerateCC7Event()         SET_REG_BIT(PWMB_EGR, PWMBEGR_CC7G_MSK)
#define PWMB_GenerateCC6Event()         SET_REG_BIT(PWMB_EGR, PWMBEGR_CC6G_MSK)
#define PWMB_GenerateCC5Event()         SET_REG_BIT(PWMB_EGR, PWMBEGR_CC5G_MSK)
#define PWMB_GenerateUpdateEvent()      SET_REG_BIT(PWMB_EGR, PWMBEGR_UG_MSK)

#define PWMBCCMR1_OC5CE_MSK             BIT7
#define PWMB_EnableETRFClearOC5REF()    SET_REG_BIT(PWMB_CCMR1, PWMBCCMR1_OC5CE_MSK)
#define PWMB_DisableETRFClearOC5REF()   CLR_REG_BIT(PWMB_CCMR1, PWMBCCMR1_OC5CE_MSK)

#define PWMBCCMR1_OC5M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMB_SetOC5OutputMode(n)        MODIFY_REG(PWMB_CCMR1,  PWMBCCMR1_OC5M_MSK, ((n) << 4))
#define PWMB_OC5REFFrozen()             PWMB_SetOC5OutputMode(0)
#define PWMB_OC5REFHighIfMatch()        PWMB_SetOC5OutputMode(1)
#define PWMB_OC5REFLowIfMatch()         PWMB_SetOC5OutputMode(2)
#define PWMB_OC5REFToggleIfMatch()      PWMB_SetOC5OutputMode(3)
#define PWMB_OC5REFForceLow()           PWMB_SetOC5OutputMode(4)
#define PWMB_OC5REFForceHigh()          PWMB_SetOC5OutputMode(5)
#define PWMB_OC5REFPWMMode1()           PWMB_SetOC5OutputMode(6)
#define PWMB_OC5REFPWMMode2()           PWMB_SetOC5OutputMode(7)

#define PWMBCCMR1_OC5PE_MSK             BIT3
#define PWMB_UnbufferCCR5()             CLR_REG_BIT(PWMB_CCMR1, PWMBCCMR1_OC5PE_MSK)
#define PWMB_BufferCCR5()               SET_REG_BIT(PWMB_CCMR1, PWMBCCMR1_OC5PE_MSK)

#define PWMBCCMR1_OC5FE_MSK             BIT2
#define PWMB_DisableOC5FastMode()       CLR_REG_BIT(PWMB_CCMR1, PWMBCCMR1_OC5FE_MSK)
#define PWMB_EnableOC5FastMode()        SET_REG_BIT(PWMB_CCMR1, PWMBCCMR1_OC5FE_MSK)

#define PWMBCCMR1_CC5S_MSK              (BIT1 | BIT0)
#define PWMB_SetCC5Mode(n)              MODIFY_REG(PWMB_CCMR1,  PWMBCCMR1_CC5S_MSK, ((n) << 0))
#define PWMB_CC5Output()                PWMB_SetCC5Mode(0)
#define PWMB_CC5CaptureTI5FP5()         PWMB_SetCC5Mode(1)
#define PWMB_CC5CaptureTI6FP5()         PWMB_SetCC5Mode(2)
#define PWMB_CC5CaptureTRC()            PWMB_SetCC5Mode(3)

#define PWMBCCMR1_IC5F_MSK              (BIT_HN)
#define PWMB_SetIC5Filter(n)            MODIFY_REG(PWMB_CCMR1,  PWMBCCMR1_IC5F_MSK, ((n) << 4))
#define PWMB_IC5Filter1()               PWMB_SetIC5Filter(0)
#define PWMB_IC5Filter2()               PWMB_SetIC5Filter(1)
#define PWMB_IC5Filter4()               PWMB_SetIC5Filter(2)
#define PWMB_IC5Filter8()               PWMB_SetIC5Filter(3)
#define PWMB_IC5Filter12()              PWMB_SetIC5Filter(4)
#define PWMB_IC5Filter16()              PWMB_SetIC5Filter(5)
#define PWMB_IC5Filter24()              PWMB_SetIC5Filter(6)
#define PWMB_IC5Filter32()              PWMB_SetIC5Filter(7)
#define PWMB_IC5Filter48()              PWMB_SetIC5Filter(8)
#define PWMB_IC5Filter64()              PWMB_SetIC5Filter(9)
#define PWMB_IC5Filter80()              PWMB_SetIC5Filter(10)
#define PWMB_IC5Filter96()              PWMB_SetIC5Filter(11)
#define PWMB_IC5Filter128()             PWMB_SetIC5Filter(12)
#define PWMB_IC5Filter160()             PWMB_SetIC5Filter(13)
#define PWMB_IC5Filter192()             PWMB_SetIC5Filter(14)
#define PWMB_IC5Filter256()             PWMB_SetIC5Filter(15)

#define PWMBCCMR1_IC5PS_MSK             (BIT3 | BIT2)
#define PWMB_SetIC5Divider(n)           MODIFY_REG(PWMB_CCMR1,  PWMBCCMR1_IC5PS_MSK, ((n) << 2))
#define PWMB_IC5Divider1()              PWMB_SetIC5Divider(0)
#define PWMB_IC5Divider2()              PWMB_SetIC5Divider(1)
#define PWMB_IC5Divider4()              PWMB_SetIC5Divider(2)
#define PWMB_IC5Divider8()              PWMB_SetIC5Divider(3)

#define PWMBCCMR2_OC6CE_MSK             BIT7
#define PWMB_EnableETRFClearOC6REF()    SET_REG_BIT(PWMB_CCMR2, PWMBCCMR2_OC6CE_MSK)
#define PWMB_DisableETRFClearOC6REF()   CLR_REG_BIT(PWMB_CCMR2, PWMBCCMR2_OC6CE_MSK)

#define PWMBCCMR2_OC6M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMB_SetOC6OutputMode(n)        MODIFY_REG(PWMB_CCMR2,  PWMBCCMR2_OC6M_MSK, ((n) << 4))
#define PWMB_OC6REFFrozen()             PWMB_SetOC6OutputMode(0)
#define PWMB_OC6REFHighIfMatch()        PWMB_SetOC6OutputMode(1)
#define PWMB_OC6REFLowIfMatch()         PWMB_SetOC6OutputMode(2)
#define PWMB_OC6REFToggleIfMatch()      PWMB_SetOC6OutputMode(3)
#define PWMB_OC6REFForceLow()           PWMB_SetOC6OutputMode(4)
#define PWMB_OC6REFForceHigh()          PWMB_SetOC6OutputMode(5)
#define PWMB_OC6REFPWMMode1()           PWMB_SetOC6OutputMode(6)
#define PWMB_OC6REFPWMMode2()           PWMB_SetOC6OutputMode(7)

#define PWMBCCMR2_OC6PE_MSK             BIT3
#define PWMB_UnbufferCCR6()             CLR_REG_BIT(PWMB_CCMR2, PWMBCCMR2_OC6PE_MSK)
#define PWMB_BufferCCR6()               SET_REG_BIT(PWMB_CCMR2, PWMBCCMR2_OC6PE_MSK)

#define PWMBCCMR2_OC6FE_MSK             BIT2
#define PWMB_DisableOC6FastMode()       CLR_REG_BIT(PWMB_CCMR2, PWMBCCMR2_OC6FE_MSK)
#define PWMB_EnableOC6FastMode()        SET_REG_BIT(PWMB_CCMR2, PWMBCCMR2_OC6FE_MSK)

#define PWMBCCMR2_CC6S_MSK              (BIT1 | BIT0)
#define PWMB_SetCC6Mode(n)              MODIFY_REG(PWMB_CCMR2,  PWMBCCMR2_CC6S_MSK, ((n) << 0))
#define PWMB_CC6Output()                PWMB_SetCC6Mode(0)
#define PWMB_CC6CaptureTI6FP6()         PWMB_SetCC6Mode(1)
#define PWMB_CC6CaptureTI5FP6()         PWMB_SetCC6Mode(2)
#define PWMB_CC6CaptureTRC()            PWMB_SetCC6Mode(3)

#define PWMBCCMR2_IC6F_MSK              (BIT_HN)
#define PWMB_SetIC6Filter(n)            MODIFY_REG(PWMB_CCMR2,  PWMBCCMR2_IC6F_MSK, ((n) << 4))
#define PWMB_IC6Filter1()               PWMB_SetIC6Filter(0)
#define PWMB_IC6Filter2()               PWMB_SetIC6Filter(1)
#define PWMB_IC6Filter4()               PWMB_SetIC6Filter(2)
#define PWMB_IC6Filter8()               PWMB_SetIC6Filter(3)
#define PWMB_IC6Filter12()              PWMB_SetIC6Filter(4)
#define PWMB_IC6Filter16()              PWMB_SetIC6Filter(5)
#define PWMB_IC6Filter24()              PWMB_SetIC6Filter(6)
#define PWMB_IC6Filter32()              PWMB_SetIC6Filter(7)
#define PWMB_IC6Filter48()              PWMB_SetIC6Filter(8)
#define PWMB_IC6Filter64()              PWMB_SetIC6Filter(9)
#define PWMB_IC6Filter80()              PWMB_SetIC6Filter(10)
#define PWMB_IC6Filter96()              PWMB_SetIC6Filter(11)
#define PWMB_IC6Filter128()             PWMB_SetIC6Filter(12)
#define PWMB_IC6Filter160()             PWMB_SetIC6Filter(13)
#define PWMB_IC6Filter192()             PWMB_SetIC6Filter(14)
#define PWMB_IC6Filter256()             PWMB_SetIC6Filter(15)

#define PWMBCCMR2_IC6PS_MSK             (BIT3 | BIT2)
#define PWMB_SetIC6Divider(n)           MODIFY_REG(PWMB_CCMR2,  PWMBCCMR2_IC6PS_MSK, ((n) << 2))
#define PWMB_IC6Divider1()              PWMB_SetIC6Divider(0)
#define PWMB_IC6Divider2()              PWMB_SetIC6Divider(1)
#define PWMB_IC6Divider4()              PWMB_SetIC6Divider(2)
#define PWMB_IC6Divider8()              PWMB_SetIC6Divider(3)

#define PWMBCCMR3_OC7CE_MSK             BIT7
#define PWMB_EnableETRFClearOC7REF()    SET_REG_BIT(PWMB_CCMR3, PWMBCCMR3_OC7CE_MSK)
#define PWMB_DisableETRFClearOC7REF()   CLR_REG_BIT(PWMB_CCMR3, PWMBCCMR3_OC7CE_MSK)

#define PWMBCCMR3_OC7M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMB_SetOC7OutputMode(n)        MODIFY_REG(PWMB_CCMR3,  PWMBCCMR3_OC7M_MSK, ((n) << 4))
#define PWMB_OC7REFFrozen()             PWMB_SetOC7OutputMode(0)
#define PWMB_OC7REFHighIfMatch()        PWMB_SetOC7OutputMode(1)
#define PWMB_OC7REFLowIfMatch()         PWMB_SetOC7OutputMode(2)
#define PWMB_OC7REFToggleIfMatch()      PWMB_SetOC7OutputMode(3)
#define PWMB_OC7REFForceLow()           PWMB_SetOC7OutputMode(4)
#define PWMB_OC7REFForceHigh()          PWMB_SetOC7OutputMode(5)
#define PWMB_OC7REFPWMMode1()           PWMB_SetOC7OutputMode(6)
#define PWMB_OC7REFPWMMode2()           PWMB_SetOC7OutputMode(7)

#define PWMBCCMR3_OC7PE_MSK             BIT3
#define PWMB_UnbufferCCR7()             CLR_REG_BIT(PWMB_CCMR3, PWMBCCMR3_OC7PE_MSK)
#define PWMB_BufferCCR7()               SET_REG_BIT(PWMB_CCMR3, PWMBCCMR3_OC7PE_MSK)

#define PWMBCCMR3_OC7FE_MSK             BIT2
#define PWMB_DisableOC7FastMode()       CLR_REG_BIT(PWMB_CCMR3, PWMBCCMR3_OC7FE_MSK)
#define PWMB_EnableOC7FastMode()        SET_REG_BIT(PWMB_CCMR3, PWMBCCMR3_OC7FE_MSK)

#define PWMBCCMR3_CC7S_MSK              (BIT1 | BIT0)
#define PWMB_SetCC7Mode(n)              MODIFY_REG(PWMB_CCMR3,  PWMBCCMR3_CC7S_MSK, ((n) << 0))
#define PWMB_CC7Output()                PWMB_SetCC7Mode(0)
#define PWMB_CC7CaptureTI7FP7()         PWMB_SetCC7Mode(1)
#define PWMB_CC7CaptureTI8FP7()         PWMB_SetCC7Mode(2)
#define PWMB_CC7CaptureTRC()            PWMB_SetCC7Mode(3)

#define PWMBCCMR3_IC7F_MSK              (BIT_HN)
#define PWMB_SetIC7Filter(n)            MODIFY_REG(PWMB_CCMR3,  PWMBCCMR3_IC7F_MSK, ((n) << 4))
#define PWMB_IC7Filter1()               PWMB_SetIC7Filter(0)
#define PWMB_IC7Filter2()               PWMB_SetIC7Filter(1)
#define PWMB_IC7Filter4()               PWMB_SetIC7Filter(2)
#define PWMB_IC7Filter8()               PWMB_SetIC7Filter(3)
#define PWMB_IC7Filter12()              PWMB_SetIC7Filter(4)
#define PWMB_IC7Filter16()              PWMB_SetIC7Filter(5)
#define PWMB_IC7Filter24()              PWMB_SetIC7Filter(6)
#define PWMB_IC7Filter32()              PWMB_SetIC7Filter(7)
#define PWMB_IC7Filter48()              PWMB_SetIC7Filter(8)
#define PWMB_IC7Filter64()              PWMB_SetIC7Filter(9)
#define PWMB_IC7Filter80()              PWMB_SetIC7Filter(10)
#define PWMB_IC7Filter96()              PWMB_SetIC7Filter(11)
#define PWMB_IC7Filter128()             PWMB_SetIC7Filter(12)
#define PWMB_IC7Filter160()             PWMB_SetIC7Filter(13)
#define PWMB_IC7Filter192()             PWMB_SetIC7Filter(14)
#define PWMB_IC7Filter256()             PWMB_SetIC7Filter(15)

#define PWMBCCMR3_IC7PS_MSK             (BIT3 | BIT2)
#define PWMB_SetIC7Divider(n)           MODIFY_REG(PWMB_CCMR3,  PWMBCCMR3_IC7PS_MSK, ((n) << 2))
#define PWMB_IC7Divider1()              PWMB_SetIC7Divider(0)
#define PWMB_IC7Divider2()              PWMB_SetIC7Divider(1)
#define PWMB_IC7Divider4()              PWMB_SetIC7Divider(2)
#define PWMB_IC7Divider8()              PWMB_SetIC7Divider(3)

#define PWMBCCMR4_OC8CE_MSK             BIT7
#define PWMB_EnableETRFClearOC8REF()    SET_REG_BIT(PWMB_CCMR4, PWMBCCMR4_OC8CE_MSK)
#define PWMB_DisableETRFClearOC8REF()   CLR_REG_BIT(PWMB_CCMR4, PWMBCCMR4_OC8CE_MSK)

#define PWMBCCMR4_OC8M_MSK              (BIT6 | BIT5 | BIT4)
#define PWMB_SetOC8OutputMode(n)        MODIFY_REG(PWMB_CCMR4,  PWMBCCMR4_OC8M_MSK, ((n) << 4))
#define PWMB_OC8REFFrozen()             PWMB_SetOC8OutputMode(0)
#define PWMB_OC8REFHighIfMatch()        PWMB_SetOC8OutputMode(1)
#define PWMB_OC8REFLowIfMatch()         PWMB_SetOC8OutputMode(2)
#define PWMB_OC8REFToggleIfMatch()      PWMB_SetOC8OutputMode(3)
#define PWMB_OC8REFForceLow()           PWMB_SetOC8OutputMode(4)
#define PWMB_OC8REFForceHigh()          PWMB_SetOC8OutputMode(5)
#define PWMB_OC8REFPWMMode1()           PWMB_SetOC8OutputMode(6)
#define PWMB_OC8REFPWMMode2()           PWMB_SetOC8OutputMode(7)

#define PWMBCCMR4_OC8PE_MSK             BIT3
#define PWMB_UnbufferCCR8()             CLR_REG_BIT(PWMB_CCMR4, PWMBCCMR4_OC8PE_MSK)
#define PWMB_BufferCCR8()               SET_REG_BIT(PWMB_CCMR4, PWMBCCMR4_OC8PE_MSK)

#define PWMBCCMR4_OC8FE_MSK             BIT2
#define PWMB_DisableOC8FastMode()       CLR_REG_BIT(PWMB_CCMR4, PWMBCCMR4_OC8FE_MSK)
#define PWMB_EnableOC8FastMode()        SET_REG_BIT(PWMB_CCMR4, PWMBCCMR4_OC8FE_MSK)

#define PWMBCCMR4_CC8S_MSK              (BIT1 | BIT0)
#define PWMB_SetCC8Mode(n)              MODIFY_REG(PWMB_CCMR4,  PWMBCCMR4_CC8S_MSK, ((n) << 0))
#define PWMB_CC8Output()                PWMB_SetCC8Mode(0)
#define PWMB_CC8CaptureTI8FP8()         PWMB_SetCC8Mode(1)
#define PWMB_CC8CaptureTI7FP8()         PWMB_SetCC8Mode(2)
#define PWMB_CC8CaptureTRC()            PWMB_SetCC8Mode(3)

#define PWMBCCMR4_IC8F_MSK              (BIT_HN)
#define PWMB_SetIC8Filter(n)            MODIFY_REG(PWMB_CCMR4,  PWMBCCMR4_IC8F_MSK, ((n) << 4))
#define PWMB_IC8Filter1()               PWMB_SetIC8Filter(0)
#define PWMB_IC8Filter2()               PWMB_SetIC8Filter(1)
#define PWMB_IC8Filter4()               PWMB_SetIC8Filter(2)
#define PWMB_IC8Filter8()               PWMB_SetIC8Filter(3)
#define PWMB_IC8Filter12()              PWMB_SetIC8Filter(4)
#define PWMB_IC8Filter16()              PWMB_SetIC8Filter(5)
#define PWMB_IC8Filter24()              PWMB_SetIC8Filter(6)
#define PWMB_IC8Filter32()              PWMB_SetIC8Filter(7)
#define PWMB_IC8Filter48()              PWMB_SetIC8Filter(8)
#define PWMB_IC8Filter64()              PWMB_SetIC8Filter(9)
#define PWMB_IC8Filter80()              PWMB_SetIC8Filter(10)
#define PWMB_IC8Filter96()              PWMB_SetIC8Filter(11)
#define PWMB_IC8Filter128()             PWMB_SetIC8Filter(12)
#define PWMB_IC8Filter160()             PWMB_SetIC8Filter(13)
#define PWMB_IC8Filter192()             PWMB_SetIC8Filter(14)
#define PWMB_IC8Filter256()             PWMB_SetIC8Filter(15)

#define PWMBCCMR4_IC8PS_MSK             (BIT3 | BIT2)
#define PWMB_SetIC8Divider(n)           MODIFY_REG(PWMB_CCMR4,  PWMBCCMR4_IC8PS_MSK, ((n) << 2))
#define PWMB_IC8Divider1()              PWMB_SetIC8Divider(0)
#define PWMB_IC8Divider2()              PWMB_SetIC8Divider(1)
#define PWMB_IC8Divider4()              PWMB_SetIC8Divider(2)
#define PWMB_IC8Divider8()              PWMB_SetIC8Divider(3)

#define PWMBCCER1_CC5E_MSK              BIT0
#define PWMB_CC5PEnable()               SET_REG_BIT(PWMB_CCER1, PWMBCCER1_CC5E_MSK)
#define PWMB_CC5PDisable()              CLR_REG_BIT(PWMB_CCER1, PWMBCCER1_CC5E_MSK)

#define PWMBCCER1_CC5P_MSK              BIT1
#define PWMB_CC5PNonInverted()          CLR_REG_BIT(PWMB_CCER1, PWMBCCER1_CC5P_MSK)
#define PWMB_CC5PInverted()             SET_REG_BIT(PWMB_CCER1, PWMBCCER1_CC5P_MSK)

#define PWMBCCER1_CC6E_MSK              BIT4
#define PWMB_CC6PEnable()               SET_REG_BIT(PWMB_CCER1, PWMBCCER1_CC6E_MSK)
#define PWMB_CC6PDisable()              CLR_REG_BIT(PWMB_CCER1, PWMBCCER1_CC6E_MSK)

#define PWMBCCER1_CC6P_MSK              BIT5
#define PWMB_CC6PNonInverted()          CLR_REG_BIT(PWMB_CCER1, PWMBCCER1_CC6P_MSK)
#define PWMB_CC6PInverted()             SET_REG_BIT(PWMB_CCER1, PWMBCCER1_CC6P_MSK)

#define PWMBCCER2_CC7E_MSK              BIT0
#define PWMB_CC7PEnable()               SET_REG_BIT(PWMB_CCER2, PWMBCCER2_CC7E_MSK)
#define PWMB_CC7PDisable()              CLR_REG_BIT(PWMB_CCER2, PWMBCCER2_CC7E_MSK)

#define PWMBCCER2_CC7P_MSK              BIT1
#define PWMB_CC7PNonInverted()          CLR_REG_BIT(PWMB_CCER2, PWMBCCER2_CC7P_MSK)
#define PWMB_CC7PInverted()             SET_REG_BIT(PWMB_CCER2, PWMBCCER2_CC7P_MSK)

#define PWMBCCER2_CC8E_MSK              BIT4
#define PWMB_CC8PEnable()               SET_REG_BIT(PWMB_CCER2, PWMBCCER2_CC8E_MSK)
#define PWMB_CC8PDisable()              CLR_REG_BIT(PWMB_CCER2, PWMBCCER2_CC8E_MSK)

#define PWMBCCER2_CC8P_MSK              BIT5
#define PWMB_CC8PNonInverted()          CLR_REG_BIT(PWMB_CCER2, PWMBCCER2_CC8P_MSK)
#define PWMB_CC8PInverted()             SET_REG_BIT(PWMB_CCER2, PWMBCCER2_CC8P_MSK)

#define PWMBBRK_MOE_MSK                 BIT7
#define PWMB_EnableMainOutput()         SET_REG_BIT(PWMB_BKR, PWMBBRK_MOE_MSK)
#define PWMB_DisableMainOutput()        CLR_REG_BIT(PWMB_BKR, PWMBBRK_MOE_MSK)

#define PWMBBRK_AOE_MSK                 BIT6
#define PWMB_EnableAutoOutput()         SET_REG_BIT(PWMB_BKR, PWMBBRK_AOE_MSK)
#define PWMB_DisableAutoOutput()        CLR_REG_BIT(PWMB_BKR, PWMBBRK_AOE_MSK)

#define PWMBBRK_BKP_MSK                 BIT5
#define PWMB_BRKNonInverted()           SET_REG_BIT(PWMB_BKR, PWMBBRK_BKP_MSK)
#define PWMB_BRKInverted()              CLR_REG_BIT(PWMB_BKR, PWMBBRK_BKP_MSK)

#define PWMBBRK_BKE_MSK                 BIT4
#define PWMB_BRKEnable()                SET_REG_BIT(PWMB_BKR, PWMBBRK_BKE_MSK)
#define PWMB_BRKDisable()               CLR_REG_BIT(PWMB_BKR, PWMBBRK_BKE_MSK)

#define PWMBBRK_OSSR_MSK                BIT3
#define PWMBBRK_OSSI_MSK                BIT2
#define PWMB_RunInactiveNoOutput()      CLR_REG_BIT(PWMB_BKR, PWMBBRK_OSSR_MSK)
#define PWMB_RunInactiveOutput()        SET_REG_BIT(PWMB_BKR, PWMBBRK_OSSR_MSK)
#define PWMB_IdleInactiveNoOutput()     CLR_REG_BIT(PWMB_BKR, PWMBBRK_OSSI_MSK)
#define PWMB_IdleInactiveOutput()       SET_REG_BIT(PWMB_BKR, PWMBBRK_OSSI_MSK)

#define PWMBBRK_LOCK_MSK                (BIT1 | BIT0)
#define PWMB_SetLockLevel(n)            MODIFY_REG(PWMB_BKR,  PWMBBRK_LOCK_MSK, ((n) << 0))
#define PWMB_SetUnLock()                PWMB_SetLockLevel(0)

#define PWMBOISR_OIS5_MSK               BIT0
#define PWMBOISR_OIS6_MSK               BIT2
#define PWMBOISR_OIS7_MSK               BIT4
#define PWMBOISR_OIS8_MSK               BIT6
#define PWMB_OC5PIdleLevelLow()         CLR_REG_BIT(PWMB_OISR, PWMBOISR_OIS5_MSK)
#define PWMB_OC5PIdleLevelHigh()        SET_REG_BIT(PWMB_OISR, PWMBOISR_OIS5_MSK)
#define PWMB_OC6PIdleLevelLow()         CLR_REG_BIT(PWMB_OISR, PWMBOISR_OIS6_MSK)
#define PWMB_OC6PIdleLevelHigh()        SET_REG_BIT(PWMB_OISR, PWMBOISR_OIS6_MSK)
#define PWMB_OC7PIdleLevelLow()         CLR_REG_BIT(PWMB_OISR, PWMBOISR_OIS7_MSK)
#define PWMB_OC7PIdleLevelHigh()        SET_REG_BIT(PWMB_OISR, PWMBOISR_OIS7_MSK)
#define PWMB_OC8PIdleLevelLow()         CLR_REG_BIT(PWMB_OISR, PWMBOISR_OIS8_MSK)
#define PWMB_OC8PIdleLevelHigh()        SET_REG_BIT(PWMB_OISR, PWMBOISR_OIS8_MSK)

#define PWMB_SetCounter(n)              (PWMB_CNTRH = HIBYTE(n), PWMB_CNTRL = LOBYTE(n))
#define PWMB_SetClockDivider(n)         (PWMB_PSCRH = HIBYTE(n), PWMB_PSCRL = LOBYTE(n))
#define PWMB_SetReload16(n)             (PWMB_ARRH = HIBYTE(n), PWMB_ARRL = LOBYTE(n))
//#define PWMB_SetRepeatCounter(n)      (PWMB_RCRH = HIBYTE(n), PWMB_RCR = LOBYTE(n))
#define PWMB_SetRepeatCounter(n)        (PWMB_RCR = LOBYTE(n))

#define PWMB_SetCCR5Value(n)            (PWMB_CCR5H = HIBYTE(n), PWMB_CCR5L = LOBYTE(n))
#define PWMB_SetCCR6Value(n)            (PWMB_CCR6H = HIBYTE(n), PWMB_CCR6L = LOBYTE(n))
#define PWMB_SetCCR7Value(n)            (PWMB_CCR7H = HIBYTE(n), PWMB_CCR7L = LOBYTE(n))
#define PWMB_SetCCR8Value(n)            (PWMB_CCR8H = HIBYTE(n), PWMB_CCR8L = LOBYTE(n))

#define PWMB_ReadReload16()            	MAKEWORD(PWMB_ARRL, PWMB_ARRH)

#define PWMB_ReadCCR5Value()            MAKEWORD(PWMB_CCR5L, PWMB_CCR5H)
#define PWMB_ReadCCR6Value()            MAKEWORD(PWMB_CCR6L, PWMB_CCR6H)
#define PWMB_ReadCCR7Value()            MAKEWORD(PWMB_CCR7L, PWMB_CCR7H)
#define PWMB_ReadCCR8Value()            MAKEWORD(PWMB_CCR8L, PWMB_CCR8H)

#define PWMB_SetDeadTime(n)             PWMB_DTR = LOBYTE(n)

/////////////////////////////////////////////////

#define DMA_M2M_SetAmount(d)            (DMA_M2M_AMTH = HIBYTE(d), DMA_M2M_AMT = LOBYTE(d))
#define DMA_M2M_SetTxAddress(d)         (DMA_M2M_TXAH = HIBYTE(d), DMA_M2M_TXAL = LOBYTE(d))
#define DMA_M2M_SetRxAddress(d)         (DMA_M2M_RXAH = HIBYTE(d), DMA_M2M_RXAL = LOBYTE(d))

#define DMAM2MCFG_M2MPTY_MSK            (BIT1 | BIT0)
#define DMA_M2M_SetBusPriority(n)       MODIFY_REG(DMA_M2M_CFG,  DMAM2MCFG_M2MPTY_MSK, ((n) << 0))

#define DMAM2MCR_ENM2M_MSK              BIT7
#define DMA_M2M_Enable()                SET_REG_BIT(DMA_M2M_CR, DMAM2MCR_ENM2M_MSK)

#define DMAM2MCR_TRIG_MSK               BIT6
#define DMA_M2M_Trigger()               SET_REG_BIT(DMA_M2M_CR, DMAM2MCR_TRIG_MSK)

/////////////////////////////////////////////////

#endif

