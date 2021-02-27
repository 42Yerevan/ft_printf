/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:21:10 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:21:14 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned		int		i;
	unsigned const	char	*s;
	unsigned		char	*d;
	unsigned		char	buff[len];

	s = src;
	d = dest;
	i = 0;
	while (i < len)
	{
		buff[i] = s[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		d[i] = buff[i];
		i++;
	}
	return (dest);
}
