#include "main.h"

/**
 * get_bit - Function that return the value of a bit at a given index
 * @n: Shearch number
 * @index: index of n
 * Return: the value of the bit at index or -1 for error(-1)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int pow;

	if (index > 63)
		return (-1);

	pow = (n >> index) & 1;

	return (pow);
}
