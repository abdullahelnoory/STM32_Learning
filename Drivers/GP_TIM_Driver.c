/*
 * GP_TIM.c
 *
 *  Created on: Mar 6, 2026
 *      Author: Abdullah Ahmed
 */

#include "GP_TIM_Driver.h"

void GP_TIM_Clock_Control(GP_TIM_RegDef_t* pGP_TIM,uint8_t value)
{
	if(value == ENABLE)
	{
		if(pGP_TIM == TIM2)
		{
			TIM2_Clk_En();
		}
		else if(pGP_TIM == TIM3)
		{
			TIM3_Clk_En();
		}
		else if(pGP_TIM == TIM4)
		{
			TIM4_Clk_En();
		}
		else if(pGP_TIM == TIM5)
		{
			TIM5_Clk_En();
		}
	}
	else if(value == DISABLE)
	{
		if(pGP_TIM == TIM2)
		{
			TIM2_Clk_En();
		}
		else if(pGP_TIM == TIM3)
		{
			TIM3_Clk_En();
		}
		else if(pGP_TIM == TIM4)
		{
			TIM4_Clk_En();
		}
		else if(pGP_TIM == TIM5)
		{
			TIM5_Clk_En();
		}
	}
}

void GP_TIM_Control_Setting(GP_TIM_RegDef_t* pGP_TIM, uint8_t CountEnable, uint8_t AutoReloadPreloadEnable, uint8_t Direction)
{
	if(CountEnable == ENABLE)
	{
		pGP_TIM->CR[0] |= (1 << 0);
	}
	else if(CountEnable == DISABLE)
	{
		pGP_TIM->CR[0] &= ~(1 << 0);
	}

	if(AutoReloadPreloadEnable == ENABLE)
	{
		pGP_TIM->CR[0] |= (1 << 7);
	}
	else if(AutoReloadPreloadEnable == DISABLE)
	{
		pGP_TIM->CR[0] &= ~(1 << 7);
	}

	if(Direction == ENABLE)
	{
		pGP_TIM->CR[0] |= (1 << 4);
	}
	else if(Direction == DISABLE)
	{
		pGP_TIM->CR[0] &= ~(1 << 4);
	}
}

void GP_TIM_Interrupt_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t InterruptType, uint8_t value)
{
	if(value == ENABLE)
	{
		pGP_TIM->DIER |= (1 << InterruptType);
	}
	else if(value == DISABLE)
	{
		pGP_TIM->DIER &= ~(1 << InterruptType);
	}
}

uint8_t GP_TIM_Status_Check(GP_TIM_RegDef_t* pGP_TIM, uint8_t FlagType)
{
	uint8_t statusValue = ((pGP_TIM->SR >> FlagType) & 1);
	pGP_TIM->SR &= ~(1 << FlagType);
	return statusValue;
}

void GP_TIM_Event_Generation_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t EventType, uint8_t value)
{
	if(value == ENABLE)
	{
		pGP_TIM->EGR |= (1 << EventType);
	}
	else if(value == DISABLE)
	{
		pGP_TIM->EGR &= ~(1 << EventType);
	}
}

void GP_TIM_Set_Channel_Selection(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t ChannelSelection)
{
	ChannelSelection &= 0x03;
	if(ChannelNumber >= 1 && ChannelNumber <= 2)
	{
		pGP_TIM->CCMR[0] &= ~(3 << 8 * (ChannelNumber - 1));
		pGP_TIM->CCMR[0] |= (ChannelSelection << 8 * (ChannelNumber - 1));
	}
	else if(ChannelNumber > 2 && ChannelNumber <= 4)
	{
		pGP_TIM->CCMR[1] &= ~(3 << 8 * (ChannelNumber - 3));
		pGP_TIM->CCMR[1] |= (ChannelSelection << 8 * (ChannelNumber - 3));
	}
}

void GP_TIM_Compare_Set_Mode(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t Mode)
{
	Mode &= 0x07;
	if(ChannelNumber >= 1 && ChannelNumber <= 2)
	{
		pGP_TIM->CCMR[0] &= ~(7 << (8 * (ChannelNumber - 1) + 4));
		pGP_TIM->CCMR[0] |= (Mode << (8 * (ChannelNumber - 1) + 4));
	}
	else if(ChannelNumber > 2 && ChannelNumber <= 4)
	{
		pGP_TIM->CCMR[1] &= ~(7 << (8 * (ChannelNumber - 3) + 4));
		pGP_TIM->CCMR[1] |= (Mode << (8 * (ChannelNumber - 3) + 4));
	}
}

void GP_TIM_Enable_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t value)
{
	if(ChannelNumber > 0 && ChannelNumber <= 4)
	{
		if(value == ENABLE)
		{
			pGP_TIM->CCER |= (1 << ((ChannelNumber - 1) * 4));
		}
		else if(value == DISABLE)
		{
			pGP_TIM->CCER &= ~(1 << ((ChannelNumber - 1) * 4));
		}
	}
}

void GP_TIM_Polarity_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t value)
{
	if(ChannelNumber > 0 && ChannelNumber <= 4)
	{
		if(value == ENABLE)
		{
			pGP_TIM->CCER |= (1 << ((ChannelNumber - 1) * 4 + 1));
		}
		else if(value == DISABLE)
		{
			pGP_TIM->CCER &= ~(1 << ((ChannelNumber - 1) * 4 + 1));
		}
	}
}

uint16_t GP_TIM_ReadCount(GP_TIM_RegDef_t* pGP_TIM)
{
	return pGP_TIM->CNT;
}

void GP_TIM_SetCount(GP_TIM_RegDef_t* pGP_TIM, uint16_t value)
{
	pGP_TIM->CNT = value;
}

void GP_TIM_SetPrescaler(GP_TIM_RegDef_t* pGP_TIM, uint16_t value)
{
	pGP_TIM->PSC = value;
}

void GP_TIM_SetAutoReload(GP_TIM_RegDef_t* pGP_TIM, uint16_t value)
{
	pGP_TIM->ARR = value;
}

uint16_t GP_TIM_ReadCaptureCompareValue(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber)
{
	if(ChannelNumber > 0 && ChannelNumber <= 4)
		return pGP_TIM->CCR[ChannelNumber - 1];
	else
		return 0;
}

void  GP_TIM_SetCaptureCompareValue(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint16_t value)
{
	if(ChannelNumber > 0 && ChannelNumber <= 4)
	{
		pGP_TIM->CCR[ChannelNumber - 1] = value;
	}
}

void GP_TIM_DeInit(GP_TIM_RegDef_t* pGP_TIM)
{
	if(pGP_TIM == TIM2)
	{
		(RCC)->APB1RSTR |= (1 << 0);
	}
	else if(pGP_TIM == TIM3)
	{
		(RCC)->APB1RSTR |= (1 << 1);
	}
	else if(pGP_TIM == TIM4)
	{
		(RCC)->APB1RSTR |= (1 << 2);
	}
	else if(pGP_TIM == TIM5)
	{
		(RCC)->APB1RSTR |= (1 << 3);
	}
}


