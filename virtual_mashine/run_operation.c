//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

void do_op_code_part_two(t_vm *main_struct, t_car *car)
{

	if (car->op_tabble.opcode == 9)
		do_zjmp_func(main_struct, car);
	else if (car->op_tabble.opcode == 10)
		do_ldi_func(main_struct, car);
	else if (car->op_tabble.opcode == 11)
		do_sti_func(main_struct, car);
	else if (car->op_tabble.opcode == 12)
		do_fork_func(main_struct, car);
	else if (car->op_tabble.opcode == 13)
		do_lld_func(main_struct, car);
	else if (car->op_tabble.opcode == 14)
		do_lldi_func(main_struct, car);
	else if (car->op_tabble.opcode == 15)
		do_lfork_func(main_struct, car);
	else if (car->op_tabble.opcode == 16)
		do_aff_func(main_struct, car);
}

void do_op_code_part_one(t_vm *main_struct, t_car *car)
{

    if (car->op_tabble.opcode == 1)
        do_live_func(main_struct, car);
    else if (car->op_tabble.opcode == 2)
        do_ld_func(main_struct, car);
	else if (car->op_tabble.opcode == 3)
		do_st_func(main_struct, car);
	else if (car->op_tabble.opcode  == 4)
		do_add_func(main_struct, car);
	else if (car->op_tabble.opcode == 5)
		do_sub_func(main_struct, car);
	else if (car->op_tabble.opcode == 6)
		do_and_func(main_struct, car);
	else if (car->op_tabble.opcode == 7)
		do_or_func(main_struct, car);
	else if (car->op_tabble.opcode == 8)
		do_xor_func(main_struct, car);
}

void do_op_code(t_vm *main_struct, t_car *car)
{
	if (car->op_tabble.opcode < 9)
		do_op_code_part_one(main_struct, car);
	else if (car->op_tabble.opcode > 8)
		do_op_code_part_two(main_struct,car);
}
