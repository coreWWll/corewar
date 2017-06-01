//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "op.h"

void    get_op_code(char *map, int cycle, t_car *car, int *pos)
{
    if (map[*pos]  == 1)
        get_live_func(map, car, pos);
    if (map[*pos] == 2)
        get_ld_func(map, car, pos);
    if (map[*pos] == 3)
        get_st_func(map, car, pos);
    if (map[*pos] == 4)
        get_add_func(map, car, pos);
}

void    look_on_car(int cycle, int round, t_car *car, char *map)
{
    if (car->c_for_op == 0)
    {
        if (car->op_type == 0)
            get_op_code(map, cycle, car, &car->pos);
        else
        {
            do_op_code(map, car);
            get_op_code(map, cycle, car, &car->pos);
        }
    }
    else
        car->c_for_op--;
}

void    check_cars(int cycle, int round, t_player *p_l, char *map)
{
    t_player *player;
    t_car   *car;

    player = p_l;
    while (player)
    {
        car = player->car;
        while (car)
        {
            look_on_car(cycle, round, car, map);
            car = car->next;
        }
        player = player->next;
    }
}

void    move_car(int cycle, int round, t_player *p_l, char *map)
{
    // write (1, "!", 1);
    check_cars(cycle, round, p_l, map);
}
