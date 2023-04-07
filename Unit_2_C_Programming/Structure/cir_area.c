#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14
#define calc_carea(r)  M_PI*r*r
int main()
{
	float r;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&r);
	printf("Area: %.2f",calc_carea(r));

}

