#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _strlen - function that return the length of a string
 * @s: character
 * Return: value p
 */
int _strlen(const char *s)
{
	int p = 0;

	while (s[p] != '\0')
	{
		p++;
	}
	return (p);
}

/**
 * add_node - function that add a new mode at the beginning of a list
 * @head: The head of list_t
 * @str: Inserted element
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));

	if (add == NULL)
		return (NULL);
	add->str = strdup(str);

	add->len = _strlen(str);

	add->len = +strlen(str);
	add->next = *head;
	*head = add;

	return (add);
}
