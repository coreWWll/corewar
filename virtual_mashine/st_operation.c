//
// Created by Yevhen Yefimov on 6/1/17.
//

void    get_st_func(char *map, t_car *car, int *pos)
{
    car->data = ft_strsub(map + *pos + 1, 0, 4);
    car->op_type = 3;
    car->c_for_op = 4;
    *pos = (*pos) + 4;
    ft_printf ("-> зчитали інструкцію і її аргументи ST = %s\n", car->data);
}

void    do_st_func(char *map, t_car *car)
{
    car->op_type = 0;
    ft_printf("ST HAX!!!!\n");
}
