/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *catch_file(const char *dir, const char *file)
{
	char *strnew = NULL;
	int the_len = strlen(dir);
	int len = 0;
	int tempo = 0;

	if (dir == NULL || file == NULL)
		return (NULL);
	if (dir[the_len - 1] != '/')
		tempo = 2;
	else
		tempo = 1;
	len = the_len + strlen(file) + tempo;
	strnew = malloc(sizeof(char) * len);
	strcpy(strnew, dir);
	(dir[the_len - 1] != '/') ? (strnew[the_len] = '/') : (0);
	(dir[the_len - 1] != '/') ? (tempo = 1) : (tempo = 0);
	strcpy(strnew + the_len + tempo, file);
	if (access(strnew, X_OK) != -1)
		return (strnew);
	return (NULL);
}
