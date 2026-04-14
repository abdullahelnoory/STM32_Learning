/*
 * AFIO_Driver.h
 *
 *  Created on: Feb 14, 2026
 *      Author: Abdullah Ahmed
 */

#ifndef AFIO_DRIVER_H_
#define AFIO_DRIVER_H_

#include "stm32f1xx.h"

void AFIO_Clock_Control(uint8_t value);
void AFIO_Set_EXTI_Pin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber);
void AFIO_Clear_EXTI_Pin(uint8_t PinNumber);

void AFIO_DeInit();

#endif /* AFIO_DRIVER_H_ */
