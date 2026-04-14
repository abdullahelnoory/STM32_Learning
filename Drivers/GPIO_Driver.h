/*
 * GPIO_Driver.h
 *
 *  Created on: Jan 26, 2026
 *      Author: Abdullah Ahmed
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f1xx.h"

//Clock Enable or Disable API

void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

//GPIO Init and GPIO Deinit

void GPIO_Init(GPIO_RegDef_t *pGPIOx,
			   uint8_t GPIO_PinNumber,
			   uint8_t GPIO_PinMode);

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

//Read Write

uint8_t GPIO_ReadFromIn_Pin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber);
uint16_t GPIO_ReadFromIn_Port(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber, uint8_t value);
void GPIO_WriteToOut_Port(GPIO_RegDef_t *pGPIOx, uint16_t value);

void GPIO_ToggleOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber);

#endif /* GPIO_DRIVER_H_ */
