/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:34:23 by seruff            #+#    #+#             */
/*   Updated: 2025/07/30 13:11:33 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_string(char *line)
{
	int	i;

	i = 0;
	if (!line || ft_strlen(line) == 0)
		return (-1);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	get_width_map(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line && line[i] != '\n')
		i++;
	return (i);
}

int	max_width_map(char *file)
{
	int		i;
	int		max;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	max = get_width_map(line);
	while (line && line[i])
	{
		if (max < get_width_map(line))
			max = get_width_map(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (max);
}
