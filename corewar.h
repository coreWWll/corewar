//
// Created by Oleksiy Kres on 5/26/17.
//

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

# define MAX_INT 2147483647;

# include "libft/libft.h"
#include <fcntl.h>
typedef struct      s_asm
{
	char            *file_name;// имя файла
	char            *name;// имя бота
	char            *comm; // комментарий
	int 			l_flag[3];
	char            *lable;
	int             opcode;
	char            *command;
	int 			amount_arg;
	char            **args;
	int             bin[8];
	char            hexa[4];
	int             carry;
	int             c_oct;
	int             cycles;
	int             label_size;
	struct s_asm    *next;
}                   t_asm;

#endif
