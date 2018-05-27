/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

termline_t *get_key(char **env, char **save)
{
	char buffer[3];
	termline_t *line = init_line();

	prompt(env);
	while (1) {
		write(1, "\033[3g", 5);
		read(0, buffer, 3);
		line->check = 0;
		if (check_one(buffer, save, line, env) == NULL)
			return (NULL);
		if (line->check == 1)
			continue;
		if (check_two(buffer, save, line, env) != NULL)
			return (line);
		if (line->check == 1)
			continue;
		check_four(buffer, line);
	}
}

int check_terminal(struct termios *term, struct termios *backup)
{
	char *name_term = "xterm-256color";

	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	if (tcgetattr(0, backup) == -1)
		return (-1);
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= (ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	return (0);
}
