#include "main.h"

/**
 * print_sign - Entry point
 * @n: print negative or positive
 * Return: 1 (Print +), 0 (Print 0) or -1 (Print -)
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
	_putchar('\n');
}
