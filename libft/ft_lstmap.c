/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:01:50 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/06 18:23:04 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;

	if (lst && f)
	{
		res = (t_list*)malloc(sizeof(t_list));
		res = (*f)(lst);
		res->next = ft_lstmap(lst->next, f);
		return (res);
	}
	return (NULL);
}
