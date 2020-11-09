/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:37:04 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/29 15:31:43 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	*dd;
	unsigned char	cc;

	ss = (unsigned char *)src;
	dd = (unsigned char *)dst;
	cc = (unsigned char)c;
	while (n--)
	{
		if (*ss == cc)
		{
			*dd++ = *ss++;
			return (dd++);
		}
		*dd++ = *ss++;
	}
	return (NULL);
}
