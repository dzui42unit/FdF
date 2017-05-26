/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:42:19 by dzui              #+#    #+#             */
/*   Updated: 2016/11/28 17:59:25 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		obst_or_empty(const char *s, char ch)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] != ch)
			return (0);
		i++;
	}
	return (1);
}

static	int		count_words(const char *s, char ch)
{
	int		words;
	size_t	i;

	words = 0;
	i = 0;
	if (obst_or_empty(s, ch))
		return (1);
	if (s[i] != ch)
		words++;
	while (i < ft_strlen(s) - 1)
	{
		if (s[i] == ch)
		{
			if (s[i + 1] != ch)
				words++;
		}
		i++;
	}
	return (words);
}

static	int		read_obst(const char *s, int i, char ch)
{
	while ((s[i] == ch) && (s[i] != '\0'))
		i++;
	return (i);
}

static	int		next_word(const char *s, int i, char ch)
{
	int	j;

	j = 0;
	while ((s[i + j] != ch) && (s[i + j] != '\0'))
		j++;
	return (j);
}

char			**ft_strsplit(const char *s, char ch)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	k = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (count_words(s, ch) + 1))))
		return (NULL);
	if (obst_or_empty(s, ch))
		res[k++] = NULL;
	i = 0;
	while (k < count_words(s, ch))
	{
		j = 0;
		i = read_obst(s, i, ch);
		if (!(res[k] = ft_strnew(next_word(s, i, ch))))
			return (NULL);
		while (next_word(s, i, ch))
			res[k][j++] = s[i++];
		k++;
	}
	res[k] = NULL;
	return (res);
}
