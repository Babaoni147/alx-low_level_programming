#include "main.h"

/**
 * _strlen_recursion - funtion that returns the length of a string
 * @s: Measured string
 * Return: 0 (Success)
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
		longit++;
		longit += _strlen_recursion(s + 1);
	}
	return (longit);
}
