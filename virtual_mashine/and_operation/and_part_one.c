//
// Created by Yevhen Yefimov on 6/16/17.
//

#include "../vm.h"

void and_reg_reg(t_car *car, int reg_n)
{
	car->reg[reg_n - 1] = (car->reg[car->args[0].value - 1] &
			car->reg[car->args[1].value - 1]);
}

void and_ind_reg(t_car *car, int reg_n, char *map)
{
	int nb;

	nb = get_int_from_byte_code(map + car->args[0].value);
	car->reg[reg_n - 1] = (nb & car->reg[car->args[1].value - 1]);

}

void	and_dir_reg(t_car *car, int reg_n)
{
	car->reg[reg_n - 1] = (car->args[0].value &
											car->reg[car->args[1].value - 1]);
}

void and_reg_ind(t_car *car, int reg_n, char *map)
{
	int nb;

	nb = get_int_from_byte_code(map + car->args[1].value);
	car->reg[reg_n - 1] = (car->reg[car->args[0].value - 1] & nb);
}

void and_ind_ind(t_car *car, int reg_n, char *map)
{
	int nb_1;
	int nb_2;

	nb_1 = get_int_from_byte_code(map + car->args[0].value);
	nb_2 = get_int_from_byte_code(map + car->args[1].value);
	car->reg[reg_n - 1] = (unsigned int)(nb_1 & nb_2);
}