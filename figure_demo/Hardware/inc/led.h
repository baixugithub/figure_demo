#ifndef __LED_H
#define __LED_H	 
#include "stm32f10x.h"

//sbit red=   P2^7;//录入模式指示灯 
//sbit green= P2^0;//识别模式指示灯 

//LED端口定义
#define red PAout(8)// PA8	//红色灯  录入 模式
#define green PDout(2)// PD2	//绿色灯  识别 模式

void LED_Init(void);//初始化

		 				    
#endif
