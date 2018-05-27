/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int bef_redir(int tempo3, int fd, int *bk)
{
	int tempo = 0;

	bk[0] = dup(fd);
	if (bk[0] == -1)
		return (84);
	tempo = dup2(tempo3, fd);
	if (tempo == -1)
		return (84);
	else
		return (0);
	return (0);
}

int rst_redir(int tempo3, int fd, int *bk)
{
	int tempo = dup2(bk[0], fd);

	if (tempo == -1)
		return (84);
	close(tempo3);
	close(bk[0]);
	return (0);
}
