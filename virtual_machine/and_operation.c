/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:27:15 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:27:17 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void get_and_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

void    do_and_func(t_car *car)
{
	if (car->args[2].name == T_REG && car->args[2].value > 0 && car->args[2]
		.value <= REG_NUMBER &&	car->args_error)
	{
		car->reg[car->args[2].value - 1] = (car->args[0].value &
				car->args[1].value);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos + car->arg_size + 2;
		return;
	}
	car->op_tabble.opcode = 0;
	if (car->reg[car->args[2].value - 1] == 0 && car->carry == 0)
		car->carry = 1;
	else if (car->reg[car->args[2].value - 1] != 0 && car->carry == 1)
		car->carry = 0;
	car->pos = car->pos + car->arg_size + 2;
	fix_car_pos(car);
}
