/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:21:48 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/05 17:23:08 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*res;
	size_t		i;

	i = 0;
	if (s && f)
	{
		res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!res)
			return (NULL);
		while (s[i] != '\0')
		{
			res[i] = (*f)(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
