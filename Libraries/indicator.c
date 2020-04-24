#include "indicator.h"

const uint16_t indicator_pins = 0x3FE; // pins 1-9

void indicator_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = indicator_pins;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void indicator_turn_off(void)
{
	GPIO_ResetBits(GPIOA, indicator_pins);
}

void indicator_turn_on_1(void)
{
	GPIO_SetBits(GPIOA, 0x0002);
}

void indicator_turn_on_2(void)
{
	GPIO_SetBits(GPIOA, 0x0006);
}

void indicator_turn_on_3(void)
{
	GPIO_SetBits(GPIOA, 0x000E);
}

void indicator_turn_on_4(void)
{
	GPIO_SetBits(GPIOA, 0x001E);
}

void indicator_turn_on_5(void)
{
	GPIO_SetBits(GPIOA, 0x003E);
}

void indicator_turn_on_6(void)
{
	GPIO_SetBits(GPIOA, 0x007E);
}

void indicator_turn_on_7(void)
{
	GPIO_SetBits(GPIOA, 0x00FE);
}

void indicator_turn_on_8(void)
{
	GPIO_SetBits(GPIOA, 0x01FE);
}

void indicator_turn_on_9(void)
{
	GPIO_SetBits(GPIOA, 0x03FE);
}

void indicator_turn_on_asterisk(void)
{
	GPIO_SetBits(GPIOA, 0x00F8);
}

void indicator_turn_on_sharp(void)
{
	GPIO_SetBits(GPIOA, 0x02AA);
}
