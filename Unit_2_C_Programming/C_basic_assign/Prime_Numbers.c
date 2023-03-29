#include <stdio.h>
#include <stdlib.h>

void prime_numbers(int i , int j,int arr[],int *numberOfelemnts);

int main()
{
	int a ,b,arr[1000],numberOfelemnts=0;
	printf("Enter two numbers(intervals): ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&a,&b);

	prime_numbers(a,b,arr,&numberOfelemnts);

	printf("prime numbers between %d and %d are:  ",a,b);
	for(int i=0;i<numberOfelemnts;i++)
		printf("%d ",arr[i]);
	return 0;
}

void prime_numbers(int i , int j,int arr[],int *numberOfelemnts)
{
	int count=0;
	for(;i<=j;i++)
	{
		int flag=0;
		if(i==0 || i==1 || (!(i%2) && i!=2)) //ignore 0 & 1 & even numbers
			continue;

		else if(i==2)         //special case for number 2 as it is a prime number
			arr[count++]=2;

		/*check if each number in the interval is divisible by any number
	      smaller than the number itself*/
		else
		{
			for(int k=2;k<i;k++)
			{
				if(!(i%k))
				{
					flag=1;
					break;
				}
			}

			if(flag==0)
				arr[count++]=i;
		}
	}

	*numberOfelemnts=count;
}
