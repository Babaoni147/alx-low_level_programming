#include "main.h"

/**
 * _atoi - function that convert a string to an integer
 * @s: string parameter
 * Return: 0 for no number but 1 for number
 */
int _atoi(char *s)
{
	int i, b, c, len, f, digit;

	i = 0;
	b = 0;
	c = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
	{
		if (s[i] == '-')
			++b;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] = '0';
			if (b % 2)
				digit = -digit;
			c = c * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')

				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	return (c);
}
