/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:13:34 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 10:51:28 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(t_file *in)
{
	if (!in)
		return ;
	if (in->file && *in->file && in->file[0])
		ft_free_array(in->file);
	if (in->floor)
		free(in->floor);
	if (in->ceiling)
		free(in->ceiling);
	if (in->elements && *in->elements && in->elements[0])
		ft_free_array(in->elements);
	if (in->map_bloc && *in->map_bloc && in->map_bloc[0])
		ft_free_array(in->map_bloc);
}
