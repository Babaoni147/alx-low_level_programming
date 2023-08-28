#include "main.h"

/**
 * set_string - function that sets the value of a pointer to a char
 * @s: pointer to pointer
 * @to: pointer char
 * Retunrn: 0 (Success)
 */
void set_string(char **s, char *to)
{
	*s = to;
}
