#ifndef __LED_H
#define __LED_H	 
#include "stm32f10x.h"

//sbit red=   P2^7;//¼��ģʽָʾ�� 
//sbit green= P2^0;//ʶ��ģʽָʾ�� 

//LED�˿ڶ���
#define red PAout(8)// PA8	//��ɫ��  ¼�� ģʽ
#define green PDout(2)// PD2	//��ɫ��  ʶ�� ģʽ

void LED_Init(void);//��ʼ��

		 				    
#endif
