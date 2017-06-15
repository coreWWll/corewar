/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int_on_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:32:44 by dburtnja          #+#    #+#             */
/*   Updated: 2017/06/09 20:04:10 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void put_int_on_map(char *map, int data, char *players, char player_nbr)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		map[i] = (char)data;
		players[i] = player_nbr;
		data = data >> 8;
		i--;
	}
}