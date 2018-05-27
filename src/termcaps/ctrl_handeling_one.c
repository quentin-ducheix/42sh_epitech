/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

void ctrl_a(termline_t *line)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	while (line->pos > 0) {
		write(1, "\033[D", 4);
		line->pos -= 1;
	}
}

void ctrl_b(termline_t *line)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	if (line->pos > 0) {
		write(1, "\033[D", 4);
		line->pos -= 1;
	}
}

void ctrl_c(termline_t *line, char **env)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	write(1, "\n", 1);
	prompt(env);
	free (line->str);
	line->str = calloc(1, 1);
	line->pos = 0;
	line->len = 0;
}

char *ctrl_d(termline_t *line, char **env)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	if (line->len == 0) {
		free_termline(line);
		write(1, "exit\n", 5);
		system("reset xterm");
		return (NULL);
	} else if (line->pos < line->len) {
		tputs(line->del, 0, write_char);
		line->str = del_char(line->str, line->len, line->pos);
		line->len -= 1;
	} else {
		write(1, "\n", 1);
		prompt(env);
		write(1, line->str, line->len);
	}
	return ("ok");
}

void ctrl_e(termline_t *line)
{
	line->check = 1;
	while (line->pos != line->len) {
		write(1, "\033[C", 4);
		line->pos += 1;
	}
}