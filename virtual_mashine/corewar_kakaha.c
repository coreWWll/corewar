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

void    get_bots(int argc, char **argv, char *map, int n_bots)
{
    int     i;
    int     j;
    int     k = 0;
    char    bot[1];
    int     fd;
    int     n;

    n = 0;
    j = 1;
    while (j <= argc)
    {
        i = 0;
        if (argv[j] != NULL)
        {
            if ((fd = open(argv[j], O_RDONLY)) < 3)
                exit(-2);
            while (read(fd, bot, 1))
            {
                if (k > PROG_NAME_LENGTH + COMMENT_LENGTH + 15)
                {
                    map[i + (MEM_SIZE / n_bots) * n] = bot[0];
                    i++;
                }
                k++;
            }
            n++;
            close (fd);
        }
        j++;
    }
}

int main(int argc, char **argv)
{
    char	    *map;
    int         n_bots;
    int         n;
    t_player    *p_list;
    t_player    *ptr;

    n = 1;
    ptr = p_list;
	map = ft_memalloc(MEM_SIZE);
    n_bots = get_flags(argc, argv, map);
    while (n < n_bots + 1)
    {
        p_list = create_players(map, n_bots, argv[1], &n);
        p_list = p_list->next;
    }
    //get_bots(argc, argv, map, n_bots);

    show_map(map);

    //put_car(map, n_bots);
	return (0);
}
