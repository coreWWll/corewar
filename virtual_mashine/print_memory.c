
#include "vm.h"

void	put_nbr(unsigned char c)
{
	unsigned char	print;

	if (c >= 16)
	{
		put_nbr(c / (char)16);
		put_nbr(c % (char)16);
	}
	else
	{
		if (c < 10)
			print = (unsigned char)(c + '0');
		else
			print = (unsigned char)((c - 10) + 'a');
		write(1, &print, 1);
	}
}

void	print_memory(unsigned char *map)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_putendl("");
		if (map[i] < 16)
			ft_putchar('0');
		put_nbr(map[i]);
		ft_putchar(' ');
		i++;
	}
}