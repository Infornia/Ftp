# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2016/03/30 04:41:34 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## PROJECT

NAME = serveur
NAME2 = client

LIBFT = libft

## COMPILATEUR

OS = $(shell uname -s)
CC = clang
FLAGS = -Wall -Wextra -Werror

## FILES

SRC	=	server.c\
		pwd_cd_ls.c \
		get_put.c \
		mk.c \
		ft_recv.c \
		ft_send.c
SRC2 = client.c\
		echange.c \
		copt.c \
		ft_recv.c \
		ft_send.c

INC =  -I ./
INC += -I ./libft/includes/

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

LIB =  -L libft -lft

## RULES

all: ml $(NAME) $(NAME2)

update:
	git pull
	git submodule update --init --recursive
	git submodule foreach git pull origin master

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(SRC)
	@echo "\033[35m <(O.O<) WOW ! Very $(NAME) ! Amaze ! (>^o^)> \033[0m"

$(NAME2): $(OBJ2)
	@$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME2) $(SRC2)
	@echo "\033[35m <(O.O<) WOW ! Very $(NAME2) ! Amaze ! (>^o^)> \033[0m"

clean:
	rm -rf $(OBJ) $(OBJ2)
	@echo "\033[36mT.T Miss you $(NAME)-object files T.T \033[0m"

fclean:
	rm -rf $(OBJ) $(OBJ2)
	@echo "\033[36mT.T Miss you $(NAME)-object files T.T \033[0m"
	rm -rf $(NAME) $(NAME2)
	@echo "\033[36m X.x Bye Bye $(NAME)-compiled files >_< \033[0m"

%.o:%.c
	@echo "<(O.o)>\t\t$@\t\t<(o.O)>"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

ml:
		make -C libft

mcl:
		make -C libft clean

mfl:
		make -C libft fclean

re: fclean all

.PHONY: all normal clean fclean re makelib ml mcl mfl

