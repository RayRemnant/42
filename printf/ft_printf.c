/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:03:05 by ddragos           #+#    #+#             */
/*   Updated: 2025/01/21 18:03:48 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percentage_sign(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	check_format(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (*format == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (*format == 'i' || *format == 'd')
		return (ft_print_int(va_arg(args, int)));
	if (*format == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (*format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (*format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (*format == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));
	if (*format == '%')
		return (ft_print_percentage_sign());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;

	va_start(args, format);
	chars_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			chars_printed += check_format(format, args);
		}
		else
		{
			write(1, format, 1);
			chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
/*
int	main(int argc, char **argv){
	(void)argc;
	(void)argv;

	//char *pi = "3";
	//ft_printf("%c %s %d %i %u %x %X %p", 'k', "miao", 42, 42, 42, 0, 0, pi);
	ft_printf("%c", '0');
	ft_printf(" %c ", '0');
	ft_printf(" %c", '0' - 256);
	ft_printf("%c ", '0' + 256);
	ft_printf(" %c %c %c ", '0', 0, '1');
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	ft_printf(" %c %c %c ", '1', '2', '3');
	ft_printf(" %c %c %c ", '2', '1', 0);
	ft_printf(" %c %c %c \n", 0, '1', '2');

	//printf("%c %s %d %i %u %x %X %p", 'k', "miao", 42, 42, 42, 0, 0, pi);
	printf("%c", '0');
	printf(" %c ", '0');
	printf(" %c", '0' - 256);
	printf("%c ", '0' + 256);
	printf(" %c %c %c ", '0', 0, '1');
	printf(" %c %c %c ", ' ', ' ', ' ');
	printf(" %c %c %c ", '1', '2', '3');
	printf(" %c %c %c ", '2', '1', 0);
	printf(" %c %c %c \n", 0, '1', '2');
	return (0);
}
 */
