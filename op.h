//
// Created by Anton Repnovskyi on 5/22/17.
//

#ifndef COREWAR_OP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include "libft/libft.h"
#define COREWAR_OP_H

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
#define MAX_INT                 2147483647
# define MAX_SHORT_INT 			65535

typedef struct		header_s
{
    unsigned int		magic;
    char				prog_name[PROG_NAME_LENGTH + 1];
    unsigned int		prog_size;
    char				comment[COMMENT_LENGTH + 1];
}						header_t;

typedef struct      s_asm
{
    char            *file_name;
    char            *file_path;
    char            *name;
    char            *comm;
    char            *label;
    int             only_label; //flag if command is under lable
    int             opcode;
    int             comm_num;//num of command and its line in t_op
    char            *command;
    int             amount_of_args;
    int             what_args[3]; //type of args (T_DIR, T_IND or T_REG
    int             l_flag[3];//if lable in args
    char            **args;
    int             label_size;
    struct s_asm    *next;
	header_t		*header;
    int 			cur_size;
    int 			cur_codage_octal;
    int             program_s;
}                   t_asm;

typedef struct s_op
{
    char 			*command;
    int 			args_am; //required number of args
    int 			args[3];// 3 is maximum
    int 			opcode;
	int             nb_tours;
	char            *full_name;
	int 			carry;
	int				codage_octal;
} t_op;

extern t_op op_tab[17];

typedef enum e_t
{
	REG,
	IND
}			t_t;

t_asm               *new_asm();
void				get_all_info(t_asm *start, char *line);
void				get_args(char *line, t_asm *start);
int					is_num(char *str);
char				*good_strtrim(char *str);
void    			mult_putstr(char *str, char *str1, char *str2);
char				*get_name_or_comm(char *line, int fd, int flag);
char				*get_file_name(char *av);
char				*get_result_output(char *av);
void				check_format(char *file);
void				check_endl_and_len(char *t, char *name, char *line, int flag);
int					if_comment(char *line);
int					is_label(char *line);
char				*if_comment_at_end(char *line);
void				check_if_label_ok(char *line, int len);
void				check_label_syntax(char *line);
void				find_label_or_die(t_asm *start, char *label);
void				ft_exit(int flag);
void				to_byte_code(t_asm *head);
void 				header_parse(t_asm *asemb, int fd);
void                validate_it(t_asm *start);
t_op                *init_tab();
char	            *clean_arg(char *line);
void 	            check_if_end_is_newln(char *av);
int 				if_lable(int *ar);// check if in arguments lable
void				write_op_code(t_asm *head, t_asm *begin, int op_c, int fd); // write commands in file
unsigned int		do_big_endian(unsigned int magic, int size); // change place of bits
char	            *get_full_name_or_comment(int fd, char *name, char *line, int flag);
char	            *start_getting_name(char **name, char *t, size_t len);
void	            check_if_name_comment_is_correct(char *line, int flag);

#endif //COREWAR_OP_H