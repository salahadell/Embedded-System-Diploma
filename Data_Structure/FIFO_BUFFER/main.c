/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: salah
 */

#include "FIFO_BUFFER.h"
#include "stdio.h"

void PrintElement(QueueEntry e)
{
	printf("=========== FIFO Print ========\n");
	printf("%d\n",e);
}

int main(void)
{
	Queue FIFO_uart;
	uint32 i, temp;

	InitQueue(&FIFO_uart);

	printf("=========== FIFO Writing ========\n");
	for (i = 1; i < MAXQUEUE+2; i++)
	{
		if(!QueueFull(&FIFO_uart))
		{
			enqueue(i,&FIFO_uart);
			printf("Writing %d in FIFO_uart passed\n",i);
		}
		else
		{
			printf("QUEUE IS FULL \n");
		}
	}
	printf("Queue size is: %d",QueueSize(&FIFO_uart));

	printf("\n=========== FIFO Reading ========\n");
	for (i = 0; i < MAXQUEUE+1; i++)
	{
		if(!QueueEmpty(&FIFO_uart))
		{
			dequeue(&temp,&FIFO_uart);
			printf("Reading %d in FIFO_uart passed\n",temp);
		}
		else
		{
			printf("QUEUE IS EMPTY\n");
		}
	}

	printf("Queue size is: %d\n",QueueSize(&FIFO_uart));

	for (i = 0; i <2; i++)
	{
		if(!QueueFull(&FIFO_uart))
		{
			enqueue(i,&FIFO_uart);
			printf("Writing %d in FIFO_uart passed\n",i);
		}

	}

	TraverseQueue(&FIFO_uart, PrintElement);
	return 0;
}
