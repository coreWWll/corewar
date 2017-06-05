//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_fork_func(char *map, t_car *car, int *pos)
{

	car->data = ft_memdup(2, map, (*pos) + 1);
	car->op_type = 12;
	car->c_for_op = 799;
	*pos = (*pos) + 3;
	ft_printf ("-> read FORK instruction, data = %s\n", (char*)
			car->data);
}



void    do_fork_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("-> BU/|KA <-\n");
}
