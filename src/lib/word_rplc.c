/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int count_word_sec(const char *str, const char *word)
{
	int i = catch_str_pos(str, word);
	int len = strlen(word);
	int temp = 0;

	if (i == 84)
		return (0);
	(IS_WORD_SEP(str[i + len])
	&& (i == 0 || IS_WORD_SEP(str[i - 1]))) ? (temp = 1) : (temp = 0);
	str += i + len;
	for (; (i = catch_str_pos(str, word)) != 84; str = str + len)
		(IS_WORD_SEP(str[i + len]) && IS_WORD_SEP(str[i - 1]))
		? (temp++) : (0);
	return (temp);
}

char *easy_rplc_word(char *str, const char *orig, const char *rep, int len)
{
	for (int i = 0; str[i] != '\0';) {
		if (!strncmp(str + i, orig, len) && (i == 0
		|| IS_WORD_SEP(str[i - 1])) && IS_WORD_SEP(str[i + len])) {
			strncpy(str + i, rep, len);
			i = i + len;
		} else
			i++;
	}
	return (str);
}

char *change_rplc_word(char *str, const char *orig, const char *rep, int *lens)
{
	char *new = malloc(sizeof(char) * (lens[2] + 1));
	int tempo = 0;
	int tempo2 = 0;

	for (; str[tempo] && tempo2 < lens[2];) {
		if (!strncmp(str + tempo, orig, lens[0])
		&& (tempo == 0 || (IS_WORD_SEP(str[tempo - 1])))
		&& IS_WORD_SEP(str[tempo + lens[0]])) {
			strncpy(new + tempo2, rep, lens[1]);
			tempo = tempo + lens[0];
			tempo2 = tempo2 + lens[1];
		} else {
			new[tempo2] = str[tempo];
			tempo2++;
			tempo++;
		}
	}
	new[lens[2]] = '\0';
	return (new);
}

char *rplc_word(char *str, const char *word, const char *rep)
{
	int lens[3];
	int tempo2 = count_word_sec(str, word);
	char *tempo = NULL;

	if (tempo2 == 0)
		return (str);
	lens[0] = strlen(word);
	lens[1] = strlen(rep);
	if (lens[0] == lens[1]) {
		tempo = easy_rplc_word(str, word, rep, lens[0]);
		return (tempo);
	}
	lens[2] = strlen(str) + tempo2 * (lens[1] - lens[0]);
	tempo = change_rplc_word(str, word, rep, lens);
	return (tempo);
}
