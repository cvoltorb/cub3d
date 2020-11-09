/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:03:10 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:40 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win_mlx);
	exit(0);
}

static void	ft_ws_keys(int keycode, t_vars *vars, double change_x,\
						double change_y)
{
	int		cord_y;
	int		cord_x;

	change_x = 10 * cos(vars->pov);
	change_y = 10 * sin(vars->pov);
	cord_y = (int)((vars->py - change_y) / 64);
	cord_x = (int)((vars->px + change_x) / 64);
	if (keycode == W)
		if (vars->map[cord_y][cord_x] != '1' &&
			vars->map[cord_y][(int)(vars->px / 64)] != '1' &&
			vars->map[(int)(vars->py / 64)][cord_x] != '1')
		{
			vars->px += (int)change_x;
			vars->py -= (int)change_y;
		}
	cord_y = (int)((vars->py + change_y) / 64);
	cord_x = (int)((vars->px - change_x) / 64);
	if (keycode == S)
		if (vars->map[cord_y][cord_x] != '1' &&
			vars->map[cord_y][(int)(vars->px / 64)] != '1' &&
				vars->map[(int)(vars->py / 64)][cord_x] != '1')
		{
			vars->px -= (int)change_x;
			vars->py += (int)change_y;
		}
}

static void	ft_ad_keys(int keycode, t_vars *vars, double change_x,\
						double change_y)
{
	int		cord_y;
	int		cord_x;

	change_x = 10 * cos(M_PI_2 - vars->pov);
	change_y = 10 * sin(M_PI_2 - vars->pov);
	cord_y = (int)((vars->py - change_y) / 64);
	cord_x = (int)((vars->px - change_x) / 64);
	if (keycode == A)
		if (vars->map[cord_y][cord_x] != '1' &&
			vars->map[cord_y][(int)(vars->px / 64)] != '1' &&
			vars->map[(int)(vars->py / 64)][cord_x] != '1')
		{
			vars->px -= (int)change_x;
			vars->py -= (int)change_y;
		}
	cord_y = (int)((vars->py + change_y) / 64);
	cord_x = (int)((vars->px + change_x) / 64);
	if (keycode == D)
		if (vars->map[cord_y][cord_x] != '1' &&
			vars->map[cord_y][(int)(vars->px / 64)] != '1' &&
			vars->map[(int)(vars->py / 64)][cord_x] != '1')
		{
			vars->px += (int)change_x;
			vars->py += (int)change_y;
		}
}

static void	ft_left_right(int keycode, t_vars *vars)
{
	if (keycode == LEFT)
	{
		vars->pov += 0.0872665;
		if (vars->pov <= 0)
			vars->pov += 2 * M_PI;
	}
	if (keycode == RIGHT)
	{
		vars->pov -= 0.0872665;
		if (vars->pov >= 2 * M_PI)
			vars->pov -= 2 * M_PI;
	}
}

int			events(int keycode, t_vars *vars)
{
	int i;

	i = -1;
	if (keycode == ESC)
		ft_close(vars);
	if (keycode == W || keycode == S)
		ft_ws_keys(keycode, vars, 0, 0);
	if (keycode == A || keycode == D)
		ft_ad_keys(keycode, vars, 0, 0);
	if (keycode == LEFT || keycode == RIGHT)
		ft_left_right(keycode, vars);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, vars->s_width, vars->s_height);
	vars->img.addr = mlx_get_data_addr(vars->img.img,\
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	cast_ray(vars);
	sort_sprites(vars);
	while (++i < vars->sprites_amount)
		get_sprite(vars, i);
	if (vars->ray_length)
		free(vars->ray_length);
	mlx_put_image_to_window(vars->mlx, vars->win_mlx, vars->img.img, 0, 0);
	return (0);
}
