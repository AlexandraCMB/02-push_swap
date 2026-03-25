CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinclude
RM      = rm -rf
NAME    = push_swap

SRC     = src/main.c \
            src/utilities/linked_list.c \
            src/utilities/assigning_indices.c \
            src/utilities/manual_sort.c \
            src/operations/push.c \
            src/operations/swap.c \
            src/operations/rot.c \
            src/operations/rev_rot.c \
            src/utilities/printing_op.c \
            src/utilities/input_checker.c \
            src/libft/ft_atoi.c \
            src/libft/ft_strlen.c \



OBJ     = $(SRC:src/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

objs/%.o: src/%.c include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
