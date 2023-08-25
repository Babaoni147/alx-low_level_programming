#include "main.h"

/**
 * reverse_array - funtion that reverses the content of an array of integer
 * @a: input
 * @n: nuber of element of array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i;
	int j;

	for (i = 0; i < n--; i++)
	{
		j = a[i];
		a[i] = a[n];
		a[n] = j;
	}
}
