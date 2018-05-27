/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	int i = 0;
	if (str == NULL)
		return;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
