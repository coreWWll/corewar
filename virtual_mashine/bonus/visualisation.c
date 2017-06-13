//
// Created by denys on 13.06.17.
//

#include "../vm.h"
#include "visualisation.h"
#include <time.h>

void	visualisation(t_vm *main_struct)
{
	long	time;

	time = 1000000;
	ft_putstr(CLEARE);
	ft_putstr(TO_BEGIN);
	print_memory((unsigned char*)main_struct->map, MEM_SIZE);
	nanosleep((const struct timespec[]){{0, time}}, NULL);
}