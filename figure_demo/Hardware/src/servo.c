#include "include.h"

u8 Instruction,Checkout,Id;
u8 final[11];
u8 paramenter_ang_spe[4]; 

u8 calculate_checkout(void)	  //����У����
{
	u8 checkout;
	checkout=~(Id+0x07+0x03+0x1e+paramenter_ang_spe[0]+paramenter_ang_spe[1]+paramenter_ang_spe[2]+paramenter_ang_spe[3]);
/*	if(num>255)
	{
		num=num&0x00ff;
	}  
	checkout=~num; */
	return checkout;
}
//

void ang_spe_set(u8 id,u16 ang,u16 spe)   //����ID  �Ƕ� �ٶ�
{
	u8 a1,a2,s1,s2;
	Id=id;

	a1=ang/255;	  //˫�ֽ�ʮ���Ʒֽ�Ϊ���ֽ�ʮ������
	a2=ang%255;
	s1=spe/255;
	s2=spe%255;
	paramenter_ang_spe[0]=a2;		
	paramenter_ang_spe[1]=a1;
	paramenter_ang_spe[2]=s2;
	paramenter_ang_spe[3]=s1;	
	complete();
	transmitdata(11);
}
//

void complete(void)	   //ȷ�������������
{
	 final[0]=0xff;
	 final[1]=0xff;
	 final[2]=Id;
	 final[3]=0x07;
	 final[4]=0x03;	 
	 final[5]=0x1e;
	 final[6]=paramenter_ang_spe[0];
	 final[7]=paramenter_ang_spe[1];	
	 final[8]=paramenter_ang_spe[2];
	 final[9]=paramenter_ang_spe[3];
	 final[10]=calculate_checkout();
	 
}
//
	
void transmitdata(u8 str)	 //���ڷ�������
{
    u8 index = 0;  
	 for (index=0;index<str;index++)	  
    {
        USART_SendData(USART1,final[index]);
        while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);

    }
//    while(str[index] != 0);  //����ַ���������־    
}
//
void Open_door(void)				//******************************����
{		
	u8 i=25;	
	while(i--)
	{ 
		ang_spe_set(0,512,500);delay_ms(30);//819
	}		  
}
//
void Close_door(void)				//******************************����
{		
	u8 i=25;	
	while(i--)
	{ 
		ang_spe_set(0,218,500);delay_ms(30);//500
	}		  
}

