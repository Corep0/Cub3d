/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:57:55 by seruff            #+#    #+#             */
/*   Updated: 2025/07/18 14:01:32 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**file_to_array(int fd)
{
	int		i;
	char	*line;
	char	**file;

	i = 0;
	line = get_next_line(fd);
	if (!line || fd < 0)
		return (NULL);
	while (line)
	{
		if (!file)
		{
			file = malloc(sizeof(char *) * (ft_strlen(line) - 1));
			if (!file)
				return (free(line), NULL);
		}
		file[i++] = line;
	}
	file[i] = NULL;
	close(fd);
	return (file);
}
