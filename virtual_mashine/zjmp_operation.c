//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_zjmp_func(char *map, t_car *car)
{

	car->data = ft_memdup((size_t)DIR_SIZE - 2 * car->op_tabble.codage_octal,
						  map, car->pos + 1);
	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
	//ft_printf ("-> read instruction ZJMP, data = %s\n", car->data);
}



void    do_zjmp_func(t_vm *main_struct, t_car *car)
{
	int dist;


	if (car->carry == 1)
	{
		dist = get_short_from_byte_code(car->data, car->op_tabble.codage_octal);
		car->pos = car->pos + dist;
	}
	else
		car->pos = car->pos + 1 + DIR_SIZE - 2 * car->op_tabble.codage_octal;
	//ft_printf("JUST JUMP!\n");
	car->op_tabble.opcode = 0;
}