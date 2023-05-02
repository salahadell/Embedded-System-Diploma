/*
 * DC_motor.c

 *
 *  Created on: May 1, 2023
 *      Author: salah
 */
#include "DC_motor.h"
unsigned int DC_speed;

void DC_init()
{
	printf("DC_init\n");
}

void DC_motor_speed(int speed)
{
	DC_speed=speed;
	printf("CA --------> speed to DC = %d\n",DC_speed);
	DC_pstate=state(DC_busy);

}

define_state(DC_idel)
{
	DC_states_ID=DC_idel;
	DC_pstate=state(DC_idel);
	printf("DC_idel : speed = %d\n",DC_speed);
}

define_state(DC_busy)
{
	DC_states_ID=DC_busy;
	printf("DC_busy : speed = %d\n",DC_speed);
	DC_pstate=state(DC_idel);

}
