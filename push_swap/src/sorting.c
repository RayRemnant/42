#include "../push_swap.h"
#include <stdio.h>

int stack_size(t_node *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

int find_smallest_index(t_node *stack)
{
    int min = stack->value;
    int min_index = 0;
    int index = 0;
    t_node *current = stack;

    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_index = index;
        }
        index++;
        current = current->next;
    }
    return min_index;
}

void move_smallest_to_top(t_node **stack)
{
    int min_index = find_smallest_index(*stack);
    int size = stack_size(*stack);

    if (min_index <= size / 2)
    {
        while (min_index-- > 0)
            ra(stack);
    }
    else
    {
        min_index = size - min_index;
        while (min_index-- > 0)
            rra(stack);
    }
}


#include "../push_swap.h"
#include <stdio.h>

// Sort a stack of size 3 with fewer moves
void sort_three(t_node **a)
{
    int num1 = (*a)->value;
    int num2 = (*a)->next->value;
    int num3 = (*a)->next->next->value;

    // Case 1: 3 2 1 (needs swap and reverse rotation)
    if (num1 > num2 && num2 > num3)
    {
        sa(a);  // Swap top two: 2 3 1
        printf("sa\n");
        rra(a); // Reverse rotate: 1 2 3
        printf("rra\n");
    }
    // Case 2: 3 1 2 (needs rotation)
    else if (num1 > num3 && num3 > num2)
    {
        ra(a);  // Rotate: 1 2 3
        printf("ra\n");
    }
    // Case 3: 2 3 1 (needs swap and rotate)
    else if (num2 > num1 && num1 > num3)
    {
        rra(a);  // Swap top two: 3 2 1
        printf("rra\n");
    }
    // Case 4: 1 3 2 (needs swap and rotate)
     else if (num2 > num3 && num3 > num1)
    {
        rra(a);
        printf("rra\n");
        sa(a);
        printf("sa\n");
    }
    // Case 5: 2 1 3 
      else if (num3 > num1 && num1 > num2)
    {
        sa(a);
        printf("sa\n");
    }
    // Case 4: 1 3 2 (already sorted, no action needed)
    // No action needed as the stack is already sorted in ascending order.
}




// Sort a stack of size 5
void sort_five(t_node **a, t_node **b)
{
    while (stack_size(*a) > 3) // Move two smallest elements to stack B
    {
        move_smallest_to_top(a);
        pb(b, a);
        printf("pb\n");
    }

    sort_three(a); // Sort the remaining three elements in stack A

    while (*b) // Move elements back from stack B to stack A
    {
        pa(a, b);
        printf("pa\n");
    }
}

// Radix Sort for Large Stacks
void radix_sort(t_node **a, t_node **b)
{
    int size = stack_size(*a);
    int max_bits = 0;
    int i, j;
    
    t_node *temp = *a;
    while (temp)
    {
        if (temp->value > (1 << max_bits))
            max_bits++;
        temp = temp->next;
    }

    for (i = 0; i < max_bits; i++)
    {
        j = size;
        while (j--)
        {
            if (((*a)->value >> i) & 1)
            {
                ra(a);
                printf("ra\n");
            }
            else
            {
                pb(b, a);
                printf("pb\n");
            }
        }
        while (*b)
        {
            pa(a, b);
            printf("pa\n");
        }
    }
}

// Main sorting function
// Sort a stack of exactly 3 elements using sort_three
void sort_stack(t_node **a, t_node **b)
{
    int size = stack_size(*a);

    // Repeatedly find the smallest element and push it to stack B
    while (size > 0)
    {
        move_smallest_to_top(a);  // Move the smallest element to the top
        pb(b, a);  // Push the smallest element to stack B
        printf("pb\n");
        size--;
    }

    // Move elements from stack B back to stack A
    while (*b)
    {
        pa(a, b);  // Push the top element from stack B to stack A
        printf("pa\n");
    }
}