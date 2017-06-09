//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_ld_func(t_car *car)
{
    size_t buf;

    ft_printf ("-> read LD intruction, data = %s\n");
}

void    do_ld_func(t_vm *main_struct, t_car *car)
{
    car->op_type = 0;
    ft_printf("LOAD HAX!!!!\n");
    car->data = NULL;
}
