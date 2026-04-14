/*
 * AFIO_Driver.c
 *
 *  Created on: Feb 14, 2026
 *      Author: Abdullah Ahmed
 */

#include "AFIO_Driver.h"

void AFIO_Clock_Control(uint8_t value)
{
	if(value == ENABLE)
	{
		AFIO_Clk_En();
	}
	else if(value == DISABLE)
	{
		AFIO_Clk_Di();
	}
}

void AFIO_Set_EXTI_Pin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{
	uint8_t setValue = 0x00;
	if(pGPIOx == GPIOA)
		setValue = 0x00;
	else if(pGPIOx == GPIOB)
		setValue = 0x01;
	else if(pGPIOx == GPIOC)
			setValue = 0x02;
	else if(pGPIOx == GPIOD)
			setValue = 0x03;
	else if(pGPIOx == GPIOE)
			setValue = 0x04;

	if(PinNumber >= 0 && PinNumber <= 3)
	{
		(AFIO)->EXTICR1 &= ~(0x0F << (4 * PinNumber));
		(AFIO)->EXTICR1 |= (setValue << (4 * PinNumber));
	}
	else if(PinNumber >= 4 && PinNumber <= 7)
	{
		(AFIO)->EXTICR2 &= ~(0x0F << (4 * (PinNumber - 4)));
		(AFIO)->EXTICR2 |= (setValue << (4 * (PinNumber - 4)));
	}
	else if(PinNumber >= 8 && PinNumber <= 11)
	{
		(AFIO)->EXTICR3 &= ~(0x0F << (4 * (PinNumber - 8)));
		(AFIO)->EXTICR3 |= (setValue << (4 * (PinNumber - 8)));
	}
	else if(PinNumber >= 12 && PinNumber <= 15)
	{
		(AFIO)->EXTICR4 &= ~(0x0F << (4 * (PinNumber - 12)));
		(AFIO)->EXTICR4 |= (setValue << (4 * (PinNumber - 12)));
	}
}

void AFIO_Clear_EXTI_Pin(uint8_t PinNumber)
{
	if(PinNumber >= 0 && PinNumber <= 3)
		(AFIO)->EXTICR1 &= ~(0x0F << (4 * PinNumber));
	else if(PinNumber >= 4 && PinNumber <= 7)
		(AFIO)->EXTICR2 &= ~(0x0F << (4 * (PinNumber - 4)));
	else if(PinNumber >= 8 && PinNumber <= 11)
		(AFIO)->EXTICR3 &= ~(0x0F << (4 * (PinNumber - 8)));
	else if(PinNumber >= 12 && PinNumber <= 15)
		(AFIO)->EXTICR4 &= ~(0x0F << (4 * (PinNumber - 12)));
}

void AFIO_DeInit()
{
	(RCC)->APB2RSTR |= (1 << 0);
}
