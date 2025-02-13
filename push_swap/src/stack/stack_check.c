/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:07:21 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:07:22 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_is_sorted(t_node *current)
{
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_size(t_node *current)
{
	int	size;

	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	stack_has_duplicates(t_node *head)
{
	t_node	*i;
	t_node	*j;

	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
			{
				return (1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

// Function to print the stack for testing
void	print_stack(t_node *head)
{
	char	*str_value;

	str_value = ft_itoa(head->value);
	while (head)
	{
		ft_putstr_fd(str_value, 1);
		free(str_value);
		head = head->next;
	}
	ft_putstr_fd("\n", 1);
}
