#include "main.h"

/**
 * swap_int - function that swap the value of two integers.
 * @a: integer to swap
 * @b: integer to swap
 * Return: 0 (Success)
 */
void swap_int(int *a, int *b)
{
	int m;

	m = *a;
	*a = *b;
	*b = m;
}
