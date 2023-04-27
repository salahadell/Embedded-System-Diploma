/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: salah
 */

#include "LIFO_BUFFER.h"
#include "stdio.h"

int main(void)
{
	Stack LIFO_uart;
	uint32 i, temp;

	InitStack(&LIFO_uart);

	printf("=========== LIFO Writing ========\n");
	for (i = 1; i < MAXSTACK+2; i++)
	{
		if(!StackFull(&LIFO_uart))
		{
			Push(i,&LIFO_uart);
			printf("Writing %d in LIFO_uart passed\n",i);
		}
		else
		{
			printf("STACK IS FULL \n");
		}
	}
	printf("stack size is: %d",StackSize(&LIFO_uart));

	printf("\n=========== LIFO Reading ========\n");
	for (i = 0; i < MAXSTACK+1; i++)
	{
		if(!StackEmpty(&LIFO_uart))
		{
			Pop(&temp,&LIFO_uart);
			printf("Reading %d in LIFO_uart passed\n",temp);
		}
		else
		{
			printf("STACK IS EMPTY\n");
		}
	}

printf("stack size is: %d",StackSize(&LIFO_uart));

	return 0;
}
