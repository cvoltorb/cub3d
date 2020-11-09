/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:45:41 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/29 15:25:03 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ss;
	char	*dd;

	if (dest == NULL && src == NULL)
		return (NULL);
	dd = (char *)dest;
	ss = (char *)src;
	if (dd <= ss)
		while (n--)
			*dd++ = *ss++;
	else
	{
		dd += n;
		ss += n;
		while (n--)
			*--dd = *--ss;
	}
	return (dest);
}
