#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Description: print 1 to 100, Fizz for multiple of 3, Buss for multiple
 * of 5 and FizzBuzz for multiple of both
 * Return: 0 (Success)
 */
int main(void)
{
	int a;

	for (a = 1; a <= 100; a++)
	{
		if (a % 15 == 0)
			printf("FissBuzz");
		else if (a % 3 == 0)
			printf("Fizz");
		else if (a % 5 == 0)
			printf("Buzz");
		else
			printf("%i", a);
		if (a < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
