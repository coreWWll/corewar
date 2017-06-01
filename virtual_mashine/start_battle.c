//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"
#include <stdio.h>
#include <time.h>


int check_alive(t_player *p_l)
{
    return (1);
}

void    start_battle(t_vm *main_struct)
{
	main_struct->cycle = 1;
    main_struct->round = 0;
    while (check_alive(main_struct->players))
    {
        nanosleep((const struct timespec[]){{0, 259900000}}, NULL);
        if (main_struct->cycle == CYCLE_TO_DIE + (CYCLE_TO_DIE - main_struct
																		->round * CYCLE_DELTA) * main_struct->round)
            (main_struct->round)++;
		move_all_car(main_struct);
        printf("CYCLE = %d PERIOD = %d\n", main_struct->cycle, main_struct
                ->round);
        (main_struct->cycle)++;
    }
}
