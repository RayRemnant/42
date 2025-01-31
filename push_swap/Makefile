# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Your project files
SRC = src/push_swap.c src/operations.c src/stack_utils.c src/sorting.c
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
