/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:52:33 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/16 18:52:39 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	quicksort(t_node **stack_a, t_node **stack_b)
{
	int		size;
	int		quicksort_size;
	int		original_size;

	size = stack_size(*stack_a);
	original_size = size;
	if (original_size < 20)
		quicksort_size = 3;
	else if (original_size < 120)
		quicksort_size = 19;
	else
		quicksort_size = 52;
	push_to_b(stack_a, stack_b, quicksort_size);
	push_to_a(stack_a, stack_b);
	operations_handler("end");
	operations_handler("print");
}
