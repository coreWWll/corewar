//
// Created by denys on 13.06.17.
//

#ifndef VIRTUAL_MASHINE_VISUALISATION_H
#define VIRTUAL_MASHINE_VISUALISATION_H

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "../vm.h"
#include <ncurses.h>

# define	COL_ARENA	10
# define	COL_CAR		20

int		ft_kbhit(void);
void	w_print_arena(t_vm *main_struct);
void	erase_all(t_vis *vis);
void	refresh_all(t_vis *vis);
void	w_print_param(t_vm *main_struct);
void	w_print_usage(WINDOW *win);




#endif //VIRTUAL_MASHINE_VISUALISATION_H
