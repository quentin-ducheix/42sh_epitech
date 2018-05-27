/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int is_rredir(tree_t *base)
{
	char *tempo = ">";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84)
		return (1);
	if (is_start(base->exp, posi) == 0) {
		tempo2 = move_words(base->exp + posi, tempo);
		if (tempo2 == 0) {
			tempo2 = is_rredir(base);
			return (tempo2);
		} else
			return (84);
	}
	memset(base->exp + posi, '\0', 1);
	if (is_rredir2(base, posi) == 84)
		return (84);
	tempo2 = subtree_maker(base, posi + 1, 7);
	return (tempo2);
}

int is_drredir2(tree_t *base, int posi)
{
	if (invalid_empt(base->exp + posi + 2) == 0) {
		my_putstr("Invalid null command.\n");
		return (84);
	} else if (invalid_empt(base->exp) == 0) {
		my_putstr("Invalid null command.\n");
		return (84);
	}
	return (0);
}

int is_drredir(tree_t *base)
{
	char *tempo = ">>";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_rredir(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	} else if (is_start(base->exp, posi) == 0) {
		tempo2 = move_words(base->exp + posi, tempo);
		if (tempo2 == 0) {
			tempo2 = is_drredir(base);
			return (tempo2);
		} else
			return (84);
	}
	memset(base->exp + posi, '\0', 2);
	if (is_drredir2(base, posi) == 84)
		return (84);
	tempo2 = subtree_maker(base, posi + 2, 6);
	return (tempo2);
}

int is_lredir2(tree_t *base, int posi)
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

int is_lredir(tree_t *base)
{
	char *tempo = "<";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_drredir(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	} else if (is_start(base->exp, posi) == 0) {
		tempo2 = move_words(base->exp + posi, tempo);
		if (tempo2 == 0) {
			tempo2 = is_lredir(base);
			return (tempo2);
		} else
			return (84);
	}
	memset(base->exp + posi, '\0', 1);
	if (is_lredir2(base, posi) == 84)
		return (84);
	tempo2 = subtree_maker(base, posi + 1, 5);
	return (tempo2);
}
