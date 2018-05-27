/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

void free_termline(termline_t *line)
{
	free (line->str);
	free (line);
}