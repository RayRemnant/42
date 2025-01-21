/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:02:48 by ddragos           #+#    #+#             */
/*   Updated: 2025/01/21 19:02:50 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long p)
{
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_print_hex(p, 0) + 2);
	}
}
