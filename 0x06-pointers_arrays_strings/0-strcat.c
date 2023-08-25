#include "main.h"

/**
 * _strcat - Function that concatenates two strings
 * @dest: string 1 to recieve string 2
 * @src: string 2
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int  i;
	int  j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
