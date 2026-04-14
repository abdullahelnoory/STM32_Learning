#ifndef GP_TIM_DRIVER_H
#define GP_TIM_DRIVER_H

#include "stm32f1xx.h"

void GP_TIM_Clock_Control(GP_TIM_RegDef_t* pGP_TIM,uint8_t value);

void GP_TIM_Control_Setting(GP_TIM_RegDef_t* pGP_TIM, uint8_t CountEnable, uint8_t AutoReloadPreloadEnable, uint8_t Direction);
void GP_TIM_Interrupt_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t InterruptType, uint8_t value);
uint8_t GP_TIM_Status_Check(GP_TIM_RegDef_t* pGP_TIM, uint8_t FlagType);
void GP_TIM_Event_Generation_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t EventType, uint8_t value);

//Capture/Compare Modes
void GP_TIM_Set_Channel_Selection(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t ChannelSelection);
void GP_TIM_Compare_Set_Mode(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t Mode);

//Capture/Compare Enable
void GP_TIM_Enable_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t value);
void GP_TIM_Polarity_Control(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint8_t value);

//Counter, Prescaler and Auto-Reload
uint16_t GP_TIM_ReadCount(GP_TIM_RegDef_t* pGP_TIM);
void GP_TIM_SetCount(GP_TIM_RegDef_t* pGP_TIM, uint16_t value);
void GP_TIM_SetPrescaler(GP_TIM_RegDef_t* pGP_TIM, uint16_t value);
void GP_TIM_SetAutoReload(GP_TIM_RegDef_t* pGP_TIM, uint16_t value);

//Capture/Compare values
uint16_t GP_TIM_ReadCaptureCompareValue(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber);
void  GP_TIM_SetCaptureCompareValue(GP_TIM_RegDef_t* pGP_TIM, uint8_t ChannelNumber, uint16_t value);

void GP_TIM_DeInit(GP_TIM_RegDef_t* pGP_TIM);

#endif
