/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:30:16 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 19:30:18 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void	sort_three(t_node **a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*a)->value;
	num2 = (*a)->next->value;
	num3 = (*a)->next->next->value;
	if (num1 > num2 && num2 > num3)
	{
		sx(a, "sa");
		rrx(a, "rra");
	}
	else if (num1 > num3 && num3 > num2)
		rx(a, "ra");
	else if (num2 > num1 && num1 > num3)
		rrx(a, "rra");
	else if (num2 > num3 && num3 > num1)
	{
		rrx(a, "rra");
		sx(a, "sa");
	}
	else if (num3 > num1 && num1 > num2)
		sx(a, "sa");
}

void	sort_simple(t_node **a, t_node **b)
{
	int	size;
	int	min;
	int	index;

	size = stack_size(*a);
	while (stack_size(*a) > 3)
	{
		min = get_min(*a);
		index = get_index(*a, min);
		move_to_top(a, index, size, 'a');
		px(b, a, "pb");
		size--;
	}
	sort_three(a);
	while (*b)
		px(a, b, "pa");
}
