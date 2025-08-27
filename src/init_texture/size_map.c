/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:08:45 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 11:20:11 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_width(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!map)
		return (0);
	len = ft_strlen(map[i]);
	while (map && map[i])
	{
		if (len < (int)ft_strlen(map[i]))
			len = (int)ft_strlen(map[i]);
		i++;
	}
	return (len);
}

void	stock_map_size(t_data *data, t_file *in)
{
	int	len_max;
	int	height;

	len_max = get_map_width(in->map_bloc);
	height = ft_array_len(in->map_bloc);
	data->content->height = height;
	data->content->width = len_max;
}
