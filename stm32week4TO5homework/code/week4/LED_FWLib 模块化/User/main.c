/*********************************
оƬ��STM32F103VET6
ʵ�ֹ��ܣ��͵�ƽ����LED��
���ţ�PB5
*************************************/

#include "stm32f10x.h" 
#include "led.h"

int main(void)
{
	  LED_GPIO_Config();
  LED_RGBlooping();  
//LED_switchControl2();
}






