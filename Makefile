# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/29 18:08:50 by mwilk             #+#    #+#              #
#    Updated: 2015/10/24 13:06:26 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= serveur
NAME2		= client

OBJ_PATH	= ./obj/
SRC_PATH	= ./

OBJ			= $(FILES:.c=.o)
OBJ2		= $(FILES2:.c=.o)

FILES		= server.c ftp_ls_pwd.c ftp_utils.c ftp_get.c
FILES2		= client.c

OBJS		= $(addprefix $(OJB_PATH),$(OBJ))
OBJS2		= $(addprefix $(OJB_PATH),$(OBJ2))

SRCS		= $(addprefix $(SRC_PATH),$(FILES))
SRCS2		= $(addprefix $(SRC_PATH),$(FILES2))

LIB_H		= -I Libft/includes/
LIB_L		= -LLibft -lft

CFLAGS		= -Wall -Wextra -Werror

all: serveur client

serveur: $(NAME)

client: $(NAME2)

$(NAME):
	@gcc $(CFLAGS) $(LIB_H) -c $(SRCS) 
	@mkdir $(OBJ_PATH)
	@gcc -o $(NAME) $(OBJ) $(LIB_L)
	@mv $(OBJ) $(OBJ_PATH)
	@echo "\033[35m <(O.O<) WOW ! Very Fdf ! Amaze ! (>^o^)> \033[0m"

$(NAME2):
	@gcc $(CFLAGS) $(LIB_H) -c $(SRCS2) 
	@mkdir -p $(OBJ_PATH)
	@gcc -o $(NAME2) $(OBJ2) $(LIB_L)
	@mv $(OBJ2) $(OBJ_PATH)
	@echo "\033[35m <(O.O<) WOW ! Very Fdf ! Amaze ! (>^o^)> \033[0m"


clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(NAME2)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

re: fclean all

.PHONY: all clean fclean re
