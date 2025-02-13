/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neo_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:07:10 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:07:11 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

long	ft_atoi_check(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return ((long)INT_MAX + 1);
	while (ft_isdigit(*nptr))
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	if (!*nptr)
		return (result * sign);
	return ((long)INT_MAX + 1);
}

int	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return (0);
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
}
