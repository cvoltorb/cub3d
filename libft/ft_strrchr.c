/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:16:24 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/27 00:59:09 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = NULL;
	while (*s)
	{
		if (*s == c)
			str = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (str);
}
