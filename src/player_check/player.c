/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:24:50 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 10:54:02 by seruff           ###   ########.fr       */
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
				printf("px %d py %d dir %c\n", x, y, map[y][x]);
				map[y][x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	content->map = map;
	return (0);
}

int	pick(t_data *data, t_file *in)
{
	if (give_dir(data->content, in->map_bloc) == 0)
		exit_win(data, "No player found\n", 1);
	data->player->x_pos = data->content->x_player + 0.5;
	data->player->y_pos = data->content->y_player + 0.5;
	return (0);
}
