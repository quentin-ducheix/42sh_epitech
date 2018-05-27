/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** 42sh
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <glob.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include <term.h>
#include <curses.h>

#define IS_SEP(x) (x == ' ' || x == '\t' || x == '\v' || x == ';')
#define IS_WORD_SEP(x) (x == ' ' || x == '\t' || x == '/' || x == '\0')
#define IS_MIN(x) ('a' <= (x) && (x) <= 'z')
#define IS_MAJ(x) ('A' <= (x) && (x) <= 'Z')

//; -> 0
//&& -> 1
//|| -> 2
//| -> 3
//<< -> 4
//< -> 5
//>> -> 6
//> -> 7
//nothing -> 8
//echo_option 0->n  1->e

#define RED "\033[01;31m"
#define YELLOW "\033[01;32m"
#define GREEN "\033[01;33m"
#define WHITE "\033[0m"
#define CYAN "\033[01;34m"
#define UNDERLINE "\033[4m"

typedef struct termline_s {
	char *str;
	char *del;
	char *clear;
	int pos;
	int len;
	int check;
} termline_t;

typedef struct	elem_s {
	void *data;
	struct elem_s *prev;
	struct elem_s *next;
} elem_t;

typedef struct	list_s {
	elem_t *first;
	elem_t *last;
	int size;
} list_t;

typedef struct tree_s {
	char *exp;
	int op;
	struct tree_s *left;
	struct tree_s *right;
} tree_t;

typedef struct signal_msg_s {
	int signal;
	const char *message;
} signal_msg_t;

typedef struct shell_s {
	int echo_option[2];
	int interactive;
	list_t *env;
	list_t *aliases;
	list_t *history;
	list_t *pids;
	int pipes_count;
	elem_t *hist_cur;
	char *where_tempo;
	int pipefd[2];
	int bk[2];
	FILE *fd;
	int count;
	int exit_status;
	int run;
	struct termios term;
	struct termios backup;
} shell_t;

typedef struct builtin_s {
	const char *name;
	int (*func)(char **, list_t *, shell_t *);
} builtin_t;

//BUILTINS
int the_alias(char **, list_t *, shell_t *sh);
int the_unalias(char **, list_t *, shell_t *sh);
char *change_alias(char *, const list_t *);
int is_builtin(char **, shell_t *);
char *cat_path(char *);
int update_pwd(char *, list_t *, char *);
int the_cd(char **, list_t *, shell_t *sh);
char *the_getenv(const char *, const list_t *);
int the_printenv(char **, list_t *, shell_t *sh);
int the_unsetenv(char **, list_t *, shell_t *sh);
int the_setenv(char **, list_t *, shell_t *sh);
int the_exit(char **, shell_t *);
int print_history(list_t *, shell_t *);
int the_history(char **, list_t *, shell_t *sh);
char *catch_last_com(const list_t *, const char *);
char *catch_com_index(const list_t *, int);
int bttf_com(char **, shell_t *);
list_t *env_in_list(char **);
elem_t *find_var_name(const list_t *, const char *);
int maj_var_val(list_t *, const char *, const char *);
char **env_to_array(list_t *);
int the_which(char **av, list_t *env, shell_t *shell);
int the_where(char **av, list_t *env, shell_t *shell);

//EXECUTION
int do_rredir(tree_t *, tree_t *, shell_t *);
int do_drredir(tree_t *, tree_t *, shell_t *);
int do_lredir(tree_t *, tree_t *, shell_t *);
int do_dlredir(tree_t *, tree_t *, shell_t *);
int do_delim(tree_t *, tree_t *, shell_t *);
int do_and(tree_t *, tree_t *, shell_t *);
int do_or(tree_t *, tree_t *, shell_t *);
void kill_pid(list_t *);
int do_pipe(tree_t *, tree_t *, shell_t *);
int exe_tree(tree_t *, shell_t *);
int bef_redir(int , int , int *);
int rst_redir(int , int , int *);
int take_error(int , shell_t *);
void child_exe(char **, shell_t *, int);
int pid_stock(int , shell_t *);
int easy_exe(char **, shell_t *, int);
int easy_com(const char *, shell_t *);
int look_path(char **argv, const shell_t *sh);

