/*
 * CA.c
 *
 *  Created on: May 1, 2023
 *      Author: salah
 */
#include "CA.h"
unsigned int CA_speed;
unsigned int CA_distance;
unsigned int threshold=50;

void US_set_distance(int distance)
{
	CA_distance=distance;
	CA_distance>threshold?(CA_pstate=state(CA_driving)):(CA_pstate=state(CA_waiting));
	printf("US --------> distance to CA=%d\n",CA_distance);
}


define_state(CA_waiting)
{
	CA_states_ID=CA_waiting;
	printf("CA_waiting : speed=%d , distance=%d \n",CA_speed,CA_distance);
	CA_speed=0;
	DC_motor_speed(CA_speed);
}

define_state(CA_driving)
{
	CA_states_ID=CA_driving;
	printf("CA_driving : speed=%d , distance=%d \n",CA_speed,CA_distance);
	CA_speed=30;
	DC_motor_speed(CA_speed);

}

