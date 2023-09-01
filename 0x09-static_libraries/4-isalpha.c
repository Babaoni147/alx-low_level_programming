#include "main.h"

/**
 * _isalpha - Entry point
 * @c: check for charaters
 * Return: 1 (Success)
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
