#include "main.h"

/**
 * _memset - function that fills memory with a constant byte
 * @s: located area of memory to be filled
 * @b: constant byte to be filled in
 * @n: the first number of memory to be filled
 * Return: change array
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
