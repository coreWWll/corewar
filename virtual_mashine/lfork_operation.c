//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_lfork_func(char *map, t_car *car)
{
	if (!(car->data = ft_memdup((size_t)DIR_SIZE - 2 * car->op_tabble.codage_octal, map, car->pos + 1)))
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "file: lfork_operatin.c:10"));
	car->op_tabble.nb_tours--;
	//ft_printf ("-> read LONG FORK instruction, data = %s\n", car->data);
}

void    do_lfork_func(t_vm *main_struct, t_car *car)
{
	int delta;
	int arg_size;

	arg_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	delta = (int)get_short_from_byte_code(car->data, car->op_tabble.codage_octal);
	ft_printf("distance = %d\n", delta);
	create_new_car(car, delta);
	//ft_printf("-> LONG FORK <-\n");
	car->pos = car->pos + 1 + arg_size;
	car->op_type = 0;
	ft_strdel(&(car->data));
}
