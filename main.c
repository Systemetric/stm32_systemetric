/*
 * Copyright 2013 Systemetric
 */

#include "main.h"

volatile int tick_counter = 0;

/*
 * main
 * Entry point
 */
int main()
{
    /* Get hardware initialised */
    init_hw();

    /* Send test signal */
    while (1) {
        USART_SendData(USART3, 60000);
    }

    /*while (1) {
        if (STM_EVAL_PBGetState(BUTTON_USER)) {
            GPIO_SetBits(GPIOE, GPIO_Pin_15);
        } else {
            GPIO_ResetBits(GPIOE, GPIO_Pin_15);
        }
    }*/
    


    return 0;
}

/*
 * init_hw
 * Initialises hardware; pins, LEDs, sensors, etc.
 */
void init_hw(void)
{
    /* Vars */
    GPIO_InitTypeDef GPIO_Init_PD8, GPIO_Init_PD9;
    USART_InitTypeDef USART3_Init;
    int i = 0;

    /* Configure ticks to equal milliseconds (for delays) */
    if (SysTick_Config(SystemCoreClock / 1000)) {
        /* Catch errors using infinite loop */
        while (1);
    }

    /* Easy stuff first; enable LEDs */
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_LEDInit(LED6);
    STM_EVAL_LEDInit(LED7);
    STM_EVAL_LEDInit(LED8);
    STM_EVAL_LEDInit(LED9);
    STM_EVAL_LEDInit(LED10);

    /* Enable USART3 clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

    /* Enable clock on GPIOD pins (for USART3) */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
    
    /* Configure PD8's alternate function.
     * GPIO_AF_7 represents function USART3. */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_7);

    /* Enable USART3 transmit on pin PD8 */
    GPIO_Init_PD8.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init_PD8.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init_PD8.GPIO_OType = GPIO_OType_PP;
    GPIO_Init_PD8.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init_PD8.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_Init_PD8);
    
    /* Configure PD9's alternate function.
     * GPIO_AF_7 represents function USART3. */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_7);

    /* Enable USART3 receive on pin PD9 */
    GPIO_Init_PD9.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init_PD9.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init_PD9.GPIO_OType = GPIO_OType_PP;
    GPIO_Init_PD9.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init_PD9.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_Init_PD9);

    /* Configure USART3 */
    USART3_Init.USART_BaudRate = 1000000; // this is auto'd later
    USART3_Init.USART_WordLength = USART_WordLength_8b;
    USART3_Init.USART_StopBits = USART_StopBits_1;
    USART3_Init.USART_Parity = USART_Parity_No;
    USART3_Init.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART3_Init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

    /* Initialise and enable USART3 */
    USART_Init(USART3, &USART3_Init);
    USART_Cmd(USART3, ENABLE);

    /* Enable and configure automatic baud rate */
    USART_AutoBaudRateCmd(USART3, ENABLE);
    USART_AutoBaudRateConfig(USART3, USART_AutoBaudRate_FallingEdge);

    /* Enable user button */
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);

    /* Turn the LEDs on */
    STM_EVAL_LEDOn(LED3);
    STM_EVAL_LEDOn(LED4);
    STM_EVAL_LEDOn(LED5);
    STM_EVAL_LEDOn(LED6);
    STM_EVAL_LEDOn(LED7);
    STM_EVAL_LEDOn(LED8);
    STM_EVAL_LEDOn(LED9);
    STM_EVAL_LEDOn(LED10);
    
    /* Flash 'em a bit, shows something's happening */
    for (i = 0; i < 3; i++) {
        wait(500);
        STM_EVAL_LEDToggle(LED3);
        STM_EVAL_LEDToggle(LED4);
        STM_EVAL_LEDToggle(LED5);
        STM_EVAL_LEDToggle(LED6);
        STM_EVAL_LEDToggle(LED7);
        STM_EVAL_LEDToggle(LED8);
        STM_EVAL_LEDToggle(LED9);
        STM_EVAL_LEDToggle(LED10);
    }
}

/* 
 * tick_decrement
 * Decrements counter; used by systick callback,
 * enables us to use wait()
 */
void tick_decrement()
{
    if (tick_counter != 0) {
        tick_counter--;
    }
    return;
}

/* 
 * wait
 * Waits the specified number of milliseconds
 * and returns
 */
void wait(int time)
{
    tick_counter = time;
    while (tick_counter != 0);
}
