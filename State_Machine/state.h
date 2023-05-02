/*
 * state.h
 *
 *  Created on: May 1, 2023
 *      Author: salah
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdlib.h>
#include <stdio.h>

#define define_state(_state_fun_) void ST_##_state_fun_()
#define state(_state_fun_) ST_##_state_fun_

void US_set_distance(int distance);
void DC_motor_speed(int speed);
#endif /* STATE_H_ */
