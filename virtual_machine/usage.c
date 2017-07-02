/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:20:32 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 17:20:37 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	usage(void)
{
	ft_printf("## USAGE #####################################\n");
	ft_printf("Usage: ./corewar [-dump N | -v | -aff | -alive ] "
					  "[[-n N] <champion1.cor>] "
					  "[[-n N] <...>]\n");
	ft_printf("\t%-10s %s\n", "-v", "Use visualization");
	ft_printf("\t%-10s %s\n", "-usage", "Print usage then exits");
	ft_printf("\t%-10s %s\n", "-dump N", "Dumps memory after N cycles "
			"then exits");
	ft_printf("\t%-10s %s\n", "-aff", "Prints output from \"aff\"");
	ft_printf("\t%-10s %s\n", "-alive", "Show lives");
	exit(1);
}
