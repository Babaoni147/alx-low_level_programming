#include "main.h"

/**
 * set_bit - function that set the value of a bit to 1
 * at a given index
 * @n: pointer pointing to the number to change
 * @index: the index, starting from 0
 * Return: 1 if it worked or -1 for error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
