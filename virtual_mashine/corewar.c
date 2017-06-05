//
// Created by Denys Burtnjak on 5/24/17.
//

#include "vm.h"

int get_flags(int argc, char **argv, char *map)
{
    return (argc - 1);
}

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
void    make_players_list(t_player **head, char *map, char **argv, int argc)
{
    int         n;
    t_player    *player;
    int         j;
    int         n_bots;

    j = 1;
    n = 1;
    n_bots = get_flags(argc, argv, map);
    while (j < argc)
    {
        if (argv[j] != NULL)
        {
            player = create_players(map, n_bots, argv[j], n);
            add_player_back(head, player);
            n++;
        }
        j++;
    }
}


int main(int argc, char **argv)
{
	t_vm		main_struct;

    main_struct.players = NULL;
	main_struct.map = ft_memalloc(MEM_SIZE);

    make_players_list(&(main_struct.players), main_struct.map, argv, argc);
    print_memory(main_struct.map);
    start_battle(&main_struct);
    return (0);
}
