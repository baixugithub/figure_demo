#ifndef _BEEP_H_
#define _BEEP_H_			   
#include "stm32f10x.h"
#include "delay.h"
#include "system.h"

#define buzzer PCout(5)	// buzzer,�������ӿ�		   

void BEEP_Init(void);	
void beep(void);


#endif 
