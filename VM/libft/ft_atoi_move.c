/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:35:37 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/26 18:37:30 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_h(char **buf, int s)
{
	unsigned long long nb;

	nb = 0;
	while (**buf != '\0' && (**buf >= '0' && **buf <= '9'))
	{
		nb = nb * 10 + (**buf - '0');
		(*buf)++;
		if (nb > 9223372036854775807 && s == -1)
			return (0);
		if (nb > 9223372036854775807)
			return (-1);
	}
	nb = nb * s;
	return ((int)nb);
}

int			cheak_nbr(char *temp, int nbr, int size)
{
	char	*buf;
	int		res;
	int		i;

	i = 0;
	res = 1;
	buf = ft_itoa(nbr);
	while ((*temp == ' ' || *temp == '\t' || *temp == '\v' || *temp == '\r' ||
				*temp == '\f' || *temp == '\n') && *temp != 0)
	{
		temp++;
		i++;
	}
	if (ft_strncmp(temp, buf, (size_t)(size - i)) == 0 && size > 0)
		res = 0;
	ft_strdel(&buf);
	return (res);
}

int			ft_atoi_move(char **buf, int *error, int move)
{
	int		s;
	char	*temp;

	temp = *buf;
	s = 1;
	while (**buf == ' ' || **buf == '\t' || **buf == '\v' || **buf == '\r' ||
			**buf == '\f' || **buf == '\n')
	{
		(*buf)++;
		if (**buf == '\0')
			return (0);
	}
	if (**buf == '-')
	{
		s = -1;
		(*buf)++;
	}
	else if (**buf == '+')
		buf++;
	s = ft_h(buf, s);
	*error = cheak_nbr(temp, s, (int)(*buf - temp));
	*buf = move ? *buf : temp;
	return (s);
}
