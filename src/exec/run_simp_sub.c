/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *is_segfault(int status)
{
	if (status == 8)
		return ("Floating exception");
	else if (status == 11)
		return ("Segmentation fault");
	else
		return ("\0");
	return ("\0");
}

int take_error(int stat, shell_t *shell)
{
	int term = WTERMSIG(stat);
	int core = -1;
	char *termes = is_segfault(term);
	int tempo = 0;

	my_putstr(termes);
	if (WIFSIGNALED(stat) == 1)
		core = WCOREDUMP(stat);
	if (core == 1)
		my_putstr(" (core dumped)\n");
	else if (termes[0] != '\0')
		my_putstr("\n");
	if (termes[0] != '\0') {
		shell->exit_status = 128 + term;
		return (shell->exit_status);
	} else if (termes[0] == '\0') {
		shell->exit_status = WEXITSTATUS(stat);
		return (shell->exit_status);
	}
	return (tempo);
}

void child_exe(char **av, shell_t *shell, __attribute__((unused))int val)
{
	char **env = env_to_array(shell->env);
	int tempo = 0;

	if (shell->pipes_count > 0) {
		close(shell->pipefd[0]);
		if (dup2(shell->pipefd[1], 1) == -1)
			exit(1);
	}
	if (val == 1) {
		tempo = is_builtin(av, shell);
		if (dup2(shell->pipefd[0], 1) == -1)
			exit(1);
	} else
		tempo = execve(av[0], av, env);
	if (tempo == -1) {
		my_putstr(av[0]);
		my_putstr(": Exec format error.");
		my_putstr(" Binary file not executable.\n");
		exit(1);
	}
}

int pid_stock(int pid, shell_t *shell)
{
	void *tempo2 = &pid;
	int tempo = app_to_list(shell->pids, tempo2);

	if (tempo == 84) {
		kill(pid, SIGQUIT);
		return (84);
	}
	shell->pipes_count--;
	return (0);
}
