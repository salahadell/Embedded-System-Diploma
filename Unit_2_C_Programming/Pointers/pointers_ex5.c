#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
	char name[50];
	int id;
}ep1,ep2={"salah",10};
int main(void)
{
	struct employee *arr[10];
	struct employee *(*p_arr)[10];

	*arr=&ep1;
	*(arr+1)=&ep2;
	p_arr=&arr;
	strcpy((*(*p_arr))->name,"Alex");         //&ep1 ->name
	(**(*p_arr)).id=1200;                     //ep1   .id

	printf("Employee Name: %s\n",(*(*p_arr))->name);
	//printf("Employee Name: %s\n",(**(*p_arr+1)).name);
	printf("Employee ID: %d\n",(*(*p_arr))->id);
	//printf("Employee ID: %d\n",(**(*p_arr+1)).id);



}
