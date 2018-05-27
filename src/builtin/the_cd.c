/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *cat_path(char *join)
{
	char *found = getcwd(NULL, 512);
	char *rec = NULL;
	int found_len = strlen(found);
	int join_len = strlen(join);

	if (found == NULL || join == NULL || is_dir(found) == 0)
		return (NULL);
	rec = malloc(sizeof(char) * (found_len + join_len + 2));
	strncpy(rec, found, found_len);
	rec[found_len] = '/';
	found_len++;
	strncpy(rec + found_len, join, join_len);
	rec[found_len + join_len] = '\0';
	return (rec);
}

int update_pwd(char *rec, list_t *env, char *fol)
{
	int tempo = chdir(rec);

	if (errno == ENOTDIR) {
		(fol) ? (my_putstr(fol)) : (0);
		my_putstr(": Not a directory.\n");
		return (84);
	}
	if (tempo == -1) {
		(fol) ? (my_putstr(fol)) : (0);
		my_putstr(": No such file or directory.\n");
		return (84);
	}
	maj_var_val(env, "OLDPWD", the_getenv("PWD", env));
	maj_var_val(env, "PWD", rec);
	return (0);
}

int the_cd2(char **av, list_t *env, shell_t *shell, char *tempo)
{
	int var = 0;

	if (strcmp(av[1], "-") == 0) {
		var = update_pwd(the_getenv("OLDPWD", env), env, tempo);
		return (var);
	}
	if (av[1][0] == '/') {
		var = update_pwd(av[1], env, tempo);
		(var == 84) ? (shell->exit_status = 1) : (0);
		return (var);
	}
	return (var);
}

int the_cd(char **av, list_t *env, shell_t *shell)
{
	int var = 0;
	static char *tempo = NULL;
	static int i = 0;

	if (av && av[0] && av[1] && i == 0)
		tempo = av[1];
	if (!av || !av[0] || !av[1]) {
		var = update_pwd(the_getenv("HOME", env), env, tempo);
		return (var);
	}
	if (strcmp(av[1], "-") == 0 || av[1][0] == '/')
		return (the_cd2(av, env, shell, tempo));
	if ((av[1] = cat_path(av[1])) == NULL)
		return (84);
	i++;
	var = the_cd(av, env, shell);
	i = 0;
	return (var);
}
