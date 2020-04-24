#include "keyboard.h"
// in this example key saved you state

char keypad[numRow][numCol]=
{
	'1','2','3',
	'4','5','6',
	'7','8','9',
	'*','0','#'
};

void (*keypad_functions[numRow][numCol])()=
{
	indicator_turn_on_1,				indicator_turn_on_2,	indicator_turn_on_3,
	indicator_turn_on_4,				indicator_turn_on_5,	indicator_turn_on_6,
	indicator_turn_on_7,				indicator_turn_on_8,	indicator_turn_on_9,
	indicator_turn_on_asterisk,	indicator_turn_off,		indicator_turn_on_sharp
};

uint16_t row[numRow];
uint16_t col[numCol];
//char oldKey=KEYPAD_NO_PRESSED;
void (*previous_function)() = indicator_turn_on_9;

void keypad_init(uint16_t cols[numCol],uint16_t rows[numRow]){ 
		uint16_t colSum=0;
		uint16_t rowSum=0;
		for(int i=0;i<numCol;i++)
		{
			col[i]=cols[i];
			colSum=colSum | col[i];
		}
		for(int i=0;i<numRow;i++)
		{
			row[i]=rows[i];
			rowSum=rowSum | row[i];
		}
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);// BUS is ON
    GPIO_InitTypeDef      KEYPAD_COL_B_STRUCT; 
		//Init columns 
    KEYPAD_COL_B_STRUCT.GPIO_Pin = colSum; // KEEP HARD PINS                                       
    KEYPAD_COL_B_STRUCT.GPIO_Mode = GPIO_Mode_Out_OD;
		KEYPAD_COL_B_STRUCT.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &KEYPAD_COL_B_STRUCT);			
		// Init rows
		GPIO_InitTypeDef KEYPAD_ROW_B_STRUCT;
		KEYPAD_ROW_B_STRUCT.GPIO_Pin = rowSum; // KEEP HARD PINS 																				
		KEYPAD_ROW_B_STRUCT.GPIO_Mode = GPIO_Mode_IPU;
		KEYPAD_ROW_B_STRUCT.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &KEYPAD_ROW_B_STRUCT);
}


void (*keypad_get_function(void))()
{

	void (* res)() = (void *)0;
	for(int i=0;i<numCol;i++)
	{
		for(int k=0;k<numCol;k++)GPIO_SetBits(GPIOB, col[k]); 																				//Set all columns
		GPIO_ResetBits(GPIOB, col[i]);																																//Reset column which check now
		for(int k=0;k<numRow;k++)if(!GPIO_ReadInputDataBit(GPIOB, row[k]))res=keypad_functions[k][i]; //Check all rows
	}
	
	if(res != previous_function && res != (void *)0) //if key is difference with old key
	{
		previous_function = res;
		return res;
	}
	
	return previous_function;
}
