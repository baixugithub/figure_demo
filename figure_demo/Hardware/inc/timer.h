#ifndef _TIME_H_
#define _TIME_H_
#include "stm32f10x.h"

#define EnTIMER  TIM_Cmd(TIM5,ENABLE)

void Nvic_Init(void);
void TIM5_Config(void);

#endif 
