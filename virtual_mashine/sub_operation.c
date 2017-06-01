//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void    get_sub_func(char *map, t_car *car, int *pos)
{

	car->data = ft_memdup(4, map, (*pos) + 1);
    car->op_type = 5;
    car->c_for_op = 9;
    *pos = (*pos) + 5;
    ft_printf ("-> зчитали інструкцію і її аргументи SUB = %s\n", car->data);
}



void    do_sub_func(char *map, t_car *car)
{
    car->op_type = 0;
    ft_printf("SUB!!!!!\n");
}