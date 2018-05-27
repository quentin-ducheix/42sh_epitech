/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

termline_t *init_line(void)
{
	termline_t *line = malloc (sizeof(termline_t) * 1);

	line->str = calloc(1, 1);
	if ((line->clear = tgetstr("cl", NULL)) == NULL)
		return (NULL);
	if ((line->del = tgetstr("dc", NULL)) == NULL)
		return (NULL);
	line->len = 0;
	line->pos = 0;
	return (line);
}