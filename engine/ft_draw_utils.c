/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:15:06 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:34 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	paint_ceil(t_vars *vars, int top_pos_of_wall, int num_wall)
{
	int y;

	y = 0;
	while (y < top_pos_of_wall)
	{
		my_mlx_pixel_put(&(vars->img), num_wall, y, vars->ceil_color);
		y++;
	}
}

void	paint_floor(t_vars *vars, int bot_pos_of_wall, int num_wall)
{
	while (bot_pos_of_wall < vars->s_height)
	{
		my_mlx_pixel_put(&(vars->img), num_wall,\
				bot_pos_of_wall, vars->flr_color);
		bot_pos_of_wall++;
	}
}

void	get_hor_texture(t_vars *vars, t_data *current_texture)
{
	if (vars->current_ray > 0 && vars->current_ray < M_PI)
		*current_texture = vars->texture.no_img;
	else if (vars->current_ray > M_PI && vars->current_ray < 2 * M_PI)
		*current_texture = vars->texture.so_img;
}

void	get_vert_texture(t_vars *vars, t_data *current_texture)
{
	if (vars->current_ray > 3 * M_PI / 2 || vars->current_ray < M_PI_2)
		*current_texture = vars->texture.ea_img;
	else if (vars->current_ray > M_PI_2 && vars->current_ray < 3 * M_PI / 2)
		*current_texture = vars->texture.we_img;
}

int		get_cur_color(t_vars *vars, t_data *current_texture, int y_pixel)
{
	int cur_color;

	if (vars->offset_x_hor != -1)
	{
		get_hor_texture(vars, current_texture);
		cur_color = my_mlx_pixel_get_color(current_texture, \
					(int)vars->offset_x_hor % 64, y_pixel);
	}
	else
	{
		get_vert_texture(vars, current_texture);
		cur_color = my_mlx_pixel_get_color(current_texture, \
					(int)vars->offset_y_vert % 64, y_pixel);
	}
	return (cur_color);
}
