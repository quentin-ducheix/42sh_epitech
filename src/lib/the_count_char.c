/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

int count_chara(const char *str, char c)
{
	int ct = 0;

	for (; *str; str++)
		(*str == c) ? (ct++) : (0);
	return (ct);
}
