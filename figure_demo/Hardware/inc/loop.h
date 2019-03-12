#ifndef _LOOP_H_
#define _LOOP_H_
/* Includes ------------------------------------------------------------------*/
#include "include.h"


typedef struct {
	
	      u8 Loop_250Hz;	//4ms
	      u8 Loop_100Hz;	//10ms
	      u8 Loop_10Hz;		//50ms
	      u8 Loop_3s;		//3s
         }Flag_t;	//标志1

extern Flag_t flag;	   		//中断判断标志位


void loop(void);
void Time_slice(void);	  //时间片0


#endif /* _loop_H_ */



