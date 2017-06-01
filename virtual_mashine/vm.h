//
// Created by Denys Burtnjak on 6/1/17.
//

#ifndef VIRTUAL_MASHINE_VM_H_H
#define VIRTUAL_MASHINE_VM_H_H

#include <fcntl.h>
#include "libft/libft.h"
#include "../op.h"

typedef struct		s_car
{
	int             pos;
	int             nb;
	int             op_type;
	int             c_for_op;
	char            *data;
	struct s_car    *next;

}					t_car;

typedef struct			s_player
{
	int                 name;
	char 				*bot_name;
	char 				*comment;
	struct s_car        *car;
	struct  s_player    *next;
}						t_player;

typedef struct			s_vm
{
	t_player			*players;
	char 				*map;
	int					f_dump;
	int					f_n;
	int					f_v;
	int					cycle;
	int					round;
}						t_vm;

char	*ft_memdup(size_t size, char *map, int pos);
t_player	*create_players(void *map, int n_bots, char *file_name, int n);
void    start_battle(t_vm *main_struct);
void    get_live_func(char *map, t_car *car, int *pos);
void    get_ld_func(char *map, t_car *car, int *pos);
void    get_st_func(char *map, t_car *car, int *pos);
void    get_add_func(char *map, t_car *car, int *pos);
void    get_sub_func(char *map, t_car *car, int *pos);
void    get_or_func(char *map, t_car *car, int *pos);
void    get_xor_func(char *map, t_car *car, int *pos);
void    do_live_func(char *map, t_car *car);
void    do_ld_func(char *map, t_car *car);
void    do_st_func(char *map, t_car *car);
void    do_add_func(char *map, t_car *car);
void    do_sub_func(char *map, t_car *car);
void    do_and_func(char *map, t_car *car);
void    do_or_func(char *map, t_car *car);
void    do_xor_func(char *map, t_car *car);
void    get_and_func(char *map, t_car *car, int *pos);
void	do_op_code(char *map, t_car *car);
void    move_all_car(t_vm *main_struct);
int		get_int_from_file(int fd);
char	*get_string_from_file(int fd, size_t define_len);
char	*get_champ_code(int fd, size_t prog_len);
void	print_memory(unsigned char *map);
void	ft_error(char *error_message);
void    get_op_code(t_vm *main_struct, t_car *car, int *pos);

#define ERR_PLAYER_FILE_READING	"Error: player_file reading fail"


//exit -5 error player file readin
//exit -6 player size bigger than...

#endif
