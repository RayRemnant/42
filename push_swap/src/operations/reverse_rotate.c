/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:06:28 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:06:31 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rrx(t_node **stack, char *op)
{
	if (reverse_rotate(stack))
		operations_handler(op);
}
