//
// Created by Yevhen Yefimov on 6/1/17.
//
#include "vm.h"

void get_aff_func(char *map, t_car *car)
{

	car->data = ft_memdup(1, map, car->pos + 1);
	ft_printf ("-> read AFF intruction\n");
}



void    do_aff_func(t_vm *main_struct, t_car *car)
{
	int reg_n;

	reg_n = (int)car->data;
	ft_printf("-> AFF OPERATION<-\n");
	car->op_tabble.opcode = 0;
	car->pos = car->pos + 1 + DIR_SIZE - 2 * car->op_tabble.codage_octal;
}

