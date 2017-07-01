//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_lld_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

void    do_lld_func(t_vm *main_struct, t_car *car)
{
	int mark;

	mark = car->pos + car->args[0].value;
	if (car->args[0].name == T_DIR && car->args[1].name == T_REG && car->args_error)
		car->reg[car->args[1].value - 1] = (unsigned int)car->args[0].value;
	else if (car->args[0].name == T_IND && car->args[1].name == T_REG &&
			 car->args[1].value > 0 && car->args_error)
		car->reg[car->args[1].value - 1] = (unsigned int) get_int_from_byte_code
				(main_struct->map + mark);
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	if (car->reg[car->args[1].value - 1] == 0 && car->carry == 0)
		car->carry = 1;
	else if (car->reg[car->args[1].value - 1] != 0 && car->carry == 1)
		car->carry = 0;
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
}