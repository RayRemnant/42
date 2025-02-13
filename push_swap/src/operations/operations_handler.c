/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:06:17 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:06:18 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	operations_handler(const char *op)
{
	static char	best_operations[999991];
	static char	current_operations[999991];
	size_t		current_len;
	size_t		best_len;

	current_len = ft_strlen(current_operations);
	best_len = ft_strlen(best_operations);
	if (ft_strncmp(op, "end", 3) == 0)
	{
		if (best_len == 0 || (current_len < best_len && current_len > 0))
		{
			ft_memcpy(best_operations, current_operations, current_len + 1);
			best_operations[current_len] = '\0';
		}
		return ;
	}
	if (ft_strncmp(op, "print", 5) == 0)
		return ((void)ft_putstr_fd(best_operations, 1));
	ft_strlcat(current_operations, op, current_len + 5);
	ft_strlcat(current_operations, "\n", current_len + 10);
}
