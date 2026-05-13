# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 17:01:36 by abrunjes          #+#    #+#              #
#    Updated: 2026/05/13 13:15:48 by abrunjes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

#compiler and flags 
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -f
INCLUDE		=	-I.
 
SRC			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c
BONUS		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 
SRC_OBJS	=	$(SRC:.c=.o)
BONUS_OBJS	=	$(BONUS:.c=.o)

#compile object files > $< INGREDIENT $@ PRODUCT
%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

#main build rule
all: $(NAME)

#create library  
$(NAME): $(SRC_OBJS)
	$(AR) $(NAME) $(SRC_OBJS)

bonus: $(SRC_OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(SRC_OBJS) $(BONUS_OBJS)

#clear object files
clean: 
	$(RM) $(SRC_OBJS) $(BONUS_OBJS)

#clean objects AND library 
fclean: clean 
	$(RM) $(NAME)

#rebuild!
re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(SRC_OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re so
