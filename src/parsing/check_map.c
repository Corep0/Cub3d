/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:24:15 by seruff            #+#    #+#             */
/*   Updated: 2025/07/31 13:40:09 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_content(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

static int	find_map(t_file *infile, int *start, int *end)
{
	int		i;
	int		len;
	char	*line;

	len = ft_array_len(infile->file);
	*start = -1;
	*end = -1;
	i = infile->line_end_element + 1;
	while (i < len)
	{
		line = infile->file[i];
		if (is_map_content(line))
		{
			if (*start == -1)
				*start = i;
			*end = i;
		}
		else if (*start != -1 && empty_string(line) == 0)
			exit_win(NULL, "Map contains invalid the map", -1);
		i++;
	}
	if (*start == -1 || *end == -1)
		exit_win(NULL, "No map found in file", -1);
	return (0);
}

static int	valid_map(t_file *infile, int start, int end)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	while (infile->file[start][j] && (infile->file[start][j] == ' '
			|| infile->file[start][j] == '\t'))
		j++;
	if (infile->file[start][j] != '1')
		exit_win(NULL, "Map corner doesn't start with a 1", -1);
	len = ft_array_len(infile->file);
	i = end + 1;
	while (i < len)
	{
		if (empty_string(infile->file[i]) == 0)
			exit_win(NULL, "There is empty line inside the map", -1);
		i++;
	}
	if (i <= len && (infile->file[i] && !is_map_content(infile->file[i])))
		exit_win(NULL, "The map isn't the last element of the file", -1);
	return (0);
}

static int	extract_map(t_file *infile, int start, int end)
{
	int	i;
	int	map_len;

	i = 0;
	map_len = end - start + 1;
	infile->map_bloc = malloc(sizeof(char *) * (map_len + 1));
	if (!infile->map_bloc)
		exit_win(NULL, "Malloc failed in extract_map", -1);
	while (i < map_len)
	{
		infile->map_bloc[i] = ft_strdup(infile->file[start + i]);
		if (!infile->map_bloc[i++])
		{
			ft_free_array(infile->map_bloc);
			exit_win(NULL, "Malloc failed", -1);
		}
	}
	infile->map_bloc[map_len] = NULL;
	return (0);
}

int	check_and_extract_map(t_file *infile)
{
	int	start;
	int	end;

	if (find_map(infile, &start, &end) != 0)
		return (-1);
	if (valid_map(infile, start, end) != 0)
		return (-1);
	if (extract_map(infile, start, end) != 0)
		return (-1);
	return (0);
}
