/*
 * GccApplication1.c
 *
 * Created: 5/25/2023 11:11:01 AM
 * Author : salah
 */ 

typedef volatile unsigned char vuint08_t ;
#include <util/delay.h>
#include <avr/interrupt.h>

// register address
#define F_CPU 8000000UL
#define IO_BASE 0x20
#define PORTC_ *(vuint08_t *)(IO_BASE + 0x15) //ODR
#define DDRC_ *(vuint08_t *)(IO_BASE + 0x14) //DDR
#define PINC_ *(vuint08_t *)(IO_BASE + 0x13) //IDR


void PORTC_init()
{
	//enable output point to pin 2/3/4/5/6/7
	DDRC_|=0b111111<<2;

}

#define toggile_bit(PORT,bit) PORT^= 1<<bit 
#define set_bit(PORT,bit) PORT|= 1<<bit
#define clear_bit(PORT,bit) PORT&= ~(1<<bit)


int main(void)
{
	PORTC_init();
	while(1)
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				PORTC_=0b1011|i<<4;
				_delay_ms(1500);
				PORTC_=0b0111|j<<4;
				_delay_ms(500);
			}
		}
		

	}
	return 0;
}

