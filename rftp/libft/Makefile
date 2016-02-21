# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 14:48:13 by ccholin           #+#    #+#              #
#    Updated: 2015/03/20 22:30:16 by ccholin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_strncpy.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_isprint.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_isascii.c \
	   ft_isalnum.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putendl.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_intlen.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRCS) 
	@ echo "Compiling \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ echo "$(NAME) was created for you \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"
	@ranlib $(NAME)
	@ echo "Indexing \t\
	\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

clean:
	@ rm -f $(OBJ)
	@ echo "Cleaning $(NAME) \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "Fcleaning $(NAME) \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

re: fclean all
