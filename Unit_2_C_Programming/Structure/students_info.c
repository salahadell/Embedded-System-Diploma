/*
 * students_info.c
 *
 *  Created on: Apr 7, 2023
 *      Author: salah
 */

#include <stdio.h>
#include <stdlib.h>
struct student
{
	char name[50];
	int roll;
	float mark;
};

void Read_Data(struct student *s)
{
	printf("Enter the roll number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s->roll);
	printf("Enter the name of the student:");
	fflush(stdin);fflush(stdout);
	gets(s->name);
	printf("Enter the marks:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&s->mark);
}
void Print_Data(struct student *s)
{
	printf("The information for roll number: %d\n",s->roll);
	printf("The student name: %s\n",s->name);
	printf("The student mark: %0.2f\n",s->mark);
}

int main()
{
	struct student students[10];

	printf("Enter information of the students:\n");
	for(int i=0;i<2;i++)
		Read_Data(&students[i]);

	printf("\nDisplaying information of the students:\n");
	for(int i=0;i<2;i++)
		Print_Data(&students[i]);
}
