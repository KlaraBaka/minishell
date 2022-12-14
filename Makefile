# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radriann <radriann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:56:07 by radriann          #+#    #+#              #
#    Updated: 2022/09/18 12:59:53 by radriann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MS		=	minishell
HEADER_MS	=	minishell.h

LIB_DIR	=	libft/
LIBFT	=	libft/libft.a

FILES_MS	=	main.c \
				built_command.c \
				builtin_echo.c \
				builtin_unset.c \
				builtin_export.c \
				builtin_exit.c \
				builtin_pwd.c \
				builtin_cd.c \
				builtin_env.c \
				check_syntax.c \
				count_words.c \
				execute.c \
				heredoc.c \
				init_struct.c \
				list_utils.c \
				make_struct.c \
				make_struct_utils.c \
				pipex.c \
				redirect.c \
				replace_dollar.c \
				signal_handler.c \
				split_by_words.c \
				utils_ex.c \
				utils_free.c \
				utils_builtin.c \
				utils_parse.c \
				utils_pipex.c \


OBJ_MS		=	$(FILES_MS:%.c=%.o)
FLAGS_MS	=	-Wall -Wextra -Werror


.PHONY	: all clean fclean re libft

all		: libft $(NAME_MS)

libft	:
	@make -C $(LIB_DIR)

#компиляция объектных файлов
%.o	:	%.c  $(HEADER_MS) Makefile
	cc $(FLAGS_MS) -I$/include -c $< -o $@ -I $(HEADER_MS)

#сборка исполняемого файла с подключением библиотеки 
$(NAME_MS):	$(OBJ_MS)
	cc $(FLAGS_MS) $(LIBFT) -L/lib -lreadline $(OBJ_MS) -o $@

clean	:
	rm -rf $(OBJ_MS)
	make -C $(LIB_DIR) clean

fclean	:	clean
	rm -rf $(NAME_MS)
	MAKE -C $(LIB_DIR) fclean

re		: fclean all