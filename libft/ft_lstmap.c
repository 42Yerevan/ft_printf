/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:18:13 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:18:15 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*c;
	t_list	*start;

	if (!(start = ft_lstnew(f(lst->content))))
		ft_lstdelone(lst, del);
	else
	{
		lst = lst->next;
		c = start;
	}
	while (lst)
	{
		if (!(c->next = ft_lstnew(f(lst->content))))
			ft_lstdelone(lst, del);
		lst = lst->next;
		c = c->next;
	}
	return (start);
}
