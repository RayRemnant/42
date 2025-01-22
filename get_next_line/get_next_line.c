#include "get_next_line.h"

void	move_buffer(char *buffer, int *i)
{
	while(buffer[*i] == '\n')
		(*i)++;
	ft_memmove(buffer, buffer + *i, BUFFER_SIZE - *i);
	ft_bzero(&buffer[BUFFER_SIZE - *i], *i);
}

char	*read_from_file(int fd)
{
	int			bytes_read;
	static char	cup_buffer[BUFFER_SIZE];
	int			i;
	char		*line;
	char		*temp;

	line = NULL;
	while (1)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (cup_buffer[i] == '\n')
			{
				if(i == 0){
					if(!line){
						move_buffer(cup_buffer, &i);
						continue;
					}
						return (line);
				}
				temp = ft_substr(cup_buffer, 0, i);
				line = ft_strjoin(line, temp);
				move_buffer(cup_buffer, &i);
				return (line);
			}
			i++;
		}
		if (*cup_buffer)
			line = ft_strjoin(line, cup_buffer);
		ft_bzero(cup_buffer, BUFFER_SIZE);
		

		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);

		if (bytes_read <= 0)
		{
			if (!line)
				return (NULL);
			return (line);
		}
	}
}

/* ------------------------------------------------------------------- */
/* The get_next_line function to get the next line from the fd         */
/* ------------------------------------------------------------------- */
char	*get_next_line(int fd)
{
	char *line;

	line = read_from_file(fd);
	return (line);
}