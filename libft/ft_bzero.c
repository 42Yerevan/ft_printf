/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:27:49 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 15:27:53 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t len)
{
	size_t			length;
	unsigned char	*str;

	str = s;
	length = 0;
	while (length < len)
	{
		str[0] = 0;
		length++;
		str++;
	}
}
