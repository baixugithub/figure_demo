#ifndef _SERVO_H_
#define _SERVO_H_
	
#include "stm32f10x.h"
#include "delay.h"


void transmitdata(u8 str);	 //���ڷ�������
u8 calculate_checkout(void);
void ang_spe_set(u8 id,u16 ang,u16 spe);   //����ID  �Ƕ� �ٶ�
void complete(void);

void Open_door(void);
//
void Close_door(void);

#endif

