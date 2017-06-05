//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

void    move_single_car(t_vm *main_struct, t_car *car)
{
    if (car->c_for_op == 0)
    {
        if (car->op_type == 0)
            get_op_code(main_struct, car, &car->pos);
        else
        {
            do_op_code(main_struct->map, car);
            get_op_code(main_struct, car, &car->pos);
        }
    }
    else
        car->c_for_op--;
}

void    move_all_car(t_vm *main_struct)
{
    t_player	**player;
    t_car		*car;
	int			i;

	i = 0;
    player = main_struct->players;
    while (player[i])
    {
        car = player[i]->car;
        while (car)
        {
            move_single_car(main_struct, car);
            car = car->next;
        }
        i++;
    }
}