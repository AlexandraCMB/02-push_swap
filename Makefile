CC		= gcc
CFLAGS	= -g3 -fPIE -O0 -Wall -Wextra -Werror -Iinclude -Ilibft -Iprintf
RM		= rm -rf
NAME	= push_swap

# Libraries
LIBFT_DIR   = ./libft
PRINTF_DIR  = ./ft_printf
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/ft_printf.a

SRC			= src/main.c \
			src/algorithms/manual_sort.c \
			src/algorithms/main_algo.c \
			src/operations/push.c \
			src/operations/swap.c \
			src/operations/rot.c \
			src/operations/rev_rot.c \
			src/utilities/assigning_indices.c \
			src/utilities/freeing_and_exiting.c \
			src/utilities/initialising.c \
			src/utilities/check_inputs.c \
			src/utilities/linked_list.c \
			src/utilities/optimisation.c \
			src/utilities/printing_op.c \

# Path transformation: src/folder/file.c -> objs/folder/file.o
OBJ		= $(SRC:src/%.c=objs/%.o)

all: $(NAME)

# Linking executables
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

# Build libraries by calling their respective Makefiles
$(LIBFT):
	@$(MAKE) -C ./libft

$(PRINTF):
	@$(MAKE) -C ./ft_printf

# Compile object files and create subdirectories in objs/
objs/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./ft_printf
	$(RM) objs

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
