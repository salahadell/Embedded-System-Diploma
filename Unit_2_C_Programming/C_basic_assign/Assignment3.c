#include <stdio.h>
#include <stdlib.h>

int main()
{
	//find sum of two matrix of order 2*2
	float mat1 [2][2];
	float mat2 [2][2];
	int i,j;
	printf("Enter the element of first matrix \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&mat1[i][j]);
		}
	}
	printf("Enter the element of second matrix \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&mat2[i][j]);
			mat2[i][j]+=mat1[i][j];
		}
	}
	printf("Sum of matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%0.1f\t",mat2[i][j]);
		}
		printf("\n");
	}

	return 0;
}
