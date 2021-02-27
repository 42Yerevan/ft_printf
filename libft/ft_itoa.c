/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:32:06 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:15:50 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dc(int n)
{
	int i;

	i = 0;
	if (n < 0 || n == 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	int				n1;
	unsigned int	n2;
	int				i;
	char			*d;

	i = ft_dc(n);
	n1 = 0;
	n2 = n;
	d = malloc(i);
	d[--i] = '\0';
	if (n < 0)
	{
		n2 = n * -1;
		d[n1] = '-';
		n1++;
	}
	while (n1 < i--)
	{
		d[i] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (d);
}
