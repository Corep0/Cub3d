/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:06 by seruff            #+#    #+#             */
/*   Updated: 2025/08/27 14:22:55 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_cross(void)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit_win(NULL, "Need one file\n", 1);
	data.av_file = av[1];
	init_file(&data);
	init_game(&data);
	mlx_hook(data.win, 17, 0, close_cross, &data);
	mlx_key_hook(data.win, key_event, &data);
	mlx_loop(data.mlx);
	return (0);
}
