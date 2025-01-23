/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ray <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:46:39 by ray               #+#    #+#             */
/*   Updated: 2025/01/23 16:46:40 by ray              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strdup(const char *s, size_t size)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_substr(char const *s, size_t n)
{
	char	*result;
	size_t	i;

	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	*write_line(char *result, char *s1, size_t s1len, const char *s2)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++i < s1len)
		result[i] = s1[i];
	while (++j < BUFFER_SIZE && s2[j] != '\0')
		result[i++] = s2[j];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*update_line(char *s1, char const *s2)
{
	size_t	size;
	char	*result;
	size_t	s1len;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2, BUFFER_SIZE + 1));
	if (!s1 && !s2)
	{
		return (NULL);
	}
	s1len = ft_strlen(s1);
	size = s1len + BUFFER_SIZE + 1;
	result = malloc(size);
	if (!result)
		return (NULL);
	return (write_line(result, s1, s1len, s2));
}
