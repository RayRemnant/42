#include "../../push_swap.h"

int	get_closest_min_index(t_node *current, int min)
{
	int	i;

	i = 0;
	while (current)
	{
		if (current->value <= min)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

static void	push_max_to_a(t_node **stack_a, t_node **stack_b, int index,
		int number)
{
	int	size;

	size = stack_size(*stack_b);
	move_to_top(stack_b, index, size, 'b');
	px(stack_a, stack_b, "pa");
	size--;
	if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
		sx(stack_a, "sa");
	index = get_index(*stack_b, number);
	move_to_top(stack_b, index, size, 'b');
	px(stack_a, stack_b, "pa");
	size--;
	if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
		sx(stack_a, "sa");
}

int	get_moves_required(t_node **stack_b, int number, int size)
{
	int	moves_required;
	int	index;

	index = get_index(*stack_b, number);
	moves_required = index;
	if (index > size / 2)
		moves_required = size - index;
	return (moves_required);
}

static void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int	first;
	int	second;
	int	first_moves_required;
	int	second_moves_required;
	int	size;

	size = stack_size(*stack_b);
	while (*stack_b)
	{
		first = get_max(*stack_b);
		second = get_next_max(*stack_b, first);
		first_moves_required = get_moves_required(stack_b, first, size);
		second_moves_required = get_moves_required(stack_b, second, size);
		if (first_moves_required <= second_moves_required)
			push_max_to_a(stack_a, stack_b, get_index(*stack_b,
					get_max(*stack_b)), second);
		else
			push_max_to_a(stack_a, stack_b, get_index(*stack_b,
					get_next_max(*stack_b, get_max(*stack_b))), first);
	}
}

static void	push_min_to_b(t_node **stack_a, t_node **stack_b, int chunk_size)
{
	int	times;
	int	min;
	int	index;
	int	middle;
	int	size;

	size = stack_size(*stack_a);
	times = 0;
	min = get_min(*stack_a);
	while (*stack_a && times++ < chunk_size)
	{
		min = get_next_min(*stack_a, min);
		if (times == chunk_size / 2)
			middle = min;
	}
	times = 0;
	while (*stack_a && times++ < chunk_size)
	{
		index = get_closest_min_index(*stack_a, min);
		if (index > size / 2)
			index = size - index;
		move_to_top(stack_a, index, size, 'a');
		px(stack_b, stack_a, "pb");
		size--;
		if ((*stack_b)->value < middle)
			rx(stack_b, "rb");
	}
}

static void	push_to_b(t_node **stack_a, t_node **stack_b, int chunk_size)
{
	while (*stack_a)
		push_min_to_b(stack_a, stack_b, chunk_size);
}

void	chunk_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*stack_c;
	int	size;
	int	chunk_size;
	int	original_size;

	size = stack_size(*stack_a);
	original_size = size;
	duplicate_stack(&stack_c, *stack_a);
	if (original_size < 20)
		chunk_size = 3;
	else if (original_size < 120)
		chunk_size = 19;
	else
		chunk_size = 52;
	while (chunk_size < original_size)
	{
		free_stack(*stack_a);
		free_stack(*stack_b);
		duplicate_stack(stack_a, stack_c);
		push_to_b(stack_a, stack_b, chunk_size);
		push_to_a(stack_a, stack_b);
		chunk_size = original_size;
		operations_handler("end");
	}
	operations_handler("print");
}
