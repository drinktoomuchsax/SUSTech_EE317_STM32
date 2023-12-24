#include "sys.h"

int main(void)
{
	LED_GPIO_Config();
	delay_init();
	TIM3_Init(9999, 7199);
	static uint8_t i = 0;
	while (1)
	{
		KEY_Scan();
		LED_Change();
	}
}
