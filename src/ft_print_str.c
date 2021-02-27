/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:52:01 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/19 10:35:06 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_second_str(char *ptr, int len)
{
	if (flags.dot)
		if ((int)flags.maxwidth < ((int)ft_strlen(ptr)))
			ft_memset((ptr + (flags.maxwidth)), '\0',
				(ft_strlen(ptr) - flags.maxwidth));
	if ((int)flags.minwidth > ((int)ft_strlen(ptr)))
	{
		len = (int)flags.minwidth - ((int)ft_strlen(ptr));
		if (!flags.minus)
		{
			while ((len))
			{
				ft_putchar_fd(' ', 1);
				len--;
			}
			ft_putstr_fd(ptr, 1);
		}
		else
		{
			ft_putstr_fd(ptr, 1);
			while ((len--))
				ft_putchar_fd(' ', 1);
		}
	}
	else
		ft_putstr_fd(ptr, 1);
}

void		ft_print_str(void)
{
	char	*ptr;
	int		len;

	len = 0;
	if (flags.arg == NULL)
		flags.arg = "(null)";
	if ((!flags.minwidth) && (!flags.maxwidth) && (!(ft_atoi(flags.arg) <= 0)))
		ft_putstr_fd(flags.arg, 1);
	else
	{
		if (flags.minwidth < 0)
		{
			flags.minus = 1;
			flags.minwidth *= -1;
		}
		ptr = (char *)malloc((ft_strlen(flags.arg)));
		ptr[ft_strlen(flags.arg)] = '\0';
		ft_memcpy(ptr, flags.arg, ft_strlen(flags.arg));
		ft_second_str(ptr, len);
	}
}
