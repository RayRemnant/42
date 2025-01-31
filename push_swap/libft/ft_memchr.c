/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:25:01 by ddragos           #+#    #+#             */
/*   Updated: 2024/12/15 00:25:17 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*_s;

	i = 0;
	_s = (unsigned char *)s;
	while (i < n)
	{
		if (_s[i] == (unsigned char)c)
			return ((void *)&_s[i]);
		i++;
	}
	return (NULL);
}
