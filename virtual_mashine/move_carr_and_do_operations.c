//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

void    move_single_car(t_vm *main_struct, t_car *car)
{
	if (!car)
		return ;
    if (car->op_tabble.nb_tours == 0)
    {
        if (car->op_tabble.opcode == 0)
            get_op_code(main_struct, car);
        else
        {
            do_op_code(main_struct, car);
            get_op_code(main_struct, car);
        }
    }
    else
        car->op_tabble.nb_tours--;
}

void    move_all_car(t_vm *main_struct)
{
    t_player	**player;
    t_car		*car;
	int			i;

	i = main_struct->players_nbr;
	player = main_struct->players;
    while (i)
    {
        car = player[i - 1]->car;
        while (car)
        {
            move_single_car(main_struct, car);
			if (car->pos > MEM_SIZE)
				car->pos = car->pos - MEM_SIZE;
            car = car->next;
        }
        i--;
    }
}