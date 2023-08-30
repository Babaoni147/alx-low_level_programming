#include "main.h"


/**
 * factorial - function that returns the fctorial of number
 * @n: the number which fatorial is to return
 * Return: 0 (Success)
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
