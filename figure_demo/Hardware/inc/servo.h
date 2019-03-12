#ifndef _SERVO_H_
#define _SERVO_H_
	
#include "stm32f10x.h"
#include "delay.h"


void transmitdata(u8 str);	 //串口发送数组
u8 calculate_checkout(void);
void ang_spe_set(u8 id,u16 ang,u16 spe);   //设置ID  角度 速度
void complete(void);

void Open_door(void);
//
void Close_door(void);

#endif

