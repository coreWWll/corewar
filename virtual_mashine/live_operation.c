//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

void    get_live_func(char *map, t_car *car, int *pos)
{

    car->data = ft_memdup(4, map, (*pos) + 1);
    car->op_type = 1;
    car->c_for_op = 9;
    *pos = (*pos) + 5;
    ft_printf ("-> зчитали інструкцію і її аргументи LIVE = %s\n", (char*)
			car->data);
}



void    do_live_func(char *map, t_car *car)
{
    car->op_type = 0;
    ft_printf("I'm ALIVE!!!!!\n");
}

