/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int catch_str_pos(const char *str, const char *to_find)
{
	if (strlen(to_find) > strlen(str))
		return (84);
	for (int i = 0; str[i + strlen(to_find) - 1] != '\0'; i++) {
		if (strncmp(str + i, to_find, strlen(to_find)) == 0)
			return (i);
	}
	return (84);
}

int quote_checker(const char *str, int *i)
{
	if (str[*i] == '"') {
		*i -= 1;
		for (; str[*i] != '"' && *i; *i -= 1);
		if (*i == 0)
			return (84);
	}
	return (0);
}
int getter_l_pos(const char *str, const char *to_find)
{

	if (strlen(to_find) > strlen(str))
		return (84);
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (quote_checker(str, &i) == 84)
			return (84);
		if (strncmp(str + i, to_find, strlen(to_find)) == 0)
			return (i);
	}
	return (84);
}
