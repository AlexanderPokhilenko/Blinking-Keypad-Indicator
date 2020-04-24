#include "keyboard.h"
#include "delay.h"
#include "timer.h"
#include "indicator.h"

void (*HighFunction)() = indicator_turn_on_9;
void (*LowFunction)() = indicator_turn_off;

const uint16_t tau = 2;
const uint16_t T = 10;

int main()
{
	timer2_init(tau, T);
	
	keypad_init((uint16_t[3]){GPIO_Pin_9,GPIO_Pin_10,GPIO_Pin_11},(uint16_t[4]){GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15});
	
	indicator_init();
	
	timer2_start();
	
	indicator_turn_on_9();
	
	while (1)
	{
		HighFunction = keypad_get_function();
		
		delay_ms(100);
	}
}
