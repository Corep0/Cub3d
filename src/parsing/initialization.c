/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:57:58 by seruff            #+#    #+#             */
/*   Updated: 2025/08/27 15:51:32 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
 * copy_file() -> Check file nature and copied it into struct
 * split_element_map -> Check the order of element and if they exist 
 * 	then copied them into char **elements
 * check_and_extract_map -> Check format/content of the map
*/

static void	swap_space_one(t_content *content, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	content->map = map;
}

static void	initial_direction(t_content *content, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
					|| map[i][j] == 'E' || map[i][j] == 'W')
				content->dir_player = map[i][j];
			j++;
		}
		i++;
	}
}

void	init_file(t_data *data)
{
	data->content = ft_calloc(1, sizeof(t_content));
	if (!data->content)
		exit_win(data, "Calloc failed", 1);
	data->infile = ft_calloc(1, sizeof(t_file));
	if (!data->infile)
		exit_win(data, "Calloc failed", 1);
	if (copy_file(data->infile, data->av_file) != 0)
		exit_win(data, "Copy file failed", 1);
	printf("File copied\n");
	if (split_element_map(data->infile) != 0)
		exit_win(data, "Split element and map failed", 1);
	printf("Split element and map\n");
	if (check_and_extract_map(data->infile) != 0)
		exit_win(data, "Check and extract map failed", 1);
	printf("Extracted map \n");
	if (check_element_value(data->infile, data->infile->elements) != 0)
		exit_win(data, "Element value check failed", 1);
	printf("Element correct\n");
	if (check_content_map(data->infile, data->infile->map_bloc) != 0)
		exit_win(data, "Map content check failed", 1);
	printf("Map content is correct\n");
	swap_space_one(data->content, data->infile->map_bloc);
	initial_direction(data->content, data->infile->map_bloc);
	printf("Map well copied into t_content *\n");
}
