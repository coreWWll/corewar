//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "op.h"

void    get_op_code(char *map, int cycle, t_car *car, int *pos)
{
    //printf("%c%c\n", map[*pos], map[*pos + 1]);
    if (map[*pos] == '0' && map[*pos + 1] == '1')
        get_live_func(map, car, pos);
    if (map[*pos] == '0' && map[*pos + 1] == '2')
        get_ld_func(map, car, pos);
}

void    look_on_car(int cycle, int round, t_car *car, char *map)
{
    if (car->c_for_op == 0)
    {
        if (car->op_type == 0)
            get_op_code(map, cycle, car, &car->pos); // достаэмо оп код
        else
        {
            do_op_code(map, car); // виконуэмо оп код
            get_op_code(map, cycle, car, &car->pos); //  сразу зчитуємо наступний опкод, тому що це в один ицкл проходити має =(
        }
    }
    else
        car->c_for_op--; // очыкування виконання опкодыв
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
            look_on_car(cycle, round, car, map); //перевіряємо де стоїть каретка, яка команда там записана  і т д СУКА
            car = car->next;
        }
        player = player->next;
    }
}

void    move_car(int cycle, int round, t_player *p_l, char *map)
{
   // write (1, "!", 1);
    check_cars(cycle, round, p_l, map); // проходимо по всых каретках
}