/*
*********************************************************************************************************
*
*	ģ������ : LEDָʾ������ģ��
*	�ļ����� : bsp_led.c
*	��    �� : V1.0
*	˵    �� : ����LEDָʾ��
*
*	�޸ļ�¼ :
*		�汾��  ����        ����     ˵��
*		V1.0    2018-09-05 armfly  ��ʽ����
*
*	Copyright (C), 2015-2030, ���������� www.armfly.com
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
*	�� �� ��: bsp_InitLed
*	����˵��: ����LEDָʾ����ص�GPIO,  �ú����� bsp_Init() ���á�
*	��    ��:  ��
*	�� �� ֵ: ��
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
*	�� �� ��: bsp_LedOn
*	����˵��: ����ָ����LEDָʾ�ơ�
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��
*********************************************************************************************************
*/



  
void bsp_LedOn(uint8_t _no) //5���� 
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
*	�� �� ��: bsp_LedOff
*	����˵��: Ϩ��ָ����LEDָʾ�ơ�
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��
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
*	�� �� ��: bsp_LedToggle
*	����˵��: ��תָ����LEDָʾ�ơ�
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��������
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
*	�� �� ��: bsp_IsLedOn
*	����˵��: �ж�LEDָʾ���Ƿ��Ѿ�������
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: 1��ʾ�Ѿ�������0��ʾδ����
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
//		return 0;	/* �� */
//	}
//	else
//	{
//		return 1;	/* �� */
//	}
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
