#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int main()
{
	/*Ex1(find sum of two matrix of order 2*2)
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
	}*/

	/*Ex2(calculate the average using arrays)
	float arr [100];
	int i,n;float avr=0;
	printf("Enter the number of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter number: ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&arr[i]);
	}
	for(i=0;i<n;i++)
		avr+=arr[i];
	printf("Average = %0.2f",avr/n);*/

	/*Ex3(find transpose of the matrix)
	int matr [100][100];
	int trans [100][100];
	int i,r,c,j;
	printf("Enter the number of row and columns : ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&r,&c);
	printf("Enter element of the matrix:\n");

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter Elements a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&matr[i][j]);
		}
	}

	printf("Entered matrix:\n ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",matr[i][j]);
			trans[j][i]=matr[i][j];
		}
		printf("\n");
	}

	printf("transpose matrix:\n ");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
			printf("%d\t",trans[i][j]);
		printf("\n");
	}*/

	/*Ex4 (insert an element into an array)
	int i,num,inserted,loc;
	int arr [100];
	printf("Enter number of elements:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);

	printf("Enter the element to be inserted: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&inserted);
	printf("Enter the location: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&loc);

	for(i=num-1;i>=loc-1;i--)
		arr[i+1]=arr[i];
	arr[loc-1]=inserted;

	for(i=0;i<num+1;i++)
		printf("%d  ",arr[i]);*/

	/*Ex5 (searching for an element )
	int i,num,searched;
	int arr [100];
	bool found=false;
	printf("Enter number of elements:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);

	printf("Enter the element to be searched: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&searched);

	for(i=0;i<num;i++)
	{
		if(arr[i]==searched)
		{
			printf("Number found at the location= %d",i+1);
			found=true;
			break;
		}
	}
	if(!found)
		printf("Number not found");*/

	/*Ex6 (find the frequency of a character in a string)
	char string [100],searched_char;
	int freq=0;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(string);
	printf("Enter a character to find the frequency : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&searched_char);
	for(int i=0;i<strlen(string);i++)
	{
		if(string[i]==searched_char)
			freq+=1;
	}
	printf("Frequency of %c = %d ",searched_char,freq);*/
	return 0;

}
