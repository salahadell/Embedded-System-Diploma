/*
 * student_info.c
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
	printf("Enter information of the student\n");
	printf("Enter the name of the student:");
	fflush(stdin);fflush(stdout);
	gets(s->name);
	printf("Enter the roll number of the student:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s->roll);
	printf("Enter the mark of the student:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&s->mark);
}
void Print_Data(struct student *s)
{
	printf("\nDisplaying information of the student:\n");
	printf("The student name: %s\n",s->name);
	printf("The student roll: %d\n",s->roll);
	printf("The student mark: %0.2f\n",s->mark);
}
int main(){
	struct student s;
	Read_Data(&s);
	Print_Data(&s);
	return 0;
}
