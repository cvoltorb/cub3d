/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:52:57 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:48 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_convert(unsigned char *str, unsigned int size)
{
	str[0] = (unsigned char)(size);
	str[1] = (unsigned char)(size >> 8);
	str[2] = (unsigned char)(size >> 16);
	str[3] = (unsigned char)(size >> 24);
}

void	ft_create_bmp_head(t_vars *vars, unsigned int size_bmp, int fd)
{
	unsigned int	i;
	unsigned char	str[54];

	i = 0;
	while (i < 54)
		str[i++] = (unsigned char)(0);
	str[0] = (unsigned char)('B');
	str[1] = (unsigned char)('M');
	ft_convert(str + 2, size_bmp);
	str[10] = (unsigned char)(54);
	str[14] = (unsigned char)(40);
	ft_convert(str + 18, vars->s_width);
	ft_convert(str + 22, vars->s_height);
	str[26] = (unsigned char)(1);
	str[28] = (unsigned char)(24);
	write(fd, str, 54);
}

void	ft_create_bmp_2(t_vars *vars, int fd)
{
	int				i;
	int				j;
	unsigned int	color;

	i = vars->s_height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < vars->s_width)
		{
			color = my_mlx_pixel_get_color(&vars->img, j, i);
			j++;
			write(fd, &color, 3);
		}
		i--;
	}
}

void	create_bmp(t_vars *vars)
{
	unsigned int	size_bmp;
	int				fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_TRUNC | O_WRONLY | O_APPEND,
		0666)) == -1)
		ft_error(1);
	size_bmp = 54 + (vars->s_width * vars->s_height * 4);
	ft_create_bmp_head(vars, size_bmp, fd);
	ft_create_bmp_2(vars, fd);
	close(fd);
	exit(0);
}
