/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:37:19 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:37:22 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	memory_dump(t_vm *main_struct, int nbr_cycles)
{
	if (main_struct->f_dump == TRUE && nbr_cycles == main_struct->dump_cycle)
	{
		print_memory((unsigned char *) main_struct->map, MEM_SIZE);
		exit(1);
	}
}
