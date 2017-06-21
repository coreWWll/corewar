//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_sub_func(t_car *car)
{
	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
    //ft_printf ("-> read ADD intruction, data =\n");
}



void    do_sub_func(t_vm *main_struct, t_car *car)
{
	if (car->args[0].name == 1 && car->args[1].name == 1 && car->args[2].name
															== 1 &&
			car->args[0].value > 0 && car->args[1].value > 0 && car->args[2]
																		.value > 0)
	{
		car->reg[car->args[2].value - 1] = car->reg[car->args[0].value - 1] -
										   car->reg[car->args[1].value - 1];
		if (car->reg[car->args[2].value - 1] == 0)
			car->op_tabble.carry = 1;
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	if (car->reg[car->args[2].value - 1] == 0)
		car->carry = 1;
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	//ft_printf("SUB OPERATION LAUNCHED!!!!!\n");
}