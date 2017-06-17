//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	w_print_param(t_vm *main_struct)
{
	WINDOW	*win;

	win = main_struct->vis->param;
	wprintw(win, "%-35s%d\n", "CYCLES:", main_struct->cycle);
}