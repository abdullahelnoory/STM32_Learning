/*
 * LCD_Driver.c
 *
 *  Created on: Apr 15, 2026
 *      Author: Abdullah Ahmed
 */


#include "LCD_Driver.h"

#include "GP_TIM_Driver.h"
#include "GPIO_Driver.h"

static void LCD_Delay(int delay_ms)
{
	GP_TIM_SetCount(TIM2, 0);
	GP_TIM_SetPrescaler(TIM2, 7199);
	GP_TIM_SetAutoReload(TIM2, 10 * delay_ms);
	while(!(GP_TIM_Status_Check(TIM2, 0)));
}

void LCD_Init(I2C_RegDef_t* pI2Cx)
{
	LCD_Delay(50);

	I2C_Start(pI2Cx, 0x27, 0);
	LCD_SendCMD(pI2Cx, 0x33);
	LCD_Delay(5);
	LCD_SendCMD(pI2Cx, 0x32);
	LCD_Delay(1);
	LCD_SendCMD(pI2Cx, 0x28);
	LCD_Delay(1);
	LCD_SendCMD(pI2Cx, 0x0C);
	LCD_Delay(1);
	LCD_SendCMD(pI2Cx, 0x01);
	LCD_Delay(2);
	I2C_Stop(pI2Cx);
}

void LCD_SendCMD(I2C_RegDef_t* pI2Cx, uint8_t cmd)
{
	uint8_t lowerNible = cmd & 0x0F;
	uint8_t upperNible = (cmd >> 4) & 0x0F;
	I2C_Write(pI2Cx, (upperNible << 4) | 0x0C);
	I2C_Write(pI2Cx, (upperNible << 4) | 0x08);
	I2C_Write(pI2Cx, (lowerNible << 4) | 0x0C);
	I2C_Write(pI2Cx, (lowerNible << 4) | 0x08);
}

void LCD_SendByte(I2C_RegDef_t* pI2Cx, uint8_t data)
{
	uint8_t lowerNible = data & 0x0F;
	uint8_t upperNible = (data >> 4) & 0x0F;
	I2C_Write(pI2Cx, (upperNible << 4) | 0x0D);
	I2C_Write(pI2Cx, (upperNible << 4) | 0x09);
	I2C_Write(pI2Cx, (lowerNible << 4) | 0x0D);
	I2C_Write(pI2Cx, (lowerNible << 4) | 0x09);
}
