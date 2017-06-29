//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	change_time(t_vm *main_struct, int c)
{
	if (c == '-' && main_struct->time + 1000 < 1000000)
		main_struct->time += 1000;
	else if (c == '+' && main_struct->time - 1000 > 0)
		main_struct->time -= 1000;
}

void	pause_vis(t_vm *main_struct)
{
	int c;

	main_struct->vis->pause = FALSE;
	wprintw(main_struct->vis->param, "\t\t== PAUSE ==\n");
	w_print_arena(main_struct);
	w_print_param(main_struct);
	refresh_all(main_struct->vis);
	nodelay(main_struct->vis->arena, FALSE);
	while ((c = wgetch(main_struct->vis->arena)) != ' ')
	{
		if (c == 's')
		{
			main_struct->vis->pause = TRUE;
			break ;
		}
		if (c == 't')
		{
			main_struct->vis->pause = FALSE;

			main_struct->vis->t_pause = main_struct->cycle;
			break ;
		}
		if (c == 'h')
		{
			main_struct->vis->pause = FALSE;

			main_struct->vis->h_pause = main_struct->cycle;
			break ;
		}



		werase(main_struct->vis->param);
		change_time(main_struct, c);
		wprintw(main_struct->vis->param, "\t\t== PAUSE ==\n");
		w_print_param(main_struct);
		wrefresh(main_struct->vis->param);
	}
	nodelay(main_struct->vis->arena, TRUE);
}

void	read_commands(t_vm *main_struct)
{
	int		c;

	c = wgetch(main_struct->vis->arena);
	if (c == ' ' || main_struct->vis->pause == TRUE)
		pause_vis(main_struct);
	change_time(main_struct, c);
	while (wgetch(main_struct->vis->arena) != EOF);	/*delete chars in stdin*/
	wprintw(main_struct->vis->param, "\t\t== PLAY ==\n");
}

int		check_if_refresh(t_vm *main_struct)
{
	int		bul_h;
	int		bul_t;

	bul_h = main_struct->vis->h_pause != -1;
	bul_t = main_struct->vis->t_pause != -1;
	if (bul_h && main_struct->cycle == main_struct->vis->h_pause + 99)
	{
		main_struct->vis->pause = TRUE;
		main_struct->vis->h_pause = -1;
		return (TRUE);
	}
	if (bul_t && main_struct->cycle == main_struct->vis->t_pause + 999)
	{
		main_struct->vis->pause = TRUE;
		main_struct->vis->t_pause = -1;
		return (TRUE);
	}
	if (bul_h || bul_t)
		return (FALSE);
	return (TRUE);
}

void	visualisate(t_vm *main_struct)
{
	read_commands(main_struct);
	if (check_if_refresh(main_struct))
	{
		put_caret_on_map(main_struct);
		w_print_arena(main_struct);
		w_print_param(main_struct);
		refresh_all(main_struct->vis);
		erase_all(main_struct->vis);
		usleep((useconds_t) main_struct->time);
	}
}