#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - functio that returns a pointer to a newly
 * allcated space in memory which contain
 * a copy of of the string given as a parameter
 * @str: char
 * Return: 0 (Success)
 */
char *_strdup(char *str)
{
	char *aaa;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	aaa = malloc(sizeof(char) * (i + 1));

	if (aaa == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		aaa[r] = str[r];

	return (aaa);
}
