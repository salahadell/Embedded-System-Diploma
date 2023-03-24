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
	/*Ex1
	int a;
	printf("Enter an integer you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	if(!(a%2))
		printf("%d is even",a);
	else
		printf("%d is odd",a);*/

	/*Ex2
	char choice;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&choice);
	switch (choice)
	{
	case 'a':
	case 'A':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
	case 'i':
	case 'I':
	case 'e':
	case 'E':
	{
		printf("%c is a vowel",choice);
	    break;
	}
	default:
	    printf("%c is a consonant",choice);
	    break;
	}*/
	/*Ex3
	float a,b,c;
	printf("enter three numbers: ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f %f",&a,&b,&c) ;
	if(a>=b)
	{
		if(a>=c)
			printf("largest number= %.2f ",a);
		else
			printf("largest number= %.2f ",c);
	}
	else
	{
		if(b>=c)
			printf("largest number= %.2f ",b);
		else
			printf("largest number= %.2f ",c);
	}*/

	float a;
	printf("enter a number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&a);
	if(a>0)
		printf("%.2f is positive ",a);
	else if(a<0)
		printf("%.2f is negative ",a);
	else
		printf("You entered zero ");
	return 0;
}

