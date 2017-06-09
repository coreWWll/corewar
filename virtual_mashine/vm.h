//
// Created by Denys Burtnjak on 6/1/17.
//

#ifndef VIRTUAL_MASHINE_VM_H_H
#define VIRTUAL_MASHINE_VM_H_H

#include <fcntl.h>
#include "libft/libft.h"
#include "../op.h"

#define TRUE						1
#define FALSE						0

#define ERR_PLAYER_FILE_READING		"Player_file reading fail"
#define ERR_OPEN_FILE				"Can't open file - "
#define ERR_PLAYER_SIZE				"The size of player is to big - "
#define ERR_MEM_ALLOC				"Cant allocate the memory: "

//extern t_op op_tab[17];

typedef struct		s_args
{
	int				name;
	int 			value;
}					t_args;

typedef struct		s_car
{
	t_args			args[3];
	int 			carry;
	int				arg_size;
	unsigned int	reg[16];
	t_op			op_tabble;
	int				op_size;
	int             pos;
	int             live;
	int 			nb;
	int             op_type;
	int             c_for_op;
	char            *data;
	struct s_car    *next;
}					t_car;


typedef struct			s_player
{
	unsigned int		lives_in_current_period;
	int					boot_nbr;
	int                 name;
	char 				*bot_name;
	char 				*comment;
	struct s_car        *car;
	size_t				prog_len;
	char				*champ_code;
}						t_player;

typedef struct			s_vm
{
	t_player			**players;
	int 				last_live[2];
	int 				max_checks;
	int 				nbr_of_lifes;
	int 				count_live_functions;
	int					players_nbr;
	char 				*map;
	int					f_dump;
	int					dump_cycle;
	int					f_v;
	int					cycle;
	int					round;
	int 				cycle_to_die;
}						t_vm;

void	dell_car_from_list(t_car **head, t_car *to_dell);
char	*ft_memdup(size_t size, char *map, int pos);
t_player *create_players(char *file_name, int boot_nbr);
void    start_battle(t_vm *main_struct);
void	put_cat_on_start(t_vm	*main_struct);

void    get_live_func(char *map, t_car *car);
void get_ld_func(t_car *car);
void get_st_func(t_car *car);
void get_add_func(t_car *car);
void get_sub_func(t_car *car);
void get_or_func(t_car *car);
void get_xor_func(t_car *car);
void    get_zjmp_func(char *map, t_car *car);
void get_ldi_func(t_car *car);
void get_sti_func(t_car *car);
void get_fork_func(char *map, t_car *car);
void get_lld_func(t_car *car);
void get_lldi_func(t_car *car);
void get_lfork_func(char *map, t_car *car);
void get_aff_func(char *map, t_car *car);
void get_xor_func(t_car *car);
void get_and_func(t_car *car);

void	do_op_code(t_vm *main_struct, t_car *car);

void    do_live_func(t_vm *main_struct, t_car *car);
void    do_ld_func(t_vm *main_struct, t_car *car);
void    do_st_func(t_vm *main_struct, t_car *car);
void    do_add_func(t_vm *main_struct, t_car *car);
void    do_sub_func(t_vm *main_struct, t_car *car);
void    do_and_func(t_vm *main_struct, t_car *car);
void    do_or_func(t_vm *main_struct, t_car *car);
void    do_xor_func(t_vm *main_struct, t_car *car);
void    do_zjmp_func(t_vm *main_struct, t_car *car);
void    do_ldi_func(t_vm *main_struct, t_car *car);
void    do_sti_func(t_vm *main_struct, t_car *car);
void    do_fork_func(t_vm *main_struct, t_car *car);
void	create_new_car(t_car *car, int delta);
t_car	*add_car(t_car *car, int delta);
short	get_short_from_byte_code(char *buffer, int flag);
void    do_lld_func(t_vm *main_struct, t_car *car);
void    do_lld_func(t_vm *main_struct, t_car *car);
void    do_lldi_func(t_vm *main_struct, t_car *car);
void    do_lfork_func(t_vm *main_struct, t_car *car);
void    do_aff_func(t_vm *main_struct, t_car *car);


void    move_all_car(t_vm *main_struct);
int		get_int_from_file(int fd);
char	*get_string_from_file(int fd, size_t define_len);
char	*get_champ_code(int fd, size_t prog_len);
void	print_memory(unsigned char *map);
void	ft_error(char *error_message);
void    get_op_code(t_vm *main_struct, t_car *car);
void	read_arguments(t_vm *main_struct, char **argv, int argc);
void	create_map(t_vm *main_struct);
void	create_names_players(t_vm *main_struct);


int		get_int_from_byte_code(char *buffer);
int		get_args_nd_value(t_car *car, t_vm *main_struct);
void	put_int_on_map(char *map, int data);



#endif
