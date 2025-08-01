/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_element_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:18:21 by seruff            #+#    #+#             */
/*   Updated: 2025/07/30 12:40:12 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_is_map(char *line)
{
	int	i;

	i = 0;
	if (!line || empty_string(line))
		return (0);
	while (line && line[i])
	{
		if (empty_string(line) == 1 && (line[0] == ' '
				|| line[0] == '1' || line[0] == '0'))
			return (1);
		else
			i++;
	}
	return (0);
}
