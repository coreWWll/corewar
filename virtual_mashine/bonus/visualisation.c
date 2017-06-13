//
// Created by denys on 13.06.17.
//

#include "../vm.h"
#include "visualisation.h"
#include <time.h>

void	get_input(t_vm *main_struct)
{
	char	buf[2];

	fgets(buf, 1, stdin);
		if (buf[0] == '+')
			main_struct->time -= 10;
		if (buf[0] == '-')
			main_struct->time += 10;
}

void	visualisation(t_vm *main_struct)
{
	long	time;

	//190 50 c
	time = 100000 * 200;
	get_input(main_struct);
	ft_putstr(CLEARE);
	ft_putstr(TO_BEGIN);
	printf("CYCLE = %10d PERIOD = %10d\n", main_struct->cycle, main_struct
			->round);
	ft_putnbr(main_struct->time);
	if (main_struct->cycle % 50 == 0)
		ft_putstr("s");
//	print_memory((unsigned char*)main_struct->map, MEM_SIZE);
	nanosleep((const struct timespec[]){{0, time}}, NULL);
}