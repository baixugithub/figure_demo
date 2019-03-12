/**
  ******************************************************************************
  * @file    CAN/Networking/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "include.h"
/*
*********************************************************************************************************
*	                                  
*	模块名称 : 中断模块
*	文件名称 : stm32f10x_it.c
*	版    本 : V2.0
*	说    明 : 本文件存放所有的中断服务函数。为了便于他人了解程序用到的中断，我们不建议将中断函数移到其他
*			的文件。
*				
*********************************************************************************************************
*/
void TIM5_IRQHandler(void)		    //2ms中断一次
{	
	if(TIM5->SR & TIM_IT_Update)	
	{    
		TIM5->SR = ~TIM_FLAG_Update;//清除中断标志	
			if(mark.Mark_0 == 1)
			{
				red = 0;
			}
			if(mark.Mark_0 == 0)
			{
				red = 1;
			}
		FIRE_init();

		Time_slice();
//					DHT11_test();//温湿度检测
//		smoke();

		/*-------------程序选择开关-----------------*/
		/*-功能0： KEY1 = 0 启动识别功能*/
		if (KEY1==0) 
		{
			modeflag = 0;
			changeflag = 1;//模式发生了转换			
			Figure_Test();
			FigureIdenfity();

		}
		/*-功能1： KEY2 = 0 启动录入功能*/
		if (KEY2==0)
		{
			modeflag = 1;
			changeflag = 1;//模式发生了转换			
			Figure_Test();
			FigureEnter();

		}
//		/*-功能2： KEY0 = 1 & KYE1 = 0【A<——>B（停）】*/
		if (KEY3==0)
		{
				mark.Mark_2 = 1;
				clearallflag = 1;
		//		changeflag = 1;//模式发生了转换			
				Figure_Test();

				FigureClear();

		}
		if (KEY1==1 & KEY2==1 & KEY3==1)
		{
				LCD_ShowString(10,100,200,24,24,"Switch isn't open!!!!");//Switch isn't open
				LCD_ShowString(10,130,200,24,24,"Please open!!!!");

		}


	}
}
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

/** @addtogroup CAN_Networking
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/ 
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}
/*
* FunctionName:RTC_IRQHandler
* Description: Configuration RTC_IRQHandler
* Input: void
* Output: void
* Return: void
*/
//
/*
* FunctionName:USART2_IRQHandler
* Description: Configuration USART2_IRQHandler
* Input: void
* Output: void
* Return: void
*/

//

/******************************************************************************/
/*            STM32F10x Peripherals Interrupt Handlers                        */
/******************************************************************************/

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
