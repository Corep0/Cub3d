/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:13:00 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 10:18:27 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_element_xpm(char *file)
{
	int	i;
	int	fd;

	i = ft_strlen(file);
	if (i < 4 || ft_strcmp(file + i - 4, ".xpm"))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

static int	*add_rgb(char **tab)
{
	int	i;
	int	j;
	int	color;
	int	*rgb;

	i = 0;
	j = 0;
	rgb = malloc(sizeof(int) * 4);
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 3 || ft_strlen(tab[i]) < 1)
			return (free(rgb), NULL);
		color = ft_atoi(tab[i]);
		if (color < 0 || color > 255)
			return (free(rgb), NULL);
		else
			rgb[j++] = color;
		i++;
	}
	rgb[j] = -1;
	return (rgb);
}

static int	check_rgb(t_file *in, char *element, int i)
{
	int		*rgb_tab;
	char	**tab;

	tab = ft_split(element, ',');
	if (!tab)
		return (-1);
	if (ft_array_len(tab) != 3)
		return (ft_free_array(tab), -1);
	rgb_tab = add_rgb(tab);
	ft_free_array(tab);
	if (rgb_tab == NULL)
		return (-1);
	if (i == 4)
		in->floor = rgb_tab;
	else if (i == 5)
		in->ceiling = rgb_tab;
	return (0);
}

int	check_element_value(t_file *in, char **element)
{
	int	i;

	i = 0;
	if (!element)
		return (-1);
	while (element && element[i] && ft_count_carac(element[i], ',') == 0)
	{
		if (check_element_xpm(element[i]) != 0)
			return (exit_win(NULL, "File doesn't end with .xpm", -1), -1);
		i++;
	}
	while (element[i])
	{
		if (check_rgb(in, element[i], i) != 0)
			return (exit_win(NULL, "RGB color isn't valid", -1), -1);
		i++;
	}
	return (0);
}
