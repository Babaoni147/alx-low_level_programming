#include "main.h"

/**
 * print_triangle - function that print triangle
 * @size: size of triangle
 * Return: 0 (Success)
 */
void print_triangle(int size)
{
	int a, b, c;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (a = 0; a <= size; a++)
		{
			for (c = size - a; c >= 1; c--)
			{
				_putchar(' ');
			}
			for (b = 1; b <= a; b++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}

