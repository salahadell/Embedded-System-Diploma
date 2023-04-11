#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int m;
int *ab=&m;
m=29;
printf("address of m: %p\n value of m: %d\n\n",&m,m);
printf("address of pointer ab : %p\n content of pointer ab : %d\n\n",ab,*ab);
m=34;
printf("address of pointer ab : %p\n content of pointer ab : %d\n\n",ab,*ab);
*ab=7;
printf("address of m: %p\n value of m: %d\n\n",&m,m);

}
