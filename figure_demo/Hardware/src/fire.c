#include "include.h"

u8 Flag_Fire = 0; 
void FIRE_init(void)
{
	if(FIRE == 0)
	{
		 GPIO_SetBits(GPIOC,GPIO_Pin_13);  
		 delay_ms(100);
 		 GPIO_ResetBits(GPIOC,GPIO_Pin_13); 

	}

}
//
