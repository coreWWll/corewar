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
void	put_cat_on_start(t_vm	*main_struct)
{
	int i;

	i = 1;
	while (i <= main_struct->players_nbr)
	{
		main_struct->players[i]->car->pos = MEM_SIZE /
				main_struct->players_nbr * (i - 1);
		main_struct->players[i]->car->nb = 0;
		if (main_struct->players[i]->boot_nbr != 0)
		{
			main_struct->players[i]->name = (unsigned int)
											main_struct->players[i]->boot_nbr;
			main_struct->players[i]->car->reg[0] =
					(unsigned int) main_struct->players[i]->boot_nbr;
		}
		else
		{
			main_struct->players[i]->name = (i * (-1));
			main_struct->players[i]->car->reg[0] = (unsigned int) (i * (-1));
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_vm		*main_struct;

	main_struct = (t_vm*)ft_memalloc(sizeof(t_vm));
	main_struct->players = (t_player**)ft_memalloc(sizeof(t_player*) *
														   (MAX_PLAYERS + 1));
	main_struct->cycle_to_die = CYCLE_TO_DIE;
	read_arguments(main_struct, argv, argc);
	put_cat_on_start(main_struct);
	create_map(main_struct);
    print_memory((unsigned char*)main_struct->map);
    start_battle(main_struct);
    return (0);
}