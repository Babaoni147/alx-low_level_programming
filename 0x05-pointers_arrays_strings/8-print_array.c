#include "main.h"

/**
 * print_array - function that prints n elements of an array of intgeter
 * @n: number of element of the array to be printed
 * @a: array
 * Return: 0 (Success)
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < (n - 1); i++)
	{
		printf("%d, ", a[i]);
	}
	if (i == (n - 1))
	{
		printf("%d", a[n - 1]);
	}
	printf("\n");
}
