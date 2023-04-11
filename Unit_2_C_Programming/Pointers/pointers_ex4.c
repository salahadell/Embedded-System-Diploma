#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int arr[100];
	int *ps,size;
	ps=arr;
	printf("Enter number of element of the array: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);
	printf("Enter element of the array:\n");
	fflush(stdin);fflush(stdout);
	for(int i=0;i<size;i++)
	{
		printf("element-%d: ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",ps);
		ps++;
	}
	ps--;

	printf("Reverse array is:\n");
	fflush(stdin);fflush(stdout);
	for(int i=size;i>0;i--)
		printf("element-%d: %d\n",i,*ps--);
}
