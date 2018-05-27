/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av,
		char **env)
{
	shell_t *sh = init_shell(env);
	char *insert_mode = NULL;
	int tempo = 0;

	if (sh == NULL)
		return (84);
	if (isatty(0) != 1) {
		the_shell(env, insert_mode, sh);
		return (sh->exit_status);
	}
	if (check_terminal(&sh->term, &sh->backup) == -1)
		return (84);
	if (tcsetattr(0, TCSADRAIN, &sh->term) == -1)
		return (84);
	if ((insert_mode = tgetstr("im", NULL)) == NULL)
		return (84);
	the_shell(env, insert_mode, sh);
	tempo = sh->exit_status;
	return (tempo);
}
