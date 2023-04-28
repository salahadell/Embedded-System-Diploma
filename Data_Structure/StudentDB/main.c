/*
 * main.c
 *
 *  Created on: Apr 28, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#include "Linked_List.h"

static int counter;

#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);fflush(stdin);}

void fill_the_record(S_Student *P_Student)
{
	char temp[50];
	DPRINTF("Enter Student ID: ");
	gets(temp);
	P_Student->ID = atoi(temp);

	DPRINTF("Enter Student Name: ");
	gets(P_Student->name);

	DPRINTF("Enter Student Height: ");
	gets(temp);
	P_Student->height = atof(temp);

}

int find_ID(List *P_List)
{
	ListNode *pn=P_List->head;
	char temp[50];
	int i=0;
	DPRINTF("Enter Student ID: ");
	gets(temp);
	while(pn)
	{
		if((pn->entry.ID)==atoi(temp))
		{
			return i;
		}
		else
		{
			pn=pn->next;
			i++;
		}
	}
	return -1;   //can't find ID
}

void view_student(S_Student Student)
{
	DPRINTF("\n Record Number %d",counter++);
	DPRINTF("\n\t ID : %d",Student.ID);
	DPRINTF("\n\t Name : %s",Student.name);
	DPRINTF("\n\t Height : %0.2f\n",Student.height);
}

int Students_counter_by_Iteration(ListNode *head)   //O(n)
{
	int size=0;
	ListNode *pn=head;
	while(pn)
	{
		size++;
		pn=pn->next;
	}
	return size;
}

int Students_counter_by_Recursion(ListNode *head )   //O(n)
{
	ListNode *pn=head;
	if(!pn)
		return 0;
	pn=pn->next;
	return 1 + Students_counter_by_Recursion(pn);
}

void get_node_from_end_using_Iteration(List *pl,int num)
{
	S_Student student;
    int index = pl->size - num;
    Retrieve_Item(index,&student,pl);
    view_student(student);
    /*it's supposed to be slower but because of size(O(1)) member
  of the list struct this function will be O(n) in the worst case but maybe find the element earlier*/
}

void get_node_from_end_using_pointers(List *pl,int num)
{
	int count=0;
	ListNode *fast=pl->head;
    ListNode *slow=pl->head;
    while(count++!=num)    //the difference between two pointers must be equal to the desired index
    	fast=fast->next;
    while(fast)  //this function will be O(n) in any case because we must reach the NULL to find the element
    {
    fast=fast->next;
    slow=slow->next;
    } // fast pointer stop at null , slow pointer stop at the target node

    view_student(slow->entry);
}

void get_middle_student(List *pl)
{
	ListNode *fast=pl->head;      //double speed so when it arrived to the end
	ListNode *slow=pl->head;     // the slow pointer will stop the middle
	while(fast)
	{
		fast=fast->next;
		if(!fast)      //to break in case of odd numbers  1 2 (3) 4 [5] null   1 2 3 (4) 5 null []-->error
			break;
		fast=fast->next;
		slow=slow->next;
	}
    view_student(slow->entry);
}

int main(void)
{
	char temp[50];
	int num;
	int pos;
	S_Student Student;
	List mylist;
	CreateList(&mylist);

	while(1)
	{
		DPRINTF(" ============================= ");
		DPRINTF("\n Choose one of the following options \n");
		DPRINTF("\n\t 1: Add Student");
		DPRINTF("\n\t 2: Delete Student");
		DPRINTF("\n\t 3: View Students");
		DPRINTF("\n\t 4: Delete All");
		DPRINTF("\n\t 5: Get Students numbers using size member of the list struct"); //O(1)
		DPRINTF("\n\t 6: Get Students numbers by Iteration");  //O(n)
		DPRINTF("\n\t 7: Get Students numbers by Recursion");  //O(n)
		DPRINTF("\n\t 8: Get Node in a Linked List(Retrieve Item)");
		DPRINTF("\n\t 9: Get Node from the end");
		DPRINTF("\n\t 10: Get Middle student");
		//DPRINTF("\n\t 11: Reverse student");
		DPRINTF("\n\t 12: Exit");
		DPRINTF("\n\n Enter option number: ");

		gets(temp);
		DPRINTF("\n ============================= \n");
		switch(atoi(temp))
		{
		case 1:
			fill_the_record(&Student);
			Insert_Item(mylist.size,Student,&mylist);
			break;

		case 2:
			pos=find_ID(&mylist);
			if(pos!=-1)
				Delete_Item(pos,&Student,&mylist);
			else
				DPRINTF("\n cannot find student ID. ");
			break;

		case 3:
			if(!mylist.head)
			{
				DPRINTF("\n List is empty. \n");
				break;
			}
			counter=1;
			TraverseList(&mylist,view_student);
			break;

		case 4:
			DestroyList(&mylist);
			break;

		case 5:
			num = mylist.size;
			DPRINTF("Student Numbers : %d\n", num);
			break;

		case 6:
			num =Students_counter_by_Iteration(mylist.head);
			DPRINTF("Student Numbers : %d\n", num);
			break;

		case 7:
			num = Students_counter_by_Recursion(mylist.head);
			DPRINTF("Student Numbers : %d\n", num);
			break;

		case 8:
			DPRINTF("Enter Node Number: ");
			gets(temp);
			num = atoi(temp);
			Retrieve_Item(num,&Student,&mylist);
			view_student(Student);
			break;

		case 9:
			DPRINTF("Enter Node Number from the end : ");
			gets(temp);
			num = atoi(temp);
			get_node_from_end_using_Iteration(&mylist,num);
			//get_node_from_end_using_pointers(&mylist,num);
			break;

		case 10:
			get_middle_student(&mylist);
			break;

		/*case 11:
			list_reverse_students();
			break;*/

		case 12:
			return 0;

		default:
			DPRINTF("\n Wrong Option: Try Again \n\n");
			break;
		}
	}
	return 0;
}

