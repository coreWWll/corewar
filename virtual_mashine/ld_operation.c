//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_ld_func(t_car *car)
{
    ft_printf ("-> read LD intruction, data =\n");
}

void    do_ld_func(t_vm *main_struct, t_car *car)
{
	if (car->args[0].name == 4 && car->args[0].value == 0
			&& car->args[1].name == 1)
		car->carry = 1;
    car->op_tabble.opcode = 0;
	  car->pos = car->pos + car->arg_size + 2;
    ft_printf("LOAD HAX!!!!\n");
    car->data = NULL;
}
