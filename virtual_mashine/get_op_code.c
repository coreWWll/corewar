//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

void	get_op_code_part_one(char *map, t_car *car)
{
	if (map[car->pos]  == op_tab[0].opcode)
		get_live_func(map, car);
	if (map[car->pos]  == op_tab[8].opcode)
		get_zjmp_func(map, car);
	else if (map[car->pos] == op_tab[11].opcode)
		get_fork_func(map, car);
	else if (map[car->pos] == op_tab[14].opcode)
		get_lfork_func(map, car);
	else if (map[car->pos] == op_tab[15].opcode)
		get_aff_func(map, car);
}

void get_op_code_part_two(t_car *car)
{
	if (car->op_tabble.opcode == op_tab[1].opcode)
		get_ld_func(car);
	else if (car->op_tabble.opcode == op_tab[2].opcode)
		get_st_func(car);
	else if (car->op_tabble.opcode == op_tab[3].opcode)
		get_add_func(car);
	else if (car->op_tabble.opcode == op_tab[4].opcode)
		get_sub_func(car);
	else if (car->op_tabble.opcode == op_tab[5].opcode)
		get_and_func(car);
	else if (car->op_tabble.opcode == op_tab[6].opcode)
		get_or_func(car);
	else if (car->op_tabble.opcode == op_tab[7].opcode)
		get_xor_func(car);
	else if (car->op_tabble.opcode == op_tab[9].opcode)
		get_ldi_func(car);
	else if (car->op_tabble.opcode == op_tab[10].opcode)
		get_sti_func(car);
	else if (car->op_tabble.opcode == op_tab[12].opcode)
		get_lld_func(car);
	else if (car->op_tabble.opcode == op_tab[13].opcode)
		get_lldi_func(car);
}

t_op	find_op_tab(char code)
{
	int i;

	i = 0;
	while (op_tab[i].opcode != 0)
	{
		if (op_tab[i].opcode == code)
			break ;
		i++;
	}
	return (op_tab[i]);
}

void    get_op_code(t_vm *main_struct, t_car *car)
{
	car->op_tabble = find_op_tab(main_struct->map[car->pos]);
	if (main_struct->cycle == 0)
		car->op_tabble.nb_tours--;
	if (car->op_tabble.opcode == 0)
	{
		if (car->pos == MEM_SIZE - 1)
			car->pos = 0;
		else
			car->pos++;
	}
	else
	{
		if (car->op_tabble.opcode == 0 && main_struct->map[car->pos] != 0)
			ft_error(ft_strjoin("OPCODE ERROR: map position = ", ft_itoa
					(car->pos)));
		else
		{
			if (car->op_tabble.args_am == 1)
				get_op_code_part_one(main_struct->map, car);
			else
			{
				car->error = get_args_nd_value(car, main_struct);
				get_op_code_part_two(car);
			}
		}
	}
}