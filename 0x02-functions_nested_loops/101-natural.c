/*
 * File: 101_natural.c
 * Athur: Obah Edwin
 */
#include <stdio.h>
/**
 * main - list of nutural numbers below 1024, multiple of 3 or 5.
 * Return: 0 (Success)
 */
int main(void)
{
int i;
sum = 0;
for (i = 0; i < 1024; 1++)
{
if ((i % 3) == 0 || (i % 5) == 0)
sum += i;
}
printf("%n\n", sum);
	return (0);
}
