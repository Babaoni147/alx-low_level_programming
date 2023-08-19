#include <stdio.h>

/**
 * main - First 50 fibonacci number
 * Return: 0 (Success)
 */
int main(void)
{
	int a;
	unsigned long fib1 = 0, fib2 = 1, sum;

	for (a = 0; a < 50; a++)
	{
		sum = fib1 + fib2;
		printf("%lu", sum);

		fib1 = fib2;
		fib2 = sum;

		if (a == 49)
			printf("\n");
		else
			printf(", ");
	}
	return (0);
}
