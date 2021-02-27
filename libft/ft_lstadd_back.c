/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:16:19 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:16:21 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	if (*lst)
	{
		n = ft_lstlast(*lst);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}
