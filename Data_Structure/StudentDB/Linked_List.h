/*
 * Linked_List.h
 *
 *  Created on: Apr 28, 2023
 *      Author: salah
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "Platform_Types.h"
#define ListEntry S_Student

typedef struct
{
  uint32 ID;
  char name[50];
  float height;
}S_Student;

typedef struct listnode
{
  ListEntry entry;
  struct listnode *next;
}ListNode;
//------------------------------------------------------------------------------------------
typedef struct list
{
  int size;
  ListNode *head;
}List;
//------------------------------------------ LINKED LIST METHODS ---------------------------
void CreateList(List *pl);
int ListSize(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
void DestroyList(List *pl);
void Insert_Item(int pos,ListEntry e,List *pl);
void Delete_Item(int pos,ListEntry *pe,List *pl);
void Retrieve_Item(int pos,ListEntry *pe,List *pl);
void Replace_Item(int pos,ListEntry e,List *pl);
void TraverseList(List *pl , void (*pf)(ListEntry));

#endif /* LINKED_LIST_H_ */
