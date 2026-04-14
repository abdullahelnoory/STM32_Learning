/*
 * NVIC.h
 *
 *  Created on: Feb 25, 2026
 *      Author: Abdullah Ahmed
 */

#ifndef NVIC_H_
#define NVIC_H_

#include "stm32f1xx.h"

void Enable_Interrupt(IRQn_type IRQn);
void Disable_Interrupt(IRQn_type IRQn);

#endif /* NVIC_H_ */
