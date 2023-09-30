#include "main.h"

/**
 * print_binary - function that prints the binary repsentation of a number
 * @n: Input number
 * Return: printed binary number
 */
void print_binary(unsigned long int n)
{
	int q, num = 0;
	unsigned long int currt;

	for (q = 63; q >= 0; q--)
	{
		currt = n >> q;

		if (currt & 1)
		{
			_putchar('1');
			num++;
		}
		else if (num)
			_putchar('0');
	}
	if (!num)
		_putchar('0');
}
