/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:38:47 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 16:38:49 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisation.h"

int		check_input_char(t_vm *main_struct, int c)
{
	if (c == 's')
	{
		main_struct->vis->pause = TRUE;
		return (TRUE);
	}
	if (c == 't')
	{
		main_struct->vis->pause = FALSE;
		main_struct->vis->t_pause = main_struct->cycle;
		return (TRUE);
	}
	if (c == 'h')
	{
		main_struct->vis->pause = FALSE;
		main_struct->vis->h_pause = main_struct->cycle;
		return (TRUE);
	}
	return (FALSE);
}

int		read_when_play_and_pause(t_vm *main_struct, int c)
{
	if (c == 'e')
	{
		throw_visualization(main_struct, "GOING TO END");
		main_struct->vis->go_to_end = TRUE;
		return (TRUE);
	}
	else if (c == 'q')
	{
		stop_vis_and_exit(main_struct);
		return (TRUE);
	}
	return (FALSE);
}

void	pause_vis(t_vm *main_struct)
{
	int c;

	main_struct->vis->pause = FALSE;
	throw_visualization(main_struct, "PAUSE");
	nodelay(main_struct->vis->arena, FALSE);
	while ((c = wgetch(main_struct->vis->arena)) != ' ')
	{
		if (read_when_play_and_pause(main_struct, c))
			break ;
		if (check_input_char(main_struct, c))
			break ;
		change_time(main_struct, c);
		throw_visualization(main_struct, "PAUSE");
	}
	nodelay(main_struct->vis->arena, TRUE);
}

void	read_commands(t_vm *main_struct)
{
	int		c;

	c = wgetch(main_struct->vis->arena);
	if (c == ' ' || main_struct->vis->pause == TRUE)
		pause_vis(main_struct);
	else
	{
		change_time(main_struct, c);
		read_when_play_and_pause(main_struct, c);
	}
	while (wgetch(main_struct->vis->arena) != EOF)
	{
	}
}
