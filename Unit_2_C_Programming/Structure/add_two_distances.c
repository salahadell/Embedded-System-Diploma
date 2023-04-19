/*
 * add_ two_distances.c
 *  Created on: Apr 7, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <stdlib.h>
struct distance
{
	int feet;
	float inch;
};

struct distance add(struct distance a,struct distance b )
{
	struct distance s;
	s.feet=a.feet+b.feet;
	s.inch=a.inch+b.inch;
	if(s.inch>=12)
	{
		s.feet+=(int)(s.inch/12);
		s.inch=12-s.inch;
	}
	return s;
}
void Read_Data1(struct distance *s)
{
	printf("Enter feet: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s->feet);
	printf("Enter inch: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&s->inch);
}

int main()
{
	struct distance a,b,c;
	printf("Enter information for first distance\n");
	Read_Data1(&a);
	printf("Enter information for second distance\n");
	Read_Data1(&b);
	c=add(a,b);
	printf("Sum of distances= %d'%.1f\"",c.feet,c.inch);
}
