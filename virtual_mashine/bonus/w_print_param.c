//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	w_print_param(t_vm *main_struct)
{
	WINDOW	*win;

	win = main_struct->vis->param;
	wprintw(win, "%-35s%d\n\n", "PLAYERS:", main_struct->players_nbr);
	wprintw(win, "%-35s%d\n\n", "CYCLES:", main_struct->cycle);
	wprintw(win, "%-35s%d\n\n", "CYCLE TO DIE:", main_struct->cycle_to_die);
	wprintw(win, "%-35s%d\n\n", "NUMBER OF LIVES:", main_struct->nbr_of_lifes);
	wprintw(win, "%-35s\n\n", "LAST LIVE:");
	wprintw(win, "\t%-27s%d\n\n", "Player number:", main_struct->last_live[0]);
	wprintw(win, "\t%-27s%d\n\n", "Cycle", main_struct->last_live[1]);
	wprintw(win, "%-35s%d\n\n", "MAX CHECKS:", main_struct->max_checks);

	wprintw(win ,"Time = %d", main_struct->time);
}