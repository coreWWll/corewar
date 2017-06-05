//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_lldi_func(char *map, t_car *car, int *pos)
{
	car->data = ft_memdup(5, map, (*pos) + 1);
	car->op_type = 14;
	car->c_for_op = 49;
	*pos = (*pos) + 6;
	ft_printf ("-> read LLDI intruction, data = %s\n", car->data);
}

void    do_lldi_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("-> LLDI <- \n");
}