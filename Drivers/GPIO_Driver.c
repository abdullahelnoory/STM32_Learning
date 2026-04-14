/*
 * GPIO_Driver.c
 *
 *  Created on: Jan 27, 2026
 *      Author: Abdullah Ahmed
 */

#include "GPIO_Driver.h"

void GPIO_Init(GPIO_RegDef_t *pGPIOx,
			   uint8_t GPIO_PinNumber,
			   uint8_t GPIO_PinMode)
{
	uint32_t tempReg = 0;

	if(GPIO_PinNumber < 8)
	{
		tempReg |= (GPIO_PinMode << 4*GPIO_PinNumber);
		pGPIOx->CR[0] &= ~(15 << 4*GPIO_PinNumber);
		pGPIOx->CR[0] |= tempReg;
	}
	else
	{
		tempReg |= (GPIO_PinMode << 4*(GPIO_PinNumber - 8));
		pGPIOx->CR[1] &= ~(15 << 4*GPIO_PinNumber);
		pGPIOx->CR[1] |= tempReg;
	}
}

void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_Clk_En();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_Clk_En();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_Clk_En();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_Clk_En();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_Clk_En();
		}
	}
	else if(EnorDi == DISABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_Clk_Di();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_Clk_Di();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_Clk_Di();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_Clk_Di();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_Clk_Di();
		}
	}
}

uint8_t GPIO_ReadFromIn_Pin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber)
{
	uint8_t value = 0;
	value = ((pGPIOx->IDR) >> GPIO_PinNumber) & 0x00000001;
	return value;
}

uint16_t GPIO_ReadFromIn_Port(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value = 0;
	value = pGPIOx->IDR;
	return value;
}

void GPIO_WriteToOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber, uint8_t value)
{
	if(value == 1)
	{
		pGPIOx->ODR |= (1 << GPIO_PinNumber);
	}
	else if(value == 0)
	{
		pGPIOx->ODR &= ~(1 << GPIO_PinNumber);
	}
}

void GPIO_WriteToOut_Port(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}

void GPIO_ToggleOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber)
{
	pGPIOx->ODR ^= (1 << GPIO_PinNumber);
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		(RCC)->APB2RSTR |= (1 << 2);
	}
	else if(pGPIOx == GPIOB)
	{
		(RCC)->APB2RSTR |= (1 << 3);
	}
	else if(pGPIOx == GPIOC)
	{
		(RCC)->APB2RSTR |= (1 << 4);
	}
	else if(pGPIOx == GPIOD)
	{
		(RCC)->APB2RSTR |= (1 << 5);
	}
	else if(pGPIOx == GPIOE)
	{
		(RCC)->APB2RSTR |= (1 << 6);
	}
}
