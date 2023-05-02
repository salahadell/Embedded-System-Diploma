/*
 * US_sensor.h
 *
 *  Created on: May 1, 2023
 *      Author: salah
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_
#include "state.h"
enum
{
	US_busy
}US_states_ID;

define_state(US_busy);
void US_init();
void (*US_pstate)();


#endif /* US_SENSOR_H_ */
