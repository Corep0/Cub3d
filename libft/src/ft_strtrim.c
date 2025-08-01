/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:40:20 by seruff            #+#    #+#             */
/*   Updated: 2024/11/18 14:30:04 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

static	int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

static size_t	is_start(const char *s, char const *set)
{
	size_t	start;

	start = 0;
	while (s[start] && (is_set(s[start], set) == 1))
		start++;
	return (start);
}

static size_t	is_end(const char *s, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen(s);
	while (end > start && is_set(s[end - 1], set) == 1)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char		*d;
	size_t		start;
	size_t		end;
	size_t		i;

	start = is_start(s, set);
	end = is_end(s, set, start);
	i = 0;
	d = malloc(sizeof(char) * (end - start + 1));
	if (!d || !s || !set)
		return (NULL);
	if (end - start == 0)
	{
		d[0] = '\0';
		return (d);
	}
	while (i < end - start)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/*
#include <stdio.h>
int	main()
{
	char const *s = "   i oooJean  Claude   ooo";
	char const *set = " o";
	char *s2 = ft_strtrim(s, set);
	printf("s1 : %s\n", s);
	printf("s2 : %s", s2);
	return (0);
}
*/
