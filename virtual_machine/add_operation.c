//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_add_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

void    do_add_func(t_vm *main_struct, t_car *car)
{
	if (car->args[0].name == T_REG && car->args[1].name == T_REG &&
			car->args[2].name == T_REG && car->args_error && car->args[2]
			 .value > 0 && car->args[2].value <= REG_NUMBER)
	{
		car->reg[car->args[2].value - 1] = car->args[0].value + car->args[1]
																		.value;
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos + car->arg_size + 2;
		return ;
	}
	if (car->reg[car->args[2].value - 1] == 0 && car->carry == 0)
		car->carry = 1;
	else if (car->reg[car->args[2].value - 1] != 0 && car->carry == 1)
		car->carry = 0;
    car->op_tabble.opcode = 0;
    car->pos = car->pos + car->arg_size + 2;
}