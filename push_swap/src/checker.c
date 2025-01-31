#include "../push_swap.h"
#include <stdio.h>

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int main(int argc, char **argv)
{
    t_node *a;
    
    if (argc < 2)
        return (1);
    a = init_stack(argc, argv);
    if (!a)
        return (1);

    if (is_sorted(a))
        printf("OK\n");
    else
        printf("KO\n");

    free_stack(a);
    return (0);
}
