#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 * Return: 0 (success)
 */
int main(void)
{
	int c;

	for (c = 97; c < 123; c++)
	{
		if (c != 100 && c != 133)
		{
			putchar(c);
		}
	}
	putchar('\n');
	return (0);
}
