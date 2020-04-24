#ifndef _INDICATOR_H
#define _INDICATOR_H
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void indicator_init(void);

void indicator_turn_off(void);

void indicator_turn_on_1(void);
void indicator_turn_on_2(void);
void indicator_turn_on_3(void);
void indicator_turn_on_4(void);
void indicator_turn_on_5(void);
void indicator_turn_on_6(void);
void indicator_turn_on_7(void);
void indicator_turn_on_8(void);
void indicator_turn_on_9(void);
void indicator_turn_on_asterisk(void);
void indicator_turn_on_sharp(void);

#endif
