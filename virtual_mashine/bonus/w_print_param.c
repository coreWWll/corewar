//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

char	*remove_unprintable(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strdup(str);
	while (new_str[i] != 0)
	{
		if (new_str[i] <= 32 && new_str[i] >= 127)
			new_str[i] = ' ';
		i++;
	}
	return (new_str);
}

void	print_all_players_name(WINDOW *win, t_player **players, int player_nbr)
{
	int		i;
	char	*str;

	i = 0;
	wprintw(win, "%-4c %s\n\n", '#', "Player name");
	while (player_nbr > i)
	{
		str = remove_unprintable(players[i]->bot_name);
		wattron(win, COLOR_PAIR(i + 1));
		wprintw(win, "%-4d %s\n\n", players[i]->name, str);
		wattroff(win, COLOR_PAIR(COL_ARENA));
		ft_strdel(&str);
		i++;
	}
	wprintw(win, "\n");
}

void	w_print_param(t_vm *main_struct)
{
	WINDOW	*win;

	win = main_struct->vis->param;
	wprintw(win, "%-35s%d\n\n", "PLAYERS:", main_struct->players_nbr);
	print_all_players_name(win, main_struct->players, main_struct->players_nbr);
	wprintw(win, "%-35s%d\n\n", "CYCLES:", main_struct->cycle);
	wprintw(win, "%-35s%d\n\n", "CYCLE TO DIE:",
			main_struct->cycle_to_die_for_viz);
	wprintw(win, "%-35s%d\n\n", "PROCESSES:", main_struct->processes);
	wprintw(win, "%-35s%d\n\n", "NUMBER OF LIVES:", main_struct->nbr_of_lifes);
	wprintw(win, "%-35s\n\n", "LAST LIVE:");
	wprintw(win, "\t%-27s%d\n\n", "Player number:", main_struct->last_live[0]);
	wprintw(win, "\t%-27s%d\n\n", "Cycle", main_struct->last_live[1]);
	wprintw(win, "%-35s%d\n\n", "MAX CHECKS:", main_struct->max_checks);

	wprintw(win ,"Time = %d", main_struct->time);
}