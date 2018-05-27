/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

list_t *backup_env(void)
{
	list_t *env = init_list();

	if (app_to_list(env, strdup("PWD=.")) == 84
	|| app_to_list(env, strdup("OLDPWD=/")) == 84)
		return (NULL);
	return (env);
}

int catch_info_fd(shell_t *sh)
{
	sh->fd = NULL;
	if (isatty(0) == 1)
		sh->interactive = 0;
	else
		sh->interactive = 1;
	return (EXIT_SUCCESS);
}

shell_t *init_shell(char **env)
{
	shell_t *sh = malloc(sizeof(shell_t));
	int tempo = 0;

	memset(sh, '\0', sizeof(shell_t));
	tempo = catch_info_fd(sh);
	if (tempo == 84)
		return (NULL);
	if (env && *env)
		sh->env = env_in_list(env);
	else
		sh->env = backup_env();
	if (sh->env == NULL || !(sh->aliases = init_list()))
		return (NULL);
	if (!(sh->history = init_list()) || !(sh->pids = init_list()))
		return (NULL);
	sh->hist_cur = NULL;
	sh->bk[0] = dup(0);
	sh->count = 0;
	return (sh);
}
