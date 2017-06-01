//
// Created by Denys Burtnjak on 5/24/17.
//

#include "op.h"

void    show_map(char *map)
{
    int i;

    i = 0;
    while (i < MEM_SIZE)
    {
        if (i % 64 == 0 && i != 0)
            write (1, "\n", 1);
        if (i % 2 == 0 && i % 64 != 0 && i != 0)
            write (1, " ", 1);
        write (1, &map[i], 1);
        i++;
    }
}

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
    char	    *map;
    t_player    *head;

    head = NULL;
	map = ft_memalloc(MEM_SIZE);

    make_players_list(&head, map, argv, argc);
    show_map(map);
    start_battle(head, map);
    return (0);
}
