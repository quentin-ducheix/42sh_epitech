/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int the_exit(char **av, shell_t *shell)
{
	for (int idx = (av[1] != NULL && av[1][0] == '-') ? (1) : (0);
	av[1] != NULL && av[1][idx] != '\0'; idx++) {
		if (av[1][idx] < '0' || av[1][idx] > '9') {
			my_putstr("exit: Expression Syntax.\n");
			return (84);
		}
	}
	if (av[1] != NULL && av[2] != NULL) {
		my_putstr("exit: Expression Syntax.\n");
		return (84);
	}
	if (av[1] != NULL)
		shell->exit_status = atoi(av[1]);
	else
		shell->exit_status = 0;
	shell->run = 1;
	return (0);
}
