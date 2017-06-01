/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:17:38 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/10 16:52:53 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	minimize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

static void	first_letter(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	else
	{
		while ((str[i] < 'a' && str[i] > 'z') || str[i] != '\0')
		{
			i++;
			if (str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] == ' ')
				break ;
			else if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ')
			{
				str[i] = str[i] - 32;
				break ;
			}
		}
	}
}

char		*ft_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	minimize(str);
	first_letter(str);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			while ((str[i] < 'a' || str[i] > 'z') && str[i] != '\0')
			{
				i++;
				if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ')
					str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}
