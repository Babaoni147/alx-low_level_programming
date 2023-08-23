#include "main.h"

/**
 * *_strcpy - function that copies the sttring pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer ponter to by dest
 * @dest: copy to
 * @src: copy from
 * Return: 0 (Success)
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int c = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; c  < l; c++)
	{
		dest[c] = src[c];
	}
	dest[l] = '\0';
	return (dest);
}
