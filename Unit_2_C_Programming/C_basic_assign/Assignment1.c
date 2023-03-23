#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*Ex1
	printf("C Programming");*/
	/*Ex2
	int a;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&a);
	printf("you entered: %d",a);*/
	/*Ex3
	int a;
	int b;
	int sum;
	printf("enter two numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&a,&b);
	sum=a+b;
	printf("sum: %d ",sum);*/
	/*Ex4
	float a;
	float b;
	float product;
	printf("enter two numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&a,&b);
	product=a*b;
	printf("product: %f ",product);*/
	char a;
	printf("enter a character: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&a);
	printf("ASCII value of %c = %d ",a,a);
	return 0;

}
