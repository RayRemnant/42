#include "../push_swap.h"
#include "stdio.h"
// Swap top two elements of stack A
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


// Swap top two elements of stack B (same as sa)
void sb(t_node **stack)
{
	if (swap(stack))
		printf("sb\n");
}

void sa(t_node **stack)
{
	if (swap(stack))
		printf("sa\n");
}

// Swap both stacks A and B
void ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
	printf("ss\n");
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

void pa(t_node **a, t_node **b)
{
	if(push(a, b))
		printf("pa\n");
}

void pb(t_node **b, t_node **a)
{
	if(push(b, a))
		printf("pb\n");
}



// Rotate stack A (shift up)
void rotate(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    t_node *first = *stack;
    t_node *last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

// Rotate stack B (same as ra)
void rb(t_node **stack)
{
    rotate(stack);
	printf("rb\n");
}

// Rotate stack B (same as ra)
void ra(t_node **stack)
{
    rotate(stack);
	printf("ra\n");
}

void rx(t_node**stack, char stack_char){
	rotate(stack);
	printf("r%c\n", stack_char);
}

// Rotate both stacks A and B
void rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
}

// Reverse rotate stack A (shift down)
void reverse_rotate(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
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
}

// Reverse rotate stack B (same as rra)
void rrb(t_node **stack)
{
    reverse_rotate(stack);
	printf("rrb\n");
}

void rra(t_node **stack)
{
    reverse_rotate(stack);
	printf("rra\n");
}

void rrx(t_node**stack, char stack_char){
	reverse_rotate(stack);
	printf("rr%c\n", stack_char);
}

// Reverse rotate both stacks A and B
void rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
	printf("rrr\n");
}
