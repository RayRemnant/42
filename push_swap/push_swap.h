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
void    sa(t_node **stack);
void    sb(t_node **stack);
void    ss(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);
void    ra(t_node **stack);
void    rb(t_node **stack);
void 	rx(t_node**stack, char stack_char);
void    rr(t_node **a, t_node **b);
void    rra(t_node **stack);
void    rrb(t_node **stack);
void rrx(t_node**stack, char stack_char);
void    rrr(t_node **a, t_node **b);

// Sorting
void    sort_stack(t_node **a, t_node **b);

// Utils
int stack_size(t_node *stack);
t_node  *init_stack(int argc, char **argv);
void    free_stack(t_node *stack);
void    print_stack(t_node *stack);
void	chunk_sort(t_node **a, t_node **b);

#endif
