//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_or_func(t_car *car)
{
	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
	//ft_printf ("-> read OR intruction, data =\n");
}



void    do_or_func(t_vm *main_struct, t_car *car)
{
	if (car->args[2].name == T_REG && car->args[2].value > 0)
	{
		car->reg[car->args[2].value - 1] = (unsigned int) (car->args[0].value |
														   car->args[1].value);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	if (car->reg[car->args[2].value - 1] == 0)
		car->carry = 1;
	//ft_printf("OR OPERATION!!!!\n");
}