#include "../push_swap.h"
#include "stdio.h"


int main(int argc, char **argv)
{
    t_node *a;
    t_node *b = NULL;

    if (argc < 2)
        return (1);

    a = init_stack(argc, argv);
    if (!a)
    {
		free_stack(a);
        ft_putstr_fd("Error\n", 2);
        return (1);
    }

    sort_stack(&a, &b);
    //printf("SORTED\n");
    // print_stack(a);


    free_stack(a);
    free_stack(b);
    return (0);
}
