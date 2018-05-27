/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

void check_one_sub(char **save)
{
	if (*save != NULL)
		free(*save);
}

char *check_one(char buffer[3], char **save, termline_t *line, char **env)
{
	switch (buffer[0]) {
		case 1:
			ctrl_a(line);
			break;
		case 2:
			ctrl_b(line);
			break;
		case 3:
			ctrl_c(line, env);
			break;
		case 4:
			if (ctrl_d(line, env) == NULL) {
				check_one_sub(save);
				return (NULL);
			}
	}
	return ("ok");
}

void check_three(char buffer[3], char **save, termline_t * line, char **env)
{
	switch (buffer[0]) {
		case 12:
			ctrl_l(line, env);
			break;
		case 21:
			ctrl_u(line, save);
			break;
		case 23:
			ctrl_w(line, save);
			break;
		case 25:
			ctrl_y(line, save);
			break;
		case 27:
			keys_control(buffer, line);
			break;
		case 126:
			if (buffer[2] == 51)
				key_suppr(line);
	}
}

termline_t *check_two(char buffer[3], char **save, termline_t *line, char **env)
{
	switch (buffer[0]) {
		case 5:
			ctrl_e(line);
			break;
		case 6:
			ctrl_f(line);
			break;
		case 8:
			ctrl_h(line);
			break;
		case 10:
			return (line);
		case 11:
			ctrl_k(line, save);
			break;
		default:
			check_three(buffer, save, line, env);
	}
	return (NULL);
}

void check_four(char buffer[3], termline_t *line)
{
	if (buffer[0] >= 32 && buffer[0] <= 126) {
		line->len += 1;
		line->str = add_char(line->str, buffer[0], line->len,
		line->pos);
		line->pos += 1;
	} else if (buffer[0] == 127)
		key_delete(line);
	else {
		if (buffer[0] != 15 && buffer[0] != 7 && buffer[0] != 14) {
			write(1, "\033[D", 4);
			tputs(line->del, 0, write_char);
		}
	}
}