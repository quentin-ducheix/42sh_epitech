/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int manage_input(char *geted, shell_t *sh)
{
	char *expr = skip_empty(geted);
	tree_t *expr_tree;
	char *tempo = NULL;

	sh->count++;
	if (!expr || *expr == '\0')
		return (0);
	if (expr[0] != '!')
		app_to_list(sh->history, strdup(expr));
	if ((tempo = rplc_word(expr, "\"\"", "")) == NULL)
		return (84);
	if ((tempo = change_alias(tempo, sh->aliases)) == NULL)
		return (84);
	if ((tempo = glob_change(tempo)) == NULL)
		return (84);
	sh->pipes_count = 0;
	expr_tree = exp_parser(tempo);
	if (expr_tree)
		exe_tree(expr_tree, sh);
	return (0);
}
