/*
 ============================================================================
 Name        : PowerFun.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int PowerFun(int base, int power);
int main(void)
{
	int base,power;
	printf("Enter base number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number(positive integer):");
	fflush(stdin);fflush(stdout);
	scanf("%d",&power);
	printf("%d^%d = %d",base,power,PowerFun(base,power));
}
int PowerFun(int base ,int power)
{
	if(power==0)
		return 1;
	else
		return base=base*PowerFun(base,power-1);
}
