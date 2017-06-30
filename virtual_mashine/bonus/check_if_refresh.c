//
// Created by Denys Burtnjak on 6/30/17.
//

#include "visualisation.h"

int		time_refresh(t_vm *main_struct)
{
	if (main_struct->time - 50 > 0)
	{
		if (main_struct->cycle % (main_struct->time - 50) == 0)
			return (TRUE);
	}
	return (FALSE);
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
	if (bul_h || bul_t || time_refresh(main_struct))
		return (FALSE);
	return (TRUE);
}