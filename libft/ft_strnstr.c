/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:54:25 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/06/02 00:43:15 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;
	size_t	max_len;

	s2_len = ft_strlen(s2);
	if (!s2_len)
		return ((char *)s1);
	max_len = ft_strlen(s1);
	if (max_len > len)
		max_len = len;
	i = 0;
	while (s2_len + i <= max_len)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j + 1 == s2_len)
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
