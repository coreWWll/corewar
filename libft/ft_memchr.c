/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:31:00 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/05 15:31:03 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n != 0)
	{
		if (str[i] == cc)
			return (str + i);
		i++;
		n--;
	}
	return (NULL);
}
