#include "include.h"

Flag_t flag;   	//0

/******************0*****************************************/
void loop(void)
{
	// 250HZ
	if(flag.Loop_250Hz)
	{
		flag.Loop_250Hz=0;

//		DHT11_test();//温湿度检测
//		smoke();
	}	
	// 100HZ
	if(flag.Loop_100Hz)
	{
		flag.Loop_100Hz=0;
//		red = 0;
//		delay_ms(30);
//		red = 1;
//		mavlink();		//串口数据发送
//		Screen_Update();//屏幕数据更新
	}

}

/*====================================================================================================*/
/*====================================================================================================*
**函数 : Time_slice0
**功能 : 时间片0
**输入 : None
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
void Time_slice(void)
{
	static u16 tick[]={0,0,0,0};//可通过扩展数组来增加多个功能
	tick[0]++; //温湿度检测
	tick[1]++; //

	if(tick[0]>=2)	 //4ms执行一次(1/2*2)ms
	{
		tick[0] = 0;
		flag.Loop_250Hz = 1;
		DHT11_test();//温湿度检测
		smoke();

	}
	if(tick[1]>=5)
	{
		tick[1] = 0;
		flag.Loop_100Hz = 1;
	}	

}				   
//


/******************************END****FILE*************************************/
