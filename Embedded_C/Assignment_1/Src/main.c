#include "Platform_Types.h"
#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800
#define RCC_APB2En *( vuint32_t *)(RCC_BASE + 0x18)
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



int main(void)
{
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
