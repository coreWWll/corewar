//
// Created by Oleksiy Kres on 5/22/17.
//

#include <unistd.h>

char	hex_digit_to_char(unsigned char d)
{
	if (d < 10)
		return (d + '0');
	else
		return ('a' + d - 10);
}

void	print_byte_hex(unsigned char c)
{
	char c1;

	c1 = hex_digit_to_char(c / 16);
	write(1, &c1, 1);
	c1 = hex_digit_to_char(c % 16);
	write(1, &c1, 1);
}

void	print_points(const unsigned char *addr1, size_t i1, size_t size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < 16 && i1 + i < size)
	{
		c = (unsigned char)(addr1[i1 + i]);
		if (c < 32 || c > 126)
			write(1, ".", 1);
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	const unsigned char		*addr1;
	unsigned int			i;
	unsigned int			i1;

	addr1 = addr;
	i1 = 0;
	while (i1 < size)
	{
		i = 0;
		while (i < 16)
		{
			if (i1 + i < size)
				print_byte_hex((char)(addr1[i1 + i]));
			else
				write(1, "  ", 2);
			i++;
			if (i % 2 == 0)
				write(1, " ", 1);
		}
		print_points(addr1, i1, size);
		i1 += 16;
	}
}

/*int	main(void)
{
	char *s = "Hello world";

	print_memory(s, 20);
	return (0);
}*/


