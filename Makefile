# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 22:33:41 by vmusaely          #+#    #+#              #
#    Updated: 2021/01/30 06:03:45 by vmusaely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCS = $(shell find "./src" -name '*.c') ft_printf.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar csr

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
		$(MAKE) -C ./libft
		cp $(LIBFT) ${NAME}
		${AR} ${NAME} ${OBJS}

all : ${NAME}

clean : 
		$(MAKE) clean -C ./libft
		${RM} ${OBJS}

fclean : clean
		$(MAKE) fclean -C ./libft
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean bonus re .c.o
