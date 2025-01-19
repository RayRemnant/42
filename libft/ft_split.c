/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:20:37 by ddragos           #+#    #+#             */
/*   Updated: 2025/01/11 01:20:38 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		**make_words(char **words, char const *s, char c);
static void		*free_words(char **strs);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	words_count;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!words)
		return (NULL);
	words[words_count] = NULL;
	return (make_words(words, s, c));
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	**make_words(char **words, char const *s, char c)
{
	size_t	n;
	size_t	word_len;

	n = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			words[n] = ft_substr(s, 0, word_len);
			if (!words[n])
				return (free_words(words));
			n++;
			s += word_len;
		}
	}
	return (words);
}

static void	*free_words(char **words)
{
	char	**temp;

	temp = words;
	if (!words)
		return (NULL);
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(words);
	return (NULL);
}
