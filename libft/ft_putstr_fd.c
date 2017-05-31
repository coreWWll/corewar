/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:35:44 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/09 14:58:33 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	return ;
}
