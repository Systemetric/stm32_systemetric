/*
 * Copyright 2013 Systemetric
 */

#include "main.h"

/*
 * NMI_Handler
 * Handles NMI exceptions
 */
void NMI_Handler(void)
{
}

/*
 * HardFault_Handler
 * Handles hard fault exceptions
 */
void HardFault_Handler(void)
{
    while (1);
}

/*
 * MemManage_Handler
 * Handles memory management exceptions
 */
void MemManage_Handler(void)
{
    while (1);
}

/*
 * BusFault_Handler
 * Handles bus fault exceptions
 */
void BusFault_Handler(void)
{
    while (1);
}

/*
 * UsageFault_Handler
 * Handles usage fault exceptions
 */
void UsageFault_Handler(void)
{
    while (1);
}

/*
 * SVC_Handler
 * Handles SVC exceptions
 */
void SVC_Handler(void)
{
}

/*
 * DebugMon_Handler
 * I don't really know what this does, but it's needed apparently
 */
void DebugMon_Handler(void)
{
}

/* PendSV_Handler
 * See above
 */
void PendSV_Handler(void)
{
}

/* 
 * SysTick_Handler
 * This is run upon the passing of every tick.
 * We use it for our wait() function in main.c.
 */
void SysTick_Handler(void)
{
    tick_decrement();
}
