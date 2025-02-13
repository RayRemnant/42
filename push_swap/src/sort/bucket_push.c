/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:52:25 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 20:52:26 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_min_to_b(t_node **stack_a, t_node **stack_b, int bucket_size,
		int min)
{
	int	times;
	int	index;
	int	middle;
	int	size;

	size = stack_size(*stack_a);
	times = 0;
	while (*stack_a && times++ < bucket_size)
	{
		min = get_next_min(*stack_a, min);
		if (times == bucket_size / 2)
			middle = min;
	}
	times = 0;
	while (*stack_a && times++ < bucket_size)
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

void	push_to_b(t_node **stack_a, t_node **stack_b, int bucket_size)
{
	int	min;

	min = get_min(*stack_a);
	while (*stack_a)
		push_min_to_b(stack_a, stack_b, bucket_size, min);
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

void	push_to_a(t_node **stack_a, t_node **stack_b)
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
		size = size - 2;
	}
}
