/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:39:33 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:39:34 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_int_from_file(int fd)
{
	unsigned char	buffer[4];

	if ((read(fd, buffer, 4)) != 4)
		ft_error(ERR_PLAYER_FILE_READING);
	return (buffer[3] | ((int)buffer[2] << 8) | ((int)buffer[1] << 16) |
				((int)buffer[0] << 24));
}

char	*get_string_from_file(int fd, size_t define_len)
{
	char	*buf_str;
	char	*ret_str;

	buf_str = ft_strnew(define_len);
	if (read(fd, buf_str, define_len) != define_len)
		ft_error(ERR_PLAYER_FILE_READING);
	ret_str = ft_strdup(buf_str);
	ft_strdel(&buf_str);
	return (ret_str);
}

char	*get_champ_code(int fd, size_t prog_len)
{
	char	*champ_code;

	champ_code = ft_strnew(prog_len);
	int n = read(fd, champ_code, prog_len);
	if (n != prog_len)
		ft_error(ERR_PLAYER_FILE_READING);
	return (champ_code);
}
