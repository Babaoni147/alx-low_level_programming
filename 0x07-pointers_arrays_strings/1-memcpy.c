#include "main.h"

/**
 * _memcpy - Function that copies memory area
 * @dest: New memory area
 * @src: Original memory area
 * @n: number of memory to be copied
 * Return: dest after copy
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
