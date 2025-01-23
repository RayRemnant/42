/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ray <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:33:24 by ray               #+#    #+#             */
/*   Updated: 2025/01/23 16:33:25 by ray              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	move_buffer(char *buffer, int i)
{
	int	j;

	j = 0;
	while (j < BUFFER_SIZE - i)
	{
		buffer[j] = buffer[j + i];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = '\0';
		j++;
	}
}

int	cycle(char **line, char *cup_buffer, int i)
{
	char	*temp;

	while (i < BUFFER_SIZE)
	{
		if (cup_buffer[i] == '\n')
		{
			i++;
			temp = ft_substr(cup_buffer, i);
			*line = update_line(*line, temp);
			free(temp);
			move_buffer(cup_buffer, i);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	cup_buffer[BUFFER_SIZE];
	int			i;
	char		*line;

	line = NULL;
	while (1)
	{
		i = 0;
		if (cycle(&line, cup_buffer, i))
			return (line);
		if (*cup_buffer)
		{
			line = update_line(line, cup_buffer);
			i = 0;
			while (i < BUFFER_SIZE)
			{
				cup_buffer[i] = '\0';
				i++;
			}
		}
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (line);
	}
}
