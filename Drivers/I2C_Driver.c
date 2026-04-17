/*
 * I2C_Driver.c
 *
 *  Created on: Apr 14, 2026
 *      Author: Abdullah Ahmed
 */

#include "I2C_Driver.h"

void I2C_ClockControl(I2C_RegDef_t *pI2Cx, uint8_t value)
{
	if(value == ENABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_Clk_En();
		}
		else if(pI2Cx == I2C2)
		{
			I2C2_Clk_En();
		}
	}
	else if(value == DISABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_Clk_Di();
		}
		else if(pI2Cx == I2C2)
		{
			I2C2_Clk_Di();
		}
	}
}

void I2C_Init(I2C_RegDef_t *pI2Cx)
{
	pI2Cx->CR[0] &= ~(1 << 0);
	pI2Cx->CR[1] = (36 & 0x3F);
	pI2Cx->CCR = 180;
	pI2Cx->TRISE = 37;
	pI2Cx->CR[0] |= (1 << 0);
}

void I2C_Start(I2C_RegDef_t *pI2Cx, uint8_t address, uint8_t direction)
{
	pI2Cx->CR[0] |= (1 << 8);
	while(!(pI2Cx->SR[0] & (1 << 0))); //Starting

	pI2Cx->DR = (address << 1) | direction;
	while(!(pI2Cx->SR[0] & (1 << 1))); //Sending address
	(void)pI2Cx->SR[1]; //Clearing the address flag
}

void I2C_Stop(I2C_RegDef_t *pI2Cx)
{
	pI2Cx->CR[0] |= (1 << 9);
}

void I2C_Write(I2C_RegDef_t *pI2Cx, uint8_t data)
{
	while(!(pI2Cx->SR[0] & (1 << 7))); //Preparing the transmitter
	pI2Cx->DR = data;
	while(!(pI2Cx->SR[0] & (1 << 2))); //Sending the data
}

void I2C_WriteMultiple(I2C_RegDef_t *pI2Cx, uint8_t *data, uint16_t size)
{
	for(uint16_t i = 0; i < size; i++)
	{
		I2C_Write(pI2Cx, data[i]);
	}
}

uint8_t I2C_Read(I2C_RegDef_t *pI2Cx)
{
	pI2Cx->CR[0] &= ~(1 << 10); //Disable ACK
	while(!(pI2Cx->SR[0] & (1 << 6))); //Waiting for the data to be received
	return pI2Cx->DR;
}

void I2C_DeInit(I2C_RegDef_t *pI2Cx)
{
	if(pI2Cx == I2C1)
	{
		(RCC)->APB1RSTR |= (1 << 21);
	}
	else if(pI2Cx == I2C2)
	{
		(RCC)->APB1RSTR |= (1 << 22);
	}
}
