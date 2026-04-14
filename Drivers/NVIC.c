/*
 * NVIC.c
 *
 *  Created on: Feb 25, 2026
 *      Author: Abdullah Ahmed
 */

#include "NVIC.h"

void Enable_Interrupt(IRQn_type IRQn)
{
	(NVIC)->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

void Disable_Interrupt(IRQn_type IRQn)
{
	(NVIC)->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}
