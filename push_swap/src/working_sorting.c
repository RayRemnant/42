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

int check_sorted(t_node **a)
{
	t_node *current = *a;
	while (current->next)
	{
		// printf("current value: %d\n", current->value);
		if (current->value > current->next->value)
			return 0;
		current = current->next;
	}
	// printf("is sorted\n");
	return 1;
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

	// printf("min value is: %d\n", min);
	//printf("min_index: %d\n", min_index);
    return min_index;
}

void move_smallest_to_top(t_node **stack)
{
    int min_index = find_smallest_index(*stack);
	// printf("min_index: %d\n", min_index);
    int size = stack_size(*stack);
	// printf("size: %d\n", size);

    if (min_index <= size / 2)
    {
        while (min_index-- > 0)
		{
            ra(stack);
			printf("ra\n");
		}
    }
    else
    {
        min_index = size - min_index;
        while (min_index-- > 0)
		{
            rra(stack);
			printf("rra\n");
		}
    }
}


// Function to find the index of the largest element in the stack
int find_largest_index(t_node *stack)
{
    int max = stack->value;
    int max_index = 0;
    int index = 0;
    t_node *current = stack;

    while (current)
    {
        if (current->value > max)
        {
            max = current->value;
            max_index = index;
        }
        index++;
        current = current->next;
    }
	// printf("largest value is: %d\n", max);
    return max_index;
}

// Function to move the largest element to the top of stack A
void move_biggest_to_top(t_node **stack)
{
    int max_index = find_largest_index(*stack);
	//printf("Stack A: \n");
	print_stack(*stack);
	//printf("\n");
	//printf("max_index: %d\n", max_index);
    int size = stack_size(*stack);

    if (max_index <= size / 2)
    {
        while (max_index-- > 0)
        {
            ra(stack);
            printf("ra\n");
        }
    }
    else
    {
        max_index = size - max_index;
        while (max_index-- > 0)
        {
            rra(stack);
            printf("rra\n");
        }
    }
}

void move_to_top(t_node **stack, int index, int size){
	if (index <= size / 2)
	{
		while (index-- > 0)
		{
			ra(stack);
			printf("ra\n");
		}
	}
	else
	{
		index = size - index;
		while (index-- > 0)
		{
			rra(stack);
			printf("rra\n");
		}
	}
}

void move_small(t_node **a, t_node **b)
{
    int min_index = find_smallest_index(*a);
    int size = stack_size(*a);

    // Move only the smallest number to the top and push it to B
    move_to_top(a, min_index, size);
    pb(b, a);
    printf("pb\n");
}


void move_big_or_small(t_node **a, t_node **b)
{
	int max_index = find_largest_index(*a);
	int min_index = find_smallest_index(*a);
	int size = stack_size(*a);

	int moves_required_max = max_index;
	if(max_index > size / 2)
	{
		moves_required_max = size - max_index;
	}

	int moves_required_min = min_index;
	if(min_index > size / 2)
	{
		moves_required_min = size - min_index;
	}
	
	if(moves_required_max < moves_required_min)
	{
		// printf("max_index: %d\n", max_index);
		move_to_top(a, max_index, size);
	}
	else
	{
		move_to_top(a, min_index, size);
	}

	pb(b, a);
	printf("pb\n");
}

int abs_value(int n)
{
	if (n < 0)
		return -n;
	else
		return n;
}

int find_closer_number_index(t_node *stack, int b_number)
{
    int closer_number = stack->value;
    int closer_index = 0;
    int index = 0;
    t_node *current = stack;

    while (current)
    {
        if (abs_value(current->value - b_number) < abs_value(closer_number - b_number))
		{
			closer_number = current->value;
			closer_index = index;
		}
        index++;
        current = current->next;
    }
	//printf("largest value is: %d\n", max);
    return closer_index;
}

int find_biggest_number(t_node *stack)
{
	int max = stack->value;
	t_node *current = stack;

	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
		}
		current = current->next;
	}
	return max;
}

int find_smallest_number(t_node *stack)
{
	int min = stack->value;
	t_node *current = stack;

	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
		}
		current = current->next;
	}
	return min;
}

void move_closer_less_moves(t_node **a, t_node **b){
	if (check_sorted(a)) return;

	int smallest_b = find_smallest_number(*b);
	int biggest_b = find_biggest_number(*b);

	int closer_index_smallest = find_closer_number_index(*a, smallest_b);
	int closer_index_biggest = find_closer_number_index(*a, biggest_b);

	int size = stack_size(*a);

	int moves_required_biggest = closer_index_biggest;

	if(closer_index_biggest > size / 2)
	{
		moves_required_biggest = size - closer_index_biggest;
	}

	int moves_required_smallest = closer_index_smallest;
	if(closer_index_smallest > size / 2)
	{
		moves_required_smallest = size - closer_index_smallest;
	}
	
	if(moves_required_biggest < moves_required_smallest)
	{
		move_to_top(a, moves_required_biggest, size);
		pb(b, a);
		printf("pb\n");
		ra(b);
		printf("rb\n");
	}
	else
	{
		move_to_top(a, closer_index_smallest, size);
		pb(b, a);
		printf("pb\n");
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




// Main sorting function
// Sort a stack of exactly 3 elements using sort_three
void sort_stack(t_node **a, t_node **b)
{
    int size = stack_size(*a);

	/* printf("\nStack A: \n");
	print_stack(*a);
	printf("\nStack B: \n");
	print_stack(*b);
	printf("\n"); */

	if(check_sorted(a) == 1){
		//printf("is sorted\n");
		return ;
	}

	if(size == 2){
		sa(a);
		printf("sa\n");
		return ;
	}

	if(size == 3){
		sort_three(a);
		return ;
	}

	//move the biggest or smallest number from a to b, whichever requires less moves
	move_small(a, b); 
	size--;
    while (size > 3)
    {
		//move the closest number to max b or min b, whichever requires less moves
		move_closer_less_moves(a, b);  
        size--;
    }

	sort_three(a);

    // Move elements from stack B back to stack A
    while (*b)
    {
        pa(a, b);  // Push the top element from stack B to stack A
        printf("pa\n");
		if((*a)->value > (*a)->next->value){
			ra(a);
			printf("ra\n");
		}
    }	
	

}