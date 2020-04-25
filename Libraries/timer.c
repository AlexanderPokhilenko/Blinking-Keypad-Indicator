#include "timer.h"

uint16_t get_GCD(uint16_t a, uint16_t b)
{
	while (a != b)
	{
		if (a > b)
		{
			uint16_t tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}

static __IO uint16_t tauDelayCount;
static __IO uint16_t TDelayCount;
static __IO uint16_t currentDelayCount;

void timer_init(uint16_t tau, uint16_t T)
{
	uint16_t delay = get_GCD(tau, T);
	tauDelayCount = tau / delay;
	TDelayCount = T / delay;
	
	int32_t ms_delay = SystemCoreClock / 1000;
	
	if (SysTick_Config(ms_delay * delay)) while (1);
}

void SysTick_Handler(void)
{
	if(currentDelayCount == 0 && tauDelayCount > 0)
		{
			HighFunction();
		}
		else if(currentDelayCount == tauDelayCount)
		{
			LowFunction();
		}
		
		currentDelayCount++;
		
		if(currentDelayCount >= TDelayCount)
		{
			currentDelayCount = 0;
		}
}
