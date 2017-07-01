//
// Created by denys on 03.06.17.
//

#include "vm.h"

void	memory_dump(t_vm *main_struct, int nbr_cycles)
{
	if (main_struct->f_dump == TRUE && nbr_cycles == main_struct->dump_cycle)
	{
		print_memory((unsigned char *) main_struct->map, MEM_SIZE);
		exit(1);
	}
}