/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int get_arr_size(char **arr)
{
	int i = 0;

	for (; arr[i] != NULL; i++);
	return (i);
}

int replace_arr_entry(char **arr, int pos, char *new)
{
	if (arr == NULL)
		return (84);
	if (new == NULL)
		return (84);
	if (get_arr_size(arr) <= pos)
		return (84);
	arr[pos] = new;
	return (0);
}
