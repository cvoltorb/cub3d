/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:20:40 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/29 14:42:19 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char *dd;

	if (s1 == NULL && s2 == NULL)
		return (s1);
	dd = s1;
	while (n--)
		*dd++ = *(char *)s2++;
	return (s1);
}
