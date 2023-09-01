#include "main.h"

/**
 * _puts - function that print a string
 * @str: string
 * Return: 0 (Success)
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
