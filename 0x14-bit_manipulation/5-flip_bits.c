#include "main.h"

/**
 * flip_bits - function that returns the number
 * @n: 1st number
 * @m: 2nd number
 * Return: 0 (success)
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int q, num = 0;
	unsigned long int currt;
	unsigned long int classic = n ^ m;

	for (q = 63; q >= 0; q--)
	{
		currt = classic >> q;
		if (currt & 1)
			num++;
	}
	return (num);
}
