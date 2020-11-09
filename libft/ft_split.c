/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 15:23:20 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/30 12:47:38 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int i;
	int words_sum;

	i = 0;
	words_sum = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words_sum++;
		i++;
	}
	return (words_sum);
}

static int	word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static void	*free_mem(char **result, int words)
{
	int i;

	i = 0;
	while (i < words)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	**fill_words(char const *s, char c, int words, char **result)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!result[i])
			return (free_mem(result, i));
		j = 0;
		while (j < len)
			result[i][j++] = *s++;
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	int		words_sum;

	if (!s)
		return (NULL);
	words_sum = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words_sum + 1));
	if (!result)
		return (NULL);
	result = fill_words(s, c, words_sum, result);
	return (result);
}
