#ifndef _LOOP_H_
#define _LOOP_H_
/* Includes ------------------------------------------------------------------*/
#include "include.h"


typedef struct {
	
	      u8 Loop_250Hz;	//4ms
	      u8 Loop_100Hz;	//10ms
	      u8 Loop_10Hz;		//50ms
	      u8 Loop_3s;		//3s
         }Flag_t;	//��־1

extern Flag_t flag;	   		//�ж��жϱ�־λ


void loop(void);
void Time_slice(void);	  //ʱ��Ƭ0


#endif /* _loop_H_ */



