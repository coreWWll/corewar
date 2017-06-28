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
#include "bonus/visualisation.h"

void put_int_on_map(t_vm *main_struct, int data, char *players, char player_nbr)
{
	int		i;
	int 	cor;


	cor = main_struct->coord_for_put_int_on_map;
	i = 3;
	while (i >= 0)
	{
		if (cor + i > MEM_SIZE - 1)
			main_struct->map[cor + i - MEM_SIZE] = (char) data;
		else
			main_struct->map[cor] = (char) data;

		players[i] = (char)(player_nbr + COL_NEW_MEM);
		data = data >> 8;
		i--;
	}
}