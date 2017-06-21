//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_lldi_func(t_car *car)
{
	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
	//ft_printf ("-> read LONG LDI intruction\n");
}

void    do_lldi_func(t_vm *main_struct, t_car *car)
{
	if (car->args[3].name == 1 && car->args[3].value > 0)
	{
		car->reg[car->args[3].value] = (unsigned int)get_int_from_byte_code
				(main_struct->map + car->args[0].value + car->args[1].value);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	//ft_printf("LONG LDI HAX!!!!\n");
}