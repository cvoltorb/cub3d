/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:38:29 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/06/01 18:26:22 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size1;
	size_t	size2;
	size_t	size_sum;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	size_sum = size1 + size2;
	str = (char *)malloc((size_sum + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (size1--)
		*str++ = *s1++;
	while (size2--)
		*str++ = *s2++;
	*str = '\0';
	str -= size_sum;
	return (str);
}
