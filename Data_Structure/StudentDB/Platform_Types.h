/*
 * Platform_Types.h
 *
 *  Created on: Apr 19, 2023
 *      Author: salah
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned char           boolean;
typedef char                    char_t;
typedef signed char             sint8;
typedef unsigned char           uint8;
typedef signed short            sint16;
typedef unsigned short          uint16;
typedef signed int              sint32;
typedef unsigned int            uint32;
typedef long long               sint64;
typedef float                   float32;
typedef double                  float64;
typedef unsigned long long      uint64;

typedef volatile  sint8         vint8_t;
typedef volatile  uint8         vuint8_t;
typedef volatile  sint16        vint16_t;
typedef volatile  uint16        vuint16_t;
typedef volatile  sint32        vint32_t;
typedef volatile  uint32        vuint32_t;
typedef volatile  sint64        vint64_t;
typedef volatile  uint64        vuint64_t;

#ifndef TRUE
#define TRUE     ((boolean)1)
#endif
#ifndef FALSE
#define FALSE     ((boolean)0)
#endif
#ifndef NULL
#define NULL     (void*)0
#endif
#endif
