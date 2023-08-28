#include "main.h"

/**
 * _strstr - function that locate a substring
 * @haystack: main string
 * @needle: substring
 * Return: 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *s = haystack;
		char *p = needle;

		while (*s == *p && *p != '\0')
		{
			s++;
			p++;
		}
		if (*p == '\0')
			return (haystack);
	}
	return (0);
}
