#include "lists.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - that print all the element of a List_t list
 * @h: list name to be printed
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	int p = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		p++;
		h = h->next;
	}
	return (p);
}
