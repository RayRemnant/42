/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:06:47 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:06:48 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sx(t_node **stack, char *op)
{
	if (swap(stack))
		operations_handler(op);
}
