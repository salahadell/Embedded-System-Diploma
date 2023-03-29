/*
 * Factorial.c
 *
 *  Created on: Mar 29, 2023
 *      Author: salah
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int i );

int main()
{
	int a ;
	printf("Enter a positive number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	printf("Factorial of %d = %d  ",a,factorial(a));
	return 0;
}

int factorial(int a)
{
	if(a==0||a==1 )
		return 1;
	else
		return (a*factorial(a-1));

}
