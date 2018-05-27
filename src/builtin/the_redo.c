/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *catch_last_com(const list_t *histo, const char *begin)
{
	elem_t *elem = histo->last;

	for (int len = strlen(begin); elem && strncmp((const char *)elem->data,
	begin, len); elem = elem->prev);
	if (elem != NULL)
		return (elem->data);
	return (NULL);
}

char *catch_com_index(const list_t *histo, int nb)
{
	elem_t *elem = histo->last;

	for (int i = 1; elem && i < nb; i++, elem = elem->prev);
	if (elem != NULL)
		return (elem->data);
	return (NULL);
}

char *bttf_com2(char **av, char *tempo)
{
	int i = 0;

	if (av[0][0] != '\0' && av[0][1] != '!')
		tempo = av[0] + 1;
	else {
		for (; av[0][i] != '\0' && av[0][i] == '!'; i++)
			tempo = av[0] + 1;
		if (av[0][i] == '\0') {
			tempo = NULL;
		}
	}
	return (tempo);
}

int bttf_com(char **av, shell_t *shell)
{
	const char *end = NULL;
	char *tempo = NULL;
	int tempo2 = 0;

	if (av[0][0] == '\0' && av[0][1] == '\0')
		return (0);
	if (av[0][0] == '!' && av[0][1] == '\0') {
		shell->exit_status = 1;
		my_putstr("!: Command not found.\n");
		return (0);
	}
	tempo = bttf_com2(av, tempo);
	if (is_number(av[0] + 1) == 0)
		end = catch_com_index(shell->history, atoi(av[0] + 1));
	else
		end = catch_last_com(shell->history, tempo);
	if (end == NULL)
		return (0);
	tempo2 = manage_input(strdup(end), shell);
	return (tempo2);
}
