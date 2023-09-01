#include "main.h"

/**
 * _strpbrk - function that searhes a strin for any of a set of byte
 * @s: first string
 * @accept: second string
 * Return: 0 (Success)
 */
char *_strpbrk(char *s, char *accept)
{
	int k;

	while (*s)
	{
		for (k = 0; accept[k]; k++)
		{
			if (*s == accept[k])
				return (s);
		}
		s++;
	}
	return ('\0');
}
