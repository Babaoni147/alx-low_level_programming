#include "main.h"

/**
 * _isupper - function to check uppercase
 * @c: uppercase
 * Return: 1 for uppercase, 0 for others
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}
