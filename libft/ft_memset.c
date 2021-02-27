/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:21:27 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:21:31 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			length;
	unsigned char	*str;

	str = b;
	length = 0;
	while (length < len)
	{
		*str = c;
		length++;
		str++;
	}
	return (b);
}
