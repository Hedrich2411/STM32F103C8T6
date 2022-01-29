/*
 * rcc_config.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Vland
 */

#include "rcc_config.h"

void Clock_config(void){

	//TIPO DE OSCILADOR
	RCC->CR |= RCC_CR_HSEON; // Cristal Externo -> 8MHz
	while((RCC->CR & RCC_CR_HSERDY) == 0);//Indica si el oscilador es estable

	RCC->CR &= RCC_CR_PLLON;//Desactiva el pll

	//LECTURA MEMORIA FLASH
	FLASH->ACR &= ~(FLASH_ACR_LATENCY); //Se limpia
	FLASH->ACR |= FLASH_ACR_LATENCY_0;// Para 8Mhz
	FLASH->ACR |= FLASH_ACR_PRFTBE; //Habilita el PREFETCH

	//MODO DE CONFIGURACIÓN
	RCC->CFGR &= ~(RCC_CFGR_SW); //Se limpia
	RCC->CFGR |= RCC_CFGR_SW_0; //Selecciona HSE

	// AHB
	RCC->CFGR &= ~(RCC_CFGR_HPRE);
	// APB1
	RCC->CFGR &= ~(RCC_CFGR_PPRE1);
	RCC->CFGR |= RCC_CFGR_PPRE1_2;
	// APB2
	RCC->CFGR &= ~(RCC_CFGR_PPRE2);

}
