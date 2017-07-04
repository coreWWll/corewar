/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_and_values_part_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:34:25 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:34:27 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_values_reg_end(t_car *car, t_vm *main_struct, int i)
{
	int mark;

	while (i < 2)
	{
		if (car->args[i].name == T_REG)
		{
			if (car->args[i].value - 1 < 0 || car->args[i].value > REG_NUMBER)
				car->args_error = FALSE;
			else
				car->args[i].value = car->reg[car->args[i].value - 1];
		}
		else if (car->args[i].name == T_IND)
		{
			if (car->op_tabble.opcode == 14)
				mark = get_correct_ind(car->pos + car->args[i].value);
			else
				mark = get_correct_ind(car->pos + car->args[i].value % IDX_MOD);
			car->args[i].value = get_int_from_byte_code(main_struct->map +
																mark);
		}
		i++;
	}
}

void	get_values_reg_start(t_car *car, t_vm *main_struct, int i)
{
	int mark;

	i = 1;
	while (i < 3)
	{
		if (car->args[i].name == T_REG)
		{
			if (car->args[i].value > 0 && car->args[i].value <= REG_NUMBER)
				car->args[i].value = car->reg[car->args[i].value - 1];
			else
				car->args_error = FALSE;
		}
		else if (car->args[i].name == T_IND)
		{
			mark = get_correct_ind(car->pos + car->args[i].value % IDX_MOD);
			car->args[i].value = get_int_from_byte_code(main_struct->map +
																mark);
		}
		i++;
	}
}

void	get_ldst_args(t_car *car, t_vm *main_struct, int i)
{
	int mark;

	if (car->op_tabble.opcode == 2 || car->op_tabble.opcode == 13)
	{
		if (car->args[0].name == T_IND)
		{
			if (car->op_tabble.opcode == 2)
				mark = get_correct_ind(car->pos + car->args[0].value % IDX_MOD);
			else
				mark = get_correct_ind(car->pos + car->args[0].value);
			car->args[0].value = get_int_from_byte_code(main_struct->map +
																mark);
		}
		else if (car->args[0].name == T_DIR)
			car->args_error = TRUE;
		else
			car->args_error = FALSE;
	}
	if (car->op_tabble.opcode == 3 && car->args[0].name == T_DIR)
		car->args_error = FALSE;
}
