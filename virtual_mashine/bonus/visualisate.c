//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	stop_vis_and_exit(t_vm *main_struct)
{
	stop_visualisation(main_struct);
	exit(1);
}

void throw_visualization(t_vm *main_struct, char *status)
{
	erase_all(main_struct->vis);
	put_caret_on_map(main_struct);
	w_print_arena(main_struct);
	w_print_param(main_struct, status);
	refresh_all(main_struct->vis);
}

void	visualisate(t_vm *main_struct)
{
	read_commands(main_struct);
	if (check_if_refresh(main_struct) && main_struct->vis->go_to_end == FALSE)
	{
		throw_visualization(main_struct, "PLAY");
		time_pause(main_struct);
	}
}