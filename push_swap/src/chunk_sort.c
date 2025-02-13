#include "../push_swap.h"
#include <stdio.h>

#include <stdio.h>

double sqrt_manual(int n) {
    if (n == 0 || n == 1) return n; // Base case

    double x = n;
    double guess = n / 2.0; // Initial guess

    while (x - guess > 0.00001 || guess - x > 0.00001) { // Precision check
        x = guess;
        guess = (x + (n / x)) / 2.0;
    }

    return guess;
}



int get_closest_min_index(t_node *current, int min)
{
	int i;

	i = 0;
	while (current)
	{
		if (current->value <= min)
			return i;
		current = current->next;
		i++;
	}
	return (i);
}

static void push_to_a(t_node **stack_a, t_node **stack_b)
{
	int first;
	int second;
	int first_index;
	int second_index;
	int first_moves_required;
	int second_moves_required;
	int size = stack_size(*stack_b);

	while (*stack_b)
	{
		first = get_max(*stack_b);
		second = get_next_max(*stack_b, first);
		// printf("FIND: %d\n", first);
		// print_stack(*stack_b);
		first_index = get_index(*stack_b, first);
		// printf("first index is: %d\n", first_index);
		second_index = get_index(*stack_b, second);
		// printf("FIND: %d\n", second);
		// printf("second index is: %d\n", second_index);
		first_moves_required = first_index;
		second_moves_required = second_index;
		// printf("size / 2 %d\n", size/2);
		if (first_index > size / 2)
			first_moves_required = size - first_index;
		if (second_moves_required > size / 2)
			second_moves_required = size - second_index;
		// print_stack(*stack_b);
		// printf("first_moves_required: %d\n", first_moves_required);
		// printf("second_moves_required: %d\n", second_moves_required);
		if (first_moves_required <= second_moves_required)
		{
			// printf("moving first...\n");
			// print_stack(*stack_a);
			move_to_top(stack_b, first_index, size, 'b');
			px(stack_a, stack_b, "pa");
			size--;
			// print_stack(*stack_a);
			if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			{
				// printf("head value: %d - next value: %d\n", (*stack_a)->value, (*stack_a)->next->value);
				sx(stack_a, "sa");
			}
			second_index = get_index(*stack_b, second);
			// print_stack(*stack_a);
			move_to_top(stack_b, second_index, size, 'b');
			px(stack_a, stack_b, "pa");
			size--;
			// print_stack(*stack_a);
			if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			{
				// printf("head value: %d - next value: %d\n", (*stack_a)->value, (*stack_a)->next->value);
				sx(stack_a, "sa");
			}
		}
		else
		{
			// printf("moving second...\n");
			move_to_top(stack_b, second_index, size, 'b');
			px(stack_a, stack_b, "pa");
			size--;
			// print_stack(stack_a);
			// print_stack(*stack_a);
			if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			{
				// printf("head value: %d - next value: %d\n", (*stack_a)->value, (*stack_a)->next->value);
				sx(stack_a, "sa");
			}
			first_index = get_index(*stack_b, first);
			// print_stack(*stack_a);
			move_to_top(stack_b, first_index, size, 'b');
			// print_stack(*stack_a);

			px(stack_a, stack_b, "pa");
			size--;
			// print_stack(stack_a);
			// print_stack(*stack_a);
			if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			{
				// printf("head value: %d - next value: %d\n", (*stack_a)->value, (*stack_a)->next->value);
				sx(stack_a, "sa");
			}
		}
	}
}

void chunk_sort(t_node **stack_a, t_node **stack_b)
{
	(void)stack_b;
	// int	index;
	int min_int;
	int times;
	int size = stack_size(*stack_a);
	int chunk_size;
	int middle;
	// chunk_size = 50;
	// if(size <= 120){
	// 	chunk_size=18;
	// }

	int original_size = size;
	t_node *stack_c;

	duplicate_stack(&stack_c, *stack_a);
	// clone stack a into stack c

	// while chunk size is less than the size of the stack
	// reset / empty stack a
	// fill it with stack c elements
	// sort it.
	chunk_size = original_size / sqrt_manual(original_size);
	if(original_size < 20){
		chunk_size = 3;
	}
	else if (original_size < 120)
		chunk_size = 19;
	else
		chunk_size = 52;
	


	while (chunk_size < original_size)
	{
		free_stack(*stack_a);
		free_stack(*stack_b);
		duplicate_stack(stack_a, stack_c);

		size = original_size;

		while (*stack_a /* && size > 3 */)
		{
			times = 0;
			min_int = get_min(*stack_a);
			// printf("min int: %d\n", min_int);
			while (*stack_a && times++ < chunk_size)
			{
				min_int = get_next_min(*stack_a, min_int);
				//  printf("next min int: %d\n", min_int);
				if (times == chunk_size / 2)
					middle = min_int;
			}

			times = 0;
			while (*stack_a /* && size > 3 */ && times++ < chunk_size)
			{
				// print_stack(*stack_a);
				int index = get_closest_min_index(*stack_a, min_int);
				// printf("MIN INT: %d - INDEX: %d\n", min_int, index);
				if (index > size / 2)
					index = size - index;
				move_to_top(stack_a, index, size, 'a');
				px(stack_b, stack_a, "pb");
				size--;
				if((*stack_b)->value < middle)
					rx(stack_b, "rb");
				// if (stack_b->stack[0] < stack_a->middle)
				// 	ft_do_rotate(stack_b, 'b');
			}
		}
		//sort_three(stack_a);
		//printf("chunk size: %d\n", chunk_size);
		push_to_a(stack_a, stack_b);
		chunk_size = original_size;
		add_operation("end");
	}
	add_operation("print");
}