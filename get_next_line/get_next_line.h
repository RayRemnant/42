#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
char  *get_next_line(int fd);
int main(void);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
