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
#define PORTD_ *(vuint08_t *)(IO_BASE + 0x12) //ODR
#define DDRD_ *(vuint08_t *)(IO_BASE + 0x11) //DDR
#define PIND_ *(vuint08_t *)(IO_BASE + 0x10) //IDR


void PORTD_init()
{
	//enable output point to pin 4/5/6/7
	DDRD_|=0b1111<<4;

}

#define toggile_bit(PORT,bit) PORT^= 1<<bit 

int main(void)
{
	PORTD_init();
	while(1)
	{
		int i=5;
		for(;i<8;i++)
		{
          toggile_bit(PORTD_,i);
		  _delay_ms(10000);
          toggile_bit(PORTD_,i);
		}
		
	   toggile_bit(PORTD_,4);
	   _delay_ms(10000);
	   toggile_bit(PORTD_,4);
	   _delay_ms(10000);

	}
	return 0;
}

