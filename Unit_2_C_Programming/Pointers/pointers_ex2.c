#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char arr[27];
char *p;
p=arr;
for(int i=0;i<26;i++)
	*(p+i)=i+'A';

printf("The Alphabets are:\n");
for(int i=0;i<26;i++)
{
	printf("%c \t",*p+i);
  if(i==16)
		printf("\n");
}

}
