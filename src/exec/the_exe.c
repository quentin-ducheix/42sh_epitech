/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int do_delim(tree_t *left, tree_t *right, shell_t *shell)
{
	int tempo = 0;
	int tempo2 = 0;

	tempo = exe_tree(left, shell);
	tempo2 = exe_tree(right, shell);
	if (tempo || tempo2)
		return (0);
	return (84);
}

int do_and(tree_t *left, tree_t *right, shell_t *shell)
{
	int tempo = 0;
	int tempo2 = exe_tree(left, shell);

	if (shell->exit_status == 0)
		tempo = exe_tree(right, shell);
	else
		return (tempo2);
	return (tempo);
}

int do_or(tree_t *left, tree_t *right, shell_t *shell)
{
	int ret = exe_tree(left, shell);
	int tempo = 0;

	if (shell->exit_status != 0)
		tempo = exe_tree(right, shell);
	else
		return (ret);
	return (tempo);
}

int do_pipe(tree_t *left, tree_t *right, shell_t *shell)
{
	int tempo = 0;

	shell->pipes_count++;
	exe_tree(left, shell);
	if (shell->exit_status != 0) {
		tempo = dup2(shell->bk[0], 0);
		return (84);
	}
	if (dup2(shell->pipefd[0], 0) == -1)
		return (84);
	close(shell->pipefd[1]);
	tempo = exe_tree(right, shell);
	if (shell->exit_status != 0) {
		tempo = dup2(shell->bk[0], 0);
		return (84);
	}
	(shell->pipes_count == 0) ? (tempo = dup2(shell->bk[0], 0)) : (0);
	if (tempo == -1 && shell->pipes_count == 0)
		return (84);
	return (0);
}
