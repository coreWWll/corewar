//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "op.h"

void    get_live_func(char *map, t_car *car, int *pos)
{
    car->data = ft_strsub(map + *pos + 2, 0, 8);
    car->op_type = 1;
    car->c_for_op = 9;
    *pos = (*pos) + 10;
    printf ("-> зчитали інструкцію і її аргументи LIVE = %s\n", car->data);
}

void    get_ld_func(char *map, t_car *car, int *pos)
{
    car->data = ft_strsub(map + *pos + 2, 0, 14);
    car->op_type = 2;
    car->c_for_op = 4;
    *pos = (*pos) + 14;
    printf ("-> зчитали інструкцію і її аргументи LD = %s\n", car->data);
}

void    do_live_func(char *map, t_car *car)
{
    car->op_type = 0;
    printf("I'm ALIVE!!!!!\n");
}

void    do_ld_func(char *map, t_car *car)
{
    car->op_type = 0;
    printf("LOAD HAX!!!!\n");
}