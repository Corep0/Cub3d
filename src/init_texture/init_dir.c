/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:20:13 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 09:41:12 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_view_plane_side(t_player *player, char dir)
{
	if (dir == 'W')
	{
		player->x_dir = -1;
		player->y_dir = 0;
		player->x_plane = 0;
		player->y_plane = 0.66;
	}
	else if (dir == 'E')
	{
		player->x_dir = 1;
		player->y_dir = 0;
		player->x_plane = 0;
		player->y_plane = -0.66;
	}
}

static void	fill_view_plane(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->x_dir = 0;
		player->y_dir = -1;
		player->x_plane = 0.66;
		player->y_plane = 0;
	}
	else if (dir == 'S')
	{
		player->x_dir = 0;
		player->y_dir = 1;
		player->x_plane = -0.66;
		player->y_plane = 0;
	}
	else if (dir == 'W' || dir == 'E')
		fill_view_plane_side(player, dir);
}

static void	fill_player_data(t_player *player, t_content *content)
{
	player->x_player = content->x_player;
	player->y_player = content->y_player;
	fill_view_plane(player, content->dir_player);
}

void	init_game(t_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		exit_win(data, "Calloc failed", 3);
	fill_player_data(data->player, data->content);
	pick(data, data->infile);
	stock_map_size(data, data->infile);
	init_window(data);
	init_ray(data);
	raycaster(data, data->visu, data->visu->cam);
	load_colors_images_in_struct(data, data->infile);
}
