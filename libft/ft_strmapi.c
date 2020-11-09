/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:21:22 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/30 12:54:38 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*str_mod;
	unsigned int	count;

	if (!s || !f)
		return (NULL);
	count = 0;
	str = (char *)s;
	if (!(str_mod = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[count])
	{
		str_mod[count] = (*f)(count, str[count]);
		count++;
	}
	str_mod[count] = '\0';
	return (str_mod);
}
