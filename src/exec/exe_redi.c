/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int do_rredir(tree_t *left, tree_t *right, shell_t *shell)
{
	char *tempo2 = skip_empty(right->exp);
	int tempo = 0;
	int tempo3 = 0;
	int bk[2];
	int tempo4 = 0;

	right->exp = end_cut(tempo2);
	tempo3 = open(right->exp, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
	| S_IWUSR);
	tempo = bef_redir(tempo3, STDOUT_FILENO, bk);
	if (tempo == 84) {
		my_putstr("Failed to redirect command output.\n");
		shell->exit_status = 1;
		return (84);
	}
	tempo4 = exe_tree(left, shell);
	rst_redir(tempo3, STDOUT_FILENO, bk);
	return (tempo4);
}

int do_drredir(tree_t *left, tree_t *right, shell_t *shell)
{
	char *tempo = skip_empty(right->exp);
	int tempo3 = 0;
	int tempo4 = 0;
	int bk[2];

	right->exp = end_cut(tempo);
	tempo3 = open(right->exp, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR |
	S_IWUSR);
	bef_redir(tempo3, STDOUT_FILENO, bk);
	tempo4 = exe_tree(left, shell);
	rst_redir(tempo3, STDOUT_FILENO, bk);
	return (tempo4);
}

int do_lredir(tree_t *left, tree_t *right, shell_t *shell)
{
	char *tempo = skip_empty(right->exp);
	int tempo3 = 0;
	int tempo4 = 0;
	int bk[2];

	right->exp = end_cut(tempo);
	if (right->exp[strlen(right->exp) - 1] == ' ')
		right->exp[strlen(right->exp) - 1] = '\0';
	tempo3 = open(right->exp, O_RDONLY);
	if (bef_redir(tempo3, STDIN_FILENO, bk) == 84) {
		my_putstr("Failed to take ");
		my_putstr(tempo);
		my_putstr(" as input.\n");
		return (84);
	}
	tempo4 = exe_tree(left, shell);
	rst_redir(tempo3, STDIN_FILENO, bk);
	return (tempo4);
}

int do_dlredir(tree_t *left, tree_t *right, shell_t *shell)
{
	char *tempo = skip_empty(right->exp);
	int tempo4 = 0;
	int tfd = 0;
	int bk[2];
	size_t n;
	char *buf = NULL;

	right->exp = end_cut(tempo);
	for (int val = 0; printf("%s", "?")
	&& (val = getline(&buf, &n, stdin)) > 0;) {
		if (val > 1 && buf[val - 1] == '\n')
			buf[val - 1] = '\0';
		if (strcmp(buf, right->exp) == 0)
			break;
	}
	bef_redir(tfd, STDIN_FILENO, bk);
	tempo4 = exe_tree(left, shell);
	rst_redir(tfd, STDIN_FILENO, bk);
	return (tempo4);
}
