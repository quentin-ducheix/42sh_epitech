/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

void ctrl_f(termline_t *line)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	if (line->pos < line->len) {
		write(1, "\033[C", 4);
		line->pos += 1;
	}
}

void ctrl_h(termline_t *line)
{
	line->check = 1;
	if (line->len > 0 && line->pos > 0) {
		line->pos -= 1;
		tputs(line->del, 0, write_char);
		line->str = del_char(line->str, line->len, line->pos);
		line->len -= 1;
	} else
		write(1, "\033[C", 4);
}

void ctrl_k(termline_t *line, char **save)
{
	line->check = 1;
	write(1, "\033[A", 4);
	if (*save != NULL) {
		free (*save);
		*save = calloc(1, 1);
	}
	while (line->pos < line->len) {
		tputs(line->del, 0, write_char);
		*save = add_char(*save, line->str[line->pos],
		strlen(*save) + 1, strlen(*save));
		line->str = del_char(line->str, line->len, line->pos);
		line->len -= 1;
	}
}

void ctrl_l(termline_t *line, char **env)
{
	line->check = 1;
	tputs(line->clear, 0, write_char);
	prompt(env);
	write(1, line->str, line->len);
}

void ctrl_u(termline_t *line, char **save)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	if (*save != NULL)
		free (*save);
	if (line->str != NULL) {
		*save = strdup(line->str);
		free(line->str);
		line->str = calloc(1, 1);
	}
	while (line->pos > 0) {
		write(1, "\033[D", 4);
		line->pos -= 1;
	}
	while (line->len > 0) {
		tputs(line->del, 0, write_char);
		line->len -= 1;
	}
}
