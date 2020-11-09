/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:00:06 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/08 19:21:55 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		is_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

size_t	line_len(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

size_t	buff_len(char *str)
{
	size_t b_len;

	if (!str)
		return (0);
	b_len = 0;
	while (str[b_len] != '\0')
		b_len++;
	return (b_len);
}
