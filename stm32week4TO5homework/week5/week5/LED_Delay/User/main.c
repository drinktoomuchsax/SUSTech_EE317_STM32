/*********************************
оƬ��STM32F103ZET6
ʵ�ֹ��ܣ�LED����˸���͵�ƽ�������ߵ�ƽϨ��
���ţ�PB5
*************************************/

#include "stm32f10x.h" 
#include "led.h"

uint32_t count;

void Delay( uint32_t count )
{
	for(; count!=0; count--);
}


int main(void)
{
		LED_GPIO_Config();
	  while(1)
		{
		    LED_ON();
			Delay(0xffffff);		
			LED_OFF();	
			Delay(0xffffff);
		}
}






