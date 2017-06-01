/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:39:51 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/09 14:55:51 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	minus;
	int	res;

	minus = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == '\n')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = '1';
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (minus == '1')
		res = -res;
	return (res);
}
