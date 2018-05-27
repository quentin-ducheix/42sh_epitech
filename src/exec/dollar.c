/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int dollar_count(const char *str)
{
	int count = 0;

	for (int tmp = 0; str[tmp] != '\0'; tmp++)
		(str[tmp] == '$') ? (count++) : (0);
	return (count);
}

char *str_to_env(char *str, int count, const list_t *env, shell_t *shell)
{
	int tmp = count;

	(void)shell;
	for (; str[tmp] != '\0' && str[tmp] != ' ' && str[tmp] != '\t'; tmp++);
	str[tmp] = '\0';
	return (the_getenv(str + count, env));
}

char *env_printin(char *str, const list_t *env, shell_t *shell)
{
	int count = dollar_count(str);
	int check = 0;
	char *tempo = NULL;
	int tmp = 0;

	if (count >= 2)
		return ("getpid()");
	for (; str[tmp] != '$'; tmp++);
	str += tmp;
	if (count % 2 != 0 && str[count] != '\0') {
		tempo = str_to_env(str, count, env, shell);
		check = 1;
	}
	if (count % 2 != 0 && check == 0) {
		if (str[count] == '\0')
			return ("$");
		return (NULL);
	}
	return (tempo);
}
