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
	int a;
	int b;
	float sum;
	printf("enter two numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&a,&b);
	sum=a+b;
	printf("sum: %f ",sum);
	return 0;

}
