/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:47:33 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:58:18 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_array(char ***ar)
{
	char	**array;
	int		i;

	array = *ar;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int		get_amount_line(char **lines)
{
	int i;

	i = 0;
	if (!lines || !(*lines))
		return (0);
	while (lines[i])
		i++;
	return (i);
}

int		ft_pos(char **map)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("SWNE", map[i][j]) != NULL)
				pos++;
			j++;
		}
		i++;
	}
	return (pos == 1 ? 1 : 0);
}
