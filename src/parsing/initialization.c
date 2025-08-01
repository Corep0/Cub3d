/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:57:58 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 11:24:19 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
 * copy_file() -> Check file nature and copied it into struct
 * split_element_map -> Check the order of element and if they exist 
 * 	then copied them into char **elements
 * check_and_extract_map -> Check format/content of the map
*/
void	init_file(t_data *data)
{
	data->content = ft_calloc(1, sizeof(t_content));
	if (!data->content)
		exit_win(data, 1);
	data->infile = ft_calloc(1, sizeof(t_file));
	if (!data->infile)
		exit_win(data, 1);
	if (copy_file(data->infile, data->av_file) != 0)
		exit_win(data, 1);
	if (split_element_map(data->infile) != 0)
		exit_win(data, 1);
	if (check_and_extract_map(data->infile) != 0)
		exit_win(data, 1);
	if (check_element_value(data->infile, data->infile->elements) != 0)
		exit_win(data, 1);
	if (check_content_map(data->infile, data->infile->map_bloc) != 0)
		exit_win(data, 1);
}
