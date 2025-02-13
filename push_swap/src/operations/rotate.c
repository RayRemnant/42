/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:06:38 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:06:39 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	rx(t_node **stack, char *op)
{
	if (rotate(stack))
		operations_handler(op);
}
