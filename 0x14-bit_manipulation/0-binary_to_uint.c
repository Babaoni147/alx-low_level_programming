#include "main.h"

/**
 * binary_to_uint - function that convert a binary number
 * to an unsigned int
 * @b: Pointer pointing to a string of 0 and 1 chars
 * Return: The converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int q;
	unsigned int pow = 0;

	if (!b)
		return (0);
	for (q = 0; b[q]; q++)
	{
		if (b[q] < '0' || b[q] > '1')
			return (0);
		pow = 2 * pow + (b[q] - '0');
	}

	return (pow);
}
