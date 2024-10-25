#include "stm32f10x.h"                  // Device header

void PWM2_Init(void)
{
    // 设置外部条件
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); // 开启TIM3时钟所在的总线
    TIM_InternalClockConfig(TIM3);  // 使用内部时钟驱动TIM3

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 开启GPIOA的时钟

    GPIO_InitTypeDef GPIO_InitStructrue;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; // PA6, PA7 对应TIM3_CH1 和 TIM3_CH2
    GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructrue);

    // 时基单元初始化
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1; // 自动重装值, ARR
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1; // 预分频值, PSC
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

    TIM_OCInitTypeDef TIM_OCInitStruct;
    TIM_OCStructInit(&TIM_OCInitStruct);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_Pulse = 0; // CCR
    TIM_OC2Init(TIM3, &TIM_OCInitStruct);
    TIM_OC1Init(TIM3, &TIM_OCInitStruct);

    // 启动定时器
    TIM_Cmd(TIM3, ENABLE);
}

void PWM2_SetCompare1(uint16_t Compare)
{
    TIM_SetCompare1(TIM3, Compare);
}

void PWM2_SetCompare2(uint16_t Compare)
{
    TIM_SetCompare2(TIM3, Compare);
}
