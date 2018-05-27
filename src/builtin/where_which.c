/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int the_where(char **av, list_t *env, shell_t *shell)
{
	if (av[1] == NULL) {
		my_putstr("where: Too few arguments.\n");
		shell->exit_status = 1;
		return (0);
	}
	if (!strcmp("env", av[0]) || !strcmp("cd", av[0]) || !strcmp("setenv",
	av[0]) || !strcmp("unsetenv", av[0]) || !strcmp("alias", av[0]) ||
	!strcmp("history", av[0]) || !strcmp("unalias", av[0]) ||
	!strcmp("where", av[0]) || !strcmp("which", av[0]) ||
	!strcmp("echo", av[0])) {
		my_putstr(av[0]);
		my_putstr(" is a shell built-in\n");
	}
	(void)env;
	return (0);
}

int the_which(char **av, list_t *env, shell_t *shell)
{
	if (av[1] == NULL) {
		my_putstr("which: Too few arguments.\n");
		shell->exit_status = 1;
		return (0);
	}
	if (!strcmp("env", av[0]) || !strcmp("cd", av[0]) || !strcmp("setenv",
	av[0]) || !strcmp("unsetenv", av[0]) || !strcmp("alias", av[0]) ||
	!strcmp("history", av[0]) || !strcmp("unalias", av[0]) ||
	!strcmp("where", av[0]) || !strcmp("which", av[0]) ||
	!strcmp("echo", av[0])) {
		my_putstr(av[0]);
		my_putstr(" is a shell built-in\n");
		return (0);
	}
	(void)env;
	return (0);
}
