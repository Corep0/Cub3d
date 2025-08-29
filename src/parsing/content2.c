/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:53:48 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 09:13:17 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	right_element(t_file *in, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && x < (int)ft_strlen(map[y]))
		{
			if (ft_strchr("0 1NESW\n", map[y][x]) == NULL)
				return (-1);
			if (ft_strchr("NESW", map[y][x]))
				in->nb_player++;
			if (map[y][x] == '\n')
				break ;
			x++;
		}
		y++;
	}
	return (0);
}

static int	flood_case(char **map, char c, int y, int x)
{
	if (c == '0' || ft_strchr("NSEW", c))
	{
		if (ft_strchr(" \t", map[y - 1][x]) || ft_strchr(" \t", map[y + 1][x])
				|| ft_strchr(" \t", map[y][x - 1])
				|| ft_strchr(" \t", map[y][x + 1])
				|| !map[y - 1] || !map[y + 1]
				|| x >= (int)ft_strlen(map[y - 1])
				|| x >= (int)ft_strlen(map[y + 1]))
			return (exit_win(NULL, "Map isn't closed", -1), 1);
	}
	return (0);
}

static int	wrong_content_in_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (flood_case(map, map[y][x], y, x) != 0)
				return (exit_win(NULL, "Map isn't closed", -1), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_content_map(t_file *in, char **map)
{
	if (!map)
		exit_win(NULL, "Map doesn't exist", -1);
	in->nb_player = 0;
	if (right_element(in, map) != 0)
		exit_win(NULL, "Map got other content than 01NESW' '", -1);
	if (in->nb_player > 1)
		exit_win(NULL, "Too many player in the map", -1);
	if (wrong_content_in_map(map) != 0)
		exit_win(NULL, "Wrong carac inside the map", -1);
	return (0);
}
