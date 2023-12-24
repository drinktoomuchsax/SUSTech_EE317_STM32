#include "led.h"

void LED_GPIO_Config(void)
{
 	// �� GPIOB �˿ڵ�ʱ��
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	// ����IO��Ϊ���
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED_GPIO_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

}

void LED_ON(void)
{
	// �����ƽ	
	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin); //LED on

}


void LED_OFF(void)
{
	// �����ƽ	
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin); //LED on

}
