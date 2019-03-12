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
				u8 Mark_0;	//ִ��ʶ��
				u8 Mark_1;	//ִ��¼��ָ��
				u8 Mark_2;	//ִ��ɾ������ָ��
				u8 Mark_3;	//��������

         }Mark_t;
extern Mark_t mark;	  //����ִ�б�־λ���ⲿ������


 


/*ͨ�����뿪�ض��������ѡ��*/
#define KEY1 PAin(5)   //PA5  
#define KEY2 PAin(6)   //PA6  
#define KEY3 PAin(7)   //PA7  
#define KEY4 PAin(8)   //PA8  

#endif
