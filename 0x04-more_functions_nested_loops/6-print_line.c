#include "main.h"

/**
 * print_line - function that draw a straight line
 * @n: the number of times the character _ should be printed
 * Return: 0 (Success)
 */
void print_line(int n)
{
	int a;

	for (a = 0; a <= n; a++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
