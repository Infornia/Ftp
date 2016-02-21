# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/14 20:50:24 by ccholin           #+#    #+#              #
#    Updated: 2015/05/14 21:00:58 by ccholin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	server.c\
		option.c \
		op2.c \
		mk.c \
		ft_recv.c \
		ft_send.c
CRC = client.c\
		get_next_line.c\
		echange.c \
		copt.c \
		ft_recv.c \
		ft_send.c

NAME = client
NA		=	serveur
SOBJ	=	$(SRC:.c=.o)
COBJ	=	$(CRC:.c=.o)
FLAGS	=	-Werror -Wall -Wextra
LIB_NAME	=	./libft/libft.a

all: serveur client

client:
	@make -C libft/
	@gcc -c $(FLAGS) $(CRC)
	@echo "Compiling \t\
		\033[4m\033[91md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"
	@gcc -o $(NAME) $(COBJ) $(LIB_NAME)
	@echo "$(NAME) was created for you \t\
		\033[4m\033[91md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

serveur:
	@make -C libft/
	@gcc -c $(FLAGS) $(SRC)
	@echo "Compiling \t\
		\033[4m\033[91md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"
	@gcc -o $(NA) $(SOBJ) $(LIB_NAME)
	@echo "$(NA) was created for you \t\
		\033[4m\033[91md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

clean:
	@make clean -C libft
	@rm -rf $(COBJ)
	@rm -rf $(SOBJ)
	@echo "Cleaning $(NAME) \t\
		\033[4m\033[91md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)
	@rm -rf $(NA)
	@echo "Fcleaning $(NAME) \t\
		\033[4m\033[91md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

re: fclean all

.PHONY: clean fclean all
