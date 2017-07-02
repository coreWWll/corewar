//
// Created by Yevhen Yefimov on 6/29/17.
//

#include "vm.h"

void get_values_reg_end(t_car *car, t_vm *main_struct, int i)
{
	while (i < 2)
	{
		if (car->args[i].name == T_REG && car->op_tabble.opcode != 3 &&
			car->op_tabble.opcode != 11 && car->op_tabble.opcode != 2
			&& car->op_tabble.opcode != 4 && car->op_tabble.opcode != 5)
			car->args[i].value = car->reg[car->args[i].value - 1];
		else if (car->args[i].name == T_IND && car->op_tabble.opcode != 3 &&
				 car->op_tabble.opcode != 11 && car->op_tabble.opcode != 2
				 && car->op_tabble.opcode != 4 && car->op_tabble.opcode != 5)
		{
			if (car->op_tabble.opcode != 14)
				car->args[i].value = get_int_from_byte_code(main_struct->map +
				car->pos + car->args[i].value % IDX_MOD);
			else
				car->args[i].value = get_int_from_byte_code(main_struct->map +
				car->pos + car->args[i].value);
		}
		i++;
	}
}

void get_values_reg_start(t_car *car, t_vm *main_struct, int i)
{
	i = 1;
		while (i < 3)
		{
			if (car->args[i].name == T_REG)
				car->args[i].value = car->reg[car->args[i].value - 1];
			else if (car->args[i].name == T_IND)
			{
				car->args[i].value = get_int_from_byte_code(main_struct->map +
				car->pos + car->args[i].value % IDX_MOD);
			}
			i++;
		}
}

void	get_ldst_args(t_car *car, t_vm *main_struct, int i)
{
	if (car->op_tabble.opcode == 2)
	{
		if (car->args[0])
	}
}