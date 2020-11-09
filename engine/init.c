/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:48:39 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:41 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	init_vars(t_vars *vars, t_params *params)
{
	int max_width;
	int max_height;

	vars->mlx = mlx_init();
	mlx_get_screen_size(vars->mlx, &max_width, &max_height);
	vars->s_width = params->resolution[0] >= max_width \
	? max_width : params->resolution[0];
	vars->s_height = params->resolution[1] >= max_height \
	? max_height : params->resolution[1];
	vars->len_x = params->len_x;
	vars->len_y = params->len_y;
	vars->ceil_color = params->ceil_color;
	vars->flr_color = params->flr_color;
	vars->map = params->map;
	vars->offset_y_vert = -1;
	vars->offset_x_hor = -1;
	vars->win_mlx = mlx_new_window(vars->mlx, vars->s_width, \
		vars->s_height, "Cub3D");
	vars->img.img = mlx_new_image(vars->mlx, vars->s_width, vars->s_height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

static	void	init_mlx_texture(t_vars *vars, t_texture *textures)
{
	vars->texture.no_img.img = mlx_xpm_file_to_image(vars->mlx, textures->\
	no_texture, &vars->texture.no_img.img_width, \
	&vars->texture.no_img.img_height);
	vars->texture.so_img.img = mlx_xpm_file_to_image(vars->mlx, \
	textures->so_texture, &vars->texture.so_img.img_width, \
	&vars->texture.so_img.img_height);
	vars->texture.we_img.img = mlx_xpm_file_to_image(vars->mlx, \
	textures->we_texture, &vars->texture.we_img.img_width, \
	&vars->texture.we_img.img_height);
	vars->texture.ea_img.img = mlx_xpm_file_to_image(vars->mlx, \
	textures->ea_texture, &vars->texture.ea_img.img_width,\
	&vars->texture.ea_img.img_height);
	check_texture_correct(vars);
	vars->texture.no_img.addr = mlx_get_data_addr(vars->texture.no_img.img,\
	&vars->texture.no_img.bits_per_pixel, \
	&vars->texture.no_img.line_length, &vars->texture.no_img.endian);
	vars->texture.so_img.addr = mlx_get_data_addr(vars->texture.so_img.img,\
	&vars->texture.so_img.bits_per_pixel, \
	&vars->texture.so_img.line_length, &vars->texture.so_img.endian);
	vars->texture.we_img.addr = mlx_get_data_addr(vars->texture.we_img.img,\
	&vars->texture.we_img.bits_per_pixel, \
	&vars->texture.we_img.line_length, &vars->texture.we_img.endian);
	vars->texture.ea_img.addr = mlx_get_data_addr(vars->texture.ea_img.img, \
	&vars->texture.ea_img.bits_per_pixel, \
	&vars->texture.ea_img.line_length, &vars->texture.ea_img.endian);
}

void			init_sprites(t_vars *vars, t_texture *textures)
{
	int i;

	i = 0;
	if (!(vars->sprites = malloc(sizeof(t_sprite) * vars->sprites_amount)))
		ft_error(4);
	while (i < vars->sprites_amount)
	{
		if (!(vars->sprites[i].img_sprite.img = mlx_xpm_file_to_image(vars->mlx,
			textures->sprite_texture, &vars->sprites[i].img_sprite.img_width,
				&vars->sprites[i].img_sprite.img_height)))
			ft_error(7);
		vars->sprites[i].img_sprite.addr = \
			mlx_get_data_addr(vars->sprites[i].img_sprite.img, \
			&vars->sprites[i].img_sprite.bits_per_pixel, \
			&vars->sprites[i].img_sprite.line_length, \
			&vars->sprites[i].img_sprite.endian);
		i++;
	}
}

void			sort_sprites(t_vars *vars)
{
	int		i;
	int		j;
	double	key_dist;
	double	key_x;
	double	key_y;

	i = 0;
	if (vars->sprites_amount > 2)
		while (i++ < vars->sprites_amount)
		{
			key_dist = vars->sprites[i].sprite_dist;
			key_x = vars->sprites[i].sprite_x;
			key_y = vars->sprites[i].sprite_y;
			j = i - 1;
			while (j >= 0 && vars->sprites[j].sprite_dist < key_dist)
			{
				vars->sprites[j + 1].sprite_x = vars->sprites[j].sprite_x;
				vars->sprites[j + 1].sprite_y = vars->sprites[j].sprite_y;
				vars->sprites[j + 1].sprite_dist = vars->sprites[j].sprite_dist;
				j--;
			}
			vars->sprites[j + 1].sprite_dist = key_dist;
			vars->sprites[j + 1].sprite_x = key_x;
			vars->sprites[j + 1].sprite_y = key_y;
		}
}

int				start(t_params *params, t_texture *textures, int screen)
{
	t_vars		vars;
	int			i;

	init_vars(&vars, params);
	init_mlx_texture(&vars, textures);
	get_coordinates(&vars);
	ft_count_sprites(&vars);
	init_sprites(&vars, textures);
	free_textures(textures);
	get_sprite_coord(&vars);
	cast_ray(&vars);
	sort_sprites(&vars);
	i = -1;
	while (++i < vars.sprites_amount)
		get_sprite(&vars, i);
	if (vars.ray_length)
		free(vars.ray_length);
	mlx_put_image_to_window(vars.mlx, vars.win_mlx, vars.img.img, 0, 0);
	if (screen == 1)
		create_bmp(&vars);
	mlx_hook(vars.win_mlx, 17, 0, ft_close, &vars);
	mlx_hook(vars.win_mlx, 2, 0L, events, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
