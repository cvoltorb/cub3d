/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:19:49 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:32 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_look_up(double f)
{
	while (f > 2 * M_PI)
		f -= 2 * M_PI;
	while (f < 0)
		f += 2 * M_PI;
	if (f > 0 && f < M_PI)
		return (1);
	if (f == 0 || f == M_PI)
		return (0);
	return (-1);
}

int			ft_look_right(double f)
{
	while (f > 2 * M_PI)
		f -= 2 * M_PI;
	while (f < 0)
		f += 2 * M_PI;
	if (f < M_PI / 2 || f > 3 * M_PI / 2)
		return (1);
	if (f == M_PI / 2 || f == 3 * M_PI / 2)
		return (0);
	return (-1);
}

double		make_angle(double ray)
{
	while (ray > 2 * M_PI)
		ray -= 2 * M_PI;
	while (ray < 0)
		ray += 2 * M_PI;
	return (ray);
}
