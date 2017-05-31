/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:41:18 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/05 18:41:24 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	end;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
		j++;
	end = i;
	while (src[i - end] && i < size - 1)
	{
		dest[i] = src[i - end];
		i++;
	}
	if (end < size)
		dest[i] = '\0';
	return (end + j);
}
