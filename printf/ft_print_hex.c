/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:06:59 by ddragos           #+#    #+#             */
/*   Updated: 2025/01/21 19:07:00 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex(unsigned long num, const char *hex_digits)
{
	int	chars_printed;

	chars_printed = 0;
	if (num >= 16)
		chars_printed += ft_puthex(num / 16, hex_digits);
	ft_putchar_fd(hex_digits[num % 16], 1);
	chars_printed++;
	return (chars_printed);
}

int	ft_print_hex(unsigned long x, int upper)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (upper)
		hex_digits = "0123456789ABCDEF";
	return (ft_puthex(x, hex_digits));
}
