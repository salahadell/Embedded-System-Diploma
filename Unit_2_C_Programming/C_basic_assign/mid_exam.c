#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int sum_digits()
{
	static int sum;
	char c;
	scanf("%c",&c);
	if(c!='\n')
	{
		sum+=c-48;
		sum_digits();
	}
	return sum;
}
float sq_root(float num)
{
	return sqrt(num);

}
void reverse_digits()
{
	char c;
	scanf("%c",&c);
	if(c!='\n')
	{
		reverse_digits();
		printf("%d",c-48);
	}
	else
		printf("output:");

}
int ones_in_binary(int num)
{
	int count=0;
	int binary_num[32];
	for(int i=0;i<32; i++)
		binary_num[i]=0;
	for(int i=0;num>0; i++)
	{
		binary_num[i]=num%2;
		num=num/2;
	}

	for(int i=0;i<32; i++)
	{
		if(binary_num[i]==1)
			count++;
	}
	return count;
}
void unique_number(int size)
{                                    /*this soln is limited to the range of numbers up to 100 (size of freq array)
	                                  the practical soln is by using two nested loops */
	static int arr[10],freq[100];
	int i;
	bool flag=false;
	for(i=0;i<size;i++) //initialize the frequency array with zeros
		freq[i]=0;

	printf("Enter the elements:");
	fflush(stdin);fflush(stdout);
	for(i=0;i<size;i++)  //enter the elements of the array
	{
		scanf("%d",&arr[i]);
		freq[arr[i]]++;       //increase the frequency of each element
	}

	for(i=0;i<100;i++)
	{
		if(freq[i]==1)       //return the element which is entered once
		{
			flag=true;
			break;
		}
	}
	if(flag)
		printf("output:%d",i);
	else
		printf("there is no unique number");
}
int sum_two_numbers( int n1,int n2)
{
	static int sum=0;
	if(n1<=n2)
	{
		sum+=n1;
		sum_two_numbers(++n1,n2);
	}
	return sum;
}
void reverse_array(int arr[],int size)
{
	char temp;int j=0;
	for(int i=size-1;i>j;i--,j++)
	{
		temp=arr[j];
		arr[j]=arr[i];
		arr[i]=temp;
	}

}
void reverse_words(char arr[])
{
	int space_index;
	for(int i=0;i<strlen(arr);i++)
		if(arr[i]==' ')
		{
			space_index=i;
			break;
		}
	arr[space_index]='\0';
	printf("output:%s %s",&arr[space_index+1],arr);
}
int max_num_of_ones(int num)
{
	int count=0;
	while(num!=0)
	{
		num=(num&(num<<1));
		count++;
	}
	return count;
}

int main(void)
{
	/*int size,arr[100],i;
	printf("Enter size of the array:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&size);
	printf("Enter elements of the array:");
	fflush(stdout);fflush(stdin);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	reverse_array(arr,size);
	printf("output:");
	for(i=0 ;i<size ;i++)
		printf("%d ",arr[i]);*/
	/*char arr[100];
	printf("Enter your string:");
	fflush(stdin);fflush(stdout);
	gets(arr);
	reverse_words(arr);*/
	int num;
	printf("Enter a number:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	printf("output:%d",max_num_of_ones(num));
}

