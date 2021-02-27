/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:47:15 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/17 16:51:24 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_swap(char *s1, char *s2)
{
	char c;

	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

void		ft_iszero(char **ptr, char **new_ptr)
{
	if (!flags.dot)
	{
		if (!(*new_ptr = (char *)malloc(flags.minwidth) + 1))
			return ;
		if (flags.zero)
			ft_memset(*new_ptr, '0', (flags.minwidth - ft_strlen(*ptr)));
		*new_ptr = ft_strjoin(*new_ptr, *ptr);
		if ((**ptr == '-' && flags.minwidth >= (int)ft_strlen(*ptr)))
			ft_swap(*new_ptr,
					(*new_ptr + (flags.minwidth - ft_strlen(*ptr))));
	}
	else
		*new_ptr = *ptr;
}

void		ft_second_digit(char *ptr, char *new_ptr)
{
	if ((flags.dot && flags.maxwidth >= (int)ft_strlen(ptr)))
	{
		if (!(new_ptr = (char *)malloc(flags.maxwidth) + 1))
			return ;
		if (*ptr != '-')
		{
			ft_memset(new_ptr, '0', (flags.maxwidth - ft_strlen(ptr)));
			new_ptr = ft_strjoin(new_ptr, ptr);
		}
		else
		{
			*new_ptr = '-';
			ft_memset((new_ptr + 1), '0', (flags.maxwidth - ft_strlen(ptr)));
			*ptr = '0';
			new_ptr = ft_strjoin(new_ptr, (ptr));
		}
	}
	else if (flags.minwidth > (int)ft_strlen(ptr) && flags.zero)
		ft_iszero(&ptr, &new_ptr);
	else
		new_ptr = ptr;
	if (flags.minwidth == 0 && flags.maxwidth == 0)
		new_ptr = ptr;
	flags.arg = new_ptr;
}

void		ft_print_percent(void)
{
	char *ptr;
	char *new_ptr;

	new_ptr = NULL;
	ptr = (char *)malloc(2);
	ptr[0] = '%';
	if (flags.minwidth < 0)
	{
		flags.zero = 0;
		flags.minwidth *= -1;
		flags.minus = 1;
	}
	if ((flags.zero && !flags.minus) || flags.dot)
		ft_second_digit(ptr, new_ptr);
	else
		flags.arg = ptr;
	if (ft_atoi((char *)flags.arg) != 0)
		flags.dot = 0;
	ft_print_str();
}

void		ft_print_digit(void)
{
	char *ptr;
	char *new_ptr;

	new_ptr = NULL;
	ptr = flags.unsign ? ft_itoa2((unsigned)flags.unsign)
		: ft_itoa((int)flags.arg);
	if (flags.minwidth < 0)
	{
		flags.zero = 0;
		flags.minwidth *= -1;
		flags.minus = 1;
	}
	if ((flags.zero && !flags.minus) || flags.dot)
		ft_second_digit(ptr, new_ptr);
	else
		flags.arg = ptr;
	if (ft_atoi((char *)flags.arg) != 0)
		flags.dot = 0;
	ft_print_str();
}
