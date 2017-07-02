//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_zjmp_func(char *map, t_car *car)
{
	int arg_size;

	car->op_tabble.nb_tours--;
}

void    do_zjmp_func(t_vm *main_struct, t_car *car)
{
	int dist;
	int arg_size;

	arg_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	if (car->carry == 1)
	{
		dist = get_short_from_byte_code(main_struct->map + car->pos + 1,
										car->op_tabble
				.codage_octal);
		car->pos = car->pos + dist;
	}
	else
		car->pos = car->pos + arg_size + 1;
	car->op_tabble.opcode = 0;
}