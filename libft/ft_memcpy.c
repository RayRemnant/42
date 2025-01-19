/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:52 by ddragos           #+#    #+#             */
/*   Updated: 2024/12/14 21:30:55 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*_src;
	unsigned char		*_dest;

	if (dest == NULL && src == NULL)
		return (dest);
	_src = (const unsigned char *)src;
	_dest = (unsigned char *)dest;
	while (n > 0)
	{
		*_dest++ = *_src++;
		n--;
	}
	return (dest);
}
