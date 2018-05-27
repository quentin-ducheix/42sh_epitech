/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

elem_t *crt_ele(void *data)
{
	elem_t *elem = malloc(sizeof(elem_t));

	if (data == NULL)
		return (NULL);
	else
		elem->data = data;
	return (elem);
}

int app_to_list(list_t *list, void *data)
{
	elem_t *elem = crt_ele(data);

	if (elem == NULL)
		return (84);
	elem->next = NULL;
	elem->prev = list->last;
	(list->last != NULL) ? (list->last->next = elem) :
	(list->first = elem);
	list->last = elem;
	list->size++;
	return (0);
}
