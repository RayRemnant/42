# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft

# Output library
NAME = libftprintf.a

# Source and object files
SRCS = ft_printf.c ft_print_char.c ft_print_string.c ft_print_int.c ft_print_unsigned_int.c ft_print_hex.c ft_print_pointer.c 
OBJS = $(SRCS:.c=.o)

# Dependencies
LIBFT = ./libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)              # Copy libft.a to libftprintf.a
	@ar rcs $(NAME) $(OBJS)           # Add printf.o to libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c