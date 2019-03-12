#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f10x.h"

#include "delay.h"
#include "system.h"
#include "usart.h"
#include "figure.h"
#include "lcd.h"
#include "led.h"
#include "beep.h"
#include "exti.h"
#include "servo.h"
#include "timer.h"
#include "loop.h"
#include "adc.h"
#include "dht11.h"
#include "fire.h"
#include "smoke.h"

typedef struct {
				u8 Mark_0;	//执行识别
				u8 Mark_1;	//执行录入指纹
				u8 Mark_2;	//执行删除所有指纹
				u8 Mark_3;	//待定……

         }Mark_t;
extern Mark_t mark;	  //程序执行标志位【外部变量】


 


/*通过拨码开关对任务进行选择*/
#define KEY1 PAin(5)   //PA5  
#define KEY2 PAin(6)   //PA6  
#define KEY3 PAin(7)   //PA7  
#define KEY4 PAin(8)   //PA8  

#endif
