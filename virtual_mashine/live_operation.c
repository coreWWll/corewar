//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "op.h"

void    get_live_func(char *map, t_car *car, int *pos)
{
    car->data = ft_strsub(map + *pos + 1, 0, 4);
    car->op_type = 1;
    car->c_for_op = 9;
    *pos = (*pos) + 5;
    ft_printf ("-> зчитали інструкцію і її аргументи LIVE = %s\n", car->data);
}



void    do_live_func(char *map, t_car *car)
{
    car->op_type = 0;
    ft_printf("I'm ALIVE!!!!!\n");
}

