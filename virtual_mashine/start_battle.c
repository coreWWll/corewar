//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"
#include <stdio.h>
#include <time.h>


int check_alive(t_vm *main_struct)
{
    return (1);
}

void    start_battle(t_vm *main_struct)
{
	main_struct->cycle = 1;
    main_struct->round = 0;
    while (check_alive(main_struct) && (CYCLE_TO_DIE -
			main_struct->round * CYCLE_DELTA) >= 0)
    {
        nanosleep((const struct timespec[]){{0, 2599000}}, NULL);
        if (main_struct->cycle == main_struct->cycle_to_die)
		{
			(main_struct->round)++;
			main_struct->cycle_to_die = main_struct->cycle_to_die + CYCLE_TO_DIE - main_struct->round * CYCLE_DELTA;
		}
		move_all_car(main_struct);
        printf("CYCLE = %d PERIOD = %d\n", main_struct->cycle, main_struct
                ->round);
        (main_struct->cycle)++;
		//conditions not right
    }
}
