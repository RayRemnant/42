/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:51:26 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 20:51:27 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bucket_sort(t_node **stack_a, t_node **stack_b)
{
	int		size;
	int		bucket_size;
	int		original_size;

	size = stack_size(*stack_a);
	original_size = size;
	if (original_size < 20)
		bucket_size = 3;
	else if (original_size < 120)
		bucket_size = 19;
	else
		bucket_size = 52;
	push_to_b(stack_a, stack_b, bucket_size);
	push_to_a(stack_a, stack_b);
	operations_handler("end");
	operations_handler("print");
}
