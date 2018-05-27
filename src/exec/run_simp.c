/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int easy_exe(char **av, shell_t *shell, __attribute__((unused))int val)
{
	int pid = 0;
	int stat = 0;
	int tempo = 0;

	if (shell->pipes_count && pipe(shell->pipefd) == -1)
		return (84);
	if ((pid = fork()) == -1)
		return (84);
	(pid == 0) ? (child_exe(av, shell, val)) : (0);
	if (shell->pipes_count > 0) {
		if ((tempo = pid_stock(pid, shell)) == 84)
			return (84);
	} else if (shell->pipes_count <= 0) {
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &stat, 0);
		signal(SIGINT, SIG_DFL);
	}
	if (WIFSIGNALED(stat) || WIFEXITED(stat))
		return ((tempo = take_error(stat, shell)));
	return (tempo);
}

char **easy_com2(shell_t *shell, char **av)
{
	char *tempo3 = NULL;

	for (int i = 0; av[i]; i++) {
		if (contains_dollar(av[i]) != 1)
			continue;
		tempo3 = av[i];
		av[i] = env_printin(av[i], shell->env, shell);
		if (av == NULL || av[i][0] == '\0') {
			tempo3++;
			my_putstr(tempo3);
			my_putstr(": Undifined variable.\n");
			return (NULL);
		}
	}
	return (av);
}

int easy_com3(shell_t *shell, char **av)
{
	char *blink = NULL;

	(shell->pipes_count > 0) ? (shell->pipes_count--) : (0);
	shell->exit_status = 1;
	my_putstr(av[0]);
	if ((blink = tgetstr("vb", NULL)) == NULL && isatty(0) == 1)
		return (84);
	if (isatty(0) == 1)
		tputs(blink, 0, write_char);
	my_putstr(": Command not found.\n");
	return (84);
}

int check_builtin(char **av)
{
	if (!strcmp("env", av[0]) || !strcmp("cd", av[0]) || !strcmp("setenv",
	av[0]) || !strcmp("unsetenv", av[0]) || !strcmp("alias", av[0]) ||
	!strcmp("history", av[0]) || !strcmp("unalias", av[0]) ||
	!strcmp("where", av[0]) || !strcmp("which", av[0]) ||
	!strcmp("echo", av[0]))
		return (1);
	else
		return (0);
}

int easy_com(const char *input, shell_t *shell)
{
	int tempo = 0;
	char **av = conv_array(input, " \t");
	int tempo2 = 0;

	av = easy_com2(shell, av);
	if (av == NULL || *av == NULL)
		return (84);
	if (check_builtin(av) == 1 && shell->pipes_count > 0) {
		tempo = easy_exe(av, shell, 1);
		return (tempo);
	} else
		tempo2 = is_builtin(av, shell);
	if (tempo2 == 0 || tempo2 == 84) {
		(tempo2) ? (shell->exit_status = 1) : (0);
		return (tempo2);
	} else if (look_path(av, shell) == 84) {
		if (easy_com3(shell, av) == 84)
			return (84);
	}
	return ((tempo = easy_exe(av, shell, 0)));
}
