#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - Function that excutes a function given
 * as a parameter on each element of an array
 * @array: array
 * @size: the size of the array
 * @action: Pointer to the funtion you need to use
 * Return: 0 (Success)
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	i = 0;

	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
