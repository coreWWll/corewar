//
// Created by Yevhen Yefimov on 5/26/17.
//

#include "op.h"

void    show_players_and_cars(t_player *p_list)
{
    while (p_list)
    {
        printf("PLAYER = %d, CAR_0_POS = %d\n", p_list->name, p_list->car->pos);
        p_list = p_list->next;
    }

}