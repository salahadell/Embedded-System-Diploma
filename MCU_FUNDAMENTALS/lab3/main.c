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
#define MCUCR_ *(vuint08_t *)(IO_BASE + 0x35) 
#define MCUSR_ *(vuint08_t *)(IO_BASE + 0x34) 
#define GICR_ *(vuint08_t *)(IO_BASE + 0x3B) 
#define GIFR_ *(vuint08_t *)(IO_BASE + 0x3A) 
#define SREG_ *(vuint08_t *)(IO_BASE + 0x3F) 
#define PORTD_ *(vuint08_t *)(IO_BASE + 0x12) 
#define DDRD_ *(vuint08_t *)(IO_BASE + 0x11)

void PORTD_init()
{
	//enable output point to pin5/6/7
	DDRD_|=0b111<<5;

}


int main(void)
{
	PORTD_init();
	//enable global interrupt
	SREG_|= 1<<7;
	//enable INT0/INT1/INT2
	GICR_|= 0b111<<5;
	//enable falling edge for INT2
	MCUSR_&= ~(1<<6);
	//enable any logical change for INT0 and rising edge for INT1
	MCUCR_|= 0b1101<<0;

	while(1)
	{
		PORTD_&= ~(0b111<<5) ;
	}
	return 0;
}
ISR(INT0_vect)
{
	PORTD_ |= 1<<5 ;
	_delay_ms(1000);
	//disable pending pin
	GIFR_|= 1<<5;
}
ISR(INT1_vect)
{
	PORTD_ |= 1<<6 ;
	_delay_ms(1000);
	//disable pending pin
	GIFR_|= 1<<6;
}
ISR(INT2_vect)
{
	PORTD_ |= 1<<7 ;
	_delay_ms(1000);
	//disable pending pin
	GIFR_|= 1<<7;
}
