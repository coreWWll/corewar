
#include "vm.h"

void	add_char(char *buf, int *j, char c)
{
	buf[*j] = c;
	(*j)++;
}

void	put_nbr(unsigned char c, char *buf, int *j)
{
	unsigned char	print;

	if (c >= 16)
	{
		put_nbr(c / (char)16, buf, j);
		put_nbr(c % (char)16, buf, j);
	}
	else
	{
		if (c < 10)
			print = (unsigned char)(c + '0');
		else
			print = (unsigned char)((c - 10) + 'a');
		add_char(buf, j, print);
	}
}

void	print_memory(unsigned char *map, size_t size)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	if (!(buf = ft_strnew(size * 3)))
		ft_error(ERR_MEM_ALLOC);
	while (i < size)
	{
		if (map[i] < 16)
			add_char(buf, &j, '0');
		put_nbr(map[i], buf, &j);
		i++;
		if (i % 64 == 0 && i != 0)
			add_char(buf, &j,'\n');
		else
			add_char(buf, &j, ' ');
	}
	write(1, buf, size * 3);
	ft_strdel(&buf);
}