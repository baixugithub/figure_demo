#include "include.h"

Mark_t mark;	  //����ִ�б�־λ���ⲿ������

int main(void)
{
	
	delay_init(72);	     //��ʱ��ʼ��
	uart_init(115200);//���ڳ�ʼ��Ϊ9600
	USART_Config(9600);//���
//	Timerx_Init(170,7199);//10Khz�ļ���Ƶ�ʣ�������170Ϊ17ms 
	NVIC_Configuration();
	Nvic_Init();
	BEEP_Init();
	EXTIX_Init();
 	LED_Init();		   //LED�˿ڳ�ʼ��
	TIM5_Config();
	KEY_Init();          //�����˿ڳ�ʼ��
	LCD_Init();
	Adc_Init();
	while(DHT11_Init())	//DHT11��ʼ��	
	{
		LCD_ShowString(60,100,200,16,16,"DHT11 Error");
		delay_ms(200);
		LCD_Fill(60,130,239,130+16,WHITE);
 		delay_ms(200);
	}			
//	DS18B20_Init();
	//��ʾ��ʾ��Ϣ
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(60,200,200,16,16,"ADC_CH0_VAL:");	      
	LCD_ShowString(60,160,200,16,16,"Temp:  C");	 
 	LCD_ShowString(60,180,200,16,16,"Humi:  %");	 

	
	POINT_COLOR = RED;
	LCD_ShowString(40,30,200,24,16, "Physics Base Project");
	EnTIMER;    		//ʹ�ܶ�ʱ��5(ʹ���˺����궨��)
	
	while(1)
	{
		loop();
	}
	

} //main()
