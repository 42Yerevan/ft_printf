/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:33:27 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:33:32 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char *d1;
	const unsigned char *d2;

	d1 = (unsigned const char*)s1;
	d2 = (unsigned const char*)s2;
	i = 0;
	while ((d1[i] || d2[i]) && i < n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}
