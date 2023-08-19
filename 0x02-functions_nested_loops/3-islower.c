#include "main.h"

/**
 * _islower - Entry point
 * @c: check lower case charaters
 * Return: 1 for lower case and 0 for others
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
