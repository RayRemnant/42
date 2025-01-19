/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:34:51 by ddragos           #+#    #+#             */
/*   Updated: 2024/12/17 16:34:53 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*last_occurence;

	i = 0;
	last_occurence = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			last_occurence = (char *)&str[i];
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (last_occurence);
}
