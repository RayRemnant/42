#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h" 

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

// Stack operations
void 	sx(t_node**stack, char *op);
void	px(t_node **dest, t_node **src, char *op);
void 	rx(t_node**stack, char *op);
void	rrx(t_node**stack, char *op);

// Sorting
void    sort_stack(t_node **a, t_node **b);

// Utils
int stack_size(t_node *stack);
t_node  *init_stack(int argc, char **argv);
void    free_stack(t_node *stack);
void    print_stack(t_node *stack);
void	chunk_sort(t_node **a, t_node **b);
void duplicate_stack(t_node **dest, t_node *src);
void add_operation(const char *op);
void sort_three(t_node **a);

// Sorting utils
int get_min(t_node *stack);
void move_to_top(t_node **stack, int index, int size, char stack_char);
int get_index(t_node *current, int n);
int get_max(t_node *stack);
int get_next_max(t_node *current, int max);
int get_next_min(t_node *current, int min);

#endif
