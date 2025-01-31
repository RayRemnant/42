/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:32:56 by ddragos           #+#    #+#             */
/*   Updated: 2024/12/15 00:32:59 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dst_len)
		ft_memcpy(dst, src, src_len + 1);
	else if (dst_len != 0)
	{
		ft_memcpy(dst, src, dst_len - 1);
		dst[dst_len - 1] = 0;
	}
	return (src_len);
}
