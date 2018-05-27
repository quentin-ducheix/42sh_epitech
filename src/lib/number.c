/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int is_alphanum(const char *str)
{
	for (; ('a' <= (*str) && (*str) <= 'z') || ('A' <= (*str) && (*str)
	<='Z') || ('0' <= *str && *str <= '9') || *str == '_'; str++);
	if (*str == '\0')
		return (0);
	return (1);
}

int is_number(const char *str)
{
	for (; '0' <= *str && *str <= '9'; str++);
	if (*str == '\0')
		return (0);
	return (1);
}
