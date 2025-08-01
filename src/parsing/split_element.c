/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:59:33 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 10:46:56 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	which_element(char *s)
{
	if (!ft_strcmp(s, "NO"))
		return (1);
	if (!ft_strcmp(s, "SO"))
		return (2);
	if (!ft_strcmp(s, "WE"))
		return (3);
	if (!ft_strcmp(s, "EA"))
		return (4);
	if (!ft_strcmp(s, "F"))
		return (5);
	if (!ft_strcmp(s, "C"))
		return (6);
	return (-1);
}

static int	copy_element(t_file *infile, char **ele, char *line, int *index)
{
	char	**tab;

	infile->nb_element++;
	tab = ft_split_charset(line, " \t\n");
	if (!tab)
		return (-1);
	if (ft_array_len(tab) != 2)
		return (ft_free_array(tab), -1);
	if (is_element(tab[0]) == 0)
	{
		if (infile->nb_element != which_element(tab[0]))
			return (ft_free_array(tab), -1);
		ele[*index] = ft_strdup(tab[1]);
		ft_free_array(tab);
		if (!ele[*index])
			return (print_error("Malloc"), -1);
		(*index)++;
		return (0);
	}
	return (ft_free_array(tab), -1);
}

static int	process_element_line(t_file *in, char **ele, int *index, int i)
{
	if (line_is_map(in->file[i]) == 1)
	{
		in->line_end_element = i;
		return (0);
	}
	if (empty_string(in->file[i]) == 0)
		return (1);
	if (copy_element(in, ele, in->file[i], index) != 0)
		return (print_error("Wrong orders of elements"), -1);
	if (in->nb_element == 6)
	{
		ele[*index] = NULL;
		in->elements = ele;
		in->line_end_element = i;
		return (0);
	}
	return (1);
}

int	split_element_map(t_file *infile)
{
	int		i;
	int		index;
	char	**element;

	i = 0;
	index = 0;
	element = malloc(sizeof(char *) * 7);
	if (!element)
		return (-1);
	infile->nb_element = 0;
	while (infile->file && infile->file[i])
	{
		if (process_element_line(infile, element, &index, i) == 0)
			return (0);
		i++;
	}
	return (-1);
}
