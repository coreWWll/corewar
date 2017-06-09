//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"
#include <stdio.h>
#include <time.h>


void change_alive_flag(t_vm *main_struct)
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
			if (car->live == 0)
				dell_car_from_list(&(player[i]->car), car);
			car->live = 0;
			car = car->next;
		}
		i++;
	}
}

int check_alive(t_vm *main_struct)
{
	t_player	**player;
	int			i;

	i = 0;
	player = main_struct->players;
	while (player[i])
	{
		if (player[i]->car)
			return (1);
		i++;
	}
    return (0);
}

void    start_battle(t_vm *main_struct)
{
	main_struct->cycle = 1;
    main_struct->round = 0;
	main_struct->nbr_of_lifes = 0;
	while (check_alive(main_struct) && (CYCLE_TO_DIE -
			main_struct->round * CYCLE_DELTA) >= 0)
    {
        nanosleep((const struct timespec[]){{0, 259900}}, NULL);
        if (main_struct->cycle == main_struct->cycle_to_die)
		{
			if (main_struct->nbr_of_lifes >= NBR_LIVE)
			{
				main_struct->cycle_to_die =
						main_struct->cycle_to_die + CYCLE_TO_DIE -
						CYCLE_DELTA * main_struct->round;
				(main_struct->round)++;
			}
			else
				main_struct->cycle_to_die = main_struct->cycle_to_die + CYCLE_TO_DIE;
			main_struct->nbr_of_lifes = 0;
			change_alive_flag(main_struct);
		}
		move_all_car(main_struct);
        printf("CYCLE = %d PERIOD = %d\n", main_struct->cycle, main_struct
                ->round);
		//printf ("Last live Player = %d cylcle = %d\n",
		//		main_struct->last_live[0], main_struct->last_live[1]);
        (main_struct->cycle)++;
    }
}
