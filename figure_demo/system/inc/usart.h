#ifndef __USART_H
#define __USART_H
#include "stdio.h"
#include "system.h"


void uart_init(u32 bound);
void USART_Config(u32 bound);
//���ڷ�����Ϣ,ͨ����ѯ��ʽ����һ���ַ�
void USART2_SendByte(unsigned char dat);
// �� USART2 ��ȡһ���ֽ�
unsigned char USART2_ReceivByte(void);


#endif
