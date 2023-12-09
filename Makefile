# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:17:23 by zhedlund          #+#    #+#              #
#    Updated: 2023/06/01 18:41:04 by zhedlund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRC = 	ft_printf.c print_char.c print_hex.c print_int.c \
		print_ptr.c print_str.c print_unsigned.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

$(NAME): $(LIBFT) $(OBJ)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJ)

all:	$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFTDIR) all

clean:
		make -C $(LIBFTDIR) clean
		$(RM) *.o

fclean:	clean
		make -C $(LIBFTDIR) fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re
