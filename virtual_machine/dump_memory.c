/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:32:44 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:32:46 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	put_nbr_dump(unsigned char c)
{
	unsigned char	print;

	if (c >= 16)
	{
		put_nbr_dump(c / (char)16);
		put_nbr_dump(c % (char)16);
	}
	else
	{
		if (c < 10)
			print = (unsigned char)(c + '0');
		else
			print = (unsigned char)((c - 10) + 'a');
		ft_printf("%c", print);
	}
}

void	dump_memory(unsigned char *map, size_t size)
{
	size_t	i;
	int		count;

	i = 0;
	while (i < size)
	{
		if (i % 64 == 0)
		{
			count = (int)i / 64;
			ft_printf("0x%04x : ", count * 64);
		}
		if (map[i] < 16)
			ft_printf("%d", 0);
		put_nbr_dump(map[i]);
		i++;
		if (i % CHAR_IN_ROW == 0 && i != 0)
			ft_printf("\n");
		else
			ft_printf(" ");
	}
	exit(0);
}
