#include <stdio.h>

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
	char alp[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int c;

	for (c = 0; c < 52; c++)
	{
		putchar(alp[c]);
	}
	putchar('\n');
	return (0);
}
