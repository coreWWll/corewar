/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:56:07 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/09 15:01:07 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	c = 0;
	if (to_find[0] == '\0')
		return ((char*)(str));
	while (str[i] != '\0' && i < len)
	{
		j = i;
		while (str[j] == to_find[c] && j < len)
		{
			j++;
			c++;
			if (to_find[c] == '\0')
				return ((char*)(&str[i]));
		}
		i++;
		c = 0;
	}
	return (NULL);
}
