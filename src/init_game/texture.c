/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:04:15 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 15:50:19 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_images(t_data *data, t_file *in)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		write(2, "[", 1);
write(2, in->elements[i], strlen(in->elements[i]));
write(2, "]\n", 2);
		write(2, "la\n", 3);
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx,
				in->elements[i], &data->texture[i].width,
				&data->texture[i].height);
		if (!data->texture[i].img)
			exit_win(data, 4);
		data->texture[i].img_addr = mlx_get_data_addr(
				data->texture[i].img,
				&data->texture[i].bits,
				&data->texture[i].line_length,
				&data->texture[i].endian);
		write(2, "la\n", 3);
		if (!data->texture[i].img_addr)
			exit_win(data, 4);
		i++;
	}
		write(2, "la1\n", 4);
	return (0);
}
