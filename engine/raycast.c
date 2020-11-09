/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:56:33 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:47 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_sprite(t_vars *vars, double sprite_size, int h_offset,
					double sprite_dist)
{
	int i;
	int j;
	int cur_color;
	int v_offset;

	v_offset = vars->s_height / 2 - sprite_size / 2;
	i = -1;
	cur_color = 0;
	while (++i < sprite_size)
		if (h_offset + i >= 0 && h_offset + i < vars->s_width \
			&& sprite_dist < vars->ray_length[h_offset + i])
		{
			j = -1;
			while (++j < sprite_size)
				if (v_offset + j >= 0 && v_offset + j < vars->s_height)
				{
					cur_color =
						my_mlx_pixel_get_color(&vars->sprites->img_sprite,\
						i * 64 / sprite_size, j * 64 / sprite_size);
					if (cur_color != -16777216 && cur_color != 0)
						my_mlx_pixel_put(&(vars->img), h_offset + i,\
						v_offset + j, cur_color);
				}
		}
}

void	get_sprite(t_vars *vars, int num_sprite)
{
	double	sprite_dir;
	double	sprite_dist;
	double	sprite_size;
	int		h_offset;

	sprite_dir = atan2(-vars->sprites[num_sprite].sprite_y + vars->py, \
						vars->sprites[num_sprite].sprite_x - vars->px);
	while (sprite_dir - vars->pov > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - vars->pov < -M_PI)
		sprite_dir += 2 * M_PI;
	sprite_dist = sqrt(pow(vars->px - vars->sprites[num_sprite].sprite_x, 2) \
					+ pow(vars->py - vars->sprites[num_sprite].sprite_y, 2));
	vars->sprites[num_sprite].sprite_dist = sprite_dist;
	sprite_size = 64 / sprite_dist * (vars->s_width / 2 / tan(M_PI / 6));
	h_offset = (vars->pov - sprite_dir) * vars->s_width / (FOV) \
				+ (vars->s_width / 2 - sprite_size / 2);
	print_sprite(vars, sprite_size, h_offset, sprite_dist);
}

void	print_walls(t_vars *vars, int top_position_of_wall, int num_wall,\
					int wall_height)
{
	t_data	current_texture;
	int		cur_color;
	int		y_pixel;
	double	coef;
	int		begining_of_wall;

	begining_of_wall = top_position_of_wall;
	coef = 64.0 / (wall_height);
	if (top_position_of_wall == 0)
	{
		begining_of_wall = (vars->s_height - wall_height) / 2;
		wall_height = vars->s_height;
	}
	paint_ceil(vars, top_position_of_wall, num_wall);
	paint_floor(vars, top_position_of_wall + wall_height, num_wall);
	while (wall_height > 0)
	{
		y_pixel = (top_position_of_wall - begining_of_wall) * coef;
		cur_color = get_cur_color(vars, &current_texture, y_pixel);
		my_mlx_pixel_put(&(vars->img), num_wall, \
							top_position_of_wall, cur_color);
		top_position_of_wall++;
		wall_height--;
	}
}

int		create_walls(t_vars *vars, double current_len, int num_wall)
{
	int	dist_from_player;
	int	wall_height;
	int	top_position_of_wall;

	dist_from_player = vars->s_width / 2 / tan(M_PI / 6);
	wall_height = 64 / current_len * dist_from_player;
	wall_height = (wall_height % 2 == 0) ? wall_height : wall_height + 1;
	top_position_of_wall = ((vars->s_height - wall_height) / 2) < 0 ? \
							0 : (vars->s_height - wall_height) / 2;
	print_walls(vars, top_position_of_wall, num_wall,\
				wall_height);
	return (0);
}

int		cast_ray(t_vars *vars)
{
	double		start;
	double		vert_len;
	double		horiz_len;
	double		current_len;
	int			num_wall;

	if (!(vars->ray_length = (double*)malloc(sizeof(double) * vars->s_width)))
		ft_error(4);
	num_wall = 0;
	start = vars->pov + M_PI / 6;
	while (start > vars->pov - M_PI / 6 && num_wall < vars->s_width)
	{
		current_len = get_len_ray(vars, start);
		vars->current_ray = make_angle(start);
		vars->ray_length[num_wall] = current_len;
		create_walls(vars, cos(vars->pov - start) * current_len, num_wall);
		start -= ((M_PI / 3) / vars->s_width);
		num_wall++;
	}
	return (0);
}
