#include "main.h"

/**
 * print_rev - function that print a string in reverse
 * @s: Sring to be printed
 * Return: 0 (Success)
 */
void print_rev(char *s)
{
	int rev = 0;
	int i;

	while (*s != '\0')
	{
		rev++;
		s++;
	}
	s--;
	for (i = rev; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
