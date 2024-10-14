# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: selcyilm <marvin@42.fr>                       +#+                     #
#                                                     +#+                      #
#    Created: 2024/10/10 18:22:09 by selcyilm       #+#    #+#                 #
#    Updated: 2024/10/10 18:22:11 by selcyilm       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\
			ft_strlen.c\
			print_digit.c\
			print_hex.c\
			print_ptr.c\
			print_str.c\
			print_unsigned.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra

HEADERS = ft_printf.h

CC		= gcc
RM		= rm -f

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
