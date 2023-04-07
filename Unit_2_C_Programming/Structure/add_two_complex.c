/*
 * add_two_complex.c
 *
 *  Created on: Apr 7, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <stdlib.h>
struct complex
{
	float real;
	float img;
};

struct complex add_complex(struct complex a,struct complex b)
{
	struct complex s;
	s.real=a.real+b.real;
	s.img=a.img+b.img;

	return s;
}
void Read_Data2(struct complex *s)
{
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&s->real,&s->img);
}

int main()
{
	struct complex a,b,c;
	printf("For first complex number\n");
	Read_Data2(&a);
	printf("For second complex number\n");
	Read_Data2(&b);
	c=add_complex(a,b);
	printf("Sum = %.1f+%.1fi",c.real,c.img);
}
