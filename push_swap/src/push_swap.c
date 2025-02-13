/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ray <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:02:14 by ray               #+#    #+#             */
/*   Updated: 2025/02/13 18:02:15 by ray              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "stdio.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (stack_is_sorted(*a) == 1)
		return ;
	if (size == 2)
	{
		sx(a, "sa");
		operations_handler("end");
		return (operations_handler("print"));
	}
	if (size == 3)
	{
		sort_three(a);
		operations_handler("end");
		return (operations_handler("print"));
	}
	if (size < 6)
	{
		sort_simple(a, b);
		operations_handler("end");
		return (operations_handler("print"));
	}
	chunk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	if (argc < 2)
		return (1);
	a = init_stack(argc, argv);
	if (!a)
	{
		free_stack(a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
