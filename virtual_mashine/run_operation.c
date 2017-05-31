//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "op.h"

void do_op_code(char *map, t_car *car)
{
    if (car->op_type == 1)
        do_live_func(map, car);
    else if (car->op_type == 2)
        do_ld_func(map, car);
}