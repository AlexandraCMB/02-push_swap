NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -O0
AR			= ar rcs
RM			= rm -f
INCLUDE		= -I.

SRC			= main.c \
			  operations/operations_double.c \
			  operations/operations_push.c \
			  operations/operations_rot.c \
			  operations/operations_swap.c \
			  utilities/assigning_indices.c \
			  utilities/linked_list.c

OBJ	= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
