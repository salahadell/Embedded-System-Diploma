#include <stdio.h>
#include <stdlib.h>
void DrawNumbers(int num);

int main(void)
{
	DrawNumbers(9);
	return 0;
}


void DrawNumbers(int num)
{   int i=0,j=0;
    while(i<=num)
    {
    for(;i<=num;i++)
    {
        printf("%d ",i);
    }
    j++;
    i=j;
    printf("\n");
    }
}
