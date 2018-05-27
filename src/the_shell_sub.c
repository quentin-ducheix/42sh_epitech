/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int the_shell_notty(__attribute__((unused)) char **env, shell_t *shell)
{
	char *geted = NULL;
	int vale = 0;
	char *tempo2 = NULL;
	size_t n;

	if ((vale = getline(&geted, &n, stdin)) < 0)
		return (27);
	if (vale >= 1 && geted[vale - 1] == '\n')
		geted[vale - 1] = '\0';
	if (geted[0] == '\0')
		shell->exit_status = 0;
	tempo2 = rm_comment(geted);
	if (manage_input(tempo2, shell) != 0)
		return (84);
	shell->hist_cur = NULL;
	return (0);
}