#include "main.h"

/**
 * puts2 - function that prints every other charater of sting
 * @str: charater
 * Return: 0 (Success)
 */
void puts2(char *str)
{
	int log = 0;
	int p = 0;
	char *y = str;
	int o;

	while (*y != '\0')
	{
		y++;
		log++;
	}
	p = log - 1;
	for (o = 0; o <= p; o++)
	{
		if (o % 2 == 0)
		{
			_putchar(str[o]);
		}
	}
	_putchar('\n');
}
