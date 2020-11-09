/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:35:08 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:58:14 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_textures(t_texture *textures, char **parsed_line, \
											unsigned char *flags)
{
	int		fd;

	if (get_amount_line(parsed_line) != 2
	|| (fd = open(parsed_line[1], O_RDONLY)) == -1)
		return (-1);
	if (!(ft_strcmp(parsed_line[0], "NO\0")) && (*flags = *flags | FLG_NORTH))
		textures->no_texture = ft_strdup(parsed_line[1]);
	else if (!(ft_strcmp(parsed_line[0], "SO\0"))
	&& (*flags = *flags | FLG_SOUTH))
		textures->so_texture = ft_strdup(parsed_line[1]);
	else if (!(ft_strcmp(parsed_line[0], "WE\0"))
	&& (*flags = *flags | FLG_WEST))
		textures->we_texture = ft_strdup(parsed_line[1]);
	else if (!(ft_strcmp(parsed_line[0], "EA\0"))
	&& (*flags = *flags | FLG_EAST))
		textures->ea_texture = ft_strdup(parsed_line[1]);
	else if (!(ft_strcmp(parsed_line[0], "S\0"))
	&& (*flags = *flags | FLG_SPR))
		textures->sprite_texture = ft_strdup(parsed_line[1]);
	return (0);
}

int		parse_resolution(t_params *params, char **parsed_line,
unsigned char *flags)
{
	int i;

	*flags = *flags | FLG_RES;
	if (get_amount_line(parsed_line) != 3)
		return (-1);
	i = 0;
	while (parsed_line[1][i])
		if (!ft_isdigit(parsed_line[1][i++]))
			return (-1);
	i = 0;
	while (parsed_line[2][i])
		if (!ft_isdigit(parsed_line[2][i++]))
			return (-1);
	params->resolution[0] = ft_atoi(parsed_line[1]);
	params->resolution[1] = ft_atoi(parsed_line[2]);
	return (0);
}
