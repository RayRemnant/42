/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:06:22 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:06:23 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_node **dest, t_node **src)
{
	t_node	*head_src;

	if (!src || !(*src))
		return (0);
	head_src = *src;
	*src = head_src->next;
	head_src->next = *dest;
	*dest = head_src;
	return (1);
}

void	px(t_node **dest, t_node **src, char *op)
{
	if (push(dest, src))
		operations_handler(op);
}
