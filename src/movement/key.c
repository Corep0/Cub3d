/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:04:41 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 11:53:06 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(t_data *data, t_player *player, int new_x, int new_y)
{
	int	x_count;
	int	y_count;

	x_count = player->x_pos + new_x;	
	y_count = player->y_pos + new_y;
	printf("pos x %d y %d\n", player->x_pos, player->y_pos);
	if (x_count <= 0 || y_count <= 0)
	{
		printf("Cannot move there\n");
		return ;
	}
	if (data->content->map[y_count][x_count] == '1'
		|| data->content->map[y_count][x_count] == ' ')
	{
		printf("Cannot move there\n");
		return ;
	}
	if (data->active == 1)
	{
		player->x_pos = x_count;
		player->y_pos = y_count;
		printf("New pos x %d y %d\n", player->x_pos, player->y_pos);
	}
	else
		return ;
	//render(data);
}

int	key_event(int key, t_data *data)
{
	data->active = 1;
	if (key == KEY_UP)
		move(data, data->player, 0, -1);
	if (key == KEY_DOWN)
		move(data, data->player, 0, 1);
	if (key == KEY_RIGHT)
		move(data, data->player, 1, 0);
	if (key == KEY_LEFT)
		move(data, data->player, -1, 0);
	if (key == KEY_ESC)
		exit_win(data, "Program closed", 0);
	return (0);
}
