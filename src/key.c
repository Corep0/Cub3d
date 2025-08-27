/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:04:41 by seruff            #+#    #+#             */
/*   Updated: 2025/08/27 11:11:16 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(t_data *data, int new_x, int new_y)
{
	(void)data;
	(void)new_x;
	(void)new_y;
}

int	key_event(int key, t_data *data)
{
	if (key == KEY_UP)
		move(data, 0, -1);
	if (key == KEY_DOWN)
		move(data, 0, 1);
	if (key == KEY_RIGHT)
		move(data, 1, 0);
	if (key == KEY_LEFT)
		move(data, -1, 0);
	if (key == KEY_ESC)
		exit_win(data, 0);
	return (0);
}
