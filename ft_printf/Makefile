# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 15:22:34 by abrunjes          #+#    #+#              #
#    Updated: 2026/05/13 13:38:00 by abrunjes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR          = ar rcs
SRC			= ft_printf.c ft_printf_utils.c
TEST		= test.out #OPTIONAL EXECUTABLE

OBJ	= $(SRC:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

#default target.. i.e. when I type make
all: $(NAME)

#make library
$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(TEST)

$(TEST): main.c $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o $(TEST)

.PHONY: all clean fclean re
