#include "fsm.h"

uint8 fsm_state = 0;

void (*pit_handler_fsm_ptr_map[])(void) = {
    //pit_handler_encoder,
    pit_handler_adc_print,
    //pit_handler_encoder_print,
    //pit_handler_imu660rb,
    //pit_handler_hornshell
};
void (*pit_handler_fsm_cond_map[])(uint8 *) = {
    //pit_handler_cond_common,
    pit_handler_cond_common,
//    pit_handler_cond_hornshell
};
void (*pit_handler_fsm_ptr)(void) = 0;

void pit_handler_fsm(void)
{

    pit_handler_fsm_ptr = pit_handler_fsm_ptr_map[fsm_state];
    pit_handler_fsm_ptr();
    pit_handler_fsm_cond_map[fsm_state](&fsm_state);
}

void pit_handler_cond_dec_one(uint8 *stat_fsm)
{

    *stat_fsm = (*stat_fsm + 1) % (sizeof(pit_handler_fsm_ptr_map) / sizeof(pit_handler_fsm_ptr_map[0]) - 1);
}

void pit_handler_cond_common(uint8 *stat_fsm)
{

    *stat_fsm = (*stat_fsm + 1) % (sizeof(pit_handler_fsm_ptr_map) / sizeof(pit_handler_fsm_ptr_map[0]));
}

void pit_handler_cond_hornshell(uint8 *stat_fsm)
{

    if (*stat_fsm == 2)
        return;

    if (gpio_get_level(IO_P32) == 0)
    {
        *stat_fsm = 2;     // hornshell
        //shell_uart_init(); // 初始化 shell UART 接收
    }
    else
    {
        pit_handler_cond_dec_one(stat_fsm);
    }
}