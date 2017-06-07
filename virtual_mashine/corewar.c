//
// Created by Denys Burtnjak on 5/24/17.
//

#include "vm.h"

int main(int argc, char **argv)
{
	t_vm		*main_struct;

	main_struct = (t_vm*)ft_memalloc(sizeof(t_vm));
	main_struct->players = (t_player**)ft_memalloc(sizeof(t_player*) *
														   (MAX_PLAYERS + 1));
	main_struct->cycle_to_die = CYCLE_TO_DIE;
	main_struct->last_live[0] = 0;
	main_struct->last_live[1] = 0;
	read_arguments(main_struct, argv, argc);
	put_cat_on_start(main_struct);
	create_map(main_struct);
    print_memory((unsigned char*)main_struct->map);
    start_battle(main_struct);
    return (0);
}