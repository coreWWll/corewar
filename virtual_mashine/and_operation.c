//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_and_func(t_car *car)
{
	car->op_tabble.nb_tours = car->op_tabble.nb_tours - 1;
	ft_printf ("-> read AND intruction, data =\n");
}

/*void	check_args(t_vm *main_struct, t_car *car, int reg_n)
{
	if (car->args[0].name == 1 && car->args[1].name == 1)
		 and_reg_reg(car, reg_n);
	else if (car->args[0].name == 2 && car->args[1].name == 1)
		and_ind_reg(car, reg_n, main_struct->map);
	else if (car->args[0].name == 4 && car->args[1].name == 1)
		and_dir_reg(car, reg_n);
	else if (car->args[0].name == 1 && car->args[1].name == 2)
		and_reg_ind(car, reg_n, main_struct->map);
	else if (car->args[0].name == 2 && car->args[1].name == 2)
		and_ind_ind(car, reg_n, main_struct->map);
	else if (car->args[0].name == 4 && car->args[1].name == 2)
		and_dir_ind(car, reg_n, main_struct->map);
	else if (car->args[0].name == 1 && car->args[1].name == 4)
		and_reg_dir(car, reg_n);
	else if (car->args[0].name == 2 && car->args[1].name == 4)
		and_ind_dir(car, reg_n, main_struct->map);
	else if (car->args[0].name == 4 && car->args[1].name == 4)
		and_dir_dir(car, reg_n);
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return;
	}
}
*/
void    do_and_func(t_vm *main_struct, t_car *car)
{
	if (car->args[2].name == 1)
	{
		car->reg[car->args[2].value + 2] = (unsigned int) (car->args[0].value &
				car->args[1].value);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	ft_printf("AND OPERATION!!!!\n");
}
