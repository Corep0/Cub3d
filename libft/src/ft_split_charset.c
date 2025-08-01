/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:06:50 by seruff            #+#    #+#             */
/*   Updated: 2025/07/30 09:13:10 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	in_w;

	count = 0;
	in_w = 0;
	while (*str)
	{
		if (is_sep(*str, charset))
			in_w = 0;
		else if (!in_w)
		{
			in_w = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*word_dup(char *start, char *charset)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (start[len] && !is_sep(start[len], charset))
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split_charset(char *str, char *charset)
{
	int		i;
	int		nb;
	char	**res;

	i = 0;
	nb = count_words(str, charset);
	res = malloc(sizeof(char *) * (nb + 1));
	if (!res)
		return (NULL);
	while (*str)
	{
		if (!is_sep(*str, charset))
		{
			res[i] = word_dup(str, charset);
			if (!res[i++])
				return (ft_free_array(res), NULL);
			while (*str && !is_sep(*str, charset))
				str++;
		}
		else
			str++;
	}
	res[i] = NULL;
	return (res);
}
