/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int print_history(list_t *histo, shell_t *shell)
{
	elem_t *elem = histo->first;

	for (int i = 0; elem; i++, elem = elem->next)
		printf("%d %s\n", i, (char *)elem->data);
	shell->exit_status = 0;
	return (0);
}

int the_history(char **av, list_t *histo, shell_t *shell)
{
	elem_t *elem = NULL;
	int tempo = 0;

	if (!av[1]) {
		tempo = print_history(histo, shell);
		return (tempo);
	}
	if (is_number(av[1]) == 1) {
		my_putstr("histo: Badly formed number.\n");
		shell->exit_status = 1;
		return (0);
	}
	elem = get_ele_idx(histo, atoi(av[1]) - 1);
	if (elem) {
		my_putstr(av[1]);
		my_putstr(" ");
		my_putstr((char *)elem->data);
		my_putstr("\n");
	}
	return (0);
}
