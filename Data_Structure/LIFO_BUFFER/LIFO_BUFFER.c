/*
 * LIFO_BUFFER.c
 *
 *  Created on: Apr 26, 2023
 *      Author: salah
 */

#include "LIFO_BUFFER.h"
#include <stdlib.h>
#ifdef STATIC_IMP   //**************************ALLOW ARRAY BASED IMPLEMENTATION**************************//

void InitStack(Stack *s)
{
s->top=0;
}
//----------------------------------------------------------------------------------------
void Push(StackEntry e,Stack *s)
{
s->entry[s->top]=e;
s->top++;
}
//----------------------------------------------------------------------------------------
void Pop(StackEntry *e ,Stack *s)
{
*e=s->entry[--s->top];
}
//----------------------------------------------------------------------------------------
int StackFull(Stack *s)
{
return s->top==MAXSTACK;
}
//----------------------------------------------------------------------------------------
int StackEmpty(Stack *s)
{
return s->top==0;
}
//----------------------------------------------------------------------------------------
void StackTop(StackEntry *e,Stack *s)
{
*e=s->entry[s->top-1];
}
//----------------------------------------------------------------------------------------
int StackSize(Stack *s)
{
return s->top;
}
//----------------------------------------------------------------------------------------
void ClearStack(Stack *s)
{
s->top=0;
}
//----------------------------------------------------------------------------------------
void TraverseStack(Stack *ps ,void (*pf)(StackEntry))
{
for(int i=ps->top;i>0;i--)
{
   (*pf)(ps->entry[i-1]);
}
}

#else     //*************************** ALLOW linked BASED IMPLEMENTATION **************************//


void InitStack(Stack *ps)
{
  ps->top=NULL;
  ps->size=0;
}
//----------------------------------------------------------------------------------------
void Push(StackEntry e ,Stack *ps)
{
  StackNode *pn =(StackNode*)malloc(sizeof(StackNode));
  pn->entry=e;
  pn->next=ps->top;
  ps->top=pn;
  ps->size++;
}
//----------------------------------------------------------------------------------------
void Pop(StackEntry *e,Stack *ps)
{
  StackNode *pn;
  *e=ps->top->entry;
  pn=ps->top;
  ps->top=ps->top->next;
  free(pn);
  ps->size--;
}
//----------------------------------------------------------------------------------------
int StackFull(Stack *ps)
{
  return 0;
}
//----------------------------------------------------------------------------------------
int StackEmpty(Stack *ps)
{
  return ps->top==NULL;
}
//----------------------------------------------------------------------------------------
int StackSize(Stack *ps)
{
  return ps->size;
} //after adding size in struct Stack .... theta(1)
//----------------------------------------------------------------------------------------
void ClearStack(Stack *ps)
{
  StackNode *pn =ps->top;
   while(pn)
   {
     pn=pn->next;
     free(ps->top);
     ps->top=pn;
   }
  ps->size=0;
}
//----------------------------------------------------------------------------------------
void TraverseStack(Stack *ps,void (*pf)(StackEntry))
{
  StackNode *pn=ps->top;
  while(pn)
	  {
     (*pf)(pn->entry);
     pn=pn->next;
	  }
}

#endif
