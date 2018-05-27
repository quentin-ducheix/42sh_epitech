/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *skip_empty(char *str)
{
	if (!str)
		return (str);
	for (; (*str == ' ' || *str == '\t' || *str == ';') && *str != '\0';
	str++);
	return (str);
}

char *end_cut(char *str)
{
	int i = 0;

	for (; str[i] != '\0' && (str[i] != ' ' || str[i] != '\t'
	|| str[i] != ';'); i++);
	str[i] = '\0';
	return (str);
}

int is_empty(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' || str[i] != '\t' || str[i] != ';')
			return (1);
	}
	return (0);
}
