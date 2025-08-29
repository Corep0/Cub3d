/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nature_of_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:01:45 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 10:18:00 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4 || ft_strcmp(file + i - 4, ".cub"))
		return (exit_win(NULL, "The file need to be .cub at the end", -1), -1);
	return (0);
}

static char	**copy_file_to_array(char **file, int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		file[count++] = line;
		line = get_next_line(fd);
	}
	return (close(fd), file);
}

static int	size_file(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), i);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	return (close(fd), i);
}

int	copy_file(t_file *infile, char *av_file)
{
	int		fd;
	int		cap;
	char	**copy;

	fd = open(av_file, O_RDONLY);
	if (fd < 0)
		return (exit_win(NULL, "File doesn't exist", -1), -1);
	if (!av_file || check_extension(av_file) != 0)
		return (exit_win(NULL, "Need file.cub", -1), close(fd), -1);
	cap = size_file(av_file);
	if (cap == -1)
		return (close(fd), exit_win(NULL, "Malloc failed", -1), -1);
	copy = malloc(sizeof(char *) * (cap + 1));
	if (!copy)
		return (close(fd), exit_win(NULL, "Malloc failed", -1), -1);
	copy = copy_file_to_array(copy, fd);
	if (!copy)
		return (close(fd), exit_win(NULL, "Copy file to array failed", -1), -1);
	copy[cap] = NULL;
	infile->file = copy;
	return (0);
}
