/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

char *add_char(char *str, char c, int len, int pos)
{
	char *next = calloc(1, len + 1);
	int i = 0;

	for (; i < pos; i++)
		next[i] = str[i];
	next[i++] = c;
	for (int j = i - 1; i < len; i++)
		next[i] = str[j++];
	if (str != NULL)
		free(str);
	return (next);
}

char *del_char(char *str, int len, int pos)
{
	char *next = calloc(1, len);
	int i = 0;

	for (; i < pos; i++)
		next[i] = str[i];
	for (int j = i + 1; i < len; i++)
		next[i] = str[j++];
	if (str != NULL)
		free(str);
	return (next);
}