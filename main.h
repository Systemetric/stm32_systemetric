/*
 * Copyright 2013 Systemetric
 */

#ifndef MAIN_H
#define MAIN_H

#include "stm32f30x.h"
#include "stm32f3_discovery.h"
#include "stm32f30x_it.h"
#include "stm32f30x_gpio.h"

void init_hw(void);

void tick_decrement(void);
void wait(int time);

#endif

