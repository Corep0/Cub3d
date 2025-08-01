/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:41 by seruff            #+#    #+#             */
/*   Updated: 2025/07/30 12:36:08 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_element(char *line)
{
	if (!ft_strcmp(line, "NO") || !ft_strcmp(line, "SO")
		|| !ft_strcmp(line, "EA") || !ft_strcmp(line, "WE")
		|| !ft_strcmp(line, "C") || !ft_strcmp(line, "F"))
		return (0);
	return (-1);
}
