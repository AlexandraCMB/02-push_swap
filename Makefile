NAME		=libpush_swap.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -O0
AR			= ar rcs
RM			= rm -f
INCLUDE		= -I.

SRC			= push_swap.c
# SRC_B		= get_next_line_bonus.c get_next_line_utils_bonus.c

SRC_OBJS	= $(SRC:.c=.o)
# SRC_B_OBJS	= $(SRC_B:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(AR) $(NAME) $(SRC_OBJS)

bonus: fclean $(SRC_B_OBJS)
	$(AR) $(NAME) $(SRC_B_OBJS)

clean:
	$(RM) $(SRC_OBJS) $(SRC_B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

val: fclean $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lpush_swap
 -o push_swap \
	&& valgrind --leak-check=full ./push_swap

testm: fclean $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lpush_swap
 -o test_man

# testb: fclean bonus main.c
# 	$(CC) $(CFLAGS) main.c -L. -lpush_swap -o test_bon

.PHONY: all bonus clean fclean re testm testb val
