/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:39:51 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/28 18:33:08 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_into_str(int n, char *s, int *i)
{
	if (n < 0)
	{
		s[*i] = '-';
		(*i)++;
		n = n * -1;
	}
	if (n >= 10)
	{
		putnbr_into_str(n / 10, s, i);
		putnbr_into_str(n % 10, s, i);
	}
	else
		s[(*i)++] = (char)(n + '0');
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	i = 0;
	str = ft_strnew((size_t)len);
	if (!str)
		return (NULL);
	putnbr_into_str(n, str, &i);
	return (str);
}
