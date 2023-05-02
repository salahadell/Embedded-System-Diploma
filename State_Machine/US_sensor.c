/*
 * US_sensor.c
 *
 *  Created on: May 1, 2023
 *      Author: salah
 */
#include "US_sensor.h"
unsigned int US_distance;


void US_init()
{
	printf("US_init\n");

}
 int generate_distance(int low ,int high , int count)
 {
	 int i,randn;
	 for (i=0;i<count;i++)
		 randn =(rand() % (high-low +1)) +low;
	 return randn;
 }

define_state(US_busy)
{
	US_states_ID=US_busy;
	US_distance=generate_distance(45 ,55 ,1);
	printf("US_busy : distance=%d \n",US_distance);
	US_set_distance(US_distance);
	US_pstate=state(US_busy);
}
