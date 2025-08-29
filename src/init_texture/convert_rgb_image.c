/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:47:47 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 10:16:23 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	fill_the_image(char *img_addr)
{
	int	x;
	int	y;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			*(unsigned int *)(img_addr + (y * 64 + x)
					* 4) = create_trgb(0, 255, 255, 255);
			x++;
		}
		y++;
	}
}

void	convert_rgb_to_image(t_data *data, int *rgb, int i)
{
	data->texture[i].img = mlx_new_image(data->mlx, 64, 64);
	if (!data->texture[i].img)
		exit_win(data, "Error\nFailed to create image", 1);
	data->texture[i].img_addr = mlx_get_data_addr(data->texture[i].img,
			&data->texture[i].bits,
			&data->texture[i].line_length,
			&data->texture[i].endian);
	if (!data->texture[i].img_addr)
		exit_win(data, "Error\nFailed to get image address", 1);
	*(unsigned int *)data->texture[i].img_addr = create_trgb(0, rgb[0], rgb[1],
			rgb[2]);
	fill_the_image(data->texture[i].img_addr);
	data->texture[i].width = 64;
	data->texture[i].height = 64;
}
