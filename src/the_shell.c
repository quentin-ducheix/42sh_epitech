/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int the_shell_tty2(termline_t *command_line, shell_t *shell)
{
	if (manage_input(command_line->str, shell) != 0) {
		free_termline(command_line);
		return (84);
	} else
		free_termline(command_line);
	return (0);
}

int the_shell_tty(char **env, shell_t *shell)
{
	termline_t *command_line;
	static char *save = NULL;

	if (save == NULL)
		save = calloc(1, 1);
	if ((command_line = get_key(env, &save)) == NULL)
		return (27);
	else {
		if ((command_line->str)[0] == '\0')
			shell->exit_status = 0;
		if (tcsetattr(0, TCSADRAIN, &shell->backup) == -1)
			return (84);
		command_line->str = rm_comment(command_line->str);
		if (the_shell_tty2(command_line, shell) == 84)
			return (84);
		shell->hist_cur = NULL;
		if (tcsetattr(0, TCSADRAIN, &shell->term) == -1)
			return (84);
	}
	return (0);
}

int the_shell2(char *insert_mode, shell_t *shell)
{
	if (isatty(0) == 1)
		tputs(insert_mode, 0, write_char);
	shell->exit_status = 0;
	shell->run = 0;
	shell->hist_cur = NULL;
	return (0);
}

int in_the_shell(char **env, shell_t *shell)
{
	int vale = 0;

	if (isatty(0) != 1) {
		vale = the_shell_notty(env, shell);
		if (vale == 27)
			return (27);
		else if (vale == 84)
			return (84);
	} else {
		vale = the_shell_tty(env, shell);
		if (vale == 27)
			return (27);
		if (vale == 84)
			return (84);
	}
	return (0);
}

int the_shell(char **env, char *insert_mode, shell_t *shell)
{
	int vale = 0;

	the_shell2(insert_mode, shell);
	while (shell->run == 0) {
		vale = in_the_shell(env, shell);
		if (vale == 84)
			return (84);
		if (vale == 27)
			return (27);
	}
	return (0);
}
