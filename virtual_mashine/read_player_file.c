//
// Created by denys on 31.05.17.
//

#include "op.h"

int		get_int_from_file(int fd)
{
	unsigned char	buffer[4];

    if (read(fd, buffer, 4) != 4)
		return (-5);
	return (buffer[3] | ( (int)buffer[2] << 8 ) | ( (int)buffer[1] << 16 ) |
				( (int)buffer[0] << 24 ));
}

char	*get_string_from_file(int fd, int define_len)
{
	char	buf_space[define_len];

	if (read(fd, buf_space, define_len + 1) != define_len)
		exit(-5);
	return (ft_strdup(buf_space));
}

char	*get_champ_code(int fd, int prog_len)
{
	char	*champ_code;
	char	test[1];

	champ_code = ft_strnew(prog_len);
	if (read(fd, champ_code, prog_len) != prog_len)
		exit(-5);
	return (champ_code);
}