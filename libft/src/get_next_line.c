/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:45:35 by seruff            #+#    #+#             */
/*   Updated: 2024/12/24 10:52:03 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*concat_and_free(char *left, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(left, buffer);
	free(left);
	return (temp);
}

static char	*ft_read_it(int fd, char *left)
{
	int		bytes;
	char	*buffer;

	if (!left)
		left = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		left = concat_and_free(left, buffer);
		if (ft_strchr_bn(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (left);
}

static char	*ft_trim_leftover(char *left)
{
	int		i;
	int		j;
	char	*new_left;

	i = 0;
	j = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (left[i] == '\0')
	{
		free(left);
		return (NULL);
	}
	new_left = ft_calloc(ft_strlen(left) - i + 1, sizeof(char));
	i++;
	while (left[i])
	{
		new_left[j] = left[i];
		i++;
		j++;
	}
	free(left);
	return (new_left);
}

static char	*ft_fill_and_keep(char *left)
{
	int		i;
	char	*line;

	i = 0;
	if (left[i] == '\0')
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] && left[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	left = ft_read_it(fd, left);
	if (!left)
		return (NULL);
	line = ft_fill_and_keep(left);
	left = ft_trim_leftover(left);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*buffer;

	fd = open("texte.txt", O_RDONLY);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("ligne : %s", buffer);
		free(buffer);
	}
	close(fd);
	return (0);
}
*/
