/*
 * DC_motor.h
 *
 *  Created on: May 1, 2023
 *      Author: salah
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "state.h"
enum
{
	DC_idel,
	DC_busy
}DC_states_ID;

define_state(DC_idel);
define_state(DC_busy);

void DC_init();
void (*DC_pstate)();


#endif /* DC_MOTOR_H_ */
