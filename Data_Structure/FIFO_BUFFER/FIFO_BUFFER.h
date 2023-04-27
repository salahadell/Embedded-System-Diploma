/*
 * FIFO_BUFFER.h
 *
 *  Created on: Apr 27, 2023
 *      Author: salah
 */

#ifndef FIFO_BUFFER_H_
#define FIFO_BUFFER_H_
#define STATIC_IMP
#include "Platform_Types.h"
#define QueueEntry uint32
#define MAXQUEUE 5

#ifdef STATIC_IMP   //**************************ALLOW ARRAY BASED IMPLEMENTATION**************************//

typedef struct
{ int front;
  int rear;
  int size;
  QueueEntry entry[MAXQUEUE];
}Queue;
#else             //**************************ALLOW linked BASED IMPLEMENTATION**************************//

typedef struct queuenode
{
  QueueEntry entry;
  struct queuenode *next;
}QueueNode;

typedef struct
{
  QueueNode *rear;
  QueueNode *front;
  int size;
}Queue;

#endif

void InitQueue(Queue *pq);
int enqueue(QueueEntry e , Queue *pq);
void dequeue(QueueEntry *pe,Queue *pq );
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
int QueueSize(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue  *pq , void (*pf)(QueueEntry)); //passing specific function to pass all the queue element to it

#endif /* FIFO_BUFFER_H_ */
