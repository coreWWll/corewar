
#include <unistd.h>
#include "op.h"

void	put_16(unsigned char c, char *str, int *i)
{
	if (c >= 16)
	{
		put_16(c / 16, str, i);
		put_16(c % 16, str, i);
	}
	else
	{
		if (c < 10)
			c = c + '0';
		else
			c = c + 'a' - 10;
		str[*i] = c;
		(*i)++;
	}

}

void	print_memory(const void *addr, char *buf, int *i)
{
	unsigned char	*str;

	str = (unsigned char*)addr;
		if (str[0] < 16)
		{
			buf[*i] = '0';
			(*i)++;
		}
	put_16(str[0], buf, i);
}

char	*put_bot_on_map(int fd)
{
	char 			ptr[1];
	int 			c;
	char			*str;
	int				i;

    i = 0;
	str = ft_strnew(MEM_SIZE / 6);
	ft_bzero(str, MEM_SIZE / 6);
	c = 0;
	while (read(fd, ptr, 1))
	{
		if (c > PROG_NAME_LENGTH + COMMENT_LENGTH + 15)
			print_memory(ptr, str, &i);
		c++;
	}
	return (ft_strsub(str, 0, i));
}
