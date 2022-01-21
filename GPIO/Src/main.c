/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */



#include <stdint.h>
#include "rcc_config.h"

void GPIO_init(void);

int main(void)
{
	Clock_config();
	GPIO_init();

	while(1){

		if(~GPIOA->IDR & GPIO_IDR_IDR1){
			GPIOA->ODR |= (GPIO_ODR_ODR0);
		}
		else{
			GPIOA->ODR &=~(GPIO_ODR_ODR0);
		}

	}
}

void GPIO_init(void){

	//HABILITA CLOCK DEL PUERTO A
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//PA0->SALIDA PUSH PULL
	GPIOA->CRL &=~ (GPIO_CRL_CNF0 | GPIO_CRL_MODE0);
	GPIOA->CRL |= GPIO_CRL_MODE0;
	//PA1->ENTRADA
	GPIOA->CRL &=~ (GPIO_CRL_CNF1 | GPIO_CRL_MODE1);
	//MODO PULL UP-PULL DOWN
	GPIOA->CRL |= GPIO_CRL_CNF1_1;
	//MODO PULL UP
	GPIOA->ODR |= (GPIO_ODR_ODR1);

}