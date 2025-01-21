/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:41:04 by ddragos           #+#    #+#             */
/*   Updated: 2025/01/21 19:41:06 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_string(char *s);
int	ft_print_int(int i);
int	ft_print_unsigned_int(unsigned int u);
int	ft_print_hex(unsigned long x, int upper);
int	ft_print_pointer(unsigned long p);

#endif
