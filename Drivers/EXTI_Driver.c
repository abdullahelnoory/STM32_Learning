/*
 * EXTI_Driver.c
 *
 *  Created on: Feb 14, 2026
 *      Author: Abdullah Ahmed
 */

#include "EXTI_Driver.h"

void Mask_Interrupt_Request(uint8_t LineNumber, uint8_t value)
{
	if(value == ENABLE)
	{
		if(LineNumber >= 0 && LineNumber <= 19)
				(EXTI)->IMR |= (1 << LineNumber);
	}
	else if(value == DISABLE)
	{
		if(LineNumber >= 0 && LineNumber <= 19)
				(EXTI)->IMR &= ~(1 << LineNumber);
	}
}

void Select_Rising_Trigger(uint8_t LineNumber, uint8_t value)
{
	if(value == ENABLE)
	{
		if(LineNumber >= 0 && LineNumber <= 19)
			(EXTI)->RTSR |= (1 << LineNumber);
	}
	else if(value == DISABLE)
	{
		if(LineNumber >= 0 && LineNumber <= 19)
			(EXTI)->RTSR &= ~(1 << LineNumber);
	}
}

void Select_Falling_Trigger(uint8_t LineNumber, uint8_t value)
{
	if(value == ENABLE)
	{
		if(LineNumber >= 0 && LineNumber <= 19)
			(EXTI)->FTSR |= (1 << LineNumber);
	}
	else if(value == DISABLE)
	{
		if(LineNumber >= 0 && LineNumber <= 19)
			(EXTI)->FTSR &= ~(1 << LineNumber);
	}
}

uint8_t Check_Request_Occurence(uint8_t LineNumber)
{
	if(LineNumber >= 0 && LineNumber <= 19)
		return ((((EXTI)->PR) >> LineNumber) & 0x01);
	else
		return 0x00;
}

void Clear_Interrupt_Flag(uint8_t LineNumber)
{
	if(LineNumber >= 0 && LineNumber <= 19)
		(EXTI)->PR |= (1 << LineNumber);
}
