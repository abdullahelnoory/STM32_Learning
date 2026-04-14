/*
 * EXTI_Driver.h
 *
 *  Created on: Feb 14, 2026
 *      Author: Abdullah Ahmed
 */

#ifndef EXTI_DRIVER_H_
#define EXTI_DRIVER_H_

#include "stm32f1xx.h"

void Mask_Interrupt_Request(uint8_t LineNumber, uint8_t value);
void Select_Rising_Trigger(uint8_t LineNumber, uint8_t value);
void Select_Falling_Trigger(uint8_t LineNumber, uint8_t value);
uint8_t Check_Request_Occurence(uint8_t LineNumber);
void Clear_Interrupt_Flag(uint8_t LineNumber);

#endif /* EXTI_DRIVER_H_ */