//GLOBING
int glob_str(glob_t *, char *);
char *replace_pattern(char *, char *);
int word_lenght(const char *, const char *);
char *glob_change(char *);

//LIBRARY
void my_putchar(char );
void my_putstr(char *);
int count_chara(const char *, char );
list_t *init_list(void);
int show_list(const list_t *);
elem_t *crt_ele(void *);
int app_to_list(list_t *, void *);
void *pop_list(list_t *);
int rm_ele(list_t *, elem_t *);
elem_t *get_ele_idx(list_t *, int);
char *catch_file(const char *, const char *);
int catch_str_pos(const char *, const char *);
int getter_l_pos(const char *, const char *);
char *skip_empty(char *);
char *end_cut(char *);
int is_empty(const char *);
int is_alphanum(const char *);
int is_number(const char *);
int get_tab_size(char **);
int replace_tab_entry(char **, int , char *);
int count_word_sec(const char *, const char *);
char *easy_rplc_word(char *str, const char *, const char *, int );
char *change_rplc_word(char *, const char *, const char *, int *);
char *rplc_word(char *, const char *, const char *);
char **conv_array(const char *str, const char *seps);
int in_str(char c, const char *str);
int lenght_word(const char *str, const char *seps);
int nb_words(const char *str, const char *seps);
int replace_arr_entry(char **arr, int pos, char *new);

//PARSER
tree_t *exp_parser(char *input);
int is_rredir2(tree_t *base, int posi);
int is_dlredir2(tree_t *base, int posi);
int is_rredir(tree_t *root);
int is_drredir(tree_t *root);
int is_lredir(tree_t *root);
int is_dlredir(tree_t *root);
int is_pipe(tree_t *root);
int is_and(tree_t *root);
int is_or(tree_t *root);
int is_delim(tree_t *root);
tree_t *the_init_small_tree(char *exp, int op);
int subtree_maker(tree_t *root, int pos, int op);
int is_start(const char *str, int pos);
int stlen_word(const char *str, int n);
int move_words(char *str, const char *op);

//MAIN AND OTHERS
int manage_input(char *input, shell_t *sh);
int the_shell(char **env, char *insert_mode, shell_t *sh);
int the_shell_notty(char **env, shell_t *sh);
list_t *backup_env(void);
int catch_info_fd(shell_t *sh);
shell_t *init_shell(char **env);
int is_dir(const char *path);
char *rm_comment(char *str);
int invalid_empt(const char *str);

//ECHO
int dollar_count(const char *str);
int print_pid(const char *str);
void print_undefined(const char *str, int count_dollars);
char *str_to_env(char *str, int count, const list_t *env, shell_t *shell);
char *env_printin(char *str, const list_t *env, shell_t *shell);
int my_echo(char **av, list_t *env, shell_t *shell);
void arg_print(const char *str, shell_t *shell);
void print_backs(const char *str, int idx);
void print_backs2(const char *str);
int contains_dollar(const char *str);

//TERMCAPS
char *read_file(char *);
int write_char(int);
void check_git_prompt(void);
void prompt(char **);
void free_termline(termline_t *);
char *add_char(char *, char c, int, int);
char *del_char(char *, int, int);
void ctrl_a(termline_t *);
void ctrl_b(termline_t *);
void ctrl_c(termline_t *, char **);
char *ctrl_d(termline_t *, char **);
void ctrl_e(termline_t *);
void ctrl_f(termline_t *);
void ctrl_h(termline_t *);
void ctrl_k(termline_t *, char **);
void ctrl_l(termline_t *, char **);
void ctrl_u(termline_t *, char **);
void ctrl_w(termline_t *, char **);
void ctrl_y(termline_t *, char **);
void keys_control(char *, termline_t *);
void key_suppr(termline_t *);
void key_delete(termline_t *);
termline_t *init_line(void);
void check_one_sub(char **);
char *check_one(char[3], char **, termline_t *, char **);
void check_three(char[3], char **, termline_t *, char **);
termline_t *check_two(char[3], char **, termline_t *, char **);
void check_four(char[3], termline_t *);
termline_t *get_key(char **, char **);
int check_terminal(struct termios *, struct termios *);

#endif
