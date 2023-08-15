#include <stdio.h>

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
	int c, d;

	for (c = 48; c <= 56; c++)
	{
		for (d  = 49; d <= 57; d++)
		{
			if (d > c)
			{
				putchar(c);
				putchar(d);
				if (c != 56 || d != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

