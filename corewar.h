//
// Created by Oleksiy Kres on 5/26/17.
//

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

typedef struct      s_asm
{
	char            *file_name;// имя файла
	char            *name;// имя бота
	char            *comm; // комментарий
	char            *lable;
	int             opcode;
	char            *command;
	char            *args;
	int             bin[8];
	char            hexa[4];
	int             carry;
	int             c_oct;
	int             cycles;
	int             label_size;
	struct s_asm    *next;
}                   t_asm;

#endif
