/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#include "my.h"

list_t *env_in_list(char **arr)
{
	list_t *list = init_list();
	int tempo = 0;

	for (int i = 0; arr[i] != NULL; i++) {
		tempo = app_to_list(list, strdup(arr[i]));
		if (tempo == 84)
			return (NULL);
	}
	return (list);
}

elem_t *find_var_name(const list_t *env, const char *label)
{
	char *tempo = NULL;

	for (elem_t *elem = env->first; elem; elem = elem->next) {
		tempo = elem->data;
		if (strncmp(tempo, label, strlen(label)) == 0 &&
		tempo[strlen(label)] == '=')
			return (elem);
	}
	return (NULL);
}

int maj_var_val(list_t *env, const char *label, const char *val)
{
	elem_t *elem = NULL;
	char *varia = NULL;

	if (!label || !val)
		return (84);
	varia = malloc(sizeof(char) * (strlen(label) + strlen(val) + 2));
	strncpy(varia, label, strlen(label));
	varia[strlen(label)] = '=';
	strcpy(varia + strlen(label) + 1, val);
	elem = find_var_name(env, label);
	if (elem == NULL) {
		app_to_list(env, varia);
		return (0);
	}
	elem->data = varia;
	return (0);
}

char **env_to_array(list_t *env)
{
	int i = 0;
	char **arr = malloc(sizeof(char *) * (env->size + 1));

	for (elem_t *e = env->first; e && i < env->size; e = e->next, i++)
		arr[i] = e->data;
	arr[i] = NULL;
	return (arr);
}
