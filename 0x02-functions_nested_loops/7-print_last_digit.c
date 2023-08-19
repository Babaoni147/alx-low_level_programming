#include "main.h"

/**
 * print_last_digit - Entry point
 * @n: Last digit of a number
 * Return: 0 (SSuccess)
 */
int print_last_digit(int n)
{
	int p;

	p = n % 10;
	if (p < 0)
	{
		_putchar(-p + 48);
		return (-p);
	}
	else
	{
		_putchar(p + 48);
		return (p);
	}
}
