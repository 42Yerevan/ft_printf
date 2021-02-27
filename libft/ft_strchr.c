/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:24:00 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:24:02 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (s[len])
	{
		len++;
	}
	while (i <= len)
	{
		if (s[i] == c)
		{
			return (char*)(s + i);
		}
		i++;
	}
	return (0);
}
