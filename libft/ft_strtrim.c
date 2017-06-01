/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:39:37 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/10 14:25:37 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	from_end(const char *s, size_t len)
{
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			if (s[i + 1] == '\0')
				return (ft_strdup(""));
			i++;
		}
		len = from_end(s, len);
		if (!(res = (char *)malloc((len - i + 1) * sizeof(char))))
			return (NULL);
		while (s[i] != '\0' && i < len)
			res[j++] = s[i++];
		res[j] = '\0';
		return (res);
	}
	return (NULL);
}
