#include "led.h"
#include "delay.h"


void LED_GPIO_Config(void)
{
	// 打开 GPIOB 端口的时钟
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	// 配置IO口为输出
	GPIO_InitTypeDef GPIO_InitStruct_PB5;
	GPIO_InitTypeDef GPIO_InitStruct_PB0;
	GPIO_InitTypeDef GPIO_InitStruct_PB1;
	
	GPIO_InitStruct_PB5.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct_PB5.GPIO_Pin=LED_GPIO_Pin_R;
	GPIO_InitStruct_PB5.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct_PB5);
	
	GPIO_InitStruct_PB0.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct_PB0.GPIO_Pin=LED_GPIO_Pin_G;
	GPIO_InitStruct_PB0.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct_PB0);
	
 	GPIO_InitStruct_PB1.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct_PB1.GPIO_Pin=LED_GPIO_Pin_B;
	GPIO_InitStruct_PB1.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct_PB1);
	
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
	
	//init Key1(PA0)
	RCC_APB2PeriphClockCmd(SWITCH_GPIO_CLK, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct_PA0;
	GPIO_InitStruct_PA0.GPIO_Pin=K1_GPIO_Pin;
 	GPIO_InitStruct_PA0.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(SWT_GPIO_PORT, &GPIO_InitStruct_PA0);
	
}

void LED_ON(void)
{
	// 输出电平	
	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin); //LED on

}


void LED_OFF(void)
{
	// 输出电平	
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin); //LED off

}

void LED_RGBlooping(void){
	delay_init();
	int gapTime = 1000;
	while(1){
	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED on
	delay_ms(gapTime);
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
	delay_ms(1);
	
	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED on
	delay_ms(gapTime);
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
	delay_ms(1);
	
 	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED on
	delay_ms(gapTime);
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
	delay_ms(1);
	}
}

void LED_switchControl(void){
	delay_init();
	int state = 0;
	int gapTime = 1000;
	while(1){
		while(1){
			if(GPIO_ReadInputDataBit(SWT_GPIO_PORT,K1_GPIO_Pin) == 1){ //switch pressed
			state++;
			delay_ms(50);
			}	
		break;
		}
		if((state%3)==0){
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
			delay_ms(gapTime);
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED on
		}else if((state%3)==1){
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
			delay_ms(gapTime);
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED on
		}else if((state%3)==2){
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
			delay_ms(gapTime);
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED on
		}
	}
}


uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*????????? */
	if (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON ) 
	{
		/*?????? */
		while (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
		return KEY_ON;
	} 
	else
	{
		return KEY_OFF;
	}
}

void LED_switchControl2(void){
delay_init();
int state = 0;
while (1) 
	{
		if ( Key_Scan(SWT_GPIO_PORT,K1_GPIO_Pin) == KEY_ON ) 
		{
			state++;
			delay_ms(10);
		}
		if(state==1){
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
			
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED on
		}else if(state==2){
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
			
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED on
		}else if(state==3){
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_R); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_G); //LED off
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED off
			
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_Pin_B); //LED on
		}else if(state >3)
		{
		state =1;
		}
	}
}
