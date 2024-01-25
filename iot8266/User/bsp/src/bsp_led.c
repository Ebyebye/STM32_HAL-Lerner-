/*
*********************************************************************************************************
*
*	模块名称 : LED指示灯驱动模块
*	文件名称 : bsp_led.c
*	版    本 : V1.0
*	说    明 : 驱动LED指示灯
*
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2018-09-05 armfly  正式发布
*
*	Copyright (C), 2015-2030, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp.h"

#define  PORTLED1  GPIOB
#define  PORTLED2  GPIOB
#define  PORTLED3  GPIOB
#define  PORTLED4  GPIOB
#define  PORTLED5  GPIOC

#define  PINLED1   GPIO_PIN_10
#define  PINLED2   GPIO_PIN_2
#define  PINLED3   GPIO_PIN_1
#define  PINLED4   GPIO_PIN_0
#define  PINLED5   GPIO_PIN_13

/*
*********************************************************************************************************
*	函 数 名: bsp_InitLed
*	功能说明: 配置LED指示灯相关的GPIO,  该函数被 bsp_Init() 调用。
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_InitLed(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10, GPIO_PIN_RESET);

    /*Configure GPIO pin : PC13 */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /*Configure GPIO pins : PB0 PB1 PB2 PB10 */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedOn
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 无
*********************************************************************************************************
*/



  
void bsp_LedOn(uint8_t _no) //5个灯 
{
	if (_no == 1)
	{

         PORTLED1->BSRR = PINLED1;
	}
	else if (_no == 2)
	{

        PORTLED2->BSRR = PINLED2;
	}
	else if (_no == 3)
	{
		PORTLED3->BSRR = PINLED3;
	}
	else if (_no == 4)
	{
		PORTLED4->BSRR = PINLED4;
	}
    else if(_no ==5)
    {
         PORTLED5->BSRR = (uint32_t)PINLED5 << 16U;
    }
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedOff
*	功能说明: 熄灭指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_LedOff(uint8_t _no)
{
	if (_no == 1)
	{
        PORTLED1->BSRR = (uint32_t)PINLED1 << 16U;
       
	}
	else if (_no == 2)
	{
        PORTLED2->BSRR = (uint32_t)PINLED2 << 16U;
	}
	else if (_no == 3)
	{
        PORTLED3->BSRR = (uint32_t)PINLED3 << 16U;
	}
	else if (_no == 4)
	{
		PORTLED4->BSRR = (uint32_t)PINLED4 << 16U;
	}
    else if(_no ==5)
    {
        PORTLED5->BSRR = PINLED5;
    }
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedToggle
*	功能说明: 翻转指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 按键代码
*********************************************************************************************************
*/
void bsp_LedToggle(uint8_t _no)
{
	
	if (_no == 1)
	{
		HAL_GPIO_TogglePin(PORTLED1, PINLED1);
	}
	else if (_no == 2)
	{
		HAL_GPIO_TogglePin(PORTLED2, PINLED2);
	}
	else if (_no == 3)
	{
		HAL_GPIO_TogglePin(PORTLED3, PINLED3);
	}
	else if (_no == 4)
	{
		HAL_GPIO_TogglePin(PORTLED4, PINLED4);
	}
    else if(_no ==5)
    {
        HAL_GPIO_TogglePin(PORTLED5, PINLED5);
    }
	else
	{
		return;
	}


}

/*
*********************************************************************************************************
*	函 数 名: bsp_IsLedOn
*	功能说明: 判断LED指示灯是否已经点亮。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 1表示已经点亮，0表示未点亮
*********************************************************************************************************
*/
uint8_t bsp_IsLedOn(uint8_t _no)
{
//	uint32_t pin;
//	
//	if (_no == 1)
//	{
//		pin = LED1;
//	}
//	else if (_no == 2)
//	{
//		pin = LED2;
//	}
//	else if (_no == 3)
//	{
//		pin = LED3;
//	}
//	else if (_no == 4)
//	{
//		pin = LED4;
//	}
//	else
//	{
//		return 0;
//	}
//	
//	if (HC574_GetPin(pin))
//	{
//		return 0;	/* 灭 */
//	}
//	else
//	{
//		return 1;	/* 亮 */
//	}
}

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
