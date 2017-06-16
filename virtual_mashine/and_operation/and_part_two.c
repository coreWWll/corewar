//
// Created by Yevhen Yefimov on 6/16/17.
//

#include "../vm.h"

void and_dir_ind(t_car *car, int reg_n, char *map)
{
	int nb;

	nb = get_int_from_byte_code(map + car->args[1].value);
	car->reg[reg_n - 1] = (unsigned int)(car->args[0].value & nb);
}

void and_reg_dir(t_car *car, int reg_n)
{
	car->reg[reg_n - 1] = car->reg[car->args[0].value - 1] & car->args[1].value;
}

void and_ind_dir(t_car *car, int reg_n, char *map)
{
	int nb;

	nb = get_int_from_byte_code(map + car->args[0].value);
	car->reg[reg_n - 1] = (unsigned int)(nb & car->args[1].value);
}

void and_dir_dir(t_car *car, int reg_n)
{
	car->reg[reg_n - 1] = (unsigned int)(car->args[0].value & car->args[1]
																	  .value);
}