/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int specific_chara2(const char escape)
{
	switch (escape) {
		case 'n':
			my_putstr("\n");
			break;
		case 't':
			my_putstr("\t");
			break;
		case 'v':
			my_putstr("\v");
			break;
		default:
			return (-1);
	}
	return (0);
}

int specific_chara(const char escape)
{
	switch (escape) {
		case 'a':
			my_putstr("\a");
			break;
		case 'b':
			my_putstr("\b");
			break;
		case 'c':
			return '1';
		case 'f':
			my_putstr("\f");
			break;
		default:
			return (specific_chara2(escape));
	}
	return (0);
}

int check_chara(const char *str, int *tmp, shell_t *shell)
{
	int verif = 0;

	if (str[*tmp] == '\\') {
		(str[*tmp + 1] != '\0') ? (*tmp += 1) : (0);
		if ((verif = specific_chara(str[*tmp])) == -1)
			print_backs(str, *tmp);
		else if (verif == 1) {
			shell->echo_option[0] = 1;
			return (1);
		}
	} else
		write(1, &str[*tmp], 1);
	return (0);
}

void arg_print(const char *str, shell_t *shell)
{
	for (int tmp = 0; str[tmp] != '\0' && str[tmp] != '$'; tmp++) {
		if (check_chara(str, &tmp, shell) == 1)
			return;
	}
}
