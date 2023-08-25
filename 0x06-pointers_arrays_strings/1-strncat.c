#include "main.h"

/**
 * _strncat - function that concatenates two strings
 * @n: number of bytes from src
 * @dest: sting to be concated into
 * @src: sting to concate
 * Return: dest (Success)
 */
char *_strncat(char *dest, char *src, int n)
{
	int a;
	int c;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	c = 0;
	while (c < n && src[c] != '\0')
	{
		dest[a] = src[c];
		a++;
		c++;
	}
	dest[a] = '\0';
	return (dest);
}
