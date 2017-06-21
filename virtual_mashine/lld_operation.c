//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_lld_func(t_car *car)
{
	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
	//ft_printf ("-> read LLD intruction, data =\n");
}

void    do_lld_func(t_vm *main_struct, t_car *car)
{
	if (car->args[0].name == 4 && car->args[0].value == 0
		&& car->args[1].name == 1 && car->args[1].value > 0)
		car->carry = 1;
	if (car->args[0].name == 4 && car->args[1].name == 1)
		car->reg[car->args[1].value - 1] = (unsigned int)car->args[0].value;
	else if (car->args[0].name == 2 && car->args[1].name == 1 && car->args[1]
																		 .value > 0)
		car->reg[car->args[1].value - 1] = (unsigned int) get_int_from_byte_code
				(main_struct->map + car->pos + car->args[0].value);
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	//ft_printf("LONG LOAD HAX!!!!\n");
}