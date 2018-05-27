/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int glob_str(glob_t *the_glob, char *str)
{
	int posi = 0;
	int lenght = 0;

	for (size_t i = 0; i < the_glob->gl_pathc; i++, posi++) {
		lenght = strlen(the_glob->gl_pathv[i]);
		strncpy(str + posi, the_glob->gl_pathv[i], lenght);
		posi = posi + lenght;
		str[posi] = ' ';
	}
	posi--;
	str[posi] = '\0';
	globfree(the_glob);
	return (0);
}

char *change_patt(char *str, char *pattern)
{
	int lenght = 0;
	glob_t the_glob;
	char *tempo2 = NULL;
	int tempo = 0;

	if (strchr(pattern, '"'))
		return (str);
	if (glob(pattern, GLOB_MARK | GLOB_TILDE | GLOB_BRACE, NULL,
	&the_glob) != 0) {
		my_putstr("error\n");
		return (str);
	}
	for (size_t i = 0; i < the_glob.gl_pathc; i++)
		lenght = lenght + (strlen(the_glob.gl_pathv[i]));
	tempo = (lenght + the_glob.gl_pathc);
	tempo2 = malloc(sizeof(char) * (tempo));
	glob_str(&the_glob, tempo2);
	str = rplc_word(str, pattern, tempo2);
	return (str);
}

int word_lenght(const char *str, const char *sepa)
{
	int lenght = 0;

	for (; *str && in_str(*str, sepa) == 1; lenght++, str++);
	return (lenght);
}

char *glob_change(char *str)
{
	char *tempo = NULL;
	char *tempo2 = strdup(str);
	int size = strlen(tempo2);
	int posi = 0;
	char the_bk;

	for (int lenght = 0; tempo2 != NULL && posi < size;) {
		lenght = word_lenght(tempo2 + posi, " \t");
		the_bk = tempo2[posi + lenght];
		tempo2[posi + lenght] = '\0';
		if (((strchr(tempo2 + posi, '~') || strchr(tempo2 + posi, '*'))
		|| (strchr(tempo2 + posi, '[') && strchr(tempo2 + posi, ']')))
		&& !(str = change_patt(str, tempo2 + posi)))
			return (NULL);
		posi = posi + lenght;
		tempo2[posi] = the_bk;
		for (; tempo2[posi] == ' ' || tempo2[posi] == '\t'; posi++);
	}
	(tempo2 == NULL) ? (tempo = NULL) : (tempo = str);
	return (tempo);
}
