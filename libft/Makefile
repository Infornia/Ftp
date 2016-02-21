# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2016/02/17 22:05:57 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## PROJECT

NAME = libft.a

## COMPILATEUR

OS = $(shell uname -s)
CC = clang
FLAGS = -Wall -Wextra -Werror

## FILES

SRC = ft_atoi.c ft_abs.c \
	  ft_bzero.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c \
	  ft_isgraph.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd.c ft_lstaddq.c ft_lstdel.c ft_lstdelone.c \
	  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strgroupchar.c ft_strchartrim.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnjoin.c ft_strnstr.c ft_strsub.c\
	  ft_strrchr.c ft_strsplit.c ft_strstr.c \
	  ft_strtrim.c ft_realloc.c \
	  ft_tolower.c ft_toupper.c \
	  get_next_line.c \
	  tt_pchar.c tt_perr.c tt_pnbr.c tt_pnbl.c \
	  tt_pel.c tt_ps.c tt_pstr.c tt_puts.c \
	  tt_tree_new.c tt_tree_del.c tt_tree_h.c tt_tree_add.c \
	  tt_tree_iter_ord.c tt_tree_iter_rev.c \
	  tt_intlen.c \

INC =  -I ./
INC += -I ./includes/
INC += -I minilibx/

OBJ = $(SRC:.c=.o)

LIB =  -L libft -lft
LIB += -L minilibx/ -lmlx -framework OpenGl -framework Appkit

## RULES

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m (>0.0)>\t./|Invocation|\.\t<(O.O<) \033[0m"
	@$(CC) $(FLAGS) -c $(SRC) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33m <(O.O<)\tWOW ! Very Library ! Amaze !\t(>^o^)> \033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[36m\tT.T Miss you lib-object files T.T\t\033[0m"

fclean:
	@rm -rf $(OBJ)
	@echo "\033[36m\tT.T Miss you lib-object files T.T\t\033[0m"
	@rm -rf $(NAME)
	@echo "\033[36m\tX.x Bye Bye lib-compiled files >_<\t\033[0m"

%.o:%.c
	@echo "\033[0;34;44m<(O.o)>\t\t$@\t\t<(o.O)>\033[0m"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

re: fclean all

.PHONY: all normal clean fclean re

