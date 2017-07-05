/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:43:02 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:43:03 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_zjmp_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

void	do_zjmp_func(t_vm *main_struct, t_car *car)
{
	int dist;
	int arg_size;

	arg_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	if (car->carry == 1)
	{
		dist = get_short_from_byte_code(main_struct->map + car->pos + 1,
			car->op_tabble.codage_octal);
		car->pos = car->pos + dist;
	}
	else
	{
		car->pos = car->pos + 1 + arg_size;
	}
	car->op_tabble.opcode = 0;
	fix_car_pos(car);
}
