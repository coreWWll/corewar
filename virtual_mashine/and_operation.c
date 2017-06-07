//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_and_func(char *map, t_car *car, int *pos)
{
	car->data = ft_memdup(4, map, (*pos) + 1);
	car->op_type = 6;
	car->c_for_op = 5;
	*pos = (*pos) + 5;
	ft_printf ("-> read AND operation and it data = %s\n", car->data);
}

void    do_and_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("AND FUNCTION!!!!\n");
}
