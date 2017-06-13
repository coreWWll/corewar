//
// Created by Denys Burtnjak on 5/24/17.
//

#include "vm.h"

t_vm	*create_main_struct(void)
{
	t_vm		*main_struct;

	if ((main_struct = (t_vm*)ft_memalloc(sizeof(t_vm))) == NULL)
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "corewar.c:11"));
	main_struct->players = (t_player**)ft_memalloc(sizeof(t_player*) *
												   (MAX_PLAYERS + 1));
	if (main_struct->players == NULL)
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "corewar.c:16"));
	main_struct->cycle_to_die = CYCLE_TO_DIE;
	main_struct->time = 50;
	return (main_struct);
}

int		main(int argc, char **argv)
{
	t_vm		*main_struct;

/*	char	*buf;
	int		i;

	i = 0;

	buf = ft_strnew(128);
	while (i < 129)
	{
		buf[i] = (char)i;
		i++;
	}
	print_memory((unsigned char*)buf, 129);
*/
	main_struct = create_main_struct();
	read_arguments(main_struct, argv, argc);
	if (main_struct->players_nbr == 0)
		ft_error("NO PLAYERS!");
	put_cat_on_start(main_struct);
	create_map(main_struct);
    print_memory((unsigned char*)main_struct->map, MEM_SIZE);
	start_battle(main_struct);
    return (0);
}