/*
 * LCD_Driver.h
 *
 *  Created on: Apr 15, 2026
 *      Author: Abdullah Ahmed
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "I2C_Driver.h"

void LCD_Init(I2C_RegDef_t* pI2Cx);

void LCD_SendCMD(I2C_RegDef_t* pI2Cx, uint8_t cmd);
void LCD_SendByte(I2C_RegDef_t* pI2Cx, uint8_t data);

#endif /* LCD_DRIVER_H_ */
