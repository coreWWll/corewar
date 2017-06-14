//
// Created by denys on 13.06.17.
//

#ifndef VIRTUAL_MASHINE_VISUALISATION_H
#define VIRTUAL_MASHINE_VISUALISATION_H

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "../vm.h"

# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define RED			"\x1b[31m"
# define RESET			"\x1b[0m"
# define CLEARE			"\033[2J"
# define TO_BEGIN		"\033[0;0f"

int		ft_kbhit(void);

#endif //VIRTUAL_MASHINE_VISUALISATION_H
