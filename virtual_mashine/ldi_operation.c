//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_ldi_func(char *map, t_car *car, int *pos)
{

	car->data = ft_memdup(6, map, (*pos) + 1);
	car->op_type = 10;
	car->c_for_op = 24;
	*pos = (*pos) + 7;
	ft_printf ("-> read LDI instruction, data = %s\n", (char*)
			car->data);
}



void    do_ldi_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("LDI??WTF??\n");
}
