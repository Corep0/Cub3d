/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:37:47 by seruff            #+#    #+#             */
/*   Updated: 2025/07/31 13:31:37 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_win(t_data *data, int code)
{
	free(data->content);
	if (code == 0)
		exit(1);
	else if (code == 1)
	{
		free_file(data->infile);
		free(data->infile);
	}
	else if (code == 2)
	{
		free_file(data->infile);
		free(data->infile);
	}
	exit(code);
}

void	print_error(char *mess)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(mess, 2);
	write(2, "\n", 1);
}
