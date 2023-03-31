/*
 * least_sig_bit.c
 *
 *  Created on: Mar 30, 2023
 *      Author: salah
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int LeastSegBit(int num)
{
	int arr[1000];
	for(int i=0;num>0;i++)
	{
		arr[i]=num%2;
		num=num/2;
	}
	return arr[3];
}
int powerofthree(int num)
{
	double x;
	x =log(num)-log(3);
	if(x==trunc(x))
		return 0;
	else
		return 1;
}
void swap2arrays(char arr1[],char arr2[])
{
	int i,j;
	char temp;
	int length1= strlen(arr1);
	int length2= strlen(arr2);
	j=(length2>length1)?length2:length1;
	for( i=0;i<=j;i++ )
	{
		temp=arr1[i];
		arr1[i]=arr2[i];
		arr2[i]=temp;
	}
}
int clear_bit(int pos ,int number)
{
	number&=~(1<<pos);
	return number;
}
void reverse_array(char arr[])
{
	int i,j=0;
	char temp;
	for(i=(strlen(arr)-1);i>j;i--)
	{
		temp=arr[j];
		arr[j]=arr[i];
		arr[i]=temp;
		j++;

	}
}
int last_occurence(char arr[],char number)
{
	int lo=-1;
	for(int i=0;i<strlen(arr);i++)
	{
		if(arr[i]==number)
			lo=i;
	}
	return lo;

}

int main()
{
	/*char arr1[100], arr2[100];
	printf("Enter a string : ");
	fflush (stdin);fflush(stdout);
	gets (arr1);
	printf("Enter another string : ");
	fflush(stdin);fflush (stdout);
	gets(arr2);
	printf("First array: %s\n",arr1);
	printf("Second array: %s\n",arr2);
	swap2arrays(arr1,arr2);
	printf("First array: %s\n",arr1);
	printf("Second array: %s\n",arr2);*/

	/*int number,pos;
	printf("Input Number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	printf("Bit Position: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&pos);
	printf("Result = %d",clear_bit( pos , number));*/

	/*char arr[1000];
	printf("Enter array elements: ");
	fflush(stdin);fflush(stdout);
	gets(arr);
	reverse_array(arr);
	printf("The reverse array: %s ",arr);*/

	/*char arr[1000];
	char number;
	printf("Enter array elements: ");
	fflush(stdin);fflush(stdout);
	gets(arr);
	printf("Enter the number: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&number);
	printf("result :%d ",last_occurence(arr,number));*/

}

