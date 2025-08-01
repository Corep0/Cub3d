/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:02:49 by seruff            #+#    #+#             */
/*   Updated: 2025/04/07 11:03:02 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str, to_find, ft_strlen(to_find) == 0))
			return (str);
		str++;
	}
	return (NULL);
}
