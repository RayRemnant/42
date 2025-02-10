#include "../push_swap.h"
#include "stdio.h"

#define OPERATION_STRING_SIZE 1024

static void add_operation(const char *op){
    static char operations_string[1024] = "";

	printf("%s\n", op);
	return;

    if (ft_strlen(operations_string) + ft_strlen(op) + 1 < 1024) {
        ft_strlcat(operations_string, op, 1024);
        printf("%s\n", operations_string);
    } else {
        printf("Error: operation string buffer overflow\n");
    }
}

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


void sx(t_node**stack, char *op){
	if(swap(stack))
		add_operation(op);
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

void px(t_node **dest, t_node **src, char *op){
	if(push(dest, src))
		add_operation(op);
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

void rx(t_node**stack, char *op){
	if(rotate(stack))
		add_operation(op);
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


void rrx(t_node**stack, char *op){
	if(reverse_rotate(stack))
		add_operation(op);
}

