#ifndef __FIRE_H
#define __FIRE_H 			   
#include "include.h"


#define FIRE  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//��ȡ
void FIRE_init(void);

#endif
