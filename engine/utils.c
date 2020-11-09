/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:55:04 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:49 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_texture_correct(t_vars *vars)
{
	if (!(vars->texture.no_img.img) || !(vars->texture.so_img.img) || !(vars->\
		texture.we_img.img) || !(vars->texture.ea_img.img))
		ft_error(7);
}

void		free_textures(t_texture *textures)
{
	if (textures != NULL)
	{
		if (textures->ea_texture)
			free(textures->ea_texture);
		if (textures->no_texture)
			free(textures->no_texture);
		if (textures->so_texture)
			free(textures->so_texture);
		if (textures->we_texture)
			free(textures->we_texture);
		if (textures->sprite_texture)
			free(textures->sprite_texture);
		free(textures);
	}
}
