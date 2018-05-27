/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int the_alias(char **av, list_t *list, shell_t *shell)
{
	if (!av || !av[1] || !av[2]) {
		if (!av || !av[1]) {
			show_list(list);
			shell->exit_status = 0;
			return (0);
		}
		if (av[2] == NULL) {
			shell->exit_status = 0;
			return (84);
		}
		my_putstr(the_getenv(av[1], list));
		my_putstr("\n");
	}
	maj_var_val(list, av[1], av[2]);
	shell->exit_status = 0;
	return (0);
}

int the_unalias(char **av, list_t *list, shell_t *shell)
{
	elem_t *e = NULL;

	if (!av || !av[1]) {
		my_putstr("unalias: Too few arguments.\n");
		shell->exit_status = 1;
		return (84);
	} else if (av[2]) {
		shell->exit_status = 0;
		return (84);
	}
	if (av[1] == NULL) {
		my_putstr("unalias: Too few arguments.\n");
		shell->exit_status = 1;
		return (0);
	}
	e = find_var_name(list, av[1]);
	rm_ele(list, e);
	shell->exit_status = 0;
	return (0);
}

char *change_alias(char *input, const list_t *list)
{
	char *cur = NULL;
	int pos = 0;

	if (!strncmp(input, "alias", 5) &&
	(input[5] == ' ' || input[5] == '\t' || input[5] == ';'))
		return (input);
	if (!strncmp(input, "unalias", 7) &&
	(input[7] == ' ' || input[7] == '\t' || input[7] == ';'))
		return (input);
	for (elem_t *e = list->first; e && input && (cur = strdup(e->data));
	e = e->next) {
		for (; cur[pos] && cur[pos] != '='; pos++);
		(pos >= 0) ? (cur[pos] = '\0') : (0);
		input = rplc_word(input, cur, cur + pos + 1);
	}
	return (input);
}
