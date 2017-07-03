/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:33:48 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:33:50 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*ft_memdup(size_t size, char *map, int pos)
{
	char *data;

	data = ft_memalloc(size);
	ft_memmove(data, map + pos, size);
	return (data);
}
