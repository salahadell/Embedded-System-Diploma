/*
 * Reverse_Sentence.c
 *
 *  Created on: Mar 29, 2023
 *      Author: salah
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reverse_Sentence();

int main()
{
	printf("Enter a sentence: ");
	fflush(stdin);fflush(stdout);
	Reverse_Sentence();
	return 0;
}

void Reverse_Sentence()
{
	char a;
   scanf("%c",&a);
	if(a!='\n')
	{
		Reverse_Sentence();
	    printf("%c",a);
	}


}

