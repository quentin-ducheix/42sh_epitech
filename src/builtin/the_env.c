/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *the_getenv(const char *var, const list_t *env)
{
	char *tempo = NULL;
	elem_t *actual = find_var_name(env, var);

	if (actual)
		tempo = strchr((char *)(actual->data), '=') + 1;
	else
		tempo = "";
	return (tempo);
}

int the_printenv(char **av, list_t *env, shell_t *shell)
{
	int tempo = 0;
	elem_t *actual = NULL;
	(void)shell;

	if (!av || !av[1]) {
		tempo = show_list(env);
		return (tempo);
	}
	if (av[2])
		return (0);
	actual = find_var_name(env, av[1]);
	if (actual)
		my_putstr(strchr((char *)(actual->data), '=') + 1);
	else
		my_putstr("");
	return (0);
}

int the_unsetenv(char **av, list_t *env, shell_t *shell)
{
	int tempo2 = 0;
	elem_t *tempo = NULL;

	if (av == NULL || av[1] == NULL) {
		my_putstr("unsetenv: Too few arguments.\n");
		shell->exit_status = 1;
		return (0);
	}
	tempo = find_var_name(env, av[1]);
	tempo2 = rm_ele(env, tempo);
	return (tempo2);
}

int the_setenv2(char **av, list_t *env, shell_t *shell)
{
	if (!av || !av[1]) {
		the_printenv(NULL, env, shell);
		return (0);
	} else if (av[1][0] != '_' && !IS_MIN(av[1][0]) && !IS_MAJ(av[1][0])) {
		my_putstr("setenv: Variable name must begin with a letter.\n");
		shell->exit_status = 1;
		return (0);
	}
	return (0);
}

int the_setenv(char **av, list_t *env, shell_t *shell)
{
	int tempo = 0;

	if (!av || !av[1] || (av[1][0] != '_' && !IS_MIN(av[1][0]) &&
	!IS_MAJ(av[1][0])))
		return (the_setenv2(av, env, shell));
	if (is_alphanum(av[1]) == 1) {
		my_putstr("setenv: Variable name must contain alphanumeric ");
		my_putstr("characters.\n");
		shell->exit_status = 1;
		return (0);
	} else if (av[2] == NULL) {
		maj_var_val(env, av[1], "");
		return (0);
	} else if (av[3]) {
		my_putstr("setenv: Too many arguments.\n");
		shell->exit_status = 1;
		return (0);
	}
	tempo = maj_var_val(env, av[1], av[2]);
	return (tempo);
}
