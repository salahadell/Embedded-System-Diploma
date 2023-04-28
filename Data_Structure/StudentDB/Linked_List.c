/*
 * Linked_List.c
 *
 *  Created on: Apr 28, 2023
 *      Author: salah
 */

#include "Linked_List.h"

void CreateList(List *pl)
{
  pl->head=NULL;
  pl->size=0;
}
//------------------------------------------------------------------------------------------
int ListSize(List *pl)
{
  return pl->size;
}
//------------------------------------------------------------------------------------------
int ListEmpty(List *pl)
{
  return !pl->size; //return pl->head==NULL;
}
//------------------------------------------------------------------------------------------
int ListFull(List *pl)
{
  return 0;
}
//------------------------------------------------------------------------------------------
void DestroyList(List *pl)
{
  ListNode *pn=pl->head;
  while(pn)
  {
    pn=pl->head->next;
    free(pl->head);
    pl->head=pn;
  }
 pl->size=0;
}
//------------------------------------------------------------------------------------------
void Insert_Item(int pos,ListEntry e,List *pl) //0=<p=<size
{
  ListNode *q;
  int i;
  ListNode *pn=(ListNode *)malloc(sizeof(ListNode)); // mehtagen ne3ml bardo hena if cond bta3et en law el malloc ma7agzetsh bas msh haktebha
  pn->entry=e;
  pn->next=NULL;
  if(pos==0)
  {
    pn->next=pl->head;
    pl->head=pn;
  }
  else
  {
    for(q=pl->head,i=0;i<pos-1;i++)
    {
      q=q->next;
    }
    pn->next=q->next;
    q->next=pn;
  }
  pl->size++;
}
//------------------------------------------------------------------------------------------
void Delete_Item(int pos,ListEntry *pe,List *pl) //0=<p=<size-1 **** Retrieve_Item and delete it
{
  ListNode *q ,*tmp;
  int i;
  if(pos==0)
  {
   *pe=pl->head->entry;
   q=pl->head->next;
   free(pl->head);
   pl->head=q;
  }
  else
  {
   for(q=pl->head,i=0;i<pos-1;i++)
    {
     q=q->next;
    }
   *pe=q->next->entry;
   tmp=q->next->next;
   free(q->next);
   q->next=tmp;
  }
 pl->size--;
}
//------------------------------------------------------------------------------------------
void Retrieve_Item(int pos,ListEntry *pe,List *pl) //0=<p=<size-1 **** Retrieve_Item and keep it
{
 ListNode *q;
 int i;
 for(q=pl->head,i=0;i<pos;i++)
 {
  q=q->next;
 }
  *pe=q->entry;
}
//------------------------------------------------------------------------------------------
void Replace_Item(int pos,ListEntry e,List *pl) //0=<p=<size-1
{
 ListNode *q;
 int i;
 for(q=pl->head,i=0;i<pos;i++)
 {
  q=q->next;
 }
 q->entry=e;
}
//------------------------------------------------------------------------------------------
void TraverseList(List *pl , void (*pf)(ListEntry))
{

  ListNode *pn;
  for(pn=pl->head;pn;pn=pn->next)
 {
   (*pf)(pn->entry);
 }
}
