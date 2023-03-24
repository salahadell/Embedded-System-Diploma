/*
 * Assignment2.c
 *
 *  Created on: Mar 23, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <stdlib.h>
int Facto(int number);
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

	/*Ex4
	float a;
	printf("enter a number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&a);
	if(a>0)
		printf("%.2f is positive ",a);
	else if(a<0)
		printf("%.2f is negative ",a);
	else
		printf("You entered zero ");*/

	/*Ex5
	char a;
	printf("enter a character: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&a);
	if((a>='a'||a>='A')&&(a<='z'||a<='Z'))
		printf("%c is an alphabet ",a);
	else
		printf("%c is not an alphabet ",a);*/

	/*Ex6
	int a,sum=0;
	printf("enter an integer: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&a);
	for(int i=0;i<a;i++)
		sum+=i+1;
	printf("Sum = %d",sum);*/

	/*Ex7
	int a,fact=1;
	printf("enter an integer: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&a);
	if(a<0)
		printf("ERROR!!! Factorial of negative number doesn't exist");
	else
	{
		//using iteration faster and less memory
		for(int i=0;i<a;i++)
			fact*=i+1;
		printf("Factorial =%d ",fact);

		//using recursion slower because calling the stack and more memory
		//printf("Factorial =%d ",Facto(a));
	}*/

	/*Ex8
	char operator;
	float op1,op2;
	printf("Enter an operator either + or - or / or * : ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&operator);
	printf("Enter two operands: ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f",&op1,&op2);
	switch(operator)
	{
	case '*':
		printf("%.1f %c %.1f = %.1f ",op1,operator,op2,op1*op2);
		break;
	case '/':
			printf("%.1f %c %.1f = %.1f ",op1,operator,op2,op1/op2);
			break;
	case '+':
			printf("%.1f %c %.1f = %.1f ",op1,operator,op2,op1+op2);
			break;
	case '-':
			printf("%.1f %c %.1f = %.1f ",op1,operator,op2,op1-op2);
			break;
	}*/
	return 0;
}

int Facto(int number)
{
	if(number==0||number==1)
		return 1 ;
	else
		return (number*Facto(number-1));
}

