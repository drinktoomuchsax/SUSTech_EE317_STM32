#include "timer_time.h"
/********************
����NVIC��

��ʹ�ܶ�ʱ��ʱ�ӡ�
RCC_APB1PeriphClockCmd();
�� ��ʼ����ʱ��������ARR,PSC��
TIM_TimeBaseInit();
������������жϱ�־λ��������ʱ���ж�
TIM_ClearFlag
void TIM_ITConfig();

��ʹ�ܶ�ʱ����
TIM_Cmd();
�ݱ�д�жϷ�������
TIMx_IRQHandler();
*****************/

// �ж����ȼ�����
static void BASIC_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	   
		// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn ;	
		// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  // ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void BASIC_TIM_Config()
{
	  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		
		// 1 ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
		// 2 �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;

	  // ʱ��Ԥ��Ƶ��Ϊ
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;
	
		// ʱ�ӷ�Ƶ���� ��������ʱ��û�У����ù�
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		
		// ����������ģʽ��������ʱ��ֻ�����ϼ�����û�м���ģʽ������
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
		// �ظ���������ֵ��������ʱ��û�У����ù�
		//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	  // ��ʼ����ʱ��
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
		
		// 3 ����������жϱ�־λ
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	  
		//  �����������ж�
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
		
		//4 ʹ�ܼ�����
    TIM_Cmd(TIM6, ENABLE);
}

void BASIC_TIM_Init(void)
{
	BASIC_TIM_NVIC_Config();
	BASIC_TIM_Config();
}



