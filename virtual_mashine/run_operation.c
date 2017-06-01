//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

void do_op_code(char *map, t_car *car)
{
    if (car->op_type == 1)
        do_live_func(map, car);
    else if (car->op_type == 2)
        do_ld_func(map, car);
	else if (car->op_type == 3)
		do_st_func(map, car);
	else if (car->op_type == 4)
		do_add_func(map, car);
	else if (car->op_type == 5)
		do_sub_func(map, car);
	else if (car->op_type == 6)
		do_and_func(map, car);
	else if (car->op_type == 7)
		do_or_func(map, car);
	else if (car->op_type == 8)
		do_xor_func(map, car);
}
