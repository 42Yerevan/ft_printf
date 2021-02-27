/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upperhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:32:52 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/19 10:34:12 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static	char	*ft_revers_upperhex(char *s)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s);
	i = 0;
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	while ((len) != 0)
	{
		ptr[i] = s[len - 1];
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}

int				ft_upperlen(size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void			ft_upperzero(char **s)
{
	int		size;
	char	*ptr;

	size = flags.minwidth ? flags.minwidth : flags.maxwidth;
	ptr = (char *)malloc(size);
	if ((flags.zero) && (flags.minwidth > (int)ft_strlen(*s)) && (!flags.dot))
	{
		ft_memset(ptr, '0', (flags.minwidth - ft_strlen(*s)));
		ptr = ft_strjoin(*s, ptr);
		*s = ptr;
	}
	else if ((flags.dot) && (flags.maxwidth > (int)ft_strlen(*s)))
	{
		ft_memset(ptr, '0', (flags.maxwidth - ft_strlen(*s)));
		ptr = ft_strjoin(*s, ptr);
		*s = ptr;
	}
	else
		return ;
}

void			ft_second_upperhex(char **ptr)
{
	if (flags.zero || flags.dot)
		ft_upperzero(&(*ptr));
	flags.dot = 0;
	flags.arg = ft_revers_upperhex(*ptr);
	ft_print_str();
}

void			ft_print_upperhex(void)
{
	char	*ptr;
	int		remainder;
	int		i;
	size_t	n;

	i = 0;
	n = (size_t)flags.arg;
	if (!(ptr = (char *)malloc((ft_upperlen(n) + 1))))
		return ;
	if (n == 0 && !flags.dot)
		*ptr = '0';
	else
	{
		while (n)
		{
			remainder = n % 16;
			n /= 16;
			if (remainder < 10)
				ptr[i++] = remainder + '0';
			else
				ptr[i++] = 65 + (remainder - 10);
		}
		ptr[i] = '\0';
	}
	ft_second_upperhex(&ptr);
}
