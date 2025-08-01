/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:06 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 11:09:04 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_file(t_data *data)
{
	for (int i = 0; data->infile->file[i]; i++)
		printf("file[%d]: %s\n", i, data->infile->file[i]);
	for (int i = 0; data->infile->elements[i]; i++)
		printf("elements[%d] %s\n", i, data->infile->elements[i]);
	for (int i = 0; data->infile->map_bloc[i]; i++)
		printf("map[%d] %s\n", i, data->infile->map_bloc[i]);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (print_error("Need one file\n"), 1);
	data.av_file = av[1];
	init_file(&data);
	print_file(&data);
	init_game(&data);
	exit_win(&data, 2);
	return (0);
}
