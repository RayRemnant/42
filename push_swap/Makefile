# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Your project files
SRC_OPERATIONS = src/operations/operations_handler.c src/operations/push.c src/operations/swap.c src/operations/rotate.c src/operations/reverse_rotate.c 
SRC_STACK = src/stack/stack_utils.c src/stack/stack_check.c src/stack/neo_libft.c
SRC_SORT = src/sort/get.c src/sort/move.c src/sort/sort.c
SRC_QUICKSORT = src/sort/quicksort_get.c src/sort/quicksort_push.c src/sort/quicksort.c
SRC = $(SRC_OPERATIONS) $(SRC_STACK) $(SRC_SORT) $(SRC_QUICKSORT) src/push_swap.c 
OBJ = $(SRC:.c=.o)
NAME = push_swap

# Compile your project
all: $(LIBFT) $(NAME)

# Compile libft first
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile push_swap and link with libft
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# Clean object files
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

# Clean everything including libft
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompile everything
re: fclean all

# Dependencies
.PHONY: all clean fclean re
