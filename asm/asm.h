//
// Created by Anton Repnovskyi on 6/26/17.
//

#ifndef COREWAR_ASM_H

#include "../op.h"
#include "../asm/libft/libft.h"
#define COREWAR_ASM_H
#define MAX_INT                 2147483647
#define MAX_SHORT_INT 			65535

typedef struct      s_asm
{
    char            *file_name;
    char            *file_path;
    char            *name;
    char            *comm;
    char            *label;
    int             only_label;
    int             opcode;
    int             comm_num;
    char            *command;
    int             amount_of_args;
    int             what_args[3];
    int             l_flag[3];
    char            **args;
    int             label_size;
    struct s_asm    *next;
    header_t		*header;
    int 			cur_size;
    int 			cur_codage_octal;
    int             program_s;
}                   t_asm;

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
void				check_endl_and_len(char *t, char *name, int flag);
int					if_comment(char *line);
int					is_label(char *line);
char				*if_comment_at_end(char *line);
void				check_if_label_ok(char *line, int len);
void				check_label_syntax(char *line);
void				find_label_or_die(t_asm *start, char *label);
void				ft_exit(int flag);
void				to_byte_code(t_asm *head);
void 				header_parse(t_asm *asemb);
void                validate_it(t_asm *start);
char	            *clean_arg(char *line);
void 	            check_if_end_is_newln(char *av);
int 				if_lable(int *ar);
void				write_op_code(t_asm *head, t_asm *begin, int op_c, int fd);
unsigned int		do_big_endian(unsigned int magic, int size);
char	            *get_full_name_or_comment(int fd, char *name, char *line, int flag);
char	            *start_getting_name(char **name, char *t, size_t len);
void	            check_if_name_comment_is_correct(char *line, int flag);
int	                check_if_num_ok(char *reg, int f);

#endif
