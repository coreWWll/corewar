//
// Created by Yevhen Yefimov on 6/1/17.
//
#include "vm.h"

void get_aff_func(char *map, t_car *car)
{

	car->data = ft_memdup(2, map, car->pos + 1);
	car->op_type = 16;
	car->c_for_op = 1;
	car->pos = car->pos + 3;
	ft_printf ("-> read AFF instruction, data = %s\n", (char*)
			car->data);
}



void    do_aff_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("-> AFF <-\n");
}

