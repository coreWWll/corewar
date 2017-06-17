//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

int i = 0;

void	read_comands(t_vm *main_struct)
{
	if (wgetch(main_struct->vis->arena) == ' ')
		while (wgetch(main_struct->vis->arena) != ' ');
}

void	visualisate(t_vm *main_struct)
{
	read_comands(main_struct);
	erase_all(main_struct->vis);
	w_print_arena(main_struct);
	w_print_param(main_struct);
	wprintw(main_struct->vis->param ,"Time = %d", i);
	if (main_struct->cycle % 50 == 0)
		i++;
	refresh_all(main_struct->vis);
	usleep(1000 * (useconds_t)main_struct->time);
}


/*
 *
 * #include <time.h>

int 	i = 0;


void	get_input(t_vm *main_struct)
{
	char	buf[2];

	if (ft_kbhit() && fgets(buf, 2, stdin))
	{
		if (buf[0] == '+' && main_struct->time > 10)
			main_struct->time -= 10;
		if (buf[0] == '-' && main_struct->time < 9990)
			main_struct->time += 10;
	}
}

void	visualisation(t_vm *main_struct)
{
	long	time;

	//210 * 100000 50/c
	//    1/c
	time = 10000 * main_struct->time;
	get_input(main_struct);
	ft_putstr(CLEARE);
	ft_putstr(TO_BEGIN);
	printf("CYCLE = %10d PERIOD = %10d\n", main_struct->cycle, main_struct
		->round);
	//ft_putnbr(main_struct->time);
	if (main_struct->cycle % 50 == 0)
		i++;
//	ft_putnbr(i);
	//print_memory((unsigned char*)main_struct->map, MEM_SIZE);
	nanosleep((const struct timespec[]){{0, time}}, NULL);
}
 */