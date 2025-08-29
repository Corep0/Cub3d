/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:04:15 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 10:55:48 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*static void	add_right_image(t_data *d, t_content *content, int y, int x)
{
	content->dir_player = 'N';
	if (content->map[y][x] == '1' && content->dir_player == 'N')
		mlx_put_image_to_window(d->mlx, d->win, d->texture[3].img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (content->map[y][x] == '1' && content->dir_player == 'S')
		mlx_put_image_to_window(d->mlx, d->win, d->texture[0].img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (content->map[y][x] == '1' && content->dir_player == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->texture[1].img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (content->map[y][x] == '1' && content->dir_player == 'W')
		mlx_put_image_to_window(d->mlx, d->win, d->texture[2].img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (content->map[y][x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->texture[4].img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (content->map[y][x] == 'N')
		mlx_put_image_to_window(d->mlx, d->win, d->texture[2].img,
			x * TILE_SIZE, y * TILE_SIZE);

}*/

static void	fill_window(t_data *data, t_content *content)
{
	int	x;
	int	y;

	y = 0;
	while (y < content->height)
	{
		x = 0;
		while (x < content->width)
		{
			add_right_image(data, content, y, x);
			x++;
		}
		y++;
	}
}

static void	load_images(t_data *data, t_file *in)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = TILE_SIZE;
	height = TILE_SIZE;
	while (i < 4)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx,
				in->elements[i], &width, &height);
		if (!data->texture[i].img)
			exit_win(data, "xpm_file_to_image failed", 4);
		data->texture[i].img_addr = mlx_get_data_addr(
				data->texture[i].img,
				&data->texture[i].bits,
				&data->texture[i].line_length,
				&data->texture[i].endian);
		if (!data->texture[i].img_addr)
			exit_win(data, "get_data_addr failed", 4);
		i++;
	}
}

static void	load_colors(t_data *data, t_file *in)
{
	convert_rgb_to_image(data, in->floor, 4);
	convert_rgb_to_image(data, in->ceiling, 5);
}

void	load_colors_images_in_windows(t_data *data, t_file *in)
{
	load_images(data, in);
	load_colors(data, in);
	//fill_window(data, data->content);
}
