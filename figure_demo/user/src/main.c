#include "include.h"

Mark_t mark;	  //程序执行标志位【外部变量】

int main(void)
{
	
	delay_init(72);	     //延时初始化
	uart_init(115200);//串口初始化为9600
	USART_Config(9600);//舵机
//	Timerx_Init(170,7199);//10Khz的计数频率，计数到170为17ms 
	NVIC_Configuration();
	Nvic_Init();
	BEEP_Init();
	EXTIX_Init();
 	LED_Init();		   //LED端口初始化
	TIM5_Config();
	KEY_Init();          //按键端口初始化
	LCD_Init();
	Adc_Init();
	while(DHT11_Init())	//DHT11初始化	
	{
		LCD_ShowString(60,100,200,16,16,"DHT11 Error");
		delay_ms(200);
		LCD_Fill(60,130,239,130+16,WHITE);
 		delay_ms(200);
	}			
//	DS18B20_Init();
	//显示提示信息
	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(60,200,200,16,16,"ADC_CH0_VAL:");	      
	LCD_ShowString(60,160,200,16,16,"Temp:  C");	 
 	LCD_ShowString(60,180,200,16,16,"Humi:  %");	 

	
	POINT_COLOR = RED;
	LCD_ShowString(40,30,200,24,16, "Physics Base Project");
	EnTIMER;    		//使能定时器5(使用了函数宏定义)
	
	while(1)
	{
		loop();
	}
	

} //main()
