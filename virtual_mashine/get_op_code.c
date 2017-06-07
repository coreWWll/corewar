//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

void	get_op_code_part_one(char *map, t_car *car, int *pos)
{
	if (map[*pos]  == op_tab[0].opcode)
		get_live_func(map, car, pos);
	if (map[*pos]  == 9)
		get_zjmp_func(map, car, pos);
	else if (map[*pos] == 12)
		get_fork_func(map, car, pos);
	else if (map[*pos] == 15)
		get_lfork_func(map, car, pos);
	else if (map[*pos] == 16)
		get_aff_func(map, car, pos);
}

void	get_op_code_part_two(char *map, t_car *car, int *pos)
{
	if (map[*pos] == 2)
		get_ld_func(map, car, pos);
	else if (map[*pos] == 3)
		get_st_func(map, car, pos);
	else if (map[*pos] == 4)
		get_add_func(map, car, pos);
	else if (map[*pos] == 5)
		get_sub_func(map, car, pos);
	else if (map[*pos] == 6)
		get_and_func(map, car, pos);
	else if (map[*pos] == 7)
		get_or_func(map, car, pos);
	else if (map[*pos] == 8)
		get_xor_func(map, car, pos);

	else if (map[*pos] == 10)
		get_ldi_func(map, car, pos);
	else if (map[*pos] == 11)
		get_sti_func(map, car, pos);

	else if (map[*pos] == 13)
		get_lld_func(map, car, pos);
	else if (map[*pos] == 14)
		get_lldi_func(map, car, pos);

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

void    get_op_code(t_vm *main_struct, t_car *car, int *pos)
{
	car->op_tabble = find_op_tab(main_struct->map[*pos]);
	if (car->op_tabble.opcode == 0)
		ft_error(ft_strjoin("OPCODE ERROR: map position = ", ft_itoa(*pos)));
	else
	{
		if (car->op_tabble.args_am == 1)
			get_op_code_part_one(main_struct->map, car, pos);
		else
			get_op_code_part_two(main_struct->map, car, pos);

	}
}