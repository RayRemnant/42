#include <stdlib.h> 
#include <stdint.h>
#include "get_next_line.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = (unsigned char)c;
	return (s);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*_src;
	unsigned char		*_dest;

	if (src == NULL && dest == NULL)
		return (NULL);
	_src = (const unsigned char *)src;
	_dest = (unsigned char *)dest;
	if (_src < _dest)
		while (n-- > 0)
			_dest[n] = _src[n];
	else
	{
		i = 0;
		while (i < n)
		{
			_dest[i] = _src[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	size;
	char	*result;

	if(!s2)
		return (s1);
	if(!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(size);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}


char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
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

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (n == 0 || start >= s_len)
		return (ft_strdup(""));
	if (n + start > s_len)
		n = s_len - start;
	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}


