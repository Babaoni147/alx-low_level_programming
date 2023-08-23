#include "main.h"

/**
 * puts_half - function that prints half of a string
 * @str: half string
 * Return: length (Success)
 */
void puts_half(char *str)
{
	int a, n, log;

	log = 0;

	for (a = 0; str[a] != '\0'; a++)
	{
		log++;
	}
	n = (log / 2);

	if ((log % 2) == 1)
	{
		n = ((log + 1) / 2);
	}

	for (a = n; str[a] != '\0'; a++)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}
