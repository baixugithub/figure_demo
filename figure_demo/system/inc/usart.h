#ifndef __USART_H
#define __USART_H
#include "stdio.h"
#include "system.h"


void uart_init(u32 bound);
void USART_Config(u32 bound);
//串口发送信息,通过查询方式发送一个字符
void USART2_SendByte(unsigned char dat);
// 从 USART2 读取一个字节
unsigned char USART2_ReceivByte(void);


#endif
