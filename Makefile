##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## 42sh
##

CC	=	gcc

RM	=	rm -f

SRCS	=	src/lib/list_op.c			\
		src/lib/list_util.c 			\
		src/lib/arr_util.c			\
		src/lib/conv_array.c			\
		src/lib/conv_array2.c			\
		src/lib/catch_file.c			\
		src/lib/get_pos.c			\
		src/lib/empty.c				\
		src/lib/number.c			\
		src/lib/word_rplc.c			\
		src/lib/the_count_char.c		\
		src/lib/the_base.c			\
		src/for_setup.c				\
		src/parse/the_tree.c			\
		src/parse/the_util.c			\
		src/parse/the_rules.c			\
		src/parse/the_rules_bis.c		\
		src/parse/the_rules_sub.c		\
		src/builtin/the_cd.c			\
		src/builtin/the_alias.c			\
		src/builtin/the_var_utils.c		\
		src/builtin/the_env.c			\
		src/builtin/the_history.c		\
		src/builtin/the_redo.c			\
		src/builtin/the_exit.c			\
		src/builtin/builtin.c			\
		src/builtin/where_which.c		\
		src/exec/the_fd_config.c		\
		src/exec/the_exe.c			\
		src/exec/exe_redi.c			\
		src/exec/exe.c				\
		src/exec/run_simp.c			\
		src/exec/run_simp_sub.c			\
		src/exec/run_utils.c			\
		src/parse/the_globbing.c		\
		src/utils_for.c 			\
		src/main.c				\
		src/manage_input.c			\
		src/the_shell.c				\
		src/the_shell_sub.c			\
		src/exec/dollar.c			\
		src/builtin/echo/backslash.c		\
		src/builtin/echo/the_echo.c		\
		src/builtin/echo/echo_show.c		\
		src/termcaps/read_file.c		\
		src/termcaps/termcaps.c			\
		src/termcaps/prompt.c			\
		src/termcaps/free_termline.c		\
		src/termcaps/char_manip.c		\
		src/termcaps/ctrl_handeling_one.c	\
		src/termcaps/ctrl_handeling_two.c	\
		src/termcaps/ctrl_handeling_three.c	\
		src/termcaps/key_handeling.c		\
		src/termcaps/init_line.c		\
		src/termcaps/checks.c			\

OBJS	=	$(SRCS:.c=.o)

NAME	=	42sh

CFLAGS	+=	-W -Wall -Wextra -Werror -I ./include -lncurses

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
