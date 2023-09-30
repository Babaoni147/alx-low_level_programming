#include "main.h"

/**
 * get_endianness - function that checks the endianness
 * Return: 0 if big endia, 1 if little endian
 */
int get_endianness(void)
{
	int q = 1;
	char *c = (char *) &q;

	return (*c);
}
