#include "../push_swap.h"
#include "stdio.h"

/* static void add_operation(const char *op){
	static char	operations_string[SIZE_MAX/2];

	ft_strlcat(operations_string, op, SIZE_MAX);

	printf("%s\n", operations_string);
} */

static int swap(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return (0);

    t_node *first = *stack;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
	return (1);
}


void sx(t_node**stack, char stack_char){
	if(swap(stack))
		printf("s%c\n", stack_char);
}

int push(t_node **dest, t_node **src)
{
    if (!src || !(*src))
        return (0);
    t_node *head_src = *src;
    *src = head_src->next;
    head_src->next = *dest;
    *dest = head_src;
	return (1);
}

void px(t_node **dest, t_node **src, char dest_char){
	if(push(dest, src))
		printf("p%c\n", dest_char);
}

// Rotate stack A (shift up)
int rotate(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return 0;
    t_node *first = *stack;
    t_node *last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    first->next = NULL;
    last->next = first;
	return (1);
}

void rx(t_node**stack, char stack_char){
	if(rotate(stack))
		printf("r%c\n", stack_char);
}

// Reverse rotate stack A (shift down)
int reverse_rotate(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return (0);
    t_node *prev = NULL;
    t_node *last = *stack;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
	return(1);
}


void rrx(t_node**stack, char stack_char){
	if(reverse_rotate(stack))
		printf("rr%c\n", stack_char);
}

