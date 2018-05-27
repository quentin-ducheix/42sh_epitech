/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int rm_ele(list_t *list, elem_t *elem)
{
	if (elem == NULL)
		return (0);
	(elem == list->first) ? (list->first = elem->next)
	: (elem->prev->next = elem->next);
	(elem == list->last) ? (list->last = elem->prev)
	: (elem->next->prev = elem->prev);
	elem->prev = NULL;
	elem->next = NULL;
	free(elem);
	free(elem->data);
	list->size--;
	return (0);
}

elem_t *get_ele_idx(list_t *list, int idx)
{
	elem_t *e = list->first;

	for (int i = 0; e && i < idx; i++, e = e->next);
	return (e);
}

list_t *init_list(void)
{
	list_t *list = malloc(sizeof(*list));

	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

int show_list(const list_t *list)
{
	for (elem_t *cur = list->first; cur; cur = cur->next) {
		my_putstr((char *)(cur->data));
		my_putstr("\n");
	}
	return (0);
}
