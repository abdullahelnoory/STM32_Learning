/*
 * I2C_Driver.h
 *
 *  Created on: Apr 2, 2026
 *      Author: Abdullah Ahmed
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "stm32f1xx.h"

void I2C_ClockControl(I2C_RegDef_t *pI2Cx, uint8_t value);

void I2C_Init(I2C_RegDef_t *pI2Cx);
void I2C_Start(I2C_RegDef_t *pI2Cx, uint8_t address, uint8_t direction);
void I2C_Stop(I2C_RegDef_t *pI2Cx);
void I2C_Write(I2C_RegDef_t *pI2Cx, uint8_t data);
void I2C_WriteMultiple(I2C_RegDef_t *pI2Cx, uint8_t *data, uint16_t size);
uint8_t I2C_Read(I2C_RegDef_t *pI2Cx);

void I2C_DeInit(I2C_RegDef_t *pI2Cx);


#endif /* I2C_DRIVER_H_ */
