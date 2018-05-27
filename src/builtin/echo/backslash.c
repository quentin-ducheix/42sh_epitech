/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

void print_backs(const char *str, int tmp)
{
	my_putstr ("\\");
	if (str[tmp] != '\0')
		write(1, &str[tmp], 1);
}

void print_backs2(const char *str)
{
	for (int tmp = 0; str[tmp] != '\0' && str[tmp] != '$'; tmp++)
		write(1, &str[tmp], 1);
}
