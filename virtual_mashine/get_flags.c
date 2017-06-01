//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

void	read_flags(t_vm *main_struct, char **argv, int *i)
{
	int	error = FALSE;

	if (ft_strcmp("-dump", argv[*i]))
	{

	}
	else if (ft_strcmp("-v", argv[*i]))
		main_struct->f_v = TRUE;

	//add -n flag
}

void	read_arguments(t_vm *main_struct, char **argv, int argc)
{
	t_player	*player;
	int			i;

	i = 0;
	main_struct->players_nbr = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			read_flags(main_struct, argv, &i);
		else
		{
			if (main_struct->players_nbr > MAX_PLAYERS)
				ft_error(ft_strjoin("To many players, allowed - ",
									ft_itoa(MAX_PLAYERS)));
			player = create_players(main_struct->map,)
			(main_struct->players_nbr)++;
		}
		i++;
	}
}