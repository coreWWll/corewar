//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "op.h"
#include <stdio.h>
#include <stdlib.h>


int check_alive(t_player *p_l)
{
    return (1);
}

void    start_battle(t_player *p_l, char *map)
{
    int cycle;
    int round;

    cycle = 1;
    round = 0;
    while (check_alive(p_l))
    {
        nanosleep((const struct timespec[]){{0, 259900000}}, NULL);
        if (cycle == CYCLE_TO_DIE + (CYCLE_TO_DIE - round * CYCLE_DELTA) * round)
            round++;
        move_car(cycle, round, p_l, map);
        printf("CYCLE = %d PERIOD = %d\n", cycle, round);
        cycle++;
    }
}