#include "main.h"

/**
 * _isdigit - function that check for digit
 * @c: digit
 * Return: 1 for digit 0 for others
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
