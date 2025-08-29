/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:37:47 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 09:37:54 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_win(t_data *data, char *mess, int code)
{
	if (code > 0)
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(mess, 2);
	if (code == -1)
		return ;
	if (code == 0)
		exit(1);
	exit(code);
	(void)data;
}
