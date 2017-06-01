/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:30:41 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/09 17:46:23 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = len - 1;
	if (len > 0)
	{
		if (src > dest)
			ft_memcpy(dest, src, len);
		else
		{
			while (i > 0)
			{
				d[i] = s[i];
				i--;
			}
			d[i] = s[i];
		}
	}
	return ((void *)dest);
}
