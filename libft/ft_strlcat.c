/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:57:20 by ddragos           #+#    #+#             */
/*   Updated: 2024/12/15 10:57:29 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	if (!size)
	{
		return (ft_strlen(src));
	}
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (!size || size <= dest_len)
		return (src_len + size);
	while ((dest_len + i) < (size - 1) && src[i])
	{
		if (dest)
			dest[dest_len + i] = src[i];
		i++;
	}
	if (dest && (dest_len + i) < size)
		dest[dest_len + i] = 0;
	return (dest_len + src_len);
}
