/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:29:47 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 22:11:36 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_texture	*ft_init(void)
{
	t_texture	*textures;

	if (!(textures = malloc(sizeof(t_texture))))
		return (NULL);
	textures->no_texture = NULL;
	textures->so_texture = NULL;
	textures->we_texture = NULL;
	textures->ea_texture = NULL;
	textures->sprite_texture = NULL;
	return (textures);
}

t_params	*ft_init_param(void)
{
	t_params *params;

	if (!(params = malloc(sizeof(t_params))))
		return (NULL);
	params->len_x = 0;
	params->len_y = 0;
	params->resolution[0] = 0;
	params->resolution[1] = 0;
	params->flr_color = 0;
	params->ceil_color = 0;
	return (params);
}

int			ft_check_dotcub(char *path)
{
	int len;

	len = ft_strlen(path) - 1;
	if (len > 3)
		if (path[len - 3] == '.' && path[len - 2] == 'c' && \
			path[len - 1] == 'u' && path[len] == 'b')
			return (0);
	return (1);
}

void		ft_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Error: Bad file!\n", 1);
	if (flag == 2)
		ft_putstr_fd("Error: Wrong amount of arguments!\n", 1);
	if (flag == 3)
		ft_putstr_fd("Error: Bad second argument!\n", 1);
	if (flag == 4)
		ft_putstr_fd("Error: Bad memory allocation!\n", 1);
	if (flag == 5)
		ft_putstr_fd("Error: Uncorrect strings in file!\n", 1);
	if (flag == 6)
		ft_putstr_fd("Error: Bad map format!\n", 1);
	if (flag == 7)
		ft_putstr_fd("Error: Bad textures!\n", 1);
	exit(0);
}

int			main(int argc, char **argv)
{
	int			screen;
	int			fd;
	t_texture	*textures;
	t_params	*params;

	if (argc == 1 || ft_check_dotcub(argv[1])
	|| ((fd = open(argv[1], O_RDONLY)) < 0))
		ft_error(1);
	if (argc > 3 || (argc == 3 && ft_strcmp(argv[2], "--save") != 0))
		argc > 3 ? ft_error(2) : ft_error(3);
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		screen = 1;
	if (!(params = ft_init_param()))
		ft_error(4);
	if (!(textures = ft_init()))
		ft_error(4);
	if (parser(params, textures, fd))
		ft_error(5);
	if (!(params->map = get_map(fd, params)))
		ft_error(6);
	close(fd);
	start(params, textures, screen);
}
