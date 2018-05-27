/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

void ctrl_w(termline_t *line, char **save)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	if (*save != NULL) {
		free (*save);
		*save = calloc(1, 1);
	}
	while (line->pos > 0) {
		line->pos -= 1;
		write(1, "\033[D", 4);
		tputs(line->del, 0, write_char);
		*save = add_char(*save, line->str[line->pos],
		strlen(*save) + 1, 0);
		line->str = del_char(line->str, line->len, line->pos);
		line->len -= 1;
	}
}

void ctrl_y(termline_t *line, char **save)
{
	line->check = 1;
	write(1, "\033[D", 4);
	tputs(line->del, 0, write_char);
	if (*save != NULL) {
		write (1, *save, strlen(*save));
		for (int i = 0; (*save)[i]; i++) {
			line->len += 1;
			line->str = add_char(line->str, (*save)[i], line->len,
			line->pos);
			line->pos += 1;
		}
	}
}