/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:57:04 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/10 14:16:29 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(int n)
{
	size_t	size;
	int		num;

	num = n;
	size = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	if (num <= 0)
		size++;
	return (size);
}

static char	*transform(char *res, int n, int size)
{
	while (size > 0)
	{
		size--;
		res[size] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		minus;
	size_t	size;
	char	*res;

	minus = 0;
	size = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = int_size(n);
	if (n <= 0)
	{
		minus = 1;
		n = n * -1;
	}
	res = (char *)malloc((size) * sizeof(char));
	if (!res)
		return (NULL);
	res[--size] = '\0';
	res = transform(res, n, size);
	if (minus == 1 && res[1] > '0' && res[1] <= '9')
		res[0] = '-';
	return (res);
}
