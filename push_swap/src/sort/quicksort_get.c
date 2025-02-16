/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:52:58 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/16 18:53:00 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
