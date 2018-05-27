/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int is_start(const char *str, int posi)
{
	int i = 0;

	for (; str[i] == ' ' && str[i] == '\t' && i < posi; i++);
	posi--;
	if (i >= posi)
		return (0);
	else
		return (1);
	return (1);
}

int stlen_word(const char *str, int j)
{
	int i = 0;

	for (; str[i] && j >= 0; i++) {
		(i == 0 || (str[i] != ' ' && str[i] != '\t'
		&& (str[i - 1] == ' ' || str[i - 1] == '\t'))) ? (j--) : (0);
	}
	i--;
	return (i);
}

int move_words(char *str, const char *ope)
{
	char *tempo2 = strdup(str);
	int ope_lenght = strlen(ope);;
	int c_word = 0;
	int lenght = 0;
	int tot = 0;

	if (nb_words(str, " \t") <= 1) {
		my_putstr("Invalid null command.\n");
		return (1);
	}
	if (tempo2 == NULL)
		return (1);
	c_word = (str[ope_lenght] == ' ' || str[ope_lenght] == '\t') ? 2 : 1;
	lenght = stlen_word(str, c_word);
	tot = strlen(tempo2);
	strncpy(str, tempo2 + lenght, tot - lenght);
	strncpy(str + tot - lenght, tempo2, lenght);
	free(tempo2);
	return (0);
}
