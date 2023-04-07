#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14

float calc_carea(float r);
int main()
{
	float r;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&r);
	printf("Area: %.2f",calc_carea(r));

}
float calc_carea(float r)
{
	return r*r*M_PI;
}
