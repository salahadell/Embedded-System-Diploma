/*
 * LIFO_BUFFER.h
 *
 *  Created on: Apr 26, 2023
 *      Author: salah
 */

#ifndef LIFO_BUFFER_H_
#define LIFO_BUFFER_H_
#define STATIC_IMP
#include "Platform_Types.h"
#define StackEntry uint32
#define MAXSTACK 5

#ifdef STATIC_IMP   //**************************ALLOW ARRAY BASED IMPLEMENTATION**************************//

typedef struct
{
int top;
StackEntry entry[MAXSTACK];
}Stack;

#else             //**************************ALLOW linked BASED IMPLEMENTATION**************************//

typedef struct stacknode
{
  StackEntry entry ;
  struct stacknode *next;
}StackNode;

typedef struct
{
StackNode *top;
int size;
}Stack;

#endif

void InitStack(Stack *s);
void Push(StackEntry e,Stack *s);
void Pop(StackEntry *e ,Stack *s);
int StackFull(Stack *s);
int StackEmpty(Stack *s);
void StackTop(StackEntry *e,Stack *s);  //get the top element of the stack without popping it
int StackSize(Stack *s);
void ClearStack(Stack *s);
void TraverseStack(Stack *ps ,void (*pf)(StackEntry)); //passing specific function to pass all the stack element to it

#endif /* LIFO_BUFFER_H_ */
