//
// Created by Denys Burtnjak on 6/1/17.
//

#include "vm.h"

void	ft_error(char *error_message)
{
	perror(error_message);
	exit(-1);
}