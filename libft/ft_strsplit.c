/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:31:08 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/10 14:35:46 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(const char *s, char c)
{
	int			words;
	size_t		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	if (s[0] != c)
		words++;
	if (s[0] == '\0')
		words = 0;
	return (words);
}

static int	word_start(const char *s, char c, size_t start)
{
	size_t		i;

	i = start;
	while (s[i] == c)
		i++;
	return (i);
}

static int	length(const char *s, size_t start, char c)
{
	size_t		len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

static void	fill_tabs(char **tab, const char *s, char c, int words)
{
	size_t		start;
	int			i;
	size_t		j;

	start = 0;
	i = 0;
	j = 0;
	while (s[start] != '\0')
	{
		start = word_start(s, c, start);
		if (i < words)
		{
			tab[i] = (char *)malloc((length(s, start, c) + 1) * sizeof(char));
			while (s[start] != '\0' && s[start] != c && i < words)
				tab[i][j++] = s[start++];
			tab[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	tab[i] = NULL;
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		words;

	if (s)
	{
		words = count_words(s, c);
		if (words == 0 && words == -1)
			return (NULL);
		if (!(tab = (char **)malloc((words + 1) * sizeof(char *))))
			return (NULL);
		if (tab)
			fill_tabs(&(*tab), s, c, words);
		return (tab);
	}
	return (NULL);
}
