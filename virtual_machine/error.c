//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

void	ft_error(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	exit(-1);
}