#ifndef TIMER_H
#define TIMER_H
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>

void timer2_init(uint16_t tau, uint16_t T);

void timer2_start(void);
void timer2_stop(void);

extern void (*HighFunction)();
extern void (*LowFunction)();

#endif
