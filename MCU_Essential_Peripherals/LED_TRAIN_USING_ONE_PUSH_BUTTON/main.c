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
#define set_bit(PORT,bit) PORT|= 1<<bit
#define clear_bit(PORT,bit) PORT&= ~(1<<bit)


int main(void)
{
	//LED TRAIN USING ONE PUSH BUTTON
	PORTD_init();
	int flag=0;
	while(1)
	{
		if((PIND_&1)==1 )
		{
			if(!flag) //ALL LEDS ARE OFF
			{

				if(((PORTD_&(1<<5))>>5)==0)
				{
					set_bit(PORTD_,5);
					_delay_ms(10000);

				}
				else if(((PORTD_&(1<<6))>>6)==0)
				{
					set_bit(PORTD_,6);
					_delay_ms(10000);

				}
				else if(((PORTD_&(1<<7))>>7)==0)
				{
					set_bit(PORTD_,7);
					_delay_ms(10000);
					flag=1;  //ALL LEDS ARE ON

				}
			}
			else
			{
				if(((PORTD_&(1<<7))>>7)==1)
				{
					clear_bit(PORTD_,7);
					_delay_ms(10000);

				}
				else if(((PORTD_&(1<<6))>>6)==1)
				{
					clear_bit(PORTD_,6);
					_delay_ms(10000);
				}

				else if(((PORTD_&(1<<5))>>5)==1)
				{
					clear_bit(PORTD_,5);
					_delay_ms(10000);
					flag=0;   //ALL LEDS ARE OFF AGIAN
				}

			}
		}


	}
	return 0;
}

