//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_ldi_func(t_car *car)
{
	car->op_tabble.nb_tours--;
	//ft_printf ("-> read LDI intruction\n");
}

int 	get_correct_ind(int mark)
{
	int k;

	if (mark > MEM_SIZE)
	{
		k = mark / MEM_SIZE;
		mark = mark - k * MEM_SIZE;
	}
	return (mark);
}

void    do_ldi_func(t_vm *main_struct, t_car *car)
{
	int mark;

	mark = get_correct_ind(car->pos + car->args[0].value + car->args[1].value - 2);
	if (car->args[2].name == T_REG && car->args[2].value > 0)
	{
		car->reg[car->args[2].value - 1] = (unsigned int)get_int_from_byte_code(main_struct->map + mark);
		// reading a value of a registry’s size !!!!!!!!!!!!!!!!!!!!
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	if (car->reg[car->args[2].value - 1] == 0 && car->carry == 0)
		car->carry = 1;
	else if (car->reg[car->args[2].value - 1] != 0 && car->carry == 1)
		car->carry = 0;
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
}
