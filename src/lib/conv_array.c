/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

void fill_array(char *to_fill, const char *str, int *i, int *k)
{
	while (str[*i] != '"') {
		to_fill[*k] = str[*i];
		*i += 1;
		*k += 1;
	}
}

int print_it_arr(char **arr, const char *str, int pos, const char *seps)
{
	int j = 0;
	int i = 0;

	if ((j = lenght_word(str, seps)) == 0 && !strchr(seps, ':'))
		return (84);
	arr[pos] = malloc(sizeof(char) * (j + 1));
	for (int k = 0; k < j && str[i] && in_str(str[i], seps) == 1; i++) {
		if (str[i] == '"') {
			i++;
			fill_array(arr[pos], str, &i, &k);
		} else {
			arr[pos][k] = str[i];
			k++;
		}
	}
	arr[pos][j] = '\0';
	for (; str[i] != '\0' && in_str(str[i], seps) == 0; i++);
	return (i);
}

char **conv_array(const char *str, const char *seps)
{
	char **arr = NULL;
	int tempo = 0;
	int j = 0;
	int pas = 0;

	if (str == NULL || seps == NULL)
		return (NULL);
	if (count_chara(str, '"') % 2)
		return (NULL);
	tempo = nb_words(str, seps);
	arr = malloc((tempo + 1) * sizeof(char *));
	memset(arr, '\0', sizeof(*arr));
	for (int i = 0; i < (int)strlen(str); i += pas) {
		if ((pas = print_it_arr(arr, str + i, j++, seps)) == 84)
			return (NULL);
	}
	arr[tempo] = NULL;
	return (arr);
}
