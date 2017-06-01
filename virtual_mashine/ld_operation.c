//
// Created by Yevhen Yefimov on 6/1/17.
//

void    get_ld_func(char *map, t_car *car, int *pos)
{
    car->data = ft_strsub(map + *pos + 1, 0, 7);
    car->op_type = 2;
    car->c_for_op = 4;
    *pos = (*pos) + 7;
    ft_printf ("-> зчитали інструкцію і її аргументи LD = %s\n", car->data);
}

void    do_ld_func(char *map, t_car *car)
{
    car->op_type = 0;
    ft_printf("LOAD HAX!!!!\n");
}
