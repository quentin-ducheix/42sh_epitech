/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

void keys_control(char *buffer, termline_t *line)
{
	line->check = 1;
	switch (buffer[2]) {
		case 65:
			write(1, "\033[B", 4);
			break;
		case 66:
			write(1, "\033[A", 4);
			break;
		case 67:
			(line->pos < line->len) ? (line->pos += 1) :
			(write(1, "\033[D", 4));
			break;
		case 68:
			(line->pos > 0) ? line->pos -= 1 :
			write(1, "\033[C", 4);
	}
}

void key_suppr(termline_t *line)
{
	line->check = 1;
	if (line->pos < line->len) {
		tputs(line->del, 0, write_char);
		line->str = del_char(line->str, line->len, line->pos);
		line->len -= 1;
	}
	for (int i = 0; i < 4; i++) {
		write(1, "\033[D", 4);
		tputs(line->del, 0, write_char);
	}
}

void key_delete(termline_t *line)
{
	line->check = 1;
	if (line->len > 0 && line->pos > 0) {
		line->pos -= 1;
		write(1, "\033[D", 4);
		tputs(line->del, 0, write_char);
		line->str = del_char(line->str, line->len, line->pos);
		line->len -= 1;
	}
}
