/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:30:31 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 19:30:32 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	move_to_top(t_node **stack, int index, int size, char stack_char)
{
	char	op[4];

	op[0] = 'r';
	if (index <= size / 2)
	{
		op[1] = stack_char;
		op[2] = '\0';
		while (index-- > 0)
			rx(stack, op);
	}
	else
	{
		index = size - index;
		op[1] = 'r';
		op[2] = stack_char;
		op[3] = '\0';
		while (index-- > 0)
			rrx(stack, op);
	}
}
