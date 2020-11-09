/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:04:37 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/05/29 15:37:49 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0 || dst_len >= size)
		return (src_len + size);
	if (src_len + 1 <= size - dst_len - 1)
		ft_strlcpy(&dst[dst_len], src, src_len + 1);
	else
		ft_strlcpy(&dst[dst_len], src, size);
	dst[size - 1] = '\0';
	return (src_len + dst_len);
}
