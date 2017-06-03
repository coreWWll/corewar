//
// Created by Denys Burtnjak on 5/24/17.
//

#include "vm.h"
/*
void	add_player_back(t_player **alst, t_player *new)
{
    t_player	*p;

    p = *alst;
    if (*alst == NULL)
        *alst = new;
    else
    {
        while (p->next)
            p = p->next;
        p->next = new;
    }
}

void    make_players_list(t_vm *main_struct, char **players_path)
{
    int         n;
    t_player    *player;
    int         j;

    j = 0;
    while (j < main_struct->players_nbr)
    {
		player = create_players(main_struct->map, main_struct->players_nbr,
				players_path[j], j + 1);
		add_player_back(&(main_struct->players), player);
        j++;
    }
}

*/
int main(int argc, char **argv)
{
	t_vm		*main_struct;

	main_struct = (t_vm*)ft_memalloc(sizeof(t_vm));
	main_struct->players = (t_player**)ft_memalloc(sizeof(t_player*) *
														   (MAX_PLAYERS + 1));
	read_arguments(main_struct, argv, argc);
	create_map(main_struct);
    print_memory((unsigned char*)main_struct->map);
    start_battle(main_struct);
    return (0);
}
