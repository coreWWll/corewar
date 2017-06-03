//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

char	*ft_memdup(size_t size, char *map, int pos)
{
	char *data;

	data = ft_memalloc(size);
	ft_memmove(data, map + pos, size);
	return (data);
}