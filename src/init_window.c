/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:07:23 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 15:39:48 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_data *data)
{
	int	height;
	int	width;

	height = data->content->height * TILE_SIZE;
	width = data->content->width * TILE_SIZE;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_win(data, 4);
	data->win = mlx_new_window(data->mlx, width, height, "CUB3D");
	if (!data->win)
		exit_win(data, 4);
	data->img.img = mlx_new_image(data->mlx, width,	height);
	if (!data->img.img)
		exit_win(data, 4);
	data->img.img_addr = mlx_get_data_addr(data->img.img, &data->img.bits,
		&data->img.line_length, &data->img.endian);	
	if (!data->img.img_addr)
		exit_win(data, 4);
}
