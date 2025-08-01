/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:24:50 by seruff            #+#    #+#             */
/*   Updated: 2025/07/31 13:31:23 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	give_dir(t_content *content, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NESW", map[y][x]))
			{
				content->x_player = x;
				content->y_player = y;
				content->dir_player = map[y][x];
				map[y][x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	pick(t_data *data, t_file *in)
{
	if (give_dir(data->content, in->map_bloc) == 0)
		return (print_error("There is no player in the map"), -1);
	return (0);
}
