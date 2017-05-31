//
// Created by denys on 31.05.17.
//

#include "op.h"

int		check_magic(int fd)
{
	unsigned char	magic[4];
	int				magic_int;

    if (read(fd, magic, 4) != 4)
		return (-5);
	magic_int = magic[3] | ( (int)magic[2] << 8 ) | ( (int)magic[1] << 16 ) |
				( (int)magic[0] << 24 );
	return (magic_int - COREWAR_EXEC_MAGIC);
}

char	*get_player_name(int fd)
{
	char	name_space[PROG_NAME_LENGTH];

	if (read(fd, name_space, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		exit(-5);
	return (ft_strdup(name_space));
}

char	*get_player_comment(int fd)
{
	char	comment_space[COMMENT_LENGTH];

	if (read(fd, comment_space, COMMENT_LENGTH) != COMMENT_LENGTH)
		exit(-5);
	return (ft_strdup(comment_space));
}

char	*get_champ_code(int fd)
{
	char	*champ_code;
	char	test[1];

	champ_code = ft_strnew(CHAMP_MAX_SIZE);
	if (read(fd, champ_code, CHAMP_MAX_SIZE) < 1)
		exit(-5);
	if (read(fd, test, 1) == 1)
		exit(-6);
	return (champ_code);
}