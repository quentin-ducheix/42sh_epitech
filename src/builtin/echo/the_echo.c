/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int check_it(shell_t *shell, int tmp, const char *str, int count)
{
	int verif = 0;

	if ((str[tmp] == 'n' || str[tmp] == 'e') && (str[tmp + 1] == '\0' ||
	str[tmp + 1] == 'n' || str[tmp + 1] == 'e')) {
		verif = 1;
		if (str[tmp] == 'n')
			shell->echo_option[0] = 1;
		else if (str[tmp] == 'e')
			shell->echo_option[1] = 1;
		if (str[tmp + 1] != '\0' && str[tmp + 1] != 'e' &&
		str[tmp + 1] != 'n') {
			(count == 1) ? (shell->echo_option[0] = 0) : (0);
			(count == 1) ? (shell->echo_option[1] = 0) : (0);
			(count == 1) ? (verif = 0) : (0);
		}
	}
	return (verif);
}

char check_str(const char *str, shell_t *shell, int count)
{
	int verif = 0;

	for (int tmp = 1; str[tmp] != '\0'; tmp++)
		verif = check_it(shell, tmp, str, count);
	(verif == 1) ? (count++) : (0);
	return (count);
}

int check_options(char **av, shell_t *shell)
{
	int count = 0;

	for (int tmp = 1; av[tmp] != NULL; tmp++) {
		if (av[tmp][0] == '-' && (av[tmp - 1][0] == '-' ||
		tmp - 1 == 0))
			count = check_str(av[tmp], shell, count);
	}
	return (count);
}

int contains_dollar(const char *str)
{
	for (int tmp = 0; str[tmp] != '\0'; tmp++) {
		if (str[tmp] == '$')
			return (1);
	}
	return (0);
}

int my_echo(char **av, list_t *env, shell_t *shell)
{
	(void)env;
	shell->echo_option[0] = 0;
	shell->echo_option[1] = 0;
	for (int tmp = (check_options(av, shell) + 1);
	av[tmp] != NULL; tmp++) {
		if (shell->echo_option[1] != 1)
			print_backs2(av[tmp]);
		else
			arg_print(av[tmp], shell);
		if (av[tmp + 1] != NULL)
			my_putstr(" ");
	}
	if (shell->echo_option[0] == 0)
		my_putstr("\n");
	return (0);
}
