/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:30:19 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:30:23 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char				*d;
	const		char	*s;
	unsigned	int		n;
	unsigned	int		dlen;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- && *d)
		d++;
	dlen = d - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
