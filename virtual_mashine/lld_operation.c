//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_lld_func(t_car *car)
{
	//car->data = ft_memdup(7, map, (*pos) + 1);
	car->c_for_op = 9;
	car->pos = car->pos + 7;
	ft_printf ("-> read LLD intruction, data = %s");
}

void    do_lld_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("LONG LOAD HAX!!!!\n");
}