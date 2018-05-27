/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int is_rredir2(tree_t *base, int posi)
{
	if (invalid_empt(base->exp + posi + 1) == 0) {
		my_putstr("Invalid null command.\n");
		return (84);
	} else if (invalid_empt(base->exp) == 0) {
		my_putstr("Invalid null command.\n");
		return (84);
	}
	return (0);
}

int is_dlredir2(tree_t *base, int posi)
{
	if (invalid_empt(base->exp + posi + 2) == 0) {
		my_putstr("Invalid null command.\n");
		return (84);
	} else if (invalid_empt(base->exp)) {
		my_putstr("Invalid null command.\n");
		return (84);
	}
	return (0);
}