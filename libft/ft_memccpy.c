/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:19:07 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:19:08 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned		int		i;
	unsigned const	char	*s;
	unsigned		char	*d;

	s = src;
	d = dest;
	i = 0;
	while (i < n)
	{
		if (s[i] == c)
		{
			d[i] = s[i];
			return (d + i + 1);
		}
		d[i] = s[i];
		i++;
	}
	return (0);
}
