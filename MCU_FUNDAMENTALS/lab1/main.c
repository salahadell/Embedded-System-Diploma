#include "Platform_Types.h"
#define RCC_BASE 0x40021000
#define RCC_APB2En *(vuint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR *(vuint32_t *)(RCC_BASE + 0x04)
#define RCC_CR *(vuint32_t *)(RCC_BASE + 0x0)
#define PORTA_BASE 0x40010800
//#define GPIO_CRH *( vuint32_t *)(PORTA_BASE + 0x04)
//#define GPIO_ODR *( vuint32_t *)(PORTA_BASE + 0x0C)
#define preg_CRH ((volatile MyReg *)(PORTA_BASE + 0x04))
#define preg_ODR ((volatile MyReg *)(PORTA_BASE + 0x0C))


typedef union
{
	uint32  ALL_Pins;
	struct
	{
		uint32:13;
		uint32 pin13:1;
		uint32:6;
		uint32 CRH:4;
	}S_Pins;
}MyReg;

void clock_init()
{
	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/

		RCC_CFGR |=0b0100<<8;

		/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
		 */
		RCC_CFGR|=0b101<<11;


		/*Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8
	0111: PLL input clock x 9
	1000: PLL input clock x 10
	1001: PLL input clock x 11
	1010: PLL input clock x 12
	1011: PLL input clock x 13
	1100: PLL input clock x 14
	1101: PLL input clock x 15
	1110: PLL input clock x 16
	1111: PLL input clock x 16*/
		RCC_CFGR|=0b0110<<18;

		/*Bits 1:0 SW: System clock switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed*/
		RCC_CFGR|=0b10<<0;

		/*Bit 24 PLLON: PLL enable
	Set and cleared by software to enable PLL.
	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	PLL clock is used as system clock or is selected to become the system clock.
	0: PLL OFF
	1: PLL ON*/
		RCC_CR |=1<<24;

}

int main(void)
{
	clock_init();

	/*GPIO init*/
	RCC_APB2En |=1<<2;
	preg_CRH->S_Pins.CRH=0;
	preg_CRH->S_Pins.CRH=2;

	/*GPIO_CRH&=0xFF0FFFFF;
	GPIO_CRH|=0x00200000;*/

	while(1)
	{
		preg_ODR->S_Pins.pin13=1;
		for(int i=0;i<1500;i++);
		preg_ODR->S_Pins.pin13=0;
		for(int i=0;i<1500;i++);

	}
}
