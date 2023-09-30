#include "main.h"

/**
 * clear_bit - function that sets the value of a bit to 0
 * @n: pointer pointing to the number to change
 * @index: index of bit
 * Return: 1 if successfully and -1 error
 */
int  clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
