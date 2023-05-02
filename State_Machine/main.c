/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: salah
 */

#include "CA.h"
#include "DC_motor.h"
#include "US_sensor.h"


void setup(void)
{
	US_init();
	DC_init();
	CA_pstate = state(CA_waiting);
	US_pstate = state(US_busy);
	DC_pstate = state(DC_idel);
}

int main(void)
{
	volatile int i;
	setup();

	while(1)
	{
		// Call state for each block
		US_pstate();
		CA_pstate();
		DC_pstate();

		// Delay
		for(i = 0 ; i <= 50000 ; i++);
	}
	return 0;
}
