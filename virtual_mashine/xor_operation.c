//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_xor_func(t_car *car)
{

	//car->data = ft_memdup(4, map, (*pos) + 1);
	car->c_for_op = 5;
	car->pos = car->pos + 5;
	ft_printf ("-> read XOR operation ant it data \n", car->data);
}



void    do_xor_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("XOR OPERATION\n");
}