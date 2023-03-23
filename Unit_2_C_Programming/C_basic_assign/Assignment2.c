/*
 * Assignment2.c
 *
 *  Created on: Mar 23, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	printf("Enter an integer you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	if(!(a%2))
		printf("%d is even",a);
	else
		printf("%d is odd",a);


   return 0;
}

