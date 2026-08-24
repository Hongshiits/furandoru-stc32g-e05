#ifndef GPIO_H
#define GPIO_H

#include "pt_headfile.h"

#define MOTOR_LEFT_DIR_PIN (IO_P35)
#define MOTOR_RIGHT_DIR_PIN (IO_P36)
#define MOTOR_UP_DIR_PIN (IO_P37)

void pt_gpio_init(void);

extern gpio_pin_enum mot_dir_pin_list[3];

#endif