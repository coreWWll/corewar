//
// Created by Yevhen Yefimov on 6/1/17.
//
#include "vm.h"

void get_aff_func(char *map, t_car *car)
{
	int arg_size;

	if (!(car->data = ft_memdup(REG_SIZE, map, car->pos + 1)))
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "file: lfork_operatin.c:10"));
	car->op_tabble.nb_tours--;
}

void    do_aff_func(t_vm *main_struct, t_car *car)
{
	int		reg_n;
	char 	print;

	reg_n = get_int_from_byte_code(car->data);
	print = (char)(reg_n % 256);
	if (main_struct->aff)
		ft_printf("AFF OPERATION = %c\n", print);
	car->op_tabble.opcode = 0;
	car->pos = car->pos + 1 + REG_SIZE;
}

