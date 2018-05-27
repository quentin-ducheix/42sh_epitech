/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int is_dlredir(tree_t *base)
{
	char *tempo = "<<";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_lredir(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	}
	if (is_start(base->exp, posi) == 0) {
		tempo2 = move_words(base->exp + posi, tempo);
		if (tempo2 == 0) {
			return ((tempo2 = is_dlredir(base)));
		} else
			return (84);
	}
	memset(base->exp + posi, '\0', 2);
	if (is_dlredir2(base, posi) == 84)
		return (84);
	tempo2 = subtree_maker(base, posi + 2, 4);
	return (tempo2);
}

int is_pipe(tree_t *base)
{
	char *tempo = "|";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_dlredir(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	}
	memset(base->exp + posi, '\0', 1);
	if (invalid_empt(base->exp + posi + 1) == 0
	|| invalid_empt(base->exp) == 0) {
		my_putstr("Invalid null command.\n");
		return (84);
	}
	if (subtree_maker(base, posi + 1, 3) == 0)
		return (0);
	if (is_pipe(base->left) == 1)
		if (is_pipe(base->right) == 1)
			return (1);
	return (0);
}

int is_and(tree_t *base)
{
	char *tempo = "&&";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_pipe(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	}
	memset(base->exp + posi, '\0', 2);
	subtree_maker(base, posi + 2, 1);
	if (is_and(base->left) == 1)
		if (is_and(base->right) == 1)
			return (1);
	return (0);
}

int is_or(tree_t *base)
{
	char *tempo = "||";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_and(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	}
	memset(base->exp + posi, '\0', 2);
	subtree_maker(base, posi + 2, 2);
	if (is_or(base->left) == 1)
		if (is_or(base->right) == 1)
			return (1);
	return (0);
}

int is_delim(tree_t *base)
{
	char *tempo = ";";
	int posi = getter_l_pos(base->exp, tempo);
	int tempo2 = 0;

	if (posi == 84) {
		(is_or(base) == 1) ? (tempo2 = 1) : (tempo2 = 0);
		return (tempo2);
	}
	memset(base->exp + posi, '\0', 1);
	subtree_maker(base, posi + 1, 0);
	if (is_delim(base->left) == 1)
		if (is_delim(base->right) == 1)
			return (1);
	return (0);
}
