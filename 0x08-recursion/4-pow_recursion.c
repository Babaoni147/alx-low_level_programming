#include "main.h"

/**
 * _pow_recursion - function that returns the vaule of x
 * raise to the power y
 * @x: number value to be raise
 * @y: power
 * Return: 0 (Success)
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
