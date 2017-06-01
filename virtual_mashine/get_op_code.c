//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

void	get_op_code_part_one(char *map, t_car *car, int *pos)
{
	if (map[*pos]  == 1)
		get_live_func(map, car, pos);
	else if (map[*pos] == 2)
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
}

void	get_op_code_part_two(char *map, t_car *car, int *pos)
{
	if (map[*pos]  == 9)
		get_live_func(map, car, pos);
	else if (map[*pos] == 10)
		get_ld_func(map, car, pos);
	else if (map[*pos] == 11)
		get_st_func(map, car, pos);
	else if (map[*pos] == 12)
		get_add_func(map, car, pos);
	else if (map[*pos] == 13)
		get_sub_func(map, car, pos);
	else if (map[*pos] == 14)
		get_and_func(map, car, pos);
	else if (map[*pos] == 15)
		get_or_func(map, car, pos);
	else if (map[*pos] == 16)
		get_xor_func(map, car, pos);
}


void    get_op_code(t_vm *main_struct, t_car *car, int *pos)
{
	if ((main_struct->map)[*pos] < 9)
		get_op_code_part_one(main_struct->map, car, pos);
	else
		get_op_code_part_two(main_struct->map, car, pos);
}