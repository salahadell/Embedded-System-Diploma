/*
 * CA.h
 *
 *  Created on: May 1, 2023
 *      Author: salah
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

enum
{
	CA_waiting,
	CA_driving
}CA_states_ID;

define_state(CA_waiting);
define_state(CA_driving);

void (*CA_pstate)();

#endif /* CA_H_ */
