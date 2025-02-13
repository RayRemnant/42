/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:30:58 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 19:30:57 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_index(t_node *current, int n)
{
	int	index;

	index = 0;
	while (current)
	{
		if (current->value == n)
			return (index);
		current = current->next;
		index++;
	}
	return (index);
}

int	get_max(t_node *stack)
{
	int		max;
	t_node	*current;

	max = stack->value;
	current = stack;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_next_max(t_node *current, int max)
{
	int	next_max;

	next_max = INT_MIN;
	while (current)
	{
		if (current->value < max && current->value > next_max)
			next_max = current->value;
		current = current->next;
	}
	return (next_max);
}

int	get_min(t_node *stack)
{
	int		min;
	t_node	*current;

	min = stack->value;
	current = stack;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_next_min(t_node *current, int min)
{
	int	next_min;

	next_min = INT_MAX;
	while (current)
	{
		if (current->value > min && current->value < next_min)
			next_min = current->value;
		current = current->next;
	}
	return (next_min);
}
