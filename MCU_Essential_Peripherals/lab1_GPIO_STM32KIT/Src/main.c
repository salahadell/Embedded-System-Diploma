/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define RCC_BASE 0x40021000
#define RCC_APB2En *(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOA_IDR *(volatile uint32_t *)(GPIOA_BASE + 0x08)


void GPIO_init()
{
	//enable clock for PORTA
	RCC_APB2En|=1<<2;
	//enable clock for PORTB
	RCC_APB2En|=1<<3;
	//enable floating input to PA_pin1 (4-->7)
	GPIOA_CRL|=0b0100<<4;
	//enable floating input to PA_pin13 (20-->23)
	GPIOA_CRH|=0b0100<<20;
	//enable push-pull output to PB_pin1
	GPIOB_CRL|=  0b01<<4;
	GPIOB_CRL&= ~(0b11<<6);
	//enable push-pull output to PB_pin13
	GPIOB_CRH |=  0b01<<20;
	GPIOB_CRH &= ~(0b11<<22);

}


int main(void)
{
	GPIO_init();


while(1)
{
	if((GPIOA_IDR&(1<<1))>>1 == 0)             //  A1 single pressing
	{
		GPIOB_ODR^=1<<1;
		while((GPIOA_IDR&(1<<1))>>1 == 0);

	}

	if((GPIOA_IDR&(1<<13))>>13 == 1)             //  A13 multi pressing
		{
			GPIOB_ODR^=1<<13;
		}
	for(int i=0;i<1500;i++);


}
}