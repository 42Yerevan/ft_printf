/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:42:58 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/17 16:46:49 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_address(void)
{
	char	*ptr;
	int		remainder;
	int		i;
	size_t	n;

	i = 0;
	n = (size_t)flags.arg;
	if (flags.arg == NULL)
		ptr = "0";
	else
	{
		ptr = (char *)malloc(13);
		while (n)
		{
			remainder = n % 16;
			n /= 16;
			if (remainder < 10)
				ptr[i] = remainder + '0';
			else
				ptr[i] = 97 + (remainder - 10);
			i++;
		}
	}
	flags.arg = ft_revers_str(ptr);
	ft_print_str();
}
