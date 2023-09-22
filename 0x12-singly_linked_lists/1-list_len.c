#include "lists.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - function that return the number of element in the
 * linked_t list
 * @h: list name
 * Return: the number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t p = 0;

	while (h)
	{
		p++;
		h = h->next;
	}
	return (p);
}
