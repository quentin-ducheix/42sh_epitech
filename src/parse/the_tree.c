/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

tree_t *the_init_small_tree(char *str, int ope)
{
	tree_t *tree = malloc(sizeof(*tree));

	tree->left = NULL;
	tree->right = NULL;
	tree->op = ope;
	tree->exp = str;
	return (tree);
}

int subtree_maker(tree_t *root, int pos, int ope)
{
	root->left = the_init_small_tree(root->exp, 8);
	root->right = the_init_small_tree(root->exp + pos, 8);
	if (!root->left || !root->right)
		return (0);
	root->op = ope;
	root->exp = NULL;
	return (1);
}

tree_t *exp_parser(char *str)
{
	tree_t *tree = NULL;

	if (count_chara(str, '"') % 2) {
		my_putstr("Unmatched \".\n");
		return (NULL);
	}
	if (!(tree = the_init_small_tree(str, 8)) || is_delim(tree) == 0)
		return (NULL);
	else
		return (tree);
	return (tree);
}
