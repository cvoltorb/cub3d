/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:38:16 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:58:12 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_create_color(int red, int green, int blue)
{
	if (red <= 255 && red >= 0 && \
		green <= 255 && green >= 0 && \
		blue <= 255 && blue >= 0)
		return (red << 16 | green << 8 | blue);
	return (-1);
}

int		ft_valid_numbers(char **colors)
{
	int i;
	int k;

	i = 0;
	while (colors[i])
	{
		k = 0;
		while (colors[i][k])
		{
			if (!ft_isdigit(colors[i][k]) || ft_strlen(colors[i]) > 3)
				return (-1);
			k++;
		}
		i++;
	}
	if (i != 3)
		return (-1);
	return (0);
}

int		parse_params(t_params *params, char **parsed_line, unsigned char *flags)
{
	char **colors;

	if (get_amount_line(parsed_line) != 2)
		return (-1);
	colors = ft_split(parsed_line[1], ',');
	if (ft_valid_numbers(colors) == -1)
	{
		ft_free_array(&colors);
		return (-1);
	}
	if (!ft_strcmp(parsed_line[0], "F")
	&& (*flags = *flags | FLG_FLOOR))
	{
		if ((params->flr_color = ft_create_color(ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]))) == -1)
			ft_error(5);
	}
	else if (!ft_strcmp(parsed_line[0], "C")
	&& (*flags = *flags | FLG_CEIL))
		if ((params->ceil_color = ft_create_color(ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]))) == -1)
			ft_error(5);
	ft_free_array(&colors);
	return (0);
}
