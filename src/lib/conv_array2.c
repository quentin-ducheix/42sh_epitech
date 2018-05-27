/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int in_str(char c, const char *str)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != c; i++);
	if (c == str[i])
		return (0);
	return (1);
}

void next_quote(const char *str, int *i)
{
	for (; str[*i] != '"'; *i += 1);
}

int lenght_word(const char *str, const char *seps)
{
	int j = 0;
	int i = 0;
	int tempo = 0;

	for (; str[i] != '\0' && in_str(str[i], seps) == 1; i++) {
		if (str[i] == '"') {
			i++;
			next_quote(str, &i);
			j = j + 2;
		}
	}
	tempo = i - j;
	return (tempo);
}

int nb_words(const char *str, const char *seps)
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (i == 0 || (in_str(str[i], seps) == 1
		&& in_str(str[i - 1], seps) == 0))
			len++;
		if (str[i] == '"') {
			i++;
			next_quote(str, &i);
		}
	}
	return (len);
}
