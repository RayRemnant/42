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
			// printf("letter %c", cup_buffer[i]);
			if (cup_buffer[i] == '\n')
			{
				//printf("WHOLE BUFFER: %s %d\n", cup_buffer, i);
				if(i == 0){
					if(!line){
						move_buffer(cup_buffer, &i);
						continue;
					}
						return (line);
				}
				temp = ft_substr(cup_buffer, 0, i);
				//printf("TEMPPP %s\n", temp);
				if (line)
					line = ft_strjoin(line, temp);
				else
					line = ft_strdup(temp);
				//printf("THE LINE: %s\n", line);
				move_buffer(cup_buffer, &i);

				
				return (line);

				//("---START---\n %s\n---END---\n\n", line);
				//printf("---STARTCUT\n %s\n---STARTCUT\n\n", cup_buffer + i);
				//i++;
				
				//printf("---ENDCUT\n %s\n---ENDCUT\n\n", cup_buffer);
				//printf("HEY\n");
			}
			/* while(cup_buffer[i] == '\n')
					i++;
				ft_memmove(cup_buffer, cup_buffer + i, BUFFER_SIZE - i);
				ft_bzero(&cup_buffer[BUFFER_SIZE - i], i); */
			i++;
		}
		//printf("---2START---\n %s\n---2END---\n\n", line);
		if (ft_strlen(cup_buffer))
		{
			if (line)
				line = ft_strjoin(line, cup_buffer);
			else
				line = ft_strdup(cup_buffer);
			ft_bzero(cup_buffer, BUFFER_SIZE);
		}
		//printf("---2START---\n %s\n---2END---\n\n", line);
		//printf("READING...\n");
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		//cup_buffer[bytes_read] = '\0';
		
		//printf("BUFFER: %s\n", cup_buffer);
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