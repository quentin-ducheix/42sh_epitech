/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int is_dir(const char *path)
{
	struct stat info;

	if (stat(path, &info) == -1)
		return (84);
	if (S_ISDIR(info.st_mode))
		return (1);
	return (0);
}

char *rm_comment(char *str)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != '#' && is_empty(str + i); i++);
	str[i] = '\0';
	return (str);
}

int invalid_empt(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (strncmp(str + i, "&&", 2) == 0
		|| strncmp(str + i, "||", 2) == 0)
			return (0);
		else if (str[i] != ' ' && str[i] != '\t' && str[i] != ';')
			return (1);
	}
	return (0);
}
