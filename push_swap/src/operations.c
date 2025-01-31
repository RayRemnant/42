#include "../push_swap.h"
#include "stdio.h"
// Swap top two elements of stack A
void sa(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    t_node *first = *stack;
    t_node *second = first->next;
    
    first->next = second->next;
    second->next = first;
    *stack = second;
}

// Swap top two elements of stack B (same as sa)
void sb(t_node **stack)
{
    sa(stack);
}

// Swap both stacks A and B
void ss(t_node **a, t_node **b)
{
    sa(a);
    sb(b);
}

// Push top of stack B to stack A
void pa(t_node **a, t_node **b)
{
    if (!b || !(*b))
        return;
    t_node *top_b = *b;
    *b = top_b->next;
    top_b->next = *a;
    *a = top_b;
}

// Push top of stack A to stack B
void pb(t_node **b, t_node **a)
{
    pa(b, a);
}

// Rotate stack A (shift up)
void ra(t_node **stack)
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
    ra(stack);
}

// Rotate both stacks A and B
void rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
}

// Reverse rotate stack A (shift down)
void rra(t_node **stack)
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
    rra(stack);
}

// Reverse rotate both stacks A and B
void rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
}
