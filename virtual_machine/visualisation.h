/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:04:48 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 17:04:53 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISATION_H
# define VISUALISATION_H

# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include "vm.h"
# include <ncurses.h>
# include <time.h>

# define COL_ARENA			10
# define COL_CAR			20
# define COL_NEW_MEM		30
# define RED_TEXT_ON_CYAN	40
# define TIME_TWO_MS		20000
# define TIME_ONE_S			1000000

void	w_print_arena(t_vm *main_struct);
void	erase_all(t_vis *vis);
void	refresh_all(t_vis *vis);
void	w_print_param(t_vm *main_struct, char *status);
void	w_print_usage(WINDOW *win);
void	read_commands(t_vm *main_struct);
void	time_pause(t_vm *main_struct);
void	change_time(t_vm *main_struct, int c);
int		check_if_refresh(t_vm *main_struct);
void	read_commands(t_vm *main_struct);
void	stop_vis_and_exit(t_vm *main_struct);
void	create_windows(t_vm *main_struct);

#endif
