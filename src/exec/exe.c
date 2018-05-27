/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

static int (*tree_things[])(tree_t *, tree_t *, shell_t *) = {
	&do_delim,
	&do_and,
	&do_or,
	&do_pipe,
	&do_dlredir,
	&do_lredir,
	&do_drredir,
	&do_rredir,
	NULL
};

int exe_tree(tree_t *tree, shell_t *shell)
{
	int tempo = 0;
	char *tempo2 = NULL;

	if (!tree)
		return (84);
	if (tree->op < 8) {
		tempo = tree_things[tree->op](tree->left, tree->right, shell);
		return (tempo);
	}
	tempo2 = skip_empty(tree->exp);
	tempo = easy_com(tempo2, shell);
	return (tempo);
}
