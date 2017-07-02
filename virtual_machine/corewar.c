//
// Created by Denys Burtnjak on 5/24/17.
//

#include "vm.h"
#include "visualisation.h"

void	create_color_array(t_vm *main_struct)
{
	int 	i;

	i = 0;
	if ((main_struct->color = (char *)malloc(MEM_SIZE)) == NULL)
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "corewar.c:10"));
	while (i < MEM_SIZE)
	{
		main_struct->color[i] = COL_ARENA;
		i++;
	}
}

t_vm	*create_main_struct(void)
{
	t_vm		*main_struct;

	if ((main_struct = (t_vm*)ft_memalloc(sizeof(t_vm))) == NULL)
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "corewar.c:11"));
	main_struct->players = (t_player**)ft_memalloc(sizeof(t_player*) *
												   (MAX_PLAYERS + 1));
	if (main_struct->players == NULL)
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "corewar.c:16"));
	create_color_array(main_struct);
	main_struct->cycle_to_die = CYCLE_TO_DIE;
	main_struct->time = 50;
	return (main_struct);
}

void	introducing(t_vm *main_struct)
{
	int			i;

	i = 0;
	if (main_struct->f_v == FALSE)
		ft_printf("Introducing contestants...\n");
	if (main_struct->f_v == FALSE)
	{
		while (main_struct->players[i])
		{
			ft_printf("* Player %d, weighing %d bytes,  \"%s\" (\"%s\") !\n",
					  -main_struct->players[i]->name,
					  main_struct->players[i]->prog_len,
					  main_struct->players[i]->bot_name,
					  main_struct->players[i]->comment);
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	t_vm		*main_struct;

	main_struct = create_main_struct();
	read_arguments(main_struct, argv, argc);
	if (main_struct->players_nbr == 0)
		usage();
	put_cat_on_start(main_struct);
	create_map(main_struct);
	if (main_struct->f_v == TRUE)
		start_visualisation(main_struct);
	main_struct->cycle_to_die_for_viz = CYCLE_TO_DIE;
	introducing(main_struct);
	start_battle(main_struct);
	if (main_struct->f_v == TRUE)
		stop_visualisation(main_struct);
	return 0;
}
