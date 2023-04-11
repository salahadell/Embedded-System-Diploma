#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
char string[100];
char *ps;
int size;
ps=string;
printf("Enter a string: ");
fflush(stdin);fflush(stdout);
gets(string);

for(size=0;*ps;size++)
   ps++;
ps--; //after finishing the loop ps pointed to the \0 element so w decrease it by one to point to last char;

printf("Reverse of the string is: ");
for(;size>0;size--)
	printf("%c",*ps--);

}
