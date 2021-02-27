/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:32:05 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:33:11 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char))
{
	char	*st;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	if (!s || !(st = malloc(size + 1)))
		return (NULL);
	ft_strlcpy(st, s, size + 1);
	while (i < size)
	{
		st[i] = (*f)(i, st[i]);
		i++;
	}
	return (st);
}
