#ifndef __LED_H
#define __LED_H

#define KEY_ON 	1
#define KEY_OFF 0

#include "stm32f10x.h"

#define LED_GPIO_CLK   RCC_APB2Periph_GPIOB
#define LED_GPIO_Pin   GPIO_Pin_5
#define LED_GPIO_PORT   GPIOB

#define LED_GPIO_Pin_R   GPIO_Pin_5
#define LED_GPIO_Pin_G   GPIO_Pin_0
#define LED_GPIO_Pin_B   GPIO_Pin_1

//switch related define
#define SWITCH_GPIO_CLK    RCC_APB2Periph_GPIOA
#define SWT_GPIO_PORT   GPIOA
#define K1_GPIO_Pin   GPIO_Pin_0

void LED_GPIO_Config(void);
void LED_ON(void);
void LED_OFF(void);
void LED_RGBlooping(void);
void LED_switchControl(void);
void LED_switchControl2(void);
uint8_t Key_Scan(GPIO_TypeDef*,uint16_t);
#endif
