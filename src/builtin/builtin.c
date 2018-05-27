/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

static const builtin_t	built_po[] = {
	{"env", &the_printenv},
	{"setenv", &the_setenv},
	{"unsetenv", &the_unsetenv},
	{"cd", &the_cd},
	{"alias", &the_alias},
	{"history", &the_history},
	{"unalias", &the_unalias},
	{"where", &the_where},
	{"which", &the_which},
	{"echo", &my_echo},
	{NULL, NULL}
};

int is_builtin2(char **av, shell_t *shell)
{
	int tempor = 0;

	if (av[0][0] == '!') {
		tempor = bttf_com(av, shell);
		return (tempor);
	}
	if (strcmp(av[0], "exit") == 0) {
		tempor = the_exit(av, shell);
		return (tempor);
	}
	return (tempor);
}

int is_builtin(char **av, shell_t *shell)
{
	int tempor = 0;
	int i = 0;

	shell->exit_status = 0;
	if (!av || !av[0])
		return (0);
	if (av[0][0] == '!' || strcmp(av[0], "exit") == 0)
		return (is_builtin2(av, shell));
	for (; built_po[i].func != NULL && strcmp(av[0], built_po[i].name);
	i++);
	if (built_po[i].func == NULL)
		return (27);
	if (i == 4 || i == 6)
		tempor = built_po[i].func(av, shell->aliases, shell);
	else if (i == 5)
		tempor = built_po[i].func(av, shell->history, shell);
	else
		tempor = built_po[i].func(av, shell->env, shell);
	return (tempor);
}
