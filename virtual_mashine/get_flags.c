//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

int		get_nbr_after_flag(char **argv, int argc, int *i)
{
	int	error;
	int ret_val;

	(*i)++;
	if (*i >= argc)
		ft_error(ft_strjoin("No parameter after flag ", argv[(*i) - 1]));
	ret_val = ft_atoi_move(&(argv[*i]), &error, FALSE);
	if (error == TRUE || ret_val < 0)
		ft_error(ft_strjoin("Bad number: ", argv[*i]));
	(*i)++;
	return (ret_val);
}

void	read_flags(t_vm *main_struct, char **argv, int argc, int *i)
{
	if (ft_strcmp("-dump", argv[*i]) == 0)
	{
		main_struct->dump_cycle = get_nbr_after_flag(argv, argc, i);
		main_struct->f_dump = TRUE;
	}
	else if (ft_strcmp("-v", argv[*i]) == 0)
		main_struct->f_v = TRUE;
	else
		ft_error(ft_strjoin("NO such flag - ", argv[*i]));
}

t_player	*add_players(t_vm *main_struct, char **argv, int argc, int *i)
{
	int boot_nbr = 0;

	(main_struct->players_nbr)++;
	if (main_struct->players_nbr > MAX_PLAYERS)
		ft_error(ft_strjoin("Many players, allowed - ", ft_itoa(MAX_PLAYERS)));
	if (ft_strcmp("-n", argv[*i]) == 0)
		boot_nbr = get_nbr_after_flag(argv, argc, i);
	return (create_players(argv[*i], boot_nbr));
}

void	read_arguments(t_vm *main_struct, char **argv, int argc)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != 'n')
			read_flags(main_struct, argv, argc, &i);
		else
			main_struct->players[main_struct->players_nbr] =
					add_players(main_struct, argv, argc, &i);
		i++;
	}
}