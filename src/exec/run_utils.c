/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *catch_path(const list_t *env)
{
	char *value = NULL;
	elem_t *cur = find_var_name(env, "PATH");
	char *tempo_path = "/bin:/usr/bin";

	if (cur) {
		value = strchr(cur->data, '=');
		value++;
		if (value)
			return (value);
	}
	return (tempo_path);
}

int look_path2(char *tempo3, int tempo2, char **av)
{
	char *tempo = av[0] + 2;

	if (access(tempo, X_OK) || is_dir(tempo3))
		return (84);
	else {
		tempo2 = replace_arr_entry(av, 0, tempo3 + 2);
		return (tempo2);
	}
	return (tempo2);
}

int look_path(char **av, const shell_t *shell)
{
	char *coma = NULL;
	char **path = NULL;
	char *tempo = NULL;
	int tempo2 = 0;
	char *tempo3 = av[0];

	if (access(tempo3, X_OK) == 0 && !is_dir(tempo3))
		return (0);
	else if (strncmp("./", tempo3, 2) == 0)
		return (look_path2(tempo3, tempo2, av));
	tempo = catch_path(shell->env);
	path = conv_array(tempo, ":");
	if (path == NULL)
		return (84);
	for (int i = 0; path[i] != NULL; i++) {
		coma = catch_file(path[i], tempo3);
		if (coma != NULL && !is_dir(coma))
			return ((tempo2 = replace_arr_entry(av, 0, coma)));
	}
	return (84);
}
