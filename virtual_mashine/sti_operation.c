//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_sti_func(t_car *car)
{

	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
	//ft_printf ("-> read STI intruction\n");
}



void    do_sti_func(t_vm *main_struct, t_car *car)
{
	if (car->args[0].name == 1 && car->args[0].value > 0)
	{
		put_int_on_map(main_struct->map + car->args[0].value + car->args[1].value,
					   car->reg[car->args[2].value - 1], main_struct->color,
					   car->color);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	//ft_printf("ST HAX!!!!\n");
	car->data = NULL;
}
