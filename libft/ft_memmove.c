/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:55:16 by ddragos           #+#    #+#             */
/*   Updated: 2024/12/14 21:55:32 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*_src;
	unsigned char		*_dest;

	if (src == NULL && dest == NULL)
		return (NULL);
	_src = (const unsigned char *)src;
	_dest = (unsigned char *)dest;
	if (_src < _dest)
		while (n-- > 0)
			_dest[n] = _src[n];
	else
	{
		i = 0;
		while (i < n)
		{
			_dest[i] = _src[i];
			i++;
		}
	}
	return (dest);
}
