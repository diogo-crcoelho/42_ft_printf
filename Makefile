# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 18:27:40 by soups             #+#    #+#              #
#    Updated: 2022/10/24 14:31:12 by dcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa_base.c
OBJS = $(SRCS:.c=.o)
INC = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -fsanitize=address -g
NORM = norminette -R

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
		
all : $(NAME)

bonus: $(B_OBJS)
	ar rcs $(NAME) $(B_OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

so: re bonus
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(B_SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(B_OBJS)
	
norm :
	$(NORM) CheckDefine $(INC)
	$(NORM) CheckForbiddenSourceHeader $(SRCS)

sanitize:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS)
	