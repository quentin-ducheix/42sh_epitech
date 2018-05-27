/*
** EPITECH PROJECT, 2018
** 42sh_termcaps
** File description:
** termcaps
*/

#include "my.h"

int write_char(int c)
{
	write(1, &c, 1);
	return (0);
}

void check_git_prompt(void)
{
	int flag = -42;
	char *branch = NULL;

	flag = system("git rev-parse --is-inside-work-tree > /dev/null 2>&1");
	if (flag == 0) {
		system("git rev-parse --abbrev-ref HEAD > .tmp_git");
		branch = read_file(".tmp_git");
		printf("%sgit:(%s", CYAN, WHITE);
		for (int i = 0; branch[i] != '\n'; i++)
			printf("%s%c%s", RED, branch[i], WHITE);
		printf("%s)%s> ", CYAN, WHITE);
		fflush(stdout);
		system("rm .tmp_git");
	}
}

void prompt(char **env)
{
	char *host = NULL;
	char *pwd = getcwd(NULL, 0);

	for (int i = 0; env[i] != NULL; i++) {
		if (strncmp(env[i], "LOGNAME=", 8) == 0) {
			host = env[i];
			host += 8;
		}
	}
	if (isatty(0) == 1) {
		printf("%s%s%s:%s%s%s> %s", UNDERLINE, RED, host, WHITE,
				GREEN, pwd, WHITE);
		fflush(stdout);
		check_git_prompt();
	}
	free(pwd);
}